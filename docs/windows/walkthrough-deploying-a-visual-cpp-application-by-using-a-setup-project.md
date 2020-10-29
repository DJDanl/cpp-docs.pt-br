---
title: Implantar um aplicativo do Visual C++ usando um projeto de instalação
ms.date: 04/25/2019
helpviewer_keywords:
- deployment for Visual C++
ms.assetid: 66735cda-8fe3-4211-a19a-2cf717a12a3f
ms.openlocfilehash: 4ded30695647b3e9377bc35227283f367816edfa
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92918844"
---
# <a name="walkthrough-deploying-a-visual-c-application-by-using-a-setup-project"></a>Instruções passo a passo: implantando um aplicativo do Visual C++ usando um projeto de instalação

Descreve como usar um projeto de instalação para implantar um aplicativo do Visual C++.

## <a name="prerequisites"></a>Pré-requisitos

Você precisará dos seguintes componentes para concluir este passo a passo:

- Um computador com o Visual Studio instalado.

- Um computador adicional que não tenha as bibliotecas do Visual C++.

## <a name="create-the-setup-project"></a>Criar o projeto de instalação

As instruções para criar um projeto de instalação variam dependendo da versão do Visual Studio instalada. Para ver a documentação da sua versão preferida do Visual Studio, use o controle seletor de **versão** . Ele é encontrado na parte superior do Sumário nesta página.

::: moniker range="=msvc-160"

### <a name="to-create-the-project-in-visual-studio-2019"></a>Para criar o projeto no Visual Studio 2019

1. Na barra de menus, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Criar um novo projeto** .

   ![Projeto de aplicativo MFC](media/vs2019-mfc-app-new-project.png "Novo aplicativo MFC")

1. Na parte superior do diálogo, digite `MFC` na caixa de pesquisa e escolha **aplicativo MFC** na lista de resultados. Se você não o vir, será necessário iniciar o programa Instalador do Visual Studio no menu Iniciar do Windows e clicar no bloco **carga de trabalho de desenvolvimento de Desktop C++** . Em **componentes individuais** , verifique se o componente MFC está marcado.

1. Na próxima página, insira um nome para o projeto e especifique o local do projeto, se desejado.

1. Escolha o botão **Criar** para criar o projeto do cliente. Quando o **Assistente de aplicativo do MFC** for exibido, aceite todos os padrões.

1. Altere a configuração da solução ativa para **Versão** . No menu **Build** , selecione **Configuration Manager** . Na caixa de diálogo **Configuration Manager** , selecione **Versão** na caixa suspensa **Configuração da solução ativa** . Clique em **Fechar** .

1. Pressione **Ctrl** + **Shift** + **B** para compilar o aplicativo. Se preferir, no menu **Build** , clique em **Compilar Solução** . A compilação do aplicativo permite que o projeto de instalação use a saída deste projeto de aplicativo MFC.

1. Se você ainda não fez isso, baixe a extensão de projetos Microsoft Visual Studio Installer. A extensão é gratuita para desenvolvedores do Visual Studio e adiciona a funcionalidade de modelos de projeto de instalação e de implantação ao Visual Studio. Quando você estiver conectado à Internet, no Visual Studio, escolha **extensões**  >  **gerenciar extensões** . Na caixa de diálogo **Extensões e Atualizações** , selecione a guia **Online** e digite *Projetos de Instalador do Microsoft Visual Studio* na caixa de pesquisa. Pressione **Enter** , selecione **Microsoft Visual Studio \<version> projetos do instalador** e clique em **baixar** . Escolha executar e instalar a extensão e, em seguida, reinicie o Visual Studio.

   ![Projeto de instalação do Visual Studio](media/vs2019-extension-dialog-installer-project.png "Nomear o projeto do cliente")

1. Na barra de menus do Visual Studio, escolha **Arquivo** > **Projetos e Soluções Recentes** e, em seguida, escolha reabrir seu projeto.

1. Na barra de menus, escolha **arquivo**  >  **novo**  >  **projeto** para abrir a caixa de diálogo **criar um novo projeto** . Na caixa de pesquisa, digite “Instalação” e, na lista de resultados, escolha **Projeto de instalação** .

