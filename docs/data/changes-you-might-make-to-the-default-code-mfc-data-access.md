---
title: "Altera&#231;&#245;es que podem ser feitas ao c&#243;digo padr&#227;o (Acesso a dados MFC) | Microsoft Docs"
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
  - "exibições de registro [C++], personalizando código padrão"
ms.assetid: 9992ed37-a6bf-45a5-a572-5c14e42b6628
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Altera&#231;&#245;es que podem ser feitas ao c&#243;digo padr&#227;o (Acesso a dados MFC)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O O [Assistente para Aplicativo do MFC](../mfc/reference/database-support-mfc-application-wizard.md) grava uma classe de conjunto de registros que seleciona todos os registros em uma única tabela.  Geralmente, você irá querer modificar esse comportamento em uma ou mais das seguintes maneiras:  
  
-   Defina um filtro ou uma ordem de classificação do conjunto de registros.  Faça isso na `OnInitialUpdate` depois que o objeto do conjunto de registros é construído, mas antes que sua função de membro **Abrir** seja chamada.  Para obter mais informações, consulte [Conjunto de registros: filtrando registros \(ODBC\)](../data/odbc/recordset-filtering-records-odbc.md) e [Conjunto de registros: classificando registros \(ODBC\)](../data/odbc/recordset-sorting-records-odbc.md).  
  
-   Parametrizar o conjunto de registros.  Especifique o valor do parâmetro de tempo de execução real após o filtro.  Para obter mais informações, consulte [Conjunto de registros: parametrizando um conjunto de registros \(ODBC\)](../data/odbc/recordset-parameterizing-a-recordset-odbc.md)  
  
-   Passe uma cadeia de caracteres SQL personalizada para a função de membro [Abrir](../Topic/CRecordset::Open.md).  Para obter uma discussão do que você pode fazer com essa técnica, consulte [SQL: personalizando a instrução SQL de seu conjunto de registros \(ODBC\)](../data/odbc/sql-customizing-your-recordset’s-sql-statement-odbc.md).  
  
## Consulte também  
 [Usando uma exibição de registro](../data/using-a-record-view-mfc-data-access.md)