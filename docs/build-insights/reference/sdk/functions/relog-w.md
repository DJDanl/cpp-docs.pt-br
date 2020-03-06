---
title: RelogW
description: A C++ referência da função RELOGW do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- RelogW
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 563b1aa92877ff5bc1216bc914c1c661de06dfc0
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332694"
---
# <a name="relogw"></a>RelogW

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A função `RelogW` é usada para ler eventos MSVC de um rastreamento ETW (rastreamento de eventos de entrada para Windows) e gravá-los em um rastreamento ETW novo e modificado.

## <a name="syntax"></a>Sintaxe

```cpp
enum RESULT_CODE RelogW(
    const wchar_t*          inputLogFile,
    const wchar_t*          outputLogFile,
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
