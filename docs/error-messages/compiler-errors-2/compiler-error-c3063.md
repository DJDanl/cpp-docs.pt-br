---
title: C3063 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3063
dev_langs:
- C++
helpviewer_keywords:
- C3063
ms.assetid: 0ecf6f1f-e4a7-487a-9fd5-79d8ac470001
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 68809002b2c895387cd10d33615ec9d6c7a6b861
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3063"></a>C3063 de erro do compilador
operador 'operator': todos os operandos devem ter o mesmo tipo de enumeração  
  
Ao usar operadores em enumeradores, ambos os operandos devem ser do tipo de enumeração. Para obter mais informações, consulte [como: definir e consumir enumerações em C + + CLI](../../dotnet/how-to-define-and-consume-enums-in-cpp-cli.md).  
  
## <a name="example"></a>Exemplo  
O exemplo a seguir gera C3063 e mostra como corrigi-lo:  
  
```  
// C3063.cpp  
// compile with: /clr  
enum class E { a, b } e, mask;  
int main() {  
   if ( ( e & mask ) != 0 ) ;   // C3063 no operator!= (E, int)  
  
   if ( ( e & mask ) != E() )   // OK  
      ;  
}  
```