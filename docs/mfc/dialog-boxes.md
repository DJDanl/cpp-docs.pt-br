---
title: "Caixas de di&#225;logo | Microsoft Docs"
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
  - "Classe CDialog, caixas de diálogo MFC"
  - "caixas de diálogo MFC"
  - "MFC, caixas de diálogo"
  - "caixas de diálogo modais, caixas de diálogo MFC"
  - "caixas de diálogo sem modo, caixas de diálogo MFC"
ms.assetid: e4feea1a-8360-4ccb-9b84-507f1ccd9ef3
caps.latest.revision: 14
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Caixas de di&#225;logo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os aplicativos do windows se comunicam com que frequência o usuário pelas caixas de diálogo.  A classe [CDialog](../mfc/reference/cdialog-class.md) fornece uma interface para gerenciar caixas de diálogo, o publicador da caixa de diálogo do Visual C\+\+ o facilita a criação de caixas de diálogo e criar seus recursos de diálogo\- modelo, e os assistentes de código simplificam o processo de inicialização e validar os controles em uma caixa de diálogo e colete os valores inseridos pelo usuário.  
  
 As caixas de diálogo contêm os controles, incluindo:  
  
-   Controles comum do windows como caixas de edição, chaves, caixas de listagem, caixas de combinação, controles de árvore, controles de lista, e indicadores de progresso.  
  
-   Controles ActiveX.  
  
-   Controles Proprietário\-desenhados: controles que você é responsável para o desenho na caixa de diálogo.  
  
 A maioria das caixas de diálogo são modal, que exigem que o usuário fechar a caixa de diálogo antes de usar qualquer outra parte do programa.  Mas é possível criar as caixas de diálogo modeless, que permitem que os usuários trabalhem com outras janelas quando a caixa de diálogo estiver aberta.  MFC O oferece suporte aos tipos da caixa de diálogo com `CDialog`classe.  Os controles são organizados e gerenciados usando um recurso de diálogo\- modelo, criado com [editor da caixa de diálogo](../mfc/dialog-editor.md).  
  
 [Folhas de propriedades](../mfc/property-sheets-mfc.md), também conhecido como caixas de diálogo da guia, são as caixas de diálogo que contêm “páginas” de controles distintos da caixa de diálogo.  Cada página tiver uma pasta de arquivos “tab” na parte superior.  Clique em um guia coloca essa página para a frente da caixa de diálogo.  
  
## Que você deseja saber mais?  
  
-   [Exemplo: Exibindo uma caixa de diálogo por um comando de menu](../mfc/example-displaying-a-dialog-box-via-a-menu-command.md)  
  
-   [Componentes da caixa de diálogo na estrutura](../mfc/dialog-box-components-in-the-framework.md)  
  
-   [Caixas de diálogo modais e modeless](../mfc/modal-and-modeless-dialog-boxes.md)  
  
-   [Folhas de propriedades e páginas de propriedade](../mfc/property-sheets-and-property-pages-mfc.md) em uma caixa de diálogo  
  
-   [Criando o recurso da caixa de diálogo](../Topic/Creating%20the%20Dialog%20Resource.md)  
  
-   [Criando uma classe da caixa de diálogo com os assistentes de código](../mfc/creating-a-dialog-class-with-code-wizards.md)  
  
-   [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)  
  
-   [Caixa de diálogo de troca de dados \(DDX\) e validação \(DDV\)](../mfc/dialog-data-exchange-and-validation.md)  
  
-   [Acesso fortemente tipado nos controles em uma caixa de diálogo](../Topic/Type-Safe%20Access%20to%20Controls%20in%20a%20Dialog%20Box.md)  
  
-   [Mensagens do windows da sua classe mapeamento](../mfc/mapping-windows-messages-to-your-class.md)  
  
-   [Funções de membro geralmente substituídas](../mfc/commonly-overridden-member-functions.md)  
  
-   [Funções de membro geralmente unidas](../Topic/Commonly%20Added%20Member%20Functions.md)  
  
-   [Classes comuns da caixa de diálogo](../mfc/common-dialog-classes.md)  
  
-   [Caixas de diálogo no OLE](../mfc/dialog-boxes-in-ole.md)  
  
-   Crie um aplicativo cuja interface de usuário seja uma caixa de diálogo: consulte [CMNCTRL1](../top/visual-cpp-samples.md) ou [CMNCTRL2](../top/visual-cpp-samples.md) programas de exemplo.  O assistente do aplicativo fornece essa opção também.  
  
-   [Exemplos](../mfc/dialog-sample-list.md)  
  
## Consulte também  
 [Elementos da interface do usuário](../mfc/user-interface-elements-mfc.md)