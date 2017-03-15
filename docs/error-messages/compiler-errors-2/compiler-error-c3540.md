---
title: C3540 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3540
dev_langs:
- C++
helpviewer_keywords:
- C3540
ms.assetid: 3c0c959c-e3b7-40eb-b922-ccac44bd9d85
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
ms.openlocfilehash: a211e81418dc6354f9e61b2df4b0077b0b6986ba
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3540"></a>C3540 de erro do compilador
'type': sizeof pode ser aplicado a um tipo que contém 'auto'  
  
 O [sizeof](../../cpp/sizeof-operator.md) operador não pode ser aplicado para o tipo indicado porque ela contém o `auto` especificador.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir produz C3540.  
  
```  
// C3540.cpp  
// Compile with /Zc:auto  
int main() {  
    auto x = 123;  
    sizeof(x);    // OK  
    sizeof(auto); // C3540  
    return 0;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [palavra-chave auto](../../cpp/auto-keyword.md)   
 [/ZC: auto (deduzir tipo variável)](../../build/reference/zc-auto-deduce-variable-type.md)   
 [Operador sizeof](../../cpp/sizeof-operator.md)
