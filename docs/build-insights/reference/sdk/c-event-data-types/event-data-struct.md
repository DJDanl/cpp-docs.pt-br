---
title: estrutura EVENT_DATA
description: O C++ Build Insights SDK EVENT_DATA referência de estrutura.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- EVENT_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 8ce396febe278c5e7c34fe170939c9522913f92a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325605"
---
# <a name="event_data-structure"></a>estrutura EVENT_DATA

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `EVENT_DATA` estrutura descreve um evento recebido de uma sessão de análise ou relogging. Essas sessões são iniciadas ligando para as funções [Analyze,](../functions/analyze.md) [AnalyzeA,](../functions/analyze-a.md) [AnalyzeW,](../functions/analyze-w.md) [Relog,](../functions/relog.md) [RelogA](../functions/relog-a.md)ou [RelogW.](../functions/relog-w.md)

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
| `EventInstanceId` | Um número que identifica exclusivamente o evento atual dentro de um traço. Esse valor não muda ao analisar ou relogar o mesmo traço várias vezes. Use este campo para identificar o mesmo evento em várias análises ou relogamento passa sobre o mesmo traço. |
| `TickFrequency` | O número de carrapatos por segundo a ser usado ao avaliar uma duração medida em carrapatos. |
| `StartTimestamp` | Quando o evento é uma *Atividade,* este campo é definido como um valor de tique-taque capturado no momento em que a atividade começou. Se este evento for um *evento simples,* este campo será definido como um valor de tique-taque capturado no momento em que o evento ocorreu. |
| `StopTimestamp` | Quando o evento é uma *Atividade,* este campo é definido como um valor de tique-taque capturado no momento em que a atividade parou. Se o evento stop ainda não foi recebido para esta atividade, este campo está definido como zero. Se este evento for um *evento simples,* este campo será definido como zero. |
| `ExclusiveDurationTicks` | Se este evento for uma *Atividade,* este campo será definido para o número de carrapatos que ocorreram diretamente nesta atividade. O número de carrapatos que ocorreram em uma atividade infantil está excluído. Este campo está definido como zero para *Eventos Simples*. |
| `CPUTicks` | Se este evento for uma *atividade,* este campo será definido como o número de carrapatos da CPU que ocorreram durante esta atividade. Um carrapato da CPU é diferente de um carrapato normal. Os carrapatos da CPU só são contados quando a CPU está executando o código em uma atividade. Os carrapatos da CPU não são contados quando o segmento associado à atividade está dormindo. Este campo está definido como zero para *Eventos Simples*. |
| `ExclusiveCPUTicks` | Este campo tem o `CPUTicks`mesmo significado de , exceto que não inclui carrapatos de CPU que ocorreram em atividades infantis. Este campo está definido como zero para *Eventos Simples*. |
| `WallClockTimeResponsibilityTicks` | Se este evento for uma *atividade,* este campo será definido como uma contagem de carrapatos que representa a contribuição desta atividade para o tempo geral do relógio de parede. Um carrapato de responsabilidade de relógio de parede é diferente de um carrapato normal. Os carrapatos de responsabilidade do relógio de parede levam em conta o paralelismo entre as atividades. Por exemplo, duas atividades paralelas podem ter uma duração de 50 carrapatos e o mesmo tempo de início e parada. Neste caso, ambos serão atribuídos uma responsabilidade de tempo de parede de 25 carrapatos. Este campo está definido como zero para *Eventos Simples*. |
| `ExclusiveWallClockTimeResponsibilityTicks` | Este campo tem o `WallClockTimeResponsibilityTicks`mesmo significado de , exceto que não inclui os carrapatos de responsabilidade do relógio de parede das atividades infantis. Este campo está definido como zero para *Eventos Simples*. |
| `Data` | Aponta para dados adicionais armazenados no evento. O tipo de dados apontados é `EventId` diferente, dependendo do campo. |
| `ProcessId` | O identificador para o processo em que o evento ocorreu. |
| `ThreadId` | O identificador para o segmento em que o evento ocorreu. |
| `ProcessorIndex` | O número da CPU com indexação zero no qual o evento ocorreu. |
| `EventName` | Uma seqüência ANSI contendo o `EventId`nome da entidade identificada por . |
| `EventWideName` | Uma corda larga contendo o nome `EventId`da entidade identificada por . |

## <a name="remarks"></a>Comentários

Muitos campos `EVENT_DATA` contêm contagem de carrapatos. C++ Build Insights usa o contador de desempenho do Window como fonte de carrapatos. Uma contagem de carrapatos deve ser usada com o `TickFrequency` campo para convertê-lo em uma unidade de tempo apropriada, como segundos. Veja o exemplo abaixo para realizar esta conversão. `EVENT_DATA`não contém um campo para a contagem regular de carrapatos de uma atividade. Para obter esse valor, subtraia `StartTimestamp` de `StopTimestamp`. `EVENT_DATA`é uma estrutura que deve ser usada por usuários de API C. Para usuários de API C++, classes como [Event](../cpp-event-data-types/event.md) fazem conversões de tempo automaticamente.

O valor `EVENT_DATA` `Data` do campo depende do `EventId` valor de seu campo. O valor `Data` do é descrito na tabela abaixo. Alguns identificadores de entidades podem estar faltando na tabela abaixo. Neste caso, `Data` o campo `nullptr` está definido como ou zero.

| `EventId` valor | Tipo apontado para`Data` |
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

## <a name="tick-conversion-example"></a>Exemplo de conversão de carrapato

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
