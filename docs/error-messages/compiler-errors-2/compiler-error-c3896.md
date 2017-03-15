---
title: C3896 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3896
dev_langs:
- C++
helpviewer_keywords:
- C3896
ms.assetid: eb8be0f6-5b4e-4d71-8285-8a2a94f8ba29
caps.latest.revision: 7
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
ms.openlocfilehash: 8eb96071ae0065a3025c46bdb3a489870de16812
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3896"></a>C3896 de erro do compilador
'member': inicializador inadequado: esse membro de dados literais só pode ser inicializado com 'nullptr'  
  
 A [literal](../../windows/literal-cpp-component-extensions.md) membro de dados foi inicializado incorretamente.  Consulte [nullptr](../../windows/nullptr-cpp-component-extensions.md) para obter mais informações.  
  
 O exemplo a seguir gera C3896:  
  
```  
// C3896.cpp  
// compile with: /clr /c  
ref class R{};  
  
value class V {  
   literal R ^ r = "test";   // C3896  
   literal R ^ r2 = nullptr;   // OK  
};  
```
