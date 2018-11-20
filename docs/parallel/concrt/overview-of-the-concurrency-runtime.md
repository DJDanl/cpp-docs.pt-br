---
title: Visão geral do Tempo de Execução de Simultaneidade
ms.date: 11/19/2018
helpviewer_keywords:
- Concurrency Runtime, requirements
- Concurrency Runtime, architecture
- Concurrency Runtime, overview
- Concurrency Runtime, lambda expressions
ms.assetid: 56237d96-10b0-494a-9cb4-f5c5090436c5
ms.openlocfilehash: ffaf560361da2fd54febb5e38af121ad5149f012
ms.sourcegitcommit: 9e891eb17b73d98f9086d9d4bfe9ca50415d9a37
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2018
ms.locfileid: "52176660"
---
# <a name="overview-of-the-concurrency-runtime"></a>Visão geral do Tempo de Execução de Simultaneidade

Este documento fornece uma visão geral do tempo de execução de simultaneidade. Ele descreve os benefícios do tempo de execução de simultaneidade, quando usá-lo e como seus componentes interagem entre si e com o sistema operacional e aplicativos.

##  <a name="top"></a> Seções

Este documento contém as seguintes seções:

- [Histórico de implementação de tempo de execução de simultaneidade](#dlls)

- [Por que um tempo de execução para simultaneidade é importante](#runtime)

- [Arquitetura](#architecture)

- [Expressões Lambda C++](#lambda)

- [Requisitos](#requirements)

## <a name="dlls"></a> Histórico de implementação de tempo de execução de simultaneidade

No Visual Studio 2010 por meio de 2013, o tempo de execução de simultaneidade foi incorporado msvcr100.dll por meio de msvcr120.dll.  Quando a refatoração do UCRT ocorreu no Visual Studio 2015, essa DLL foi Refatorada em três partes:

- ucrtbase. dll – C API, incluído no Windows 10 e atendidas de nível inferior por meio do Windows Update-

- suporte a compilador vcruntime140.dll – funções e tempo de execução do EH, enviadas por meio do Visual Studio

- concrt140.dll – tempo de execução de simultaneidade, enviadas por meio do Visual Studio. Necessários para contêineres em paralelo e algoritmos como `concurrency::parallel_for`. Além disso, a STL requer essa DLL no Windows XP para primitivos de sincronização de energia, como Windows XP não tem variáveis de condição.

No Visual Studio 2015 e versões posteriores, o Agendador de tarefas de tempo de execução de simultaneidade não é mais o Agendador para a classe de tarefa e os tipos relacionados em ppltasks. h. Esses tipos agora usam o pool de threads do Windows para melhor desempenho e interoperabilidade com primitivos de sincronização do Windows.

##  <a name="runtime"></a> Por que um tempo de execução para simultaneidade é importante

Um tempo de execução para simultaneidade fornece uniformidade e a previsibilidade a aplicativos e componentes de aplicativos que são executados simultaneamente. Estes são dois exemplos dos benefícios do tempo de execução de simultaneidade *agendamento de tarefas cooperativa* e *bloqueio cooperativo*.

O tempo de execução de simultaneidade usa um agendador de tarefas cooperativo que implementa um algoritmo de roubo de trabalho para distribuir o trabalho entre os recursos de computação com eficiência. Por exemplo, considere um aplicativo que tem dois threads que são gerenciados pelo mesmo tempo de execução. Se um thread termina sua tarefa agendada, ele pode descarregar o trabalho de outro segmento. Esse mecanismo equilibra a carga de trabalho geral do aplicativo.

O tempo de execução de simultaneidade também oferece primitivos de sincronização que usam o bloqueio cooperativo para sincronizar o acesso aos recursos. Por exemplo, considere uma tarefa que deve ter acesso exclusivo a um recurso compartilhado. Ao bloquear cooperativamente, o tempo de execução pode usar o quantum restante para executar outra tarefa, como a primeira tarefa aguarda o recurso. Esse mecanismo promove o uso máximo de recursos de computação.

[[Superior](#top)]

##  <a name="architecture"></a> Arquitetura

O tempo de execução de simultaneidade é dividido em quatro componentes: a biblioteca de padrões paralelos (PPL), a biblioteca de agentes assíncronos, o Agendador de tarefas e o Gerenciador de recursos. Esses componentes residam entre o sistema operacional e aplicativos. A ilustração a seguir mostra como os componentes de tempo de execução de simultaneidade interagem entre o sistema operacional e aplicativos:

**Arquitetura de tempo de execução de simultaneidade**

![A arquitetura de tempo de execução de simultaneidade](../../parallel/concrt/media/concurrencyrun.png "a arquitetura de tempo de execução de simultaneidade")

> [!IMPORTANT]
> Os componentes de Agendador de tarefas e o Gerenciador de recursos não estão disponíveis de um aplicativo da plataforma Universal do Windows (UWP) ou quando você usa a classe de tarefa ou outros tipos em ppltasks. h.

O tempo de execução de simultaneidade é altamente *Combinável*, ou seja, você pode combinar a funcionalidade existente para fazer mais. O tempo de execução de simultaneidade compõe muitos recursos, como algoritmos paralelos, de componentes de nível inferior.

O tempo de execução de simultaneidade também oferece primitivos de sincronização que usam o bloqueio cooperativo para sincronizar o acesso aos recursos. Para obter mais informações sobre esses primitivos de sincronização, consulte [estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md).

As seções a seguir fornecem uma visão geral de cada componente oferece e quando usá-lo.

### <a name="parallel-patterns-library"></a>Biblioteca de Padrões Paralelos

A biblioteca de padrões paralelos (PPL) fornece algoritmos e contêineres para fins gerais para executar o paralelismo refinado. Habilita a PPL *paralelismo de dados obrigatório* , fornecendo os algoritmos paralelos que distribuir computações em coleções ou em conjuntos de dados em recursos de computação. Ele também permite *paralelismo de tarefas* , fornecendo os objetos de tarefa que distribuir várias operações independentes em recursos de computação.

Use a biblioteca de padrões paralelos, quando você tem uma computação local que pode se beneficiar da execução paralela. Por exemplo, você pode usar o [Concurrency:: parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo para transformar uma existente `for` loop para atuar em paralelo.

Para obter mais informações sobre a biblioteca de padrões paralelos, consulte [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md).

### <a name="asynchronous-agents-library"></a>Biblioteca de Agentes Assíncronos

A biblioteca de agentes assíncronos (ou simplesmente *biblioteca de agentes*) fornece um modelo de programação baseado em ator e a transmissão de mensagem interfaces para o fluxo de dados de alta granularidade e pipelining de tarefas. Agentes assíncronos permitem fazer uso produtivo de latência enquanto outros componentes esperam dados executando o trabalho.

Use a biblioteca de agentes quando você tem várias entidades que se comunicam entre si de maneira assíncrona. Por exemplo, você pode criar um agente que lê dados de uma conexão de rede ou de arquivo e, em seguida, usa as interfaces de transmissão de mensagens para enviar esses dados para outro agente.

Para obter mais informações sobre a biblioteca de agentes, consulte [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md).

### <a name="task-scheduler"></a>Agendador de Tarefas

O Agendador de tarefas agenda e coordena tarefas em tempo de execução. O Agendador de tarefas é cooperativo e usa um algoritmo de roubo de trabalho para alcançar a utilização máxima dos recursos de processamento.

O tempo de execução de simultaneidade fornece um agendador padrão para que você não precise gerenciar detalhes da infraestrutura. No entanto, para atender as necessidades de qualidade do seu aplicativo, você também pode fornecer seus próprio agendamento agendadores de específico política ou associar com tarefas específicas.

Para obter mais informações sobre o Agendador de tarefas, consulte [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).

### <a name="resource-manager"></a>Gerenciador de Recursos

É a função do Gerenciador de recursos gerenciar recursos de computação, como processadores e memória. O Gerenciador de recursos responde às cargas de trabalho à medida que eles alterarem em tempo de execução por atribuir recursos para onde eles podem ser mais eficazes.

O Gerenciador de recursos serve como uma abstração sobre os recursos de computação e principalmente interage com o Agendador de tarefas. Embora você pode usar o Gerenciador de recursos para ajustar o desempenho dos seus aplicativos e bibliotecas, você normalmente usa a funcionalidade fornecida pela biblioteca de padrões paralelos, a biblioteca de agentes e o Agendador de tarefas. Essas bibliotecas de usam o Gerenciador de recursos para reequilibrar dinamicamente recursos como alterar as cargas de trabalho.

[[Superior](#top)]

##  <a name="lambda"></a> Expressões Lambda C++

Muitos dos tipos e algoritmos que são definidos pelo tempo de execução de simultaneidade são implementados como modelos de C++. Alguns desses tipos e algoritmos usam como um parâmetro de uma rotina que executa o trabalho. Esse parâmetro pode ser uma função lambda, um objeto de função ou um ponteiro de função. Essas entidades são também denominadas *funções de trabalho* ou *rotinas de trabalho*.

Expressões lambda são um importante novo recurso de linguagem de Visual C++, pois elas fornecem uma maneira sucinta para definir funções de trabalho para processamento paralelo. Objetos de função e ponteiros de função permitem que você usar o tempo de execução de simultaneidade com seu código existente. No entanto, é recomendável que você use expressões lambda ao escrever novo código devido aos benefícios de segurança e produtividade que eles fornecem.

O exemplo a seguir compara a sintaxe de funções lambda, objetos de função e ponteiros de função em várias chamadas para o [Concurrency:: parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) algoritmo. Cada chamada para `parallel_for_each` usa uma técnica diferente para calcular o quadrado de cada elemento em um [std:: array](../../standard-library/array-class-stl.md) objeto.

[!code-cpp[concrt-comparing-work-functions#1](../../parallel/concrt/codesnippet/cpp/overview-of-the-concurrency-runtime_1.cpp)]

**Saída**

```Output
1
256
6561
65536
390625
```

Para obter mais informações sobre as funções lambda em C++, consulte [expressões Lambda](../../cpp/lambda-expressions-in-cpp.md).

[[Superior](#top)]

##  <a name="requirements"></a> Requisitos

A tabela a seguir mostra os arquivos de cabeçalho que estão associados a cada componente do tempo de execução de simultaneidade:

|Componente|Arquivos de cabeçalho|
|---------------|------------------|
|Biblioteca de padrões paralelos (PPL)|PPL.h<br /><br /> concurrent_queue.h<br /><br /> concurrent_vector.h|
|Biblioteca de Agentes Assíncronos|agents.h|
|Agendador de Tarefas|concrt. h|
|Gerenciador de Recursos|concrtrm. h|

O tempo de execução de simultaneidade é declarado na [simultaneidade](../../parallel/concrt/reference/concurrency-namespace.md) namespace. (Você também pode usar [simultaneidade](../../parallel/concrt/reference/concurrency-namespace.md), que é um alias para esse namespace.) O `concurrency::details` namespace oferece suporte a estrutura de tempo de execução de simultaneidade e não se destina a ser usado diretamente do seu código.

O tempo de execução de simultaneidade é fornecido como parte da biblioteca de tempo de execução C (CRT). Para obter mais informações sobre como criar um aplicativo que usa o CRT, consulte [recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).

[[Superior](#top)]

