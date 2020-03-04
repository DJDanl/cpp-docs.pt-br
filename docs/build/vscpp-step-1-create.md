---
title: Criar um projeto de aplicativo de console C++
description: Criar um aplicativo de console Olá, Mundo em Visual C++
ms.custom: mvc
ms.date: 04/02/2019
ms.topic: tutorial
ms.devlang: cpp
ms.assetid: 45138d70-719d-42dc-90d7-1d0ca31a2f54
ms.openlocfilehash: 739da0b6e5400117c0b09a3d4c3335bd44529a25
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62314852"
---
# <a name="create-a-c-console-app-project"></a>Criar um projeto de aplicativo de console C++

O ponto de partida usual para um programador de C++ é um aplicativo "Olá, mundo!" executado na linha de comando. Que é o que você criará no Visual Studio nesta etapa.

## <a name="prerequisites"></a>Prerequisites

- Ter o Visual Studio com o desenvolvimento de Desktop com carga de trabalho do C++ instalada e em execução no seu computador. Se ele ainda não estiver instalado, confira [Instalar suporte para C++ no Visual Studio](vscpp-step-0-installation.md).

## <a name="create-your-app-project"></a>Criar seu projeto de aplicativo

O Visual Studio usa os *projetos* para organizar o código em um aplicativo e as *soluções* para organizar seus projetos. Um projeto contém todas as opções, configurações e regras usadas para compilar seus aplicativos e gerencia a relação entre todos os arquivos do projeto e todos os arquivos externos. Para criar seu aplicativo, primeiro, crie um novo projeto e uma nova solução.

::: moniker range=">=vs-2019"

1. No Visual Studio, abra o **arquivo** menu e escolha **New** > **projeto** para abrir o **criar um novo projeto** caixa de diálogo. Selecione o **aplicativo de Console** modelo e, em seguida, escolha **próxima**.

   ![Criar um novo projeto](media/vs2019-choose-console-app.png "abrir a criação de uma caixa de diálogo Novo projeto")

1. No **configurar seu novo projeto** caixa de diálogo, insira *HelloWorld* no **nome do projeto** caixa de edição. Escolher **criar** para criar o projeto.

   ![Nomear e criar o novo projeto](media/vs2019-configure-new-project-hello-world.png "nome e criar o novo projeto")

   Visual Studio cria um novo projeto, pronto para adicionar e editar seu código-fonte. Por padrão, o modelo de aplicativo de Console preenche seu código-fonte com um aplicativo "Hello World":

   ![Projeto do Hello World no IDE](media/vs2019-hello-world-code.png "projeto Hello World no IDE")

   Quando o código se parece com isso no editor, você estará pronto para ir para a próxima etapa e crie seu aplicativo.

::: moniker-end

::: moniker range="<=vs-2017"

1. No Visual Studio, abra o **arquivo** menu e escolha **New > Project** para abrir o **novo projeto** caixa de diálogo.

   ![Abra a caixa de diálogo Novo projeto](media/vscpp-file-new-project.gif "abrir a caixa de diálogo Novo projeto")

1. No **novo projeto** caixa de diálogo, selecione **instalado**, **Visual C++** se ele não estiver selecionado e, em seguida, escolha o **projeto vazio** modelo. No **nome** , insira *HelloWorld*. Escolher **Okey** para criar o projeto.

   ![Nomear e criar o novo projeto](media/vscpp-concierge-project-name-callouts.png "nome e criar o novo projeto")

Visual Studio cria um novo projeto vazio, pronto para ser especializados para o tipo de aplicativo que você deseja criar e adicionar seus arquivos de código-fonte. Você fará isso a seguir.

