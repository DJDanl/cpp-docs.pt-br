---
title: 'Passo a passo: Implantando o programa (C++)'
ms.date: 05/14/2019
helpviewer_keywords:
- deploying applications [C++], walkthroughs
- setup projects [C++]
- program deployments [C++]
- projects [C++], setup
- projects [C++], deploying programs
- application deployment [C++], walkthroughs
ms.assetid: 79e6cc4e-dced-419d-aaf7-d62d1367603f
ms.openlocfilehash: 4232edd10b71c70097002511ef4ee663e67d6598
ms.sourcegitcommit: fc1de63a39f7fcbfe2234e3f372b5e1c6a286087
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/15/2019
ms.locfileid: "66182656"
---
# <a name="walkthrough-deploying-your-program-c"></a>Passo a passo: Implantando o programa (C++)

Agora que você criou seu aplicativo concluindo os passos a passos anteriormente relacionados, a última etapa é criar um instalador, de modo que outros usuários possam instalar o programa nos computadores deles. Para o instalador, você adicionará um novo projeto à solução existente. A saída desse novo projeto é um arquivo setup.exe que instalará o aplicativo em outro computador.

Este passo a passo mostra como usar o Windows Installer para implantar seu aplicativo. Use também o ClickOnce para implantar um aplicativo. Para obter mais informações, confira [Implantação do ClickOnce para aplicativos do Visual C++](../windows/clickonce-deployment-for-visual-cpp-applications.md). Para obter mais informações sobre a implantação em geral, confira [Implantando aplicativos, serviços e componentes](/visualstudio/deployment/deploying-applications-services-and-components).

## <a name="prerequisites"></a>Pré-requisitos

- Este passo a passo pressupõe que você conhece os princípios básicos da linguagem C++.

- Também pressupõe que você tenha concluído os passos a passos relacionados anteriores listados em [Usando o IDE do Visual Studio para Desenvolvimento para Desktop com C++](using-the-visual-studio-ide-for-cpp-desktop-development.md).

- O passo a passo não pode ser concluído nas edições Express do Visual Studio.

## <a name="install-the-visual-studio-setup-and-deployment-project-template"></a>Instalar o modelo de projeto de implantação e de instalação do Visual Studio

As etapas a seguir variam dependendo da versão do Visual Studio que você instalou. Verifique se o seletor de versão no canto superior esquerdo desta página está definido corretamente.

::: moniker range="vs-2019"

### <a name="to-install-the-setup-and-deployment-project-template-for-visual-studio-2019"></a>Para instalar o modelo de projeto de implantação e de instalação do Visual Studio 2019

1. Se você ainda não o fez, baixe a extensão de Projetos do Instalador do Microsoft Visual Studio. A extensão é gratuita para desenvolvedores do Visual Studio e adiciona a funcionalidade de modelos de projeto de instalação e de implantação ao Visual Studio. Quando você está conectado à Internet, no Visual Studio, escolha **Extensões** > **Gerenciar Extensões**. Na caixa de diálogo **Extensões e Atualizações**, selecione a guia **Online** e digite *Projetos de Instalador do Microsoft Visual Studio* na caixa de pesquisa. Pressione **Enter**, selecione **Microsoft Visual Studio versão \<> Projetos do Instalador** e clique em **Baixar**. Escolha executar e instalar a extensão e, em seguida, reinicie o Visual Studio.

1. Na barra de menus do Visual Studio, escolha **Arquivo** > **Projetos e Soluções Recentes** e, em seguida, escolha reabrir seu projeto.

1. Na barra de menus, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Criar um projeto**. Na caixa de pesquisa, digite “Instalação” e, na lista de resultados, escolha **Projeto de instalação**.

1. Insira um nome para o projeto de instalação na caixa **Nome**. Na lista suspensa **Solução**, selecione **Adicionar à solução**. Escolha o botão **OK** para criar o projeto de instalação. Uma guia **Assistente de Arquivo (ProjectName)** é aberta na janela do editor.

1. Clique com o botão direito do mouse no nó **Pasta do Aplicativo** e selecione **Adicionar** > **Saída do projeto** para abrir a caixa de diálogo **Adicionar grupo de saída do projeto**.

1. Na caixa de diálogo, selecione **Saída Primária** e clique em **OK**. Um novo item chamado **Saída Primária do Jogo (Ativa)** é exibido.

1. Selecione o item **Saída Primária de Game (Ativa)** , clique com o botão direito do mouse em **Criar Atalho para a Saída Primária de Game (Ativa)** . Um novo item chamado **Atalho para a Saída Primária de Game (Ativa)** é exibido.

1. Renomeie o item de atalho para *Jogo* e, em seguida, arraste e solte o item no nó **Menu de Programas do Usuário** à esquerda da janela.

1. No **Gerenciador de Soluções**, selecione o projeto **Instalador do Jogo** e escolha **Exibir** > **Janela Propriedades** ou pressione **F4** para abrir a janela **Propriedades**.

1. Especifique mais detalhes como desejar que eles sejam exibidos no instalador.  Por exemplo, use *Contoso* para **Fabricante**, *Game Installer* para o **Nome do Produto** e *http\://www.contoso.com* para **SupportUrl**.

