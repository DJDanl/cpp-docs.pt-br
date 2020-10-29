---
title: Criar um projeto de aplicativo de console C++
description: Crie um aplicativo de console Olá, Mundo usando o Microsoft C++ no Visual Studio.
ms.custom: mvc
ms.date: 04/20/2020
ms.topic: tutorial
ms.assetid: 45138d70-719d-42dc-90d7-1d0ca31a2f54
ms.openlocfilehash: ee9631ee858ca34f82b599eeabce628483d9a247
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92922082"
---
# <a name="create-a-c-console-app-project"></a>Criar um projeto de aplicativo de console C++

O ponto de partida usual para um programador de C++ é um aplicativo "Olá, mundo!" executado na linha de comando. Isso é o que você criará no Visual Studio nesta etapa.

## <a name="prerequisites"></a>Pré-requisitos

- Ter o Visual Studio com o desenvolvimento de Desktop com carga de trabalho do C++ instalada e em execução no seu computador. Se ele ainda não estiver instalado, confira [Instalar suporte para C++ no Visual Studio](vscpp-step-0-installation.md).

## <a name="create-your-app-project"></a>Criar seu projeto de aplicativo

O Visual Studio usa os *projetos* para organizar o código em um aplicativo e as *soluções* para organizar seus projetos. Um projeto contém todas as opções, configurações e regras usadas para criar seus aplicativos. Ele gerencia a relação entre todos os arquivos do projeto e todos os arquivos externos. Para criar seu aplicativo, primeiro, crie um novo projeto e uma nova solução.

::: moniker range=">=msvc-160"

1. No Visual Studio, abra o menu **arquivo** e escolha **novo projeto >** para abrir a caixa de diálogo **criar um novo projeto** . Selecione o modelo de **aplicativo de console** que tem as marcas **C++** , **Windows** e **console** e, em seguida, escolha **Avançar** .

   ![Criar um novo projeto](media/vs2019-choose-console-app.png "Abrir a caixa de diálogo criar um novo projeto")

1. No diálogo **configurar seu novo projeto** , digite *HelloWorld* na caixa de edição **nome do projeto** . Escolha **criar** para criar o projeto.

   ![Captura de tela da caixa de diálogo Configurar seu novo projeto com Olá, Mundo digitados no campo de texto nome do projeto.](media/vs2019-configure-new-project-hello-world.png "Nomeie e crie o novo projeto")

   O Visual Studio cria um novo projeto. Ele está pronto para você adicionar e editar seu código-fonte. Por padrão, o modelo de aplicativo de console preenche o código-fonte com um aplicativo "Olá, Mundo":

   ![Olá, Mundo projeto no IDE](media/vs2019-hello-world-code.png "Olá, Mundo projeto no IDE")

   Quando o código tiver esta aparência no editor, você estará pronto para ir para a próxima etapa e criar seu aplicativo.

