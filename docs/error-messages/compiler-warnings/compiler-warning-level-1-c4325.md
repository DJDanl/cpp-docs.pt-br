---
title: Compilador (nível 1) de aviso C4325 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4325
dev_langs:
- C++
helpviewer_keywords:
- C4325
ms.assetid: 8127a08c-d626-481b-aa7b-04a3fdc9a9ec
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 936433987f823ae7d5d22cfd075f188dd5d4b1e4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33277638"
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