---
title: Erro das Ferramentas de Vinculador LNK1301
ms.date: 11/04/2016
f1_keywords:
- LNK1301
helpviewer_keywords:
- LNK1301
ms.assetid: 760da428-7182-4b25-b20a-de90d4b9a9cd
ms.openlocfilehash: 6a82d7756f1460c56d87a3d7b1360c140de19827
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62160601"
---
# <a name="linker-tools-error-lnk1301"></a>Erro das Ferramentas de Vinculador LNK1301

Módulos LTCG clr encontrados, incompatíveis com /LTCG:parameter

Um módulo compilado com /GL e /clr foi passado para o vinculador, juntamente com uma das otimizações guiadas por perfil parâmetros /LTCG (PGO).

Otimizações guiadas por perfil não têm suporte para /clr módulos.

Para obter mais informações, consulte:

- [/GL (otimização do programa completo)](../../build/reference/gl-whole-program-optimization.md)

- [/LTCG (geração de código do tempo de vinculação)](../../build/reference/ltcg-link-time-code-generation.md)

- [/clr (compilação do Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md)

- [Otimizações guiadas por perfil](../../build/profile-guided-optimizations.md)

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Não são compilados com /clr ou não vincular com um dos parâmetros para /LTCG PGO.

## <a name="example"></a>Exemplo

O exemplo a seguir gera das LNK1301:

```
// LNK1301.cpp
// compile with: /clr /GL /link /LTCG:PGI LNK1301.obj
// LNK1301 expected
class MyClass {
public:
   int i;
};
```