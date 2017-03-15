---
title: "Classes de caixa de di&#225;logo comuns | Microsoft Docs"
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
  - "caixas de diálogo comuns [C++]"
  - "caixas de diálogo comuns [C++], classes de caixa de diálogo comuns"
  - "classes de caixa de diálogo comuns [C++]"
  - "caixas de diálogo [C++], Caixas de diálogo comuns do Windows"
  - "classes da caixa de diálogo [C++]"
  - "classes da caixa de diálogo [C++], comum"
  - "caixas de diálogo MFC, Caixas de diálogo comuns do Windows"
  - "caixas de diálogo comuns do Windows [C++]"
ms.assetid: 5c4f6443-896c-4b05-a7df-8169fdadc71d
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de caixa de di&#225;logo comuns
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Além da classe [CDialog](../mfc/reference/cdialog-class.md)MFC, o fornece várias classes derivadas de `CDialog` que encapsulam caixas de diálogo de uso geral, como mostra a tabela a seguir.  As caixas de diálogo são encapsuladas chamadas “as caixas de diálogo comum” e são parte da biblioteca comum da caixa de diálogo do windows \(COMMDLG.DLL\).  Os recursos e o código de diálogo\- modelo para essas classes são fornecidos nas caixas de diálogo comum do windows que são parte das versões do windows 3,1 e versões posteriores.  
  
### Classes comuns da caixa de diálogo  
  
|Classe derivada da caixa de diálogo|Finalidade|  
|-----------------------------------------|----------------|  
|[CColorDialog](../mfc/reference/ccolordialog-class.md)|Permite que as cores de seleção do usuário.|  
|[CFileDialog](../Topic/CFileDialog%20Class.md)|Permite que o usuário selecione um nome de arquivo para abrir ou salvar.|  
|[CFindReplaceDialog](../Topic/CFindReplaceDialog%20Class.md)|Permite que o usuário iniciar um localizar ou substituir a operação em um arquivo de texto.|  
|[CFontDialog](../mfc/reference/cfontdialog-class.md)|Permite que o usuário especifique uma fonte.|  
|[CPrintDialog](../Topic/CPrintDialog%20Class.md)|Permite que o usuário especifique as informações para um trabalho de impressão.|  
|[CPrintDialogEx](../mfc/reference/cprintdialogex-class.md)|Folha de propriedade da cópia do Windows 2000.|  
  
 Para obter mais informações sobre classes comuns da caixa de diálogo, consulte os nomes da classe individuais na *referência de MFC*.  MFC O também fornece um número de classes padrão da caixa de diálogo usadas para OLE.  Para obter informações sobre essas classes, consulte a classe base, [COleDialog](../mfc/reference/coledialog-class.md), *na referência de MFC*.  
  
 Outras três classes no diálogo\- como MFC têm características.  Para obter mais informações sobre classes [CFormView](../mfc/reference/cformview-class.md), [CRecordView](../mfc/reference/crecordview-class.md), e [CDaoRecordView](../mfc/reference/cdaorecordview-class.md), consulte as classes *na referência de MFC*.  Para obter informações sobre a classe [CDialogBar](../mfc/reference/cdialogbar-class.md), consulte [Barras da caixa de diálogo](../mfc/dialog-bars.md).  
  
## Consulte também  
 [Caixas de diálogo](../mfc/dialog-boxes.md)   
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)   
 [Caixas de diálogo em OLE](../mfc/dialog-boxes-in-ole.md)