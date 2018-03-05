---
title: Registrar troca de campos (RFX) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- RFX (ODBC) [C++]
- data [MFC], moving between sources and recordsets
- database classes [C++], RFX
- data [MFC]
- ODBC [C++], RFX
ms.assetid: f5ddfbf0-2901-48d7-9848-4fb84de3c7ee
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 50fc0aea1ef50124cd98b0d0498b767d1f00e5c0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="record-field-exchange-rfx"></a>Registrar troca de campos (RFX)
As classes de banco de dados ODBC MFC automatizam a movimentação de dados entre a fonte de dados e um [registros](../../data/odbc/recordset-odbc.md) objeto. Quando você derivar uma classe de [CRecordset](../../mfc/reference/crecordset-class.md) e não use a busca de linhas em massa, os dados são transferidos pelo mecanismo de troca (RFX) de campos de registro.  
  
> [!NOTE]
>  Se você tiver implementado em busca de linhas em massa em um derivado `CRecordset` classe, a estrutura usa o mecanismo de troca (RFX em massa) de campos de registro em massa para transferir dados. Para obter mais informações, consulte [conjunto de registros: busca de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
 RFX é semelhante a troca de dados de caixa de diálogo (DDX). Mover dados entre uma fonte de dados e os membros de dados do campo de um conjunto de registros requer várias chamadas para o conjunto de registros [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) função e considerável interação entre a estrutura e [ODBC](../../data/odbc/odbc-basics.md). O mecanismo RFX é fortemente tipadas e elimina o trabalho de chamar funções ODBC como **:: SQLBindCol**. Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
 RFX principalmente é transparente para você. Se você declarar suas classes de conjunto de registros com o Assistente de aplicativo do MFC ou **Adicionar classe** (conforme descrito em [adicionando um consumidor de ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)), RFX baseia-los automaticamente. A classe de conjunto de registros deve ser derivada da classe base `CRecordset` fornecido pela estrutura. Assistente de aplicativo MFC permite que você criar uma classe de conjunto de registros inicial. **Adicionar classe** permite que você adicione outras classes de conjunto de registros, conforme necessário. Para obter mais informações e exemplos, consulte [adicionando um consumidor de ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md).  
  
 Você deve adicionar manualmente uma pequena quantidade de código RFX em três casos, quando você deseja:  
  
-   Use consultas parametrizadas. Para obter mais informações, consulte [conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).  
  
-   Execute junções (usando um conjunto de registros para colunas de duas ou mais tabelas). Para obter mais informações, consulte [conjunto de registros: executar uma junção (ODBC)](../../data/odbc/recordset-performing-a-join-odbc.md).  
  
-   Associe colunas de dados dinamicamente. Isso é menos comum do que a parametrização. Para obter mais informações, consulte [conjunto de registros: dinamicamente de associação de dados colunas (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).  
  
 Se você precisar de uma compreensão mais avançada de RFX, consulte [registrar troca de campos: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md).  
  
 Os tópicos a seguir explicam os detalhes de como usar objetos de conjunto de registros:  
  
-   [Troca de campo de registro: usando RFX](../../data/odbc/record-field-exchange-using-rfx.md)  
  
-   [Troca de campo de registro: usando as funções RFX](../../data/odbc/record-field-exchange-using-the-rfx-functions.md)  
  
-   [Troca de campo de registro: como a RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md)  
  
## <a name="see-also"></a>Consulte também  
 [Open Database Connectivity (ODBC)](../../data/odbc/open-database-connectivity-odbc.md)   
 [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)   
 [Consumidor ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)   
 [Suporte de banco de dados, o Assistente de aplicativo MFC](../../mfc/reference/database-support-mfc-application-wizard.md)   
 [Classe CRecordset](../../mfc/reference/crecordset-class.md)