---
title: Erro do compilador C2513
ms.date: 11/04/2016
f1_keywords:
- C2513
helpviewer_keywords:
- C2513
ms.assetid: ab5b21d3-61e2-4df7-8eea-6f14d6ba8620
ms.openlocfilehash: 13840246a5dc6a1c1bdbcb55dc47f212ee353d81
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62165210"
---
# <a name="compiler-error-c2513"></a>Erro do compilador C2513

'type': nenhuma variável declarada antes de '='

O especificador de tipo aparece na declaração sem nenhum identificador de variável.

O exemplo a seguir gera C2513:

```
// C2513.cpp
int main() {
   int = 9;   // C2513
   int i = 9;   // OK
}
```

Esse erro também pode ser gerado como resultado de um trabalho de conformidade do compilador feito para o Visual Studio .NET 2003: inicialização de um typedef não é mais permitido. A inicialização de um typedef não é permitida pelo padrão e agora gera um erro do compilador.

```
// C2513b.cpp
// compile with: /c
typedef struct S {
   int m_i;
} S = { 1 };   // C2513
// try the following line instead
// } S;
```

Uma alternativa seria excluir `typedef` definir uma variável com a lista de inicializador agregado, mas isso não é recomendado porque ele será criar uma variável com o mesmo nome que o tipo e ocultar o nome do tipo.