---
title: 'Referência: exibições do analisador de desempenho do Windows'
description: Referência para C++ os modos de exibição de informações de compilação disponíveis no analisador de desempenho do Windows.
ms.date: 11/03/2019
helpviewer_keywords:
- C++ Build Insights
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: eb3e20ed3ca4231b10efaf36310f6fbc0f5980bf
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332232"
---
# <a name="reference-windows-performance-analyzer-views"></a>Referência: exibições do analisador de desempenho do Windows

::: moniker range="<=vs-2017"

As C++ ferramentas de informações de compilação estão disponíveis no Visual Studio 2019. Para ver a documentação dessa versão, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2019.

::: moniker-end
::: moniker range="vs-2019"

Este artigo fornece detalhes sobre cada um dos C++ modos de exibição de informações de compilação disponíveis no Windows Performance Analyzer (WPA). Use esta página para localizar:

- descrições de coluna de dados; e
- predefinições disponíveis para cada exibição, incluindo o uso pretendido e o modo de exibição preferencial.

Se você for novo no WPA, recomendamos que você se familiarize com os [conceitos básicos do WPA C++ para obter informações](/cpp/build-insights/tutorials/wpa-basics)sobre o Build.

## <a name="build-explorer"></a>Build Explorer

A exibição do Gerenciador de compilação é usada para:

- diagnosticar problemas de paralelismo,
- Determine se o tempo de compilação é dominado pela análise, geração de código ou vinculação e
- Identifique afunilamentos e atividades de compilação normalmente longas.

### <a name="build-explorer-view-data-columns"></a>Colunas de dados de exibição do Gerenciador de compilação

| Nome da coluna | Descrição |
|-|-|
| BuildTimelineDescription | Uma descrição textual da linha do tempo na qual a atividade ou propriedade atual ocorre. |
| BuildTimelineId          | Um identificador de base zero para a linha do tempo em que a atividade ou propriedade atual ocorre. |
| Componente                | O componente que está sendo compilado ou vinculado quando o evento atual foi emitido. O valor desta coluna é *\<informações de invocação X\>* quando nenhum componente está associado a esse evento. X é um identificador numérico exclusivo para a invocação que está sendo executada no momento em que o evento foi emitido. Esse identificador é o mesmo da coluna invocaid para esse evento. |
| {1&gt;{2&gt;Contagem&lt;2}&lt;1}                    | O número de atividades ou propriedades representadas por esta linha de dados. Esse valor é sempre 1 e só é útil em cenários de agregação quando várias linhas são agrupadas. |
| ExclusiveCPUTime         | A quantidade de tempo de CPU, em milissegundos, usada por essa atividade. O tempo gasto em atividades filhas não está incluído nesse valor. |
| ExclusiveDuration        | A duração de milissegundos da atividade. A duração das atividades filhas não está incluída nesse valor. |
| InclusiveCPUTime         | A quantidade de tempo de CPU em milissegundos usada por essa atividade e todas as atividades filho. |
| InclusiveDuration        | A duração de milissegundos desta atividade, incluindo todas as atividades filho. |
| InvocationDescription    | Uma descrição textual da invocação em que esse evento ocorreu. A descrição inclui se ele foi *CL. exe* ou *link. exe*e um identificador de invocação numérica exclusivo. Se aplicável, ele inclui o caminho completo para o componente compilado ou vinculado durante a invocação. Para invocações que não criam nenhum componente ou para aqueles que criam vários componentes, o caminho fica em branco. O identificador de invocação é o mesmo da coluna invocaid. |
| InvocationId             | Um identificador numérico exclusivo para a invocação em que esse evento ocorreu. |
| {1&gt;Nome&lt;1}                     | O nome da atividade ou da propriedade representada por este evento. |
| Tempo                     | Um carimbo de data/hora que identifica quando o evento ocorreu. |
| Ferramenta                     | A ferramenta que está sendo executada quando esse evento ocorreu. O valor desta coluna é CL ou link. |
| Tipo                     | O tipo do evento atual. Esse valor é atividade ou propriedade. |
| {1&gt;Valor&lt;1}                    | Se o evento atual for uma propriedade, essa coluna conterá seu valor. Essa coluna é deixada em branco quando o evento atual é uma atividade. |

### <a name="build-explorer-view-presets"></a>Predefinições de exibição do Gerenciador de compilação

