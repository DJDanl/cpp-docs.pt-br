---
title: "Visão geral do tempo de execução de simultaneidade | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- Concurrency Runtime, requirements
- Concurrency Runtime, architecture
- Concurrency Runtime, overview
- Concurrency Runtime, lambda expressions
ms.assetid: 56237d96-10b0-494a-9cb4-f5c5090436c5
caps.latest.revision: "22"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ce1967b04770f53c2e1acbd49342f9080a7e3c12
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="overview-of-the-concurrency-runtime"></a>Visão geral do Tempo de Execução de Simultaneidade
Este documento fornece uma visão geral do tempo de execução de simultaneidade. Descreve os benefícios do tempo de execução de simultaneidade, quando usá-lo e como seus componentes interagem entre si e com o sistema operacional e aplicativos.  
  
> [!IMPORTANT]
>  No Visual Studio 2015 e posteriores, o Agendador de tarefas de tempo de execução de simultaneidade não é mais o Agendador para a classe de tarefa e tipos relacionados em ppltasks. Os tipos agora usam ThreadPool Windows para melhor desempenho e interoperabilidade com primitivos de sincronização do Windows. Algoritmos paralelos, como parallel_for continuam a usar o Agendador de tarefas de tempo de execução de simultaneidade.  
  
##  <a name="top"></a>Seções  
 Este documento contém as seguintes seções:  
  
