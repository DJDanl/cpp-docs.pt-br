---
title: C2743 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2743
dev_langs:
- C++
helpviewer_keywords:
- C2743
ms.assetid: 644cd444-21d2-471d-a176-f5f52c5a0b73
caps.latest.revision: 8
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
ms.sourcegitcommit: cc82b83860786ffc3f0aee73ede18ecadef16a7a
ms.openlocfilehash: 7420231e64515b556cfe81fc695eda5f75231506
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2743"></a>C2743 de erro do compilador
'type': não é possível capturar um tipo nativo com o destruidor de clrcall ou Construtor de cópia  
  
 Um módulo compilado com **/clr** tentou capturar uma exceção de tipo nativo e onde o tipo destruidor ou Construtor de cópia usa `__clrcall` convenção de chamada.  
  
 Quando compilado com **/clr**, tratamento de exceção espera que as funções de membro em um tipo nativo para ser [cdecl](../../cpp/cdecl.md) e não [clrcall](../../cpp/clrcall.md). Tipos nativos com funções de membro usando `__clrcall` convenção de chamada não pode ser detectada em um módulo compilado com **/clr**.  
  
 Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2743.  
  
```  
// C2743.cpp  
// compile with: /clr  
public struct S {  
   __clrcall ~S() {}  
};  
  
public struct T {  
   ~T() {}  
};  
  
int main() {  
   try {}  
   catch(S) {}   // C2743  
   // try the following line instead  
   // catch(T) {}  
  
   try {}  
   catch(S*) {}   // OK  
}  
```
