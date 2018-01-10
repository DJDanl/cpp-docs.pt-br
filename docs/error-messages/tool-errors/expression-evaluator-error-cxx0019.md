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
ms.workload: cplusplus
ms.openlocfilehash: c62391bb770a49810a87c52b2f75d5a0d4426fbd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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