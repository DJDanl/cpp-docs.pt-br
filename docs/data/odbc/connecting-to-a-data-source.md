---
title: Conectando-se a uma fonte de dados
ms.date: 11/04/2016
helpviewer_keywords:
- database connections [C++], ODBC
- ODBC connections [C++], using
- connections [C++], data source
- databases [C++], connecting to
- data sources [C++], connecting to
- ODBC data sources [C++], connections
- database connections [C++], MFC ODBC classes
ms.assetid: ef6c8c98-5979-43a8-9fb5-5bb06fc59f36
ms.openlocfilehash: 712910aca2622f2678b8b9d06b18a2fdbf9157e4
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213337"
---
# <a name="connecting-to-a-data-source"></a>Conectando-se a uma fonte de dados

Uma fonte de dados ODBC é um conjunto específico de dados, as informações necessárias para acessar esses dados e o local da fonte de dados, que pode ser descrito usando um nome de fonte de dados. Do ponto de vista do seu programa, a fonte de dados inclui os dados, o DBMS, a rede (se houver) e o ODBC.

Para acessar os dados fornecidos por uma fonte de dados, seu programa deve primeiro estabelecer uma conexão com a fonte de dados. Todo o acesso a dados é gerenciado por meio dessa conexão.

As conexões de fonte de dados são encapsuladas por classe [CDatabase](../../mfc/reference/cdatabase-class.md). Quando um objeto de `CDatabase` está conectado a uma fonte de dados, você pode:

- Construa [conjuntos de registros](../../mfc/reference/crecordset-class.md), que selecionam registros de tabelas ou consultas.

- Gerenciar [Transações](../../data/odbc/transaction-odbc.md), envio em lote de atualizações para que todas sejam confirmadas na fonte de dados ao mesmo tempo (ou a transação inteira seja revertida para que a fonte de dados não seja alterada) — se a fonte de dados oferecer suporte ao nível necessário de transações.

- Executar instruções [SQL](../../data/odbc/sql.md) diretamente.

Ao concluir o trabalho com uma conexão de fonte de dados, você fecha o objeto `CDatabase` e o destrói ou o reutiliza para uma nova conexão. Para obter mais informações sobre conexões de fonte de dados, consulte [Data Source (ODBC)](../../data/odbc/data-source-odbc.md).

## <a name="see-also"></a>Confira também

[ODBC e MFC](../../data/odbc/odbc-and-mfc.md)
