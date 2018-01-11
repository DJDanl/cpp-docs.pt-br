---
title: C3541 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3541
dev_langs: C++
helpviewer_keywords: C3541
ms.assetid: 252cfd4c-5fd2-415e-a17d-6b0c254350db
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: eeef2650dd772784ceee5e7802a46650e4cfcbe1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3541"></a>C3541 de erro do compilador
'type': typeid não pode ser aplicado a um tipo que contém 'auto'  
  
 O [typeid](../../windows/typeid-cpp-component-extensions.md) operador não pode ser aplicado para o tipo indicado porque ele contém o `auto` especificador.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir produz C3541.  
  
```  
// C3541.cpp  
// Compile with /Zc:auto  
#include <typeinfo>  
int main() {  
    auto x = 123;  
    typeid(x);    // OK  
    typeid(auto); // C3541  
    return 0;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [palavra-chave auto](../../cpp/auto-keyword.md)   
 [/ZC: auto (deduzir tipo variável)](../../build/reference/zc-auto-deduce-variable-type.md)   
 [TypeId](../../windows/typeid-cpp-component-extensions.md)