---
title: Classe IAnalyzer
description: A C++ referência da classe build do SDK do insights IAnalyzer.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- IAnalyzer
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 53f7b36695bb24d96ccfe88afbb56ff717c94dc9
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332449"
---
# <a name="ianalyzer-class"></a>Classe IAnalyzer

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe `IAnalyzer` fornece uma interface para analisar um rastreamento de ETW (rastreamento de eventos para Windows). Ele é usado com as funções [MakeDynamicAnalyzerGroup](../functions/make-dynamic-analyzer-group.md), [MakeDynamicReloggerGroup](../functions/make-dynamic-relogger-group.md), [MakeStaticAnalyzerGroup](../functions/make-dynamic-analyzer-group.md)e [MakeStaticReloggerGroup](../functions/make-static-analyzer-group.md) . Use `IAnalyzer` como uma classe base para criar seu próprio analisador que possa fazer parte de um grupo de analisador ou relogger.

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

Classes que derivam de `IAnalyzer` podem ser usadas como analisadores e reagentes. Quando usado como reloggers, as funções específicas de relogger são redirecionadas para o respectivo analisador equivalente. O inverso não é verdadeiro: uma classe derivada de `IRelogger` não pode ser usada como um analisador. Usar um analisador em um grupo de relogger é um padrão comum. Quando colocado em uma posição inicial de um grupo de relogger, um analisador pode pré-testar as informações e disponibilizá-las para reagentes em posições posteriores.

O valor de retorno padrão para todas as funções que não são substituídas é `AnalysisControl::CONTINUE`. Para obter mais informações, consulte [AnalysisControl](analysis-control-enum-class.md).

## <a name="members"></a>Membros

