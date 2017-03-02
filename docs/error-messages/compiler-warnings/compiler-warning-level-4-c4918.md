---
title: "Compilador aviso (nível 4) C4918 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4918
dev_langs:
- C++
helpviewer_keywords:
- C4918
ms.assetid: 1bcf6d35-3467-4aa8-b2ef-cb33f4e70238
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: f8d9b0bbb86e5fbcaaf06d21fd83b1a0304fe84f
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4918"></a>Compilador C4918 de aviso (nível 4)
'character': caractere inválido na lista de otimização do pragma  
  
 Um caractere desconhecido foi encontrado na lista de otimização de um [otimizar](../../preprocessor/optimize.md) instrução pragma.  
  
 Por exemplo, a instrução a seguir gera C4918:  
  
```  
// C4918.cpp  
// compile with: /W4  
#pragma optimize("X", on) // C4918 expected  
int main()  
{  
}  
```
