---
title: Regras predefinidas
ms.date: 11/04/2016
helpviewer_keywords:
- rules, predefined
- NMAKE program, predefined rules
- predefined rules in NMAKE
ms.assetid: 638cdc3f-4aba-4b4f-96e3-ad65b0364f12
ms.openlocfilehash: b4b8ca7b0126ca42b2144aa094e7f766f6344b2a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50609680"
---
# <a name="predefined-rules"></a>Regras predefinidas

Regras de inferência de tipos predefinidos usam macros de comando e as opções fornecidas pelo NMAKE.

|Regra|Comando|Padrão<br /><br /> ação|Lote<br /><br /> Regra|Plataforma nmake é executado em|
|----------|-------------|------------------------|--------------------|----------------------------|
|. asm.exe|$(AS) $(AFLAGS) $&LT;|ML $<|no|x86|
|. asm.obj|$(AS) $(AFLAGS) /c $<|ML /c $<|sim|x86|
|. asm.exe|$(AS) $(AFLAGS) $&LT;|$ ml64 <|no|X64|
|. asm.obj|$(AS) $(AFLAGS) /c $<|ml64 /c $<|sim|X64|
|. c.exe|$(CC) $(CFLAGS) $&LT;|Cl $<|no|all|
|. c.obj|$(CC) $(CFLAGS) /c $<|Cl /c $<|sim|all|
|. cc.exe|$(CC) $(CFLAGS) $&LT;|Cl $<|no|all|
|. cc.obj|$(CC) $(CFLAGS) /c $<|Cl /c $<|sim|all|
|. cpp.exe|$(CPP) $(CPPFLAGS) $&LT;|Cl $<|no|all|
|. cpp.obj|$(CPP) $(CPPFLAGS) /c $<|Cl /c $<|sim|all|
|. cxx.exe|$(CXX) $(CXXFLAGS) $&LT;|Cl $<|no|all|
|. cxx.obj|$(CXX) $(CXXFLAGS) /c $<|Cl /c $<|sim|all|
|. rc.res|$(RC) $(RFLAGS) /r $<|/r RC $<|no|all|

## <a name="see-also"></a>Consulte também

[Regras de inferência](../build/inference-rules.md)