[Houve um problema.](#create-your-app-project-issues)

::: moniker-end

::: moniker range="<=msvc-150"

1. No Visual Studio, abra o menu **arquivo** e escolha **novo projeto >** para abrir a caixa de diálogo **novo projeto** .

   ![Abrir a caixa de diálogo Novo Projeto](media/vscpp-file-new-project.gif "Abrir a caixa de diálogo Novo Projeto")

1. Na caixa de diálogo **novo projeto** , selecione **instalado > Visual C++** se ele ainda não estiver selecionado e, em seguida, escolha o modelo de **projeto vazio** . No campo **nome** , digite *HelloWorld* . Escolha **OK** para criar o projeto.

   ![Captura de tela da caixa de diálogo novo projeto com instalado > Visual C Plus Plus selecionado e chamado, a opção de projeto vazio chamada out e o hellow World digitado na caixa de texto nome.](media/vscpp-concierge-project-name-callouts.png "Nomeie e crie o novo projeto")

O Visual Studio cria um projeto novo e vazio. Ele está pronto para você se especializar para o tipo de aplicativo que deseja criar e adicionar seus arquivos de código-fonte. Você fará isso em seguida.

[Houve um problema.](#create-your-app-project-issues)

## <a name="make-your-project-a-console-app"></a>Tornar seu projeto um aplicativo de console

O Visual Studio pode criar todos os tipos de aplicativos e componentes para Windows e outras plataformas. O modelo de **projeto vazio** não é específico sobre o tipo de aplicativo que ele cria. Um *aplicativo de console* é aquele executado em uma janela de console ou de prompt de comando. Para criar um, você deve informar ao Visual Studio para criar seu aplicativo para usar o subsistema de console.

1. No Visual Studio, abra o menu **projeto** e escolha **Propriedades** para abrir a caixa de diálogo **páginas de propriedades do HelloWorld** .

1. Na caixa de diálogo **páginas de propriedades** , selecione **propriedades de configuração > o vinculador > sistema** e, em seguida, escolha o quadro de edição ao lado da propriedade **subsistema** . No menu suspenso que aparece, selecione **console (/SUBSYSTEM: console)** . Escolha **OK** para salvar suas alterações.

   ![Abrir a caixa de diálogo páginas de propriedades](media/vscpp-properties-linker-subsystem.gif "Abrir a caixa de diálogo páginas de propriedades")

O Visual Studio agora sabe criar seu projeto para ser executado em uma janela de console. Em seguida, você adicionará um arquivo de código-fonte e inserirá o código para seu aplicativo.

[Houve um problema.](#make-your-project-a-console-app-issues)

## <a name="add-a-source-code-file"></a>Adicionar um arquivo de código-fonte

1. Em **Gerenciador de soluções** , selecione o projeto HelloWorld. Na barra de menus, escolha **projeto** , **Adicionar novo item** para abrir a caixa de diálogo **Adicionar novo item** .

1. Na caixa de diálogo **Adicionar novo item** , selecione **Visual C++** em **instalado** , se ainda não estiver selecionado. No painel central, selecione **arquivo C++ (. cpp)** . Altere o **nome** para *HelloWorld. cpp* . Escolha **Adicionar** para fechar a caixa de diálogo e criar o arquivo.

   ![Adicionar um arquivo de origem para HelloWorld. cpp](media/vscpp-add-new-item.gif "Adicionar um arquivo de origem para HelloWorld. cpp")

O Visual Studio cria um novo arquivo de código-fonte vazio e o abre em uma janela do editor, pronto para inserir seu código-fonte.

[Houve um problema.](#add-a-source-code-file-issues)

## <a name="add-code-to-the-source-file"></a>Adicionar código ao arquivo de origem

1. Copie esse código para a janela do editor HelloWorld. cpp.

   ```cpp
   #include <iostream>

   int main()
   {
       std::cout << "Hello, world!" << std::endl;
       return 0;
   }
   ```

   O código deve ter a seguinte aparência na janela do editor:

   ![Código de Olá, Mundo no editor](media/vscpp-hello-world-editor.png "Código de Olá, Mundo no editor")

Quando o código tiver esta aparência no editor, você estará pronto para ir para a próxima etapa e criar seu aplicativo.

[Houve um problema.](#add-a-source-code-file-issues)

::: moniker-end

## <a name="next-steps"></a>Próximas etapas

> [!div class="nextstepaction"]
> [Compilar e executar um projeto C++](vscpp-step-2-build.md)

## <a name="troubleshooting-guide"></a>Guia de Solução de Problemas

Venha aqui para soluções para problemas comuns quando você cria seu primeiro projeto C++.

### <a name="create-your-app-project-issues"></a>Criar seu projeto de aplicativo: problemas

::: moniker range="msvc-160"

A caixa de diálogo **novo projeto** deve mostrar um modelo de **aplicativo de console** que tem marcas **C++** , **Windows** e **console** . Se você não vê-lo, há duas causas possíveis. Ele pode ser filtrado fora da lista ou pode não estar instalado. Primeiro, verifique as listas suspensas de filtros na parte superior da lista de modelos. Defina-os como **C++** , **Windows** e **console** . O modelo de **aplicativo de console** do C++ deve aparecer; caso contrário, o **desenvolvimento de desktop com carga de trabalho C++** não é instalado.

Para instalar o **desenvolvimento de desktop com C++** , você pode executar o instalador diretamente na caixa de diálogo **novo projeto** . Escolha o link **instalar mais ferramentas e recursos** na parte inferior da lista de modelos para iniciar o instalador. Se a caixa de diálogo **controle de conta de usuário** solicitar permissões, escolha **Sim** . No instalador, verifique se a opção **desenvolvimento de desktop com carga de trabalho C++** está marcada. Em seguida, escolha **Modificar** para atualizar a instalação do Visual Studio.

Se outro projeto com o mesmo nome já existir, escolha outro nome para o seu projeto. Ou exclua o projeto existente e tente novamente. Para excluir um projeto existente, exclua a pasta da solução (a pasta que contém o arquivo *HelloWorld. sln* ) no explorador de arquivos.

[Volte.](#create-your-app-project)

::: moniker-end

::: moniker range="msvc-150"

Se a caixa de diálogo **novo projeto** não mostrar uma entrada de **Visual C++** em **instalado** , sua cópia do Visual Studio provavelmente não terá o **desenvolvimento de desktop com** a carga de trabalho do C++ instalada. Você pode executar o instalador diretamente na caixa de diálogo **novo projeto** . Escolha o link **abrir instalador do Visual Studio** para iniciar o instalador novamente. Se a caixa de diálogo **controle de conta de usuário** solicitar permissões, escolha **Sim** . Atualize o instalador, se necessário. No instalador, verifique se a opção **desenvolvimento de desktop com carga de trabalho C++** está marcada e escolha **OK** para atualizar a instalação do Visual Studio.

::: moniker-end

::: moniker range="<=msvc-150"

Se outro projeto com o mesmo nome já existir, escolha outro nome para o seu projeto. Ou exclua o projeto existente e tente novamente. Para excluir um projeto existente, exclua a pasta da solução (a pasta que contém o arquivo *HelloWorld. sln* ) no explorador de arquivos.

[Volte.](#create-your-app-project)

### <a name="make-your-project-a-console-app-issues"></a>Tornar seu projeto um aplicativo de console: problemas

Se você não vir o **vinculador** listado em **Propriedades de configuração** , escolha **Cancelar** para fechar a caixa de diálogo páginas de **Propriedades** . Certifique-se de que o projeto **HelloWorld** esteja selecionado no **Gerenciador de soluções** antes de tentar novamente. Não selecione a solução **HelloWorld** ou outro item, em **Gerenciador de soluções** .

O controle suspenso não aparecerá na caixa de edição da propriedade **subsistema** até que você selecione a propriedade. Clique na caixa de edição para selecioná-la. Ou, você pode pressionar **Tab** para percorrer os controles da caixa de diálogo até que o **subsistema** seja realçado. Escolha o controle suspenso ou pressione **Alt + seta** para abri-lo.

[Voltar](#make-your-project-a-console-app)

### <a name="add-a-source-code-file-issues"></a>Adicionar um arquivo de código-fonte: problemas

Não há problema se você fornecer um nome diferente ao arquivo de código-fonte. No entanto, não adicione mais de um arquivo que contenha o mesmo código ao seu projeto.

Se você adicionou o tipo de arquivo errado ao seu projeto, como um arquivo de cabeçalho, exclua-o e tente novamente. Para excluir o arquivo, selecione-o em **Gerenciador de soluções** . Em seguida, pressione a tecla **delete** .

[Volte.](#add-a-source-code-file)

### <a name="add-code-to-the-source-file-issues"></a>Adicionar código ao arquivo de origem: problemas

Se você fechou acidentalmente a janela do editor de arquivo de código-fonte, você pode abri-la facilmente novamente. Para abri-lo, clique duas vezes em HelloWorld. cpp na janela **Gerenciador de soluções** .

Se os rabiscos vermelhos aparecerem em qualquer coisa no editor de código-fonte, verifique se o seu código corresponde ao exemplo em ortografia, pontuação e caso. O caso é significativo no código C++.

[Volte.](#add-code-to-the-source-file)

::: moniker-end

<iframe src="" height="0" width="0" frameborder="0" name="frameTarget" />
