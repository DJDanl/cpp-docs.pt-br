---
title: Conectando a uma fonte de dados | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- database connections [C++], ODBC
- ODBC connections [C++], using
- connections [C++], data source
- databases [C++], connecting to
- data sources [C++], connecting to
- ODBC data sources [C++], connections
- database connections [C++], MFC ODBC classes
ms.assetid: ef6c8c98-5979-43a8-9fb5-5bb06fc59f36
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 2b6a33f1e2421c56f89184d26185903b4ec7859e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33088385"
---
# <a name="connecting-to-a-data-source"></a>Conectando a uma fonte de dados
Uma fonte de dados ODBC é um conjunto específico de dados, as informações necessárias para acessar esses dados e o local da fonte de dados, que pode ser descrito usando um nome de fonte de dados. Do ponto de vista do programa, a fonte de dados inclui os dados, o DBMS, a rede (se houver) e ODBC.  
  
 Para acessar os dados fornecidos por uma fonte de dados, o programa deve primeiro estabelecer uma conexão à fonte de dados. Acesso a todos os dados é gerenciado por meio dessa conexão.  
  
 Conexões de fonte de dados são encapsulados pela classe [CDatabase](../../mfc/reference/cdatabase-class.md). Quando um `CDatabase` objeto está conectado a uma fonte de dados, você pode:  
  
-   Construir [conjuntos de registros](../../mfc/reference/crecordset-class.md), qual selecionar registros das tabelas ou consultas.  
  
-   Gerenciar [transações](../../data/odbc/transaction-odbc.md), atualizações em lote para que todos os serão confirmadas à fonte de dados de uma vez (ou a transação inteira é revertida para a fonte de dados é alterada) — se a fonte de dados oferece suporte ao nível necessário de transações.  
  
-   Executar diretamente [SQL](../../data/odbc/sql.md) instruções.  
  
 Quando terminar de trabalhar com uma conexão de fonte de dados, você fechar o `CDatabase` objeto e destrui-la ou reutilizá-lo para uma nova conexão. Para obter mais informações sobre conexões de fonte de dados, consulte [fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md).  
  
## <a name="see-also"></a>Consulte também  
 [ODBC e MFC](../../data/odbc/odbc-and-mfc.md)