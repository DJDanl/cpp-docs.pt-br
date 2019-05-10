---
title: Implantar um aplicativo do Visual C++ usando um projeto de instalação
ms.date: 04/25/2019
helpviewer_keywords:
- deployment for Visual C++
ms.assetid: 66735cda-8fe3-4211-a19a-2cf717a12a3f
ms.openlocfilehash: 6829e917ed0a0e27bea7f42eb9bcfb2b9ad5d2e1
ms.sourcegitcommit: 18d3b1e9cdb4fc3a76f7a650c31994bdbd2bde64
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/29/2019
ms.locfileid: "64877376"
---
# <a name="walkthrough-deploying-a-visual-c-application-by-using-a-setup-project"></a>Passo a passo: Implantação de um aplicativo em Visual C++ usando um projeto de instalação

Descreve como usar um projeto de instalação para implantar um aplicativo do Visual C++.

## <a name="prerequisites"></a>Pré-requisitos

Você precisa dos seguintes componentes para concluir esta instrução passo a passo:

- Um computador com o Visual Studio instalado.

- Um computador adicional que não tenha as bibliotecas do Visual C++.

## <a name="create-the-setup-project"></a>Criar o projeto de instalação

Instruções para criar um projeto de instalação variam, dependendo de qual versão do Visual Studio que você instalou. Verifique se que você tem o seletor de versão no canto superior esquerdo definido para a versão correta.

::: moniker range="=vs-2019"

### <a name="to-create-the-project-in-visual-studio-2019"></a>Para criar o projeto no Visual Studio de 2019

1. Na barra de menus, escolha **arquivo** > **New** > **projeto** para abrir o **criar um novo projeto** caixa de diálogo.

   ![Projeto de aplicativo do MFC](media/vs2019-mfc-app-new-project.png "MFC novo aplicativo")

1. Na parte superior da caixa de diálogo, digite `MFC` na pesquisa de caixa e, em seguida, escolha **aplicativo MFC** na lista de resultados. Se você não vê-lo, você precisará iniciar o programa instalador do Visual Studio a partir do menu Iniciar do Windows e clique no  **C++ carga de trabalho de desenvolvimento de área de trabalho** lado a lado. Sob **componentes individuais**, certifique-se de que o componente MFC é verificado.

1. Na próxima página, insira um nome para o projeto e especifique o local do projeto, se desejado.

1. Escolha o **criar** botão para criar o projeto do cliente. Quando o **Assistente de aplicativo MFC** for exibida, aceite todos os padrões.

1. Altere a configuração da solução ativa para **Versão**. No menu **Build**, selecione **Configuration Manager**. Na caixa de diálogo **Configuration Manager**, selecione **Versão** na caixa suspensa **Configuração da solução ativa**. Clique em **Fechar**.

1. Pressione **Ctrl**+**Shift**+**B** para criar o aplicativo. Se preferir, no menu **Build**, clique em **Compilar Solução**. A compilação do aplicativo permite que o projeto de instalação use a saída deste projeto de aplicativo MFC.

1. Se você ainda não o fez, baixe a extensão de Projetos do Instalador do Microsoft Visual Studio. A extensão é gratuita para desenvolvedores do Visual Studio e adiciona a funcionalidade de modelos de projeto de instalação e de implantação ao Visual Studio. Quando você está conectado à Internet, no Visual Studio, escolha **extensões** > **gerenciar extensões**. Na caixa de diálogo **Extensões e Atualizações**, selecione a guia **Online** e digite *Projetos de Instalador do Microsoft Visual Studio* na caixa de pesquisa. Pressione **Enter**, selecione **Microsoft Visual Studio \<versão > projetos do instalador**e clique em **baixar**. Escolha executar e instalar a extensão e, em seguida, reinicie o Visual Studio.

   ![Projeto de instalação do Visual Studio](media/vs2019-extension-dialog-installer-project.png "Nomeie o projeto de cliente")

1. Na barra de menus do Visual Studio, escolha **arquivo** > **projetos e soluções recentes**e, em seguida, optar por reabrir o projeto.

1. Na barra de menus, escolha **arquivo** > **New** > **projeto** para abrir o **criar um novo projeto** caixa de diálogo. Na caixa de pesquisa, digite "Setup" e na lista de resultados, escolha **projeto de instalação**.

