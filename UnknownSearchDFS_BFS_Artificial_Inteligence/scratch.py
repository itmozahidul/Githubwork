import collections

map={"oradea": ["zerind","sibiu"],
     "zerind": ["oradea","arad"],
     "sibiu": ["arad","rimnicu vilcea","fagaras","oradea"],
     "arad": ["zerind","sibiu","timisoara"],
     "rimnicu vilcea": ["sibiu","pitesti","craiova"],
     "fagaras": ["bucharest","sibiu"],
     "timisoara": ["arad","lugoj"],
     "pitesti": ["rimnicu vilcea","craiova","bucharest"],
     "craiova": ["dobreta","rimnicu vilcea","pitesti"],
     "bucharest": ["fagaras","pitesti","giurgiu","urziceni"],
     "lugoj": ["mehadia","timisoara"],
     "dobreta": ["mehadia","craiova"],
     "giurgiu": ["bucharest"],
     "urziceni": ["bucharest","vaslui","hirsova"],
     "mehadia": ["lugoj","dobreta"],
     "vaslui": ["lasi","urziceni"],
     "hirsova": ["urziceni","eforie"],
     "lasi": ["vaslui","neamt"],
     "eforie": ["hirsova"],
     "neamt": ["lasi"]

     }
def dfs(graph, root):
    seen = set([root])
    stack = [root]
    while stack:
        print("Stack: ", stack)
        vertex = stack.pop()
        print("Expand: ", vertex)
        for node in graph[vertex]:
            if node not in seen:
                seen.add(node)
                stack.append(node)

def bfs(graph, root):
    seen = set([root])
    queue = collections.deque([root])
    while queue:
        print("Queue: ", queue)
        vertex = queue.popleft()
        print("Expand: ", vertex)
        for node in graph[vertex]:
            if node not in seen:
                seen.add(node)
                queue.append(node)

def findPathwithdfs(graph, root,des):
    seen = set([root])
    stack = collections.deque([root])
    stop=0

    while stack:
        print("Stack: ", stack)
        vertex = stack.pop()

        print("Expand: ", vertex)
        for node in graph[vertex]:


            if node==des:
                stop=1
            if node not in seen:
                seen.add(node)
                stack.append(node)
        if stop==1:
            break

def Iteretive(graph, root,limit):
    seen = set([root])
    stack = [root]
    counter=0;
    while stack:

        print("Stack: ", stack)
        vertex = stack.pop()
        print("Expand: ", vertex)
        for node in graph[vertex]:
            if node not in seen:
                seen.add(node)
                stack.append(node)
        counter=counter+1

        if counter==limit:
            break
def findpathwithiteretive(graph, root,des,limit):
    seen = set([root])
    stack = [root]
    counter=0;
    stop=0
    while stack:

        print("Stack: ", stack)
        vertex = stack.pop()
        print("Expand: ", vertex)
        for node in graph[vertex]:
            if node==des:
                stop=1
            if node not in seen:
                seen.add(node)
                stack.append(node)
        counter=counter+1

        if counter==limit or stop==1:
            break
findpathwithiteretive(map,"fagaras","arad",7)





