---
title: Regras predefinidas | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- rules, predefined
- NMAKE program, predefined rules
- predefined rules in NMAKE
ms.assetid: 638cdc3f-4aba-4b4f-96e3-ad65b0364f12
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3be1c8eea7b11f60e9ce9a7cbf5ebc0c2b99b698
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="predefined-rules"></a>Regras predefinidas
Regras de inferência predefinidos usam macros de comando e opções de NMAKE fornecido.  
  
|Regra|Comando|Padrão<br /><br /> ação|Lote<br /><br /> Regra|Plataforma nmake é executado em|  
|----------|-------------|------------------------|--------------------|----------------------------|  
|. asm.exe|$(AS) $(AFLAGS) $<|$ ML <|no|x86|  
|. asm.obj|$(AS) $(AFLAGS) /c $<|ML /c $<|sim|x86|  
|. asm.exe|$(AS) $(AFLAGS) $<|$ ml64 <|no|[!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
|. asm.obj|$(AS) $(AFLAGS) /c $<|ml64 /c $<|sim|[!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
|. c.exe|$(CC) $(CFLAGS) $<|Cl $<|no|all|  
|. c.obj|$(CC) $(CFLAGS) /c $<|Cl /c $<|sim|all|  
|. cc.exe|$(CC) $(CFLAGS) $<|Cl $<|no|all|  
|. cc.obj|$(CC) $(CFLAGS) /c $<|Cl /c $<|sim|all|  
|. cpp.exe|$(CPP) $(CPPFLAGS) $<|Cl $<|no|all|  
|. cpp.obj|$(CPP) $(CPPFLAGS) /c $<|Cl /c $<|sim|all|  
|. cxx.exe|$(CXX) $(CXXFLAGS) $<|Cl $<|no|all|  
|. cxx.obj|$(CXX) $(CXXFLAGS) /c $<|Cl /c $<|sim|all|  
|. rc.res|$(RC) $(RFLAGS) /r $<|/r RC $<|no|all|  
  
## <a name="see-also"></a>Consulte também  
 [Regras de inferência](../build/inference-rules.md)