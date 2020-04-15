---
title: Relog
description: A referência de função C++ Build Insights SDK Relog.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Relog
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 28b290d2bf2880ce2f534fa1cd91750890e2fead
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323784"
---
# <a name="relog"></a>Relog

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `Relog` função é usada para ler eventos MSVC a partir de um rastreamento de eventos para Windows (ETW) e escrevê-los em um novo traço de ETW modificado.

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

*Membros do TAnalyzerGroup*\
Este parâmetro é sempre deduzido.

*Membros do TReloggerGroup*\
Este parâmetro é sempre deduzido.

*inputLogFile*\
O rastreamento etw de entrada do que você deseja ler eventos.

*saídaLogFile*\
O arquivo em que escrever os novos eventos.

*numberOfAnalysisPasses*\
O número de análises passa para ser executado no rastreamento de entrada. O rastreamento é passado através do grupo analisador fornecido uma vez por passe de análise.

*systemEventsRetentionFlags*\
Uma máscara de bit que especifica quais eventos de ETW do sistema para manter no rastreamento relocado. Para obter mais informações, consulte [RELOG_RETENTION_SYSTEM_EVENT_FLAGS](../other-types/relog-retention-system-event-flags-constants.md).

*analyzerGroup*\
O grupo analisador utilizado para a fase de análise da sessão de relogging. Chamada [MakeStaticAnalyzegroup](make-static-analyzer-group.md) para criar um grupo de analisadores. Para usar um grupo de analisador dinâmico obtido do [MakeDynamicAnalyzerGroup,](make-dynamic-analyzer-group.md)primeiro encapsule-o dentro de um grupo de analisadores estáticos, passando seu endereço para `MakeStaticAnalyzerGroup`.

*reloggerGroup*\
O grupo relogger que reloga eventos no arquivo de rastreamento especificado no *outputLogFile*. Ligue para [o MakeStaticReloggerGroup](make-static-relogger-group.md) para criar um grupo de relogger. Para usar um grupo de relogger dinâmico obtido do [MakeDynamicReloggerGroup,](make-dynamic-relogger-group.md)primeiro encapsule-o `MakeStaticReloggerGroup`dentro de um grupo de relogger estático, passando seu endereço para .

### <a name="return-value"></a>Valor retornado

Um código de resultado do [RESULT_CODE](../other-types/result-code-enum.md) enum.

### <a name="remark"></a>Comentário

O rastreamento de entrada é transmitido através do número do grupo *analisadorOfAnalysisPasses* times. Não há opção similar para realogar passes. O rastreamento é passado pelo grupo relogger apenas uma vez, depois que todas as análises são concluídas.

O relogamento de eventos do sistema, como amostras de CPU de dentro de uma classe de relogger, não é suportado. Use o *parâmetro SystemEventsRetentionFlags* para decidir quais eventos do sistema manter no rastreamento de saída.

::: moniker-end
