---
title: Classe IAnalyzer
description: A referência da classe C++ Build Insights SDK IAnalyzer.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- IAnalyzer
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: be9d80bb94450458c73fd6ce8d908985ba6f293d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329180"
---
# <a name="ianalyzer-class"></a>Classe IAnalyzer

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `IAnalyzer` classe fornece uma interface para analisar um rastreamento de rastreamento de eventos para Windows (ETW). Ele é usado com as funções [MakeDynamicAnalyzerGroup,](../functions/make-dynamic-analyzer-group.md) [MakeDynamicReloggerGroup,](../functions/make-dynamic-relogger-group.md) [MakeStaticAnalyzerGroup](../functions/make-dynamic-analyzer-group.md)e [MakeStaticReloggerGroup.](../functions/make-static-analyzer-group.md) Use `IAnalyzer` como uma classe base para criar seu próprio analisador que pode fazer parte de um grupo de analisadores ou relogger.

## <a name="syntax"></a>Sintaxe

```cpp
class IAnalyzer : public IRelogger
{
public:
    virtual AnalysisControl OnStartActivity(const EventStack& eventStack);
    virtual AnalysisControl OnStopActivity(const EventStack& eventStack)
    virtual AnalysisControl OnSimpleEvent(const EventStack& eventStack);
    virtual AnalysisControl OnBeginAnalysis();
    virtual AnalysisControl OnEndAnalysis();
    virtual AnalysisControl OnBeginAnalysisPass();
    virtual AnalysisControl OnEndAnalysisPass();

    AnalysisControl OnStartActivity(const EventStack& eventStack,
        const void* relogSession) final;

    AnalysisControl OnStopActivity(const EventStack& eventStack,
        const void* relogSession) final;

    AnalysisControl OnSimpleEvent(const EventStack& eventStack,
        const void* relogSession) final;

    AnalysisControl OnBeginRelogging() final;
    AnalysisControl OnEndRelogging() final;
    AnalysisControl OnBeginReloggingPass() final;
    AnalysisControl OnEndReloggingPass() final;

    virtual ~IAnalyzer();
};
```

## <a name="remarks"></a>Comentários

As classes `IAnalyzer` que derivam podem ser usadas tanto como analisadores quanto como reloggers. Quando usados como reloggers, as funções específicas do relogger redirecionam para o equivalente do analisador. O inverso não é verdade: uma `IRelogger` classe que deriva não pode ser usada como analisador. Usar um analisador em um grupo de relogger é um padrão comum. Quando colocado em uma posição inicial de um grupo de relogger, um analisador pode pré-calcular informações e disponibilizá-los para reloggers em posições posteriores.

O valor de retorno padrão para todas as `AnalysisControl::CONTINUE`funções que não estão substituídas é . Para obter mais informações, consulte [AnalysisControl](analysis-control-enum-class.md).

## <a name="members"></a>Membros

