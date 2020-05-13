---
title: Classe TraceInfo
description: A referência da classe C++ Build Insights SDK TraceInfo.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TraceInfo
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 75d53937e3999f5692dee0ecf419e0ce5f49a274
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324168"
---
# <a name="traceinfo-class"></a>Classe TraceInfo

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `TraceInfo` classe é usada para acessar propriedades úteis sobre um vestígio que está sendo analisado ou relogado.

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

Subtraia `StartTimestamp` `StopTimestamp` a de si para obter o número de carrapatos decorridos durante todo o rastreamento. Use `TickFrequency` para converter o valor resultante em uma unidade de tempo. Para um exemplo de conversão de carrapatos em tempo, veja [EVENT_DATA](../c-event-data-types/event-data-struct.md).

Se você não quiser converter carrapatos `TraceInfo` você mesmo, a classe fornece uma função de membro que retorna a duração do rastreamento em nanossegundos. Use a biblioteca `chrono` C++ padrão para converter esse valor em outras unidades de tempo.

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

[Traceinfo](#trace-info)

### <a name="functions"></a>Funções

[Duração](#duration)
[LógicaProcessadorContagemContagemDeInícioTimeStamp](#logical-processor-count)
[StartTimestamp](#start-timestamp)
[StopTimeStamp](#stop-timestamp)
[TickFrequency](#tick-frequency)

## <a name="duration"></a><a name="duration"></a>Duração

```cpp
std::chrono::nanoseconds Duration() const;
```

### <a name="return-value"></a>Valor retornado

A duração da atividade em nanossegundos.

## <a name="logicalprocessorcount"></a><a name="logical-processor-count"></a>Contagem de processadores lógicos

```cpp
const unsigned long& LogicalProcessorCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de processadores lógicos na máquina onde o rastreamento foi coletado.

## <a name="starttimestamp"></a><a name="start-timestamp"></a>StartTimestamp

```cpp
const long long& StartTimestamp() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de carrapato capturado no momento em que o rastreamento foi iniciado.

## <a name="stoptimestamp"></a><a name="stop-timestamp"></a>StopTimestamp

```cpp
const long long& StopTimestamp() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de carrapato capturado no momento em que o traço foi interrompido.

## <a name="tickfrequency"></a><a name="tick-frequency"></a>Tickfrequency

```cpp
const long long& TickFrequency() const;
```

### <a name="return-value"></a>Valor retornado

O número de carrapatos por segundo a ser usado ao avaliar uma duração medida em carrapatos.

## <a name="traceinfo"></a><a name="trace-info"></a>Traceinfo

```cpp
TraceInfo(const TRACE_INFO_DATA& data);
```

### <a name="parameters"></a>Parâmetros

*Dados*\
Os dados contendo as informações sobre o rastreamento.

::: moniker-end
