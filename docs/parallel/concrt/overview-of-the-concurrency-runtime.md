---
title: Visão geral do Runtime de Simultaneidade
ms.date: 11/19/2018
helpviewer_keywords:
- Concurrency Runtime, requirements
- Concurrency Runtime, architecture
- Concurrency Runtime, overview
- Concurrency Runtime, lambda expressions
ms.assetid: 56237d96-10b0-494a-9cb4-f5c5090436c5
ms.openlocfilehash: b50c943bb83c587ab4001556b1143f9d5f868a0b
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142929"
---
# <a name="overview-of-the-concurrency-runtime"></a>Visão geral do Runtime de Simultaneidade

Este documento fornece uma visão geral do Tempo de Execução de Simultaneidade. Ele descreve os benefícios do Tempo de Execução de Simultaneidade, quando usá-lo e como seus componentes interagem entre si e com o sistema operacional e os aplicativos.

## <a name="top"></a>As

Este documento contém as seguintes seções:

- [Histórico de implementação de Tempo de Execução de Simultaneidade](#dlls)

- [Por que um tempo de execução para simultaneidade é importante](#runtime)

- [Arquitetura](#architecture)

- [C++Expressões lambda](#lambda)

- [Requisitos](#requirements)

## <a name="dlls"></a>Histórico de implementação de Tempo de Execução de Simultaneidade

No Visual Studio 2010 até 2013, o Tempo de Execução de Simultaneidade foi incorporado em msvcr100. dll por meio de msvcr120. dll.  Quando a refatoração UCRT ocorreu no Visual Studio 2015, essa DLL foi Refatorada em três partes:

- ucrtbase. dll – C API, fornecida no Windows 10 e em nível inferior atendido por meio de Windows Update-

- vcruntime140. dll – funções de suporte do compilador e tempo de execução do EH, fornecidos por meio do Visual Studio

- concrt140. dll – Tempo de Execução de Simultaneidade, fornecido por meio do Visual Studio. Necessário para contêineres paralelos e algoritmos como `concurrency::parallel_for`. Além disso, a STL requer essa DLL no Windows XP para primitivos de sincronização de energia, porque o Windows XP não tem variáveis de condição.

No Visual Studio 2015 e posterior, o Agendador de Tarefas de Tempo de Execução de Simultaneidade não é mais o Agendador para a classe de tarefa e os tipos relacionados em ppltasks. h. Esses tipos agora usam o ThreadPool do Windows para melhorar o desempenho e a interoperabilidade com primitivos de sincronização do Windows.

## <a name="runtime"></a>Por que um tempo de execução para simultaneidade é importante

Um tempo de execução para simultaneidade fornece uniformidade e previsibilidade para aplicativos e componentes de aplicativos que são executados simultaneamente. Dois exemplos dos benefícios do Tempo de Execução de Simultaneidade são o *agendamento de tarefas cooperativas* e o *bloqueio cooperativo*.

O Tempo de Execução de Simultaneidade usa um Agendador de tarefas cooperativo que implementa um algoritmo de roubo de trabalho para distribuir o trabalho com eficiência entre os recursos de computação. Por exemplo, considere um aplicativo que tenha dois threads gerenciados pelo mesmo tempo de execução. Se um thread concluir sua tarefa agendada, ele poderá descarregar o trabalho do outro thread. Esse mecanismo equilibra a carga de trabalho geral do aplicativo.

O Tempo de Execução de Simultaneidade também fornece primitivos de sincronização que usam o bloqueio cooperativo para sincronizar o acesso aos recursos. Por exemplo, considere uma tarefa que deve ter acesso exclusivo a um recurso compartilhado. Ao bloquear a cooperação, o tempo de execução pode usar o Quantum restante para executar outra tarefa, uma vez que a primeira tarefa aguarda o recurso. Esse mecanismo promove o uso máximo de recursos de computação.

[[Superior](#top)]

## <a name="architecture"></a> Arquitetura

O Tempo de Execução de Simultaneidade é dividido em quatro componentes: a PPL (biblioteca de padrões paralelos), a biblioteca de agentes assíncronos, a Agendador de Tarefas e o Gerenciador de recursos. Esses componentes residem entre o sistema operacional e os aplicativos. A ilustração a seguir mostra como os componentes do Tempo de Execução de Simultaneidade interagem entre o sistema operacional e os aplicativos:

**Arquitetura de Tempo de Execução de Simultaneidade**

![A arquitetura de Tempo de Execução de Simultaneidade](../../parallel/concrt/media/concurrencyrun.png "A arquitetura de Tempo de Execução de Simultaneidade")

> [!IMPORTANT]
> Os componentes Agendador de Tarefas e Resource Manager não estão disponíveis em um aplicativo Plataforma Universal do Windows (UWP) ou quando você usa a classe de tarefa ou outros tipos em ppltasks. h.

A Tempo de Execução de Simultaneidade é altamente *combinável*, ou seja, você pode combinar a funcionalidade existente para fazer mais. O Tempo de Execução de Simultaneidade compõe muitos recursos, como algoritmos paralelos, de componentes de nível inferior.

O Tempo de Execução de Simultaneidade também fornece primitivos de sincronização que usam o bloqueio cooperativo para sincronizar o acesso aos recursos. Para obter mais informações sobre esses primitivos de sincronização, consulte [Synchronization data structures](../../parallel/concrt/synchronization-data-structures.md).

As seções a seguir fornecem uma visão geral resumida do que cada componente fornece e quando usá-lo.

### <a name="parallel-patterns-library"></a>Biblioteca de Padrões Paralelos

A PPL (biblioteca de padrões paralelos) fornece algoritmos e contêineres de uso geral para a execução de paralelismo refinado. A PPL permite *paralelismo de dados imperativos* , fornecendo algoritmos paralelos que distribuem cálculos em coleções ou conjuntos de dados entre recursos de computação. Ele também habilita o *paralelismo de tarefas* fornecendo objetos de tarefa que distribuem várias operações independentes entre recursos de computação.

Use a biblioteca de padrões paralelos quando você tiver um cálculo local que possa se beneficiar da execução paralela. Por exemplo, você pode usar o algoritmo [Concurrency::p arallel_for](reference/concurrency-namespace-functions.md#parallel_for) para transformar um loop de `for` existente para atuar em paralelo.

Para obter mais informações sobre a biblioteca de padrões paralelos, consulte [ppl (biblioteca de padrões paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md).

### <a name="asynchronous-agents-library"></a>Biblioteca de Agentes Assíncronos

A biblioteca de agentes assíncronos (ou apenas a *biblioteca de agentes*) fornece um modelo de programação baseado em ator e interfaces de passagem de mensagens para tarefas de pipeline e fluxo de bits de alta granularidade. Os agentes assíncronos permitem que você faça uso produtivo da latência executando o trabalho, pois outros componentes esperam dados.

Use a biblioteca de agentes quando você tiver várias entidades que se comunicam entre si de forma assíncrona. Por exemplo, você pode criar um agente que lê dados de um arquivo ou conexão de rede e, em seguida, usa as interfaces de passagem de mensagens para enviar esses dados para outro agente.

Para obter mais informações sobre a biblioteca de agentes, consulte [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md).

### <a name="task-scheduler"></a>Agendador de Tarefas

O Agendador de Tarefas agenda e coordena tarefas em tempo de execução. O Agendador de Tarefas é cooperativo e usa um algoritmo de roubo de trabalho para obter o uso máximo de recursos de processamento.

O Tempo de Execução de Simultaneidade fornece um agendador padrão para que você não precise gerenciar os detalhes da infraestrutura. No entanto, para atender às necessidades de qualidade do seu aplicativo, você também pode fornecer sua própria política de agendamento ou associar agendadores específicos a tarefas específicas.

Para obter mais informações sobre o Agendador de Tarefas, consulte [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).

### <a name="resource-manager"></a>Gerenciador de Recursos

A função do Gerenciador de recursos é gerenciar recursos de computação, como processadores e memória. O Gerenciador de recursos responde às cargas de trabalho conforme elas são alteradas em tempo de execução, atribuindo recursos para onde elas podem ser mais eficazes.

O Gerenciador de recursos serve como uma abstração sobre os recursos de computação e, principalmente, interage com o Agendador de Tarefas. Embora você possa usar o Gerenciador de recursos para ajustar o desempenho de suas bibliotecas e aplicativos, normalmente usa a funcionalidade fornecida pela biblioteca de padrões paralelos, a biblioteca de agentes e a Agendador de Tarefas. Essas bibliotecas usam o Gerenciador de recursos para reequilibrar dinamicamente os recursos à medida que as cargas de trabalho mudam.

[[Superior](#top)]

## <a name="lambda"></a>C++ Expressões lambda

Muitos dos tipos e algoritmos definidos pelo Tempo de Execução de Simultaneidade são implementados como C++ modelos. Alguns desses tipos e algoritmos assumem como um parâmetro uma rotina que executa o trabalho. Esse parâmetro pode ser uma função lambda, um objeto Function ou um ponteiro de função. Essas entidades também são referidas como *funções de trabalho* ou *rotinas de trabalho*.

As expressões lambda são um novo recurso C++ de linguagem Visual importante, pois elas fornecem uma maneira sucinta de definir funções de trabalho para processamento paralelo. Os objetos de função e os ponteiros de função permitem que você use o Tempo de Execução de Simultaneidade com o código existente. No entanto, recomendamos que você use expressões lambda ao escrever um novo código devido aos benefícios de segurança e produtividade que eles fornecem.

O exemplo a seguir compara a sintaxe de funções lambda, objetos de função e ponteiros de função em várias chamadas para o algoritmo [Concurrency::p arallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) . Cada chamada para `parallel_for_each` usa uma técnica diferente para computar o quadrado de cada elemento em um objeto [std:: array](../../standard-library/array-class-stl.md) .

[!code-cpp[concrt-comparing-work-functions#1](../../parallel/concrt/codesnippet/cpp/overview-of-the-concurrency-runtime_1.cpp)]

**Saída**

```Output
1
256
6561
65536
390625
```

Para obter mais informações sobre funções lambda C++no, consulte [expressões lambda](../../cpp/lambda-expressions-in-cpp.md).

[[Superior](#top)]

## <a name="requirements"></a> Requisitos

A tabela a seguir mostra os arquivos de cabeçalho associados a cada componente do Tempo de Execução de Simultaneidade:

|Componente|Arquivos de cabeçalho|
|---------------|------------------|
|Biblioteca de padrões paralelos (PPL)|ppl.h<br /><br /> concurrent_queue.h<br /><br /> concurrent_vector.h|
|Biblioteca de Agentes Assíncronos|agents.h|
|Agendador de Tarefas|ConcRT. h|
|Gerenciador de Recursos|concrtrm.h|

O Tempo de Execução de Simultaneidade é declarado no namespace de [simultaneidade](../../parallel/concrt/reference/concurrency-namespace.md) . (Você também pode usar a [simultaneidade](../../parallel/concrt/reference/concurrency-namespace.md), que é um alias para esse namespace.) O namespace `concurrency::details` dá suporte à estrutura de Tempo de Execução de Simultaneidade e não se destina a ser usado diretamente do seu código.

O Tempo de Execução de Simultaneidade é fornecido como parte da biblioteca de tempo de execução C (CRT). Para obter mais informações sobre como criar um aplicativo que usa o CRT, consulte [recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).

[[Superior](#top)]
