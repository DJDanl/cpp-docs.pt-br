---
title: Erro das Ferramentas de Vinculador LNK1301
ms.date: 11/04/2016
f1_keywords:
- LNK1301
helpviewer_keywords:
- LNK1301
ms.assetid: 760da428-7182-4b25-b20a-de90d4b9a9cd
ms.openlocfilehash: fe64eecfbc9fed57c3748afd5804b76d6e4284a4
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74990929"
---
# <a name="linker-tools-error-lnk1301"></a>Erro das Ferramentas de Vinculador LNK1301

Módulos clr LTCG encontrados, incompatíveis com/LTCG: Parameter

Um módulo compilado com/CLR e/GL foi passado para o vinculador junto com um dos parâmetros de PGO (otimizações guiadas por perfil) de/LTCG.

Não há suporte para otimizações guiadas por perfil para módulos/CLR.

Para obter mais informações, consulte .

- [/GL (otimização do programa completo)](../../build/reference/gl-whole-program-optimization.md)

- [/LTCG (geração de código do tempo de vinculação)](../../build/reference/ltcg-link-time-code-generation.md)

- [/clr (compilação do Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md)

- [Otimizações guiadas por perfil](../../build/profile-guided-optimizations.md)

### <a name="to-correct-this-error"></a>Para corrigir esse erro

1. Não compile com/CLR ou não vincule com um dos parâmetros PGO para/LTCG.

## <a name="example"></a>Exemplo

O exemplo a seguir gera LNK1301:

```cpp
// LNK1301.cpp
// compile with: /clr /GL /link /LTCG:PGI LNK1301.obj
// LNK1301 expected
class MyClass {
public:
   int i;
};
```
