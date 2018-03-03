---
title: "Compilador (nível 1) de aviso C4325 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4325
dev_langs:
- C++
helpviewer_keywords:
- C4325
ms.assetid: 8127a08c-d626-481b-aa7b-04a3fdc9a9ec
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ab31150efc02601d7392470198e162e979ac4917
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4325"></a>Compilador C4325 de aviso (nível 1)
**atributos para seção padrão '**   
 ***seção* ' ignorado**  
  
 Você não pode alterar os atributos de uma seção padrão. Por exemplo:  
  
```  
#pragma section(".sdata", long)  
```  
  
 Isso substituiria o `.sdata` seção padrão que usa o **curto** tipo de dados com o **longo** tipo de dados.  
  
 Incluem seções padrão cujos atributos não pode ser alterado,  
  
-   . Data  
  
-   .sdata  
  
-   .BSS  
  
-   . sbss  
  
-   . Text  
  
-   . const  
  
-   .sconst  
  
-   RDATA  
  
-   .srdata  
  
 Seções adicionais podem ser adicionadas posteriormente.  
  
## <a name="see-also"></a>Consulte também  
 [seção](../../preprocessor/section.md)