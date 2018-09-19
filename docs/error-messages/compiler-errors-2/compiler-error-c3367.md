---
title: Erro do compilador C3367 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3367
dev_langs:
- C++
helpviewer_keywords:
- C3367
ms.assetid: e675d42b-f5b0-4d43-aab1-1f5024233102
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2e063635e521efe1eabf8f2b50664ef8bf3e85e8
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46020219"
---
# <a name="compiler-error-c3367"></a>Erro do compilador C3367

'static_member_function': não é possível usar função static para criar um delegate não associado

Quando você chama um delegate não associado, você deve passar uma instância de um objeto. Uma vez que uma função de membro estático é chamada pelo nome da classe, você só pode instanciar um delegate não associado com uma função de membro de instância.

Para obter mais informações sobre delegados não associados, consulte [como: definir e usar delegados (C + + / CLI)](../../dotnet/how-to-define-and-use-delegates-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3367.

```cpp
// C3367.cpp
// compile with: /clr
ref struct R {
   void b() {}
   static void f() {}
};

delegate void Del(R^);

int main() {
   Del ^ a = gcnew Del(&R::b);   // OK
   Del ^ b = gcnew Del(&R::f);   // C3367
}
```