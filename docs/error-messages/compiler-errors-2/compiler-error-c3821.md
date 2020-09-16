---
title: Erro do compilador C3821
ms.date: 11/04/2016
f1_keywords:
- C3821
helpviewer_keywords:
- C3821
ms.assetid: 2b327c7a-5faf-443c-ae82-944fae25b4df
ms.openlocfilehash: 97d6dc0544176d90b90702a7d1f1648e8e98d756
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90686620"
---
# <a name="compiler-error-c3821"></a>Erro do compilador C3821

' function ': tipo ou função gerenciados não podem ser usados em uma função não gerenciada

Funções com assembly embutido ou [setjmp](../../c-runtime-library/reference/setjmp.md) não podem conter tipos de valor ou classes gerenciadas. Para corrigir esse erro, remova o assembly embutido e `setjmp` remova os objetos gerenciados.

C3821 também pode ocorrer se você tentar usar o armazenamento automático em uma função vararg.  Para obter mais informações, consulte [lista de argumentos de variável (...) (c++/CLI)](../../extensions/variable-argument-lists-dot-dot-dot-cpp-cli.md) e [semântica de pilha c++ para tipos de referência](../../dotnet/cpp-stack-semantics-for-reference-types.md).

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C3821.

```cpp
// C3821a.cpp
// compile with: /clr /c
public ref struct R {};
void test1(...) {
   R r;   // C3821
}
```

O exemplo a seguir gera C3821.

```cpp
// C3821b.cpp
// compile with: /clr
// processor: /x86
ref class A {
   public:
   int i;
};

int main() {
   // cannot use managed classes in this function
   A ^a;

   __asm {
      nop
   }
} // C3821
```
