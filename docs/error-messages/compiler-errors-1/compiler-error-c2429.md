---
title: Erro do compilador C2429
ms.date: 11/16/2017
f1_keywords:
- C2429
helpviewer_keywords:
- C2429
ms.assetid: 57ff6df9-5cf1-49f3-8bd8-4e550dfd65a0
ms.openlocfilehash: a5d1e98e91c541729a93f731eede9b047589c63a
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65447986"
---
# <a name="compiler-error-c2429"></a>Erro do compilador C2429

> '*recurso de linguagem*'requer o sinalizador do compilador'*opção de compilador*'

O recurso de linguagem requer uma opção de compilador específicos para o suporte.

O erro **C2429: recurso de linguagem 'aninhado-namespace-definition' requer o sinalizador do compilador ' / std:c++17 + + 17'** é gerado se você tentar definir uma *composta namespace*, um namespace que contém um ou mais nomes de namespace aninhado de escopo, a partir do Visual Studio 2015 atualização 5. (No Visual Studio 2017 versão 15.3, o **/std: c + + mais recente** comutador é necessário.) Composta namespace definições não são permitidas em C++ antes do c++17. O compilador dá suporte a definições de namespace compostas quando o [/std:c++17 + + 17](../../build/reference/std-specify-language-standard-version.md) for especificada a opção de compilador:

```cpp
// C2429a.cpp
namespace a::b { int i; } // C2429 starting in Visual Studio 2015 Update 3.
                          // Use /std:c++17 to fix, or do this:
// namespace a { namespace b { int i; }}

int main() {
   a::b::i = 2;
}
```
