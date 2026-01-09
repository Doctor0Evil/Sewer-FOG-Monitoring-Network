import type { ReachMetrics } from "../api";

export function RiskMap(props: { metrics: ReachMetrics[] }) {
  return (
    <div style={{ display: "flex", gap: "0.75rem", flexWrap: "wrap" }}>
      {props.metrics.map((m) => {
        let color = "#2b9348";
        if (m.riskScore > 0.7) color = "#d00000";
        else if (m.riskScore > 0.4) color = "#f48c06";
        return (
          <div
            key={m.reachId}
            style={{
              borderRadius: 8,
              border: "1px solid #ccc",
              padding: "0.75rem",
              minWidth: 160
            }}
          >
            <div style={{ fontWeight: 600 }}>{m.reachId}</div>
            <div
              style={{
                marginTop: "0.5rem",
                height: 10,
                borderRadius: 4,
                background: "#eee",
                overflow: "hidden"
              }}
            >
              <div
                style={{
                  width: `${Math.round(m.riskScore * 100)}%`,
                  height: "100%",
                  background: color
                }}
              />
            </div>
            <div style={{ marginTop: "0.25rem", fontSize: "0.85rem" }}>
              Risk {(m.riskScore * 100).toFixed(0)}%
            </div>
          </div>
        );
      })}
    </div>
  );
}
