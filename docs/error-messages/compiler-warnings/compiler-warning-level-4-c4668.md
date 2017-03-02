---
title: "Compilador aviso (nível 4) C4668 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4668
dev_langs:
- C++
helpviewer_keywords:
- C4668
ms.assetid: c6585460-bc4a-4a15-9242-4cbfce53c961
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: d3af2b5f14a53bb6faa5739475ad5e5d8f3cbb64
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4668"></a>Compilador C4668 de aviso (nível 4)
'symbol' não é definido como uma macro de pré-processador, substituindo por '0' para 'directives'  
  
 Foi usado um símbolo que não foi definido com uma diretiva de pré-processamento. O símbolo será avaliada como false. Para definir um símbolo, você pode usar o [#define diretiva](../../preprocessor/hash-define-directive-c-cpp.md) ou [/D](../../build/reference/d-preprocessor-definitions.md) opção de compilador.  
  
 Esse aviso é desativada por padrão. Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4668:  
  
```  
// C4668.cpp  
// compile with: /W4  
#include <stdio.h>  
  
#pragma warning (default : 4668)   // turn warning on  
  
int main()   
{  
    #if q   // C4668, q is not defined  
        printf_s("defined");  
    #else  
        printf_s("undefined");  
    #endif  
}  
```
