---
title: RelogA
description: A C++ referência da função RELOGA do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- RelogA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: c4427aa0ac85e34bfb9d569913a8ccf6ab264f52
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332729"
---
# <a name="reloga"></a>RelogA

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A função `RelogA` é usada para ler eventos MSVC de um rastreamento ETW (rastreamento de eventos para Windows) e gravá-los em um rastreamento ETW novo e modificado.

## <a name="syntax"></a>Sintaxe

```cpp
enum RESULT_CODE RelogA(
    const char*             inputLogFile,
    const char*             outputLogFile,
    const RELOG_DESCRIPTOR* relogDescriptor);
```

### <a name="parameters"></a>Parâmetros

\ *inputLogFile*
O rastreamento ETW de entrada do qual você deseja ler eventos.

\ *outputLogFile*
O arquivo no qual os novos eventos são gravados.

\ *relogDescriptor*
Ponteiro para um objeto [RELOG_DESCRIPTOR](../other-types/relog-descriptor-struct.md) . Use este objeto para configurar a sessão de reregistro em log.

### <a name="return-value"></a>Valor retornado

Um código de resultado da enumeração [RESULT_CODE](../other-types/result-code-enum.md) .

::: moniker-end