1. Insira um nome para o projeto de instalação na caixa **Nome** . Na lista suspensa **Solução** , selecione **Adicionar à solução** . Escolha o botão **OK** para criar o projeto de instalação. Uma guia **Assistente de Arquivo (ProjectName)** é aberta na janela do editor.

::: moniker-end

::: moniker range="=msvc-150"

### <a name="to-create-the-project-in-visual-studio-2017"></a>Para criar o projeto no Visual Studio 2017

1. Criar um novo projeto. No menu **Arquivo** , aponte para **Novo** e clique em **Projeto** .

1. Use o **Assistente de aplicativo do MFC** para criar uma nova solução do Visual Studio. Para encontrar o assistente, na caixa de diálogo **Novo Projeto** , expanda o nó **Visual C++** , selecione **MFC** , selecione **Aplicativo MFC** , insira um nome para o projeto e, em seguida, clique em **OK** . Clique em **Concluir** .

   > [!NOTE]
   > Se o tipo de **aplicativo do MFC** estiver ausente, selecione **abrir instalador do Visual Studio** no painel esquerdo da caixa de diálogo **novo projeto** . Instale a opção localizada embaixo de **Desenvolvimento para desktop com C++** na seção de componentes **Opcional** , denominada **Visual C++ MFC for x86 e x64** .

1. Altere a configuração da solução ativa para **Versão** . No menu **Build** , selecione **Configuration Manager** . Na caixa de diálogo **Configuration Manager** , selecione **Versão** na caixa suspensa **Configuração da solução ativa** . Clique em **Fechar** .

1. Pressione **Ctrl** + **Shift** + **B** para compilar o aplicativo. Se preferir, no menu **Build** , clique em **Compilar Solução** . A compilação do aplicativo permite que o projeto de instalação use a saída deste projeto de aplicativo MFC.

1. Se você ainda não fez isso, baixe a extensão de projetos Microsoft Visual Studio Installer. A extensão é gratuita para desenvolvedores do Visual Studio e adiciona a funcionalidade de modelos de projeto de instalação e de implantação ao Visual Studio. Quando você estiver conectado à Internet, no Visual Studio, escolha **ferramentas**  >  **extensões e atualizações** . Na caixa de diálogo **Extensões e Atualizações** , selecione a guia **Online** e digite *Projetos de Instalador do Microsoft Visual Studio* na caixa de pesquisa. Pressione **Enter** , selecione **Microsoft Visual Studio \<version> projetos do instalador** e clique em **baixar** . Escolha executar e instalar a extensão e, em seguida, reinicie o Visual Studio.

1. Na barra de menus, escolha **Arquivo** > **Projetos e Soluções Recentes** e, em seguida, escolha reabrir seu projeto.

1. Na barra de menus, escolha **arquivo**  >  **novo**  >  **projeto** para abrir a caixa de diálogo **novo projeto** . Em seguida, no painel esquerdo da caixa de diálogo, expanda os **Installed**  >  **outros** nós de tipos de projeto instalados e selecione **instalador do Visual Studio** . No painel central, selecione **Projeto de instalação** .

1. Insira um nome para o projeto de instalação na caixa **Nome** . Na lista suspensa **Solução** , selecione **Adicionar à solução** . Escolha o botão **OK** para criar o projeto de instalação. Uma guia **Assistente de Arquivo (ProjectName)** é aberta na janela do editor.

::: moniker-end

::: moniker range="=msvc-140"

### <a name="to-create-the-project-in-visual-studio-2015"></a>Para criar o projeto no Visual Studio 2015

1. Criar um novo projeto. No menu **Arquivo** , aponte para **Novo** e clique em **Projeto** .

1. Use o **Assistente de aplicativo do MFC** para criar uma nova solução do Visual Studio. Para encontrar o assistente, na caixa de diálogo **Novo Projeto** , expanda o nó **Visual C++** , selecione **MFC** , selecione **Aplicativo MFC** , insira um nome para o projeto e, em seguida, clique em **OK** . Clique em **Concluir** .

   > [!NOTE]
   > Se o tipo de **aplicativo do MFC** estiver ausente, clique no botão Iniciar do Windows e digite **Adicionar remover programas** . Abra o programa na lista de resultados e, em seguida, localize a instalação do Microsoft Visual Studio 2015 na lista de programas instalados. Clique duas vezes nele e, em seguida, escolha **Modificar** e selecione o componente **MFC** embaixo de **Visual C++** .

