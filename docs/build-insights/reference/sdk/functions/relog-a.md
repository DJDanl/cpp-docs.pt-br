---
title: RelogA
description: A referência da função RelogA do SDK do insights de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- RelogA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 4e4882bca2241c520d4cb6ba0a8eb9c32704eaef
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92922805"
---
# <a name="reloga"></a>RelogA

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `RelogA` função é usada para ler eventos MSVC de um rastreamento ETW (rastreamento de eventos para Windows) e gravá-los em um rastreamento ETW novo e modificado.

## <a name="syntax"></a>Sintaxe

```cpp
enum RESULT_CODE RelogA(
    const char*             inputLogFile,
    const char*             outputLogFile,
    const RELOG_DESCRIPTOR* relogDescriptor);
```

### <a name="parameters"></a>Parâmetros

*inputLogFile*\
O rastreamento ETW de entrada do qual você deseja ler eventos.

*outputLogFile*\
O arquivo no qual os novos eventos são gravados.

*relogDescriptor*\
Ponteiro para um objeto [RELOG_DESCRIPTOR](../other-types/relog-descriptor-struct.md) . Use este objeto para configurar a sessão de reregistro em log.

### <a name="return-value"></a>Valor Retornado

Um código de resultado da enumeração [RESULT_CODE](../other-types/result-code-enum.md) .

::: moniker-end
