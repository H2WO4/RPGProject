import displayManager # Theorical display manager for text ...

# Handles the start of battle:
# Sets each actor action gauge to zero and start the turn loop
def combatStart():
    for actor in actorList: # Theoritical list containing all actors, both monsters and ennemies
        actor.actionGauge = 0
    
    turnLoop()


# Handles each tenth of a turn, each 10 iterations of the loop is a new turn for the game
# Each actor, both monster and enemy takes an action once their action gauge reach 1000
# Each iteration, their gauge fills by their speed (baseline speed is 100), so faster characters will have more actions per turn
def turnLoop():
    turn = 1
    subturn = 0
    while not endCombat:
        if subturn == 0:
            displayManager.displayTurnBanner(turn)
        
        for actor in actorList:
            actor.calculateEffectiveStats() # Function handling calculation for stats buffs/debuffs
            actor.actionGauge += actor.effectiveSpeed
        
        # Makes a list containg only actors with a full action gauge
        actingActors = [actor for actor in actorList if actor.actionGauge >= 1000]
        actingActors = sorted(actingActors, key=lambda actor: actor.actionGauge) # Sorts by whose action gauge overflows the most

        for actor in actingActors:
            actor.takeAction() # Makes each actor with a full action gauge take an action
            actor.actionGauge -= 1000 # Empty their action gauge by the needed amount
        
        subturn = (subturn + 1) % 10