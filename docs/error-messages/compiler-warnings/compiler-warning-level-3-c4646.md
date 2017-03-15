---
title: "Compilador aviso (nível 3) C4646 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4646
dev_langs:
- C++
helpviewer_keywords:
- C4646
ms.assetid: 23677e8e-603e-40e0-b99a-2e4894a1278e
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
ms.openlocfilehash: d48e393668fbe04567a066d8a5053dd6fc8ee5e7
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-3-c4646"></a>Compilador C4646 de aviso (nível 3)
função declarada com __declspec(noreturn) possui tipo de retorno diferente de void  
  
 Uma função marcada com o [noreturn](../../cpp/noreturn.md) `__declspec` modificador deve ter uma [void](../../cpp/void-cpp.md) tipo de retorno.  
  
 O exemplo a seguir gera C4646:  
  
```  
// C4646.cpp  
// compile with: /W3 /WX  
int __declspec(noreturn) TestFunction()  
{   // C4646  make return type void  
}  
```
