---
title: 'Passo a passo: Criando um aplicativo baseado em agente | Microsoft Docs'
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
ms.openlocfilehash: 68c4b389bdd8f1121a59bce1a0ca8942f077e062
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46377144"
---
# <a name="walkthrough-creating-an-agent-based-application"></a>Instruções passo a passo: criando um aplicativo com base no agente

Este tópico descreve como criar um aplicativo básico com base em agente. Neste passo a passo, você pode criar um agente que lê dados de um arquivo de texto de forma assíncrona. O aplicativo usa o algoritmo de soma de verificação Adler-32 para calcular a soma de verificação do conteúdo do arquivo.

## <a name="prerequisites"></a>Pré-requisitos

Você deve compreender os tópicos a seguir para concluir este passo a passo:

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

Esta seção mostra como criar um aplicativo de console do Visual C++ que faz referência os arquivos de cabeçalho que usará o programa.

#### <a name="to-create-a-visual-c-application-by-using-the-win32-console-application-wizard"></a>Para criar um aplicativo Visual C++ usando o Assistente do Aplicativo de Console Win32

1. Sobre o **arquivo** menu, clique em **New**e, em seguida, clique em **projeto** para exibir o **novo projeto** caixa de diálogo.

1. No **novo projeto** caixa de diálogo, selecione o **Visual C++** nó no **tipos de projeto** painel e, em seguida, selecione **aplicativo do Console Win32** no **modelos** painel. Digite um nome para o projeto, por exemplo, `BasicAgent`e, em seguida, clique em **Okey** para exibir o **Assistente de aplicativo de Console Win32**.

1. No **Assistente de aplicativo de Console Win32** caixa de diálogo, clique em **concluir**.

1. Em Stdafx. h, adicione o código a seguir.

