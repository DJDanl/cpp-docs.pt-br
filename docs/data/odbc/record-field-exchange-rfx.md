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
ms.openlocfilehash: e1ba9f29ebf2cb3b1f94620e815882c850bbc7cc
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213051"
---
# <a name="record-field-exchange-rfx"></a>Registrar troca de campos (RFX)

As classes de banco de dados ODBC do MFC automatizam a movimentação de dados entre a fonte e um objeto [Recordset](../../data/odbc/recordset-odbc.md) . Quando você deriva uma classe de [CRecordset](../../mfc/reference/crecordset-class.md) e não usa a busca de linha em massa, os dados são transferidos pelo mecanismo de troca de campo de registro (suporte RFX).

> [!NOTE]
>  Se você tiver implementado a busca de linha em massa em uma classe de `CRecordset` derivada, a estrutura usará o mecanismo de troca de campo de registro em massa (suporte RFX em massa) para transferir dados. Para obter mais informações, consulte conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

SUPORTE RFX é semelhante à campo DDX (caixa de diálogo de troca de dados). Mover dados entre uma fonte de dados e os membros de dados de campo de um conjunto de registros requer várias chamadas para a função [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) do conjunto de registros e uma interação considerável entre a estrutura e o [ODBC](../../data/odbc/odbc-basics.md). O mecanismo suporte RFX é de tipo seguro e economiza o trabalho de chamar funções ODBC, como `::SQLBindCol`. Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

SUPORTE RFX é, na maior parte, transparente para você. Se você declarar suas classes do conjunto de registros com o assistente de aplicativo do MFC ou **Adicionar a classe** (conforme descrito em [adicionando um consumidor ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)), o suporte RFX será incorporado a eles automaticamente. A classe do conjunto de registros deve ser derivada da classe base `CRecordset` fornecida pela estrutura. O assistente de aplicativo do MFC permite criar uma classe de conjunto de registros inicial. **Adicionar classe** permite que você adicione outras classes do conjunto de registros conforme necessário. Para obter mais informações e exemplos, consulte [adicionando um consumidor ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md).

Você deve adicionar manualmente uma pequena quantidade de código suporte RFX em três casos, quando desejar:

- Use consultas parametrizadas. Para obter mais informações, consulte [conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).

- Execute junções (usando um conjunto de registros para colunas de duas ou mais tabelas). Para obter mais informações, consulte [conjunto de registros: executando uma junção (ODBC)](../../data/odbc/recordset-performing-a-join-odbc.md).

- Associar colunas de dados dinamicamente. Isso é menos comum do que parametrização. Para obter mais informações, consulte [conjunto de registros: vinculação dinâmica de colunas de dados (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).

Se você precisar de uma compreensão mais avançada do suporte RFX, confira [gravar campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md).

Os tópicos a seguir explicam os detalhes do uso de objetos Recordset:

- [Troca de campo de registro: usando RFX](../../data/odbc/record-field-exchange-using-rfx.md)

- [Troca de campo de registro: usando as funções RFX](../../data/odbc/record-field-exchange-using-the-rfx-functions.md)

- [Troca de campo de registro: como a RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md)

## <a name="see-also"></a>Confira também

[ODBC (conectividade de banco de dados aberto)](../../data/odbc/open-database-connectivity-odbc.md)<br/>
[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Consumo ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)<br/>
[Suporte ao banco de dados, Assistente de aplicativo MFC](../../mfc/reference/database-support-mfc-application-wizard.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)
