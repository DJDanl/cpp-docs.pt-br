---
title: "Vis&#227;o geral do Tempo de Execu&#231;&#227;o de Simultaneidade | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Tempo de Execução de Simultaneidade, arquitetura"
  - "Tempo de Execução de Simultaneidade, expressões lambda"
  - "Tempo de Execução de Simultaneidade, visão geral"
  - "Tempo de Execução de Simultaneidade, requisitos"
ms.assetid: 56237d96-10b0-494a-9cb4-f5c5090436c5
caps.latest.revision: 22
caps.handback.revision: 19
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Vis&#227;o geral do Tempo de Execu&#231;&#227;o de Simultaneidade
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este documento fornece uma visão geral do tempo de execução de simultaneidade.  Ele descreve os benefícios do tempo de execução de simultaneidade, quando usá\-lo e como seus componentes interagem entre si e com o sistema operacional e aplicativos.  
  
> [!IMPORTANT]
>  No Visual Studio de 2015 e posterior, o Agendador de tarefas de tempo de execução de simultaneidade não é mais o Agendador para a classe de tarefa e tipos relacionados em ppltasks.  Esses tipos de usam ThreadPool do Windows para melhor desempenho e interoperabilidade com primitivos de sincronização do Windows.  Algoritmos paralelos, como parallel\_for continuam a usar o Agendador de tarefas de tempo de execução de simultaneidade.  
  
##  <a name="top"></a> Seções  
 Este documento contém as seguintes seções:  
  