Além do membro [OnTraceInfo](irelogger-class.md#on-trace-info) `IRelogger` da interface, a `IAnalyzer` classe contém os seguintes membros:

### <a name="destructor"></a>Destruidor

[~IAnalyzer](#ianalyzer-destructor)

### <a name="functions"></a>Funções

[Análise onbegin](#on-begin-analysis)\
[OnBeginAnalysisPass](#on-begin-analysis-pass)\
[OnBeginRelogging](#on-begin-relogging)\
[OnBeginReloggingPass](#on-begin-relogging-pass)\
[Onendanalysis](#on-end-analysis)\
[Passe de Análise de Endanalysis](#on-end-analysis-pass)\
[OnEndRelogging](#on-end-relogging)\
[OnEndReloggingPass](#on-end-relogging-pass)\
[OnSimpleEvent](#on-simple-event)\
[Atividade onstart](#on-start-activity)\
[OnStopActivity](#on-stop-activity)

## <a name="ianalyzer"></a><a name="ianalyzer-destructor"></a>~IAnalyzer

Destrói a classe IAnalyzer.

```cpp
virtual ~IAnalyzer();
```

## <a name="onbeginanalysis"></a><a name="on-begin-analysis"></a>Análise onbegin

Para analisadores que fazem parte de um grupo analisador, essa função é chamada antes do início da primeira análise. Para analisadores parte de um grupo de relogger, essa função é chamada antes do relogging ser relogado. Para analisadores parte do grupo analisador e relogger da mesma sessão de relogging, esta função é chamada duas vezes antes do início da primeira análise.

```cpp
virtual AnalysisControl OnBeginAnalysis();
```

### <a name="return-value"></a>Valor retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer a seguir.

## <a name="onbeginanalysispass"></a><a name="on-begin-analysis-pass"></a>OnBeginAnalysisPass

Para analisadores que fazem parte de um grupo analisador, essa função é chamada no início de cada passe de análise. Para analisadores que fazem parte de um grupo de relogger, essa função é chamada no início do relogger pass. Para analisadores que fazem parte do grupo analisador e relogger da mesma sessão de relogamento, essa função é chamada no início de cada passe de análise e no início da passagem do relogger.

```cpp
virtual AnalysisControl OnBeginAnalysisPass();
```

### <a name="return-value"></a>Valor retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer a seguir.

## <a name="onbeginrelogging"></a><a name="on-begin-relogging"></a>OnBeginRelogging

```cpp
AnalysisControl OnBeginRelogging() final;
```

Esta função não pode ser substituída. É chamado pelo C++ Build Insights SDK quando um analisador faz parte de um grupo de relogger. Esta função redireciona a chamada para [OnBeginAnalysis](#on-begin-analysis).

### <a name="return-value"></a>Valor retornado

O resultado da chamada [OnBeginAnalysis.](#on-begin-analysis)

## <a name="onbeginreloggingpass"></a><a name="on-begin-relogging-pass"></a>OnBeginReloggingPass

Esta função não pode ser substituída. É chamado pelo C++ Build Insights SDK quando um analisador faz parte de um grupo de relogger. Esta função redireciona a chamada para [OnBeginAnalysisPass](#on-begin-analysis-pass).

```cpp
AnalysisControl OnBeginReloggingPass() final;
```

### <a name="return-value"></a>Valor retornado

O resultado da chamada [OnBeginAnalysisPass.](#on-begin-analysis-pass)

## <a name="onendanalysis"></a><a name="on-end-analysis"></a>Onendanalysis

Para analisadores que fazem parte de um grupo de analisadores, essa função é chamada após o término da última análise. Para analisadores que fazem parte de um grupo de relogger, essa função é chamada após o término do passe de relogamento. Para analisadores que fazem parte do grupo analisador e relogger da mesma sessão de relogging, essa função é chamada duas vezes:

1. depois de todas as análises passam terminou e antes do passe de relogging começa, e
1. depois que o passe de relogging terminou.

```cpp
virtual AnalysisControl OnEndAnalysis();
```

### <a name="return-value"></a>Valor retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer a seguir.

## <a name="onendanalysispass"></a><a name="on-end-analysis-pass"></a>Passe de Análise de Endanalysis

Para analisadores que fazem parte de um grupo analisador, essa função é chamada no final de cada passe de análise. Para analisadores parte de um grupo de relogger, essa função é chamada no final do passe de relogger. Para analisadores parte do grupo analisador e relogger da mesma sessão de relogamento, essa função é chamada no final de cada passe de análise e no final do passe de relogger.

```cpp
virtual AnalysisControl OnEndAnalysisPass();
```

### <a name="return-value"></a>Valor retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer a seguir.

## <a name="onendrelogging"></a><a name="on-end-relogging"></a>OnEndRelogging

Esta função não pode ser substituída. É chamado pelo C++ Build Insights SDK quando um analisador faz parte de um grupo de relogger. Esta função redireciona a chamada para [OnEndAnalysis](#on-end-analysis).

```cpp
AnalysisControl OnEndRelogging() final;
```

### <a name="return-value"></a>Valor retornado

O resultado da chamada [OnEndAnalysis.](#on-end-analysis)

## <a name="onendreloggingpass"></a><a name="on-end-relogging-pass"></a>OnEndReloggingPass

Esta função não pode ser substituída. É chamado pelo C++ Build Insights SDK quando um analisador faz parte de um grupo de relogger. Esta função redireciona a chamada para [OnEndAnalysisPass](#on-end-analysis-pass).

```cpp
AnalysisControl OnEndReloggingPass() final;
```

### <a name="return-value"></a>Valor retornado

O resultado da chamada [OnEndAnalysisPass.](#on-end-analysis-pass)

## <a name="onsimpleevent"></a><a name="on-simple-event"></a>OnSimpleEvent

Esta função é chamada quando um evento simples está sendo processado. A segunda versão desta função não pode ser substituída. É chamado pelo C++ Build Insights SDK quando um analisador faz parte de um grupo de relogger. Todas as chamadas para a versão 2 são redirecionadas para a versão 1.

### <a name="version-1"></a>Versão 1

```cpp
virtual AnalysisControl OnSimpleEvent(const EventStack& eventStack);
```

### <a name="version-2"></a>Versão 2

```cpp
AnalysisControl OnSimpleEvent(const EventStack& eventStack,
        const void* relogSession) final;
```

### <a name="parameters"></a>Parâmetros

*eventStack*\
A pilha de eventos para este evento simples. Para obter mais informações sobre pilhas de eventos, consulte [Eventos](../event-table.md).

*sessão de relog*\
Esse parâmetro não está em uso.

### <a name="return-value"></a>Valor retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer a seguir.

## <a name="onstartactivity"></a><a name="on-start-activity"></a>Atividade onstart

Esta função é chamada quando um evento de início de atividade está sendo processado. A segunda versão desta função não pode ser substituída. É chamado pelo C++ Build Insights SDK quando um analisador faz parte de um grupo de relogger. Todas as chamadas para a versão 2 são redirecionadas para a versão 1.

### <a name="version-1"></a>Versão 1

```cpp
virtual AnalysisControl OnStartActivity(const EventStack& eventStack);
```

### <a name="version-2"></a>Versão 2

```cpp
AnalysisControl OnStartActivity(const EventStack& eventStack,
        const void* relogSession) final;
```

### <a name="parameters"></a>Parâmetros

*eventStack*\
A pilha de eventos para este evento de início de atividade. Para obter mais informações sobre pilhas de eventos, consulte [Eventos](../event-table.md).

*sessão de relog*\
Esse parâmetro não está em uso.

### <a name="return-value"></a>Valor retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer a seguir.

## <a name="onstopactivity"></a><a name="on-stop-activity"></a>OnStopActivity

Esta função é chamada quando um evento de parada de atividade está sendo processado. A segunda versão desta função não pode ser substituída. É chamado pelo C++ Build Insights SDK quando um analisador faz parte de um grupo de relogger. Todas as chamadas para a versão 2 são redirecionadas para a versão 1.

### <a name="version-1"></a>Versão 1

```cpp
virtual AnalysisControl OnStopActivity(const EventStack& eventStack);
```

### <a name="version-2"></a>Versão 2

```cpp
AnalysisControl OnStopActivity(const EventStack& eventStack,
        const void* relogSession) final;
```

### <a name="parameters"></a>Parâmetros

*eventStack*\
A pilha de eventos para este evento de parada de atividades. Para obter mais informações sobre pilhas de eventos, consulte [Eventos](../event-table.md).

*sessão de relog*\
Esse parâmetro não está em uso.

### <a name="return-value"></a>Valor retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer a seguir.

::: moniker-end
