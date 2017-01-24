---
title: "Recursos de classes de exibi&#231;&#227;o de registro (Acesso a dados MFC) | Microsoft Docs"
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
  - "classes de exibição de registro"
  - "exibições de registro, classes"
ms.assetid: e7b2820f-09c4-483f-83c0-317e8be42bdf
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Recursos de classes de exibi&#231;&#227;o de registro (Acesso a dados MFC)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode fazer programação de acesso a dados com base em formulário com classe [CFormView](../mfc/reference/cformview-class.md), mas [CRecordView](../mfc/reference/crecordview-class.md) e [CDaoRecordView](../mfc/reference/cdaorecordview-class.md) são geralmente classes melhores para derivação.  Além de seus recursos `CFormView`, `CRecordView` e `CDaoRecordView`:  
  
-   Possibilite troca de dados de diálogo \(DDX\) entre os controles de formulário e o objeto do conjunto de registros associado.  
  
-   Execute os comandos Mover Primeiro, Mover Próximo e Mover Anterior e Mover Último para navegar nos registros no objeto de conjunto de registros associado.  
  
-   Atualize as alterações no registro atual quando o usuário for para outro registro.  
  
 Para obter mais informações sobre navegação, consulte [Exibições de registro: suportando navegação em uma exibição de registro](../Topic/Supporting%20Navigation%20in%20a%20Record%20View%20%20\(MFC%20Data%20Access\).md).  
  
## Consulte também  
 [Exibição de registro \(Acesso a dados MFC\)](../data/record-views-mfc-data-access.md)   
 [Lista de drivers ODBC](../data/odbc/odbc-driver-list.md)