-   [Por que um tempo de execução de simultaneidade é importante](#runtime)  
  
-   [Arquitetura](#architecture)  
  
-   [Expressões Lambda C++](#lambda)  
  
-   [Requisitos](#requirements)  
  
##  <a name="runtime"></a>Por que um tempo de execução de simultaneidade é importante  
 Um tempo de execução de simultaneidade fornece uniformidade e previsibilidade a aplicativos e componentes de aplicativos que são executados simultaneamente. Dois exemplos dos benefícios do tempo de execução de simultaneidade são *agendamento de tarefas cooperativa* e *bloqueio cooperativo*.  
  
 O tempo de execução de simultaneidade usa um agendador de tarefas cooperativa que implementa um algoritmo de roubo de trabalho para distribuir o trabalho entre os recursos de computação com eficiência. Por exemplo, considere um aplicativo que tem dois threads que são gerenciados pelo tempo de execução do mesmo. Se um thread conclui sua tarefa agendada, ele pode descarregar trabalhar a partir de outro thread. Esse mecanismo equilibra a carga de trabalho geral do aplicativo.  
  
 O tempo de execução de simultaneidade também fornece os primitivos de sincronização que usam o bloqueio cooperativo para sincronizar o acesso aos recursos. Por exemplo, considere uma tarefa que deve ter acesso exclusivo a um recurso compartilhado. Bloqueando trabalhem de forma, o tempo de execução pode usar o quantum restante para executar outra tarefa, como a primeira tarefa aguarda o recurso. Esse mecanismo promove o uso máximo de recursos de computação.  
  
 [[Superior](#top)]  
  
##  <a name="architecture"></a> Arquitetura  
 O tempo de execução de simultaneidade é dividido em quatro componentes: a biblioteca de padrões paralelos (PPL), a biblioteca de agentes assíncrona, o Agendador de tarefas e o Gerenciador de recursos. Esses componentes residam entre o sistema operacional e aplicativos. A ilustração a seguir mostra como os componentes de tempo de execução de simultaneidade interagem entre o sistema operacional e aplicativos:  
  
 **Arquitetura de tempo de execução de simultaneidade**  
  
 ![A arquitetura de tempo de execução de simultaneidade](../../parallel/concrt/media/concurrencyrun.png "concurrencyrun")  
  
> [!IMPORTANT]
>  Os componentes de Agendador de tarefas e o Gerenciador de recursos não estão disponíveis de um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo ou quando você usa a classe task ou outros tipos em ppltasks.  
  
 O tempo de execução de simultaneidade é altamente *Combinável*, ou seja, você pode combinar funções existentes para fazer muito mais. O tempo de execução de simultaneidade compõe muitos recursos, como os algoritmos paralelos, de componentes de nível inferior.  
  
 O tempo de execução de simultaneidade também fornece os primitivos de sincronização que usam o bloqueio cooperativo para sincronizar o acesso aos recursos. Para obter mais informações sobre esses primitivos de sincronização, consulte [estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md).  
  
 As seções a seguir fornecem uma visão geral de cada componente fornece e quando usá-lo.  
  
### <a name="parallel-patterns-library"></a>Biblioteca de Padrões Paralelos  
 A biblioteca de padrões paralelos (PPL) fornece algoritmos e contêineres para fins gerais para executar o paralelismo refinado. Habilita a PPL *paralelismo de dados obrigatório* , fornecendo os algoritmos paralelos que distribuir computações em coleções ou em conjuntos de dados em recursos de computação. Ele também permite que *paralelismo de tarefa* fornecendo objetos de tarefa que distribuir várias operações independentes em recursos de computação.  
  
 Use a biblioteca de padrões paralelos, quando você tem uma computação local que pode se beneficiar da execução paralela. Por exemplo, você pode usar o [concurrency::parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo para transformar uma existente `for` loop para atuar em paralelo.  
  
 Para obter mais informações sobre a biblioteca de padrões paralelos, consulte [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md).  
  
### <a name="asynchronous-agents-library"></a>Biblioteca de Agentes Assíncronos  
 A biblioteca de agentes assíncrona (ou apenas *biblioteca de agentes*) fornece um modelo de programação baseado em ator e a mensagem passando interfaces de fluxo de dados de alta granularidade e pipeline de tarefas. Agentes assíncronos lhe permitem fazer uso produtivo de latência enquanto esperam outros componentes de dados executando o trabalho.  
  
 Use a biblioteca de agentes, quando você tem várias entidades se comunicar entre si de maneira assíncrona. Por exemplo, você pode criar um agente que lê dados de uma conexão de arquivo ou de rede e, em seguida, usa as interfaces de transmissão de mensagens para enviar dados para outro agente.  
  
 Para obter mais informações sobre a biblioteca de agentes, consulte [biblioteca de agentes assíncrona](../../parallel/concrt/asynchronous-agents-library.md).  
  
### <a name="task-scheduler"></a>Agendador de Tarefas  
 O Agendador de tarefas agenda e coordena as tarefas em tempo de execução. O Agendador de tarefas é cooperativo e usa um algoritmo de roubo de trabalho para obter o máximo uso dos recursos de processamento.  
  
 O tempo de execução de simultaneidade fornece um agendador padrão para que você não precisa gerenciar detalhes de infraestrutura. No entanto, para atender as necessidades de qualidade do seu aplicativo, você também pode fornecer seus próprio agendamento agendadores de específico política ou associar com tarefas específicas.  
  
 Para obter mais informações sobre o Agendador de tarefas, consulte [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).  
  
### <a name="resource-manager"></a>Gerenciador de Recursos  
 É a função do Gerenciador de recursos gerenciar recursos de computação, como processadores e memória. O Gerenciador de recursos responde às cargas de trabalho conforme eles mudam em tempo de execução por atribuição de recursos onde podem ser mais eficientes.  
  
 O Gerenciador de recursos serve como uma abstração sobre recursos de computação e principalmente interage com o Agendador de tarefas. Embora você pode usar o Gerenciador de recursos para ajustar o desempenho de bibliotecas e aplicativos, você normalmente usa a funcionalidade que é fornecida pela biblioteca padrões paralelos, a biblioteca de agentes e o Agendador de tarefas. Essas bibliotecas de usam o Gerenciador de recursos para reequilibrar dinamicamente recursos como alterar as cargas de trabalho.  
  
 [[Superior](#top)]  
  
##  <a name="lambda"></a>Expressões Lambda C++  
 Muitos dos tipos e algoritmos que são definidos pelo tempo de execução de simultaneidade são implementados como modelos do C++. Alguns desses tipos e algoritmos levam como um parâmetro de uma rotina que executa o trabalho. Esse parâmetro pode ser uma função lambda, um objeto de função ou um ponteiro de função. Essas entidades também são conhecidas como *funções de trabalho* ou *rotinas de trabalho*.  
  
 Expressões lambda são um recurso de linguagem Visual C++ novo importante porque eles oferecem uma maneira sucinta para definir funções de trabalho para processamento paralelo. Objetos de função e ponteiros de função permitem que você use o tempo de execução de simultaneidade com seu código existente. No entanto, é recomendável que você usar expressões lambda ao escrever novo código devido os benefícios de produtividade e segurança que eles fornecem.  
  
 O exemplo a seguir compara a sintaxe de funções de lambda, objetos de função e ponteiros de função em várias chamadas para o [Concurrency:: parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) algoritmo. Cada chamada para `parallel_for_each` usa uma técnica diferente para calcular o quadrado de cada elemento em uma [std:: array](../../standard-library/array-class-stl.md) objeto.  
  
 [!code-cpp[concrt-comparing-work-functions#1](../../parallel/concrt/codesnippet/cpp/overview-of-the-concurrency-runtime_1.cpp)]  
  
 **Saída**  
  
```Output  
1  
256  
6561  
65536  
390625  
```  
  
 Para obter mais informações sobre funções de lambda em C++, consulte [expressões Lambda](../../cpp/lambda-expressions-in-cpp.md).  
  
 [[Superior](#top)]  
  
##  <a name="requirements"></a> Requisitos  
 A tabela a seguir mostra os arquivos de cabeçalho que estão associados a cada componente do tempo de execução de simultaneidade:  
  
|Componente|Arquivos de cabeçalho|  
|---------------|------------------|  
|Biblioteca de padrões paralelos (PPL)|PPL.h<br /><br /> concurrent_queue.h<br /><br /> concurrent_vector.h|  
|Biblioteca de Agentes Assíncronos|Agents.h|  
|Agendador de Tarefas|concrt.h|  
|Gerenciador de Recursos|concrtrm.h|  
  
 O tempo de execução de simultaneidade é declarado no [simultaneidade](../../parallel/concrt/reference/concurrency-namespace.md) namespace. (Você também pode usar [simultaneidade](../../parallel/concrt/reference/concurrency-namespace.md), que é um alias para esse namespace.) O `concurrency::details` namespace suporte para a estrutura de tempo de execução de simultaneidade e não se destina a ser usado diretamente no seu código.  
  
 O tempo de execução de simultaneidade é fornecido como parte da biblioteca de tempo de execução C (CRT). Para obter mais informações sobre como criar um aplicativo que usa o CRT, consulte [recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).  
  
 [[Superior](#top)]