Além do membro [OnTraceInfo](irelogger-class.md#on-trace-info) da interface `IRelogger`, a classe `IAnalyzer` contém os seguintes membros:

### <a name="destructor"></a>Destruidor

[~ IAnalyzer](#ianalyzer-destructor)

### <a name="functions"></a>{1&gt;Funções&lt;1}

\ [OnBeginAnalysis](#on-begin-analysis)
\ [OnBeginAnalysisPass](#on-begin-analysis-pass)
\ [OnBeginRelogging](#on-begin-relogging)
\ [OnBeginReloggingPass](#on-begin-relogging-pass)
\ [OnEndAnalysis](#on-end-analysis)
\ [OnEndAnalysisPass](#on-end-analysis-pass)
\ [OnEndRelogging](#on-end-relogging)
\ [OnEndReloggingPass](#on-end-relogging-pass)
\ [OnSimpleEvent](#on-simple-event)
\ [OnStartActivity](#on-start-activity)
[OnStopActivity](#on-stop-activity)

## <a name="ianalyzer-destructor"></a>~ IAnalyzer

Destrói a classe IAnalyzer.

```cpp
virtual ~IAnalyzer();
```

## <a name="on-begin-analysis"></a>OnBeginAnalysis

Para os analisadores que fazem parte de um grupo do analisador, essa função é chamada antes do início da primeira passagem de análise. Para os analisadores que fazem parte de um grupo de relogger, essa função é chamada antes do início da passagem de reregistro. Para os analisadores que fazem parte do grupo analisador e de relogger da mesma sessão de reregistro em log, essa função é chamada duas vezes antes do início da primeira passagem de análise.

```cpp
virtual AnalysisControl OnBeginAnalysis();
```

### <a name="return-value"></a>Valor retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer em seguida.

## <a name="on-begin-analysis-pass"></a>OnBeginAnalysisPass

Para os analisadores que fazem parte de um grupo do analisador, essa função é chamada no início de cada passagem de análise. Para os analisadores que fazem parte de um grupo de relogger, essa função é chamada no início da passagem de relogger. Para os analisadores que fazem parte do grupo analisador e de relogger da mesma sessão de log, essa função é chamada no início de cada passagem de análise e no início da passagem de relogger.

```cpp
virtual AnalysisControl OnBeginAnalysisPass();
```

### <a name="return-value"></a>Valor retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer em seguida.

## <a name="on-begin-relogging"></a>OnBeginRelogging

```cpp
AnalysisControl OnBeginRelogging() final;
```

Esta função não pode ser substituída. Ele é chamado pelo SDK C++ do insights de compilação quando um analisador faz parte de um grupo de relogger. Essa função redireciona a chamada para [OnBeginAnalysis](#on-begin-analysis).

### <a name="return-value"></a>Valor retornado

O resultado da chamada [OnBeginAnalysis](#on-begin-analysis) .

## <a name="on-begin-relogging-pass"></a>OnBeginReloggingPass

Esta função não pode ser substituída. Ele é chamado pelo SDK C++ do insights de compilação quando um analisador faz parte de um grupo de relogger. Essa função redireciona a chamada para [OnBeginAnalysisPass](#on-begin-analysis-pass).

```cpp
AnalysisControl OnBeginReloggingPass() final;
```

### <a name="return-value"></a>Valor retornado

O resultado da chamada [OnBeginAnalysisPass](#on-begin-analysis-pass) .

## <a name="on-end-analysis"></a>OnEndAnalysis

Para analisadores que fazem parte de um grupo do Analyzer, essa função é chamada após o término da última fase de análise. Para analisadores que fazem parte de um grupo de relogger, essa função é chamada após o encerramento da passagem de reregistro. Para analisadores que fazem parte do grupo analisador e do reagente de relogger da mesma sessão de log, essa função é chamada duas vezes:

1. Depois que todas as passagens de análise forem encerradas e antes do início da aprovação do reregistro em log, e
1. após o encerramento da passagem de reregistro.

```cpp
virtual AnalysisControl OnEndAnalysis();
```

### <a name="return-value"></a>Valor retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer em seguida.

## <a name="on-end-analysis-pass"></a>OnEndAnalysisPass

Para os analisadores que fazem parte de um grupo do analisador, essa função é chamada no final de cada passagem de análise. Para os analisadores que fazem parte de um grupo de relogger, essa função é chamada no final da passagem de relogger. Para os analisadores que fazem parte do grupo analisador e de relogger da mesma sessão de log, essa função é chamada no final de cada passagem de análise e no final da passagem de relogger.

```cpp
virtual AnalysisControl OnEndAnalysisPass();
```

### <a name="return-value"></a>Valor retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer em seguida.

## <a name="on-end-relogging"></a>OnEndRelogging

Esta função não pode ser substituída. Ele é chamado pelo SDK C++ do insights de compilação quando um analisador faz parte de um grupo de relogger. Essa função redireciona a chamada para [OnEndAnalysis](#on-end-analysis).

```cpp
AnalysisControl OnEndRelogging() final;
```

### <a name="return-value"></a>Valor retornado

O resultado da chamada [OnEndAnalysis](#on-end-analysis) .

## <a name="on-end-relogging-pass"></a>OnEndReloggingPass

Esta função não pode ser substituída. Ele é chamado pelo SDK C++ do insights de compilação quando um analisador faz parte de um grupo de relogger. Essa função redireciona a chamada para [OnEndAnalysisPass](#on-end-analysis-pass).

```cpp
AnalysisControl OnEndReloggingPass() final;
```

### <a name="return-value"></a>Valor retornado

O resultado da chamada [OnEndAnalysisPass](#on-end-analysis-pass) .

## <a name="on-simple-event"></a>OnSimpleEvent

Essa função é chamada quando um evento simples está sendo processado. A segunda versão desta função não pode ser substituída. Ele é chamado pelo SDK C++ do insights de compilação quando um analisador faz parte de um grupo de relogger. Todas as chamadas para a versão 2 são redirecionadas para a versão 1.

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

\ *eventStack*
A pilha de eventos para este evento simples. Para obter mais informações sobre as pilhas de eventos, consulte [eventos](../event-table.md).

\ *relogSession*
Esse parâmetro não está em uso.

### <a name="return-value"></a>Valor retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer em seguida.

## <a name="on-start-activity"></a>OnStartActivity

Essa função é chamada quando um evento de início de atividade está sendo processado. A segunda versão desta função não pode ser substituída. Ele é chamado pelo SDK C++ do insights de compilação quando um analisador faz parte de um grupo de relogger. Todas as chamadas para a versão 2 são redirecionadas para a versão 1.

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

\ *eventStack*
A pilha de eventos para este evento de início de atividade. Para obter mais informações sobre as pilhas de eventos, consulte [eventos](../event-table.md).

\ *relogSession*
Esse parâmetro não está em uso.

### <a name="return-value"></a>Valor retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer em seguida.

## <a name="on-stop-activity"></a>OnStopActivity

Essa função é chamada quando um evento de parada de atividade está sendo processado. A segunda versão desta função não pode ser substituída. Ele é chamado pelo SDK C++ do insights de compilação quando um analisador faz parte de um grupo de relogger. Todas as chamadas para a versão 2 são redirecionadas para a versão 1.

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

\ *eventStack*
A pilha de eventos para este evento de parada de atividade. Para obter mais informações sobre as pilhas de eventos, consulte [eventos](../event-table.md).

\ *relogSession*
Esse parâmetro não está em uso.

### <a name="return-value"></a>Valor retornado

Um código [AnalysisControl](analysis-control-enum-class.md) que descreve o que deve acontecer em seguida.

::: moniker-end