1. Insira um nome para o projeto de instalação na caixa **Nome**. Na lista suspensa **Solução**, selecione **Adicionar à solução**. Escolha o botão **OK** para criar o projeto de instalação. Uma guia **Assistente de Arquivo (ProjectName)** é aberta na janela do editor.

::: moniker-end

::: moniker range="=vs-2017"

### <a name="to-create-the-project-in-visual-studio-2017"></a>Para criar o projeto no Visual Studio 2017

1. Crie um novo projeto. No menu **Arquivo**, aponte para **Novo** e clique em **Projeto**.

1. Use o **Assistente de aplicativo MFC** para criar uma nova solução do Visual Studio. Para encontrar o assistente, na caixa de diálogo **Novo Projeto**, expanda o nó **Visual C++**, selecione **MFC**, selecione **Aplicativo MFC**, insira um nome para o projeto e, em seguida, clique em **OK**. Clique em **Finalizar**.

   > [!NOTE]
   > Se o **aplicativo do MFC** tipo está ausente, selecione **abrir instalador do Visual Studio** no painel esquerdo do **novo projeto** caixa de diálogo. Instale a opção localizada embaixo de **Desenvolvimento para desktop com C++** na seção de componentes **Opcional**, denominada **Visual C++ MFC for x86 e x64**.

1. Altere a configuração da solução ativa para **Versão**. No menu **Build**, selecione **Configuration Manager**. Na caixa de diálogo **Configuration Manager**, selecione **Versão** na caixa suspensa **Configuração da solução ativa**. Clique em **Fechar**.

1. Pressione **Ctrl**+**Shift**+**B** para criar o aplicativo. Se preferir, no menu **Build**, clique em **Compilar Solução**. A compilação do aplicativo permite que o projeto de instalação use a saída deste projeto de aplicativo MFC.

1. Se você ainda não o fez, baixe a extensão de Projetos do Instalador do Microsoft Visual Studio. A extensão é gratuita para desenvolvedores do Visual Studio e adiciona a funcionalidade de modelos de projeto de instalação e de implantação ao Visual Studio. Quando você está conectado à Internet, no Visual Studio, escolha **Ferramentas** > **Extensões e Atualizações**. Na caixa de diálogo **Extensões e Atualizações**, selecione a guia **Online** e digite *Projetos de Instalador do Microsoft Visual Studio* na caixa de pesquisa. Pressione **Enter**, selecione **Microsoft Visual Studio \<versão > projetos do instalador**e clique em **baixar**. Escolha executar e instalar a extensão e, em seguida, reinicie o Visual Studio.

1. Na barra de menus, escolha **arquivo** > **projetos e soluções recentes**e, em seguida, optar por reabrir o projeto.

1. Na barra de menus, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Novo Projeto**. Em seguida, no painel esquerdo da caixa de diálogo, expanda os nós **Instalados** > **Outros Tipos de Projeto** e selecione **Instalador do Visual Studio**. No painel central, selecione **Projeto de instalação**.

1. Insira um nome para o projeto de instalação na caixa **Nome**. Na lista suspensa **Solução**, selecione **Adicionar à solução**. Escolha o botão **OK** para criar o projeto de instalação. Uma guia **Assistente de Arquivo (ProjectName)** é aberta na janela do editor.

::: moniker-end

::: moniker range="=vs-2015"

### <a name="to-create-the-project-in-visual-studio-2015"></a>Para criar o projeto no Visual Studio 2015

1. Crie um novo projeto. No menu **Arquivo**, aponte para **Novo** e clique em **Projeto**.

1. Use o **Assistente de aplicativo MFC** para criar uma nova solução do Visual Studio. Para encontrar o assistente, na caixa de diálogo **Novo Projeto**, expanda o nó **Visual C++**, selecione **MFC**, selecione **Aplicativo MFC**, insira um nome para o projeto e, em seguida, clique em **OK**. Clique em **Finalizar**.

   > [!NOTE]
   > Se o **aplicativo do MFC** tipo está ausente, clique no botão Iniciar do Windows e digite **adicionar ou remover programas**. Abra o programa na lista de resultados e, em seguida, localize a instalação do Microsoft Visual Studio 2015 na lista de programas instalados. Clique duas vezes nele e, em seguida, escolha **Modificar** e selecione o componente **MFC** embaixo de **Visual C++**.

