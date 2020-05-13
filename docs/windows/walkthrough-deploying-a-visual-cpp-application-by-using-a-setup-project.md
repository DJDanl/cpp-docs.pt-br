---
title: Implantar um aplicativo do Visual C++ usando um projeto de instalação
ms.date: 04/25/2019
helpviewer_keywords:
- deployment for Visual C++
ms.assetid: 66735cda-8fe3-4211-a19a-2cf717a12a3f
ms.openlocfilehash: 8a1242140154c5a0123d71b83983fae20cab5d7e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374346"
---
# <a name="walkthrough-deploying-a-visual-c-application-by-using-a-setup-project"></a>Instruções passo a passo: implantando um aplicativo do Visual C++ usando um projeto de instalação

Descreve como usar um projeto de instalação para implantar um aplicativo do Visual C++.

## <a name="prerequisites"></a>Pré-requisitos

Você precisará dos seguintes componentes para concluir este passo a passo:

- Um computador com o Visual Studio instalado.

- Um computador adicional que não tenha as bibliotecas do Visual C++.

## <a name="create-the-setup-project"></a>Criar o projeto de configuração

As instruções para criar um projeto de configuração variam dependendo da versão do Visual Studio que você instalou. Para ver a documentação da sua versão preferida do Visual Studio, use o controle do seletor **de versão.** É encontrado no topo da tabela de conteúdo nesta página.

::: moniker range="=vs-2019"

### <a name="to-create-the-project-in-visual-studio-2019"></a>Para criar o projeto no Visual Studio 2019

1. Na barra de menus, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Criar um novo projeto**.

   ![Projeto de Aplicativo MFC](media/vs2019-mfc-app-new-project.png "Novo aplicativo MFC")

1. Na parte superior da `MFC` caixa de diálogo, digite a caixa de pesquisa e escolha o **Aplicativo MFC** na lista de resultados. Se você não vê-lo, você precisará iniciar o programa Visual Studio Installer a partir do menu Windows Start e clicar no bloco **de carga de trabalho C++ Desktop Development.** Em **Componentes Individuais,** certifique-se de que o componente MFC seja verificado.

1. Na página seguinte, digite um nome para o projeto e especifique o local do projeto se desejar.

1. Escolha o botão **Criar** para criar o projeto do cliente. Quando o **Assistente de Aplicativo MFC** aparecer, aceite todos os padrões.

1. Altere a configuração da solução ativa para **Versão**. No menu **Build**, selecione **Configuration Manager**. Na caixa de diálogo **Configuration Manager**, selecione **Versão** na caixa suspensa **Configuração da solução ativa**. Clique em **Fechar**.

1. Pressione o Shift**B** + **ctrl**+**Shift**para construir o aplicativo. Se preferir, no menu **Build**, clique em **Compilar Solução**. A compilação do aplicativo permite que o projeto de instalação use a saída deste projeto de aplicativo MFC.

1. Se você ainda não fez isso, baixe a extensão Microsoft Visual Studio Installer Projects. A extensão é gratuita para desenvolvedores do Visual Studio e adiciona a funcionalidade de modelos de projeto de instalação e de implantação ao Visual Studio. Quando estiver conectado à Internet, no Visual Studio, escolha **Extensões** > **Gerenciar extensões**. Na caixa de diálogo **Extensões e Atualizações**, selecione a guia **Online** e digite *Projetos de Instalador do Microsoft Visual Studio* na caixa de pesquisa. Pressione **Enter**, selecione **a versão do Microsoft Visual Studio \<> Installer Projects**e clique em **Baixar**. Escolha executar e instalar a extensão e, em seguida, reinicie o Visual Studio.

   ![Projeto de configuração do Visual Studio](media/vs2019-extension-dialog-installer-project.png "Nomeie o projeto do cliente")

1. Na barra de menus do Visual Studio, escolha **Arquivo** > **Projetos e Soluções Recentes** e, em seguida, escolha reabrir seu projeto.

1. Na barra de menu, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo Criar um **novo projeto.** Na caixa de pesquisa, digite “Instalação” e, na lista de resultados, escolha **Projeto de instalação**.

