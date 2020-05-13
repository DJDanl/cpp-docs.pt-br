---
title: Reloga
description: A referência de função C++ Build Insights SDK RelogA.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- RelogA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 5a772b1156fc69eeef39514afe401c549c3b7c38
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323845"
---
# <a name="reloga"></a>Reloga

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `RelogA` função é usada para ler eventos MSVC a partir de um rastreamento de eventos para Windows (ETW) e escrevê-los em um novo traço de ETW modificado.

## <a name="syntax"></a>Sintaxe

```cpp
enum RESULT_CODE RelogA(
    const char*             inputLogFile,
    const char*             outputLogFile,
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
