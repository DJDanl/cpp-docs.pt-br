---
title: Relog
description: A C++ referência da função relog do SDK do insights de compilação.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Relog
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 1ce09101deebd957de4b9305762dc37f38b53f4e
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332687"
---
# <a name="relog"></a>Relog

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A função `Relog` é usada para ler eventos MSVC de um rastreamento ETW (rastreamento de eventos para Windows) e gravá-los em um rastreamento ETW novo e modificado.

## <a name="syntax"></a>Sintaxe

```cpp
template <
    typename... TAnalyzerGroupMembers,
    typename... TReloggerGroupMembers>
RESULT_CODE Relog(
    const char*                                   inputLogFile,
    const char*                                   outputLogFile,
    unsigned                                      numberOfAnalysisPasses,
    unsigned long long                            systemEventsRetentionFlags,
    StaticAnalyzerGroup<TAnalyzerGroupMembers...> analyzerGroup,
    StaticReloggerGroup<TReloggerGroupMembers...> reloggerGroup);

template <
    typename... TAnalyzerGroupMembers,
    typename... TReloggerGroupMembers>
RESULT_CODE Relog(
    const wchar_t*                                inputLogFile,
    const wchar_t*                                outputLogFile,
    unsigned                                      numberOfAnalysisPasses,
    unsigned long long                            systemEventsRetentionFlags,
    StaticAnalyzerGroup<TAnalyzerGroupMembers...> analyzerGroup,
    StaticReloggerGroup<TReloggerGroupMembers...> reloggerGroup);
```

### <a name="parameters"></a>Parâmetros

\ *TAnalyzerGroupMembers*
Esse parâmetro é sempre deduzido.

\ *TReloggerGroupMembers*
Esse parâmetro é sempre deduzido.

\ *inputLogFile*
O rastreamento ETW de entrada do qual você deseja ler eventos.

\ *outputLogFile*
O arquivo no qual os novos eventos são gravados.

\ *numberOfAnalysisPasses*
O número de etapas de análise a serem executadas no rastreamento de entrada. O rastreamento é passado pelo grupo analisador fornecido uma vez por passagem de análise.

\ *systemEventsRetentionFlags*
Um bitmask que especifica quais eventos de ETW do sistema manter no rastreamento de relogin. Para obter mais informações, consulte [RELOG_RETENTION_SYSTEM_EVENT_FLAGS](../other-types/relog-retention-system-event-flags-constants.md).

\ do *fileanalyzer*
O grupo do Analyzer usado para a fase de análise da sessão de reregistro em log. Chame [MakeStaticAnalyzerGroup](make-static-analyzer-group.md) para criar um grupo do Analyzer. Para usar um grupo do analisador dinâmico obtido do [MakeDynamicAnalyzerGroup](make-dynamic-analyzer-group.md), primeiro encapsula-o dentro de um grupo do analisador estático passando seu endereço para `MakeStaticAnalyzerGroup`.

\ de *agente* novamente
O grupo de relogger que registra novamente os eventos no arquivo de rastreamento especificado em *outputLogFile*. Chame [MakeStaticReloggerGroup](make-static-relogger-group.md) para criar um grupo de relogger. Para usar um grupo de reagente dinâmico obtido do [MakeDynamicReloggerGroup](make-dynamic-relogger-group.md), primeiro encapsula-o dentro de um grupo de reagente estático, passando seu endereço para `MakeStaticReloggerGroup`.

### <a name="return-value"></a>Valor retornado

Um código de resultado da enumeração [RESULT_CODE](../other-types/result-code-enum.md) .

### <a name="remark"></a>Remark

O rastreamento de entrada é passado pelo grupo analisador *numberOfAnalysisPasses* vezes. Não há nenhuma opção semelhante para o reregistro em log. O rastreamento é passado Trough o grupo de relogger apenas uma vez, após a conclusão de todas as etapas de análise.

Não há suporte para o registro em log de eventos do sistema, como exemplos de CPU de uma classe de relogger. Use o parâmetro *systemEventsRetentionFlags* para decidir quais eventos do sistema manter no rastreamento de saída.

::: moniker-end