-   [Por que um Tempo de Execução para Simultaneidade é Importante](#runtime)  
  
-   [Arquitetura](#architecture)  
  
-   [Expressões Lambda C\+\+](#lambda)  
  
-   [Requisitos](#requirements)  
  
##  <a name="runtime"></a> Por que um Tempo de Execução para Simultaneidade é Importante  
 Um tempo de execução de simultaneidade fornece uniformidade e previsibilidade a aplicativos e componentes de aplicativos executam simultaneamente.  Dois exemplos das vantagens do Runtime de simultaneidade são *agendamento de tarefas cooperativa* e *bloqueio cooperativo*.  
  
 O tempo de execução de simultaneidade usa um agendador de tarefas cooperativo que implementa um algoritmo de roubo de trabalho para distribuir o trabalho entre os recursos de computação de forma eficiente.  Por exemplo, considere um aplicativo que tenha dois threads que são gerenciados pelo tempo de execução do mesmo.  Se um thread concluir sua tarefa agendada, ele pode descarregar o trabalho de outro thread.  Esse mecanismo equilibra a carga de trabalho geral do aplicativo.  
  
 O tempo de execução de simultaneidade também oferece primitivos de sincronização que usam o bloqueio cooperativo para sincronizar o acesso aos recursos.  Por exemplo, considere uma tarefa que deve ter acesso exclusivo a um recurso compartilhado.  Ao bloquear de forma cooperativa, o runtime pode usar o quantum restante para executar outra tarefa, como a primeira tarefa aguarda o recurso.  Esse mecanismo promove o uso máximo dos recursos de computação.  
  
 \[[Top](#top)\]  
  
##  <a name="architecture"></a> Arquitetura  
 O tempo de execução de simultaneidade é dividido em quatro componentes: o Parallel padrões PPL \(biblioteca\), a biblioteca de agentes assíncrona, o Agendador de tarefas e o Gerenciador de recursos.  Esses componentes residam entre o sistema operacional e aplicativos.  A ilustração a seguir mostra como os componentes de tempo de execução de simultaneidade interagem entre o sistema operacional e aplicativos:  
  
 **Arquitetura de tempo de execução de simultaneidade**  
  
 ![A arquitetura de Runtime de simultaneidade](../Image/ConcurrencyRun.png "ConcurrencyRun")  
  
> [!IMPORTANT]
>  Os componentes do Agendador de tarefas e o Gerenciador de recursos não estão disponíveis de uma [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo ou quando você usa a classe task ou outros tipos em ppltasks.  
  
 O tempo de execução de simultaneidade é altamente *Combinável*, ou seja, você pode combinar funções existentes para fazer mais.  O tempo de execução de simultaneidade compõe muitos recursos, como algoritmos paralelos, de componentes de nível inferior.  
  
 O tempo de execução de simultaneidade também oferece primitivos de sincronização que usam o bloqueio cooperativo para sincronizar o acesso aos recursos.  Para obter mais informações sobre esses primitivos de sincronização, consulte [Estruturas de dados de sincronização](../Topic/Synchronization%20Data%20Structures.md).  
  
 As seções a seguir fornecem uma visão geral de cada componente oferece e quando usá\-lo.  
  
### Biblioteca de Padrões Paralelos  
 Os padrões PPL \(biblioteca paralelo\) fornece contêineres de finalidade gerais e algoritmos para executar o paralelismo refinado.  Habilita a PPL *paralelismo de dados obrigatório* fornecendo algoritmos paralelos que distribuir computações em coleções ou em conjuntos de dados entre recursos de computação.  Ele também permite *paralelismo de tarefas* fornecendo objetos task que distribua várias operações independentes em recursos de computação.  
  
 Use a biblioteca de padrões paralelos quando você tem uma computação local que possa se beneficiar da execução paralela.  Por exemplo, você pode usar o [concurrency::parallel\_for](../Topic/parallel_for%20Function.md) algoritmo para transformar um existente `for` loop para atuar em paralelo.  
  
 Para obter mais informações sobre a biblioteca de padrões paralelos, consulte [Biblioteca de padrões paralelos \(PPL\)](../../parallel/concrt/parallel-patterns-library-ppl.md).  
  
### Biblioteca de Agentes Assíncronos  
 A biblioteca de agentes assíncronos \(ou apenas *biblioteca de agentes*\) fornece um modelo de programação baseado em ator e a mensagem passando interfaces para o fluxo de dados de alta granularidade e pipeline de tarefas.  Agentes assíncronos lhe permitam fazer uso produtivo de latência executando o trabalho enquanto esperam outros componentes de dados.  
  
 Use a biblioteca de agentes quando você tem várias entidades que se comunicar entre si de maneira assíncrona.  Por exemplo, você pode criar um agente que lê dados de uma arquivo ou conexão de rede e, em seguida, usa as interfaces de transmissão de mensagens para enviar esses dados para outro agente.  
  
 Para obter mais informações sobre a biblioteca de agentes, consulte [Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md).  
  
### Agendador de Tarefas  
 O Agendador de tarefas agenda e coordena as tarefas em tempo de execução.  O Agendador de tarefas é cooperativo e usa um algoritmo de roubo de trabalho para alcançar a utilização máxima de recursos de processamento.  
  
 O tempo de execução de simultaneidade fornece um agendador padrão para que você não precisa gerenciar detalhes da infra\-estrutura.  No entanto, para atender às necessidades de qualidade do seu aplicativo, você também pode fornecer seus próprio agendamento agendadores de específicos política ou associar tarefas específicas.  
  
 Para obter mais informações sobre o Agendador de tarefas, consulte [Agendador de Tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md).  
  
### Gerenciador de Recursos  
 É a função do Gerenciador de recursos gerenciar recursos de computação, como processadores e memória.  O Gerenciador de recursos responde às cargas de trabalho conforme mudam em tempo de execução por atribuição de recursos onde eles podem ser mais eficientes.  
  
 O Gerenciador de recursos serve como uma abstração sobre recursos de computação e principalmente interage com o Agendador de tarefas.  Embora você possa usar o Gerenciador de recursos para ajustar o desempenho dos seus aplicativos e bibliotecas, você geralmente usa a funcionalidade fornecida pelo Parallel Patterns Library, biblioteca de agentes e o Agendador de tarefas.  Essas bibliotecas de usam o Gerenciador de recursos para reequilibrar dinamicamente recursos como alterar as cargas de trabalho.  
  
 \[[Top](#top)\]  
  
##  <a name="lambda"></a> Expressões Lambda C\+\+  
 Muitos dos tipos e algoritmos que são definidos no tempo de execução de simultaneidade são implementados como modelos C\+\+.  Alguns desses tipos e algoritmos como dar um parâmetro de uma rotina que executa o trabalho.  Esse parâmetro pode ser uma função lambda, um objeto de função ou um ponteiro de função.  Essas entidades são também conhecidas como *funções de trabalho* ou *rotinas de trabalho*.  
  
 Expressões lambda são um recurso de linguagem do Visual C\+\+ novo importante porque elas fornecem uma maneira sucinta para definir funções de trabalho para processamento paralelo.  Objetos de função e ponteiros de função permitem usar o tempo de execução de simultaneidade com seu código existente.  No entanto, é recomendável usar expressões lambda ao escrever novo código devido os benefícios de segurança e produtividade que eles fornecem.  
  
 O exemplo a seguir compara a sintaxe de funções lambda, objetos de função e ponteiros de função em várias chamadas para o [Concurrency:: parallel\_for\_each](../Topic/parallel_for_each%20Function.md) algoritmo.  Cada chamada para `parallel_for_each` usa uma técnica diferente para calcular o quadrado de cada elemento em uma [std:: array](../../standard-library/array-class-stl.md) objeto.  
  
 [!code-cpp[concrt-comparing-work-functions#1](../../parallel/concrt/codesnippet/CPP/overview-of-the-concurrency-runtime_1.cpp)]  
  
 **Saída**  
  
  **1**  
**256**  
**6561**  
**65536**  
**390625** Para obter mais informações sobre as funções lambda em C\+\+, consulte [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md).  
  
 \[[Top](#top)\]  
  
##  <a name="requirements"></a> Requisitos  
 A tabela a seguir mostra os arquivos de cabeçalho que estão associados a cada componente do tempo de execução de simultaneidade:  
  
|Componente|Arquivos de Cabeçalho|  
|----------------|---------------------------|  
|Biblioteca de padrões paralelos \(PPL\)|PPL.h<br /><br /> concurrent\_queue.h<br /><br /> concurrent\_vector.h|  
|Biblioteca de Agentes Assíncronos|Agents.h|  
|Agendador de Tarefas|concrt.h|  
|Gerenciador de Recursos|concrtrm. h|  
  
 O tempo de execução de simultaneidade é declarado na [simultaneidade](../../parallel/concrt/reference/concurrency-namespace.md) namespace.  \(Você também pode usar [simultaneidade](../../parallel/concrt/reference/concurrency-namespace.md), que é um alias para esse namespace.\) O `concurrency::details` namespace suporta a estrutura de tempo de execução de simultaneidade e não se destina a ser usada diretamente no seu código.  
  
 O tempo de execução de simultaneidade é fornecido como parte da biblioteca de tempo de execução C \(CRT\).  Para obter mais informações sobre como criar um aplicativo que usa o CRT, consulte [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).  
  
 \[[Top](#top)\]