1. Na barra de menus, escolha **Build** > **Gerenciador de Configurações**. Na tabela **Projeto**, na coluna **Build**, marque a caixa de **Game Installer**. Clique em **Fechar**.

1. Na barra de menus, escolha **Compilar** > **Compilar Solução** para compilar o projeto Jogo e o projeto Instalador do Jogo.

1. Na pasta da solução, localize o programa setup.exe que foi compilado com base no projeto Game Installer e, em seguida, execute-o para instalar o aplicativo Game no computador. É possível copiar esse arquivo (e o GameInstaller.msi) para instalar o aplicativo e seus arquivos de biblioteca necessários em outro computador.

::: moniker-end

::: moniker range="<=vs-2017"

### <a name="to-install-the-setup-and-deployment-project-template-for-visual-studio-2017-and-earlier"></a>Para instalar o modelo de projeto de implantação e de instalação do Visual Studio 2017 e versões anteriores

1. Quando você está conectado à Internet, no Visual Studio, escolha **Ferramentas** > **Extensões e Atualizações**.

1. Em **Extensões e Atualizações**, selecione a guia **Online** e digite *Projetos de Instalador do Microsoft Visual Studio* na caixa de pesquisa. Pressione **Enter**, selecione **Microsoft Visual Studio versão \<> Projetos do Instalador** e clique em **Baixar**.

1. Escolha instalar a extensão e, em seguida, reinicie o Visual Studio.

1. Na barra de menus, escolha **Arquivo** > **Projetos e Soluções Recentes** e, em seguida, escolha a solução **Jogo** para reabri-la.

### <a name="to-create-a-setup-project-and-install-your-program"></a>Para criar um projeto de instalação e instalar o programa

1. Altere a configuração da solução ativa para Versão. Na barra de menus, escolha **Build** > **Gerenciador de Configurações**. Na caixa de diálogo **Configuration Manager**, na lista suspensa **Configuração da solução ativa**, selecione **Versão**. Escolha o botão **Fechar** para salvar a configuração.

1. Na barra de menus, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Novo Projeto**.

1. No painel esquerdo da caixa de diálogo, expanda os nós **Instalados** > **Outros Tipos de Projeto** e, em seguida, selecione **Instalador do Visual Studio**. No painel central, selecione **Projeto de instalação**.

1. Insira um nome para o projeto de instalação na caixa **Nome**. Para este exemplo, insira *Game Installer*. Na lista suspensa **Solução**, selecione **Adicionar à solução**. Escolha o botão **OK** para criar o projeto de instalação. Uma guia **Assistente de Arquivo (Game Installer)** é exibida na janela do editor.

1. Clique com o botão direito do mouse no nó **Pasta do Aplicativo** e selecione **Adicionar** > **Saída do projeto** para abrir a caixa de diálogo **Adicionar grupo de saída do projeto**.

1. Na caixa de diálogo, selecione **Saída Primária** e clique em **OK**. Um novo item chamado **Saída Primária do Jogo (Ativa)** é exibido.

1. Selecione o item **Saída Primária de Game (Ativa)** , clique com o botão direito do mouse em **Criar Atalho para a Saída Primária de Game (Ativa)** . Um novo item chamado **Atalho para a Saída Primária de Game (Ativa)** é exibido.

1. Renomeie o item de atalho para *Jogo* e, em seguida, arraste e solte o item no nó **Menu de Programas do Usuário** à esquerda da janela.

1. No **Gerenciador de Soluções**, selecione o projeto **Instalador do Jogo** e escolha **Exibir** > **Janela Propriedades** ou pressione **F4** para abrir a janela **Propriedades**.

1. Especifique mais detalhes como desejar que eles sejam exibidos no instalador.  Por exemplo, use *Contoso* para **Fabricante**, *Game Installer* para o **Nome do Produto** e *http\://www.contoso.com* para **SupportUrl**.

1. Na barra de menus, escolha **Build** > **Gerenciador de Configurações**. Na tabela **Projeto**, na coluna **Build**, marque a caixa de **Game Installer**. Clique em **Fechar**.

1. Na barra de menus, escolha **Compilar** > **Compilar Solução** para compilar o projeto Jogo e o projeto Instalador do Jogo.

1. Na pasta da solução, localize o programa setup.exe que foi compilado com base no projeto Game Installer e, em seguida, execute-o para instalar o aplicativo Game no computador. É possível copiar esse arquivo (e o GameInstaller.msi) para instalar o aplicativo e seus arquivos de biblioteca necessários em outro computador.

::: moniker-end

## <a name="next-steps"></a>Próximas etapas

**Anterior:** [Passo a passo: Depurando um projeto (C++)](walkthrough-debugging-a-project-cpp.md)<br/>

## <a name="see-also"></a>Consulte também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Sistemas de Compilação e Projetos](../build/projects-and-build-systems-cpp.md)<br/>
[Implantando aplicativos da área de trabalho](../windows/deploying-native-desktop-applications-visual-cpp.md)<br/>
