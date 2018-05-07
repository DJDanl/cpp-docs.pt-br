---
title: C4972 de aviso do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4972
dev_langs:
- C++
helpviewer_keywords:
- C4972
ms.assetid: d18e8e65-b2ef-4d75-a207-fbd0c17c9060
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bf5337a60781c6fb39281f051657ea7ebd9371fa
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-c4972"></a>C4972 de aviso do compilador
Modificar diretamente ou tratar o resultado de uma operação de unbox como um lvalue não é verificável  
  
 Não é verificável desreferenciar um identificador para um tipo de valor, também conhecido como unboxing e, em seguida, atribuí-lo.  
  
 Para obter mais informações, consulte [Boxing](../../windows/boxing-cpp-component-extensions.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4972.  
  
```  
// C4972.cpp  
// compile with: /clr:safe  
using namespace System;  
ref struct R {  
   int ^ p;   // a value type  
};  
  
int main() {  
   R ^ r = gcnew R;  
   *(r->p) = 10;   // C4972  
  
   // OK  
   r->p = 10;  
   Console::WriteLine( r->p );  
   Console::WriteLine( *(r->p) );  
}  
```