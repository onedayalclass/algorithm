def solution(bandage, health, attacks):
    n = len(attacks)
    idx = 0
    max_health = health
    
    while idx < n:
        h, damage = attacks[idx]
        con = 0
        health -= damage
        if health <= 0:
            return -1
        if idx + 1 < n:
            for _ in range(h, attacks[idx + 1][0] - 1):
                health = min(max_health, health + bandage[1])
                con += 1
                if con == bandage[0]:
                    con = 0
                    health = min(max_health, health + bandage[2])
        idx += 1
    return health
  
