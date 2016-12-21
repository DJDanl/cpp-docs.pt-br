---
title: "Projetando e criando uma exibi&#231;&#227;o de registro (Acesso a dados MFC) | Microsoft Docs"
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
  - "assistentes de aplicativo [C++], criando classes de exibição de registro"
  - "criando formulários"
  - "criando exibições de registro"
  - "formulários [C++], criando"
  - "exibições de registro, criando"
  - "exibições de registro, criando"
ms.assetid: 1d6f5439-754f-4b8b-a19d-841a4657827b
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Projetando e criando uma exibi&#231;&#227;o de registro (Acesso a dados MFC)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode criar a classe de exibição de registro com a [Assistente de Aplicativo MFC](../mfc/reference/database-support-mfc-application-wizard.md).  Se você usar um assistente de aplicativo, ele criará a classe de exibição de registro e um recurso de modelo de diálogo para ele \(sem controles\).  Você deve usar o editor de diálogo do Visual C\+\+ para adicionar controles ao recurso de modelo de diálogo.  Por outro lado, se você usar **Adicionar Classe**, deverá primeiro criar o recurso de modelo de diálogo na caixa de diálogo Editor e, em seguida, criar a classe de exibição do registro.  
  
 Essa informação se aplica a ambos `CRecordView` e `CDaoRecordView`.  
  
#### Para criar a exibição do registro com o Assistente de Aplicativo MFC  
  
1.  Consulte [Suporte ao banco de dados, Assistente de aplicativo MFC](../mfc/reference/database-support-mfc-application-wizard.md).  
  
#### Para criar o formulário  
  
1.  Consulte o [Editor de Diálogo](../mfc/dialog-editor.md).  
  
#### Para criar sua classe de exibição de registro  
  
1.  Consulte [Adicionando um consumidor MFC ODBC](../mfc/reference/adding-an-mfc-odbc-consumer.md).  
  
 Os tópicos a seguir explicam os detalhes adicionais do uso de exibição de registro:  
  
-   [Exibições de registro: suportando navegação em uma exibição de registro](../Topic/Supporting%20Navigation%20in%20a%20Record%20View%20%20\(MFC%20Data%20Access\).md)  
  
-   [Exibições de registro: Usando uma exibição do registro](../data/using-a-record-view-mfc-data-access.md)  
  
-   [Exibições de registro: preenchendo uma caixa de listagem por meio de um segundo conjunto de registros](../data/filling-a-list-box-from-a-second-recordset-mfc-data-access.md)  
  
## Consulte também  
 [Exibição de registro \(Acesso a dados MFC\)](../data/record-views-mfc-data-access.md)   
 [Conjunto de registros \(ODBC\)](../data/odbc/recordset-odbc.md)   
 [Lista de drivers ODBC](../data/odbc/odbc-driver-list.md)