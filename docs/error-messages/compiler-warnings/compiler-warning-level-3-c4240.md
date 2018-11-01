---
title: Compilador aviso (nível 3) C4240
ms.date: 11/04/2016
f1_keywords:
- C4240
helpviewer_keywords:
- C4240
ms.assetid: a2657cdb-18e1-493f-882b-4e10c0bca71d
ms.openlocfilehash: fe5306cc7909138fea0159553b53c2adc6a46dc0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50498235"
---
# <a name="compiler-warning-level-3-c4240"></a>Compilador aviso (nível 3) C4240

extensão não padrão usada: acesso a 'classname' agora definido como 'especificador de acesso,' anteriormente era definido como o especificador de acesso

Sob a compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)), você não pode alterar o acesso a uma classe aninhada. Sob as extensões da Microsoft padrão (/Ze), você pode, com este aviso.

## <a name="example"></a>Exemplo

```
// C4240.cpp
// compile with: /W3
class X
{
private:
   class N;
public:
   class N
   {   // C4240
   };
};

int main()
{
}
```