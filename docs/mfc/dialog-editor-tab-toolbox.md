---
title: "Guia Editor de Caixa de Di&#225;logo, caixa de ferramentas | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
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
  - "controles [C++], adicionando a caixas de diálogo"
  - "controles [C++], padrão"
  - "controles [C++], tipos"
  - "controles personalizados [Visual Studio], caixas de diálogo"
  - "Editor de caixa de diálogo, criando controles"
  - "controles syslink em caixas de diálogo"
  - "Caixa de Ferramentas [C++], Guia Editor de Caixas de Diálogo"
ms.assetid: 253885c2-dcb9-4d8e-ac9b-805ea31cbf5e
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Guia Editor de Caixa de Di&#225;logo, caixa de ferramentas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Na guia Editor de caixa de diálogo aparece no [janela Toolbox](../Topic/Toolbox.md) quando você estiver trabalhando no editor de caixa de diálogo. Para adicionar controles à caixa de diálogo Novo, arraste os controles da caixa de ferramentas para a caixa de diálogo Criar \(para obter mais informações, consulte [Adicionar um controle a uma caixa de diálogo](../mfc/adding-a-control-to-a-dialog-box.md)\). Você pode mover os controles ou alterar seu tamanho e forma.  
  
 Os controles padrão disponíveis na caixa de ferramentas são:  
  
-   [Controle de botão](../mfc/reference/cbutton-class.md)  
  
-   [Controle de caixa de seleção](../mfc/reference/button-styles.md)  
  
-   [Controle de caixa de combinação](../mfc/reference/ccombobox-class.md)  
  
-   [Controle de edição](../Topic/CEdit%20Class.md)  
  
-   Caixa de grupo  
  
-   [Controle caixa de listagem](../Topic/CListBox%20Class.md)  
  
-   [Controle de botão de opção](../mfc/reference/button-styles.md)  
  
-   [Controle de texto estático](../Topic/CStatic%20Class.md)  
  
-   [Controle de imagem](../mfc/reference/cpictureholder-class.md)  
  
-   [Controle Rich Editar 2.0](../mfc/using-cricheditctrl.md)  
  
-   [Controle de barra de rolagem](../mfc/reference/cscrollbar-class.md)  
  
 O [controles comuns do Windows](../mfc/controls-mfc.md) disponíveis na caixa de ferramentas oferecem maior funcionalidade em seu aplicativo. Eles incluem:  
  
-   [Controle deslizante](../Topic/Slider%20Control%20Styles.md)  
  
-   [Controle de rotação](../mfc/using-cspinbuttonctrl.md)  
  
-   [Controle de progresso](../mfc/styles-for-the-progress-control.md)  
  
-   [Controle de tecla de acesso](../Topic/Using%20a%20Hot%20Key%20Control.md)  
  
-   [Controle de lista](../mfc/list-control-and-list-view.md)  
  
-   [Controle de árvore](../Topic/Tree%20Control%20Styles.md)  
  
-   [Controle de guia](../Topic/Tab%20Controls%20and%20Property%20Sheets.md)  
  
-   [Controle de animação](../mfc/using-an-animation-control.md)  
  
-   [Controle de seletor de tempo de data](../mfc/creating-the-date-and-time-picker-control.md)  
  
-   [Controle de calendário mensal](../Topic/Month%20Calendar%20Control%20Examples.md)  
  
-   [Controle de endereço IP](../mfc/reference/cipaddressctrl-class.md)  
  
-   [Controle de caixa de combinação estendido](../mfc/creating-an-extended-combo-box-control.md)  
  
-   [Controle personalizado](../mfc/custom-controls-in-the-dialog-editor.md)  
  
 Você pode adicionar controles personalizados à caixa de diálogo selecionando o **controle personalizado** ícone na caixa de ferramentas e arrastando\-o para a caixa de diálogo. Para adicionar um controle Syslink, adicionar um controle personalizado e mude o controle **classe** propriedade **Syslink**. Isso fará com que as propriedades de atualização e mostrar as propriedades do controle Syslink. Para obter informações sobre a classe de wrapper do MFC, consulte [CLinkCtrl](../mfc/reference/clinkctrl-class.md).  
  
 Você também pode [Adicionar controles ActiveX à caixa de diálogo](../mfc/viewing-and-adding-activex-controls-to-a-dialog-box.md).  
  
 Você também pode personalizar a janela caixa de ferramentas para facilitar o uso. Para obter mais informações, consulte [guias na caixa de ferramentas e Gerenciando itens](http://msdn.microsoft.com/pt-br/21285050-cadd-455a-b1f5-a2289a89c4db). Por exemplo, você pode colocar controles na janela caixa de ferramentas para facilitar o acesso. Para obter mais informações, consulte [caixa de diálogo Personalizar caixa de ferramentas](http://msdn.microsoft.com/pt-br/bd07835f-18a8-433e-bccc-7141f65263bb).  
  
 Para obter mais informações sobre como usar o controle RichEdit 1.0 com MFC, consulte [usando o controle RichEdit 1.0 com MFC](../Topic/Using%20the%20RichEdit%201.0%20Control%20with%20MFC.md)  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
## Requisitos  
 Win32  
  
## Consulte também  
 [Controles](../mfc/controls-mfc.md)   
 [Classes de controle](../mfc/control-classes.md)   
 [Classes da caixa de diálogo](../mfc/dialog-box-classes.md)   
 [Estilos de barra de rolagem](../mfc/reference/scroll-bar-styles.md)   
 [Exemplos de controle edição avançada](../Topic/Rich%20Edit%20Control%20Examples.md)   
 [Adicionando manipuladores de eventos para controles da caixa de diálogo](../mfc/adding-event-handlers-for-dialog-box-controls.md)   
 [Controles da caixa de diálogo e tipos de variável](../Topic/Dialog%20Box%20Controls%20and%20Variable%20Types.md)