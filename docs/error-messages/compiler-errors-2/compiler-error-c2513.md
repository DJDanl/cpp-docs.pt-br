---
title: Erro do compilador C2513
ms.date: 11/04/2016
f1_keywords:
- C2513
helpviewer_keywords:
- C2513
ms.assetid: ab5b21d3-61e2-4df7-8eea-6f14d6ba8620
ms.openlocfilehash: 093a5856fdcfa6311fcef93214672b035c91b4fc
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74746520"
---
# <a name="compiler-error-c2513"></a>Erro do compilador C2513

' type ': nenhuma variável declarada antes de ' = '

O especificador de tipo aparece em declaração sem identificador de variável.

O exemplo a seguir gera C2513:

```cpp
// C2513.cpp
int main() {
   int = 9;   // C2513
   int i = 9;   // OK
}
```

Esse erro também pode ser gerado como resultado de um trabalho de conformidade do compilador feito para o Visual Studio .NET 2003: a inicialização de um typedef não é mais permitida. A inicialização de um typedef não é permitida pelo padrão e agora gera um erro do compilador.

```cpp
// C2513b.cpp
// compile with: /c
typedef struct S {
   int m_i;
} S = { 1 };   // C2513
// try the following line instead
// } S;
```

Uma alternativa seria excluir `typedef` para definir uma variável com a lista de inicializadores de agregação, mas isso não é recomendável porque criará uma variável com o mesmo nome do tipo e ocultará o nome do tipo.
