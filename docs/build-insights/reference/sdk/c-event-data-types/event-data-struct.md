---
title: Estrutura de EVENT_DATA
description: A C++ referência da estrutura de EVENT_DATA do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- EVENT_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 572cbdaba346ddb77b665b5677b978c83a80aa3d
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333772"
---
# <a name="event_data-structure"></a>Estrutura de EVENT_DATA

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A estrutura de `EVENT_DATA` descreve um evento recebido de uma sessão de análise ou de reregistro em log. Essas sessões são iniciadas chamando as funções [Analyze](../functions/analyze.md), [analyza](../functions/analyze-a.md), [AnalyzeW](../functions/analyze-w.md), [relog](../functions/relog.md), [RelogA](../functions/relog-a.md)ou [RelogW](../functions/relog-w.md) .

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct EVENT_DATA_TAG
{
    unsigned short          EventId;
    unsigned long long      EventInstanceId;

    long long               TickFrequency;
    long long               StartTimestamp;
    long long               StopTimestamp;
    long long               ExclusiveDurationTicks;
    long long               CPUTicks;
    long long               ExclusiveCPUTicks;
    long long               WallClockTimeResponsibilityTicks;
    long long               ExclusiveWallClockTimeResponsibilityTicks;

    const void*             Data;

    unsigned long           ProcessId;
    unsigned long           ThreadId;
    unsigned short          ProcessorIndex;

    const char*             EventName;
    const wchar_t*          EventWideName;

} EVENT_DATA;
```

## <a name="members"></a>Membros

|  |  |
|--|--|
| `EventId` | Um número que identifica o evento. Para obter uma lista de identificadores de eventos, consulte [EVENT_ID](event-id-enum.md). |
| `EventInstanceId` | Um número que identifica exclusivamente o evento atual dentro de um rastreamento. Esse valor não é alterado ao analisar ou refazer o log do mesmo rastreamento várias vezes. Use esse campo para identificar o mesmo evento em várias análises ou o novo registro em log passa pelo mesmo rastreamento. |
| `TickFrequency` | O número de tiques por segundo a serem usados ao avaliar uma duração medida em tiques. |
| `StartTimestamp` | Quando o evento é uma *atividade*, esse campo é definido como um valor de tique capturado no momento em que a atividade foi iniciada. Se esse evento for um *evento simples*, esse campo será definido como um valor de tique capturado no momento em que o evento ocorreu. |
| `StopTimestamp` | Quando o evento é uma *atividade*, esse campo é definido como um valor de tique capturado no momento em que a atividade foi interrompida. Se o evento de parada ainda não tiver sido recebido para essa atividade, esse campo será definido como zero. Se esse evento for um *evento simples*, esse campo será definido como zero. |
| `ExclusiveDurationTicks` | Se esse evento for uma *atividade*, esse campo será definido como o número de tiques que ocorreram diretamente nesta atividade. O número de tiques que ocorreram em uma atividade filho são excluídos. Esse campo é definido como zero para *eventos simples*. |
| `CPUTicks` | Se esse evento for uma *atividade*, esse campo será definido como o número de tiques de CPU que ocorreram durante essa atividade. Um tique de CPU é diferente de um tique regular. Os tiques de CPU são contados apenas quando a CPU está executando o código em uma atividade. As tiques de CPU não são contadas quando o thread associado à atividade está em suspensão. Esse campo é definido como zero para *eventos simples*. |
| `ExclusiveCPUTicks` | Esse campo tem o mesmo significado que `CPUTicks`, exceto pelo fato de que ele não inclui tiques de CPU que ocorreram em atividades filhas. Esse campo é definido como zero para *eventos simples*. |
| `WallClockTimeResponsibilityTicks` | Se esse evento for uma *atividade*, esse campo será definido como uma contagem em escala que representa a contribuição desta atividade para o tempo geral do relógio de parede. Um tique de responsabilidade de tempo do relógio de parede é diferente de um tique regular. Os tiques de responsabilidade do tempo do relógio do mural levam em conta o paralelismo entre as atividades. Por exemplo, duas atividades paralelas podem ter uma duração de 50 tiques e a mesma hora de início e de término. Nesse caso, as duas serão atribuídas a uma responsabilidade de tempo do relógio de uma parede de 25 tiques. Esse campo é definido como zero para *eventos simples*. |
| `ExclusiveWallClockTimeResponsibilityTicks` | Esse campo tem o mesmo significado que `WallClockTimeResponsibilityTicks`, exceto pelo fato de que ele não inclui os tiques de responsabilidade de tempo do relógio de parede das atividades de filhos. Esse campo é definido como zero para *eventos simples*. |
| `Data` | Aponta para dados adicionais armazenados no evento. O tipo de dados apontado é diferente, dependendo do campo de `EventId`. |
| `ProcessId` | O identificador do processo no qual o evento ocorreu. |
| `ThreadId` | O identificador para o thread no qual o evento ocorreu. |
| `ProcessorIndex` | O número de CPU com índices zero no qual o evento ocorreu. |
| `EventName` | Uma cadeia de caracteres ANSI que contém o nome da entidade identificada por `EventId`. |
| `EventWideName` | Uma cadeia de caracteres larga que contém o nome da entidade identificada por `EventId`. |

## <a name="remarks"></a>Comentários

Muitos campos em `EVENT_DATA` contêm contagens em escala. C++As informações de compilação usam o contador de desempenho da janela como uma fonte de tiques. Uma contagem em escala deve ser usada com o campo `TickFrequency` para convertê-lo em uma unidade de tempo apropriada, como segundos. Consulte o exemplo abaixo para executar essa conversão. `EVENT_DATA` não contém um campo para a contagem em escala regular de uma atividade. Para obter esse valor, subtraia `StartTimestamp` de `StopTimestamp`. `EVENT_DATA` é uma estrutura que deve ser usada por usuários da API C. Para C++ usuários de API, as classes como o [evento](../cpp-event-data-types/event.md) fazem conversões de tempo automaticamente.

O valor do campo `EVENT_DATA` `Data` depende do valor de seu campo `EventId`. O valor de `Data` é descrito na tabela a seguir. Alguns identificadores de entidade podem estar ausentes na tabela a seguir. Nesse caso, o campo `Data` é definido como `nullptr` ou zero.

| Valor `EventId` | Tipo apontado por `Data` |
|--|--|
| `EVENT_ID_BACK_END_PASS` | [CL_PASS_DATA](cl-pass-data-struct.md) |
| `EVENT_ID_COMMAND_LINE` | `const wchar_t` |
| `EVENT_ID_COMPILER` | [INVOCATION_DATA](invocation-data-struct.md) |
| `EVENT_ID_ENVIRONMENT_VARIABLE` | [NAME_VALUE_PAIR_DATA](name-value-pair-data-struct.md) |
| `EVENT_ID_EXECUTABLE_IMAGE_OUTPUT` | [FILE_DATA](file-data-struct.md) |
| `EVENT_ID_EXP_OUTPUT` | [FILE_DATA](file-data-struct.md) |
| `EVENT_ID_FILE_INPUT` | [FILE_DATA](file-data-struct.md) |
| `EVENT_ID_FORCE_INLINE` | [FUNCTION_FORCE_INLINEE_DATA](function-force-inlinee-data-struct.md) |
| `EVENT_ID_FRONT_END_FILE` | [FRONT_END_FILE_DATA](front-end-file-data-struct.md) |
| `EVENT_ID_FRONT_END_PASS` | [CL_PASS_DATA](cl-pass-data-struct.md) |
| `EVENT_ID_FUNCTION` | [FUNCTION_DATA](function-data-struct.md) |
| `EVENT_ID_IMP_LIB_OUTPUT` | [FILE_DATA](file-data-struct.md) |
| `EVENT_ID_LIB_OUTPUT` | [FILE_DATA](file-data-struct.md) |
| `EVENT_ID_LINKER` | [INVOCATION_DATA](invocation-data-struct.md) |
| `EVENT_ID_OBJ_OUTPUT` | [FILE_DATA](file-data-struct.md) |
| `EVENT_ID_SYMBOL_NAME` | [SYMBOL_NAME_DATA](symbol-name-data-struct.md) |
| `EVENT_ID_TEMPLATE_INSTANTIATION` | [TEMPLATE_INSTANTIATION_DATA](template-instantiation-data-struct.md) |

## <a name="tick-conversion-example"></a>Exemplo de conversão em escala

```cpp
//
// We have the elapsed number of ticks, along with the
// number of ticks per second. We use these values
// to convert to the number of elapsed microseconds.
// To guard against loss-of-precision, we convert
// to microseconds *before* dividing by ticks-per-second.
//

long long ConvertDurationToMicroseconds(const sruct EVENT_DATA& eventData)
{
    long long duration = eventData.StopTimestamp - eventData.StartTimestamp;
    long long duration *= 1000000;
    return duration / eventData.TickFrequency;
}
```

::: moniker-end
