---
title: "Compilador aviso (nível 1) C4325 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4325
dev_langs:
- C++
helpviewer_keywords:
- C4325
ms.assetid: 8127a08c-d626-481b-aa7b-04a3fdc9a9ec
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: b6d2838c9b9d94c8d5b95b410f8e98761996b5f8
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4325"></a>Compilador C4325 de aviso (nível 1)
**atributos de seção padrão '**   
 ***seção* ' ignorado**  
  
 Você não pode alterar os atributos de uma seção padrão. Por exemplo:  
  
```  
#pragma section(".sdata", long)  
```  
  
 Isso substituirá o `.sdata` seção padrão que usa o **curto** tipo de dados com o **longo** tipo de dados.  
  
 Incluem seções padrão cujos atributos não podem ser alteradas,  
  
-   . Data  
  
-   .sdata  
  
-   BSS  
  
-   .sbss  
  
-   . Text  
  
-   . const  
  
-   .sconst  
  
-   . RDATA  
  
-   .srdata  
  
 Seções adicionais podem ser adicionadas mais tarde.  
  
## <a name="see-also"></a>Consulte também  
 [seção](../../preprocessor/section.md)
