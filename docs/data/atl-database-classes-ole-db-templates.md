---
title: Classes de banco de dados ATL (modelos de banco de dados OLE)
ms.date: 05/02/2019
helpviewer_keywords:
- OLE DB templates [C++], ATL database classes
- database classes [C++], OLE DB
- database classes [C++], ATL
ms.assetid: 219766aa-e18a-405f-9e36-d7a0fdb31b2b
ms.openlocfilehash: 76e9f49d4b394d0c807ca1f3d103ff325ded8a09
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213493"
---
# <a name="atl-database-classes-ole-db-templates"></a>Classes de banco de dados ATL (modelos de banco de dados OLE)

A Microsoft fornece várias implementações de OLE DB, um conjunto de interfaces COM que fornece acesso uniforme aos dados em diferentes formatos e fontes de informações.

Os modelos de OLE DB C++ são modelos na ATL que tornam a tecnologia de banco de dados OLE DB mais fácil de usar fornecendo classes que implementam muitas das interfaces de OLE DB comumente usadas.

Esta biblioteca de modelos contém duas partes:

- [Modelos de consumidor OLE DB](../data/oledb/ole-db-consumer-templates-cpp.md) Usado para implementar um aplicativo cliente (consumidor) OLE DB.

- [Modelos de provedor de OLE DB](../data/oledb/ole-db-provider-templates-cpp.md) Usado para implementar um aplicativo de servidor de OLE DB (provedor).

Além disso, os [atributos de consumidor OLE DB](../windows/ole-db-consumer-attributes.md) fornecem uma maneira conveniente de criar OLE DB consumidores. Os atributos de OLE DB injetam código com base nos modelos de consumidor de OLE DB para criar clientes de OLE DB de trabalho.

Observe que a biblioteca MFC contém uma classe, [COleDBRecordView](../mfc/reference/coledbrecordview-class.md), que exibe registros de banco de dados em controles. A exibição é uma exibição de formulário diretamente conectada a um objeto `CRowset` e exibe os campos do objeto `CRowset` nos controles do modelo de caixa de diálogo.

Para obter mais informações, consulte [OLE DB Programming](../data/oledb/ole-db-programming.md) and [OLE DB Programmer ' s Guide](/sql/connect/oledb/ole-db/oledb-driver-for-sql-server-programming).

## <a name="see-also"></a>Confira também

[Criando um consumidor do OLE DB](../data/oledb/creating-an-ole-db-consumer.md)<br/>
[Criando um provedor do OLE DB](../data/oledb/creating-an-ole-db-provider.md)<br/>
[Referência de modelos de consumidor do OLE DB](../data/oledb/ole-db-consumer-templates-reference.md)<br/>
[Referência dos modelos de provedor do OLE DB](../data/oledb/ole-db-provider-templates-reference.md)<br/>
[Amostras de modelos do OLE DB](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB)
