---
title: 'Passo a passo: Criando um aplicativo com base em agente | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- asynchronous agents, creating
- agent class, example
ms.assetid: 730f42ce-6d58-4753-b948-fd9c9ef2ce6c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 78826bb9f00e77a80fb65dd3a3ceda7eedb38796
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33692620"
---
# <a name="walkthrough-creating-an-agent-based-application"></a>Instruções passo a passo: criando um aplicativo com base no agente
Este tópico descreve como criar um aplicativo básico com base em agente. Neste passo a passo, você pode criar um agente que lê dados de um arquivo de texto de forma assíncrona. O aplicativo usa o algoritmo de soma de verificação Adler-32 para calcular a soma de verificação do conteúdo do arquivo.  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Você deve entender os tópicos a seguir para concluir este passo a passo:  
  
- [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)  
  
- [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)  
  
- [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)  
  
- [Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md)  
  
##  <a name="top"></a> Seções  
 Este passo a passo demonstra como executar as seguintes tarefas:  
  
- [Criar o Aplicativo de Console](#createapplication)  
  
- [Criando a classe file_reader](#createagentclass)  
  
- [Usando a classe file_reader no aplicativo](#useagentclass)  
  
##  <a name="createapplication"></a> Criando o aplicativo de Console  
 Esta seção mostra como criar um aplicativo de console do Visual C++ que referencia os arquivos de cabeçalho que usará o programa.  
  
#### <a name="to-create-a-visual-c-application-by-using-the-win32-console-application-wizard"></a>Para criar um aplicativo Visual C++ usando o Assistente do Aplicativo de Console Win32  
  
1.  Sobre o **arquivo** menu, clique em **novo**e, em seguida, clique em **projeto** para exibir o **novo projeto** caixa de diálogo.  
  
2.  No **novo projeto** caixa de diálogo, selecione o **Visual C++** nó o **tipos de projeto** painel e, em seguida, selecione **aplicativo do Console Win32** no **modelos** painel. Digite um nome para o projeto, por exemplo, `BasicAgent`e, em seguida, clique em **Okey** para exibir o **Assistente de aplicativo do Console Win32**.  
  
3.  No **Assistente de aplicativo do Console Win32** caixa de diálogo, clique em **concluir**.  
  
4.  Em Stdafx. h, adicione o código a seguir.  
  
 [!code-cpp[concrt-basic-agent#1](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_1.h)]  
  
     O agents.h do arquivo de cabeçalho contém a funcionalidade do [concurrency::agent](../../parallel/concrt/reference/agent-class.md) classe.  
  
5.  Verifique se que o aplicativo foi criado com êxito ao criar e executá-lo. Para criar o aplicativo, no **criar** menu, clique em **compilar solução**. Se o aplicativo foi criado com êxito, execute o aplicativo clicando **iniciar depuração** no **depurar** menu.  
  
 [[Superior](#top)]  
  
##  <a name="createagentclass"></a> Criando a classe file_reader  
 Esta seção mostra como criar o `file_reader` classe. O tempo de execução agenda para executar o trabalho em seu próprio contexto de cada agente. Portanto, você pode criar um agente que executa o trabalho de forma síncrona, mas interage com outros componentes de forma assíncrona. O `file_reader` classe lê dados de um determinado arquivo de entrada e envia dados de arquivo para um componente de destino fornecido.  
  
#### <a name="to-create-the-filereader-class"></a>Para criar a classe file_reader  
  
1.  Adicione um novo arquivo de cabeçalho do C++ a seu projeto. Para fazer isso, clique com botão direito do **arquivos de cabeçalho** nó **Gerenciador de soluções**, clique em **adicionar**e, em seguida, clique em **Novo Item**. No **modelos** painel, selecione **o arquivo de cabeçalho (. h)**. No **Adicionar Novo Item** caixa de diálogo, digite `file_reader.h` no **nome** caixa e, em seguida, clique em **adicionar**.  
  
2.  No file_reader.h, adicione o código a seguir.  
  
 [!code-cpp[concrt-basic-agent#17](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_2.h)]  
  
3.  No file_reader.h, crie uma classe denominada `file_reader` que deriva de `agent`.  
  
 [!code-cpp[concrt-basic-agent#2](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_3.h)]  
  
4.  Adicionar os seguintes membros de dados para o `private` seção da sua classe.  
  
 [!code-cpp[concrt-basic-agent#3](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_4.h)]  
  
     O `_file_name` membro é o nome do arquivo que o agente lê. O `_target` membro é um [concurrency::ITarget](../../parallel/concrt/reference/itarget-class.md) que o agente grava o conteúdo do arquivo de objeto. O `_error` membro contém qualquer erro que ocorre durante a vida útil do agente.  
  
5.  Adicione o seguinte código para o `file_reader` construtores para o `public` seção o `file_reader` classe.  
  
 [!code-cpp[concrt-basic-agent#4](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_5.h)]  
  
     Cada sobrecarga de construtor define o `file_reader` membros de dados. A sobrecarga de construtor segundo e terceiro permite que seu aplicativo para usar um agendador específico com o agente. A primeira sobrecarga usa o agendador padrão com o agente.  
  
6.  Adicionar o `get_error` método para a seção pública a `file_reader` classe.  
  
 [!code-cpp[concrt-basic-agent#5](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_6.h)]  
  
     O `get_error` método recupera qualquer erro que ocorre durante a vida útil do agente.  
  

7.  Implementar o [concurrency::agent::run](reference/agent-class.md#run) método o `protected` seção da sua classe.  

  
 [!code-cpp[concrt-basic-agent#6](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_7.h)]  
  
O `run` método abre o arquivo e lê dados dela. O `run` método usa o tratamento de exceções para capturar erros que ocorrem durante o processamento do arquivo.  
  
   Cada vez que esse método lê os dados do arquivo, ele chama o [concurrency::asend](reference/concurrency-namespace-functions.md#asend) função para enviar dados para o buffer de destino. Envia a cadeia de caracteres vazia para o buffer de destino para indicar o final do processamento.  

  
 O exemplo a seguir mostra o conteúdo completo do file_reader.h.  
  
 [!code-cpp[concrt-basic-agent#7](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_8.h)]  
  
 [[Superior](#top)]  
  
##  <a name="useagentclass"></a> Usando a classe file_reader no aplicativo  
 Esta seção mostra como usar o `file_reader` classe para ler o conteúdo de um arquivo de texto. Ele também mostra como criar um [concurrency::call](../../parallel/concrt/reference/call-class.md) objeto que recebe esses dados de arquivo e calcula a soma de verificação seu Adler-32.  
  
#### <a name="to-use-the-filereader-class-in-your-application"></a>Para usar a classe file_reader no aplicativo  
  
1.  Em BasicAgent.cpp, adicione o seguinte `#include` instrução.  
  
 [!code-cpp[concrt-basic-agent#8](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_9.cpp)]  
  
2.  Em BasicAgent.cpp, adicione o seguinte `using` diretivas.  
  
 [!code-cpp[concrt-basic-agent#9](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_10.cpp)]  
  
3.  No `_tmain` funcionar, crie um [concurrency::event](../../parallel/concrt/reference/event-class.md) objeto que sinaliza o término do processamento.  
  
 [!code-cpp[concrt-basic-agent#10](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_11.cpp)]  
  
4.  Criar um `call` que atualiza a soma de verificação quando ele recebe dados de objeto.  
  
 [!code-cpp[concrt-basic-agent#11](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_12.cpp)]  
  
     Isso `call` objeto também define o `event` quando ele recebe a cadeia de caracteres vazia para sinalizar o final do processamento do objeto.  
  
5.  Criar um `file_reader` objeto que lê a partir do arquivo Test. txt e grava o conteúdo desse arquivo para o `call` objeto.  
  
 [!code-cpp[concrt-basic-agent#12](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_13.cpp)]  
  
6.  Iniciar o agente e Aguarde sua conclusão.  
  
 [!code-cpp[concrt-basic-agent#13](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_14.cpp)]  
  
7.  Aguarde até que o `call` objeto para receber todos os dados e concluir.  
  
 [!code-cpp[concrt-basic-agent#14](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_15.cpp)]  
  
8.  Verifique se o leitor de arquivo de erros. Se nenhum erro ocorreu, calcular a soma de Adler-32 final e a soma para o console de impressão.  
  
 [!code-cpp[concrt-basic-agent#15](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_16.cpp)]  
  
 O exemplo a seguir mostra o arquivo BasicAgent.cpp completo.  
  
 [!code-cpp[concrt-basic-agent#16](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_17.cpp)]  
  
 [[Superior](#top)]  
  
## <a name="sample-input"></a>Entrada de Exemplo  
 Este é o conteúdo de exemplo de Test.txt o arquivo de entrada:  
  
```Output  
The quick brown fox  
jumps  
over the lazy dog  
```  
  
## <a name="sample-output"></a>Saída de Exemplo  
 Quando usado com a entrada de exemplo, este programa produz a saída a seguir:  
  
```Output  
Adler-32 sum is fefb0d75  
```  
  
## <a name="robust-programming"></a>Programação robusta  
 Para evitar o acesso simultâneo aos membros de dados, recomendamos que você adicione métodos que executam o trabalho para o `protected` ou `private` seção da sua classe. Adicionar apenas os métodos que enviar ou recebem mensagens de ou para o agente de `public` seção da sua classe.  
  

 Sempre chamar o [concurrency::agent:: feito](reference/agent-class.md#done) método para mover o agente para o estado concluído. Normalmente você chama esse método antes de retornar do `run` método.  

  
## <a name="next-steps"></a>Próximas etapas  
 Outro exemplo de um aplicativo com base em agente, consulte [passo a passo: usando join para evitar Deadlock](../../parallel/concrt/walkthrough-using-join-to-prevent-deadlock.md).  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)   
 [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)   
 [Funções de transmissão de mensagens](../../parallel/concrt/message-passing-functions.md)   
 [Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md)   
 [Instruções passo a passo: usando unir para evitar deadlock](../../parallel/concrt/walkthrough-using-join-to-prevent-deadlock.md)

