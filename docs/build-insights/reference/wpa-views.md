---
title: 'Referência: Visualizações do Analisador de Desempenho do Windows'
description: Referência para visualizações C++ Build Insights disponíveis no Analisador de Desempenho do Windows.
ms.date: 11/03/2019
helpviewer_keywords:
- C++ Build Insights
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: b54b1b76d83b77ec7b8d8d3309d81ed9eb2db2d0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323231"
---
# <a name="reference-windows-performance-analyzer-views"></a>Referência: Visualizações do Analisador de Desempenho do Windows

::: moniker range="<=vs-2017"

As ferramentas C++ Build Insights estão disponíveis no Visual Studio 2019. Para ver a documentação desta versão, defina o controle do seletor Visual Studio **Version** para este artigo para o Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range="vs-2019"

Este artigo fornece detalhes sobre cada uma das visualizações do C++ Build Insights disponíveis no Windows Performance Analyzer (WPA). Use esta página para encontrar:

- descrições de colunas de dados; E
- predefinições disponíveis para cada exibição, incluindo seu uso pretendido e modo de visualização preferido.

Se você é novo no WPA, recomendamos que você primeiro se familiarize com o [básico do WPA para C++ Build Insights](/cpp/build-insights/tutorials/wpa-basics).

## <a name="build-explorer"></a>Gerenciador de Compilação

A exibição do Build Explorer está acostumada a:

- diagnosticar questões de paralelismo,
- determinar se o seu tempo de construção é dominado por análise, geração de código ou vinculação, e
- identificar gargalos e atividades de construção extraordinariamente longas.

### <a name="build-explorer-view-data-columns"></a>Criar colunas de dados de exibição do Explorer

| Nome da coluna | Descrição |
|-|-|
| BuildTimelineDescription | Uma descrição textual da linha do tempo em que a atividade ou propriedade atual ocorre. |
| BuildTimelineId          | Um identificador baseado em zero para a linha do tempo em que a atividade ou propriedade atual ocorre. |
| Componente                | O componente que está sendo compilado ou ligado quando o evento atual foi emitido. O valor desta coluna é * \<\> Invocação X Informações* quando nenhum componente está associado a este evento. X é um identificador numérico único para a invocação sendo executada no momento em que o evento foi emitido. Este identificador é o mesmo da coluna InvocaçãoId para este evento. |
| Contagem                    | O número de atividades ou propriedades representadas por essa linha de dados. Esse valor é sempre 1, e só é útil em cenários de agregação quando várias linhas são agrupadas. |
| EXCLUSIVOCPUTime         | A quantidade de tempo da CPU em milissegundos usado por esta atividade. O tempo gasto em atividades infantis não está incluído neste valor. |
| Duração exclusiva        | A duração de milissegundos da atividade. A duração das atividades infantis não está incluída neste montante. |
| InclusiveCPUTime         | A quantidade de tempo da CPU em milissegundos usado por esta atividade e todas as atividades infantis. |
| Duração inclusiva        | A duração de milissegundos desta atividade, incluindo todas as atividades infantis. |
| InvocaçãoDescrição    | Uma descrição textual da invocação em que este evento ocorreu. A descrição inclui se foi *cl.exe* ou *link.exe*, e um identificador de invocação numérica único. Se aplicável, inclui o caminho completo para o componente compilado ou ligado durante a invocação. Para invocações que não constroem nenhum componente ou para as que constroem vários componentes, o caminho está em branco. O identificador de invocação é o mesmo da coluna Invocação. |
| Invocationid             | Um identificador numérico único para a invocação em que este evento ocorreu. |
| Nome                     | O nome da atividade ou propriedade representada por este evento. |
| Hora                     | Um carimbo de data e hora que identifica quando o evento ocorreu. |
| Ferramenta                     | A ferramenta que executa quando este evento ocorreu. O valor desta coluna é CL ou Link. |
| Type                     | O tipo do evento atual. Este valor é atividade ou propriedade. |
| Valor                    | Se o evento atual for uma propriedade, esta coluna contém seu valor. Esta coluna é deixada em branco quando o evento atual é uma atividade. |

### <a name="build-explorer-view-presets"></a>Predefinições de visualização do Build Explorer

