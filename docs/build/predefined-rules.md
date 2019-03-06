---
title: Regras predefinidas
ms.date: 11/04/2016
helpviewer_keywords:
- rules, predefined
- NMAKE program, predefined rules
- predefined rules in NMAKE
ms.assetid: 638cdc3f-4aba-4b4f-96e3-ad65b0364f12
ms.openlocfilehash: e3b30957c15d6fb4eabb72381bad43a2d622a25d
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57413193"
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

[Regras de inferência](../build/inference-rules.md)
