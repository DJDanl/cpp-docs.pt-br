---
title: "Usando uma exibi&#231;&#227;o do registro (Acesso a dados MFC) | Microsoft Docs"
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
  - "exibições de registro, personalizando código padrão"
ms.assetid: 91f2828f-0666-4273-ae28-e4703fd98521
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando uma exibi&#231;&#227;o do registro (Acesso a dados MFC)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico explica como você pode personalizar o código padrão de exibições de registro que o assistente grava para você.  Normalmente, você pode restringir a seleção de registro com um [filtro](../data/odbc/recordset-filtering-records-odbc.md) ou [parâmetros](../data/odbc/recordset-parameterizing-a-recordset-odbc.md), talvez [classificar](../data/odbc/recordset-sorting-records-odbc.md) os registros, personalizar a instrução SQL.  
  
 Essa informação aplica\-se a ambos [CRecordView](../mfc/reference/crecordview-class.md) \(ODBC\) e [CDaoRecordView](../mfc/reference/cdaorecordview-class.md) \(DAO\).  
  
 O uso de `CRecordView` ou `CDaoRecordView` é semelhante a usar [CFormView](../mfc/reference/cformview-class.md).  A abordagem básica é usar a exibição do registro para exibir e atualizar talvez os registros de um único conjunto de registros.  Além disso, você pode usar outros conjuntos de registros também, conforme discutido em [Exibições de registro: preenchendo uma caixa de listagem de um segundo conjunto de registros](../data/filling-a-list-box-from-a-second-recordset-mfc-data-access.md).  
  
## Consulte também  
 [Exibição de registro \(Acesso a dados MFC\)](../data/record-views-mfc-data-access.md)   
 [Lista de drivers ODBC](../data/odbc/odbc-driver-list.md)