---
title: RelogW
description: A referência da função RelogW do SDK do insights de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- RelogW
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: e01cf7ca769c60761999ca320a7f9a65b41a8ed6
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92920054"
---
# <a name="relogw"></a>RelogW

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `RelogW` função é usada para ler eventos MSVC de um rastreamento ETW (rastreamento de eventos de entrada para Windows) e gravá-los em um rastreamento ETW novo e modificado.

## <a name="syntax"></a>Sintaxe

```cpp
enum RESULT_CODE RelogW(
    const wchar_t*          inputLogFile,
    const wchar_t*          outputLogFile,
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
