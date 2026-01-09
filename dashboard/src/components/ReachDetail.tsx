import type { ReachMetrics } from "../api";

export function ReachDetail(props: { metrics: ReachMetrics | null }) {
  if (!props.metrics) {
    return <p>Select a reach to view details.</p>;
  }
  const m = props.metrics;
  return (
    <div>
      <h2>Reach {m.reachId}</h2>
      <p>Current FOG concentration is {m.fog_mgL.toFixed(0)} mg/L with flow {m.flow_m3s.toFixed(4)} m³/s.</p>
      <p>Risk score is {(m.riskScore * 100).toFixed(0)}% and daily Karma is {m.dailyKarma.toFixed(1)} units.</p>
    </div>
  );
}
