---
title: Classes de banco de dados ATL (modelos de banco de dados OLE)
ms.date: 05/02/2019
helpviewer_keywords:
- OLE DB templates [C++], ATL database classes
- database classes [C++], OLE DB
- database classes [C++], ATL
ms.assetid: 219766aa-e18a-405f-9e36-d7a0fdb31b2b
ms.openlocfilehash: 5b13a27540b12e7ac1503fbf7cd0e1fe396ce8c8
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91501890"
---
# <a name="atl-database-classes-ole-db-templates"></a>Classes de banco de dados ATL (modelos de banco de dados OLE)

A Microsoft fornece várias implementações de OLE DB, um conjunto de interfaces COM que fornece acesso uniforme aos dados em diferentes formatos e fontes de informações.

Os modelos de OLE DB são modelos C++ na ATL que tornam a tecnologia de banco de dados OLE DB mais fácil de usar fornecendo classes que implementam muitas das interfaces de OLE DB comumente usadas.

Esta biblioteca de modelos contém duas partes:

- [Modelos de consumidor OLE DB](../data/oledb/ole-db-consumer-templates-cpp.md) Usado para implementar um aplicativo cliente (consumidor) OLE DB.

- [Modelos de provedor de OLE DB](../data/oledb/ole-db-provider-templates-cpp.md) Usado para implementar um aplicativo de servidor de OLE DB (provedor).

Além disso, os [atributos de consumidor OLE DB](../windows/attributes/ole-db-consumer-attributes.md) fornecem uma maneira conveniente de criar OLE DB consumidores. Os atributos de OLE DB injetam código com base nos modelos de consumidor de OLE DB para criar clientes de OLE DB de trabalho.

Observe que a biblioteca MFC contém uma classe, [COleDBRecordView](../mfc/reference/coledbrecordview-class.md), que exibe registros de banco de dados em controles. A exibição é uma exibição de formulário diretamente conectada a um `CRowset` objeto e exibe os campos do `CRowset` objeto nos controles do modelo de caixa de diálogo.

Para obter mais informações, consulte [OLE DB Programming](../data/oledb/ole-db-programming.md) and [OLE DB Programmer ' s Guide](/sql/connect/oledb/ole-db/oledb-driver-for-sql-server-programming).

## <a name="see-also"></a>Consulte também

[Criando um consumidor de OLE DB](../data/oledb/creating-an-ole-db-consumer.md)<br/>
[Criando um provedor de OLE DB](../data/oledb/creating-an-ole-db-provider.md)<br/>
[Referência de modelos de consumidor OLE DB](../data/oledb/ole-db-consumer-templates-reference.md)<br/>
[Referência de modelos de provedor de OLE DB](../data/oledb/ole-db-provider-templates-reference.md)<br/>
[Amostras de modelos do OLE DB](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB)
