---
title: Compilador aviso (nível 4) C4256
ms.date: 11/04/2016
f1_keywords:
- C4256
helpviewer_keywords:
- C4256
ms.assetid: a755a32e-895a-4837-a2b5-4ea06b736798
ms.openlocfilehash: b1f7534098a04c7c65a380d302999260c960f284
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50627572"
---
# <a name="compiler-warning-level-4-c4256"></a>Compilador aviso (nível 4) C4256

'function': construtor para a classe com bases virtuais possui '...'; chamadas podem não ser compatíveis com versões anteriores do Visual C++

Possível incompatibilidade.

Considere o exemplo de código a seguir. Se a definição do construtor S2::S2 (int i,...) foi compilado usando uma versão do compilador do Visual C++ antes da versão 7, mas o exemplo a seguir é compilado usando a versão atual, a chamada para o construtor para S3 não funcionaria corretamente devido uma alteração de convenção de chamada de casos especiais. Se ambos foram compiladas usando o Visual C++ 6.0, a chamada não funcionaria corretamente, a menos que não há parâmetros foram passados para o botão de reticências.

Para corrigir este aviso

1. Não use o botão de reticências em um construtor.

1. Certifique-se de que todos os componentes em seu projeto são compilados com a versão atual (incluindo todas as bibliotecas que podem definir ou fazer referência a essa classe) e desabilitar o aviso usando o [aviso](../../preprocessor/warning.md) pragma.

O exemplo a seguir gera C4256:

```
// C4256.cpp
// compile with: /W4
// #pragma warning(disable : 4256)
struct S1
{
};

struct S2: virtual public S1
{
   S2( int i, ... )    // C4256
   {
      i = 0;
   }
   /*
   // try the following line instead
   S2( int i)
   {
      i = 0;
   }
   */
};

void func1()
{
   S2 S3( 2, 1, 2 );   // C4256
   // try the following line instead
   // S2 S3( 2 );
}

int main()
{
}
```