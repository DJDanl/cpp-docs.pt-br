---
title: Erro do compilador C3821
ms.date: 11/04/2016
f1_keywords:
- C3821
helpviewer_keywords:
- C3821
ms.assetid: 2b327c7a-5faf-443c-ae82-944fae25b4df
ms.openlocfilehash: 25023277258d33ab77bde18f6cdfabc862f50a63
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74741736"
---
# <a name="compiler-error-c3821"></a>Erro do compilador C3821

' function ': tipo ou função gerenciados não podem ser usados em uma função não gerenciada

Funções com assembly embutido ou [setjmp](../../c-runtime-library/reference/setjmp.md) não podem conter tipos de valor ou classes gerenciadas. Para corrigir esse erro, remova o assembly embutido e `setjmp` ou remova os objetos gerenciados.

C3821 também pode ocorrer se você tentar usar o armazenamento automático em uma função vararg.  Para obter mais informações, consulte [listas de argumentos variáveis (...C++) (/CLI)](../../extensions/variable-argument-lists-dot-dot-dot-cpp-cli.md) e [ C++ semântica de pilha para tipos de referência](../../dotnet/cpp-stack-semantics-for-reference-types.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3821.

```cpp
// C3821a.cpp
// compile with: /clr /c
public ref struct R {};
void test1(...) {
   R r;   // C3821
}
```

## <a name="example"></a>Exemplo

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
