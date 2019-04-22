---
title: Conectando a uma fonte de dados
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
ms.openlocfilehash: 1740a34036798dac69ffc8b486e03bf6439845a5
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59024550"
---
# <a name="connecting-to-a-data-source"></a>Conectando a uma fonte de dados

Uma fonte de dados ODBC é um conjunto específico de dados, as informações necessárias para acessar esses dados e o local da fonte de dados, que pode ser descrito usando um nome de fonte de dados. Do ponto de vista do seu programa, a fonte de dados inclui os dados, o DBMS, a rede (se houver) e ODBC.

Para acessar os dados fornecidos por uma fonte de dados, o programa deve primeiro estabelecer uma conexão à fonte de dados. Acesso a todos os dados é gerenciado por meio dessa conexão.

Conexões de fonte de dados são encapsuladas pela classe [CDatabase](../../mfc/reference/cdatabase-class.md). Quando um `CDatabase` objeto está conectado a uma fonte de dados, você pode:

- Construir [conjuntos de registros](../../mfc/reference/crecordset-class.md), qual seleciona os registros de tabelas ou consultas.

- Gerencie [transações](../../data/odbc/transaction-odbc.md), atualizações de envio em lote para que todos os serão confirmadas à fonte de dados ao mesmo tempo (ou a transação inteira é revertida novamente para que a fonte de dados é alterada) — se a fonte de dados dá suporte ao nível necessário de transações.

- Executar diretamente [SQL](../../data/odbc/sql.md) instruções.

Quando você terminar de trabalhar com uma conexão de fonte de dados, você fechar o `CDatabase` objeto e destruí-lo ou reutilizá-la para uma nova conexão. Para obter mais informações sobre conexões de fonte de dados, consulte [fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md).

## <a name="see-also"></a>Consulte também

[ODBC e MFC](../../data/odbc/odbc-and-mfc.md)