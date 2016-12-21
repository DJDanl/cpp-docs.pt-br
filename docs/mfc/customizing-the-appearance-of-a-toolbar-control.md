---
title: "Personalizando a apar&#234;ncia de um controle de barra de ferramentas | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "TBSTYLE_"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CToolBar, estilos"
  - "Classe CToolBarCtrl, estilos de objeto"
  - "barras de ferramentas planas"
  - "estilos TBSTYLE_"
  - "controles de barra de ferramentas [MFC], Estilo "
  - "barras de ferramentas transparentes"
ms.assetid: fd0a73db-7ad1-4fe4-889b-02c3980f49e8
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Personalizando a apar&#234;ncia de um controle de barra de ferramentas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe `CToolBarCtrl` fornece muitos estilos que afetam a aparência \(e, ocasionalmente, o comportamento\) do objeto da barra de ferramentas.  Modifique o objeto da barra de ferramentas definindo o parâmetro de `dwCtrlStyle` da função de membro de `CToolBarCtrl::Create` \(ou `CToolBar::CreateEx`\), quando você criar o controle da barra de ferramentas.  
  
 Os seguintes estilos afetam o aspecto “3D” dos botões da barra de ferramentas e o posicionamento do texto do botão:  
  
-   **TBSTYLE\_FLAT** cria uma barra de ferramentas simples na barra de ferramentas e os botões são transparentes.  O texto do botão é exibido sob bitmaps do botão.  Quando esse estilo for usado, o botão abaixo do cursor será realçado automaticamente.  
  
-   **TBSTYLE\_TRANSPARENT** cria uma barra de ferramentas transparente.  Em uma barra de ferramentas transparente, a barra de ferramentas é transparente mas os botões não são.  O texto do botão é exibido sob bitmaps do botão.  
  
-   Os locais de**TBSTYLE\_LIST**alterações o texto à direita dos bitmaps do botão.  
  
> [!NOTE]
>  Para evitar problemas para repintar, os estilos de **TBSTYLE\_FLAT** e de **TBSTYLE\_TRANSPARENT** devem ser definidos antes que o objeto da barra de ferramentas está visível.  
  
 Os seguintes estilos determinam se a barra de ferramentas permite que um usuário reposicione os botões individuais dentro de um objeto da barra de ferramentas usando o arraste e solte os:  
  
-   **TBSTYLE\_ALTDRAG** permite que os usuários alterem uma posição de botão da barra de ferramentas arrastando a enquanto mantém pressionada ALT.  Se esse estilo não for especificado, o usuário deve manter a tecla SHIFT pressionada enquanto você arrasta um botão.  
  
    > [!NOTE]
    >  O estilo de `CCS_ADJUSTABLE` deve ser especificado para habilitar os botões da barra de ferramentas a ser arrastados.  
  
-   **TBSTYLE\_REGISTERDROP** gerenciar notificações de **TBN\_GETOBJECT** para solicitar objetos de destino de descarte quando o ponteiro do mouse no passar sobre os botões da barra de ferramentas.  
  
 Os estilos afetam outras visual e os aspectos nonvisual da barra de ferramentas objetos:  
  
-   `TBSTYLE_WRAPABLE` cria uma barra de ferramentas que pode ter várias linhas de botões.  Os botões da barra de ferramentas relacionadas podem a “quebra automática” para a linha seguinte à barra de ferramentas se tornam muito estreita para incluir todos os botões na mesma linha.  Envolver ocorre nos limites de divisão e de nongroup.  
  
-   **TBSTYLE\_CUSTOMERASE** gerenciar notificações de **NM\_CUSTOMDRAW** ao processar mensagens de `WM_ERASEBKGND` .  
  
-   `TBSTYLE_TOOLTIPS` cria um controle de dica de ferramenta que um aplicativo possa usar para exibir o texto descritivo para os botões da barra de ferramentas.  
  
 Para uma lista completa de estilo da barra de ferramentas e de estilo estendidos, consulte [Estilos de controle da barra de ferramentas e do botão](http://msdn.microsoft.com/library/windows/desktop/bb760439) e [Estilos estendidos da barra de ferramentas](http://msdn.microsoft.com/library/windows/desktop/bb760430) em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
## Consulte também  
 [Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)