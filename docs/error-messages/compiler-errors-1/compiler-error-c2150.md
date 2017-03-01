---
title: C2150 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2150
dev_langs:
- C++
helpviewer_keywords:
- C2150
ms.assetid: 21e82a10-c1d4-4c0d-9dc6-c5d92ea42a31
caps.latest.revision: 9
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
ms.openlocfilehash: d704d927938089b912d92468620b18fcb375ec40
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2150"></a>C2150 de erro do compilador
'identifier': campo de bit deve ter tipo 'int', 'int com sinal' ou 'unsigned int'  
  
 os campos de bits devem ser `int`, `signed``int`, ou `unsigned``int`.  
  
 O exemplo a seguir gera C2150:  
  
```  
// C2150.cpp  
// compile with: /c  
struct A {  
   float a : 8;    // C2150  
   int i : 8;   // OK  
};  
```
