---
title: StopAndRelogTracingSessionW
description: A referência da função C++ Build Insights SDK StopAndRelogTracingSessionW.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- StopAndRelogTracingSessionW
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: c542ba8f313f30cf5adb069dd02cf3db29ffc532
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323684"
---
# <a name="stopandrelogtracingsessionw"></a>StopAndRelogTracingSessionW

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `StopAndRelogTracingSessionW` função interrompe uma sessão de rastreamento em andamento e salva o rastreamento resultante em um arquivo temporário. Uma sessão de relogamento é então imediatamente iniciada usando o arquivo temporário como uma entrada. O traço relocamento final produzido pela sessão de relogamento é salvo em um arquivo especificado pelo chamador. Os executáveis que chamam essa função devem ter privilégios de administrador.

## <a name="syntax"></a>Sintaxe

```cpp
enum RESULT_CODE StopAndRelogTracingSessionW(
    const wchar_t*              sessionName,
    const wchar_t*              outputLogFile,
    TRACING_SESSION_STATISTICS* statistics,
    const RELOG_DESCRIPTOR*     relogDescriptor);
```

### <a name="parameters"></a>Parâmetros

*sessionName*\
O nome da sessão de rastreamento para parar. Use o mesmo nome de sessão que o aprovado para [StartTracingSession](start-tracing-session.md), [StartTracingSessionA](start-tracing-session-a.md)ou [StartTracingSessionW](start-tracing-session-w.md).

*saídaLogFile*\
O arquivo no qual escrever o traço relocouproduzido pela sessão de relogamento.

*Estatísticas*\
Ponteiro para um objeto [TRACING_SESSION_STATISTICS.](../other-types/tracing-session-statistics-struct.md) `StopAndRelogTracingSessionW`escreve estatísticas de coleta de vestígios neste objeto antes de retornar.

*análiseDescritor*\
Ponteiro para um objeto [RELOG_DESCRIPTOR.](../other-types/analysis-descriptor-struct.md) Use este objeto para configurar a sessão de `StopAndRelogTracingSessionW`relogamento iniciada por .

### <a name="return-value"></a>Valor retornado

Um código de resultado do [RESULT_CODE](../other-types/result-code-enum.md) enum.

::: moniker-end
