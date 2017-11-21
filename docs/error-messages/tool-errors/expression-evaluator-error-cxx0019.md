---
title: "CXX0019 de erro do avaliador de expressão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: CXX0019
dev_langs: C++
helpviewer_keywords:
- CXX0019
- CAN0019
ms.assetid: 4c6431fd-3310-4a61-934d-58b070b330fe
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 67fbd43280ad6ffcecdf0532819cd80a0d44b479
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="expression-evaluator-error-cxx0019"></a>Erro CXX0019 (avaliador de expressão)
conversão de tipo incorreto  
  
 O avaliador de expressão C não é possível executar a conversão como escrito de tipo.  
  
 Esse erro é idêntico ao CAN0019.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  O tipo especificado é desconhecido.  
  
2.  Havia muitos níveis de tipos de ponteiro. Por exemplo, a conversão de tipos  
  
    ```  
    (char **)h_message  
    ```  
  
     não pode ser avaliada pelo avaliador de expressão C.