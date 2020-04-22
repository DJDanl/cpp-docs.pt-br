---
title: Criar um projeto de aplicativo de console C++
description: Crie um aplicativo de console Hello World usando o Microsoft C++ no Visual Studio.
ms.custom: mvc
ms.date: 04/20/2020
ms.topic: tutorial
ms.assetid: 45138d70-719d-42dc-90d7-1d0ca31a2f54
ms.openlocfilehash: 07e88da9a8a3712e1d37e319c29fd25aebce8ea7
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81749313"
---
# <a name="create-a-c-console-app-project"></a>Criar um projeto de aplicativo de console C++

O ponto de partida usual para um programador de C++ é um aplicativo "Olá, mundo!" executado na linha de comando. Isso é o que você vai criar no Visual Studio nesta etapa.

## <a name="prerequisites"></a>Pré-requisitos

- Ter o Visual Studio com o desenvolvimento de Desktop com carga de trabalho do C++ instalada e em execução no seu computador. Se ele ainda não estiver instalado, confira [Instalar suporte para C++ no Visual Studio](vscpp-step-0-installation.md).

## <a name="create-your-app-project"></a>Criar seu projeto de aplicativo

O Visual Studio usa os *projetos* para organizar o código em um aplicativo e as *soluções* para organizar seus projetos. Um projeto contém todas as opções, configurações e regras usadas para criar seus aplicativos. Ele gerencia a relação entre todos os arquivos do projeto e quaisquer arquivos externos. Para criar seu aplicativo, primeiro, crie um novo projeto e uma nova solução.

::: moniker range=">=vs-2019"

1. No Visual Studio, abra o menu **Arquivo** e escolha **Projeto Novo >** para abrir a caixa de diálogo Criar um novo **projeto.** Selecione o modelo **de aplicativo** de console que tenha **tags C++**, **Windows**e **Console** e escolha **Next**.

   ![Criar um novo projeto](media/vs2019-choose-console-app.png "Abra o Criar um novo diálogo de projeto")

1. Na **configuração do novo diálogo de projeto, digite** *HelloWorld* na caixa de edição **nome do Projeto.** Escolha **Criar** para criar o projeto.

   ![Nomeie e crie o novo projeto](media/vs2019-configure-new-project-hello-world.png "Nomeie e crie o novo projeto")

   Visual Studio cria um novo projeto. Está pronto para você adicionar e editar seu código fonte. Por padrão, o modelo do Aplicativo de Console preenche seu código-fonte com um aplicativo "Hello World":

   ![Projeto Hello World no IDE](media/vs2019-hello-world-code.png "Projeto Hello World no IDE")

   Quando o código se parece com isso no editor, você está pronto para ir para o próximo passo e construir o seu aplicativo.

