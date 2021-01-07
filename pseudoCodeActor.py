import buffs # Theorical module handling the buffs/debuffs definition
import skills # Theorical module handling the skills definition
import displayManager
import gameActionManager

class Actor:
    def __init__(self, stats, menuList, skillList):
        self.maxHP = stats["hp"]
        self.HP = stats["hp"]
        self.maxEP = stats["ep"]
        self.EP = stats["ep"]
        self.physAtk = stats["physAtk"]
        self.speAtk = stats["speAtk"]
        self.physDef = stats["physDef"]
        self.speDef = stats["speDef"]
        self.speed = stats["speed"]
        self.critLuck = stats["critLuck"]
        self.accuracy = stats["accuracy"]
        self.dodge = stats["dodge"]

        self.effectiveMaxHP = stats["hp"]
        self.effectiveMaxEP = stats["ep"]
        self.effectivePhysAtk = stats["physAtk"]
        self.effectiveSpeAtk = stats["speAtk"]
        self.effectivePhysDef = stats["physDef"]
        self.effectiveSpeDef = stats["speDef"]
        self.effectiveSpeed = stats["speed"]
        self.effectiveCritLuck = stats["critLuck"]
        self.effectiveAccuracy = stats["accuracy"]
        self.effectiveDodge = stats["dodge"]

        self.buffs = []

        self.skillList = skillList # Dictionary of dictionaries, defining the layout of the menu

    def calculateEffectiveStats(self):
        modifiedMaxHp = 1
        modifiedMaxEp = 1
        modifiedPhysAtk = 1
        modifiedSpeAtk = 1
        modifiedPhysDef = 1
        modifiedSpeDef = 1
        modifiedSpeed = 1
        modifiedCritLuck = 1
        modifiedAccuracy = 1
        modifiedDodge = 1

        for buff in buffs:
            match buff.type: # Equivalent of the switch statement, not yet implemented, could use a numerical ID system
                case "maxHP":
                    self.modifiedMaxHP *= buff.potency
                case "maxEP":
                    self.modifiedMaxEP *= buff.potency
                case "physAtk":
                    self.modifiedPhysAtk *= buff.potency
                case "speAttack":
                    self.modifiedSpeAtk *= buff.potency
                case "physDef":
                    self.modifiedPhysDef *= buff.potency
                case "speDef":
                    self.modifiedSpeDef *= buff.potency
                case "speed":
                    self.modifiedSpeed *= buff.potency
                case "critLuck":
                    self.modifiedCritLuck *= buff.potency
                case "accuracy":
                    self.modifiedAccuracy *= buff.potency
                case "dodge":
                    self.modifiedDodge *= buff.potency
                case "atk":
                    self.modifiedPhysAtk *= buff.potency
                    self.modifiedSpeAtk *= buff.potency
                case "def":
                    self.modifiedPhysDef *= buff.potency
                    self.modifiedSpeDef *= buff.potency
        
        self.effectiveMaxHP = self.maxHH * modifiedMaxHp
        self.effectiveMaxEP = self.maxEP * modifiedMaxEP
        self.effectivePhysAtk = self.physAtk * modifiedPhysAtk
        self.effectiveSpeAtk = self.speAtk * modifiedSpeAtk
        self.effectivePhysDef = self.physDef * modifiedPhysDef
        self.effectiveSpeDef = self.speDef * modifiedSpeDef
        self.effectiveSpeed = self.speed * modifiedSpeed
        self.effectiveCritLuck = self.critLuck * modifiedCritLuck
        self.effectiveAccuracy = self.accuracy * modifiedAccuracy
        self.effectiveDodge = self.dodge * modifiedDodge


    def takeAction():
        menuList = self.skillList.entries
        while True:
            menuObj = gameActionManager.createMenu(menuList)
            displayManager.display(menuObj)
            command = menuList[gameActionManager.getSelection(menuObj)]
            if not isinstance(command, dict):
                gameActionManager.addSkill(command)
                break
            else:
                menuList = skillList[command]