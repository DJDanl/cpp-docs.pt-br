---
title: Classe TraceInfo
description: A referência de classe do SDK do TraceInfo de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TraceInfo
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: b772cc13981720c73238e56a561ca92144775cb4
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92922914"
---
# <a name="traceinfo-class"></a>Classe TraceInfo

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `TraceInfo` classe é usada para acessar propriedades úteis sobre um rastreamento que está sendo analisado ou registrado novamente.

## <a name="syntax"></a>Sintaxe

```cpp
class TraceInfo
{
public:
    TraceInfo(const TRACE_INFO_DATA& data);

    const unsigned long& LogicalProcessorCount() const;

    const long long& TickFrequency() const;
    const long long& StartTimestamp() const;
    const long long& StopTimestamp() const;

    std::chrono::nanoseconds Duration() const;
};
```

## <a name="remarks"></a>Comentários

Subtraia o `StartTimestamp` de `StopTimestamp` para obter o número de tiques decorridos durante todo o rastreamento. Use `TickFrequency` para converter o valor resultante em uma unidade de tempo. Para obter um exemplo de conversão de tiques em tempo, consulte [EVENT_DATA](../c-event-data-types/event-data-struct.md).

Se você não quiser converter os tiques por conta própria, a `TraceInfo` classe fornecerá uma função de membro que retorna a duração do rastreamento em nanossegundos. Use a biblioteca C++ padrão `chrono` para converter esse valor em outras unidades de tempo.

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

[TraceInfo](#trace-info)

### <a name="functions"></a>Funções

[Duração](#duration) 
 [LogicalProcessorCount](#logical-processor-count) 
 [StartTimestamp](#start-timestamp) 
 [StopTimestamp](#stop-timestamp) 
 [TickFrequency](#tick-frequency)

## <a name="duration"></a><a name="duration"></a> Permanência

```cpp
std::chrono::nanoseconds Duration() const;
```

### <a name="return-value"></a>Valor Retornado

A duração da atividade em nanossegundos.

## <a name="logicalprocessorcount"></a><a name="logical-processor-count"></a> LogicalProcessorCount

```cpp
const unsigned long& LogicalProcessorCount() const;
```

### <a name="return-value"></a>Valor Retornado

O número de processadores lógicos no computador em que o rastreamento foi coletado.

## <a name="starttimestamp"></a><a name="start-timestamp"></a> StartTimestamp

```cpp
const long long& StartTimestamp() const;
```

### <a name="return-value"></a>Valor Retornado

Um valor de tique capturado no momento em que o rastreamento foi iniciado.

## <a name="stoptimestamp"></a><a name="stop-timestamp"></a> StopTimestamp

```cpp
const long long& StopTimestamp() const;
```

### <a name="return-value"></a>Valor Retornado

Um valor de tique capturado no momento em que o rastreamento foi interrompido.

## <a name="tickfrequency"></a><a name="tick-frequency"></a> TickFrequency

```cpp
const long long& TickFrequency() const;
```

### <a name="return-value"></a>Valor Retornado

O número de tiques por segundo a serem usados ao avaliar uma duração medida em tiques.

## <a name="traceinfo"></a><a name="trace-info"></a> TraceInfo

```cpp
TraceInfo(const TRACE_INFO_DATA& data);
```

### <a name="parameters"></a>Parâmetros

*dado*\
Os dados que contêm as informações sobre o rastreamento.

::: moniker-end
