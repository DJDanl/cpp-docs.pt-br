---
title: 'Passo a passo: Implantando o programa (C++) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- deploying applications [C++], walkthroughs
- setup projects [C++]
- program deployments [C++]
- projects [C++], setup
- projects [C++], deploying programs
- application deployment [C++], walkthroughs
ms.assetid: 79e6cc4e-dced-419d-aaf7-d62d1367603f
caps.latest.revision: "17"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ce59dc7b767c8ff8e988ac7a765d3bb5f1cdfffc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="walkthrough-deploying-your-program-c"></a>Instruções passo a passo: implantando o programa (C++)
Agora que você criou seu aplicativo executando a anteriormente relacionada explicações passo a passo, que é listada na [usando o IDE do Visual Studio para desenvolvimento de área de trabalho do C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md), a última etapa é criar um instalador para que outros usuários possam Instale o programa em seus computadores. Para fazer isso, você adicionará um novo projeto à solução existente. A saída do novo projeto é um arquivo setup.exe que instalará o aplicativo em outro computador.  
  
 Este passo a passo mostra como usar o Windows Installer para implantar seu aplicativo. Você também pode usar o ClickOnce para implantar um aplicativo. Para obter mais informações, consulte [implantação de ClickOnce para aplicativos Visual C++](../ide/clickonce-deployment-for-visual-cpp-applications.md). Para obter mais informações sobre a implantação em geral, consulte [implantação de aplicativos, serviços e componentes](/visualstudio/deployment/deploying-applications-services-and-components).  
  
## <a name="prerequisites"></a>Pré-requisitos  
  
-   Este passo a passo pressupõe que você entender os conceitos básicos da linguagem C++.  
  
-   Ele também pressupõe que você tenha concluído as orientações relacionadas anteriormente listados na [usando o IDE do Visual Studio para desenvolvimento de área de trabalho do C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).  
  
-   Este passo a passo não pode ser concluída em edições Express do Visual Studio.  
  
-   Se você ainda não o fez, baixe o InstallShield Limited Edition (ilha), conforme descrito nas etapas neste artigo. Ilha está livre para desenvolvedores do Visual Studio e substitui a funcionalidade de instalação e implantação de modelos de projeto em edições anteriores do Visual Studio.  
  
### <a name="to-install-the-isle-setup-and-deployment-project-template"></a>Para instalar o modelo de projeto de instalação e implantação da Ilha  
  
1.  Quando você está conectado à Internet, na barra de menus, escolha **arquivo**, **novo**, **projeto** para abrir o **novo projeto** caixa de diálogo.  
  
2.  No painel esquerdo da caixa de diálogo, expanda o **instalado**, **modelos**, e **outros tipos de projetos** nós e, em seguida, selecione **instalação e implantação**. No painel central, selecione **habilitar o InstallShield Limited Edition** e, em seguida, escolha o **Okey** botão.  
  
3.  Siga as instruções para instalar o InstallShield Limited Edition para Visual Studio (ilha).  
  
4.  Depois de ter baixado, instalado e ativado ilha, feche o Visual Studio e abra-o novamente.  
  
5.  Na barra de menus, escolha **arquivo**, **soluções e projetos recentes**e, em seguida, escolha o **jogo** solução para reabri-la.  
  
### <a name="to-create-a-setup-project-and-install-your-program"></a>Para criar um projeto de instalação e instalar o programa  
  
1.  Altere a configuração de solução ativa para versão. Na barra de menus, escolha **Build**, **Configuration Manager**. No **do Configuration Manager** caixa de diálogo de **configuração de solução ativa** lista suspensa, selecione **versão**. Escolha o **fechar** botão para salvar a configuração.  
  
2.  Na barra de menus, escolha **arquivo**, **novo**, **projeto** para abrir o **novo projeto** caixa de diálogo.  
  
3.  No painel esquerdo da caixa de diálogo, expanda o **instalado**, **modelos**, e **outros tipos de projetos** nós e, em seguida, selecione **instalação e implantação**. No painel central, selecione **projeto do InstallShield Limited Edition**.  
  
4.  Insira um nome para o projeto de instalação no **nome** caixa. Para este exemplo, digite **jogo instalador**. No **solução** lista suspensa, selecione **adicionar à solução**. Escolha o **Okey** botão para criar o projeto de instalação. Um **Assistente de projeto (instalador de jogo)** guia é exibida na janela do editor.  
  
5.  Na parte inferior da **Assistente de projeto (instalador de jogo)** guia, escolha o **informações do aplicativo** link.  
  
6.  Sobre o **informações do aplicativo** , especifique o nome da sua empresa como deseja que ele apareça no instalador. Você pode usar seu próprio nome da empresa ou para este exemplo, use **Contoso**. Especifique o nome do aplicativo; Neste exemplo, especificar **jogo**. Especifique o endereço da web sua empresa ou para este exemplo, use **http://www.contoso.com**.  
  
7.  Na parte inferior da **Assistente de projeto (instalador de jogo)** guia, escolha o **instalação entrevista** link.  
  
8.  No **instalação entrevista** página em **você deseja exibir uma caixa de diálogo do contrato de licença**, selecione o **não** botão de opção. Em **você deseja solicitar aos usuários inserir o nome da sua empresa e o nome de usuário**, selecione o **não** botão de opção.  
  
9. No **Solution Explorer**, expanda o **jogo instalador** de projeto, expanda o **organizar sua instalação** nó e, em seguida, abra o **asinformaçõesgerais** página.  
  
10. No **informações gerais (instalador de jogo)** guia na janela do editor, especifique um **ID do criador da marca**, por exemplo, **regid.2012 12.com.Contoso**.  
  
11. No **Solution Explorer**, no **jogo instalador** de projeto, expanda o **especificar dados de aplicativo** nó e, em seguida, abra o **arquivos** página.  
  
12. No **arquivos (instalador de jogo)** guia na janela do editor, em **arquivos do computador de origem**, abra o menu de atalho para **saída primária de jogo** e escolha **Cópia**.  
  
13. Abrir um menu de atalho no espaço no **nome** coluna **arquivos do computador de destino**e escolha **colar**. Um novo item denominado **Game.Primary saída** é exibida.  
  
14. Em **Solution Explorer**, sob o **especificar dados de aplicativo** nó, abra o **redistribuíveis** página.  
  
15. Sobre o **redistribuíveis (instalador de jogo)** guia na janela do editor, selecione o **CRT 11.0 de Visual C++ (x86)** caixa de seleção.  
  
16. Na barra de menus, escolha **criar**, **compilar solução** para compilar o projeto do jogo e o projeto do instalador do jogo.  
  
17. Na pasta da solução, localize o programa setup.exe que foi criado a partir do projeto do instalador do jogo e, em seguida, execute-o para instalar o aplicativo de jogo em seu computador. Você pode copiar esse arquivo para instalar o aplicativo e seus arquivos de biblioteca em outro computador.  
  
18. Você pode definir várias opções no projeto de instalação para atender às suas necessidades. Para obter mais informações, em **Solution Explorer**, no **jogo instalador** projeto, abra o **Introdução** página e, em seguida, escolha a tecla F1 para abrir a biblioteca de ajuda ilha.  
  
## <a name="next-steps"></a>Próximas etapas  
 **Anterior:** [passo a passo: depurando um projeto (C++)](../ide/walkthrough-debugging-a-project-cpp.md)  
  
## <a name="see-also"></a>Consulte também  
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Compilando programas do C/C++](../build/building-c-cpp-programs.md)  
 [Implantando aplicativos de área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md)