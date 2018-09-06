---
title: Implantar um aplicativo do Visual C++ usando um projeto de instalação | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 36aad914fc9552cea06eabd0898fe33b9b09481e
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42605825"
---
# <a name="walkthrough-deploying-a-visual-c-application-by-using-a-setup-project"></a>Instruções passo a passo: implantando um aplicativo do Visual C++ usando um projeto de instalação
Descreve como usar um projeto de instalação para implantar um aplicativo do Visual C++.  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Você precisa dos seguintes componentes para concluir esta instrução passo a passo:  
  
-   Um computador com o Visual Studio 2012 instalado.  
  
-   Um computador adicional que não tenha as bibliotecas do Visual C++.  
  
### <a name="to-deploy-an-application-by-using-a-setup-project"></a>Para implantar um aplicativo usando um projeto de instalação  
  
1.  Use o **ApplicationWizard do MFC** para criar uma solução do Visual Studio. Para encontrar o assistente, na caixa de diálogo **Novo Projeto**, expanda o nó **Visual C++**, selecione **MFC**, selecione **Aplicativo MFC**, insira um nome para o projeto e, em seguida, clique em **OK**.  
  
2.  Altere a configuração da solução ativa para **Versão**. No menu **Build**, selecione **Configuration Manager**. Na caixa de diálogo **Configuration Manager**, selecione **Versão** na caixa suspensa **Configuração da solução ativa**.  
  
3.  Pressione F7 para compilar o aplicativo. Se preferir, no menu **Build**, clique em **Compilar Solução**. Isso permite que o projeto de instalação use a saída desse projeto de aplicativo MFC.  
  
4.  Se ainda não fez isso, baixe o ISLE (InstallShield Limited Edition), que é gratuito para desenvolvedores do Visual Studio e substitui a funcionalidade dos modelos de projeto no Visual Studio para instalação e implantação. Quando estiver conectado à Internet, abra a caixa de diálogo **Novo Projeto** escolhendo **Arquivo**, **Novo**, **Projeto** na barra de menus ou clicando com o botão direito do mouse na solução em **Gerenciador de Soluções** e escolhendo **Adicionar**, **Novo Projeto**. Expanda o nó **Outros Tipos de Projeto**, escolha **Habilitar o InstallShield Limited Edition** no nó **Instalação e Implantação** e siga as instruções exibidas. Depois de baixar, instalar e ativar o InstallShield Limited Edition, feche o Visual Studio e reabra-o.  
  
5.  Abra a caixa de diálogo **Novo Projeto** novamente, expanda o nó **Outros Tipos de Projeto** e escolha **Projeto do InstallShield Limited Edition** no nó **InstallShield Limited Edition**.  
  
6.  Siga as instruções do nó **Introdução** do projeto de instalação criado pelo modelo do InstallShield Limited Edition para adicionar uma referência de saída ao projeto MFC do Visual Studio.  
  
7.  Compile o projeto de instalação para criar o arquivo do instalador (setup.exe). Para fazer isso, clique com o botão direito do mouse no nó do projeto de instalação no **Gerenciador de Soluções** e selecione **Compilar**.  
  
     O InstallShield Limited Edition cria o arquivo de instalação na árvore do projeto de instalação (por padrão, ele pode estar localizado na subpasta Express\SingleImage\DiskImages\DISK1 do projeto de instalação).  
  
8.  Execute o programa de instalação em um segundo computador que não tenha as bibliotecas do Visual C++.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplos de implantação](../ide/deployment-examples.md)