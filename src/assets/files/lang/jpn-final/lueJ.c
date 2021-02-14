#include <ultra64.h>

char *lang[] = {
	/*  0*/ "|�܀₄��������\n\n�䂅�Ҁ�����ρ����Ɂʁ态�灋���˃Á����ڂ��ςׁʂ؁́ā�́Ł؁��ɀ��恻�̀�����ρ����Ɂʁӄ��҅����������Ӏ��Ѐ������ւ�����ɀ��������ρ���䂅�Ҁ܁��с态���փ�҂����߁����ƃ������ɂ��Ł́��ɀ��ҁ҂����Ӂȁ҃��փ�҂�������\n\n|�րˀ��π�π�\n\n���ӁρÁ�ӂ䂅�ρ́��̂����҄��ف��߀݃���ρ΁⃝�π�������ρ����������Ɓ�ҁ����ڃ҂��ρӃԃ��΂͂��恺�ခ�ȁ�Ӏ���π々�т��܀�ρ҂݁ρӂ������ā΁���܁����Ɂ����ҁҀ�ʀۀ̀ρ�Ӏ����ԁҀ܁��с҃ˁ惥�����Ӂ���ہӄ����҂������ςʂ́Ł́����΀�\n\n|�����������������ۀ܀�������΁ǁ�\n\n�ÁҀ��������ۀ܀���π��䂅�Ҁ�����ρ����Ҁ܀���܃��ځӂɂ΁��、�����҂��Å��׀����ʀ�ςׁʂ؁́ā�Ɂҁ����҂������҃Ӄ��������Ɓ�ɁہρӀ��ÁҀ��������ۀ܀���Ҁـπ���������ʀへ�����󅣂΁Ɓ⃇���恺��������ȁ�Ӏ����́Ҁ�рπ��ـρ��̂��߁ς��؁�Ɂ߁��΃���ρ���Ӂ����\n\n|���������σ����πՁ��݀ʀ�ǁ�\n\n�Ӏ��Ѐ����҂��̀݀׀ۀ̀ρӀ��������΁��݀ʀ����΁��߁��ρ΁��́���ˁ؁�䂅�҃σ��ۀ܀���܀����悘�́ς����Ƀ��΁�����΁��΁��́Ł؁��ҁ��Áへ����Ɂہπ������������ҁ��������Ѐπ��π��σ����πՁ��݀ʀ�Ł́��������恺���\n\n|�����������Å��׀����ʀへ�΂ρǁ�\n\n���������ۀ܀�����΂ρŁ́܀����ˁρ�����Å��׀����ʀ�ȁҁ܁ҁ恂�ˀ�΄օ؁������΄���Áへ�΂ρŁ́����ҁ��䂅����݁ŁɃ�����ӂ��ˁπ��ˁ����Ɂ态�܁����Ł��₡���߁܁����\n\n|�������������ʀӀ��Ёքт��ǁ�\n\n�����������؁́܁ς���ҁӃ����څ�΁ҁ󀁅����ʀӀ��ЁցӀӀ������߂��������̄т��Ɓ�ҁ�߁����䁼�䂅�Ҁ܁��с����҄��ρ߁�����Ӏ������߂����ā��ƁρӀՂ����ւ��惇���󀁃ۄ��������߁��Á́�����ȁ�����\n\n|�����������ԁҀ܁��с̈́΃��ǁ�\n\n�䂅�Ҁ܁��сӄ����҂������ςʂ́Ł́���Ɂۀ������Ӏ��Ё����Ɓ����́��Á́ӆ������ŁɁ恴�̂��҂ԁ����ہ��Ɂˁ⃇���恺������ʀӀ��ЁӀ�����Ђ�����态�ہӁȁҁ���み�ρ���́ҁÁ́������΁���ȁニ�ˁ҄��Ӂ΁���\n\nEND\n",
	/*  1*/ "�Ӏ��Ѐ���������",
	/*  2*/ "|�܀₄��������\n\n�䂅�Ҁ�����ρ����Ɂʁ态�灋���˃Á����ڂ��ςׁʂ؁́ā�́Ł؁��ɀ��恻�̀�����ρ����Ɂʁӄ��҅����������Ӏ��Ѐ������ւ�����ɀ��������ρ���䂅�Ҁ܁��с态���փ�҂����߁����ƃ������ɂ��Ł́��ɀ��ҁ҂����Ӂȁ҃��փ�҂�������\n\n|�րˀ��π�π�\n\n���ӁρÁ�ӂ䂅�ρ́��̂����҄��ف��߀݃���ρ΁⃝�π�������ρ����������Ɓ�ҁ����ڃ҂��ρӃԃ��΂͂��恺�ခ�ȁ�Ӏ���π々�т��܀�ρ҂݁ρӂ������ā΁���܁����Ɂ����ҁҀ�ʀۀ̀ρ�Ӏ����ԁҀ܁��с҃ˁ惥�����Ӂ���ہӄ����҂������ςʂ́Ł́����΀�\n\n|�����������������ۀ܀�������΁ǁ�\n\n�ÁҀ��������ۀ܀���π��䂅�Ҁ�����ρ����Ҁ܀���܃��ځӂɂ΁��、�����҂��Å��׀����ʀ�ςׁʂ؁́ā�Ɂҁ����҂������҃Ӄ��������Ɓ�ɁہρӀ��ÁҀ��������ۀ܀���Ҁـπ���������ʀへ�����󅣂΁Ɓ⃇���恺��������ȁ�Ӏ����́Ҁ�рπ��ـρ��̂��߁ς��؁�Ɂ߁��΃���ρ���Ӂ����\n\n|���������σ����πՁ��݀ʀ�ǁ�\n\n�Ӏ��Ѐ����҂��̀݀׀ۀ̀ρӀ��������΁��݀ʀ����΁��߁��ρ΁��́���ˁ؁�䂅�҃σ��ۀ܀���܀����悘�́ς����Ƀ��΁�����΁��΁��́Ł؁��ҁ��Áへ����Ɂہπ������������ҁ��������Ѐπ��π��σ����πՁ��݀ʀ�Ł́��������恺���\n\n|�������������ʀӀ��Ёքт��ǁ�\n\n�����������؁́܁ς���ҁӃ����څ�΁ҁ󀁅����ʀӀ��ЁցӀӀ������߂��������̄т��Ɓ�ҁ�߁����䁼�䂅�Ҁ܁��с����҄��ρ߁�����Ӏ������߂����ā��ƁρӀՂ����ւ��惇���󀁃ۄ��������߁��Á́�����ȁ�����\n\n|�����������ԁҀ܁��с̈́΃��ǁ�\n\n�䂅�Ҁ܁��сӄ����҂������ςʂ́Ł́���Ɂۀ������Ӏ��Ё����Ɓ����́��Á́ӆ������ŁɁ恴�̂��҂ԁ����ہ��Ɂˁ⃇���恺������ʀӀ��ЁӀ�����Ђ�����态�ہӁȁҁ���み�ρ���́ҁÁ́������΁���ȁニ�ˁ҄��Ӂ΁���\n\nEND\n",
	/*  3*/ "|�܀₄��������\n\n�䂅�Ҁ�����ρ����Ɂʁ态�灋���˃Á����ڂ��ςׁʂ؁́ā�́Ł؁��ɀ��恻�̀�����ρ����Ɂʁӄ��҅����������Ӏ��Ѐ������ւ�����ɀ��������ρ���䂅�Ҁ܁��с态���փ�҂����߁����ƃ������ɂ��Ł́��ɀ��ҁ҂����Ӂȁ҃��փ�҂�������\n\n|�րˀ��π�π�\n\n���ӁρÁ�ӂ䂅�ρ́��̂����҄��ف��߀݃���ρ΁⃝�π�������ρ����������Ɓ�ҁ����ڃ҂��ρӃԃ��΂͂��恺�ခ�ȁ�Ӏ���π々�т��܀�ρ҂݁ρӂ������ā΁���܁����Ɂ����ҁҀ�ʀۀ̀ρ�Ӏ����ԁҀ܁��с҃ˁ惥�����Ӂ���ہӄ����҂������ςʂ́Ł́����΀�\n\n|�����������������ۀ܀�������΁ǁ�\n\n�ÁҀ��������ۀ܀���π��䂅�Ҁ�����ρ����Ҁ܀���܃��ځӂɂ΁��、�����҂��Å��׀����ʀ�ςׁʂ؁́ā�Ɂҁ����҂������҃Ӄ��������Ɓ�ɁہρӀ��ÁҀ��������ۀ܀���Ҁـπ���������ʀへ�����󅣂΁Ɓ⃇���恺��������ȁ�Ӏ����́Ҁ�рπ��ـρ��̂��߁ς��؁�Ɂ߁��΃���ρ���Ӂ����\n\n|�������������ʀӀ��Ёքт��ǁ�\n\n�����������؁́܁ς���ҁӃ����څ�΁ҁ󀁅����ʀӀ��ЁցӀӀ������߂��������̄т��Ɓ�ҁ�߁����䁼�䂅�Ҁ܁��с����҄��ρ߁�����Ӏ������߂����ā��ƁρӀՂ����ւ��惇���󀁃ۄ��������߁��Á́�����ȁ�����\n\n|�����������ԁҀ܁��с̈́΃��ǁ�\n\n�䂅�Ҁ܁��сӄ����҂������ςʂ́Ł́���Ɂۀ������Ӏ��Ё����Ɓ����́��Á́ӆ������ŁɁ恴�̂��҂ԁ����ہ��Ɂˁ⃇���恺������ʀӀ��ЁӀ�����Ђ�����态�ہӁȁҁ���み�ρ���́ҁÁ́������΁���ȁニ�ˁ҄��Ӂ΁���\n\nEND\n",
	/*  4*/ "\n",
	/*  5*/ "\n",
	/*  6*/ "\n",
	/*  7*/ "\n",
	/*  8*/ "\n",
	/*  9*/ "���������ۀ܀�������΁ǁ�\n",
	/* 10*/ "�σ����πՁ��݀ʀ�ǁ�\n",
	/* 11*/ "���Å��׀����ʀへ�΂ρǁ�\n",
	/* 12*/ "�����ʀӀ��Ёքт��ǁ�\n",
	/* 13*/ "���ԁҀ܁��с̈́΃��ǁ�\n",
	/* 14*/ "Obtain grenades.\n",
	/* 15*/ "Dr. Caroll's\n",
	/* 16*/ "�݁ၶ����\n",
	/* 17*/ "�݁ၶ����\n",
	/* 18*/ "�݁ၶ�������݁ς����\n",
	/* 19*/ "���Å��׀����ʀへ�΂ρŁ�\n",
	/* 20*/ "���́҂��Å��׀����ʀへ�΂ρŁ�\n",
	/* 21*/ "Obtain comms rider.\n",
	/* 22*/ "Dr. Caroll's\n",
	/* 23*/ "�σ����π�\n",
	/* 24*/ "�σ����π�\n",
	/* 25*/ "�σ����πՁ��݁ς����\n",
	/* 26*/ "�σ����πՁ慠�Ł��݀ʀ�ā��\n",
	/* 27*/ "�σ����πՁ慠�Ł��݀ʀ�ā�́��؁ǁ�\n",
	/* 28*/ "�Ѐπ���΂ρā��\n",
	/* 29*/ "�Ѐπ���ˆ��Ł�\n",
	/* 30*/ "�Ѐπ���̅�Ł�\n",
	/* 31*/ "Obtain lift key card.\n",
	/* 32*/ "Dr. Caroll's\n",
	/* 33*/ "�Ղ����ւ�\n",
	/* 34*/ "�Ղ����ւ�\n",
	/* 35*/ "�Ӏ������߂��ҀՂ����ւ����݁ς����\n",
	/* 36*/ "�Ӏ������߂��ցҀЀ׀݀܄ڄۀ�\n�Ղ����ւ��惇��\n",
	/* 37*/ "�Ղ����ւ��Ǆ耨�����Ӏ������߂��ۂĄׄ�\n",
	/* 38*/ "�Ӏ������߂��⃈����\n",
	/* 39*/ "�����ʀӀ��Ёքт��Ł�\n",
	/* 40*/ "���ԁҀ܁��с̈́΃��Ł�\n",
	/* 41*/ "���������ۀ܀���慣�΁ā��\n",
	/* 42*/ "�������ځς������΃�����΂ρā��\n",
	/* 43*/ "��рπ������ׁ���\n",
	/* 44*/ "��рπ�����慐��ā��\n",
	/* 45*/ "�Ѐ׀݀܁�ڄہā��\n",
	/* 46*/ "������݀ʀ�ā��\n",
	/* 47*/ "�т���Ȃɀ��݀ր̀���ƀۀ܀���ۂ�\n",
	/* 48*/ "Obtain explosive.\n",
	/* 49*/ "Dr. Caroll's\n",
	/* 50*/ "����\n",
	/* 51*/ "����\n",
	/* 52*/ "�������݁ς����\n",
	/* 53*/ "���������ۀ܀���Ҁـπ��������\n�ȁ҂��̅����Ł���\n",
	/* 54*/ "�����Ѐπ��р�܀������΁σށ���\n����́܅܁��΁��倎\n",
	/* 55*/ "�����ʀӀ��ЁցҀӀ������߂���\n�ÁҀ�рπ�����҃��Á��р�\n",
	/* 56*/ "�ӂ����Ȁπ々�����׀��Áʁ����̀�ڀρ���\n�Ԁ��ӂ������҅����󂼁��ρ��ⁿ��\n�ׁˁ΁߀�\n",
	/* 57*/ "�Ӏ������߂��Ҁـπ�������͂���΂ρā��\n",
	/* 58*/ "���̀Ѐπ�Á҃����ӀӀ��Ѐ�����\n�����Łɂ䂅�Ҁ܁��с�݂��ŁɁ܁ҁ���\n",
	/* 59*/ "�ÁÁ悧�҄т����рπ�������҅Ё�\n���؁�����́��΁�������������\n",
	/* 60*/ "�Á҆����ł΁Ɓ�ҁ���\n�Ł��ł����ρӃ����ˁ��\n",
	/* 61*/ "�Áҁ��������Ѐπ���\n�����Ҁ�рσσ������󁺁��\np������܂����ρӃ����ˁ��\n",
	/* 62*/ "�������Á『��\n",
	/* 63*/ "�Á�懎�Ҁ�����ρ�������\n�������񁴁́���߁�����\np�����ӂ��ρ�Ҁ�܀へ����\n�Ɓ�ς������؁ہ�߁�����\n",
	/* 64*/ "��܀��΁��\n",
	/* 65*/ "�ڄ��Ӏ������Ł����߁�Ł���\n��Ӏ����������Ɂ؁���\n",
	/* 66*/ "����������ʀۀ̀υ�����\n�Ӏ��Ѐ����τт��ׄ؀�\n",
	/* 67*/ "�ӂ����Ȁπ々�����׀��Á��ʁ���\n",
	/* 68*/ "���΁Ɂ恂�̀�ڀπ�\n���Ӂ́����ဎ\n",
	/* 69*/ "���́����ဈ�􁼁ŁɁ��̀�\n",
	/* 70*/ "���΁Ɂ҅����Ӂ����Ɂ����̈́����́��Ɂ��\n�Á��΁݁�ԁ󀁁߁������́Á�Ɂ�р�\n",
	/* 71*/ "���ҁ��π��������́݁��Ɂ����\n",
	/* 72*/ "���ҁ��π���\n",
	/* 73*/ "�ȁ��������ӁÁ��ˁςׁɁ�Ɂ����Ɂҁ���\n�΁��΁������҂��������܁��̈́Ձ�������\n",
	/* 74*/ "�偿���Ɂ�܁��߁Ł؁Ł���\n�����΃�����ɁÁ́��ㅜ�Ɓ���\n",
	/* 75*/ "�����ǁ҃�����Łā�ɀ����������ǁ�\n",
};