1. Altere a configuração da solução ativa para **Versão** . No menu **Compilar** , selecione **Configuration Manager** . Na caixa de diálogo **Configuration Manager** , selecione **Versão** na caixa suspensa **Configuração da solução ativa** . Clique em **Fechar** .

1. Pressione **Ctrl** + **Shift** + **B** para compilar o aplicativo. Se preferir, no menu **Build** , clique em **Compilar Solução** . A compilação do aplicativo permite que o projeto de instalação use a saída deste projeto de aplicativo MFC.

1. Se você ainda não fez isso, baixe a extensão de projetos Microsoft Visual Studio Installer. A extensão é gratuita para desenvolvedores do Visual Studio e adiciona a funcionalidade de modelos de projeto de instalação e de implantação ao Visual Studio. Quando você estiver conectado à Internet, no Visual Studio, escolha **ferramentas**  >  **extensões e atualizações** . Na caixa de diálogo **Extensões e Atualizações** , selecione a guia **Online** e digite *Projetos de Instalador do Microsoft Visual Studio* na caixa de pesquisa. Pressione **Enter** , selecione **Microsoft Visual Studio \<version> projetos do instalador** e clique em **baixar** . Escolha executar e instalar a extensão e, em seguida, reinicie o Visual Studio.

1. Na barra de menus, escolha **Arquivo** > **Projetos e Soluções Recentes** e, em seguida, escolha reabrir seu projeto.

1. Na barra de menus, escolha **arquivo**  >  **novo**  >  **projeto** para abrir a caixa de diálogo **novo projeto** . Em seguida, no painel esquerdo da caixa de diálogo, expanda os **Installed**  >  **outros** nós de tipos de projeto instalados e selecione **instalador do Visual Studio** . No painel central, selecione **Projeto de instalação** .

1. Insira um nome para o projeto de instalação na caixa **Nome** . Na lista suspensa **Solução** , selecione **Adicionar à solução** . Escolha o botão **OK** para criar o projeto de instalação. Uma guia **Assistente de Arquivo (ProjectName)** é aberta na janela do editor.

::: moniker-end

## <a name="add-items-to-the-project"></a>Adicionar itens ao projeto

1. Clique com o botão direito do mouse no nó **Pasta do Aplicativo** e selecione **Adicionar** > **Saída do projeto** para abrir a caixa de diálogo **Adicionar grupo de saída do projeto** . Na caixa de diálogo, selecione **Saída Primária** e clique em **OK** . Um novo item chamado **Saída Primária do ProjectName (Ativa)** é exibido.

1. Clique com o botão direito do mouse no nó **Pasta do Aplicativo** e selecione **Adicionar** > **Assembly** para abrir a caixa de diálogo **Selecionar componente** . Selecione e adicione quaisquer DLLs obrigatórias exigidas pelo programa, conforme descrito pelo artigo [Determinando quais DLLs devem ser redistribuídas](determining-which-dlls-to-redistribute.md).

1. Selecione o item **Saída Primária do ProjectName (Ativa)** , clique com o botão direito do mouse em **Criar Atalho para a Saída Primária de ProjectName (Ativa)** . Um novo item chamado **Atalho para a Saída Primária de ProjectName (Ativa)** é exibido. É possível renomear item de atalho, em seguida, arrastar e soltar o item no nó **Menu de Programas do Usuário** à esquerda da janela.

1. Na barra de menus, escolha **criar**  >  **Configuration Manager** . Na tabela **Projeto** , na coluna **Build** , marque a caixa de seleção para o projeto de implantação. Clique em **Fechar** .

1. Na barra de menus, escolha **Compilar** compilar  >  **solução** para compilar o projeto MFC e o projeto de implantação.

1. Na pasta da solução, localize o programa setup.exe que foi criado com base no projeto de implantação. É possível copiar este arquivo (e o arquivo .msi) para instalar o aplicativo e seus arquivos de biblioteca necessários em outro computador. Execute o programa de instalação em um segundo computador que não tenha as bibliotecas do Visual C++.

## <a name="see-also"></a>Veja também

[Exemplos de implantação](deployment-examples.md)<br/>
