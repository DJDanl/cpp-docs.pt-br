---
title: Registrar troca de campos (RFX)
ms.date: 11/04/2016
helpviewer_keywords:
- RFX (ODBC) [C++]
- data [MFC], moving between sources and recordsets
- database classes [C++], RFX
- data [MFC]
- ODBC [C++], RFX
ms.assetid: f5ddfbf0-2901-48d7-9848-4fb84de3c7ee
ms.openlocfilehash: 6f965b90e1e0bbcfd3ad04bb5b40644d61050b2e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367155"
---
# <a name="record-field-exchange-rfx"></a>Registrar troca de campos (RFX)

As classes de banco de dados MFC ODBC automatizam dados móveis entre a fonte de dados e um objeto [de conjunto de registros.](../../data/odbc/recordset-odbc.md) Quando você obtém uma classe de [CRecordset](../../mfc/reference/crecordset-class.md) e não usa busca de linha em massa, os dados são transferidos pelo mecanismo RFX (Record Field Exchange).

> [!NOTE]
> Se você tiver implementado a busca `CRecordset` de linhas em massa em uma classe derivada, a estrutura usará o mecanismo bulk record field exchange (Bulk RFX) para transferir dados. Para obter mais informações, consulte [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

O RFX é semelhante ao Exchange de Dados de Diálogo (DDX). A movimentação de dados entre uma fonte de dados e os membros de dados de campo de um conjunto de registros requer várias chamadas para a função [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) do conjunto de registros e uma interação considerável entre o framework e o [ODBC](../../data/odbc/odbc-basics.md). O mecanismo RFX é seguro para o tipo e salva o `::SQLBindCol`trabalho de chamar funções ODBC como . Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

RFX é principalmente transparente para você. Se você declarar suas classes de conjunto de registros com o Assistente de Aplicativo MFC ou **Adicionar Classe** (conforme descrito em Adicionar um [Consumidor ODBC MFC),](../../mfc/reference/adding-an-mfc-odbc-consumer.md)o RFX será incorporado automaticamente. Sua classe de conjunto de registros `CRecordset` deve ser derivada da classe base fornecida pela estrutura. O MFC Application Wizard permite que você crie uma classe de conjunto de registros inicial. **Adicionar classe** permite adicionar outras classes de conjunto de discos conforme você precisar. Para obter mais informações e exemplos, consulte [Adicionar um Consumidor ODBC MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md).

Você deve adicionar manualmente uma pequena quantidade de código RFX em três casos, quando quiser:

- Use consultas parametrizadas. Para obter mais informações, consulte [Recordset: Parametizando um Conjunto de Registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).

- Realizar joins (usando um conjunto de discos para colunas de duas ou mais tabelas). Para obter mais informações, consulte [Recordset: Realizando uma Join (ODBC)](../../data/odbc/recordset-performing-a-join-odbc.md).

- Vincule colunas de dados dinamicamente. Isso é menos comum do que a parametrização. Para obter mais informações, consulte [Recordset: Dynamically Binding Data Columns (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).

Se você precisar de uma compreensão mais avançada do RFX, consulte [Record Field Exchange: How RFX Works](../../data/odbc/record-field-exchange-how-rfx-works.md).

Os tópicos a seguir explicam os detalhes do uso de objetos de conjunto de registros:

- [Registrar troca de campos: usando RFX](../../data/odbc/record-field-exchange-using-rfx.md)

- [Registrar troca de campos: usando as funções RFX](../../data/odbc/record-field-exchange-using-the-rfx-functions.md)

- [Registrar troca de campos: como funciona RFX](../../data/odbc/record-field-exchange-how-rfx-works.md)

## <a name="see-also"></a>Confira também

[Conectividade de banco de dados aberto (ODBC)](../../data/odbc/open-database-connectivity-odbc.md)<br/>
[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Consumo ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)<br/>
[Suporte ao banco de dados, Assistente de aplicativo MFC](../../mfc/reference/database-support-mfc-application-wizard.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)
