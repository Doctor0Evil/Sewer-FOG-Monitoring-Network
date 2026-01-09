import type { ReachMetrics } from "../api";

export function ReachSummary(props: { metrics: ReachMetrics[] }) {
  return (
    <table style={{ width: "100%", borderCollapse: "collapse" }}>
      <thead>
        <tr>
          <th>Reach</th>
          <th>Flow (m³/s)</th>
          <th>FOG (mg/L)</th>
          <th>Risk score</th>
          <th>Daily Karma</th>
        </tr>
      </thead>
      <tbody>
        {props.metrics.map((m) => (
          <tr key={m.reachId}>
            <td>{m.reachId}</td>
            <td>{m.flow_m3s.toFixed(4)}</td>
            <td>{m.fog_mgL.toFixed(0)}</td>
            <td>{(m.riskScore * 100).toFixed(0)}%</td>
            <td>{m.dailyKarma.toFixed(1)}</td>
          </tr>
        ))}
      </tbody>
    </table>
  );
}