| Nome da predefinição           | Modo de exibição preferencial | Como usar |
|-----------------------|---------------------|------------|
| Estatísticas de atividade   | Gráfico/tabela       | Use essa predefinição para exibir estatísticas agregadas para todas as atividades do Gerenciador de compilação. No modo de tabela, informe rapidamente se sua compilação é dominada pela análise, geração de código ou pelo vinculador. As durações agregadas para cada atividade são classificadas em ordem decrescente. Aprofunde-se expandindo o nó superior para descobrir facilmente quais invocações levam mais tempo para essas atividades principais. Se desejar, você pode ajustar as configurações de WPA para mostrar as médias ou outros tipos de agregações. No modo de grafo, consulte quando cada atividade está ativa durante sua compilação. |
| Invocações           | Graph               | Role para baixo em uma lista de invocações na exibição de gráfico classificada por hora de início. Você pode usá-lo junto com a exibição CPU (amostra) para localizar invocações que se alinham com as zonas de baixa utilização da CPU. Detectar problemas de paralelismo. |
| Propriedades de invocação | Table               | Encontre rapidamente informações importantes sobre um determinado compilador ou invocação do vinculador. Determine sua versão, diretório de trabalho ou a linha de comando completa usada para chamá-la. |
| Linhas do tempo             | Graph               | Veja um gráfico de barras de como sua compilação foi paralelizada. Identifique problemas e afunilamentos de paralelismo em um relance. Configure o WPA para atribuir diferentes significados às barras de acordo com suas necessidades. Escolha descrições de invocação como a última coluna agrupada para exibir um grafo de barras codificado por cor de todas as suas invocações. Ele ajuda você a identificar rapidamente os culpados demorados. Em seguida, amplie e escolha o nome da atividade como a última coluna agrupada para ver as partes mais longas. |

## <a name="files"></a>Files

A exibição arquivos é usada para:

- Determine quais cabeçalhos serão incluídos com mais frequência e
- ajudá-lo a decidir o que incluir em um cabeçalho pré-compilado (PCH).

### <a name="files-view-data-columns"></a>Colunas de dados de exibição de arquivos

| Nome da coluna              | Descrição |
|--------------------------|-------------|
| ActivityName             | A atividade em andamento quando esse evento de arquivo foi emitido. Atualmente, esse valor é sempre *analisando*. |
| BuildTimelineDescription | * |
| BuildTimelineId          | * |
| Componente                | * |
| {1&gt;{2&gt;Contagem&lt;2}&lt;1}                    | * |
| Profundidade                    | A posição de base zero na árvore de inclusão na qual esse arquivo é encontrado. A contagem começa na raiz da árvore de inclusão. Um valor 0 geralmente corresponde a um arquivo. c/. cpp. |
| ExclusiveDuration        | * |
| IncludedBy               | O caminho completo do arquivo que incluiu o arquivo atual. |
| IncludedPath             | O caminho completo do arquivo atual. |
| InclusiveDuration        | * |
| InvocationId             | * |
| StartTime                | Um timestamp que representa a hora em que o evento do arquivo atual foi emitido. |
| Ferramenta                     | * |

\* o valor dessa coluna é o mesmo da exibição do [Gerenciador de compilação](#build-explorer-view-data-columns) .

### <a name="files-view-presets"></a>Predefinições de exibição de arquivos

| Nome da predefinição | Modo de exibição preferencial | Como usar |
|-------------|---------------------|------------|
| Estatísticas  | Table               | Veja quais arquivos tiveram o tempo de análise agregado mais alto examinando a lista em ordem decrescente. Use essas informações para ajudá-lo a reestruturar seus cabeçalhos ou a decidir o que incluir em PCH. |

## <a name="functions"></a>{1&gt;Funções&lt;1}

O modo de exibição de funções é usado para identificar funções com um tempo de geração de código excessivamente longo.

### <a name="functions-view-data-columns"></a>Colunas de dados da exibição de funções

| Nome da coluna              | Descrição |
|--------------------------|-------------|
| ActivityName             | A atividade em andamento quando esse evento de função foi emitido. Atualmente, esse valor é sempre *CodeGeneration*. |
| BuildTimelineDescription | * |
| BuildTimelineId          | * |
| Componente                | * |
| {1&gt;{2&gt;Contagem&lt;2}&lt;1}                    | * |
| Duration                 | A duração da atividade de geração de código para esta função. |
| FunctionName             | O nome da função que está passando pela geração de código. |
| InvocationId             | * |
| StartTime                | Um carimbo de data/hora que representa quando o evento de função atual foi emitido. |
| Ferramenta                     | * |

\* o valor dessa coluna é o mesmo da exibição do [Gerenciador de compilação](#build-explorer-view-data-columns) .

### <a name="functions-view-presets"></a>Predefinições de exibição de funções

| Nome da predefinição | Modo de exibição preferencial | Como usar |
|-------------|---------------------|------------|
| Estatísticas  | Table               | Veja quais funções tiveram o tempo de geração de código agregado mais alto examinando a lista em ordem decrescente. Eles podem indicar onde o código usa a palavra-chave **__forceinline** ou que algumas funções podem ser muito grandes. |
| Linhas do tempo   | Graph               | Examine este grafo de barras para saber o local e a duração das funções que levam mais tempo para gerar. Veja se eles se alinham com afunilamentos na exibição do Gerenciador de compilação. Se isso ocorrer, execute a ação apropriada para reduzir seu tempo de geração de código e beneficiar seus tempos de compilação. |

## <a name="see-also"></a>Consulte também

[Introdução às informações C++ de compilação](/cpp/build-insights/get-started-with-cpp-build-insights)\
[Referência: comandos vcperf](vcperf-commands.md)\
[Tutorial: Noções básicas do analisador de desempenho do Windows](/cpp/build-insights/tutorials/wpa-basics)\
[Windows Performance Analyzer](/windows-hardware/test/wpt/windows-performance-analyzer)

::: moniker-end