[!code-cpp[concrt-basic-agent#1](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_1.h)]

     The header file agents.h contains the functionality of the [concurrency::agent](../../parallel/concrt/reference/agent-class.md) class.

1. Verifique se que o aplicativo foi criado com êxito pela criação e executá-lo. Para compilar o aplicativo, na **construir** menu, clique em **compilar solução**. Se o aplicativo for compilado com êxito, execute o aplicativo clicando **iniciar depuração** sobre o **depurar** menu.

[[Superior](#top)]

##  <a name="createagentclass"></a> Criando a classe file_reader

Esta seção mostra como criar o `file_reader` classe. O tempo de execução agenda cada agente para realizar o trabalho em seu próprio contexto. Portanto, você pode criar um agente que executa o trabalho de forma síncrona, mas que interage com outros componentes de forma assíncrona. O `file_reader` classe lê dados de um determinado arquivo de entrada e envia dados de arquivo para um componente de destino especificado.

#### <a name="to-create-the-filereader-class"></a>Para criar a classe file_reader

1. Adicione um novo arquivo de cabeçalho do C++ ao seu projeto. Para fazer isso, clique com botão direito do **arquivos de cabeçalho** nó no **Gerenciador de soluções**, clique em **Add**e, em seguida, clique em **Novo Item**. No **modelos** painel, selecione **arquivo de cabeçalho (. h)**. No **Adicionar Novo Item** caixa de diálogo, digite `file_reader.h` no **nome** caixa e, em seguida, clique em **Add**.

1. No file_reader.h, adicione o código a seguir.

[!code-cpp[concrt-basic-agent#17](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_2.h)]

1. Em file_reader.h, crie uma classe denominada `file_reader` que deriva de `agent`.

[!code-cpp[concrt-basic-agent#2](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_3.h)]

1. Adicione os seguintes membros de dados para o `private` seção da sua classe.

[!code-cpp[concrt-basic-agent#3](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_4.h)]

     The `_file_name` member is the file name that the agent reads from. The `_target` member is a [concurrency::ITarget](../../parallel/concrt/reference/itarget-class.md) object that the agent writes the contents of the file to. The `_error` member holds any error that occurs during the life of the agent.

1. Adicione o seguinte código para o `file_reader` construtores para o `public` seção o `file_reader` classe.

[!code-cpp[concrt-basic-agent#4](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_5.h)]

     Each constructor overload sets the `file_reader` data members. The second and third constructor overload enables your application to use a specific scheduler with your agent. The first overload uses the default scheduler with your agent.

1. Adicione a `get_error` método para a seção pública do `file_reader` classe.

[!code-cpp[concrt-basic-agent#5](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_6.h)]

     The `get_error` method retrieves any error that occurs during the life of the agent.

1. Implementar o [concurrency::agent::run](reference/agent-class.md#run) método o `protected` seção da sua classe.

[!code-cpp[concrt-basic-agent#6](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_7.h)]

O `run` método abre o arquivo e lê os dados dela. O `run` método usa o tratamento de exceções para capturar erros que ocorrem durante o processamento do arquivo.

   Cada vez que esse método lê dados do arquivo, ele chama o [Concurrency:: asend](reference/concurrency-namespace-functions.md#asend) função para enviar esses dados para o buffer de destino. Ele envia a cadeia de caracteres vazia para seu buffer de destino para indicar o fim do processamento.

O exemplo a seguir mostra todo o conteúdo do file_reader.h.

[!code-cpp[concrt-basic-agent#7](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_8.h)]

[[Superior](#top)]

##  <a name="useagentclass"></a> Usando a classe file_reader no aplicativo

Esta seção mostra como usar o `file_reader` classe para ler o conteúdo de um arquivo de texto. Ele também mostra como criar uma [concurrency::call](../../parallel/concrt/reference/call-class.md) objeto que recebe esses dados de arquivo e calcula sua soma de verificação Adler-32.

#### <a name="to-use-the-filereader-class-in-your-application"></a>Para usar a classe file_reader no aplicativo

1. No BasicAgent.cpp, adicione o seguinte `#include` instrução.

[!code-cpp[concrt-basic-agent#8](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_9.cpp)]

1. No BasicAgent.cpp, adicione o seguinte `using` diretivas.

[!code-cpp[concrt-basic-agent#9](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_10.cpp)]

1. No `_tmain` funcionar, crie um [concurrency::event](../../parallel/concrt/reference/event-class.md) objeto que sinaliza o término do processamento.

[!code-cpp[concrt-basic-agent#10](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_11.cpp)]

1. Criar um `call` que atualiza a soma de verificação quando ele recebe dados de objeto.

[!code-cpp[concrt-basic-agent#11](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_12.cpp)]

     This `call` object also sets the `event` object when it receives the empty string to signal the end of processing.

1. Criar uma `file_reader` objeto que lê o arquivo Test. txt e grava o conteúdo desse arquivo para o `call` objeto.

[!code-cpp[concrt-basic-agent#12](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_13.cpp)]

1. Iniciar o agente e aguardar sua conclusão.

[!code-cpp[concrt-basic-agent#13](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_14.cpp)]

1. Aguarde até que o `call` objeto para receber todos os dados e de término.

[!code-cpp[concrt-basic-agent#14](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_15.cpp)]

1. Verifique se o leitor de arquivo para erros. Se nenhum erro tiver ocorrido, calcular a soma de 32 Adler final e imprimir a soma no console.

[!code-cpp[concrt-basic-agent#15](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_16.cpp)]

O exemplo a seguir mostra o arquivo BasicAgent.cpp completo.

[!code-cpp[concrt-basic-agent#16](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_17.cpp)]

[[Superior](#top)]

## <a name="sample-input"></a>Entrada de Exemplo

Este é o conteúdo de exemplo de txt o arquivo de entrada:

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

Para evitar o acesso simultâneo aos membros de dados, é recomendável que você adicione métodos que realizam o trabalho para o `protected` ou `private` seção da sua classe. Apenas adicione métodos que enviam ou recebem mensagens de ou para o agente para o `public` seção da sua classe.

Sempre chamar o [concurrency::agent:: feito](reference/agent-class.md#done) método para mover seu agente para o estado concluído. Normalmente você chama esse método antes de retornar do `run` método.

## <a name="next-steps"></a>Próximas etapas

Para obter outro exemplo de um aplicativo baseado em agente, consulte [instruções passo a passo: usando join para evitar Deadlock](../../parallel/concrt/walkthrough-using-join-to-prevent-deadlock.md).

## <a name="see-also"></a>Consulte também

[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)<br/>
[Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md)<br/>
[Instruções passo a passo: usando unir para evitar deadlock](../../parallel/concrt/walkthrough-using-join-to-prevent-deadlock.md)

