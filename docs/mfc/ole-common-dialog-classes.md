---
title: "Classes de caixa de di&#225;logo comuns OLE | Microsoft Docs"
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
  - "vc.classes.ole"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classes ActiveX [C++]"
  - "classes de caixa de diálogo comuns"
  - "classes da caixa de diálogo [C++], OLE"
  - "classes de caixa de diálogo comuns OLE [C++]"
ms.assetid: 706526ae-f94f-4909-a0f8-6b5fe954fd97
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de caixa de di&#225;logo comuns OLE
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essas classes tratam tarefas comuns do implementando várias caixas de diálogo do padrão.  Também fornecem uma interface do usuário consistente para a funcionalidade OLE.  
  
 [COleDialog](../mfc/reference/coledialog-class.md)  
 Usado pela estrutura para conter implementações comuns de todas as caixas de diálogo do.  Todas as classes da caixa de diálogo na categoria da interface do usuário são derivadas dessa classe base.  `COleDialog` não pode ser usado diretamente.  
  
 [COleInsertDialog](../mfc/reference/coleinsertdialog-class.md)  
 Exibe a caixa de diálogo do objeto de inserção, a interface do usuário padrão para inserir novos itens vinculados ou inseridos OLE.  
  
 [COlePasteSpecialDialog](../mfc/reference/colepastespecialdialog-class.md)  
 Exibe a caixa de diálogo especial da pasta, a interface do usuário padrão para implementar o comando especial da pasta de edição.  
  
 [COleLinksDialog](../mfc/reference/colelinksdialog-class.md)  
 Exibe a caixa de diálogo de Links de edição, a interface do usuário padrão para as informações de alteração em itens vinculados.  
  
 [COleChangeIconDialog](../mfc/reference/colechangeicondialog-class.md)  
 Exibe a caixa de diálogo de ícone de alteração, a interface do usuário padrão para alterar o ícone associado a um item inserido ou vinculado OLE.  
  
 [COleConvertDialog](../mfc/reference/coleconvertdialog-class.md)  
 Exibe a caixa de diálogo de conversão, a interface do usuário padrão para itens do converter de um tipo para outro.  
  
 [COlePropertiesDialog](../Topic/COlePropertiesDialog%20Class.md)  
 Encapsula a caixa de diálogo OLE comum das propriedades do windows.  As caixas de diálogo DE propriedades comuns fornecem uma maneira fácil de um modo exibir e modificar as propriedades de um item OLE do documento consistente com os padrões do windows.  
  
 [COleUpdateDialog](../Topic/COleUpdateDialog%20Class.md)  
 Exibe a caixa de diálogo da atualização, a interface do usuário padrão para atualizar todos os links em um documento.  A caixa de diálogo contém um indicador de progresso para indicar como o fim do procedimento de atualização é até a conclusão.  
  
 [COleChangeSourceDialog](../mfc/reference/colechangesourcedialog-class.md)  
 Exibe a caixa de diálogo origem da alteração, a interface do usuário padrão para modificar o destino ou a origem de um link.  
  
 [COleBusyDialog](../mfc/reference/colebusydialog-class.md)  
 Exibe o servidor as caixas de diálogo de resposta e ocupados do servidor, a interface do usuário padrão para tratar chamadas para os aplicativos ocupados.  Exibido normalmente automaticamente pela implementação de `COleMessageFilter` .  
  
## Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)