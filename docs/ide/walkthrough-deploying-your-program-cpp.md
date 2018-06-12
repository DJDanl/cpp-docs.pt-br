---
title: 'Passo a passo: Implantando o programa (C++) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- deploying applications [C++], walkthroughs
- setup projects [C++]
- program deployments [C++]
- projects [C++], setup
- projects [C++], deploying programs
- application deployment [C++], walkthroughs
ms.assetid: 79e6cc4e-dced-419d-aaf7-d62d1367603f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e1753c63673b9dd083e2b690788801bd467938c3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33335530"
---
# <a name="walkthrough-deploying-your-program-c"></a>Instruções passo a passo: implantando o programa (C++)
Agora que você criou seu aplicativo concluindo os passos a passos anteriormente relacionados, listados em [Usando o IDE do Visual Studio para desenvolvimento para desktop com C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md), a última etapa é criar um instalador, de modo que outros usuários possam instalar o programa em seus computadores. Para fazer isso, você adicionará um novo projeto à solução existente. A saída desse novo projeto é um arquivo setup.exe que instalará o aplicativo em outro computador.  
  
 Este passo a passo mostra como usar o Windows Installer para implantar seu aplicativo. Use também o ClickOnce para implantar um aplicativo. Para obter mais informações, confira [Implantação do ClickOnce para aplicativos do Visual C++](../ide/clickonce-deployment-for-visual-cpp-applications.md). Para obter mais informações sobre a implantação em geral, confira [Implantando aplicativos, serviços e componentes](/visualstudio/deployment/deploying-applications-services-and-components).  
  
## <a name="prerequisites"></a>Pré-requisitos  
  
-   Este passo a passo pressupõe que você conheça os princípios básicos da linguagem C++.  
  
-   Também pressupõe que você tenha concluído os passos a passos relacionados anteriores listados em [Usando o IDE do Visual Studio para desenvolvimento para desktop com C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).  
  
-   Este passo a passo não pode ser concluído nas edições Express do Visual Studio.  
  
-   Se você ainda não fez isso, baixe o ISLE (InstallShield Limited Edition), conforme descrito nas etapas adiante neste artigo. O ISLE é gratuito para desenvolvedores do Visual Studio e substitui a funcionalidade de modelos de projeto de instalação e implantação em edições anteriores do Visual Studio.  
  
### <a name="to-install-the-isle-setup-and-deployment-project-template"></a>Para instalar o modelo de projeto de instalação e implantação do ISLE  
  
1.  Quando estiver conectado à Internet, na barra de menus, escolha **Arquivo**, **Novo**, **Projeto** para abrir a caixa de diálogo **Novo Projeto**.  
  
2.  No painel esquerdo da caixa de diálogo, expanda os nós **Instalados**, **Modelos** e **Outros Tipos de Projeto** e, em seguida, selecione **Instalação e Implantação**. No painel central, selecione **Habilitar InstallShield Limited Edition** e, em seguida, escolha no botão **OK**.  
  
3.  Siga as instruções para instalar o ISLE (InstallShield Limited Edition) para Visual Studio.  
  
4.  Depois de baixar, instalar e ativar o ISLE, feche o Visual Studio e reabra-o.  
  
5.  Na barra de menus, escolha **Arquivo**, **Projetos e Soluções Recentes** e, em seguida, escolha a solução **Game** para reabri-la.  
  
### <a name="to-create-a-setup-project-and-install-your-program"></a>Para criar um projeto de instalação e instalar o programa  
  
1.  Altere a configuração da solução ativa para Versão. Na barra de menus, escolha **Build**, **Configuration Manager**. Na caixa de diálogo **Configuration Manager**, na lista suspensa **Configuração da solução ativa**, selecione **Versão**. Escolha o botão **Fechar** para salvar a configuração.  
  
2.  Na barra de menus, escolha **Arquivo**, **Novo**, **Projeto** para abrir a caixa de diálogo **Novo Projeto**.  
  
