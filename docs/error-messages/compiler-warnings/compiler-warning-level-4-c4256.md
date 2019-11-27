---
title: Aviso do compilador (nível 4) C4256
ms.date: 11/04/2016
f1_keywords:
- C4256
helpviewer_keywords:
- C4256
ms.assetid: a755a32e-895a-4837-a2b5-4ea06b736798
ms.openlocfilehash: e087e3cd36ab85d6f3f6b5cfed1b55cac66ea142
ms.sourcegitcommit: 3ee06ec53153cf21910fc8cfef78a4f25f9633f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/26/2019
ms.locfileid: "74541692"
---
# <a name="compiler-warning-level-4-c4256"></a>Aviso do compilador (nível 4) C4256

' function ': construtor para classe com bases virtuais tem '... '; as chamadas podem não ser compatíveis com versões mais antigas do VisualC++

Possível incompatibilidade.

Considere o exemplo de código a seguir. Se a definição do Construtor S2:: S2 (int i,...) tiver sido compilada usando uma versão do compilador da C++ Microsoft antes da versão 7, mas o exemplo a seguir for compilado usando a versão atual, a chamada para o construtor para S3 não funcionará corretamente devido a uma alteração de Convenção de chamada de caso especial. Se ambos foram compilados usando o C++ Visual 6,0, a chamada não funcionaria bem à direita, a menos que nenhum parâmetro fosse passado para as reticências.

Para corrigir esse aviso,

1. Não use reticências em um construtor.

1. Verifique se todos os componentes em seu projeto são criados com a versão atual (incluindo as bibliotecas que podem definir ou referenciar essa classe) e, em seguida, desabilite o aviso usando o pragma de [aviso](../../preprocessor/warning.md) .

O exemplo a seguir gera C4256:

```cpp
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