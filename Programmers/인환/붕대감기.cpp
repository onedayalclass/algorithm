#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>


using namespace std;

//���ѻ���
//bandage��[���� �ð�, �ʴ� ȸ����, �߰� ȸ����] ������ ���̰� 3�� ���� �迭�Դϴ�.
//1 �� ���� �ð� = t �� 50
//1 �� �ʴ� ȸ���� = x �� 100
//1 �� �߰� ȸ���� = y �� 100
//1 �� health �� 1, 000
//1 �� attacks�� ���� �� 100
//attacks[i]��[���� �ð�, ���ط�] ������ ���̰� 2�� ���� �迭�Դϴ�.
//attacks�� ���� �ð��� �������� �������� ���ĵ� �����Դϴ�.
//attacks�� ���� �ð��� ��� �ٸ��ϴ�.
//1 �� ���� �ð� �� 1, 000
//1 �� ���ط� �� 100
// 



int solution(vector<int> bandage, int health, vector<vector<int>> attacks)
{
    int answer = 0;

    //�ð�
    int nTime = 0;

    //�÷��̾� ����
    int maxHealth = health;
    int nCurHealth = health;
    int nRecoveryCount = 0;

    bool isDamaged = false;

     //���� ����
    int nCurMonStage = 0;
    int nMaxMonStage = attacks.size();

    while (nCurMonStage < nMaxMonStage)
    {
        ++nTime;

        int nMonAttackTime = attacks[nCurMonStage][0];

		//Mon Attack Evenets
		if (nTime >= nMonAttackTime)
		{
            int nMonPower = attacks[nCurMonStage][1];

			++nCurMonStage;

            //Player State
			nCurHealth -= nMonPower;
			nRecoveryCount = 0;
			isDamaged = true;

            if (nCurHealth <= 0) break;
		}

        //Not Take Damage Heal Events
        if(!isDamaged)
        {
            int nPlayerHealSec   = bandage[1];
            int nPlayerHealBonus = bandage[0];

            ++nRecoveryCount;
            if (nCurHealth < maxHealth)
            {
                nCurHealth += nPlayerHealSec;
            }

            if (nRecoveryCount >= bandage[0])
            {
                nCurHealth += bandage[2];
                nRecoveryCount = 0;
            }

            if (nCurHealth >= maxHealth) nCurHealth = maxHealth;
        }
        else //Take Damage Events
        {
            isDamaged = false;
        }
    }

    if (nCurHealth <= 0) nCurHealth = -1;
    answer = nCurHealth;

    return answer;
}

int main()
{
    vector<int> bandage = { 4, 2, 7 };
     int health = 20;
     vector<vector<int>> attacks = { {1, 15} ,{5, 16},{8, 6} };

     cout << solution(bandage, health, attacks) << endl;

	return 0;
}

//bandage	health	attacks	                                  result
//[5, 1, 5]	  30     [[2, 10], [9, 15], [10, 5], [11, 5]]        5
//[3, 2, 7]	  20     [[1, 15], [5, 16], [8, 6]]                 - 1
//[4, 2, 7]	  20      [[1, 15], [5, 16], [8, 6]]                - 1
//[1, 1, 1]  	5      [[1, 2], [3, 2]]                          3
