---
title: "Instru&#231;&#245;es passo a passo: criando um aplicativo com base no agente | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "agentes assíncronos, criando"
  - "classe de agente, por exemplo:"
ms.assetid: 730f42ce-6d58-4753-b948-fd9c9ef2ce6c
caps.latest.revision: 24
caps.handback.revision: 21
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: criando um aplicativo com base no agente
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico descreve como criar um aplicativo agente\-baseado básico.  Neste passo a passo, você pode criar um agente que lê dados de um arquivo de texto de forma assíncrona.  O aplicativo usa o algoritmo de soma de verificação Adler\-32 para calcular a soma de verificação do conteúdo desse arquivo.  
  
## Pré-requisitos  
 Você deve entender os tópicos a seguir para concluir este passo a passo:  
  
-   [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)  
  
-   [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)  
  
-   [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)  
  
-   [Estruturas de dados de sincronização](../Topic/Synchronization%20Data%20Structures.md)  
  
##  <a name="top"></a> Seções  
 Este passo a passo demonstra como executar as seguintes tarefas:  
  
-   [Criando o Aplicativo de Console](#createApplication)  
  
-   [Criando a Classe file\_reader](#createAgentClass)  
  
-   [Usando a Classe file\_reader no Aplicativo](#useAgentClass)  
  
##  <a name="createApplication"></a> Criando o Aplicativo de Console  
 Esta seção mostra como criar um aplicativo de console do Visual C\+\+ que faz referência aos arquivos de cabeçalho que o programa usará.  
  
#### Para criar um aplicativo Visual C\+\+ usando o Assistente do Aplicativo de Console Win32  
  
1.  No menu de **Arquivo** , clique em **Novo**, e clique em **Projeto** para exibir a caixa de diálogo de **Novo Projeto** .  
  
2.  Na caixa de diálogo de **Novo Projeto** , selecione o nó de **Visual C\+\+** no painel de **Tipos de projeto** e selecione **Aplicativo do Console Win32** no painel de **Modelos** .  Digite um nome para o projeto, por exemplo, `BasicAgent`, e clique em **OK** para exibir **Assistente do aplicativo de console do Win32**.  
  
3.  Na caixa de diálogo de **Assistente do aplicativo de console do Win32** , clique **Concluir**.  
  
4.  Em stdafx.h, adicione o seguinte código.  
  
     [!code-cpp[concrt-basic-agent#1](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-agent-based-application_1.h)]  
  
     O arquivo de cabeçalho agents.h contém a funcionalidade da classe de [concurrency::agent](../../parallel/concrt/reference/agent-class.md) .  
  
5.  Verifique se o aplicativo foi criado com êxito criando e executando o.  Para compilar o aplicativo, no menu **Compilar**, clique em **Compilar Solução**.  Se o aplicativo for compilado com êxito, execute\-o clicando em **Iniciar Depuração** no menu **Depurar**.  
  
 \[[Superior](#top)\]  
  
##  <a name="createAgentClass"></a> Criando a Classe file\_reader  
 Esta seção mostra como criar a classe de `file_reader` .  O tempo de execução agenda cada agente para executar o trabalho em seu próprio contexto.  Em virtude disso, você pode criar um o agent que execute o trabalho de forma síncrona, mas interage com outros componentes de forma assíncrona.  A classe de `file_reader` ler dados de um arquivo de entrada especificado e envia os dados desse arquivo a um determinado componente de destino.  
  
#### Para criar a classe file\_reader  
  
1.  Adicionar um novo arquivo de cabeçalho C\+\+ ao seu projeto.  Para fazer isso, clique com o botão direito do mouse no nó de **Arquivos de Cabeçalho** em **Gerenciador de Soluções**, clique **Adicionar**, e clique em **Novo Item**.  No painel de **Modelos** , **Cabeçalho Arquivo \(.h\)**selecione.  Na caixa de diálogo de **Adicionar novo item** , digite `file_reader.h` na caixa de **Nome** e clique em **Adicionar**.  
  
2.  Em file\_reader.h, adicione o seguinte código.  
  
     [!code-cpp[concrt-basic-agent#17](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-agent-based-application_2.h)]  
  
3.  Em file\_reader.h, crie uma classe chamada `file_reader` que deriva de `agent`.  
  
     [!code-cpp[concrt-basic-agent#2](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-agent-based-application_3.h)]  
  
4.  Adicione os seguintes membros de dados na seção de `private` da classe.  
  
     [!code-cpp[concrt-basic-agent#3](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-agent-based-application_4.h)]  
  
     O membro de `_file_name` é o nome de arquivo que o agente lê.  O membro de `_target` é um objeto de [concurrency::ITarget](../../parallel/concrt/reference/itarget-class.md) que o agent grava o conteúdo do arquivo como.  O membro de `_error` contém qualquer erro que ocorra durante a vida do agent.  
  
5.  Adicione o seguinte código para os construtores de `file_reader` a seção de `public` da classe de `file_reader` .  
  
     [!code-cpp[concrt-basic-agent#4](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-agent-based-application_5.h)]  
  
     Cada sobrecarga de construtor define os membros de dados de `file_reader` .  A segunda e a terceira sobrecarga de construtor permite que o seu aplicativo usar um agendador específico com seu agente.  A primeira sobrecarga usa o agendador padrão com o agente.  
  
6.  Adicionar o método de `get_error` a seção pública da classe de `file_reader` .  
  
     [!code-cpp[concrt-basic-agent#5](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-agent-based-application_6.h)]  
  
     O método de `get_error` recupera qualquer erro que ocorra durante a vida do agent.  
  
7.  Implementar o método de [concurrency::agent::run](../Topic/agent::run%20Method.md) na seção de `protected` da classe.  
  
     [!code-cpp[concrt-basic-agent#6](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-agent-based-application_7.h)]  
  
     O método de `run` abre o arquivo e ler dados deles.  O método de `run` usa a manipulação de exceção para capturar todos os erros que ocorrem durante o processamento de arquivo.  
  
     Cada vez que esse método lê dados do arquivo, chamará a função de [concurrency::asend](../Topic/asend%20Function.md) para enviar os dados ao buffer de destino.  Envia a cadeia de caracteres vazia ao buffer de destino para indicar o final do processamento.  
  
 O exemplo a seguir mostra o conteúdo completo de file\_reader.h.  
  
 [!code-cpp[concrt-basic-agent#7](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-agent-based-application_8.h)]  
  
 \[[Superior](#top)\]  
  
##  <a name="useAgentClass"></a> Usando a Classe file\_reader no Aplicativo  
 Esta seção mostra como usar a classe de `file_reader` para ler o conteúdo de um arquivo de texto.  Também mostra como criar um objeto de [concurrency::call](../../parallel/concrt/reference/call-class.md) que recebe os dados de arquivo e calcula a soma de verificação Adler\-32.  
  
#### Para usar a classe file\_reader no aplicativo  
  
1.  Em BasicAgent.cpp, adicione a seguinte instrução de `#include` .  
  
     [!code-cpp[concrt-basic-agent#8](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-agent-based-application_9.cpp)]  
  
2.  Em BasicAgent.cpp, adicione as políticas de `using` .  
  
     [!code-cpp[concrt-basic-agent#9](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-agent-based-application_10.cpp)]  
  
3.  Na função de `_tmain` , crie um objeto de [concurrency::event](../Topic/event%20Class.md) que sinalize o final do processamento.  
  
     [!code-cpp[concrt-basic-agent#10](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-agent-based-application_11.cpp)]  
  
4.  Crie um objeto de `call` que atualiza a soma de verificação quando o recebe dados.  
  
     [!code-cpp[concrt-basic-agent#11](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-agent-based-application_12.cpp)]  
  
     Esse objeto de `call` também define o objeto de `event` quando o recebe a cadeia de caracteres vazia para sinalizar o final do processamento.  
  
5.  Crie um objeto de `file_reader` que a leitura do arquivo test.txt e grava o conteúdo desse arquivo ao objeto de `call` .  
  
     [!code-cpp[concrt-basic-agent#12](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-agent-based-application_13.cpp)]  
  
6.  Inicie o agente e espere\-o para concluir.  
  
     [!code-cpp[concrt-basic-agent#13](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-agent-based-application_14.cpp)]  
  
7.  Aguarde o objeto de `call` para receber todos os dados e para concluir\-los.  
  
     [!code-cpp[concrt-basic-agent#14](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-agent-based-application_15.cpp)]  
  
8.  Verifique o leitor do arquivo para erros.  Se nenhum erro ocorreu, calcula a soma Adler\-32 final e imprima a soma no console.  
  
     [!code-cpp[concrt-basic-agent#15](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-agent-based-application_16.cpp)]  
  
 O exemplo a seguir mostra o arquivo completo de BasicAgent.cpp.  
  
 [!code-cpp[concrt-basic-agent#16](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-agent-based-application_17.cpp)]  
  
 \[[Superior](#top)\]  
  
## Entrada de Exemplo  
 Este é o conteúdo de exemplo do arquivo de entrada: text.txt  
  
  **A raposa rápido marrom**  
**saltos**  
**sobre o dog lento**   
## Saída de Exemplo  
 Quando usado com a entrada de exemplo, esse programa gerencia a seguinte saída:  
  
  **A soma Adler\-32 é fefb0d75**   
## Programação robusta  
 Para evitar membros simultâneas de acesso aos dados, é recomendável adicionar os métodos que executa o trabalho na seção de `protected` ou de `private` da classe.  Acrescentar apenas os métodos que envia ou recebe mensagens do ou do agent a seção de `public` da classe.  
  
 Sempre chamar o método de [concurrency::agent::done](../Topic/agent::done%20Method.md) para mover seu agente ao estado concluído.  Você normalmente chama esse método antes que você retorne do método de `run` .  
  
## Próximas etapas  
 Para outro exemplo de um aplicativo, consulte agente\- baseado [Instruções passo a passo: usando join para Evitar Deadlock](../../parallel/concrt/walkthrough-using-join-to-prevent-deadlock.md).  
  
## Consulte também  
 [Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md)   
 [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)   
 [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)   
 [Estruturas de dados de sincronização](../Topic/Synchronization%20Data%20Structures.md)   
 [Instruções passo a passo: usando join para Evitar Deadlock](../../parallel/concrt/walkthrough-using-join-to-prevent-deadlock.md)