---
title: Erro do compilador C2653
ms.date: 11/30/2017
f1_keywords:
- C2653
helpviewer_keywords:
- C2653
ms.assetid: 3f49e731-affd-43a0-a8d0-181db7650bc3
ms.openlocfilehash: 2882764e1c0a84634c500d920f327fbebc4b19a9
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65447944"
---
# <a name="compiler-error-c2653"></a>Erro do compilador C2653

> '*identificador*': não é um nome de classe ou namespace

A sintaxe de linguagem requer uma classe, estrutura, união ou nome do namespace aqui.

Esse erro pode ocorrer quando você usa um nome que não foi declarado como uma classe, estrutura, união ou namespace na frente de um operador de escopo. Para corrigir esse problema, declare o nome ou incluir o cabeçalho que declara o nome antes de ser usada.

C2653 também é possível se você tentar definir uma *composta namespace*, um namespace que contém um ou mais nomes de namespace aninhado de escopo. Composta namespace definições não são permitidas em C++ antes do c++17. Namespaces compostas têm suporte no Visual Studio 2015 atualização 3 quando você especifica o [/std:c++17 + + mais recente](../../build/reference/std-specify-language-standard-version.md) opção de compilador. Começando no Visual Studio 2017 versão 15.5, o compilador dá suporte a definições de namespace composta quando o [/std: c + + 17](../../build/reference/std-specify-language-standard-version.md) opção for especificada.

## <a name="examples"></a>Exemplos

Este exemplo gera C2653 porque um nome de escopo é usado, mas não declarado. O compilador espera que uma classe, estrutura, união ou nome do namespace antes de um operador de escopo (::).

```cpp
// C2653.cpp
// compile with: /c
class yy {
   void func1(int i);
};

void xx::func1(int m) {}   // C2653, xx is not declared
void yy::func1(int m) {}   // OK
```

No código que não é compilado para o c++17 ou posteriores padrões, namespaces aninhados deve usar uma declaração de namespace explícito em cada nível de aninhamento:

```cpp
// C2653b.cpp
namespace a::b {int i;}   // C2653 prior to Visual Studio 2015 Update 3,
                          // C2429 thereafter. Use /std:c++17 or /std:c++latest to fix.

namespace a {             // Use this form for compliant code under /std:c++14 (the default)
   namespace b {          // or when using compilers before Visual Studio 2015 update 3.
      int i;
   }
}

int main() {
   a::b::i = 2;
}
```