[Houve um problema.](#create-your-app-project-issues)

::: moniker-end

::: moniker range="<=vs-2017"

1. No Visual Studio, abra o menu **Arquivo** e escolha **Projeto Novo >** para abrir a caixa de diálogo Novo **Projeto.**

   ![Abrir a caixa de diálogo Novo Projeto](media/vscpp-file-new-project.gif "Abrir a caixa de diálogo Novo Projeto")

1. Na caixa de diálogo **Novo projeto,** selecione **> Visual C++** se ele ainda não estiver selecionado e escolha o modelo **Projeto Vazio.** No campo **Nome,** *insira HelloWorld*. Escolha **OK** para criar o projeto.

   ![Nomeie e crie o novo projeto](media/vscpp-concierge-project-name-callouts.png "Nomeie e crie o novo projeto")

Visual Studio cria um novo projeto vazio. Ele está pronto para você se especializar para o tipo de aplicativo que você deseja criar e para adicionar seus arquivos de código fonte. Você fará isso em seguida.

[Houve um problema.](#create-your-app-project-issues)

## <a name="make-your-project-a-console-app"></a>Faça do seu projeto um aplicativo de console

Visual Studio pode criar todos os tipos de aplicativos e componentes para Windows e outras plataformas. O modelo **do Projeto Vazio** não é específico sobre que tipo de aplicativo ele cria. Um *aplicativo de console* é aquele que é executado em uma janela de solicitação de console ou comando. Para criar um, você deve dizer ao Visual Studio para construir seu aplicativo para usar o subsistema do console.

1. No Visual Studio, abra o menu **Projeto** e escolha **Propriedades** para abrir a caixa de diálogo **Páginas de Propriedade helloworld.**

1. Na caixa de diálogo **Propriedades Páginas,** selecione **Propriedades de configuração > Sistema de >** e escolha a caixa de edição ao lado da propriedade **Subsystem.** No menu suspenso que aparece, selecione **Console (/SUBSYSTEM:CONSOLE)**. Escolha **OK** para salvar suas alterações.

   ![Abra a caixa de diálogo Páginas de propriedade](media/vscpp-properties-linker-subsystem.gif "Abra a caixa de diálogo Páginas de propriedade")

Visual Studio agora sabe construir seu projeto para ser executado em uma janela de console. Em seguida, você adicionará um arquivo de código fonte e digitará o código para o seu aplicativo.

[Houve um problema.](#make-your-project-a-console-app-issues)

## <a name="add-a-source-code-file"></a>Adicionar um arquivo de código fonte

1. No **Solution Explorer,** selecione o projeto HelloWorld. Na barra de menus, escolha **Projeto**, **Adicionar novo item** para abrir a **caixa de diálogo Adicionar novo item.**

1. Na **caixa de diálogo Adicionar novo item,** selecione **Visual C++** em **Instalado** se ele ainda não estiver selecionado. No painel central, selecione **arquivo C++ (.cpp)**. Alterar o **nome** para *HelloWorld.cpp*. Escolha **Adicionar** para fechar a caixa de diálogo e criar o arquivo.

   ![Adicione um arquivo de origem para HelloWorld.cpp](media/vscpp-add-new-item.gif "Adicione um arquivo de origem para HelloWorld.cpp")

O visual studio cria um novo arquivo de código fonte vazio e o abre em uma janela de editor, pronto para inserir seu código-fonte.

[Houve um problema.](#add-a-source-code-file-issues)

## <a name="add-code-to-the-source-file"></a>Adicionar código ao arquivo de origem

1. Copie este código na janela do editor HelloWorld.cpp.

   ```cpp
   #include <iostream>

   int main()
   {
       std::cout << "Hello, world!" << std::endl;
       return 0;
   }
   ```

   O código deve ficar assim na janela do editor:

   ![Olá Código mundial no editor](media/vscpp-hello-world-editor.png "Olá Código mundial no editor")

Quando o código se parece com isso no editor, você está pronto para ir para o próximo passo e construir o seu aplicativo.

[Houve um problema.](#add-a-source-code-file-issues)

::: moniker-end

## <a name="next-steps"></a>Próximas etapas

> [!div class="nextstepaction"]
> [Construir e executar um projeto C++](vscpp-step-2-build.md)

## <a name="troubleshooting-guide"></a>Guia de Solução de Problemas

Venha aqui para obter soluções para problemas comuns quando você criar seu primeiro projeto C++.

### <a name="create-your-app-project-issues"></a>Crie seu projeto de aplicativo: problemas

::: moniker range="vs-2019"

A caixa de diálogo **Novo Projeto** deve mostrar um modelo de aplicativo **de console** que tenha tags **C++**, **Windows**e **Console.** Se você não vê-lo, há duas causas possíveis. Pode ser filtrado para fora da lista, ou pode não ser instalado. Primeiro, verifique as vertentes do filtro no topo da lista de modelos. Defina-os como **C++**, **Windows**e **Console**. O modelo c++ **console App** deve aparecer; caso contrário, o desenvolvimento de desktop com carga de trabalho **C++** não está instalado.

Para instalar **o desenvolvimento de desktop com C++,** você pode executar o instalador direto da caixa de diálogo Novo **Projeto.** Escolha o **link Instalar mais ferramentas e recursos** na parte inferior da lista de modelos para iniciar o instalador. Se a caixa de diálogo **Controle de conta** de usuário solicitar permissões, escolha **Sim**. No instalador, certifique-se de que o desenvolvimento da área de trabalho com carga de trabalho **C++** seja verificado. Em seguida, escolha **Modificar** para atualizar sua instalação do Visual Studio.

Se outro projeto com o mesmo nome já existir, escolha outro nome para o seu projeto. Ou, exclua o projeto existente e tente novamente. Para excluir um projeto existente, exclua a pasta de solução (a pasta que contém o arquivo *helloworld.sln)* no File Explorer.

[Volte.](#create-your-app-project)

::: moniker-end

::: moniker range="vs-2017"

Se a caixa de diálogo **Novo Projeto** não mostrar uma entrada **Visual C++** em **Instalação,** sua cópia do Visual Studio provavelmente não terá o desenvolvimento de Desktop com carga de trabalho **C++** instalada. Você pode executar o instalador direto da caixa de diálogo **Projeto** Novo. Escolha o link **Do Instalador do Estúdio Visual Aberto** para iniciar o instalador novamente. Se a caixa de diálogo **Controle de conta** de usuário solicitar permissões, escolha **Sim**. Atualize o instalador se necessário. No instalador, certifique-se de que o desenvolvimento da área de trabalho com carga de trabalho **C++** seja verificado e escolha **OK** para atualizar sua instalação do Visual Studio.

::: moniker-end

::: moniker range="<=vs-2017"

Se outro projeto com o mesmo nome já existir, escolha outro nome para o seu projeto. Ou, exclua o projeto existente e tente novamente. Para excluir um projeto existente, exclua a pasta de solução (a pasta que contém o arquivo *helloworld.sln)* no File Explorer.

[Volte.](#create-your-app-project)

### <a name="make-your-project-a-console-app-issues"></a>Faça do seu projeto um aplicativo de console: problemas

Se você não ver **O Linker** listado em **Propriedades de configuração,** escolha **Cancelar** para fechar a caixa de diálogo **Páginas de** propriedade. Certifique-se de que o projeto **HelloWorld** esteja selecionado no **Solution Explorer** antes de tentar novamente. Não selecione a solução **HelloWorld,** ou outro item, no **Solution Explorer**.

O controle de isto não aparece na caixa de edição de propriedade **do SubSystem** até que você selecione a propriedade. Clique na caixa de edição para selecioná-la. Ou, você pode pressionar **Tab** para ciclo através dos controles de diálogo até **que o SubSystem** seja destacado. Escolha o controle de isto ou **pressione Alt+Down** para abri-lo.

[Voltar](#make-your-project-a-console-app)

### <a name="add-a-source-code-file-issues"></a>Adicionar um arquivo de código fonte: problemas

Tudo bem se você der ao arquivo de código fonte um nome diferente. No entanto, não adicione mais de um arquivo que contenha o mesmo código ao seu projeto.

Se você adicionou o tipo de arquivo errado ao seu projeto, como um arquivo de cabeçalho, exclua-o e tente novamente. Para excluir o arquivo, selecione-o no **Solution Explorer**. Em seguida, pressione a **tecla Excluir.**

[Volte.](#add-a-source-code-file)

### <a name="add-code-to-the-source-file-issues"></a>Adicionar código ao arquivo fonte: problemas

Se você acidentalmente fechou a janela do editor de arquivos de código fonte, você pode facilmente abri-la novamente. Para abri-lo, clique duas vezes em HelloWorld.cpp na janela **Solution Explorer.**

Se os rabiscos vermelhos aparecerem em qualquer coisa no editor de código fonte, verifique se seu código corresponde ao exemplo em ortografia, pontuação e caso. O caso é significativo no código C++.

[Volte.](#add-code-to-the-source-file)

::: moniker-end

<iframe src="" height="0" width="0" frameborder="0" name="frameTarget" />
