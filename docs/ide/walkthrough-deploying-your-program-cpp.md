---
title: 'Passo a passo: Implantando o programa (C++)'
ms.date: 09/14/2018
helpviewer_keywords:
- deploying applications [C++], walkthroughs
- setup projects [C++]
- program deployments [C++]
- projects [C++], setup
- projects [C++], deploying programs
- application deployment [C++], walkthroughs
ms.assetid: 79e6cc4e-dced-419d-aaf7-d62d1367603f
ms.openlocfilehash: 051ef3aa8c691a2191d25183ef96f17b557a47c1
ms.sourcegitcommit: 9e85c2e029d06b4c1c69837437468718b4d54908
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/18/2019
ms.locfileid: "57820202"
---
# <a name="walkthrough-deploying-your-program-c"></a>Passo a passo: Implantando o programa (C++)

Agora que você criou seu aplicativo concluindo os passos a passos anteriormente relacionados, listados em [Usando o IDE do Visual Studio para desenvolvimento para desktop com C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md), a última etapa é criar um instalador, de modo que outros usuários possam instalar o programa em seus computadores. Para o instalador, você adicionará um novo projeto à solução existente. A saída desse novo projeto é um arquivo setup.exe que instalará o aplicativo em outro computador.

Este passo a passo mostra como usar o Windows Installer para implantar seu aplicativo. Use também o ClickOnce para implantar um aplicativo. Para obter mais informações, confira [Implantação do ClickOnce para aplicativos do Visual C++](../ide/clickonce-deployment-for-visual-cpp-applications.md). Para obter mais informações sobre a implantação em geral, confira [Implantando aplicativos, serviços e componentes](/visualstudio/deployment/deploying-applications-services-and-components).

## <a name="prerequisites"></a>Pré-requisitos

- Este passo a passo pressupõe que você conhece os princípios básicos da linguagem C++.

- Também pressupõe que você tenha concluído os passos a passos relacionados anteriores listados em [Usando o IDE do Visual Studio para Desenvolvimento para Desktop com C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).

- O passo a passo não pode ser concluído nas edições Express do Visual Studio.

- Se você ainda não o fez, baixe a extensão de Projetos do Instalador do Microsoft Visual Studio, conforme descrito nas etapas adicionais posteriormente. A extensão é gratuita para desenvolvedores do Visual Studio e adiciona a funcionalidade de modelos de projeto de instalação e de implantação ao Visual Studio.

### <a name="to-install-the-visual-studio-setup-and-deployment-project-template"></a>Para instalar a configuração do Visual Studio e o modelo do projeto de implantação

1. Quando você está conectado à Internet, no Visual Studio, escolha **Ferramentas** > **Extensões e Atualizações**.

1. Em **Extensões e Atualizações**, selecione a guia **Online** e digite *Projetos de Instalador do Microsoft Visual Studio* na caixa de pesquisa. Pressione **Enter**, selecione **Microsoft Visual Studio versão \<> Projetos do Instalador** e clique em **Baixar**.

1. Escolha instalar a extensão e, em seguida, reinicie o Visual Studio.

1. Na barra de menus, escolha **Arquivo** > **Projetos e Soluções Recentes** e, em seguida, escolha a solução **Game** para reabri-la.

### <a name="to-create-a-setup-project-and-install-your-program"></a>Para criar um projeto de instalação e instalar o programa

1. Altere a configuração da solução ativa para Versão. Na barra de menus, escolha **Build** > **Gerenciador de Configurações**. Na caixa de diálogo **Configuration Manager**, na lista suspensa **Configuração da solução ativa**, selecione **Versão**. Escolha o botão **Fechar** para salvar a configuração.

1. Na barra de menus, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Novo Projeto**.

1. No painel esquerdo da caixa de diálogo, expanda os nós **Instalados** > **Outros Tipos de Projeto** e, em seguida, selecione **Instalador do Visual Studio**. No painel central, selecione **Projeto de instalação**.

1. Insira um nome para o projeto de instalação na caixa **Nome**. Para este exemplo, insira *Game Installer*. Na lista suspensa **Solução**, selecione **Adicionar à solução**. Escolha o botão **OK** para criar o projeto de instalação. Uma guia **Assistente de Arquivo (Game Installer)** é exibida na janela do editor.

1. Clique com o botão direito do mouse no nó **Pasta do aplicativo** e selecione **Adicionar** > **Saída do projeto** para abrir a caixa de diálogo **Adicionar grupo de saída do projeto**.

1. Na caixa de diálogo, selecione **Saída Primária** e clique em **OK**. Um novo item chamado **Saída Primária do Jogo (Ativa)** é exibido.

1. Selecione o item **Saída Primária de Game (Ativa)**, clique com o botão direito do mouse em **Criar Atalho para a Saída Primária de Game (Ativa)**. Um novo item chamado **Atalho para a Saída Primária de Game (Ativa)** é exibido.

1. Renomeie o item de atalho para *Jogo* e, em seguida, arraste e solte o item no nó **Menu de Programas do Usuário** à esquerda da janela.

1. No **Gerenciador de Soluções**, selecione o projeto **Game Installer** e escolha **Exibir** > **Janela Propriedades** ou pressione **F4** para abrir a janela **Propriedades**.

1. Especifique mais detalhes como desejar que eles sejam exibidos no instalador.  Por exemplo, use *Contoso* para **Fabricante**, *Game Installer* para o **Nome do Produto** e *http\://www.contoso.com* para **SupportUrl**.

1. Na barra de menus, escolha **Build** > **Gerenciador de Configurações**. Na tabela **Projeto**, na coluna **Build**, marque a caixa de **Game Installer**. Clique em **Fechar**.

1. Na barra de menus, escolha **Compilar** > **Compilar solução** para criar o projeto Game e o projeto Game Installer.

1. Na pasta da solução, localize o programa setup.exe que foi compilado com base no projeto Game Installer e, em seguida, execute-o para instalar o aplicativo Game no computador. É possível copiar esse arquivo (e o GameInstaller.msi) para instalar o aplicativo e seus arquivos de biblioteca necessários em outro computador.

## <a name="next-steps"></a>Próximas etapas

**Anterior:** [Passo a passo: Depurando um projeto (C++)](../ide/walkthrough-debugging-a-project-cpp.md)<br/>

## <a name="see-also"></a>Consulte também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Sistemas de Compilação e Projetos](../build/projects-and-build-systems-cpp.md)<br/>
[Implantando aplicativos da área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md)<br/>
