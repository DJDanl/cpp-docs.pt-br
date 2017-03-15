---
title: "Selecionando e manipulando registros | Microsoft Docs"
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
  - "conjunto de registros ODBC, selecionando registros"
  - "seleção de registros, Classes MFC ODBC"
  - "registros, selecionando"
ms.assetid: 7f0b3a4a-9941-4475-a612-9ec8d15b7691
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Selecionando e manipulando registros
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Normalmente quando você selecionar registros de uma fonte de dados usando uma instrução SQL **SELECIONAR** , você obtém um conjunto de resultados, que é um conjunto de registros de uma tabela ou uma consulta.  Com as classes de base de dados do, você usa um objeto do conjunto de registros para selecionar e acessar o conjunto de resultados.  Esse é um objeto de uma classe específica do aplicativo que você derivar da classe [CRecordset](../Topic/CRecordset%20Class.md).  Quando você define uma classe do conjunto de registros, você especifica a fonte de dados para associar com, a tabela a ser usada, e as colunas da tabela.  O assistente ou **Adicionar Classe** do aplicativo MFC \(conforme descrito em [Adicionando um consumidor de MFC ODBC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)\) criam uma classe com uma conexão a uma fonte de dados específica.  Os assistentes de gravação da função de membro de [GetDefaultSQL](../Topic/CRecordset::GetDefaultSQL.md) da classe `CRecordset` para retornar o nome da tabela.  Para obter mais informações sobre como usar os assistentes para criar classes do conjunto de registros, consulte [Suporte de base de dados do aplicativo, o assistente MFC](../../mfc/reference/database-support-mfc-application-wizard.md) e [Adicionando um consumidor de MFC ODBC](../../mfc/reference/adding-an-mfc-odbc-consumer.md).  
  
 Usando um objeto de [CRecordset](../Topic/CRecordset%20Class.md) em tempo de execução, você pode:  
  
-   Examine os campos de dados do registro atual.  
  
-   Filtrar ou classificar o conjunto de registros.  
  
-   Personalizar a instrução padrão do SQL **SELECIONAR** .  
  
-   Navegue pelos registros selecionados.  
  
-   Adicionar, atualizar, excluir ou registros \(se a fonte de dados e o conjunto de registros são atualizáveis.\)  
  
-   O teste se o conjunto de registros permite consultar e atualiza o conteúdo do conjunto de registros.  
  
 Quando você terminar de usar o objeto do conjunto de registros, você fechá\-lo e destrói\-.  Para obter mais informações sobre conjuntos de registros, consulte [Conjunto de registros \(ODBC\)](../../data/odbc/recordset-odbc.md).  
  
## Consulte também  
 [ODBC e MFC](../../data/odbc/odbc-and-mfc.md)