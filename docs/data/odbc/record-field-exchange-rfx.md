---
title: Registrar troca de campos (RFX) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- RFX (ODBC) [C++]
- data [MFC], moving between sources and recordsets
- database classes [C++], RFX
- data [MFC]
- ODBC [C++], RFX
ms.assetid: f5ddfbf0-2901-48d7-9848-4fb84de3c7ee
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: ede5ce16aa7255bd6f62afc1b397d802003e6621
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50080995"
---
# <a name="record-field-exchange-rfx"></a>Registrar troca de campos (RFX)

As classes de banco de dados ODBC MFC automatizam a movimentação de dados entre a fonte de dados e uma [recordset](../../data/odbc/recordset-odbc.md) objeto. Quando você deriva uma classe de [CRecordset](../../mfc/reference/crecordset-class.md) e não usar a busca de linhas em massa, os dados são transferidos pelo mecanismo do exchange (RFX) de campos de registro.

> [!NOTE]
>  Se você tiver implementado a busca de linhas em massa em uma derivada `CRecordset` classe, a estrutura usa o mecanismo do exchange (RFX em massa) de campos de registro em massa para transferir dados. Para obter mais informações, consulte [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

RFX é semelhante a troca de dados de caixa de diálogo (DDX). Mover dados entre uma fonte de dados e os membros de dados do campo de um conjunto de registros requer várias chamadas para o conjunto de registros [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) interação de função e considerável entre a estrutura e [ODBC](../../data/odbc/odbc-basics.md). O mecanismo RFX é fortemente tipada e poupa o trabalho de chamar funções ODBC como `::SQLBindCol`. Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).

RFX geralmente é transparente para você. Se você declarar suas classes de conjunto de registros com o Assistente de aplicativo do MFC ou **Add Class** (conforme descrito em [adicionando um consumidor de ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)), RFX baseia-se neles automaticamente. Sua classe de conjunto de registros deve ser derivado da classe base `CRecordset` fornecidos pela estrutura. O Assistente de aplicativo do MFC permite criar uma classe de conjunto de registros inicial. **Adicionar classe** permite que você adicione outras classes de conjunto de registros, conforme necessário. Para obter mais informações e exemplos, consulte [adicionando um consumidor de ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md).

Você deve adicionar manualmente uma pequena quantidade de código RFX em três casos, quando você deseja:

- Use consultas parametrizadas. Para obter mais informações, consulte [conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).

- Execute junções (usando um conjunto de registros para colunas de tabelas de dois ou mais). Para obter mais informações, consulte [conjunto de registros: executando uma junção (ODBC)](../../data/odbc/recordset-performing-a-join-odbc.md).

- Vincule dinamicamente colunas de dados. Isso é menos comum do que a parametrização. Para obter mais informações, consulte [conjunto de registros: dinamicamente associando dados colunas (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).

Se você precisar de uma compreensão mais avançada de RFX, consulte [troca de campos do registro: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md).

Os tópicos a seguir explicam os detalhes de como usar objetos de conjunto de registros:

- [Troca de campo de registro: usando RFX](../../data/odbc/record-field-exchange-using-rfx.md)

- [Troca de campo de registro: usando as funções RFX](../../data/odbc/record-field-exchange-using-the-rfx-functions.md)

- [Troca de campo de registro: como a RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md)

## <a name="see-also"></a>Consulte também

[ODBC (conectividade de banco de dados aberto)](../../data/odbc/open-database-connectivity-odbc.md)<br/>
[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Consumidor ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)<br/>
[Suporte ao banco de dados, Assistente de aplicativo MFC](../../mfc/reference/database-support-mfc-application-wizard.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)