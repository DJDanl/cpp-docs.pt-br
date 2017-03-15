---
title: "Compilador aviso (nível 1) C4393 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4393
dev_langs:
- C++
helpviewer_keywords:
- C4393
ms.assetid: 353a0539-d1ea-4c1b-8849-c9b321ec9842
caps.latest.revision: 9
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
ms.openlocfilehash: 16297e4fc8ec8b8af2b0b51e563d7e5ff58a0771
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4393"></a>Compilador C4393 de aviso (nível 1)
'var': const não tem nenhum efeito no membro de dados literais; ignorado  
  
 A [literal](../../windows/literal-cpp-component-extensions.md) membro de dados também foi especificado como constante.  Como um membro de dados literais implica const, você não precisa adicionar const à declaração.  
  
 O exemplo a seguir gera C4393:  
  
```  
// C4393.cpp  
// compile with: /clr /W1 /c  
ref struct Y1 {  
   literal const int staticConst = 10;   // C4393  
   literal int staticConst2 = 10;   // OK  
};  
```
