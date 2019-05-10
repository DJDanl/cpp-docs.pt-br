---
title: 'Passo a passo: Criando um aplicativo baseado em agente'
ms.date: 04/25/2019
helpviewer_keywords:
- asynchronous agents, creating
- agent class, example
ms.assetid: 730f42ce-6d58-4753-b948-fd9c9ef2ce6c
ms.openlocfilehash: c249bc8138a3617cce3eae836751575b2626f4aa
ms.sourcegitcommit: 283cb64fd7958a6b7fbf0cd8534de99ac8d408eb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2019
ms.locfileid: "64857307"
---
# <a name="walkthrough-creating-an-agent-based-application"></a>Passo a passo: Criando um aplicativo baseado em agente

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

Esta seção mostra como criar um C++ aplicativo que faz referência os arquivos de cabeçalho que usará o programa de console. As etapas iniciais variam, dependendo de qual versão do Visual Studio que você está usando. Verifique se o seletor de versão está definido corretamente na parte superior esquerda desta página.

::: moniker range="vs-2019"

### <a name="to-create-a-c-console-application-in-visual-studio-2019"></a>Para criar um C++ console de aplicativo no Visual Studio de 2019

1. No menu principal, escolha **arquivo** > **New** > **projeto** para abrir o **criar um novo projeto** caixa de diálogo caixa.

1. Na parte superior da caixa de diálogo, defina **linguagem** à **C++**, defina **plataforma** para **Windows**e defina **tipodeprojeto** ao **Console**. 

1. Na lista filtrada de tipos de projeto, escolha **aplicativo de Console** , em seguida, escolha **próxima**. Na próxima página, insira `BasicAgent` como o nome do projeto e especifique o local do projeto, se desejado.

1. Escolha o **criar** botão para criar o projeto.

1. Clique com botão direito no nó do projeto no **Gerenciador de soluções**e escolha **propriedades**. Sob **propriedades de configuração** > **C /C++** > **cabeçalhos pré-compilados** > **pré-compilado cabeçalho** escolher **criar**.

::: moniker-end

::: moniker range="<=vs-2017"

### <a name="to-create-a-c-console-application-in-visual-studio-2017-and-earlier"></a>Para criar um C++ no Visual Studio 2017 e versões anteriores de aplicativo de console

1. Sobre o **arquivo** menu, clique em **New**e, em seguida, clique em **projeto** para exibir o **novo projeto** caixa de diálogo.

1. No **novo projeto** caixa de diálogo, selecione o **Visual C++** nó no **tipos de projeto** painel e, em seguida, selecione **aplicativo do Console Win32** no **modelos** painel. Digite um nome para o projeto, por exemplo, `BasicAgent`e, em seguida, clique em **Okey** para exibir o **Assistente de aplicativo de Console Win32**.

1. No **Assistente de aplicativo de Console Win32** caixa de diálogo, clique em **concluir**.

::: moniker-end

1. Em Stdafx. h (ou pch. h, dependendo da sua versão do Visual Studio), adicione o código a seguir.

[!code-cpp[concrt-basic-agent#1](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_1.h)]

   O arquivo de cabeçalho Agents. h contém a funcionalidade do [concurrency::agent](../../parallel/concrt/reference/agent-class.md) classe.

1. Verifique se que o aplicativo foi criado com êxito pela criação e executá-lo. Para compilar o aplicativo, na **construir** menu, clique em **compilar solução**. Se o aplicativo for compilado com êxito, execute o aplicativo clicando **iniciar depuração** sobre o **depurar** menu.

[[Top](#top)]

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

   O `_file_name` membro é o nome do arquivo que o agente lê. O `_target` membro é um [Concurrency:: ITarget](../../parallel/concrt/reference/itarget-class.md) do objeto que o agente grava o conteúdo do arquivo para. O `_error` membro contém qualquer erro que ocorre durante o ciclo de vida do agente.

1. Adicione o seguinte código para o `file_reader` construtores para o `public` seção o `file_reader` classe.

[!code-cpp[concrt-basic-agent#4](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_5.h)]

   Cada sobrecarga do construtor define o `file_reader` membros de dados. A sobrecarga de segundo e o terceiro construtor permite que seu aplicativo para usar um agendador específico com o agente. A primeira sobrecarga usa o agendador padrão com o agente.

1. Adicione a `get_error` método para a seção pública do `file_reader` classe.

[!code-cpp[concrt-basic-agent#5](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_6.h)]

   O `get_error` método recupera qualquer erro que ocorre durante o ciclo de vida do agente.

1. Implementar o [concurrency::agent::run](reference/agent-class.md#run) método o `protected` seção da sua classe.

[!code-cpp[concrt-basic-agent#6](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_7.h)]

O `run` método abre o arquivo e lê os dados dela. O `run` método usa o tratamento de exceções para capturar erros que ocorrem durante o processamento do arquivo.

   Cada vez que esse método lê dados do arquivo, ele chama o [Concurrency:: asend](reference/concurrency-namespace-functions.md#asend) função para enviar esses dados para o buffer de destino. Ele envia a cadeia de caracteres vazia para seu buffer de destino para indicar o fim do processamento.

O exemplo a seguir mostra todo o conteúdo do file_reader.h.

[!code-cpp[concrt-basic-agent#7](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_8.h)]

[[Top](#top)]

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

   Isso `call` objeto também define o `event` quando ele recebe a cadeia de caracteres vazia para sinalizar o final do processamento do objeto.

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

[[Top](#top)]

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

Para obter outro exemplo de um aplicativo baseado em agente, consulte [passo a passo: Usando join para evitar Deadlock](../../parallel/concrt/walkthrough-using-join-to-prevent-deadlock.md).

## <a name="see-also"></a>Consulte também

[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)<br/>
[Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md)<br/>
[Passo a passo: Usando join para evitar deadlock](../../parallel/concrt/walkthrough-using-join-to-prevent-deadlock.md)
