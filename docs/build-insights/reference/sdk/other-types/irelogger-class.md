---
title: Classe IRelogger
description: A referência da classe C++ Build Insights SDK IRelogger.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- IRelogger
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 146377b2b44df43ed4b2f749efd9fb614a2a09c9
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329149"
---
# <a name="irelogger-class"></a>Classe IRelogger

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `IRelogger` classe fornece uma interface para relogir um rastreamento de rastreamento de eventos para Windows (ETW). Ele é usado com as funções [MakeDynamicReloggerGroup](../functions/make-dynamic-relogger-group.md) e [MakeStaticReloggerGroup.](../functions/make-static-analyzer-group.md) Use `IRelogger` como uma classe base para criar seu próprio relogger que pode fazer parte de um grupo de relogger.

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

O valor de retorno padrão para todas as `AnalysisControl::CONTINUE`funções que não estão substituídas é . Para obter mais informações, consulte [AnalysisControl](analysis-control-enum-class.md).

## <a name="members"></a>Membros

### <a name="destructor"></a>Destruidor

[~IRelogger](#irelogger-destructor)

### <a name="functions"></a>Funções

[OnBeginRelogging](#on-begin-relogging)\
[OnBeginReloggingPass](#on-begin-relogging-pass)\
[OnEndRelogging](#on-end-relogging)\
[OnEndReloggingPass](#on-end-relogging-pass)\
[OnSimpleEvent](#on-simple-event)\
[Atividade onstart](#on-start-activity)\
[OnStopActivity](#on-stop-activity)\
[OnTraceInfo](#on-trace-info)

## <a name="irelogger"></a><a name="irelogger-destructor"></a>~IRelogger

Destrói a classe IRelogger.

```cpp
virtual ~IRelogger();
```

## <a name="onbeginrelogging"></a><a name="on-begin-relogging"></a>OnBeginRelogging

Esta função é chamada antes do relogamento começar.

```cpp
virtual AnalysisControl OnBeginRelogging();
```

### <a name="return-value"></a>Valor retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer a seguir.

## <a name="onbeginreloggingpass"></a><a name="on-begin-relogging-pass"></a>OnBeginReloggingPass

Esta função é chamada no início do passe de relogamento.

```cpp
virtual AnalysisControl OnBeginReloggingPass();
```

### <a name="return-value"></a>Valor retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer a seguir.

## <a name="onendrelogging"></a><a name="on-end-relogging"></a>OnEndRelogging

Esta função é chamada após o término do passe de relogging.

```cpp
virtual AnalysisControl OnEndRelogging();
```

### <a name="return-value"></a>Valor retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer a seguir.

## <a name="onendreloggingpass"></a><a name="on-end-relogging-pass"></a>OnEndReloggingPass

Esta função é chamada no final do passe de relogamento.

```cpp
virtual AnalysisControl OnEndReloggingPass();
```

### <a name="return-value"></a>Valor retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer a seguir.

## <a name="onsimpleevent"></a><a name="on-simple-event"></a>OnSimpleEvent

```cpp
virtual AnalysisControl OnSimpleEvent(const EventStack& eventStack);
```

Esta função é chamada quando um evento simples está sendo processado.

### <a name="parameters"></a>Parâmetros

*eventStack*\
A pilha de eventos para este evento simples. Para obter mais informações sobre pilhas de eventos, consulte [Eventos](../event-table.md).

### <a name="return-value"></a>Valor retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer a seguir.

## <a name="onstartactivity"></a><a name="on-start-activity"></a>Atividade onstart

```cpp
virtual AnalysisControl OnStartActivity(const EventStack& eventStack);
```

Esta função é chamada quando um evento de início de atividade está sendo processado.

### <a name="parameters"></a>Parâmetros

*eventStack*\
A pilha de eventos para este evento de início de atividade. Para obter mais informações sobre pilhas de eventos, consulte [Eventos](../event-table.md).

### <a name="return-value"></a>Valor retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer a seguir.

## <a name="onstopactivity"></a><a name="on-stop-activity"></a>OnStopActivity

Esta função é chamada quando um evento de parada de atividade está sendo processado.

```cpp
virtual AnalysisControl OnStopActivity(const EventStack& eventStack);
```

### <a name="parameters"></a>Parâmetros

*eventStack*\
A pilha de eventos para este evento de parada de atividades. Para obter mais informações sobre pilhas de eventos, consulte [Eventos](../event-table.md).

### <a name="return-value"></a>Valor retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer a seguir.

## <a name="ontraceinfo"></a><a name="on-trace-info"></a>OnTraceInfo

```cpp
virtual AnalysisControl OnTraceInfo(const TraceInfo& traceInfo);
```

Esta função é chamada uma vez no início de cada análise ou relogging pass.

### <a name="parameters"></a>Parâmetros

*Traceinfo*\
Um objeto [TraceInfo](../cpp-event-data-types/trace-info.md) que contém propriedades úteis sobre o vestígio que está sendo consumido.

### <a name="return-value"></a>Valor retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer a seguir.

::: moniker-end
