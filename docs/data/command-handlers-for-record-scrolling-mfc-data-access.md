---
title: "Manipuladores de comandos para rolagem de registro (Acesso a dados MFC) | Microsoft Docs"
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
  - "rolagem de registros [C++]"
  - "exibições de registro [C++], rolagem"
  - "rolando registros"
ms.assetid: f8b13477-2a37-459e-a30c-806fb78165ac
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipuladores de comandos para rolagem de registro (Acesso a dados MFC)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As classes [CRecordView](../mfc/reference/crecordview-class.md) e [CDaoRecordView](../mfc/reference/cdaorecordview-class.md) fornecem manipulação de comando padrão para os seguintes comandos:  
  
-   **ID\_RECORD\_MOVE\_FIRST**  
  
-   **ID\_RECORD\_MOVE\_LAST**  
  
-   **ID\_RECORD\_MOVE\_NEXT**  
  
-   **ID\_RECORD\_MOVE\_PREV**  
  
 A função `OnMove` de membro de classes `CRecordView` e `CDaoRecordView` fornece manipulação de comando padrão para todos os quatro comandos, que movem de registro a registro.  Como esses comandos são emitidos, RFX \(ou DFX\) carrega o novo registro nos campos do conjunto de registros e DDX move os valores para os controles do formulário de registro.  Para informações sobre RFX, consulte [RFX \(Record Field Exchange\)](../data/odbc/record-field-exchange-rfx.md).  
  
> [!NOTE]
>  Certifique\-se de usar essas IDs de comando padrão para os objetos de interface de usuário associados com os comandos de navegação de registro padrão.  
  
## Consulte também  
 [Dando suporte à navegação em uma exibição de registro](../Topic/Supporting%20Navigation%20in%20a%20Record%20View%20%20\(MFC%20Data%20Access\).md)