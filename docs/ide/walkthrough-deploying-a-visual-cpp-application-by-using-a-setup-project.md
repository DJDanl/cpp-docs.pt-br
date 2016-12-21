---
title: "Instru&#231;&#245;es passo a passo: implantando um aplicativo do Visual C++ usando um projeto de instala&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "implantação para Visual C++"
ms.assetid: 66735cda-8fe3-4211-a19a-2cf717a12a3f
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: implantando um aplicativo do Visual C++ usando um projeto de instala&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve como usar um projeto de configuração implantar um aplicativo Visual C\+\+.  
  
## Pré-requisitos  
 Para completar este passo\-a\-passo, são necessários os seguintes componentes:  
  
-   Um computador com [!INCLUDE[vs_dev11_long](../build/includes/vs_dev11_long_md.md)] instalado.  
  
-   Adicional um computador que não tenha as bibliotecas de Visual C\+\+.  
  
### Para implantar um aplicativo usando uma configuração projeto  
  
1.  Use **Aplicativo do MFCAssistente** para criar uma nova solução do Visual Studio.  Para localizar o assistente, da caixa de diálogo **Novo Projeto** , expanda o nó **Visual C\+\+** , selecione **MFC**, selecione **Aplicativo do MFC**, digite um nome para o projeto, e clique em **OK**.  
  
2.  Alterar a configuração de solução ativa a **Versão**.  No menu de **Compilar** , **Gerenciador de Configurações**.  Da caixa de diálogo **Gerenciador de Configurações** , **Versão** selecione o drop\-down de **Configuração da solução ativa** .  
  
3.  Pressione F7 para compilar o aplicativo.  Ou, no menu de **Compilar** , clique **Compilar solução**.  Isso permite que o projeto de instalação usar a saída do projeto de aplicativo MFC.  
  
4.  Se você ainda não fez isso, a edição limitada de InstallShield de download \(ILHA\), que está livre para desenvolvedores do Visual Studio e substitui a funcionalidade dos modelos de projeto no Visual Studio para a configuração e implantação.  Quando você estiver conectado à Internet, abrir a caixa de diálogo **Novo Projeto** escolhendo **Arquivo**, **Novo**, **Projeto** na barra de menus, ou clique com o botão direito do mouse na sua solução em **Gerenciador de Soluções** e selecione **Adicionar**, **Novo Projeto...** Expanda o nó de **Outros tipos de projetos** , escolha **Habilitar edição limitada de InstallShield** no nó de **Instalação e implantação** , e siga as instruções que aparecem.  Depois que você baixou, edição limitada instala e ativado de InstallShield, feche o Visual Studio e reabra\-o.  
  
5.  Abrir a caixa de diálogo **Novo Projeto** novamente, expanda o nó de **Outros tipos de projetos** , e escolha **Edição limitada Projeto de InstallShield** no nó de **Edição de InstallShield limitada** .  
  
6.  Siga as instruções no nó de **Introdução** do projeto de instalação criado pelo modelo de edição limitada de InstallShield para adicionar uma referência de saída ao projeto Visual Studio MFC.  
  
7.  Compilar o projeto de instalação criar o arquivo installer \(setup.exe\).  Para fazer isso, clique com o botão direito do mouse no nó de projeto de configuração em **Gerenciador de Soluções** e selecione **Compilar**.  
  
     O InstallShield Limited Edition cria o arquivo de configuração na árvore de projeto de instalação \(por padrão, pode ser localizada na subpasta Express\\SingleImage\\DiskImages\\DISK1 do projeto de instalação\).  
  
8.  Executar o programa de instalação em um segundo computador que não tenha as bibliotecas de Visual C\+\+.  
  
## Consulte também  
 [Exemplos de implantação](../ide/deployment-examples.md)