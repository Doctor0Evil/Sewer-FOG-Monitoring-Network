import type { ReactNode } from "react";

export function Layout(props: { children: ReactNode }) {
  return (
    <div style={{ fontFamily: "system-ui, sans-serif", minHeight: "100vh" }}>
      <header
        style={{
          padding: "0.75rem 1.5rem",
          borderBottom: "1px solid #ddd",
          background: "#04395e",
          color: "white"
        }}
      >
        <h1 style={{ margin: 0, fontSize: "1.25rem" }}>Sewer FOG Karma Dashboard</h1>
      </header>
      <main style={{ padding: "1.5rem" }}>{props.children}</main>
    </div>
  );
}