| Nome predefinido           | Modo de exibição preferido | Como usar |
|-----------------------|---------------------|------------|
| Estatísticas de Atividade   | Gráfico / Tabela       | Use esta preconfiguração para exibir estatísticas agregadas para todas as atividades do Build Explorer. No modo de tabela, diga rapidamente se sua compilação é dominada por análise, geração de código ou linker. As durações agregadas para cada atividade são classificadas em ordem decrescente. Faça exercícios expandindo o nó superior para encontrar facilmente quais invocações levam mais tempo para essas atividades de topo. Se você quiser, você pode ajustar as configurações wpa para mostrar médias ou outros tipos de agregações. No modo gráfico, veja quando cada atividade está ativa durante a sua compilação. |
| Invocações           | Grafo               | Role para baixo através de uma lista de invocações na exibição de gráficos classificada sem tempo inicial. Você pode usá-lo juntamente com a exibição CPU (Sampled) para encontrar invocações que se alinhem com zonas de utilização de CPU baixas. Detectar problemas de paralelismo. |
| Propriedades de Invocação | Tabela               | Encontre rapidamente informações-chave sobre uma determinada invocação de compilador ou linker. Determine sua versão, diretório de trabalho ou a linha de comando completa usada para invocá-la. |
| Linhas do tempo             | Grafo               | Veja um gráfico de barras de como sua compilação foi paraleletrizada. Identifique questões de paralelismo e gargalos rapidamente. Configure o WPA para atribuir diferentes significados às barras de acordo com suas necessidades. Escolha as descrições de invocação como a última coluna agrupada para exibir um gráfico de barras codificado por cores de todas as suas invocações. Ajuda você a identificar rapidamente os culpados demorados. Em seguida, amplie e escolha o nome da atividade como a última coluna agrupada para ver as partes mais longas. |

## <a name="files"></a>Arquivos

A exibição Arquivos é usada para:

- determinar quais cabeçalhos são incluídos com mais freqüência, e
- ajudá-lo a decidir o que incluir em um cabeçalho pré-compilado (PCH).

### <a name="files-view-data-columns"></a>Arquivos exibir colunas de dados

| Nome da coluna              | Descrição |
|--------------------------|-------------|
| ActivityName             | A atividade em andamento quando este evento de arquivo foi emitido. Atualmente, esse valor é sempre *parsing*. |
| BuildTimelineDescription | * |
| BuildTimelineId          | * |
| Componente                | * |
| Contagem                    | * |
| Profundidade                    | A posição baseada em zero na árvore de inclusão na qual este arquivo é encontrado. A contagem começa na raiz da árvore de inclusão. Um valor de 0 normalmente corresponde a um arquivo .c/.cpp. |
| Duração exclusiva        | * |
| Incluído               | O caminho completo do arquivo que incluía o arquivo atual. |
| IncluídoPath             | O caminho completo do arquivo atual. |
| Duração inclusiva        | * |
| Invocationid             | * |
| StartTime                | Um carimbo de data e hora que representa o momento em que o evento de arquivo atual foi emitido. |
| Ferramenta                     | * |

\*O valor desta coluna é o mesmo da exibição [Build Explorer.](#build-explorer-view-data-columns)

### <a name="files-view-presets"></a>Predefinições de exibição de arquivos

| Nome predefinido | Modo de exibição preferido | Como usar |
|-------------|---------------------|------------|
| Estatísticas  | Tabela               | Veja quais arquivos tiveram o maior tempo agregado de análise, olhando para a lista em ordem decrescente. Use essas informações para ajudá-lo a reestruturar seus cabeçalhos ou decidir o que incluir em seu PCH. |

## <a name="functions"></a>Funções

A exibição Funções é usada para identificar funções com um tempo de geração de código excessivamente longo.

### <a name="functions-view-data-columns"></a>Funções exibir colunas de dados

| Nome da coluna              | Descrição |
|--------------------------|-------------|
| ActivityName             | A atividade em andamento quando este evento de função foi emitido. Atualmente, esse valor é sempre *CodeGeneration*. |
| BuildTimelineDescription | * |
| BuildTimelineId          | * |
| Componente                | * |
| Contagem                    | * |
| Duration                 | A duração da atividade de geração de código para esta função. |
| FunctionName             | O nome da função em fase de geração de código. |
| Invocationid             | * |
| StartTime                | Um carimbo de data e hora que representa quando o evento de função atual foi emitido. |
| Ferramenta                     | * |

\*O valor desta coluna é o mesmo da exibição [Build Explorer.](#build-explorer-view-data-columns)

### <a name="functions-view-presets"></a>Predefinições de exibição de funções

| Nome predefinido | Modo de exibição preferido | Como usar |
|-------------|---------------------|------------|
| Estatísticas  | Tabela               | Veja quais funções tiveram o maior tempo agregado de geração de código, olhando para a lista em ordem decrescente. Eles podem sugerir onde seu código usa demais a **palavra-chave __forceinline,** ou que algumas funções podem ser muito grandes. |
| Linhas do tempo   | Grafo               | Olhe para este gráfico de barras para aprender a localização e duração das funções que levam mais tempo para gerar. Veja se eles se alinham com gargalos na exibição do Build Explorer. Se o fizerem, tome as medidas apropriadas para reduzir o tempo de geração de código e beneficiar seus tempos de construção. |

## <a name="see-also"></a>Confira também

[Comece com c++ Build Insights](/cpp/build-insights/get-started-with-cpp-build-insights)\
[Referência: comandos vcperf](vcperf-commands.md)\
[Tutorial: Noções básicas do Analisador de Desempenho do Windows](/cpp/build-insights/tutorials/wpa-basics)\
[Windows Performance Analyzer](/windows-hardware/test/wpt/windows-performance-analyzer)

::: moniker-end
