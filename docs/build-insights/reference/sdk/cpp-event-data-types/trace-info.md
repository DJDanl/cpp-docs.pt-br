---
title: Classe TraceInfo
description: A C++ referência da classe build do SDK do insights TraceInfo.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TraceInfo
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 5cf32c8dc954a803a11888231d35b1050ac81cc3
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332939"
---
# <a name="traceinfo-class"></a>Classe TraceInfo

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe `TraceInfo` é usada para acessar propriedades úteis sobre um rastreamento que está sendo analisado ou registrado novamente.

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

Se você não quiser converter os tiques por conta própria, a classe `TraceInfo` fornece uma função membro que retorna a duração do rastreamento em nanossegundos. Use a biblioteca C++ de `chrono` padrão para converter esse valor em outras unidades de tempo.

## <a name="members"></a>Membros

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

[TraceInfo](#trace-info)

### <a name="functions"></a>{1&gt;Funções&lt;1}

[Duration](#duration)
[LogicalProcessorCount](#logical-processor-count)
[StartTimestamp](#start-timestamp)
[StopTimestamp](#stop-timestamp)
[TickFrequency](#tick-frequency)

## <a name="duration"></a>Permanência

```cpp
std::chrono::nanoseconds Duration() const;
```

### <a name="return-value"></a>Valor retornado

A duração da atividade em nanossegundos.

## <a name="logical-processor-count"></a>LogicalProcessorCount

```cpp
const unsigned long& LogicalProcessorCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de processadores lógicos no computador em que o rastreamento foi coletado.

## <a name="start-timestamp"></a>StartTimestamp

```cpp
const long long& StartTimestamp() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de tique capturado no momento em que o rastreamento foi iniciado.

## <a name="stop-timestamp"></a>StopTimestamp

```cpp
const long long& StopTimestamp() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de tique capturado no momento em que o rastreamento foi interrompido.

## <a name="tick-frequency"></a>TickFrequency

```cpp
const long long& TickFrequency() const;
```

### <a name="return-value"></a>Valor retornado

O número de tiques por segundo a serem usados ao avaliar uma duração medida em tiques.

## <a name="trace-info"></a>TraceInfo

```cpp
TraceInfo(const TRACE_INFO_DATA& data);
```

### <a name="parameters"></a>Parâmetros

\ de *dados*
Os dados que contêm as informações sobre o rastreamento.

::: moniker-end
