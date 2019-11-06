---
title: 'C++Criar informações: referência de vcperf. exe'
description: Referência para o utilitário de linha de comando vcperf. exe.
ms.date: 11/03/2019
helpviewer_keywords:
- C++ Build Insights
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 195d115edae9947b39795440894e4f6bf0ee485e
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73633094"
---
# <a name="c-build-insights-vcperfexe-reference"></a>C++Criar informações: referência de vcperf. exe

::: moniker range="<=vs-2017"

As C++ ferramentas de informações de compilação estão disponíveis no Visual Studio 2019. Para ver a documentação dessa versão, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2019.

::: moniker-end
::: moniker range="vs-2019"

Este artigo lista e descreve os comandos disponíveis no *vcperf. exe*e como usá-los.

## <a name="commands-to-start-and-stop-traces"></a>Comandos para iniciar e parar rastreamentos

*IMPORTANTE: todos os comandos a seguir exigem privilégios administrativos.*

| Opção           | Argumentos e descrição |
|------------------|---------------------------|
| `/start`         | `[/nocpusampling]` `<sessionName>` |
|                  | Informa ao *vcperf. exe* para iniciar um rastreamento sob o nome de sessão fornecido. Só pode haver uma sessão ativa por vez em um determinado computador. <br/><br/> Se a opção `/nocpusampling` for especificada, *vcperf. exe* não coletará exemplos de CPU. Ele impede o uso da exibição de uso da CPU (amostrada) no analisador de desempenho do Windows, mas torna os rastreamentos coletados menores. <br/><br/> Depois que o rastreamento é iniciado, o *vcperf. exe* retorna imediatamente. Os eventos são coletados em todo o sistema para todos os processos em execução no computador. Isso significa que você não precisa criar seu projeto do mesmo prompt de comando que aquele usado para executar o *vcperf. exe*. Por exemplo, você pode criar seu projeto no Visual Studio. |
| `/stop`          | `<sessionName>` `<outputFile.etl>` |
|                  | Interrompe o rastreamento identificado pelo nome de sessão fornecido. Executa uma etapa de pós-processamento no rastreamento para gerar um arquivo visível no analisador de desempenho do Windows (WPA). Para obter a melhor experiência de exibição, use uma versão do WPA que C++ inclua o suplemento Build insights. Para obter mais informações, consulte Introdução [aos C++ insights de compilação](get-started-with-cpp-build-insights.md). O parâmetro `<outputFile.etl>` especifica onde salvar o arquivo de saída. |
| `/stopnoanalyze` | `<sessionName>` `<rawOutputFile.etl>` |
|                  | Interrompe o rastreamento identificado pelo nome de sessão fornecido e grava os dados brutos não processados no arquivo de saída especificado. O arquivo resultante não deve ser exibido no WPA. <br/><br/> Às vezes, a etapa de pós-processamento envolvida no comando `/stop` pode ser demorada. Você pode usar o comando `/stopnoanalyze` para atrasar esta etapa do pós-processamento. Use o comando `/analyze` quando estiver pronto para produzir um arquivo visível no analisador de desempenho do Windows. |

## <a name="miscellaneous-commands"></a>Comandos variados

| Opção     | Argumentos e descrição |
|------------|---------------------------|
| `/analyze` | `<rawInputFile.etl> <outputFile.etl>` |
|            | Aceita um arquivo de rastreamento bruto produzido pelo comando `/stopnoanalyze`. Executa uma etapa de pós-processamento nesse rastreamento para gerar um arquivo visível no analisador de desempenho do Windows. Para obter a melhor experiência de exibição, use uma versão do WPA que C++ inclua o suplemento Build insights. Para obter mais informações, consulte Introdução [aos C++ insights de compilação](get-started-with-cpp-build-insights.md). |

## <a name="see-also"></a>Consulte também

[Introdução às informações C++ de compilação](get-started-with-cpp-build-insights.md)\
[Noções básicas do analisador de desempenho do Windows](wpa-basics.md)\
[Referência de exibições do analisador de desempenho do Windows](wpa-views-reference.md)\
[Windows Performance Analyzer](/windows-hardware/test/wpt/windows-performance-analyzer)

::: moniker-end
