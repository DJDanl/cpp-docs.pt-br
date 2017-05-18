---
title: "Compilador aviso (nível 1) C4383 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4383
dev_langs:
- C++
helpviewer_keywords:
- C4383
ms.assetid: 96c0e52d-874e-4b57-a154-0e49b6a00fae
caps.latest.revision: 6
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
ms.openlocfilehash: 2bba10dcb60e8df3b4a8b0f3fd0dce8f46068853
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4383"></a>Compilador C4383 de aviso (nível 1)
'instance_dereference_operator': o significado de um identificador de referência pode mudar, existe um operador definido pelo usuário 'operator'; Escreva o operador como uma função estática para ser explícito sobre o operando  
  
 Quando você adiciona uma substituição de instância definidos pelo usuário do operador de desreferenciamento em um tipo gerenciado, você possivelmente substituir a capacidade do operador de desreferenciamento do tipo para retornar objeto o identificador do. Considere escrever um estático, definido pelo usuário de operador de cancelamento.  
  
 Para obter mais informações, consulte [operador Handle to Object (^)](../../windows/handle-to-object-operator-hat-cpp-component-extensions.md) e [operador de referência de controle](../../windows/tracking-reference-operator-cpp-component-extensions.md).  
  
 Além disso, um operador de instância não está disponível para outros compiladores de linguagem via metadados referenciado. Para obter mais informações, consulte [operadores definidos pelo usuário (C + + / CLI)](../../dotnet/user-defined-operators-cpp-cli.md).  
  
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
