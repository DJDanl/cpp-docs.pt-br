---
title: Implantar um aplicativo do Visual C++ usando um projeto de instalação | Microsoft Docs
ms.custom: ''
ms.date: 09/17/2018
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- deployment for Visual C++
ms.assetid: 66735cda-8fe3-4211-a19a-2cf717a12a3f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ea46400f0c04b62a35a676e94b7a023620c13a50
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50069640"
---
# <a name="walkthrough-deploying-a-visual-c-application-by-using-a-setup-project"></a>Instruções passo a passo: implantando um aplicativo do Visual C++ usando um projeto de instalação

Descreve como usar um projeto de instalação para implantar um aplicativo do Visual C++.

## <a name="prerequisites"></a>Pré-requisitos

Você precisa dos seguintes componentes para concluir esta instrução passo a passo:

- Um computador com o Visual Studio instalado.

- Um computador adicional que não tenha as bibliotecas do Visual C++.

### <a name="to-deploy-an-application-by-using-a-setup-project"></a>Para implantar um aplicativo usando um projeto de instalação

1. Crie um novo projeto. No menu **Arquivo**, aponte para **Novo** e clique em **Projeto**.

1. Use o **ApplicationWizard do MFC** para criar uma solução do Visual Studio. Para encontrar o assistente, na caixa de diálogo **Novo Projeto**, expanda o nó **Visual C++**, selecione **MFC**, selecione **Aplicativo MFC**, insira um nome para o projeto e, em seguida, clique em **OK**. Clique em **Finalizar**.

   > [!NOTE]
   > Se o tipo **Aplicativo MFC** estiver ausente:<br/>
   > **Visual Studio 2017**: selecione **Abrir instalador do Visual Studio** no painel esquerdo da caixa de diálogo **Novo Projeto**. Instale a opção localizada embaixo de **Desenvolvimento para desktop com C++** na seção de componentes **Opcional**, denominada **Visual C++ MFC for x86 e x64**.<br/>
   > **Visual Studio 2015**: clique no botão Iniciar do Windows e digite **Adicionar ou remover programas**. Abra o programa na lista de resultados e, em seguida, localize a instalação do Microsoft Visual Studio 2015 na lista de programas instalados. Clique duas vezes nele e, em seguida, escolha **Modificar** e selecione o componente **MFC** embaixo de **Visual C++**.

1. Altere a configuração da solução ativa para **Versão**. No menu **Build**, selecione **Configuration Manager**. Na caixa de diálogo **Configuration Manager**, selecione **Versão** na caixa suspensa **Configuração da solução ativa**. Clique em **Fechar**.

1. Pressione **Ctrl**+**Shift**+**B** para criar o aplicativo. Se preferir, no menu **Build**, clique em **Compilar Solução**. A compilação do aplicativo permite que o projeto de instalação use a saída deste projeto de aplicativo MFC.

1. Se você ainda não o fez, baixe a extensão de Projetos do Instalador do Microsoft Visual Studio. A extensão é gratuita para desenvolvedores do Visual Studio e adiciona a funcionalidade de modelos de projeto de instalação e de implantação ao Visual Studio. Quando você está conectado à Internet, no Visual Studio, escolha **Ferramentas** > **Extensões e Atualizações**. Na caixa de diálogo **Extensões e Atualizações**, selecione a guia **Online** e digite *Projetos de Instalador do Microsoft Visual Studio* na caixa de pesquisa. Pressione **Enter**, selecione **Microsoft Visual Studio versão \<> Projetos do Instalador** e clique em **Baixar**. Escolha executar e instalar a extensão e, em seguida, reinicie o Visual Studio.

1. Na barra de menus, escolha **Arquivo** > **Projetos e Soluções Recentes** e, em seguida, escolha reabrir seu projeto.

1. Na barra de menus, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Novo Projeto**. Em seguida, no painel esquerdo da caixa de diálogo, expanda os nós **Instalados** > **Outros Tipos de Projeto** e selecione **Instalador do Visual Studio**. No painel central, selecione **Projeto de instalação**.

1. Insira um nome para o projeto de instalação na caixa **Nome**. Na lista suspensa **Solução**, selecione **Adicionar à solução**. Escolha o botão **OK** para criar o projeto de instalação. Uma guia **Assistente de Arquivo (ProjectName)** é aberta na janela do editor.

1. Clique com o botão direito do mouse no nó **Pasta do aplicativo** e selecione **Adicionar** > **Saída do projeto** para abrir a caixa de diálogo **Adicionar grupo de saída do projeto**. Na caixa de diálogo, selecione **Saída Primária** e clique em **OK**. Um novo item chamado **Saída Primária do ProjectName (Ativa)** é exibido.

1. Clique com o botão direito do mouse no nó **Pasta do Aplicativo** e selecione **Adicionar** > **Assembly** para abrir a caixa de diálogo **Selecionar componente**. Selecione e adicione quaisquer DLLs obrigatórias exigidas pelo programa, conforme descrito pelo artigo [Determinando quais DLLs devem ser redistribuídas](determining-which-dlls-to-redistribute.md).

1. Selecione o item **Saída Primária do ProjectName (Ativa)**, clique com o botão direito do mouse em **Criar Atalho para a Saída Primária de ProjectName (Ativa)**. Um novo item chamado **Atalho para a Saída Primária de ProjectName (Ativa)** é exibido. É possível renomear item de atalho, em seguida, arrastar e soltar o item no nó **Menu de Programas do Usuário** à esquerda da janela.

1. Na barra de menus, escolha **Build** > **Gerenciador de Configurações**. Na tabela **Projeto**, na coluna **Build**, marque a caixa de seleção para o projeto de implantação. Clique em **Fechar**.

1. Na barra de menus, escolha **Compilar** > **Compilar Solução** para criar o projeto MFC e o projeto de implantação.

1. Na pasta da solução, localize o programa setup.exe que foi criado com base no projeto de implantação. É possível copiar este arquivo (e o arquivo .msi) para instalar o aplicativo e seus arquivos de biblioteca necessários em outro computador. Execute o programa de instalação em um segundo computador que não tenha as bibliotecas do Visual C++.

## <a name="see-also"></a>Consulte também

[Exemplos de implantação](deployment-examples.md)<br/>
