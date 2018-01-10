---
title: C2653 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/30/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2653
dev_langs: C++
helpviewer_keywords: C2653
ms.assetid: 3f49e731-affd-43a0-a8d0-181db7650bc3
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3f18e3d6210c5d9b9aba4fdfaab296a01d32b6d5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2653"></a>C2653 de erro do compilador

> '*identificador*': não é um nome de classe ou namespace

A sintaxe de linguagem requer uma classe, estrutura, união ou nome de namespace aqui.

Esse erro pode ocorrer quando você usar um nome que não foi declarado como uma classe, estrutura, união ou namespace na frente de um operador de escopo. Para corrigir esse problema, declara o nome ou incluir o cabeçalho que declara o nome antes de ser usada.

C2653 também é possível se você tentar definir um *composta namespace*, um namespace que contém um ou mais nomes de namespace aninhado de escopo. Composta namespace não são permitidas definições em C++ antes de C++ 17. Há suporte para namespaces compostas iniciadas no Visual Studio 2015 atualização 3 quando você especificar o [/std:c + + mais recente](../../build/reference/std-specify-language-standard-version.md) opção de compilador. A partir do Visual C++ 2017 versão 15,5, o compilador suporta as definições do namespace composta quando o [/std:c + + 17](../../build/reference/std-specify-language-standard-version.md) opção é especificada.

## <a name="examples"></a>Exemplos

Este exemplo gera C2653 porque um nome de escopo é usado, mas não declarado. O compilador espera que uma classe, estrutura, união ou nome de namespace antes de um operador de escopo (:).

```cpp
// C2653.cpp
// compile with: /c
class yy {
   void func1(int i);
};

void xx::func1(int m) {}   // C2653, xx is not declared
void yy::func1(int m) {}   // OK
```

No código que não é compilado para C++ 17 ou posteriores padrões, namespaces aninhados deve usar uma declaração explícita de namespace em cada nível de aninhamento:

```cpp
// C2653b.cpp
namespace a::b {int i;}   // C2653 prior to Visual C++ 2015 Update 3,
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
