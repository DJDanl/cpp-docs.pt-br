---
title: Estrutura de ANALYSIS_DESCRIPTOR
description: A referência de estrutura do SDK do insights de compilação do C++ ANALYSIS_DESCRIPTOR.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- ANALYSIS_DESCRIPTOR
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 325910f747f75f1f8d2904c248f8de69566464c7
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90041998"
---
# <a name="analysis_descriptor-structure"></a>Estrutura de ANALYSIS_DESCRIPTOR

::: moniker range="<=vs-2015"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `ANALYSIS_DESCRIPTOR` estrutura é usada com as funções [Analyze](../functions/analyze-a.md) e [AnalyzeW](../functions/analyze-w.md) . Ele descreve como um rastreamento de ETW (rastreamento de eventos para Windows) deve ser analisado.

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

| Nome | Descrição |
|--|--|
| `NumberOfPasses` | O número de passagens de análise que devem ser feitas no rastreamento ETW. |
| `Callbacks` | Um objeto [ANALYSIS_CALLBACKS](analysis-callbacks-struct.md) que especifica quais funções chamar durante a sessão de análise. |
| `Context` | Um contexto fornecido pelo usuário que é passado como um argumento para todas as funções de retorno de chamada especificadas em `Callbacks` |

## <a name="remarks"></a>Comentários

A `Callbacks` estrutura só aceita ponteiros para funções que não sejam membros. Você pode contornar essa limitação Configurando `Context` para um ponteiro de objeto. Esse ponteiro de objeto será passado como um argumento para todas as suas funções de retorno de chamada de não membro. Use este ponteiro para chamar funções de membro de dentro de suas funções de retorno de chamada não membro.

::: moniker-end
