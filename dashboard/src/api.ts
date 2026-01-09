export interface ReachMetrics {
  reachId: string;
  flow_m3s: number;
  fog_mgL: number;
  riskScore: number;
  dailyKarma: number;
}

export async function fetchReachMetrics(): Promise<ReachMetrics[]> {
  // In production, call server/api JSON endpoints.
  return [
    {
      reachId: "PHX-FOG-REACH-01",
      flow_m3s: 0.008,
      fog_mgL: 250,
      riskScore: 0.7,
      dailyKarma: 180.0
    },
    {
      reachId: "PHX-FOG-REACH-02",
      flow_m3s: 0.0045,
      fog_mgL: 200,
      riskScore: 0.4,
      dailyKarma: 90.0
    }
  ];
}
