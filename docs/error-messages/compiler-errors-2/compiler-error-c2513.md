---
title: Erro do compilador C2513
ms.date: 11/04/2016
f1_keywords:
- C2513
helpviewer_keywords:
- C2513
ms.assetid: ab5b21d3-61e2-4df7-8eea-6f14d6ba8620
ms.openlocfilehash: 96f2ccc29eed5c1fa4e29f69d18ae6503417f211
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87212716"
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

Uma alternativa seria excluir **`typedef`** para definir uma variável com a lista de inicializadores de agregação, mas isso não é recomendado porque criará uma variável com o mesmo nome do tipo e ocultará o nome do tipo.
