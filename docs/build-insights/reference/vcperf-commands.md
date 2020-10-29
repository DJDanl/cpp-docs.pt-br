---
title: 'Referência: comandos vcperf'
description: Referência para o utilitário de linha de comando vcperf.exe.
ms.date: 11/03/2019
helpviewer_keywords:
- C++ Build Insights
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 42ca422e11824bdbdad4e42e7b55950317095703
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92922199"
---
# <a name="reference-vcperf-commands"></a>Referência: comandos vcperf

::: moniker range="<=msvc-150"

As ferramentas de compilação do C++ estão disponíveis no Visual Studio 2019. Para ver a documentação dessa versão, defina o controle do seletor de **versão** do Visual Studio para este artigo como Visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range="msvc-160"

Este artigo lista e descreve os comandos disponíveis no *vcperf.exe* e como usá-los.

## <a name="commands-to-start-and-stop-traces"></a>Comandos para iniciar e parar rastreamentos

*IMPORTANTE: todos os comandos a seguir exigem privilégios administrativos.*

| Opção           | Argumentos e descrição |
|------------------|---------------------------|
| `/start`         | `[/nocpusampling]` `<sessionName>` |
|                  | Informa *vcperf.exe* para iniciar um rastreamento sob o nome de sessão fornecido. Só pode haver uma sessão ativa por vez em um determinado computador. <br/><br/> Se a `/nocpusampling` opção for especificada, *vcperf.exe* não coletará exemplos de CPU. Ele impede o uso da exibição de uso da CPU (amostrada) no analisador de desempenho do Windows, mas torna os rastreamentos coletados menores. <br/><br/> Depois que o rastreamento é iniciado, *vcperf.exe* retorna imediatamente. Os eventos são coletados em todo o sistema para todos os processos em execução no computador. Isso significa que você não precisa criar seu projeto do mesmo prompt de comando que aquele usado para executar *vcperf.exe* . Por exemplo, você pode criar seu projeto no Visual Studio. |
| `/stop`          | `<sessionName>` `<outputFile.etl>` |
|                  | Interrompe o rastreamento identificado pelo nome de sessão fornecido. Executa uma etapa de pós-processamento no rastreamento para gerar um arquivo visível no analisador de desempenho do Windows (WPA). Para obter a melhor experiência de exibição, use uma versão do WPA que inclua o suplemento de insights de compilação do C++. Para obter mais informações, consulte Introdução [às ideias de Build do C++](../get-started-with-cpp-build-insights.md). O `<outputFile.etl>` parâmetro especifica onde salvar o arquivo de saída. |
| `/stopnoanalyze` | `<sessionName>` `<rawOutputFile.etl>` |
|                  | Interrompe o rastreamento identificado pelo nome de sessão fornecido e grava os dados brutos não processados no arquivo de saída especificado. O arquivo resultante não deve ser exibido no WPA. <br/><br/> A etapa de pós-processamento envolvida no `/stop` comando às vezes pode ser demorada. Você pode usar o `/stopnoanalyze` comando para atrasar esta etapa de pós-processamento. Use o `/analyze` comando quando estiver pronto para produzir um arquivo visível no analisador de desempenho do Windows. |

## <a name="miscellaneous-commands"></a>Comandos variados

| Opção     | Argumentos e descrição |
|------------|---------------------------|
| `/analyze` | `<rawInputFile.etl> <outputFile.etl>` |
|            | Aceita um arquivo de rastreamento bruto produzido pelo `/stopnoanalyze` comando. Executa uma etapa de pós-processamento nesse rastreamento para gerar um arquivo visível no analisador de desempenho do Windows. Para obter a melhor experiência de exibição, use uma versão do WPA que inclua o suplemento de insights de compilação do C++. Para obter mais informações, consulte Introdução [às ideias de Build do C++](../get-started-with-cpp-build-insights.md). |

## <a name="see-also"></a>Veja também

[Introdução às informações de Build do C++](../get-started-with-cpp-build-insights.md)\
[Tutorial: Noções básicas do analisador de desempenho do Windows](../tutorials/wpa-basics.md)\
[Referência: exibições do analisador de desempenho do Windows](wpa-views.md)\
[Windows Performance Analyzer](/windows-hardware/test/wpt/windows-performance-analyzer)

::: moniker-end
