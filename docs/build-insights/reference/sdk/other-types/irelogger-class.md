---
title: Classe IRelogger
description: A referência de classe do SDK do IRelogger de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- IRelogger
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: e504ece95529f7279650062145f3ac0914449c98
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92922515"
---
# <a name="irelogger-class"></a>Classe IRelogger

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `IRelogger` classe fornece uma interface para o registro em log de um rastreamento do ETW (rastreamento de eventos para Windows). Ele é usado com as funções [MakeDynamicReloggerGroup](../functions/make-dynamic-relogger-group.md) e [MakeStaticReloggerGroup](../functions/make-static-analyzer-group.md) . Use `IRelogger` como uma classe base para criar seu próprio relogger que pode fazer parte de um grupo de relogger.

## <a name="syntax"></a>Sintaxe

```cpp
class IRelogger
{
public:
    virtual AnalysisControl OnStartActivity(const EventStack& eventStack,
        const void* relogSession);

    virtual AnalysisControl OnStopActivity(const EventStack& eventStack,
        const void* relogSession);

    virtual AnalysisControl OnSimpleEvent(const EventStack& eventStack,
        const void* relogSession);

    virtual AnalysisControl OnTraceInfo(const TraceInfo& traceInfo);
    virtual AnalysisControl OnBeginRelogging();
    virtual AnalysisControl OnEndRelogging();
    virtual AnalysisControl OnBeginReloggingPass();
    virtual AnalysisControl OnEndReloggingPass() ;

    virtual ~IRelogger();
};
```

## <a name="remarks"></a>Comentários

O valor de retorno padrão para todas as funções que não são substituídas é `AnalysisControl::CONTINUE` . Para obter mais informações, consulte [AnalysisControl](analysis-control-enum-class.md).

## <a name="members"></a>Membros

### <a name="destructor"></a>Destruidor

[~ IRelogger](#irelogger-destructor)

### <a name="functions"></a>Funções

[OnBeginRelogging](#on-begin-relogging)\
[OnBeginReloggingPass](#on-begin-relogging-pass)\
[OnEndRelogging](#on-end-relogging)\
[OnEndReloggingPass](#on-end-relogging-pass)\
[OnSimpleEvent](#on-simple-event)\
[OnStartActivity](#on-start-activity)\
[OnStopActivity](#on-stop-activity)\
[OnTraceInfo](#on-trace-info)

## <a name="irelogger"></a><a name="irelogger-destructor"></a> ~ IRelogger

Destrói a classe IRelogger.

```cpp
virtual ~IRelogger();
```

## <a name="onbeginrelogging"></a><a name="on-begin-relogging"></a> OnBeginRelogging

Essa função é chamada antes do início da passagem de refazer o log.

```cpp
virtual AnalysisControl OnBeginRelogging();
```

### <a name="return-value"></a>Valor Retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer em seguida.

## <a name="onbeginreloggingpass"></a><a name="on-begin-relogging-pass"></a> OnBeginReloggingPass

Essa função é chamada no início da passagem de reregistro.

```cpp
virtual AnalysisControl OnBeginReloggingPass();
```

### <a name="return-value"></a>Valor Retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer em seguida.

## <a name="onendrelogging"></a><a name="on-end-relogging"></a> OnEndRelogging

Essa função é chamada após o encerramento da passagem de reregistro.

```cpp
virtual AnalysisControl OnEndRelogging();
```

### <a name="return-value"></a>Valor Retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer em seguida.

## <a name="onendreloggingpass"></a><a name="on-end-relogging-pass"></a> OnEndReloggingPass

Essa função é chamada no final da passagem de reregistro.

```cpp
virtual AnalysisControl OnEndReloggingPass();
```

### <a name="return-value"></a>Valor Retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer em seguida.

## <a name="onsimpleevent"></a><a name="on-simple-event"></a> OnSimpleEvent

```cpp
virtual AnalysisControl OnSimpleEvent(const EventStack& eventStack);
```

Essa função é chamada quando um evento simples está sendo processado.

### <a name="parameters"></a>Parâmetros

*eventStack*\
A pilha de eventos para este evento simples. Para obter mais informações sobre as pilhas de eventos, consulte [eventos](../event-table.md).

### <a name="return-value"></a>Valor Retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer em seguida.

## <a name="onstartactivity"></a><a name="on-start-activity"></a> OnStartActivity

```cpp
virtual AnalysisControl OnStartActivity(const EventStack& eventStack);
```

Essa função é chamada quando um evento de início de atividade está sendo processado.

### <a name="parameters"></a>Parâmetros

*eventStack*\
A pilha de eventos para este evento de início de atividade. Para obter mais informações sobre as pilhas de eventos, consulte [eventos](../event-table.md).

### <a name="return-value"></a>Valor Retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer em seguida.

## <a name="onstopactivity"></a><a name="on-stop-activity"></a> OnStopActivity

Essa função é chamada quando um evento de parada de atividade está sendo processado.

```cpp
virtual AnalysisControl OnStopActivity(const EventStack& eventStack);
```

### <a name="parameters"></a>Parâmetros

*eventStack*\
A pilha de eventos para este evento de parada de atividade. Para obter mais informações sobre as pilhas de eventos, consulte [eventos](../event-table.md).

### <a name="return-value"></a>Valor Retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer em seguida.

## <a name="ontraceinfo"></a><a name="on-trace-info"></a> OnTraceInfo

```cpp
virtual AnalysisControl OnTraceInfo(const TraceInfo& traceInfo);
```

Essa função é chamada uma vez no início de cada análise ou aprovação de reregistro em log.

### <a name="parameters"></a>Parâmetros

*traceInfo*\
Um objeto [TraceInfo](../cpp-event-data-types/trace-info.md) que contém propriedades úteis sobre o rastreamento que está sendo consumido.

### <a name="return-value"></a>Valor Retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer em seguida.

::: moniker-end
