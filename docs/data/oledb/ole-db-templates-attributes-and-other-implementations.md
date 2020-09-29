---
title: Modelos de banco de dados OLE, atributos e outras implementações
ms.date: 10/22/2018
helpviewer_keywords:
- OLE DB, implementations
- OLE DB templates, about OLE DB templates
- OLE DB templates
ms.assetid: 0c780c1b-9bba-4788-8c33-8552d9f120ac
ms.openlocfilehash: 217db304c7d0b5723b7af383e07290f160cc9465
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91500920"
---
# <a name="ole-db-templates-attributes-and-other-implementations"></a>Modelos de banco de dados OLE, atributos e outras implementações

## <a name="atl-ole-db-templates"></a>Modelos de OLE DB da ATL

Os modelos de OLE DB, que fazem parte do ATL (Active Template Library), tornam a tecnologia de banco de dados OLE DB de alto desempenho mais fácil de usar fornecendo classes que implementam muitas das interfaces OLE DB usadas com frequência. Junto com essa biblioteca de modelos vem o suporte do assistente para criar OLE DB aplicativos iniciais.

Esta biblioteca de modelos contém duas partes:

- **Modelos de consumidor OLE DB** Usado para implementar um aplicativo cliente (consumidor) OLE DB.

- **Modelos de provedor de OLE DB** Usado para implementar um aplicativo de servidor de OLE DB (provedor).

Para usar os modelos de OLE DB, você deve estar familiarizado com os modelos do C++, COM e as interfaces de OLE DB. Se você não estiver familiarizado com OLE DB, consulte [referência do programador de OLE DB](/sql/connect/oledb/ole-db/oledb-driver-for-sql-server-programming).

Para obter mais informações, você pode:

- Leia os tópicos sobre os modelos de [consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md) ou [modelos de provedor de OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md).

- Criar um [OLE DB consumidor](../../data/oledb/creating-an-ole-db-consumer.md) ou [provedor de OLE DB](../../data/oledb/creating-an-ole-db-provider.md).

- Consulte a lista de classes de [consumidor de OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md) ou classes de [provedor de OLE DB](../../data/oledb/ole-db-provider-templates-reference.md).

- Consulte a lista de [exemplos de modelos de OLE DB](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB).

- Consulte [referência do programador de OLE DB](/sql/connect/oledb/ole-db/oledb-driver-for-sql-server-programming) (no SDK do Windows).

## <a name="ole-db-attributes"></a>Atributos de OLE DB

Os [atributos de consumidor OLE DB](../../windows/attributes/ole-db-consumer-attributes.md) fornecem uma maneira conveniente de criar OLE DB consumidores. Os atributos de OLE DB injetam código com base nos [modelos de consumidor de OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md) para criar clientes e provedores de OLE DB de trabalho. Se você precisar especificar a funcionalidade não suportada pelos atributos, poderá usar os modelos de OLE DB em conjunto com os atributos em seu código.

## <a name="mfc-ole-db-classes"></a>Classes OLE DB MFC

A biblioteca do MFC tem uma classe, [COleDBRecordView](../../mfc/reference/coledbrecordview-class.md), que exibe registros de banco de dados em controles. A exibição é uma exibição de formulário diretamente conectada a um `CRowset` objeto e exibe os campos do `CRowset` objeto nos controles do modelo de caixa de diálogo. Ele também fornece uma implementação padrão para mover para o primeiro registro, próximo, anterior ou último e uma interface para atualizar o registro atualmente na exibição. Para obter mais informações, consulte `COleDBRecordView`.

## <a name="ole-db-sdk-interfaces"></a>Interfaces SDK do OLE DB

Nos casos em que os modelos de OLE DB não dão suporte OLE DB funcionalidade, você precisa usar as próprias interfaces de OLE DB. Para obter mais informações, consulte [referência do programador de OLE DB](/sql/connect/oledb/ole-db/oledb-driver-for-sql-server-programming) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Programação de OLE DB](../../data/oledb/ole-db-programming.md)<br/>
[Visão geral da programação de OLE DB](../../data/oledb/ole-db-programming-overview.md)
