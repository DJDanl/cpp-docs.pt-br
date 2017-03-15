---
title: "Adicionando uma classe a partir de um controle ActiveX (Visual C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "Controles ActiveX [C++], adicionando classes"
  - "classes [C++], criando"
ms.assetid: 729fcb37-54b8-44d5-9b4e-50bb16e0eea4
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando uma classe a partir de um controle ActiveX (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use este assistente para criar uma classe do MFC a partir de uma interface em um controle de ActiveX disponível.  Você pode adicionar uma classe do MFC para um  [aplicativo MFC](../mfc/reference/creating-an-mfc-application.md), um  [DLL da MFC](../mfc/reference/creating-an-mfc-dll-project.md), ou um  [o controle de MFC ActiveX](../mfc/reference/creating-an-mfc-activex-control.md).  
  
> [!NOTE]
>  Você não precisará criar seu projeto MFC com automação habilitada para adicionar uma classe de um controle ActiveX.  
  
 Um controle ActiveX é um componente de software reutilizável com base na COM Component Object Model \(\) que oferece suporte a uma ampla variedade de funcionalidades OLE e podem ser personalizados para atender às necessidades de software muitos.  Controles de ActiveX são criados para uso em recipientes de controle de ActiveX comuns e na Internet em páginas da World Wide Web.  
  
### Para adicionar uma classe MFC a partir de um controle ActiveX  
  
1.  Em um  **Solution Explorer** ou  [Class View](http://msdn.microsoft.com/pt-br/8d7430a9-3e33-454c-a9e1-a85e3d2db925), clique com o botão direito no nome do projeto ao qual você deseja adicionar a classe de controle de ActiveX.  
  
2.  No menu de atalho, clique em  **Add**e, em seguida, clique em  **Add Class**.  
  
3.  No  [Add Class](../ide/add-class-dialog-box.md) caixa de diálogo, no painel Templates, clique em  **Classe MFC a partir do controle de ActiveX**e, em seguida, clique em  **Abrir** para exibir o  [Add Class do Assistente de controle de ActiveX](../ide/add-class-from-activex-control-wizard.md).  
  
 No assistente, você pode adicionar mais de uma interface em um controle ActiveX.  Da mesma forma, você pode criar classes de mais de um controle de ActiveX em uma sessão única do assistente.  
  
 Você pode adicionar classes de controles de ActiveX registrados no seu sistema, ou você pode adicionar classes de controles de ActiveX, localizados em arquivos de biblioteca de tipo \(. tlb,. olb,. dll,. ocx ou. exe\) sem primeiro registrando\-os no seu sistema.  Consulte  [Registrando controles de OLE](../Topic/Registering%20OLE%20Controls.md) para obter mais informações sobre como registrar os controles de ActiveX.  
  
 O assistente cria uma classe do MFC, derivada de  [CWnd](../Topic/CWnd%20Class.md) ou  [COleDispatchDriver](../mfc/reference/coledispatchdriver-class.md), para cada interface que você adiciona a partir do controle de ActiveX selecionado.  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Introdução à e a ATL](../atl/introduction-to-com-and-atl.md)