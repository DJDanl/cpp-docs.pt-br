---
title: Selecionando e manipulando registros | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- records, selecting
- record selection, MFC ODBC classes
- ODBC recordsets, selecting records
ms.assetid: 7f0b3a4a-9941-4475-a612-9ec8d15b7691
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 3220fe505bc4f4478fa663eab41f99f01d0f15d7
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46072089"
---
# <a name="selecting-and-manipulating-records"></a>Selecionando e manipulando registros

Normalmente quando você seleciona registros de uma fonte de dados usando um SQL **selecionar** instrução, você obtém um conjunto de resultados, que é um conjunto de registros de uma tabela ou uma consulta. Com as classes de banco de dados, você pode usar um objeto recordset para selecionar e acessar o conjunto de resultados. Este é um objeto de uma classe específica do aplicativo que derivam da classe [CRecordset](../../mfc/reference/crecordset-class.md). Quando você define uma classe de conjunto de registros, você deve especificar a fonte de dados para associá-lo com a tabela a ser usada e as colunas da tabela. O Assistente de aplicativo do MFC ou **Add Class** (conforme descrito em [adicionando um consumidor de ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)) cria uma classe com uma conexão a uma fonte de dados específico. Os assistentes de gravar o [GetDefaultSQL](../../mfc/reference/crecordset-class.md#getdefaultsql) função de membro da classe `CRecordset` para retornar o nome da tabela. Para obter mais informações sobre como usar os assistentes para criar classes de conjunto de registros, consulte [suporte de banco de dados, o Assistente de aplicativo MFC](../../mfc/reference/database-support-mfc-application-wizard.md) e [adicionando um consumidor de ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md).  
  
Usando um [CRecordset](../../mfc/reference/crecordset-class.md) do objeto em tempo de execução, você pode:  
  
- Examine os campos de dados do registro atual.  
  
- Filtrar ou classificar o conjunto de registros.  
  
- Personalizar o padrão SQL **selecionar** instrução.  
  
- Percorra os registros selecionados.  
  
- Adicionar, atualizar ou excluir registros (se a fonte de dados e o conjunto de registros são atualizáveis).  
  
- Teste se o conjunto de registros permite repetir a consulta e atualizar conteúdo do conjunto de registros.  
  
Quando você terminar de usar o objeto recordset, feche e destruí-lo. Para obter mais informações sobre conjuntos de registros, consulte [conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md).  
  
## <a name="see-also"></a>Consulte também  

[ODBC e MFC](../../data/odbc/odbc-and-mfc.md)