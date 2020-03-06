---
title: Estrutura de ANALYSIS_DESCRIPTOR
description: A C++ referência da estrutura de ANALYSIS_DESCRIPTOR do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- ANALYSIS_DESCRIPTOR
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: fc11ce11e1faaae02edb36aac447c18ea8107e35
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332477"
---
# <a name="analysis_descriptor-structure"></a>Estrutura de ANALYSIS_DESCRIPTOR

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A estrutura de `ANALYSIS_DESCRIPTOR` é usada com as funções [Analyze](../functions/analyze-a.md) e [AnalyzeW](../functions/analyze-w.md) . Ele descreve como um rastreamento de ETW (rastreamento de eventos para Windows) deve ser analisado.

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
| `NumberOfPasses` | O número de passagens de análise que devem ser feitas no rastreamento ETW. |
| `Callbacks` | Um objeto [ANALYSIS_CALLBACKS](analysis-callbacks-struct.md) que especifica quais funções chamar durante a sessão de análise. |
| `Context` | Um contexto fornecido pelo usuário que é passado como um argumento para todas as funções de retorno de chamada especificadas em `Callbacks` |

## <a name="remarks"></a>Comentários

A estrutura de `Callbacks` só aceita ponteiros para funções que não sejam membros. Você pode contornar essa limitação definindo `Context` como um ponteiro de objeto. Esse ponteiro de objeto será passado como um argumento para todas as suas funções de retorno de chamada de não membro. Use este ponteiro para chamar funções de membro de dentro de suas funções de retorno de chamada não membro.

::: moniker-end
