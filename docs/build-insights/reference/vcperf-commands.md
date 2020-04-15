---
title: 'Referência: comandos vcperf'
description: Referência para o utilitário de linha de comando vcperf.exe.
ms.date: 11/03/2019
helpviewer_keywords:
- C++ Build Insights
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 9d3b0a9dbdfe922dc87f91006441e1f65d54c8a7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323247"
---
# <a name="reference-vcperf-commands"></a>Referência: comandos vcperf

::: moniker range="<=vs-2017"

As ferramentas C++ Build Insights estão disponíveis no Visual Studio 2019. Para ver a documentação dessa versão, defina o controle do seletor Visual Studio **Version** para este artigo para o Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range="vs-2019"

Este artigo lista e descreve os comandos disponíveis em *vcperf.exe*, e como usá-los.

## <a name="commands-to-start-and-stop-traces"></a>Comandos para iniciar e parar rastreamentos

*IMPORTANTE: todos os seguintes comandos exigem privilégios administrativos.*

| Opção           | Argumentos e descrição |
|------------------|---------------------------|
| `/start`         | `[/nocpusampling]` `<sessionName>` |
|                  | Diz *vcperf.exe* para iniciar um rastreamento sob o nome da sessão dado. Só pode haver uma sessão ativa de cada vez em uma determinada máquina. <br/><br/> Se `/nocpusampling` a opção for especificada, *vcperf.exe* não coletará amostras de CPU. Ele impede o uso da visualização de uso da CPU (Sampled) no Analisador de Desempenho do Windows, mas torna os traços coletados menores. <br/><br/> Uma vez iniciado o rastreamento, *vcperf.exe* retorna imediatamente. Os eventos são coletados em todo o sistema para todos os processos em execução na máquina. Isso significa que você não precisa construir seu projeto a partir do mesmo prompt de comando que o que você usou para executar *vcperf.exe*. Por exemplo, você pode construir seu projeto a partir do Visual Studio. |
| `/stop`          | `<sessionName>` `<outputFile.etl>` |
|                  | Interrompe o traço identificado pelo nome da sessão. Executa uma etapa de pós-processamento no trace para gerar um arquivo visível no WPA (Windows Performance Analyzer). Para obter a melhor experiência de visualização, use uma versão do WPA que inclua o complemento C++ Build Insights. Para obter mais informações, consulte [Comece com o C++ Build Insights](/cpp/build-insights/get-started-with-cpp-build-insights). O `<outputFile.etl>` parâmetro especifica onde salvar o arquivo de saída. |
| `/stopnoanalyze` | `<sessionName>` `<rawOutputFile.etl>` |
|                  | Interrompe o rastreamento identificado pelo nome da sessão dado e grava os dados brutos e não processados no arquivo de saída especificado. O arquivo resultante não deve ser visualizado no WPA. <br/><br/> A etapa de pós-processamento `/stop` envolvida no comando às vezes pode ser demorada. Você pode `/stopnoanalyze` usar o comando para atrasar esta etapa de pós-processamento. Use `/analyze` o comando quando estiver pronto para produzir um arquivo visível no Analisador de Desempenho do Windows. |

## <a name="miscellaneous-commands"></a>Comandos variados

| Opção     | Argumentos e descrição |
|------------|---------------------------|
| `/analyze` | `<rawInputFile.etl> <outputFile.etl>` |
|            | Aceita um arquivo de rastreamento `/stopnoanalyze` bruto produzido pelo comando. Execute uma etapa de pós-processamento neste trace para gerar um arquivo visível no Analisador de Desempenho do Windows. Para obter a melhor experiência de visualização, use uma versão do WPA que inclua o complemento C++ Build Insights. Para obter mais informações, consulte [Comece com o C++ Build Insights](/cpp/build-insights/get-started-with-cpp-build-insights). |

## <a name="see-also"></a>Confira também

[Comece com c++ Build Insights](/cpp/build-insights/get-started-with-cpp-build-insights)\
[Tutorial: Noções básicas do Analisador de Desempenho do Windows](/cpp/build-insights/tutorials/wpa-basics)\
[Referência: Visualizações do Analisador de Desempenho do Windows](wpa-views.md)\
[Windows Performance Analyzer](/windows-hardware/test/wpt/windows-performance-analyzer)

::: moniker-end
