---
title: 'Instruções passo a passo: criando um aplicativo com base no agente'
ms.date: 04/25/2019
helpviewer_keywords:
- asynchronous agents, creating
- agent class, example
ms.assetid: 730f42ce-6d58-4753-b948-fd9c9ef2ce6c
ms.openlocfilehash: 3ece04811a75fba22db447875dc6ed08c22987b5
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142052"
---
# <a name="walkthrough-creating-an-agent-based-application"></a>Instruções passo a passo: criando um aplicativo com base no agente

Este tópico descreve como criar um aplicativo básico baseado em agente. Neste tutorial, você pode criar um agente que lê dados de um arquivo de texto de forma assíncrona. O aplicativo usa o algoritmo de soma de verificação Adler-32 para calcular a soma de verificação do conteúdo desse arquivo.

## <a name="prerequisites"></a>{1&gt;{2&gt;Pré-requisitos&lt;2}&lt;1}

Você deve entender os seguintes tópicos para concluir este passo a passos:

- [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)

- [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)

- [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)

- [Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md)

## <a name="top"></a>As

Este tutorial demonstra como executar as seguintes tarefas:

- [Criar o Aplicativo de Console](#createapplication)

- [Criando a classe file_reader](#createagentclass)

- [Usando a classe file_reader no aplicativo](#useagentclass)

## <a name="createapplication"></a>Criando o aplicativo de console

Esta seção mostra como criar um C++ aplicativo de console que faz referência aos arquivos de cabeçalho que o programa usará. As etapas iniciais variam de acordo com a versão do Visual Studio que você está usando. Verifique se o seletor de versão está definido corretamente no canto superior esquerdo desta página.

::: moniker range="vs-2019"

### <a name="to-create-a-c-console-application-in-visual-studio-2019"></a>Para criar um C++ aplicativo de console no Visual Studio 2019

1. No menu principal, escolha **arquivo** > **novo** **projeto** de > para abrir a caixa de diálogo **criar um novo projeto** .

1. Na parte superior da caixa de diálogo, defina **Linguagem** como **C++** , **Plataforma** como **Windows** e **Tipo de projeto** como **Console**. 

1. Na lista filtrada de tipos de projeto, escolha **Aplicativo de Console** e, em seguida, escolha **Avançar**. Na próxima página, digite `BasicAgent` como o nome do projeto e especifique o local do projeto, se desejado.

1. Escolha o botão **Criar** para criar o projeto.

1. Clique com o botão direito do mouse no nó do projeto em **Gerenciador de soluções**e escolha **Propriedades**. Em **Propriedades de configuração** > **cabeçalhos pré-compilados** **C++ C/**  >  > **cabeçalho pré-compilado** , escolha **criar**.

::: moniker-end

::: moniker range="<=vs-2017"

### <a name="to-create-a-c-console-application-in-visual-studio-2017-and-earlier"></a>Para criar um C++ aplicativo de console no Visual Studio 2017 e anterior

1. No menu **arquivo** , clique em **novo**e, em seguida, clique em **projeto** para exibir a caixa de diálogo **novo projeto** .

1. Na caixa de diálogo **novo projeto** , selecione o **nó C++ Visual** no painel **tipos de projeto** e, em seguida, selecione **aplicativo de console Win32** no painel **modelos** . Digite um nome para o projeto, por exemplo, `BasicAgent`e clique em **OK** para exibir o **Assistente do aplicativo de console do Win32**.

1. Na caixa de diálogo **Assistente de aplicativo do console do Win32** , clique em **concluir**.

::: moniker-end

1. Em *PCH. h* (*stdafx. h* no Visual Studio 2017 e anterior), adicione o seguinte código:

[!code-cpp[concrt-basic-agent#1](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_1.h)]

   O arquivo de cabeçalho Agents. h contém a funcionalidade da classe [Concurrency:: Agent](../../parallel/concrt/reference/agent-class.md) .

1. Verifique se o aplicativo foi criado com êxito criando-o e executando-o. Para criar o aplicativo, no menu **Compilar** , clique em **Compilar solução**. Se o aplicativo for compilado com êxito, execute o aplicativo clicando em **Iniciar Depuração** no menu **depurar** .

[[Superior](#top)]

## <a name="createagentclass"></a>Criando a classe file_reader

Esta seção mostra como criar a classe `file_reader`. O tempo de execução agenda cada agente para executar o trabalho em seu próprio contexto. Portanto, você pode criar um agente que executa o trabalho de forma síncrona, mas interage com outros componentes de maneira assíncrona. A classe `file_reader` lê dados de um determinado arquivo de entrada e envia dados desse arquivo para um determinado componente de destino.

#### <a name="to-create-the-file_reader-class"></a>Para criar a classe file_reader

1. Adicione um novo C++ arquivo de cabeçalho ao seu projeto. Para fazer isso, clique com o botão direito do mouse no nó **arquivos de cabeçalho** em **Gerenciador de soluções**, clique em **Adicionar**e, em seguida, clique em **novo item**. No painel **modelos** , selecione **arquivo de cabeçalho (. h)** . Na caixa de diálogo **Adicionar novo item** , digite `file_reader.h` na caixa **nome** e clique em **Adicionar**.

1. Em file_reader. h, adicione o código a seguir.

[!code-cpp[concrt-basic-agent#17](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_2.h)]

1. Em file_reader. h, crie uma classe chamada `file_reader` derivada de `agent`.

[!code-cpp[concrt-basic-agent#2](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_3.h)]

1. Adicione os seguintes membros de dados à seção `private` da sua classe.

[!code-cpp[concrt-basic-agent#3](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_4.h)]

   O membro de `_file_name` é o nome de arquivo do qual o agente lê. O membro `_target` é um objeto [Concurrency:: ITarget](../../parallel/concrt/reference/itarget-class.md) para o qual o agente grava o conteúdo do arquivo. O membro `_error` mantém qualquer erro que ocorra durante a vida útil do agente.

1. Adicione o código a seguir para os construtores de `file_reader` à seção `public` da classe `file_reader`.

[!code-cpp[concrt-basic-agent#4](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_5.h)]

   Cada sobrecarga de construtor define a `file_reader` membros de dados. A segunda e a terceira sobrecarga de Construtor permitem que seu aplicativo use um Agendador específico com seu agente. A primeira sobrecarga usa o agendador padrão com seu agente.

1. Adicione o método `get_error` à seção pública da classe `file_reader`.

[!code-cpp[concrt-basic-agent#5](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_6.h)]

   O método `get_error` recupera qualquer erro que ocorra durante a vida útil do agente.

1. Implemente o método [Concurrency:: Agent:: execute](reference/agent-class.md#run) na seção `protected` da sua classe.

[!code-cpp[concrt-basic-agent#6](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_7.h)]

O método `run` abre o arquivo e lê os dados dele. O método `run` usa o tratamento de exceções para capturar quaisquer erros que ocorram durante o processamento de arquivos.

   Cada vez que esse método lê dados do arquivo, ele chama a função [Concurrency:: asend](reference/concurrency-namespace-functions.md#asend) para enviar esses dados para o buffer de destino. Ele envia a cadeia de caracteres vazia para seu buffer de destino para indicar o fim do processamento.

O exemplo a seguir mostra o conteúdo completo de file_reader. h.

[!code-cpp[concrt-basic-agent#7](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_8.h)]

[[Superior](#top)]

## <a name="useagentclass"></a>Usando a classe file_reader no aplicativo

Esta seção mostra como usar a classe `file_reader` para ler o conteúdo de um arquivo de texto. Ele também mostra como criar um objeto [Concurrency:: Call](../../parallel/concrt/reference/call-class.md) que recebe esses dados de arquivo e calcula sua soma de verificação de Adler-32.

#### <a name="to-use-the-file_reader-class-in-your-application"></a>Para usar a classe file_reader no aplicativo

1. Em BasicAgent. cpp, adicione a instrução de `#include` a seguir.

[!code-cpp[concrt-basic-agent#8](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_9.cpp)]

1. Em BasicAgent. cpp, adicione as seguintes diretivas de `using`.

[!code-cpp[concrt-basic-agent#9](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_10.cpp)]

1. Na função `_tmain`, crie um objeto [Concurrency:: Event](../../parallel/concrt/reference/event-class.md) que sinaliza o fim do processamento.

[!code-cpp[concrt-basic-agent#10](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_11.cpp)]

1. Crie um objeto `call` que atualiza a soma de verificação quando recebe dados.

[!code-cpp[concrt-basic-agent#11](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_12.cpp)]

   Esse `call` objeto também define o objeto `event` quando ele recebe a cadeia de caracteres vazia para sinalizar o fim do processamento.

1. Crie um objeto `file_reader` que lê do arquivo Test. txt e grava o conteúdo desse arquivo no objeto `call`.

[!code-cpp[concrt-basic-agent#12](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_13.cpp)]

1. Inicie o agente e aguarde sua conclusão.

[!code-cpp[concrt-basic-agent#13](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_14.cpp)]

1. Aguarde até que o objeto de `call` receba todos os dados e conclua.

[!code-cpp[concrt-basic-agent#14](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_15.cpp)]

1. Verifique se há erros no leitor de arquivos. Se nenhum erro tiver ocorrido, calcule a soma Adler-32 final e imprima a soma no console.

[!code-cpp[concrt-basic-agent#15](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_16.cpp)]

O exemplo a seguir mostra o arquivo BasicAgent. cpp completo.

[!code-cpp[concrt-basic-agent#16](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_17.cpp)]

[[Superior](#top)]

## <a name="sample-input"></a>Entrada de exemplo

Este é o conteúdo de exemplo do arquivo de entrada Text. txt:

```Output
The quick brown fox
jumps
over the lazy dog
```

## <a name="sample-output"></a>Saída de exemplo

Quando usado com a entrada de exemplo, esse programa produz a seguinte saída:

```Output
Adler-32 sum is fefb0d75
```

## <a name="robust-programming"></a>Programação Robusta

Para impedir o acesso simultâneo aos membros de dados, recomendamos que você adicione métodos que executam trabalho à seção `protected` ou `private` da sua classe. Adicione apenas métodos que enviam ou recebem mensagens de ou para o agente para a seção `public` da sua classe.

Sempre chame o método [Concurrency:: Agent::d um](reference/agent-class.md#done) para mover o agente para o estado concluído. Normalmente, você chama esse método antes de retornar do método `run`.

## <a name="next-steps"></a>{1&gt;{2&gt;Próximas etapas&lt;2}&lt;1}

Para obter outro exemplo de um aplicativo baseado em agente, consulte [Walkthrough: usando Join para evitar deadlock](../../parallel/concrt/walkthrough-using-join-to-prevent-deadlock.md).

## <a name="see-also"></a>Consulte também

[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)<br/>
[Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md)<br/>
[Instruções passo a passo: usando unir para evitar deadlock](../../parallel/concrt/walkthrough-using-join-to-prevent-deadlock.md)
