---
title: "Configura&#231;&#245;es do aplicativo, Assistente de DLL MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.appwiz.mfc.dll.appset"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente de DLL MFC, configurações de aplicativo"
ms.assetid: 0a96b94f-ae36-4975-951b-c9ffb3def21c
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Configura&#231;&#245;es do aplicativo, Assistente de DLL MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Use esta página do assistente da DLL MFC para criar e adicionar recursos básicos para um novo projeto da DLL MFC.  
  
## Tipo DLL  
 Selecione o tipo de DLL que deseja criar.  
  
 **Regular DLL using shared MFC DLL**  
 Selecione esta opção para vincular a biblioteca MFC ao programa como uma DLL compartilhado.  Usando esta opção, você não pode compartilhar objetos MFC entre o DLL e o aplicativo de chamada.  O programa faz chamadas na biblioteca MFC em tempo de execução.  Essa opção reduz os requisitos de disco e de memória do programa se é composto de vários arquivos de execução que usam a biblioteca MFC.  O Win32 e programas MFC podem chamar funções no DLL.  Você deverá redistribuir a DLL MFC com esse tipo de projeto.  
  
 **Regular DLL with MFC statically linked**  
 Selecione esta opção para vincular estaticamente seu programa à biblioteca MFC em tempo de compilação.  O Win32 e programas MFC podem chamar funções no DLL.  Quando esta opção aumentar o tamanho do programa, não precisará redistribuir a DLL MFC com esse tipo de projeto.  Você não pode compartilhar objetos MFC entre o DLL e o aplicativo de chamada.  
  
 **MFC extension DLL**  
 Selecione esta opção para que seu programa para fazer em tempo de execução chama a biblioteca MFC, e se você quiser compartilhar objetos MFC entre o DLL e o aplicativo de chamada.  Essa opção reduz os requisitos de disco e de memória do programa, se é composto de vários arquivos executáveis que usam a biblioteca MFC.  Somente os programas de MFC podem chamar funções no DLL.  Você deverá redistribuir a DLL MFC com esse tipo de projeto.  
  
## Recursos adicionais  
 Selecione se o DLL MFC deve oferecer suporte à automação e se deve dar suporte aos soquetes do windows.  
  
 **Automação**  
 Selecione **Automação** para permitir que o programa manipular os objetos implementados em outro programa.  Selecione **Automação** também expõe o programa a outros clientes de automação.  Consulte [Automação](../../mfc/automation.md) para obter mais informações.  
  
 **Windows sockets**  
 Selecione esta opção para indicar que o programa oferece suporte aos soquetes do windows.  Soquetes do windows que permitem escrever programas que se comunicam pelas redes TCP\/IP.  
  
 Quando o DLL MFC com suporte de soquetes do windows é criado, [CWinApp::InitInstance](../Topic/CWinApp::InitInstance.md) inicializa o suporte para soquetes e o arquivo de cabeçalho StdAfx.h MFC inclui AfxSock.h.  
  
## Consulte também  
 [Assistente de DLL MFC](../../mfc/reference/mfc-dll-wizard.md)   
 [Criando um projeto DLL MFC](../../mfc/reference/creating-an-mfc-dll-project.md)