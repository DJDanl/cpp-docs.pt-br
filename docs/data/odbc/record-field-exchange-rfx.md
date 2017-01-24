---
title: "Registrar troca de campos (RFX) | Microsoft Docs"
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
  - "dados [MFC]"
  - "dados [MFC], movendo entre fontes e conjuntos de registros"
  - "classes de banco de dados [C++], RFX"
  - "ODBC [C++], RFX"
  - "RFX (ODBC) [C++]"
ms.assetid: f5ddfbf0-2901-48d7-9848-4fb84de3c7ee
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Registrar troca de campos (RFX)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As classes da base de dados de MFC ODBC automatizam a movimentação de dados entre a fonte de dados e um objeto de [conjunto de registros](../../data/odbc/recordset-odbc.md) .  Quando você deve derivar uma classe de [CRecordset](../Topic/CRecordset%20Class.md) e não usa a linha em massa que pesquisa, os dados são transferidos pelo mecanismo de troca do campo de registro \(RFX\).  
  
> [!NOTE]
>  Se você implementar a linha em massa que pesquisa em uma classe derivada de `CRecordset` , a estrutura usa o mecanismo em massa de troca do campo de registro \(RFX em massa\) para transferir dados.  Para obter mais informações, consulte [Conjunto de registros: Buscando registros em massa \(ODBC\)](../Topic/Recordset:%20Fetching%20Records%20in%20Bulk%20\(ODBC\).md).  
  
 RFX é semelhante à caixa de diálogo de troca de dados \(DDX\).  A movimentação de dados entre uma fonte de dados e os membros de dados do campo de um conjunto de registros requerem várias chamadas para a função de [DoFieldExchange](../Topic/CRecordset::DoFieldExchange.md) do conjunto de registros e a interação entre considerável a estrutura e [ODBC](../../data/odbc/odbc-basics.md).  O mecanismo de RFX é do tipo seguro e elimina o trabalho de chamar funções ODBC como **::SQLBindCol**.  Para obter mais informações sobre como DDX, consulte [Caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
 RFX for predominante transparente para você.  Se você declara o conjunto de registros classifica com o assistente de aplicativo MFC ou **Adicionar Classe** \(conforme descrito em [Adicionando um consumidor de MFC ODBC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)\), RFX é compilado neles automaticamente.  A classe do conjunto de registros deve ser derivadas da classe base `CRecordset` fornecido pela estrutura.  O assistente de aplicativo MFC permite criar uma classe inicial do conjunto de registros.  **Adicionar Classe** permite adicionar outras classes do conjunto de registros como as você precisa.  Para obter mais informações e exemplos, consulte [Adicionando um consumidor de MFC ODBC](../../mfc/reference/adding-an-mfc-odbc-consumer.md).  
  
 Você deve adicionar manualmente uma pequena quantidade de códigos de RFX em três casos, quando você quiser:  
  
-   Use consultas parametrizadas.  Para obter mais informações, consulte [Conjunto de registros: A parametrização de um conjunto de registros \(ODBC\)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).  
  
-   Executar junções \(que usam um conjunto de registros para colunas de duas ou mais tabelas\).  Para obter mais informações, consulte [Conjunto de registros: Ao executar uma junção \(ODBC\)](../Topic/Recordset:%20Performing%20a%20Join%20\(ODBC\).md).  
  
-   Associar colunas de dados dinamicamente.  Essa é menos comum da parametrização.  Para obter mais informações, consulte [Conjunto de registros: Colunas de dados dinamicamente associação \(ODBC\)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).  
  
 Se você precisar de uma compreensão mais avançado de RFX, consulte [Exchange campo do registro: Como funciona RFX](../../data/odbc/record-field-exchange-how-rfx-works.md).  
  
 Os tópicos a seguir explicam os detalhes de usar objetos do conjunto de registros:  
  
-   [Exchange campo do registro: Usando RFX](../../data/odbc/record-field-exchange-using-rfx.md)  
  
-   [Exchange campo do registro: Usando as funções de RFX](../../data/odbc/record-field-exchange-using-the-rfx-functions.md)  
  
-   [Exchange campo do registro: Como funciona RFX](../../data/odbc/record-field-exchange-how-rfx-works.md)  
  
## Consulte também  
 [Conectividade de banco de dados aberto \(ODBC\)](../Topic/Open%20Database%20Connectivity%20\(ODBC\).md)   
 [Conjunto de registros \(ODBC\)](../../data/odbc/recordset-odbc.md)   
 [Consumidor ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)   
 [Suporte ao banco de dados, Assistente de Aplicativo MFC](../../mfc/reference/database-support-mfc-application-wizard.md)   
 [Classe de CRecordset](../Topic/CRecordset%20Class.md)