1. Insira um nome para o projeto de instalação na caixa **Nome**. Na lista suspensa **Solução**, selecione **Adicionar à solução**. Escolha o botão **OK** para criar o projeto de instalação. Uma guia **Assistente de Arquivo (ProjectName)** é aberta na janela do editor.

::: moniker-end

::: moniker range="=vs-2017"

### <a name="to-create-the-project-in-visual-studio-2017"></a>Para criar o projeto no Visual Studio 2017

1. Criar um novo projeto. No menu **Arquivo** , aponte para **Novo**e clique em **Projeto**.

1. Use o **Assistente de Aplicativos do MFC** para criar uma nova solução do Visual Studio. Para encontrar o assistente, na caixa de diálogo **Novo Projeto**, expanda o nó **Visual C++**, selecione **MFC**, selecione **Aplicativo MFC**, insira um nome para o projeto e, em seguida, clique em **OK**. Clique em **Concluir**.

   > [!NOTE]
   > Se o tipo **de aplicativo MFC** estiver faltando, selecione **Abrir instalador do estúdio visual** no painel esquerdo da caixa de diálogo Novo **Projeto.** Instale a opção localizada embaixo de **Desenvolvimento para desktop com C++** na seção de componentes **Opcional**, denominada **Visual C++ MFC for x86 e x64**.

1. Altere a configuração da solução ativa para **Versão**. No menu **Build**, selecione **Configuration Manager**. Na caixa de diálogo **Configuration Manager**, selecione **Versão** na caixa suspensa **Configuração da solução ativa**. Clique em **Fechar**.

1. Pressione o Shift**B** + **ctrl**+**Shift**para construir o aplicativo. Se preferir, no menu **Build**, clique em **Compilar Solução**. A compilação do aplicativo permite que o projeto de instalação use a saída deste projeto de aplicativo MFC.

1. Se você ainda não fez isso, baixe a extensão Microsoft Visual Studio Installer Projects. A extensão é gratuita para desenvolvedores do Visual Studio e adiciona a funcionalidade de modelos de projeto de instalação e de implantação ao Visual Studio. Quando estiver conectado à Internet, no Visual Studio, escolha**Extensões e Atualizações de** **Ferramentas** > . Na caixa de diálogo **Extensões e Atualizações**, selecione a guia **Online** e digite *Projetos de Instalador do Microsoft Visual Studio* na caixa de pesquisa. Pressione **Enter**, selecione **a versão do Microsoft Visual Studio \<> Installer Projects**e clique em **Baixar**. Escolha executar e instalar a extensão e, em seguida, reinicie o Visual Studio.

1. Na barra de menus, escolha **Arquivo** > **Projetos e Soluções Recentes** e, em seguida, escolha reabrir seu projeto.

1. Na barra de menus, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Novo Projeto.** Em seguida, no painel esquerdo da caixa de diálogo, expanda os ádeos**de outros tipos** de projeto **instalados** > e selecione **Visual Studio Installer**. No painel central, selecione **Projeto de instalação**.

1. Insira um nome para o projeto de instalação na caixa **Nome**. Na lista suspensa **Solução**, selecione **Adicionar à solução**. Escolha o botão **OK** para criar o projeto de instalação. Uma guia **Assistente de Arquivo (ProjectName)** é aberta na janela do editor.

::: moniker-end

::: moniker range="=vs-2015"

### <a name="to-create-the-project-in-visual-studio-2015"></a>Para criar o projeto no Visual Studio 2015

1. Criar um novo projeto. No menu **Arquivo** , aponte para **Novo**e clique em **Projeto**.

1. Use o **Assistente de Aplicativos do MFC** para criar uma nova solução do Visual Studio. Para encontrar o assistente, na caixa de diálogo **Novo Projeto**, expanda o nó **Visual C++**, selecione **MFC**, selecione **Aplicativo MFC**, insira um nome para o projeto e, em seguida, clique em **OK**. Clique em **Concluir**.

   > [!NOTE]
   > Se o tipo **de aplicativo MFC** estiver faltando, clique no botão Iniciar do Windows e **digite Adicionar programas**de remoção . Abra o programa na lista de resultados e, em seguida, localize a instalação do Microsoft Visual Studio 2015 na lista de programas instalados. Clique duas vezes nele e, em seguida, escolha **Modificar** e selecione o componente **MFC** embaixo de **Visual C++**.

