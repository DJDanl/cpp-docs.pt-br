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
ms.openlocfilehash: 454507a3a3f33b43af0e50c25dab6703aa75a56b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="walkthrough-deploying-a-visual-c-application-by-using-a-setup-project"></a>Instruções passo a passo: implantando um aplicativo do Visual C++ usando um projeto de instalação
Descreve como usar um projeto de instalação para implantar um aplicativo do Visual C++.  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Você precisa dos seguintes componentes para concluir esta instrução passo a passo:  
  
-   Um computador com [!INCLUDE[vs_dev11_long](../build/includes/vs_dev11_long_md.md)] instalado.  
  
-   Um computador adicional que não tenha as bibliotecas do Visual C++.  
  
### <a name="to-deploy-an-application-by-using-a-setup-project"></a>Para implantar um aplicativo usando um projeto de instalação  
  
1.  Use o **ApplicationWizard MFC** para criar uma nova solução do Visual Studio. Para localizar o Assistente do **novo projeto** caixa de diálogo caixa, expanda o **Visual C++** nó, selecione **MFC**, selecione **aplicativo MFC**, insira um nome do projeto e, em seguida, clique em **Okey**.  
  
2.  Alterar a configuração de solução ativa para **versão**. Do **criar** menu, selecione **do Configuration Manager**. Do **do Configuration Manager** caixa de diálogo, selecione **versão** do **configuração de solução ativa** caixa suspensa.  
  
3.  Pressione F7 para compilar o aplicativo. Ou, no **criar** menu, clique em **compilar solução**. Isso permite que o projeto de instalação usar a saída deste projeto de aplicativo do MFC.  
  
4.  Se você ainda não o fez, baixe o InstallShield Limited Edition (ilha), que é gratuito para desenvolvedores do Visual Studio e substitui a funcionalidade dos modelos de projeto no Visual Studio para instalação e implantação. Quando você está conectado à Internet, abra o **novo projeto** caixa de diálogo, escolhendo **arquivo**, **novo**, **projeto** na barra de menus, ou por clicando duas vezes em sua solução de **Solution Explorer** e escolhendo **adicionar**, **novo projeto**. Expanda o **outros tipos de projetos** nó, escolha **habilitar o InstallShield Limited Edition** no **instalação e implantação** nó e siga as instruções que aparecem. Depois de ter baixado, instalado e ativado o InstallShield Limited Edition, feche o Visual Studio e abra-o novamente.  
  
5.  Abra o **novo projeto** caixa de diálogo novamente, expanda o **outros tipos de projetos** nó e escolha **projeto do InstallShield Limited Edition** no  **O InstallShield Limited Edition** nó.  
  
6.  Siga as instruções no **Introdução** nó do projeto de instalação criado pelo modelo InstallShield Limited Edition para adicionar uma referência de saída ao seu projeto MFC do Visual Studio.  
  
7.  Compile o projeto de instalação para criar o arquivo do instalador (setup.exe). Para fazer isso, clique com botão direito no nó do projeto de instalação no **Solution Explorer** e selecione **criar**.  
  
     O InstallShield Limited Edition cria o arquivo de instalação na árvore do projeto de instalação (por padrão, ele pode ser localizado na subpasta Express\SingleImage\DiskImages\DISK1 do projeto de instalação).  
  
8.  Execute o programa de instalação em um segundo computador que não tenha as bibliotecas do Visual C++.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplos de implantação](../ide/deployment-examples.md)