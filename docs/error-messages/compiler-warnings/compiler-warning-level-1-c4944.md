---
title: Aviso do compilador (nível 1) C4944
ms.date: 11/04/2016
f1_keywords:
- C4944
helpviewer_keywords:
- C4944
ms.assetid: e2905eb1-2e3b-4fab-a48b-c0cae0fd997f
ms.openlocfilehash: f9db36d52647b55c292a15ca724822f8b8b47e9c
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80199194"
---
# <a name="compiler-warning-level-1-c4944"></a>Aviso do compilador (nível 1) C4944

' Symbol ': não é possível importar o símbolo de ' Assembly1 ': já existe um ' Symbol ' no escopo atual

Um símbolo foi definido em um arquivo de código-fonte e uma instrução #using referenciou um assembly que também definiu o símbolo. O símbolo no assembly é ignorado.

## <a name="example"></a>Exemplo

O exemplo a seguir cria um componente com um tipo chamado ClassA.

```csharp
// C4944.cs
// compile with: /target:library
// C# source code to create a dll
public class ClassA {
   public int i;
}
```

## <a name="example"></a>Exemplo

Os exemplos a seguir geram C4944.

```cpp
// C4944b.cpp
// compile with: /clr /W1
class ClassA {
public:
   int u;
};

#using "C4944.dll"   // C4944 ClassA also defined C4944.dll

int main() {
   ClassA * x = new ClassA();
   x->u = 9;
   System::Console::WriteLine(x->u);
}
```
