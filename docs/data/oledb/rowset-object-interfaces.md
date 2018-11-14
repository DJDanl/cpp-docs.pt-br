---
title: Interfaces de objeto do conjunto de linhas
ms.date: 10/24/2018
helpviewer_keywords:
- interfaces, OLE DB
- OLE DB, interfaces
- rowset objects [OLE DB]
- OLE DB provider templates, object interfaces
- interfaces, list of
ms.assetid: 0d7a5d48-2fe4-434f-a84b-157c1fdc3494
ms.openlocfilehash: 3f20550558a4af4b286aa0de170763df979ffc5d
ms.sourcegitcommit: c40469825b6101baac87d43e5f4aed6df6b078f5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2018
ms.locfileid: "51556576"
---
# <a name="rowset-object-interfaces"></a>Interfaces de objeto do conjunto de linhas

A tabela a seguir mostra as interfaces obrigatórias e opcionais definidas por OLE DB para um objeto de conjunto de linhas.

|Interface|Necessário?|Implementado por modelos OLE DB?|
|---------------|---------------|--------------------------------------|
|[IAccessor](https://docs.microsoft.com/previous-versions/windows/desktop/ms719672(v=vs.85))|Obrigatório|Sim|
|[IColumnsInfo](https://docs.microsoft.com/previous-versions/windows/desktop/ms724541(v=vs.85))|Obrigatório|Sim|
|[IConvertType](https://docs.microsoft.com/previous-versions/windows/desktop/ms715926(v=vs.85))|Obrigatório|Sim|
|[IRowset](https://docs.microsoft.com/previous-versions/windows/desktop/ms720986(v=vs.85))|Obrigatório|Sim|
|[IRowsetInfo](https://docs.microsoft.com/previous-versions/windows/desktop/ms724541(v=vs.85))|Obrigatório|Sim|
|[IChapteredRowset](https://docs.microsoft.com/previous-versions/windows/desktop/ms718180(v=vs.85))|Opcional|Não|
|[IColumnsInfo2](https://docs.microsoft.com/previous-versions/windows/desktop/ms712953(v=vs.85))|Opcional|Não|
|[IColumnsRowset](https://docs.microsoft.com/previous-versions/windows/desktop/ms722657(v=vs.85))|Opcional|Não|
|[IConnectionPointContainer](/windows/desktop/api/ocidl/nn-ocidl-iconnectionpointcontainer)|Opcional|Sim (por meio de ATL)|
|[IDBAsynchStatus](https://docs.microsoft.com/previous-versions/windows/desktop/ms709832(v=vs.85))|Opcional|Não|
|[IGetRow](https://docs.microsoft.com/previous-versions/windows/desktop/ms718047(v=vs.85))|Opcional|Não|
|[IRowsetChange](https://docs.microsoft.com/previous-versions/windows/desktop/ms715790(v=vs.85))|Opcional|Sim|
|[IRowsetChapterMember](https://docs.microsoft.com/previous-versions/windows/desktop/ms725430(v=vs.85))|Opcional|Não|
|[IRowsetCurrentIndex](https://docs.microsoft.com/previous-versions/windows/desktop/ms709700(v=vs.85))|Opcional|Não|
|[IRowsetFind](https://docs.microsoft.com/previous-versions/windows/desktop/ms724221(v=vs.85))|Opcional|Não|
|[IRowsetIdentity](https://docs.microsoft.com/previous-versions/windows/desktop/ms715913(v=vs.85))|Opcional (mas necessário para provedores de nível 0)|Sim|
|[IRowsetIndex](https://docs.microsoft.com/previous-versions/windows/desktop/ms719604(v=vs.85))|Opcional|Não|
|[IRowsetLocate](https://docs.microsoft.com/previous-versions/windows/desktop/ms721190(v=vs.85))|Opcional|Sim|
|[IRowsetRefresh](https://docs.microsoft.com/previous-versions/windows/desktop/ms714892(v=vs.85))|Opcional|Não|
|[IRowsetScroll](https://docs.microsoft.com/previous-versions/windows/desktop/ms712984(v=vs.85))|Opcional|Não|
|[IRowsetUpdate](https://docs.microsoft.com/previous-versions/windows/desktop/ms714401(v=vs.85))|Opcional|Sim|
|[IRowsetView](https://docs.microsoft.com/previous-versions/windows/desktop/ms709755(v=vs.85))|Opcional|Não|
|[ISupportErrorInfo](https://docs.microsoft.com/previous-versions/windows/desktop/ms715816(v=vs.85))|Opcional|Sim|
|[IRowsetBookmark](https://docs.microsoft.com/previous-versions/windows/desktop/ms714246(v=vs.85))|Opcional|Não|

O objeto de conjunto de linhas gerado pelo assistente implementa `IAccessor`, `IRowset`, e `IRowsetInfo` por meio da herança. O `IAccessorImpl` associa as duas colunas de saída. O `IRowset` interface manipula dados e busca linhas. O `IRowsetInfo` interface manipula as propriedades do conjunto de linhas.

## <a name="see-also"></a>Consulte também

[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