3.  No painel esquerdo da caixa de diálogo, expanda os nós **Instalados**, **Modelos** e **Outros Tipos de Projeto** e, em seguida, selecione **Instalação e Implantação**. No painel central, selecione **Projeto do InstallShield Limited Edition**.  
  
4.  Insira um nome para o projeto de instalação na caixa **Nome**. Para este exemplo, insira **Game Installer**. Na lista suspensa **Solução**, selecione **Adicionar à solução**. Escolha o botão **OK** para criar o projeto de instalação. Uma guia **Assistente de Projeto (Game Installer)** é exibida na janela do editor.  
  
5.  Na parte inferior da guia **Assistente de Projeto (Game Installer)**, escolha o link **Informações do Aplicativo**.  
  
6.  Na página **Informações do Aplicativo**, especifique o nome de sua empresa como deseja que ele seja exibido no instalador. Use seu próprio nome de empresa ou, para este exemplo, use **Contoso**. Especifique o nome do aplicativo; neste exemplo, especifique **Game**. Especifique o endereço web de sua empresa ou, para este exemplo, use **http://www.contoso.com**.  
  
7.  Na parte inferior da guia **Assistente de Projeto (Game Installer)**, escolha o link **Entrevista de Instalação**.  
  
8.  Na página **Entrevista de Instalação**, em **Deseja exibir uma Caixa de Diálogo do Contrato de Licença?**, selecione o botão de opção **Não**. Em **Deseja solicitar aos usuários que insiram seu Nome de Empresa e seu Nome de Usuário?**, selecione o botão de opção **Não**.  
  
9. No **Gerenciador de Soluções**, expanda o projeto **Game Installer**, expanda o nó **Organizar a Instalação** e, em seguida, abra a página **Informações Gerais**.  
  
10. Na guia **Informações Gerais (Game Installer)** na janela do editor, especifique uma **ID do Criador da Marcação**, por exemplo, **regid.2012-12.com.Contoso**.  
  
11. No **Gerenciador de Soluções**, no projeto **Game Installer**, expanda o nó **Especificar Dados de Aplicativos** e, em seguida, abra a página **Arquivos**.  
  
12. Na guia **Arquivos (Game Installer)** na janela do editor, em **Arquivos do computador de origem**, abra o menu de atalho de **Saída Primária de Game** e escolha **Copiar**.  
  
13. Abra um menu de atalho no espaço da coluna **Nome** em **Arquivos do computador de destino** e escolha **Colar**. Um novo item chamado **Saída Game.Primary** é exibido.  
  
14. No **Gerenciador de Soluções**, no nó **Especificar Dados de Aplicativos**, abra a página **Pacotes Redistribuíveis**.  
  
15. Na guia **Pacotes Redistribuíveis (Game Installer)** na janela do editor, marque a caixa de seleção **CRT do Visual C++ 11.0 (x86)**.  
  
16. Na barra de menus, escolha **Build**, **Compilar Solução**, para compilar o projeto Game e o projeto Game Installer.  
  
17. Na pasta da solução, localize o programa setup.exe que foi compilado com base no projeto Game Installer e, em seguida, execute-o para instalar o aplicativo Game no computador. Copie esse arquivo para instalar o aplicativo e seus arquivos de biblioteca necessários em outro computador.  
  
18. Defina várias opções no projeto de instalação de acordo com suas necessidades. Para obter mais informações, no **Gerenciador de Soluções**, no projeto **Game Installer**, abra a página **Introdução** e, em seguida, escolha a tecla F1 para abrir a biblioteca da Ajuda do ISLE.  
  
## <a name="next-steps"></a>Próximas etapas  
 **Anterior:** [Passo a passo: Depurando um projeto (C++)](../ide/walkthrough-debugging-a-project-cpp.md)  
  
## <a name="see-also"></a>Consulte também  
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Compilando programas do C/C++](../build/building-c-cpp-programs.md)  
 [Implantando aplicativos da área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md)