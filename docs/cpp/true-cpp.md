---
title: True (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- true_cpp
dev_langs:
- C++
helpviewer_keywords:
- true keyword [C++]
ms.assetid: 96be2a70-51c3-4250-9752-874d25a5a11e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5a469b47d54cef9084ba686538219d62a2d5ec50
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37942150"
---
# <a name="true-c"></a>true (C++)
## <a name="syntax"></a>Sintaxe  
  
```  
  
bool-identifier = true ;  
bool-expression logical-operator true ;  
```  
  
## <a name="remarks"></a>Comentários  
 Essa palavra-chave é um dos dois valores para uma variável do tipo [bool](../cpp/bool-cpp.md) ou uma expressão condicional (uma expressão condicional agora é uma expressão booliana true). Se `i` é do tipo **bool**, em seguida, a instrução `i = true;` atribui **verdadeiro** para `i`.  
  
## <a name="example"></a>Exemplo  
  
```cpp 
// bool_true.cpp  
#include <stdio.h>  
int main()  
{  
    bool bb = true;  
    printf_s("%d\n", bb);  
    bb = false;  
    printf_s("%d\n", bb);  
}  
```  
  
```Output  
1  
0  
```  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)