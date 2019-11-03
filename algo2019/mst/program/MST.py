import graphviz
# AOJ GRL_2_A

class UnionFind:
    def __init__(self, n):
        self.par = [-1] * n
    def find(self, i):
        if self.par[i] < 0:
            return i
        else:
             self.par[i] = self.find(self.par[i])
             return self.par[i]

    def unite(self, i, j):
        i = self.find(i)
        j = self.find(j)
        if i == j:
            return
        if -self.par[i] < -self.par[j]:
            self.par[j] += self.par[i]
            self.par[i] = j
        else:
            self.par[i] += self.par[j]
            self.par[j] = i
    
    def same(self, i, j):
        return self.find(i) == self.find(j)

    def render(self):
        d = graphviz.Digraph('UnionFind', filename='ufgviz.gv', engine='neato')
        d.attr('node', shape='circle')
        for i in range(len(self.par)):
            d.node(str(i))
        for i, val in enumerate(self.par):
            if val < 0:
                continue
            d.edge(str(i), str(val))
        d.view()

def renderGraph(V, edge, adopted_edge_id, current_edge, cnt):
    d = graphviz.Graph('MSTgviz', filename='MSTgviz.gv', format='svg',engine='neato')
    d.attr('node', shape='circle')
    for i in range(V):
        d.node(str(i))
    for i,val in enumerate(edge):
        if i == current_edge:
            col = 'green'
        elif i in adopted_edge_id:
            col = 'red'
        else:
            col = 'black'
        d.edge(str(val[0]),str(val[1]),label=str(val[2]),color=col)
    d.render(filename='MST' + str(cnt), cleanup=True, directory='../img/', format='svg')


V,E = list(map(int, input().split(' ')))
uf = UnionFind(V)
edge = [];
adopted_edge_id = [];
for i in range(E):
    s,t,w = list(map(int, input().split(' ')))
    edge.append([s,t,w])
edge.sort(key=lambda x: x[2])

cnt=0
renderGraph(V, edge, adopted_edge_id, -1, cnt)
cnt+=1
for i, e in enumerate(edge):
    if not uf.same(e[0], e[1]):
        uf.unite(e[0], e[1])
        adopted_edge_id.append(i)
    renderGraph(V, edge, adopted_edge_id, i, cnt)
    cnt+=1
renderGraph(V, edge, adopted_edge_id,-1, cnt)
        
print(adopted_edge_id)
