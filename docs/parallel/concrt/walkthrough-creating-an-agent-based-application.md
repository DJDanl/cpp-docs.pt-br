---
title: 'Instruções passo a passo: criando um aplicativo com base no agente'
ms.date: 04/25/2019
helpviewer_keywords:
- asynchronous agents, creating
- agent class, example
ms.assetid: 730f42ce-6d58-4753-b948-fd9c9ef2ce6c
ms.openlocfilehash: 20197786e3d3c2d34d29af748c1cc073902cf70d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377452"
---
# <a name="walkthrough-creating-an-agent-based-application"></a>Instruções passo a passo: criando um aplicativo com base no agente

Este tópico descreve como criar um aplicativo básico baseado em agentes. Neste passo a passo, você pode criar um agente que lê dados de um arquivo de texto assíncronamente. O aplicativo usa o algoritmo de verificação Adler-32 para calcular a soma de verificação do conteúdo desse arquivo.

## <a name="prerequisites"></a>Pré-requisitos

Você deve entender os seguintes tópicos para completar este passo a passo:

- [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)

- [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)

- [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)

- [Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md)

## <a name="sections"></a><a name="top"></a>Seções

Este passo a passo demonstra como executar as seguintes tarefas:

- [Criando o Aplicativo de Console](#createapplication)

- [Criando a Classe file_reader](#createagentclass)

- [Usando a Classe file_reader no Aplicativo](#useagentclass)

## <a name="creating-the-console-application"></a><a name="createapplication"></a>Criando o aplicativo do console

Esta seção mostra como criar um aplicativo de console C++ que faz referência aos arquivos de cabeçalho que o programa usará. As etapas iniciais variam dependendo da versão do Visual Studio que você está usando. Para ver a documentação da sua versão preferida do Visual Studio, use o controle do seletor **de versão.** É encontrado no topo da tabela de conteúdo nesta página.

::: moniker range="vs-2019"

### <a name="to-create-a-c-console-application-in-visual-studio-2019"></a>Para criar um aplicativo de console C++ no Visual Studio 2019

1. No menu principal, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Criar um projeto**.

1. Na parte superior da caixa de diálogo, defina **Linguagem** como **C++**, **Plataforma** como **Windows** e **Tipo de projeto** como **Console**.

1. Na lista filtrada de tipos de projeto, escolha **Aplicativo de Console** e, em seguida, escolha **Avançar**. Na página seguinte, `BasicAgent` digite como o nome do projeto e especifique o local do projeto se desejar.

1. Escolha o botão **Criar** para criar o projeto.

1. Clique com o botão direito do mouse no nó do projeto no **Solution Explorer**e escolha **Propriedades**. Em **Propriedades de configuração** > **C/C++** > **Cabeçalhos pré-compilados** > **cabeçalho pré-compilado** escolha **Criar**.

::: moniker-end

::: moniker range="<=vs-2017"

### <a name="to-create-a-c-console-application-in-visual-studio-2017-and-earlier"></a>Para criar um aplicativo de console C++ no Visual Studio 2017 e anterior

1. No menu **Arquivo,** clique em **Novo**e clique em **Projeto** para exibir a caixa de diálogo **Novo Projeto.**

1. Na caixa de diálogo **Novo Projeto,** selecione o nó **Visual C++** no painel **tipos de projeto** e, em seguida, selecione **Win32 Console Application** no painel **Templates.** Digite um nome para o `BasicAgent`projeto, por exemplo, e clique em **OK** para exibir o **Assistente de aplicativo do console Win32**.

1. Na caixa de diálogo **Assistente do aplicativo do console Win32,** clique em **Concluir**.

::: moniker-end

1. Em *pch.h* *(stdafx.h* no Visual Studio 2017 e anterior), adicione o seguinte código:

[!code-cpp[concrt-basic-agent#1](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_1.h)]

   O header file agents.h contém a funcionalidade da [classe simultuá-lo::agent.](../../parallel/concrt/reference/agent-class.md)

1. Verifique se o aplicativo foi criado com sucesso, construindo e executando-o. Para construir o aplicativo, no menu **Construir,** clique em **Criar solução**. Se o aplicativo for criado com sucesso, execute o aplicativo clicando em **Iniciar depuração** no menu **Depuração.**

[[Top](#top)]

## <a name="creating-the-file_reader-class"></a><a name="createagentclass"></a>Criando a Classe file_reader

Esta seção mostra `file_reader` como criar a classe. O tempo de execução agenda cada agente para realizar o trabalho em seu próprio contexto. Portanto, você pode criar um agente que executa o trabalho de forma sincronizada, mas interage com outros componentes assíncronamente. A `file_reader` classe lê dados de um determinado arquivo de entrada e envia dados desse arquivo para um determinado componente-alvo.

#### <a name="to-create-the-file_reader-class"></a>Para criar a classe file_reader

1. Adicione um novo arquivo de cabeçalho C++ ao seu projeto. Para isso, clique com o botão direito do mouse no nó 'Arquivos de **cabeçalho'** no **Solution Explorer**, clique em **Adicionar**e clique em **Novo Item**. No **painel Modelos,** selecione **Arquivo de cabeçalho (.h)**. Na caixa de diálogo Adicionar `file_reader.h` novo **item,** digite a caixa **Nome** e clique em **Adicionar**.

1. Em file_reader.h, adicione o seguinte código.

[!code-cpp[concrt-basic-agent#17](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_2.h)]

1. Em file_reader.h, crie uma `file_reader` classe que `agent`é nomeada que deriva de .

[!code-cpp[concrt-basic-agent#2](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_3.h)]

1. Adicione os seguintes `private` membros de dados à seção da sua classe.

[!code-cpp[concrt-basic-agent#3](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_4.h)]

   O `_file_name` membro é o nome do arquivo que o agente lê. O `_target` membro é uma [moeda de serviço::ITarget](../../parallel/concrt/reference/itarget-class.md) objeto para o qual o agente grava o conteúdo do arquivo. O `_error` membro contém qualquer erro que ocorra durante a vida do agente.

1. Adicione o seguinte `file_reader` código para os `public` construtores `file_reader` à seção da classe.

[!code-cpp[concrt-basic-agent#4](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_5.h)]

   Cada sobrecarga do `file_reader` construtor define os membros dos dados. A segunda e terceira sobrecarga de construtores permite que seu aplicativo use um agendador específico com seu agente. A primeira sobrecarga usa o agendador padrão com seu agente.

1. Adicione `get_error` o método à seção pública da `file_reader` classe.

[!code-cpp[concrt-basic-agent#5](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_6.h)]

   O `get_error` método recupera qualquer erro que ocorra durante a vida do agente.

1. Implementar o [método de simultu:agent::run](reference/agent-class.md#run) na `protected` seção da sua classe.

[!code-cpp[concrt-basic-agent#6](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_7.h)]

O `run` método abre o arquivo e lê dados dele. O `run` método usa o manuseio de exceção para capturar quaisquer erros que ocorram durante o processamento de arquivos.

   Cada vez que este método lê dados do arquivo, ele chama a [função de simultuá-lo](reference/concurrency-namespace-functions.md#asend) para enviar esses dados para o buffer de destino. Ele envia a seqüência vazia para o buffer de destino para indicar o fim do processamento.

O exemplo a seguir mostra o conteúdo completo de file_reader.h.

[!code-cpp[concrt-basic-agent#7](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_8.h)]

[[Top](#top)]

## <a name="using-the-file_reader-class-in-the-application"></a><a name="useagentclass"></a>Usando a classe file_reader no aplicativo

Esta seção mostra `file_reader` como usar a classe para ler o conteúdo de um arquivo de texto. Ele também mostra como criar um objeto [de sion:call](../../parallel/concrt/reference/call-class.md) que recebe esses dados de arquivo e calcula sua soma de verificação Do Adler-32.

#### <a name="to-use-the-file_reader-class-in-your-application"></a>Para usar a classe file_reader no aplicativo

1. Em BasicAgent.cpp, adicione `#include` a seguinte declaração.

[!code-cpp[concrt-basic-agent#8](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_9.cpp)]

1. Em BasicAgent.cpp, adicione `using` as seguintes diretivas.

[!code-cpp[concrt-basic-agent#9](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_10.cpp)]

1. Na `_tmain` função, crie um objeto [de si00::evento](../../parallel/concrt/reference/event-class.md) que sinaliza o fim do processamento.

[!code-cpp[concrt-basic-agent#10](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_11.cpp)]

1. Crie `call` um objeto que atualize a soma de verificação quando receber dados.

[!code-cpp[concrt-basic-agent#11](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_12.cpp)]

   Este `call` objeto também `event` define o objeto quando recebe a seqüência vazia para sinalizar o fim do processamento.

1. Crie `file_reader` um objeto que leia a partir do file test.txt `call` e escreva o conteúdo desse arquivo para o objeto.

[!code-cpp[concrt-basic-agent#12](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_13.cpp)]

1. Ligue o agente e espere que termine.

[!code-cpp[concrt-basic-agent#13](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_14.cpp)]

1. Aguarde `call` que o objeto receba todos os dados e termine.

[!code-cpp[concrt-basic-agent#14](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_15.cpp)]

1. Verifique se há erros no leitor de arquivos. Se não ocorreu nenhum erro, calcule a soma final do Adler-32 e imprima a soma para o console.

[!code-cpp[concrt-basic-agent#15](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_16.cpp)]

O exemplo a seguir mostra o arquivo BasicAgent.cpp completo.

[!code-cpp[concrt-basic-agent#16](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-agent-based-application_17.cpp)]

[[Top](#top)]

## <a name="sample-input"></a>Entrada de exemplo

Este é o conteúdo de exemplo do arquivo de entrada text.txt:

```Output
The quick brown fox
jumps
over the lazy dog
```

## <a name="sample-output"></a>Saída de exemplo

Quando usado com a entrada de amostra, este programa produz a seguinte saída:

```Output
Adler-32 sum is fefb0d75
```

## <a name="robust-programming"></a>Programação robusta

Para evitar o acesso simultâneo aos membros de `protected` `private` dados, recomendamos que você adicione métodos que executem o trabalho à ou seção da sua classe. Adicione apenas métodos que enviam ou recebem mensagens `public` para ou do agente para a seção de sua classe.

Sempre ligue para o [método de concorrência::agent::done](reference/agent-class.md#done) para mover seu agente para o estado completo. Você normalmente chama esse método `run` antes de retornar do método.

## <a name="next-steps"></a>Próximas etapas

Para outro exemplo de um aplicativo baseado em agente, consulte [Passo a Passo: Usando o join para evitar o impasse](../../parallel/concrt/walkthrough-using-join-to-prevent-deadlock.md).

## <a name="see-also"></a>Confira também

[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)<br/>
[Estruturas de dados de sincronização](../../parallel/concrt/synchronization-data-structures.md)<br/>
[Instruções passo a passo: usando join para Evitar Deadlock](../../parallel/concrt/walkthrough-using-join-to-prevent-deadlock.md)
