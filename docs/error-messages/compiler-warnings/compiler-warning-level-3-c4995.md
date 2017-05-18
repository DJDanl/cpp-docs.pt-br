---
title: "Compilador aviso (nível 3) C4995 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4995
dev_langs:
- C++
helpviewer_keywords:
- C4995
ms.assetid: c6b61755-4730-4947-ad4d-d1c2bc82585a
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 253645d6ea22f694e657c3391bdb723b75e086d6
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-3-c4995"></a>Compilador C4995 de aviso (nível 3)
'function': nome foi marcado como #pragma preterido  
  
 O compilador encontrou uma função que foi marcada com o pragma [preterido](../../preprocessor/deprecated-c-cpp.md). A função pode não ter mais suporte em uma versão futura. Você pode desativar esse aviso com a [aviso](../../preprocessor/warning.md) pragma (exemplo abaixo).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4995:  
  
```  
// C4995.cpp  
// compile with: /W3  
#include <stdio.h>  
  
// #pragma warning(disable : 4995)  
void func1(void)  
{  
    printf("\nIn func1");  
}  
  
int main()   
{  
    func1();  
    #pragma deprecated(func1)  
    func1();   // C4995  
}  
```
