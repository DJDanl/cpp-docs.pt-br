---
title: "CXX0019 de erro do avaliador de expressão | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- CXX0019
dev_langs:
- C++
helpviewer_keywords:
- CXX0019
- CAN0019
ms.assetid: 4c6431fd-3310-4a61-934d-58b070b330fe
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
ms.openlocfilehash: 0fac97ac9d0d29fad06d546cb6c187ad65c8839c
ms.lasthandoff: 02/25/2017

---
# <a name="expression-evaluator-error-cxx0019"></a>Erro CXX0019 (avaliador de expressão)
conversão de tipo incorreto  
  
 O avaliador de expressão C não é possível executar o tipo de conversão como escrito.  
  
 Esse erro é idêntico ao CAN0019.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  O tipo especificado é desconhecido.  
  
2.  Havia muitos níveis de tipos de ponteiro. Por exemplo, a conversão de tipos  
  
    ```  
    (char **)h_message  
    ```  
  
     não pode ser avaliada pelo avaliador de expressão C.
