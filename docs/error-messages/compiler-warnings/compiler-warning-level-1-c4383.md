---
title: Compilador (nível 1) de aviso C4383 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4383
dev_langs:
- C++
helpviewer_keywords:
- C4383
ms.assetid: 96c0e52d-874e-4b57-a154-0e49b6a00fae
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b78209cf4e3e320cca8b161a4e6c99eaca6d771c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4383"></a>Compilador C4383 de aviso (nível 1)
'instance_dereference_operator': o significado de desreferenciar um identificador pode mudar, quando existe um operador definido pelo usuário 'operator'; Escreva o operador como uma função estática para ser explícito sobre o operando  
  
 Quando você adiciona uma substituição de instância definida pelo usuário do operador de desreferenciamento em um tipo gerenciado, você possivelmente substituir a capacidade do operador de desreferenciamento do tipo para retornar objeto o identificador do. Considere a possibilidade de gravar um estático, definido pelo usuário de operador de cancelamento.  
  
 Para obter mais informações, consulte [operador Handle to Object (^)](../../windows/handle-to-object-operator-hat-cpp-component-extensions.md) e [operador de referência de rastreamento](../../windows/tracking-reference-operator-cpp-component-extensions.md).  
  
 Além disso, um operador de instância não está disponível para outros compiladores de linguagem por meio de metadados referenciado. Para obter mais informações, consulte [operadores definidos pelo usuário (C + + CLI)](../../dotnet/user-defined-operators-cpp-cli.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4383.  
  
```  
// C4383.cpp  
// compile with: /clr /W1  
  
ref struct S {  
   int operator*() { return 0; }   // C4383  
};  
  
ref struct T {  
   static int operator*(T%) { return 0; }  
};   
  
int main() {  
   S s;  
   S^ pS = %s;  
  
   T t;  
   T^ pT = %t;  
   T% rT = *pT;  
}  
```