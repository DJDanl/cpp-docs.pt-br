---
title: Compilador aviso (nível 4) C4256
ms.date: 11/04/2016
f1_keywords:
- C4256
helpviewer_keywords:
- C4256
ms.assetid: a755a32e-895a-4837-a2b5-4ea06b736798
ms.openlocfilehash: 3e8a3ab1b11c719730016e6a0cd248770cd89af8
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65447778"
---
# <a name="compiler-warning-level-4-c4256"></a>Compilador aviso (nível 4) C4256

'function': construtor para a classe com bases virtuais possui '...'; chamadas podem não ser compatíveis com versões anteriores do Visual C++

Possível incompatibilidade.

Considere o exemplo de código a seguir. Se a definição do construtor S2::S2 (int i,...) foi compilado usando uma versão do Microsoft C++ compilador antes da versão 7, mas o exemplo a seguir é compilado usando a versão atual, a chamada para o construtor para S3 não funcionaria corretamente devido a uma alteração de convenção de chamada de casos especiais. Se ambos foram compiladas usando o Visual C++ 6.0, a chamada não funcionaria corretamente, a menos que não há parâmetros foram passados para o botão de reticências.

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