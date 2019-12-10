---
title: Aviso LNK4248 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4248
helpviewer_keywords:
- LNK4248
ms.assetid: e40523ff-e3cb-4ba6-ab79-23f0f339f6cf
ms.openlocfilehash: 4ba05ef067c539dc9c0aca6dc2a395748fd217a2
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988104"
---
# <a name="linker-tools-warning-lnk4248"></a>Aviso LNK4248 (Ferramentas de Vinculador)

token typeref não resolvido (token) para ' type '; a imagem pode não ser executada

Um tipo não tem uma definição em metadados MSIL.

LNK4248 pode ocorrer quando há apenas uma declaração de encaminhamento para um tipo em um módulo MSIL (compilado com **/CLR**), em que o tipo é referenciado no módulo MSIL e onde o módulo MSIL está vinculado a um módulo nativo que tem uma definição para o tipo.

Nessa situação, o vinculador fornecerá a definição de tipo nativo nos metadados MSIL, e isso pode fornecer o comportamento correto.

No entanto, se uma declaração de tipo de encaminhamento for um tipo CLR, a definição de tipo nativo do vinculador poderá não estar correta

Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).

### <a name="to-correct-this-error"></a>Para corrigir esse erro

1. Forneça a definição de tipo no módulo MSIL.

## <a name="example"></a>Exemplo

O exemplo a seguir gera LNK4248. Defina struct a para resolver.

```cpp
// LNK4248.cpp
// compile with: /clr /W1
// LNK4248 expected
struct A;
void Test(A*){}

int main() {
   Test(0);
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir tem uma definição de encaminhamento de um tipo.

```cpp
// LNK4248_2.cpp
// compile with: /clr /c
class A;   // provide a definition for A here to resolve
A * newA();
int valueA(A * a);

int main() {
   A * a = newA();
   return valueA(a);
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera LNK4248.

```cpp
// LNK4248_3.cpp
// compile with: /c
// post-build command: link LNK4248_2.obj LNK4248_3.obj
class A {
public:
   int b;
};

A* newA() {
   return new A;
}

int valueA(A * a) {
   return (int)a;
}
```
