---
title: 'Instruções passo a passo: criando um aplicativo com base no agente'
ms.date: 04/25/2019
helpviewer_keywords:
- asynchronous agents, creating
- agent class, example
ms.assetid: 730f42ce-6d58-4753-b948-fd9c9ef2ce6c
ms.openlocfilehash: 9d9fdd3ddface01f84f6426dd334600cf88b84e7
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92924825"
---
# <a name="walkthrough-creating-an-agent-based-application"></a>Instruções passo a passo: criando um aplicativo com base no agente

Este tópico descreve como criar um aplicativo básico baseado em agente. Neste tutorial, você pode criar um agente que lê dados de um arquivo de texto de forma assíncrona. O aplicativo usa o algoritmo de soma de verificação Adler-32 para calcular a soma de verificação do conteúdo desse arquivo.

## <a name="prerequisites"></a>Pré-requisitos

Você deve entender os seguintes tópicos para concluir este passo a passos:

- [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)

- [Blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md)

- [Funções de passagem de mensagens](../../parallel/concrt/message-passing-functions.md)

- [Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md)

## <a name="sections"></a><a name="top"></a> As

Este tutorial demonstra como executar as seguintes tarefas:

- [Criando o Aplicativo de Console](#createapplication)

- [Criando a Classe file_reader](#createagentclass)

- [Usando a Classe file_reader no Aplicativo](#useagentclass)

## <a name="creating-the-console-application"></a><a name="createapplication"></a> Criando o aplicativo de console

Esta seção mostra como criar um aplicativo de console C++ que faz referência aos arquivos de cabeçalho que o programa usará. As etapas iniciais variam de acordo com a versão do Visual Studio que você está usando. Para ver a documentação da sua versão preferida do Visual Studio, use o controle seletor de **versão** . Ele é encontrado na parte superior do Sumário nesta página.

::: moniker range="msvc-160"

### <a name="to-create-a-c-console-application-in-visual-studio-2019"></a>Para criar um aplicativo de console C++ no Visual Studio 2019

1. No menu principal, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Criar um projeto** .

1. Na parte superior da caixa de diálogo, defina **Linguagem** como **C++** , **Plataforma** como **Windows** e **Tipo de projeto** como **Console** .

1. Na lista filtrada de tipos de projeto, escolha **Aplicativo de Console** e, em seguida, escolha **Avançar** . Na próxima página, insira `BasicAgent` como o nome do projeto e especifique o local do projeto, se desejado.

1. Escolha o botão **Criar** para criar o projeto.

1. Clique com o botão direito do mouse no nó do projeto em **Gerenciador de soluções** e escolha **Propriedades** . Em **Propriedades de configuração**  >  cabeçalhos pré-compilados **C/C++**  >  **Precompiled Headers**  >  **cabeçalho pré-compilado** , escolha **criar** .

::: moniker-end

::: moniker range="<=msvc-150"

### <a name="to-create-a-c-console-application-in-visual-studio-2017-and-earlier"></a>Para criar um aplicativo de console C++ no Visual Studio 2017 e anterior

1. No menu **arquivo** , clique em **novo** e, em seguida, clique em **projeto** para exibir a caixa de diálogo **novo projeto** .

1. Na caixa de diálogo **novo projeto** , selecione o nó **Visual C++** no painel **tipos de projeto** e, em seguida, selecione aplicativo de **console Win32** no painel **modelos** . Digite um nome para o projeto, por exemplo, `BasicAgent` e clique em **OK** para exibir o **Assistente do aplicativo de console do Win32** .

1. Na caixa de diálogo **Assistente de aplicativo do console do Win32** , clique em **concluir** .

::: moniker-end

1. Em *PCH. h* ( *stdafx. h* no Visual Studio 2017 e anterior), adicione o seguinte código:

[!code-cpp[concrt-basic-agent#1](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_1.h)]

   O arquivo de cabeçalho Agents. h contém a funcionalidade da classe [Concurrency:: Agent](../../parallel/concrt/reference/agent-class.md) .

1. Verifique se o aplicativo foi criado com êxito criando-o e executando-o. Para criar o aplicativo, no menu **Compilar** , clique em **Compilar solução** . Se o aplicativo for compilado com êxito, execute o aplicativo clicando em **Iniciar Depuração** no menu **depurar** .

[[Superior](#top)]

## <a name="creating-the-file_reader-class"></a><a name="createagentclass"></a> Criando a classe file_reader

Esta seção mostra como criar a `file_reader` classe. O tempo de execução agenda cada agente para executar o trabalho em seu próprio contexto. Portanto, você pode criar um agente que executa o trabalho de forma síncrona, mas interage com outros componentes de maneira assíncrona. A `file_reader` classe lê dados de um determinado arquivo de entrada e envia dados desse arquivo para um determinado componente de destino.

#### <a name="to-create-the-file_reader-class"></a>Para criar a classe file_reader

1. Adicione um novo arquivo de cabeçalho C++ ao seu projeto. Para fazer isso, clique com o botão direito do mouse no nó **arquivos de cabeçalho** em **Gerenciador de soluções** , clique em **Adicionar** e, em seguida, clique em **novo item** . No painel **modelos** , selecione **arquivo de cabeçalho (. h)** . Na caixa de diálogo **Adicionar novo item** , digite `file_reader.h` na caixa **nome** e, em seguida, clique em **Adicionar** .

1. Em file_reader. h, adicione o código a seguir.

[!code-cpp[concrt-basic-agent#17](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_2.h)]

1. Em file_reader. h, crie uma classe denominada `file_reader` derivada de `agent` .

[!code-cpp[concrt-basic-agent#2](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_3.h)]

1. Adicione os seguintes membros de dados à **`private`** seção da sua classe.

[!code-cpp[concrt-basic-agent#3](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_4.h)]

   O `_file_name` membro é o nome do arquivo do qual o agente lê. O `_target` membro é um objeto [Concurrency:: ITarget](../../parallel/concrt/reference/itarget-class.md) para o qual o agente grava o conteúdo do arquivo. O `_error` membro mantém qualquer erro que ocorra durante a vida útil do agente.

1. Adicione o código a seguir para os `file_reader` construtores à **`public`** seção da `file_reader` classe.

[!code-cpp[concrt-basic-agent#4](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_5.h)]

   Cada sobrecarga de construtor define os `file_reader` membros de dados. A segunda e a terceira sobrecarga de Construtor permitem que seu aplicativo use um Agendador específico com seu agente. A primeira sobrecarga usa o agendador padrão com seu agente.

1. Adicione o `get_error` método à seção pública da `file_reader` classe.

[!code-cpp[concrt-basic-agent#5](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_6.h)]

   O `get_error` método recupera qualquer erro que ocorra durante a vida útil do agente.

1. Implemente o método [Concurrency:: Agent:: execute](reference/agent-class.md#run) na **`protected`** seção da sua classe.

[!code-cpp[concrt-basic-agent#6](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_7.h)]

O `run` método abre o arquivo e lê os dados dele. O `run` método usa o tratamento de exceções para capturar quaisquer erros que ocorram durante o processamento de arquivos.

   Cada vez que esse método lê dados do arquivo, ele chama a função [Concurrency:: asend](reference/concurrency-namespace-functions.md#asend) para enviar esses dados para o buffer de destino. Ele envia a cadeia de caracteres vazia para seu buffer de destino para indicar o fim do processamento.

O exemplo a seguir mostra o conteúdo completo de file_reader. h.

[!code-cpp[concrt-basic-agent#7](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_8.h)]

[[Superior](#top)]

## <a name="using-the-file_reader-class-in-the-application"></a><a name="useagentclass"></a> Usando a classe file_reader no aplicativo

Esta seção mostra como usar a `file_reader` classe para ler o conteúdo de um arquivo de texto. Ele também mostra como criar um objeto [Concurrency:: Call](../../parallel/concrt/reference/call-class.md) que recebe esses dados de arquivo e calcula sua soma de verificação de Adler-32.

#### <a name="to-use-the-file_reader-class-in-your-application"></a>Para usar a classe file_reader no aplicativo

1. Em BasicAgent. cpp, adicione a instrução a seguir `#include` .

[!code-cpp[concrt-basic-agent#8](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_9.cpp)]

1. Em BasicAgent. cpp, adicione as seguintes **`using`** diretivas.

[!code-cpp[concrt-basic-agent#9](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_10.cpp)]

1. Na `_tmain` função, crie um objeto [Concurrency:: Event](../../parallel/concrt/reference/event-class.md) que sinaliza o fim do processamento.

[!code-cpp[concrt-basic-agent#10](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_11.cpp)]

1. Crie um `call` objeto que atualize a soma de verificação quando receber dados.

[!code-cpp[concrt-basic-agent#11](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_12.cpp)]

   Esse `call` objeto também define o `event` objeto quando recebe a cadeia de caracteres vazia para sinalizar o fim do processamento.

1. Crie um `file_reader` objeto que leia o arquivo test.txt e grave o conteúdo desse arquivo no `call` objeto.

[!code-cpp[concrt-basic-agent#12](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_13.cpp)]

1. Inicie o agente e aguarde sua conclusão.

[!code-cpp[concrt-basic-agent#13](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_14.cpp)]

1. Aguarde até que o `call` objeto receba todos os dados e conclua.

[!code-cpp[concrt-basic-agent#14](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_15.cpp)]

1. Verifique se há erros no leitor de arquivos. Se nenhum erro tiver ocorrido, calcule a soma Adler-32 final e imprima a soma no console.

[!code-cpp[concrt-basic-agent#15](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_16.cpp)]

O exemplo a seguir mostra o arquivo BasicAgent. cpp completo.

[!code-cpp[concrt-basic-agent#16](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_17.cpp)]

[[Superior](#top)]

## <a name="sample-input"></a>Entrada de exemplo

Este é o conteúdo de exemplo do arquivo de entrada text.txt:

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

## <a name="robust-programming"></a>Programação robusta

Para impedir o acesso simultâneo aos membros de dados, recomendamos que você adicione métodos que executam trabalho **`protected`** à **`private`** seção ou da sua classe. Adicione apenas métodos que enviam ou recebem mensagens de ou para o agente para a **`public`** seção da sua classe.

Sempre chame o método [Concurrency:: Agent::d um](reference/agent-class.md#done) para mover o agente para o estado concluído. Normalmente, você chama esse método antes de retornar do `run` método.

## <a name="next-steps"></a>Próximas etapas

Para obter outro exemplo de um aplicativo baseado em agente, consulte [Walkthrough: usando Join para evitar deadlock](../../parallel/concrt/walkthrough-using-join-to-prevent-deadlock.md).

## <a name="see-also"></a>Veja também

[Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Funções de passagem de mensagens](../../parallel/concrt/message-passing-functions.md)<br/>
[Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md)<br/>
[Walkthrough: usando Join para evitar deadlock](../../parallel/concrt/walkthrough-using-join-to-prevent-deadlock.md)
