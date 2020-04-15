---
title: RelogW
description: A referência de função C++ Build Insights SDK RelogW.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- RelogW
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: c5d5f6e35c7cd24d2324ce1d8a0434d9048b1d85
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323806"
---
# <a name="relogw"></a>RelogW

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `RelogW` função é usada para ler eventos MSVC a partir de um rastreamento de evento de entrada para Windows (ETW) e escrevê-los em um novo traço de ETW modificado.

## <a name="syntax"></a>Sintaxe

```cpp
enum RESULT_CODE RelogW(
    const wchar_t*          inputLogFile,
    const wchar_t*          outputLogFile,
    const RELOG_DESCRIPTOR* relogDescriptor);
```

### <a name="parameters"></a>Parâmetros

*inputLogFile*\
O rastreamento etw de entrada do que você deseja ler eventos.

*saídaLogFile*\
O arquivo em que escrever os novos eventos.

*relogDescriptor*\
Ponteiro para um objeto [RELOG_DESCRIPTOR.](../other-types/relog-descriptor-struct.md) Use este objeto para configurar a sessão de relogamento.

### <a name="return-value"></a>Valor retornado

Um código de resultado do [RESULT_CODE](../other-types/result-code-enum.md) enum.

::: moniker-end