[Houve um problema.](#create-your-app-project-issues)

## <a name="make-your-project-a-console-app"></a>Verifique seu projeto de um aplicativo de console

Visual Studio pode criar todos os tipos de aplicativos e componentes para Windows e outras plataformas. O **projeto vazio** modelo não é específico sobre que tipo de aplicativo que ele cria. Para criar uma *aplicativo de console*, um que é executado em uma janela de prompt de comando ou o console, você deve informar ao Visual Studio para criar seu aplicativo para usar o subsistema de console.

1. No Visual Studio, abra o **Project** menu e escolha **propriedades** para abrir o **páginas de propriedades de HelloWorld** caixa de diálogo.

1. No **páginas de propriedades** caixa de diálogo, em **propriedades de configuração**, selecione **vinculador**, **sistema**e, em seguida, escolha a caixa de edição em o **subsistema** propriedade. No menu suspenso que aparece, selecione **Console (/ subsistema: CONSOLE)** . Escolha **OK** para salvar suas alterações.

   ![Abra a caixa de diálogo Property Pages](media/vscpp-properties-linker-subsystem.gif "abrir a caixa de diálogo páginas de propriedades")

Agora, o Visual Studio sabe para compilar seu projeto para ser executado em uma janela do console. Em seguida, você adicionará um arquivo de código-fonte e insira o código para seu aplicativo.

[Houve um problema.](#make-your-project-a-console-app-issues)

## <a name="add-a-source-code-file"></a>Adicionar um arquivo de código-fonte

1. Na **Gerenciador de soluções**, selecione o projeto HelloWorld. Na barra de menus, escolha **Project**, **Adicionar Novo Item** para abrir o **Add New Item** caixa de diálogo.

1. No **Adicionar Novo Item** caixa de diálogo, selecione **Visual C++** sob **instalado** se ainda não estiver selecionado. No painel central, selecione **arquivo C++ (. cpp)** . Alterar o **nome** à *HelloWorld*. Escolher **adicionar** para fechar a caixa de diálogo e criar o arquivo.

   ![Adicionar um arquivo de origem para HelloWorld](media/vscpp-add-new-item.gif "adicionar um arquivo de origem para HelloWorld")

Visual studio cria um arquivo de código fonte novo e vazio e o abre em uma janela do editor, pronta para entrar em seu código-fonte.

[Houve um problema.](#add-a-source-code-file-issues)

## <a name="add-code-to-the-source-file"></a>Adicione código ao arquivo de origem

1. Copie esse código para a janela do editor HelloWorld.

   ```cpp
   #include <iostream>

   int main()
   {
       std::cout << "Hello, world!" << std::endl;
       return 0;
   }
   ```

   Na janela do editor, o código deve ser assim:

   ![Olá, código do mundo no editor](media/vscpp-hello-world-editor.png "código Olá, mundo no editor")

Quando o código se parece com isso no editor, você estará pronto para ir para a próxima etapa e crie seu aplicativo.

[Houve um problema.](#add-a-source-code-file-issues)

::: moniker-end

## <a name="next-steps"></a>Próximas etapas

> [!div class="nextstepaction"]
> [Compilar e executar um projeto do C++](vscpp-step-2-build.md)

::: moniker range="<=vs-2017"

## <a name="troubleshooting-guide"></a>Guia de solução de problemas

Venha aqui para soluções para problemas comuns quando você cria seu primeiro projeto em C++.

### <a name="create-your-app-project-issues"></a>Criar seu aplicativo questões do projeto

Se o **novo projeto** não mostra a caixa de diálogo um **Visual C++** entrada sob **instalado**, provavelmente sua cópia do Visual Studio não tem o **área de trabalho desenvolvimento com C++** carga de trabalho instalada. Você pode executar o instalador desde o **novo projeto** caixa de diálogo. Escolha o **abrir instalador do Visual Studio** link para iniciar o instalador novamente. Se o **User Account Control** caixa de diálogo solicita permissões, escolha **Sim**. No instalador, certifique-se a **desenvolvimento para Desktop com C++** carga de trabalho está marcada e escolha **Okey** para atualizar sua instalação do Visual Studio.

Se outro projeto com o mesmo nome já existir, escolha outro nome para seu projeto, ou exclua o projeto existente e tente novamente. Para excluir um projeto existente, exclua a pasta de solução (a pasta que contém o arquivo HelloWorld) no Explorador de arquivos.

[Volte](#create-your-app-project).

### <a name="make-your-project-a-console-app-issues"></a>Tornar o seu projeto um problemas de aplicativo de console

Se você não vir **vinculador** listado em **propriedades de configuração**, escolha **Cancelar** para fechar o **páginas de propriedade** caixa de diálogo e, em seguida, Certifique-se de que o **HelloWorld** projeto for selecionado no **Gerenciador de soluções**, não a solução ou outro arquivo ou pasta, antes de tentar novamente.

O controle de lista suspensa não aparecer na **subsistema** caixa de edição de propriedade até que você selecionar a propriedade. Você pode selecioná-lo usando o ponteiro, ou você pode pressionar Tab para percorrer os controles de caixa de diálogo até **subsistema** é realçado. Escolha o controle de lista suspensa ou pressione Alt + seta para baixo para abri-lo.

[Voltar](#make-your-project-a-console-app)

### <a name="add-a-source-code-file-issues"></a>Adicionar um problemas de arquivos de código fonte

Ele é okey se você fornecer o arquivo de código fonte, um nome diferente. No entanto, não adicione mais de um arquivo de código fonte que contém o mesmo código ao seu projeto.

Se você adicionou o tipo errado de arquivo ao seu projeto, por exemplo, um arquivo de cabeçalho, exclua-o e tente novamente. Para excluir o arquivo, selecione-o na **Gerenciador de soluções** e pressione a tecla Delete.

[Volte](#add-a-source-code-file).

### <a name="add-code-to-the-source-file-issues"></a>Adicione código para os problemas de arquivo de origem

Se você acidentalmente fechou a janela de editor de origem código arquivo, para abri-lo novamente, clique duas vezes em HelloWorld na **Gerenciador de soluções** janela.

Se linhas onduladas vermelhas aparecem em qualquer coisa no editor de código fonte, verifique se o seu código corresponde ao exemplo na ortografia, pontuação e caso. Caso é significativo em código C++.

[Volte](#add-code-to-the-source-file).

::: moniker-end

<iframe src="" height="0" width="0" frameborder="0" name="frameTarget" />
