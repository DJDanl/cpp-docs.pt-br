---
title: Compilador aviso (nível 1) C4383 | Microsoft Docs
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
ms.openlocfilehash: 1e4ac56b4f94ee6ff7e6ade01dfadca0c00a92db
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46094839"
---
# <a name="compiler-warning-level-1-c4383"></a>Compilador aviso (nível 1) C4383

'instance_dereference_operator': o significado de desreferenciar um identificador pode ser alterado, quando um operador definido pelo usuário 'operator' não existe; Escreva o operador como uma função estática para ser explícito sobre o operando

Quando você adiciona uma substituição do operador de desreferenciamento de instância definida pelo usuário em um tipo gerenciado, você possivelmente substituir a capacidade do operador de desreferenciamento do tipo para retornar objeto o identificador do. Considere o operador de desreferência de escrever um estático, definidos pelo usuário.

Para obter mais informações, consulte [operador Handle to Object (^)](../../windows/handle-to-object-operator-hat-cpp-component-extensions.md) e [operador de referência de acompanhamento](../../windows/tracking-reference-operator-cpp-component-extensions.md).

Além disso, um operador de instância não está disponível para outros compiladores de linguagem por meio de metadados referenciados. Para obter mais informações, consulte [operadores definidos pelo usuário (C + + / CLI)](../../dotnet/user-defined-operators-cpp-cli.md).

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