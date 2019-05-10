---
title: Classes de banco de dados ATL (modelos de banco de dados OLE)
ms.date: 05/02/2019
helpviewer_keywords:
- OLE DB templates [C++], ATL database classes
- database classes [C++], OLE DB
- database classes [C++], ATL
ms.assetid: 219766aa-e18a-405f-9e36-d7a0fdb31b2b
ms.openlocfilehash: dc016a5e1e1d9652f6a69f73b5760f42dec5e889
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65222564"
---
# <a name="atl-database-classes-ole-db-templates"></a>Classes de banco de dados ATL (modelos de banco de dados OLE)

A Microsoft fornece várias implementações do OLE DB, um conjunto de interfaces que fornecem acesso uniforme a dados em várias fontes de informação e formatos.

Os modelos OLE DB são modelos de C++ em ATL que facilitam a tecnologia de banco de dados OLE DB usar, fornecendo classes que implementam muitas das interfaces do OLE DB comumente usadas.

Essa biblioteca de modelo contém duas partes:

- [Modelos de consumidor OLE DB](../data/oledb/ole-db-consumer-templates-cpp.md) usado para implementar um aplicativo de cliente (consumidor) do OLE DB.

- [Modelos de provedor OLE DB](../data/oledb/ole-db-provider-templates-cpp.md) usado para implementar um aplicativo de servidor (provedor) do OLE DB.

Além disso, o [atributos de consumidor do OLE DB](../windows/ole-db-consumer-attributes.md) fornecem uma maneira conveniente de criar os consumidores do OLE DB. Os atributos de OLE DB injetam código com base nos modelos de consumidor OLE DB para criar os consumidores OLE DB do trabalho.

Observe que a biblioteca do MFC contém uma classe, [COleDBRecordView](../mfc/reference/coledbrecordview-class.md), que exibe os registros do banco de dados em controles. A exibição é um modo de exibição de formulário conectado diretamente a um `CRowset` do objeto e exibe os campos do `CRowset` objeto nos controles do modelo de caixa de diálogo.

Para obter mais informações, consulte [OLE DB de programação](../data/oledb/ole-db-programming.md) e [guia do programador do DB OLE](/sql/connect/oledb/ole-db/oledb-driver-for-sql-server-programming).

## <a name="see-also"></a>Consulte também

[Criando um consumidor do OLE DB](../data/oledb/creating-an-ole-db-consumer.md)<br/>
[Criando um provedor do OLE DB](../data/oledb/creating-an-ole-db-provider.md)<br/>
[Referência de modelos de consumidor do OLE DB](../data/oledb/ole-db-consumer-templates-reference.md)<br/>
[Referência dos modelos de provedor do OLE DB](../data/oledb/ole-db-provider-templates-reference.md)<br/>
[Exemplos de modelos OLE DB](https://github.com/Microsoft/VCSamples)
