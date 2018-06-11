# search.py
# ---------
# Licensing Information: Please do not distribute or publish solutions to this
# project. You are free to use and extend these projects for educational
# purposes. The Pacman AI projects were developed at UC Berkeley, primarily by
# John DeNero (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# For more info, see http://inst.eecs.berkeley.edu/~cs188/sp09/pacman.html

"""
In search.py, you will implement generic search algorithms which are called 
by Pacman agents (in searchAgents.py).
"""

import util

class SearchProblem:
  """
  This class outlines the structure of a search problem, but doesn't implement
  any of the methods (in object-oriented terminology: an abstract class).
  
  You do not need to change anything in this class, ever.
  """
  
  def getStartState(self):
     """
     Returns the start state for the search problem 
     """
     util.raiseNotDefined()
    
  def isGoalState(self, state):
     """
       state: Search state
    
     Returns True if and only if the state is a valid goal state
     """
     util.raiseNotDefined()

  def getSuccessors(self, state):
     """
       state: Search state
     
     For a given state, this should return a list of triples, 
     (successor, action, stepCost), where 'successor' is a 
     successor to the current state, 'action' is the action
     required to get there, and 'stepCost' is the incremental 
     cost of expanding to that successor
     """
     util.raiseNotDefined()

  def getCostOfActions(self, actions):
     """
      actions: A list of actions to take
 
     This method returns the total cost of a particular sequence of actions.  The sequence must
     be composed of legal moves
     """
     util.raiseNotDefined()
           

def tinyMazeSearch(problem):
  """
  Returns a sequence of moves that solves tinyMaze.  For any other
  maze, the sequence of moves will be incorrect, so only use this for tinyMaze
  """
  from game import Directions
  s = Directions.SOUTH
  w = Directions.WEST
  return  [s,s,w,s,w,w,s,w]

def depthFirstSearch(problem):
  """
  Search the deepest nodes in the search tree first [p 85].
  
  Your search algorithm needs to return a list of actions that reaches
  the goal.  Make sure to implement a graph search algorithm [Fig. 3.7].
  
  To get started, you might want to try some of these simple 
  commands to
  understand the search problem that is being passed in:
  
  print "Start:", problem.getStartState()
  print "Is the start a goal?", problem.isGoalState(problem.getStartState())
  print "Start's successors:", problem.getSuccessors(problem.getStartState())"""
 
  
  
  "*** YOUR CODE HERE ***"
  stk=util.Stack()
  listAns=[]
  parent={}
  parentdir={}
  parent[problem.getStartState()]=None
  parentdir[problem.getStartState()]=None
  visit={}
  for i in problem.getSuccessors(problem.getStartState()):
	parent[i[0]]=problem.getStartState()
	parentdir[i[0]]=None
	stk.push(i)
	visit[i[0]]=1
  while not stk.isEmpty():
	tmp=stk.pop();
	anspos=tmp[0]
	if problem.isGoalState(tmp[0]):
		break;
	#print tmp[1]
	for i in problem.getSuccessors(tmp[0]):
		if not visit.has_key(i[0]): 
			parent[i[0]]=tmp[0]
			parentdir[i[0]]=tmp[1]
			stk.push(i)
			visit[i[0]]=1
	
  listAns.append(tmp[1])
  while parentdir[anspos]!=None:
	listAns.insert(0,parentdir[anspos])
	anspos=parent[anspos]
  
  return listAns
  util.raiseNotDefined()

def breadthFirstSearch(problem):
  "Search the shallowest nodes in the search tree first. [p 81]"
  "*** YOUR CODE HERE ***"
  que=util.Queue()
  listAns=[]
  parent={}
  parentdir={}
  parent[problem.getStartState()]=None
  parentdir[problem.getStartState()]=None
  visit={}
  for i in problem.getSuccessors(problem.getStartState()):
	parent[i[0]]=problem.getStartState()
	parentdir[i[0]]=None
	que.push(i)
	visit[i[0]]=1
  while not que.isEmpty():
	tmp=que.pop();
	anspos=tmp[0]
	if problem.isGoalState(tmp[0]):
		break;
	#print tmp[1]
	for i in problem.getSuccessors(tmp[0]):
		if not visit.has_key(i[0]): 
			parent[i[0]]=tmp[0]
			parentdir[i[0]]=tmp[1]
			que.push(i)
			visit[i[0]]=1
	
  listAns.append(tmp[1])
  while parentdir[anspos]!=None:
	listAns.insert(0,parentdir[anspos])
	anspos=parent[anspos]
  
  return listAns
  util.raiseNotDefined()
      
def uniformCostSearch(problem):
  "Search the node of least total cost first. "
  "*** YOUR CODE HERE ***"
  util.raiseNotDefined()
  """depth=0
  #isgoal=problem.isGoalState(problem.getStartState())
  #print type(isgoal)
  while True:
    path=[]
    visit={}
    visit[problem.getStartState()]=1
    found=DLS(problem.getStartState(),depth,path,problem,visit)
    if found:
        return path
    depth+=1
    #if depth==10:
        #break
  util.raiseNotDefined()
 
def DLS(state,depth,path,problem,visit):
    #print depth
    if depth==0:
        isgoal=problem.isGoalState(state)
        return isgoal
    
    for i in problem.getSuccessors(state):
        if not visit.has_key(i[0]):
            path.append(i[1])
            visit[i[0]]=1
            #print path
            if DLS(i[0],depth-1,path,problem,visit)==True:
                return True
            path.pop()
            #del visit[i[0]]
    return False"""
        
    

def nullHeuristic(state, problem=None):
  """
  A heuristic function estimates the cost from the current state to the nearest
  goal in the provided SearchProblem.  This heuristic is trivial.
  """
  return 0

def aStarSearch(problem, heuristic=nullHeuristic):
  "Search the node that has the lowest combined cost and heuristic first."
  "*** YOUR CODE HERE ***"
  pq=util.PriorityQueue()
  path=[]
  visit={}
  parent={}
  info={}
  parent[problem.getStartState()]=None	
  visit[problem.getStartState()]=1
  for i in problem.getSuccessors(problem.getStartState()):
	parent[i[0]]=problem.getStartState()
	info[i[0]]=i
	tmplist={}
	for j in range(3):
		tmplist[j]=i[j]
	pq.push(tmplist,heuristic(i[0],problem))
	#visit[i[0]]=1
	
  while not pq.isEmpty():
	tmp=pq.pop()
	if visit.has_key(tmp[0]):
		continue
	visit[tmp[0]]=1
	anspos=tmp[0]
	if problem.isGoalState(tmp[0]):
		break
	for i in problem.getSuccessors(tmp[0]):
		if not visit.has_key(i[0]):
			tmplist={}
			for j in range(3):
				tmplist[j]=i[j]
			tmplist[2]=i[2]+tmp[2]
			pq.push(tmplist,tmplist[2]+heuristic(i[0],problem))
			parent[i[0]]=tmp[0];
			info[i[0]]=i;
	"""while not pq.isEmpty():
		print pq.pop()"""	
			
  while parent[anspos]!=None:
	path.insert(0,info[anspos][1])		
	anspos=parent[anspos]
	
  return path
    
  
# Abbreviations
bfs = breadthFirstSearch
dfs = depthFirstSearch
astar = aStarSearch
ucs = uniformCostSearch