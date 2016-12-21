---
title: "Criando menus pop-up | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
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
  - "menus de contexto, o Editor de Menu"
  - "menus pop-up, criando"
  - "menus pop-up"
  - "menus, criando"
  - "menus de atalho, criando"
  - "menus pop-up, exibindo"
ms.assetid: dff4dddf-2e8d-4c34-b755-90baae426b58
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando menus pop-up
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

[Menus pop\-up](../mfc/menus-mfc.md) comandos de exibição usado com frequência. Eles podem ser sensíveis ao contexto para o local do ponteiro. Usar menus pop\-up em seu aplicativo requer o próprio menu de criação e, em seguida, conectá\-lo ao código do aplicativo.  
  
 Depois de criar o recurso de menu, o código do aplicativo precisa carregar o recurso de menu e usar [TrackPopupMenu](http://msdn.microsoft.com/library/windows/desktop/ms648002) para fazer com que o menu seja exibido. Depois que o usuário foi descartado no menu pop\-up clicando fora dele ou clicou em um comando, essa função retornará. Se o usuário escolher um comando, essa mensagem de comando será enviada à janela cujo identificador foi passado.  
  
### Para criar um menu pop\-up  
  
1.  [Criar um menu](../windows/creating-a-menu.md) com um título vazio \(não fornecem um **legenda**\).  
  
2.  [Adicionar um comando de menu ao menu novo](../Topic/Adding%20Commands%20to%20a%20Menu.md). Mover para o primeiro comando de menu abaixo do título de menu em branco \(a legenda temporária diz digite aqui\). Digite um **legenda** e quaisquer outras informações.  
  
     Repita esse processo para quaisquer outros comandos de menu no menu pop\-up.  
  
3.  Salve os recursos de menu.  
  
    > [!TIP]
    >  Para obter mais informações sobre como exibir o menu pop\-up, consulte [exibindo um Menu como um Menu pop\-up](../windows/viewing-a-menu-as-a-pop-up-menu.md).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 **Requisitos**  
  
 Win32  
  
## Consulte também  
 [Conectando um menu pop\-up ao aplicativo](../Topic/Connecting%20a%20Pop-up%20Menu%20to%20Your%20Application.md)   
 [Editor de menu](../Topic/Menu%20Editor.md)