1. Altere a configuração da solução ativa para **Versão**. Dos **construir** menu, selecione **Configuration Manager**. Na caixa de diálogo **Configuration Manager**, selecione **Versão** na caixa suspensa **Configuração da solução ativa**. Clique em **Fechar**.

1. Pressione **Ctrl**+**Shift**+**B** para criar o aplicativo. Se preferir, no menu **Build**, clique em **Compilar Solução**. A compilação do aplicativo permite que o projeto de instalação use a saída deste projeto de aplicativo MFC.

1. Se você ainda não o fez, baixe a extensão de Projetos do Instalador do Microsoft Visual Studio. A extensão é gratuita para desenvolvedores do Visual Studio e adiciona a funcionalidade de modelos de projeto de instalação e de implantação ao Visual Studio. Quando você está conectado à Internet, no Visual Studio, escolha **Ferramentas** > **Extensões e Atualizações**. Na caixa de diálogo **Extensões e Atualizações**, selecione a guia **Online** e digite *Projetos de Instalador do Microsoft Visual Studio* na caixa de pesquisa. Pressione **Enter**, selecione **Microsoft Visual Studio \<versão > projetos do instalador**e clique em **baixar**. Escolha executar e instalar a extensão e, em seguida, reinicie o Visual Studio.

1. Na barra de menus, escolha **arquivo** > **projetos e soluções recentes**e, em seguida, optar por reabrir o projeto.

1. Na barra de menus, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Novo Projeto**. Em seguida, no painel esquerdo da caixa de diálogo, expanda os nós **Instalados** > **Outros Tipos de Projeto** e selecione **Instalador do Visual Studio**. No painel central, selecione **Projeto de instalação**.

1. Insira um nome para o projeto de instalação na caixa **Nome**. Na lista suspensa **Solução**, selecione **Adicionar à solução**. Escolha o botão **OK** para criar o projeto de instalação. Uma guia **Assistente de Arquivo (ProjectName)** é aberta na janela do editor.

::: moniker-end

## <a name="add-items-to-the-project"></a>Adicionar itens ao projeto

1. Clique com o botão direito do mouse no nó **Pasta do aplicativo** e selecione **Adicionar** > **Saída do projeto** para abrir a caixa de diálogo **Adicionar grupo de saída do projeto**. Na caixa de diálogo, selecione **Saída Primária** e clique em **OK**. Um novo item chamado **Saída Primária do ProjectName (Ativa)** é exibido.

1. Clique com o botão direito do mouse no nó **Pasta do Aplicativo** e selecione **Adicionar** > **Assembly** para abrir a caixa de diálogo **Selecionar componente**. Selecione e adicione quaisquer DLLs obrigatórias exigidas pelo programa, conforme descrito pelo artigo [Determinando quais DLLs devem ser redistribuídas](determining-which-dlls-to-redistribute.md).

1. Selecione o item **Saída Primária do ProjectName (Ativa)**, clique com o botão direito do mouse em **Criar Atalho para a Saída Primária de ProjectName (Ativa)**. Um novo item chamado **Atalho para a Saída Primária de ProjectName (Ativa)** é exibido. É possível renomear item de atalho, em seguida, arrastar e soltar o item no nó **Menu de Programas do Usuário** à esquerda da janela.

1. Na barra de menus, escolha **Build** > **Gerenciador de Configurações**. Na tabela **Projeto**, na coluna **Build**, marque a caixa de seleção para o projeto de implantação. Clique em **Fechar**.

1. Na barra de menus, escolha **Compilar** > **Compilar Solução** para criar o projeto MFC e o projeto de implantação.

1. Na pasta da solução, localize o programa setup.exe que foi criado com base no projeto de implantação. É possível copiar este arquivo (e o arquivo .msi) para instalar o aplicativo e seus arquivos de biblioteca necessários em outro computador. Execute o programa de instalação em um segundo computador que não tenha as bibliotecas do Visual C++.

## <a name="see-also"></a>Consulte também

[Exemplos de implantação](deployment-examples.md)<br/>
