---
title: Regras predefinidas
ms.date: 11/04/2016
helpviewer_keywords:
- rules, predefined
- NMAKE program, predefined rules
- predefined rules in NMAKE
ms.assetid: 638cdc3f-4aba-4b4f-96e3-ad65b0364f12
ms.openlocfilehash: 7a922a239306f10121791caa8f9f088cea88c019
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824407"
---
# <a name="predefined-rules"></a>Regras predefinidas

Regras de inferência de tipos predefinidos usam macros de comando e as opções fornecidas pelo NMAKE.

|Regra|Comando|Padrão<br /><br /> ação|Lote<br /><br /> Regra|Plataforma nmake é executado em|
|----------|-------------|------------------------|--------------------|----------------------------|
|.asm.exe|$(AS) $(AFLAGS) $&LT;|ML $<|no|x86|
|.asm.obj|$(AS) $(AFLAGS) /c $<|ml /c $<|sim|x86|
|.asm.exe|$(AS) $(AFLAGS) $&LT;|ml64 $<|no|X64|
|.asm.obj|$(AS) $(AFLAGS) /c $<|ml64 /c $<|sim|X64|
|.c.exe|$(CC) $(CFLAGS) $&LT;|Cl $<|no|all|
|.c.obj|$(CC) $(CFLAGS) /c $<|cl /c $<|sim|all|
|.cc.exe|$(CC) $(CFLAGS) $&LT;|Cl $<|no|all|
|.cc.obj|$(CC) $(CFLAGS) /c $<|cl /c $<|sim|all|
|.cpp.exe|$(CPP) $(CPPFLAGS) $&LT;|Cl $<|no|all|
|.cpp.obj|$(CPP) $(CPPFLAGS) /c $<|cl /c $<|sim|all|
|.cxx.exe|$(CXX) $(CXXFLAGS) $&LT;|Cl $<|no|all|
|.cxx.obj|$(CXX) $(CXXFLAGS) /c $<|cl /c $<|sim|all|
|.rc.res|$(RC) $(RFLAGS) /r $<|rc /r $<|no|all|

## <a name="see-also"></a>Consulte também

[Regras de inferência](inference-rules.md)
