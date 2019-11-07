import graphviz
# AOJ GRL_2_A

def renderGraph(V, edge, adopted_edge_id):
    d = graphviz.Graph('gviz', filename='gviz.gv', format='svg',engine='neato')
    d.attr('node', shape='circle')
    for i in range(V):
        d.node(str(i))
    for i,val in enumerate(edge):
        if i in adopted_edge_id:
            col = 'red'
        else:
            col = 'black'
        d.edge(str(val[0]),str(val[1]),color=col)
    d.view()


V,E = list(map(int, input().split(' ')))
edge = [];
adopted_edge_id = [];
for i in range(E):
    e= list(map(int, input().split(' ')))
    edge.append([e[0],e[1]])

renderGraph(V, edge, adopted_edge_id)

