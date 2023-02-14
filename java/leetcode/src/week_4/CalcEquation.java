package week_4;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

// class CalcEquation {
//     private class Pair {
//         private String neighbor;
//         private Double weight;
// 
//         Pair(String neighbor, Double weight) {
//             this.neighbor = neighbor;
//             this.weight = weight;
//         }
// 
//         String getN() {
//             return this.neighbor;
//         }
// 
//         Double getW() {
//             return this.weight;
//         }
//     }
// 
//     public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
//         // 1. new graph
//         // better implementation:
//         // HashMap<String, HashMap<String, Double>> graph = new HashMap<>();
//         HashMap<String, List<Pair>> graph = new HashMap<>();
// 
//         // 2. create graph
//         for (int i=0; i<equations.size(); i++) {
//             if (graph.containsKey(equations.get(i).get(0))) {
//                 graph.get(equations.get(i).get(0)).add(new Pair(equations.get(i).get(1), values[i]));
//             } else {
//                 List<Pair> l = new ArrayList<>();
//                 l.add(new Pair(equations.get(i).get(1), values[i]));
//                 graph.put(equations.get(i).get(0), l);
//             }
// 
//             if (graph.containsKey(equations.get(i).get(1))) {
//                 graph.get(equations.get(i).get(1)).add(new Pair(equations.get(i).get(0), 1.0 / values[i]));
//             } else {
//                 List<Pair> l = new ArrayList<>();
//                 l.add(new Pair(equations.get(i).get(0), 1.0 / values[i]));
//                 graph.put(equations.get(i).get(1), l);
//             }
//         }
// 
//         // 3. dfs
//         List<Double> res = new ArrayList<>();
//         for (int i=0; i<queries.size(); i++) {
//             // check if both in graph
//             if (graph.containsKey(queries.get(i).get(0)) && graph.containsKey(queries.get(i).get(1))) {
//                 res.add(dfs(queries.get(i).get(0), queries.get(i).get(1), graph, new HashSet<String>()));
//             } else {
//                 res.add(-1.0);
//             }
//         }
// 
//         return res.stream().mapToDouble(Double::doubleValue).toArray();
//     }
// 
//     private Double dfs(String start, String end, HashMap<String, List<Pair>> graph, HashSet<String> visited) {
//         if (start.equals(end)) {
//             return 1.0;
//         }
//         visited.add(start);
//         for (var p : graph.get(start)) {
//             if (!visited.contains(p.getN())) {
//                 double res = p.getW() * dfs(p.getN(), end, graph, visited);
//                 if (res > 0) {
//                     return res;
//                 }
//             }
//         }
//         return -1.0;
//     }
// }

class CalcEquation {
    // UnionFind class
    private class UF {
        HashMap<String, List<String>> graph = new HashMap<>(); // save all neighbors for each node for DFS/BFS traversal
        HashMap<String, String> parent = new HashMap<>(); // save parent for easily traversing to the root at the top
        HashMap<String, Double> dividedByRoot = new HashMap<>(); // save the quotient of each node value divided by root value
        HashMap<String, Integer> size = new HashMap<>(); // save the size of a single tree for tree depth minimization
        
        // no need to initialize since all the HashMap can be populated in the methods
        public UF() {
        }
        
        public void union(String a, String b, double quotient) {
            String ra = findRoot(a);
            String rb = findRoot(b);
            if (size.get(ra) > size.get(rb)) {
                // update all dividedByRoot values for nodes in the smaller tree via DFS or BFS
                double bridge = dividedByRoot.get(a) / quotient / dividedByRoot.get(b); // quotient of smaller tree's root value divided by larger tree's root value
                dfs(rb, new HashSet<String>(), bridge);
                
                // bidirection
                graph.get(rb).add(ra);
                graph.get(ra).add(rb);

                // only one direction pointing to the root
                parent.put(rb, ra);
                
                size.put(ra, size.get(ra) + size.get(rb));
                size.remove(rb);
            } else {
                // similar logic as above
                double bridge = dividedByRoot.get(b) / (1.0 / quotient) / dividedByRoot.get(a);
                dfs(ra, new HashSet<String>(), bridge);
                
                graph.get(ra).add(rb);
                graph.get(rb).add(ra);
                parent.put(ra, rb);
                
                size.put(rb, size.get(ra) + size.get(rb));
                size.remove(ra);
            }
        }
        
        private void dfs(String node, HashSet<String> visited, double bridge) {
            if (visited.contains(node)) {
                return;
            }
            visited.add(node);
            dividedByRoot.put(node, dividedByRoot.get(node) * bridge);
            for (String nei : graph.get(node)) {
                dfs(nei, visited, bridge);
            }
        }
        
        public String findRoot(String a) {
            if (!parent.containsKey(a)) {
                graph.put(a, new ArrayList<String>());
                parent.put(a, a);
                dividedByRoot.put(a, 1.0);
                size.put(a, 1);
                return a;
            }
            String root = a;
            while (root != parent.get(root)) {
                root = parent.get(parent.get(root)); // 2 hops at a time for faster traversal
            }
            
            return root;
        }
        
        public double query(String a, String b) {
            // don't forget this edge case when the node value is not in graph (i.e. the original equations)
            if (!graph.containsKey(a) || !graph.containsKey(b)) {
                return -1.0;
            }

            if (findRoot(a).equals(findRoot(b))) {
                return dividedByRoot.get(a) / dividedByRoot.get(b);   
            } else {
                return -1.0;
            }
        }
    }
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        UF uf = new UF();
        for (int i=0; i<equations.size(); i++) {
            List<String> pair = equations.get(i);
            String p1 = pair.get(0);
            String p2 = pair.get(1);
            double quotient = values[i];
            uf.union(p1, p2, quotient);
        }
        
        double[] res = new double[queries.size()];
        for (int i=0; i<queries.size(); i++) {
            List<String> query = queries.get(i);
            res[i] = uf.query(query.get(0), query.get(1));
        }
        return res;
    }
}