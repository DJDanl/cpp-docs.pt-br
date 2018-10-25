---
title: Classes de banco de dados ATL (modelos OLE DB) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- OLE DB templates [C++], ATL database classes
- database classes [C++], OLE DB
- database classes [C++], ATL
ms.assetid: 219766aa-e18a-405f-9e36-d7a0fdb31b2b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: b5147610e580d3a67400893d41af8ad9728cc72a
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50071213"
---
# <a name="atl-database-classes-ole-db-templates"></a>Classes de banco de dados ATL (modelos de banco de dados OLE)

A Microsoft fornece várias implementações do OLE DB, um conjunto de interfaces que fornecem acesso uniforme a dados em várias fontes de informação e formatos.  OLE DB foi oficialmente preterido; Esta documentação é para desenvolvedores que estiver mantendo o código herdado. Novos aplicativos devem usar ODBC para se conectar a fontes de dados SQL.

Os modelos OLE DB são modelos de C++ em ATL que facilitam a tecnologia de banco de dados OLE DB usar, fornecendo classes que implementam muitas das interfaces do OLE DB comumente usadas.

Essa biblioteca de modelo contém duas partes:

- [Modelos de consumidor OLE DB](../data/oledb/ole-db-consumer-templates-cpp.md) usado para implementar um aplicativo de cliente (consumidor) do OLE DB.

- [Modelos de provedor OLE DB](../data/oledb/ole-db-provider-templates-cpp.md) usado para implementar um aplicativo de servidor (provedor) do OLE DB.

Além disso, o [atributos de consumidor do OLE DB](../windows/ole-db-consumer-attributes.md) fornecem uma maneira conveniente de criar os consumidores do OLE DB. Os atributos de OLE DB injetam código com base nos modelos de consumidor OLE DB para criar os consumidores OLE DB do trabalho.

Observe que a biblioteca do MFC contém uma classe, [COleDBRecordView](../mfc/reference/coledbrecordview-class.md), que exibe os registros do banco de dados em controles. A exibição é um modo de exibição de formulário conectado diretamente a um `CRowset` do objeto e exibe os campos do `CRowset` objeto nos controles do modelo de caixa de diálogo.

Para obter mais informações, consulte [OLE DB de programação](../data/oledb/ole-db-programming.md) e [guia do programador do DB OLE](/previous-versions/windows/desktop/ms713643).

## <a name="see-also"></a>Consulte também

[Criando um consumidor do OLE DB](../data/oledb/creating-an-ole-db-consumer.md)<br/>
[Criando um provedor do OLE DB](../data/oledb/creating-an-ole-db-provider.md)<br/>
[Referência de modelos de consumidor do OLE DB](../data/oledb/ole-db-consumer-templates-reference.md)<br/>
[Referência dos modelos de provedor do OLE DB](../data/oledb/ole-db-provider-templates-reference.md)<br/>
[Exemplos de modelos OLE DB](https://github.com/Microsoft/VCSamples)