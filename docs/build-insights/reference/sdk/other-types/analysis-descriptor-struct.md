---
title: estrutura ANALYSIS_DESCRIPTOR
description: O C++ Build Insights SDK ANALYSIS_DESCRIPTOR referência de estrutura.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- ANALYSIS_DESCRIPTOR
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 1de7f2a5bc3f02a327daaecf8c2cebc44687ba43
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323609"
---
# <a name="analysis_descriptor-structure"></a>estrutura ANALYSIS_DESCRIPTOR

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `ANALYSIS_DESCRIPTOR` estrutura é utilizada com as funções [AnalyzeA](../functions/analyze-a.md) e [AnalyzeW.](../functions/analyze-w.md) Ele descreve como um rastreamento de rastreamento de eventos para Windows (ETW) deve ser analisado.

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct ANALYSIS_DESCRIPTOR_TAG
{
    unsigned                NumberOfPasses;
    ANALYSIS_CALLBACKS      Callbacks;
    void*                   Context;
} ANALYSIS_DESCRIPTOR;
```

## <a name="members"></a>Membros

|  |  |
|--|--|
| `NumberOfPasses` | O número de análises passa que deve ser feito sobre o rastreamento ETW. |
| `Callbacks` | Um [objeto ANALYSIS_CALLBACKS](analysis-callbacks-struct.md) que especifica quais funções chamar durante a sessão de análise. |
| `Context` | Um contexto fornecido pelo usuário que é passado como um argumento para todas as funções de retorno de chamada especificadas em`Callbacks` |

## <a name="remarks"></a>Comentários

A `Callbacks` estrutura só aceita ponteiros para funções não-membros. Você pode contornar essa `Context` limitação definindo-se para um ponteiro de objeto. Este ponteiro de objeto será passado como um argumento para todas as suas funções de retorno de chamada não-membros. Use este ponteiro para chamar funções de membro de dentro de suas funções de retorno de chamada não-membros.

::: moniker-end
