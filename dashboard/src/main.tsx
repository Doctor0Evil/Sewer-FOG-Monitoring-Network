import React, { useEffect, useState } from "react";
import ReactDOM from "react-dom/client";
import { Layout } from "./components/Layout";
import { fetchReachMetrics, type ReachMetrics } from "./api";
import { ReachSummary } from "./components/ReachSummary";
import { ReachDetail } from "./components/ReachDetail";
import { RiskMap } from "./components/RiskMap";

function App() {
  const [metrics, setMetrics] = useState<ReachMetrics[]>([]);
  const [selected, setSelected] = useState<ReachMetrics | null>(null);

  useEffect(() => {
    fetchReachMetrics().then((data) => {
      setMetrics(data);
      if (data.length > 0) setSelected(data[0]);
    });
  }, []);

  return (
    <Layout>
      <h2>Current FOG and risk</h2>
      <RiskMap metrics={metrics} />
      <h2 style={{ marginTop: "1.5rem" }}>Tabular view</h2>
      <div
        onClick={(e) => {
          const target = e.target as HTMLElement;
          if (target.tagName === "TD") {
            const tr = target.parentElement;
            if (!tr) return;
            const reach = tr.firstElementChild?.textContent;
            const m = metrics.find((x) => x.reachId === reach);
            if (m) setSelected(m);
          }
        }}
      >
        <ReachSummary metrics={metrics} />
      </div>
      <section style={{ marginTop: "1.5rem" }}>
        <ReachDetail metrics={selected} />
      </section>
    </Layout>
  );
}

ReactDOM.createRoot(document.getElementById("root") as HTMLElement).render(
  <React.StrictMode>
    <App />
  </React.StrictMode>
);