1. Altere a configuração da solução ativa para **Versão**. No menu **Build,** selecione **Gerenciador de configuração**. Na caixa de diálogo **Configuration Manager**, selecione **Versão** na caixa suspensa **Configuração da solução ativa**. Clique em **Fechar**.

1. Pressione o Shift**B** + **ctrl**+**Shift**para construir o aplicativo. Se preferir, no menu **Build**, clique em **Compilar Solução**. A compilação do aplicativo permite que o projeto de instalação use a saída deste projeto de aplicativo MFC.

1. Se você ainda não fez isso, baixe a extensão Microsoft Visual Studio Installer Projects. A extensão é gratuita para desenvolvedores do Visual Studio e adiciona a funcionalidade de modelos de projeto de instalação e de implantação ao Visual Studio. Quando estiver conectado à Internet, no Visual Studio, escolha**Extensões e Atualizações de** **Ferramentas** > . Na caixa de diálogo **Extensões e Atualizações**, selecione a guia **Online** e digite *Projetos de Instalador do Microsoft Visual Studio* na caixa de pesquisa. Pressione **Enter**, selecione **a versão do Microsoft Visual Studio \<> Installer Projects**e clique em **Baixar**. Escolha executar e instalar a extensão e, em seguida, reinicie o Visual Studio.

1. Na barra de menus, escolha **Arquivo** > **Projetos e Soluções Recentes** e, em seguida, escolha reabrir seu projeto.

1. Na barra de menus, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Novo Projeto.** Em seguida, no painel esquerdo da caixa de diálogo, expanda os ádeos**de outros tipos** de projeto **instalados** > e selecione **Visual Studio Installer**. No painel central, selecione **Projeto de instalação**.

1. Insira um nome para o projeto de instalação na caixa **Nome**. Na lista suspensa **Solução**, selecione **Adicionar à solução**. Escolha o botão **OK** para criar o projeto de instalação. Uma guia **Assistente de Arquivo (ProjectName)** é aberta na janela do editor.

::: moniker-end

## <a name="add-items-to-the-project"></a>Adicione itens ao projeto

1. Clique com o botão direito do mouse no nó **Pasta do Aplicativo** e selecione **Adicionar** > **Saída do projeto** para abrir a caixa de diálogo **Adicionar grupo de saída do projeto**. Na caixa de diálogo, selecione **Saída Primária** e clique em **OK**. Um novo item chamado **Saída Primária do ProjectName (Ativa)** é exibido.

1. Clique com o botão direito do mouse no nó **Pasta do Aplicativo** e selecione **Adicionar** > **Assembly** para abrir a caixa de diálogo **Selecionar componente**. Selecione e adicione quaisquer DLLs obrigatórias exigidas pelo programa, conforme descrito pelo artigo [Determinando quais DLLs devem ser redistribuídas](determining-which-dlls-to-redistribute.md).

1. Selecione o item **Saída Primária do ProjectName (Ativa)**, clique com o botão direito do mouse em **Criar Atalho para a Saída Primária de ProjectName (Ativa)**. Um novo item chamado **Atalho para a Saída Primária de ProjectName (Ativa)** é exibido. É possível renomear item de atalho, em seguida, arrastar e soltar o item no nó **Menu de Programas do Usuário** à esquerda da janela.

1. Na barra de menu, escolha **Build** > **Configuration Manager**. Na tabela **Projeto**, na coluna **Build**, marque a caixa de seleção para o projeto de implantação. Clique em **Fechar**.

1. Na barra de menus, escolha **Build** > **Build Solution** para construir o projeto MFC e o projeto de implantação.

1. Na pasta da solução, localize o programa setup.exe que foi criado com base no projeto de implantação. É possível copiar este arquivo (e o arquivo .msi) para instalar o aplicativo e seus arquivos de biblioteca necessários em outro computador. Execute o programa de instalação em um segundo computador que não tenha as bibliotecas do Visual C++.

## <a name="see-also"></a>Confira também

[Exemplos de implantação](deployment-examples.md)<br/>
