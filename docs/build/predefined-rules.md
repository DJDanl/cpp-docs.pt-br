---
title: Regras predefinidas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- rules, predefined
- NMAKE program, predefined rules
- predefined rules in NMAKE
ms.assetid: 638cdc3f-4aba-4b4f-96e3-ad65b0364f12
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d0a21847bb9363099fa64825b45a90003de053da
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32369754"
---
# <a name="predefined-rules"></a>Regras predefinidas
Regras de inferência predefinidos usam macros de comando e opções de NMAKE fornecido.  
  
|Regra|Comando|Padrão<br /><br /> ação|Lote<br /><br /> Regra|Plataforma nmake é executado em|  
|----------|-------------|------------------------|--------------------|----------------------------|  
|. asm.exe|$(AS) $(AFLAGS) $&LT;|$ ML <|no|x86|  
|. asm.obj|$(AS) $(AFLAGS) /c $<|ML /c $<|sim|x86|  
|. asm.exe|$(AS) $(AFLAGS) $&LT;|$ ml64 <|no|[!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
|. asm.obj|$(AS) $(AFLAGS) /c $<|ml64 /c $<|sim|[!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
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