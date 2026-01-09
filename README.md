# README.md

Sewer-FOG-Monitoring-Network

This repository hosts a production-grade C++/IoT stack for continuous monitoring of fats, oils and grease (FOG) and hydraulic conditions in municipal sewers, with EcoNet-compatible Karma metrics for eco-impact accounting in Phoenix and similar cities. [web:1][web:2]

## Architecture

- firmware/node: ESP32/STM32 manhole nodes reading clamp-on ultrasonic flow meters and FOG probes, publishing MQTT payloads.
- edge-gateway: C++17 service aggregating packets from multiple nodes and forwarding to a cloud MQTT/REST endpoint with TLS.
- server/api: C++ REST/MQTT backend persisting time series to PostgreSQL/Timescale and computing CEIM-style FOG impact and Karma.
- dashboard: TypeScript web UI plotting flow, FOG %, and risk scores per reach, with drill-down to likely FOG sources.
- integrations/ai-chat: Webhook-style service turning alarms and Karma metrics into concise, chat-ready text snippets.
- qpudatashards/particles: Machine-readable CSV NanoKarma shards for node-level FOG loads and ecoimpact scores.
- docs: Hardware selection, Phoenix FOG ordinance references, CEIM equations and deployment playbooks.

## Build

- Requires CMake ≥ 3.16 and a C++17 compiler.
- For server components, PostgreSQL and libpq must be available.
- For embedded firmware, use the vendor toolchain (ESP-IDF or STM32Cube) and include firmware/node sources as a component.
