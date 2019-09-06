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
ms.openlocfilehash: d9c2c61714a98d9de09d8657352a14f296e35a58
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "70311795"
---
# <a name="rowset-object-interfaces"></a>Interfaces de objeto do conjunto de linhas

A tabela a seguir mostra as interfaces obrigatórias e opcionais definidas por OLE DB para um objeto de conjunto de linhas.

|Interface|Necessário?|Implementado por modelos de OLE DB?|
|---------------|---------------|--------------------------------------|
|[IAccessor](/previous-versions/windows/desktop/ms719672(v=vs.85))|Obrigatório|Sim|
|[IColumnsInfo](/previous-versions/windows/desktop/ms724541(v=vs.85))|Obrigatório|Sim|
|[IConvertType](/previous-versions/windows/desktop/ms715926(v=vs.85))|Obrigatório|Sim|
|[IRowset](/previous-versions/windows/desktop/ms720986(v=vs.85))|Obrigatório|Sim|
|[IRowsetInfo](/previous-versions/windows/desktop/ms724541(v=vs.85))|Obrigatório|Sim|
|[IChapteredRowset](/previous-versions/windows/desktop/ms718180(v=vs.85))|Opcional|Não|
|[IColumnsInfo2](/previous-versions/windows/desktop/ms712953(v=vs.85))|Opcional|Não|
|[IColumnsRowset](/previous-versions/windows/desktop/ms722657(v=vs.85))|Opcional|Não|
|[IConnectionPointContainer](/windows/win32/api/ocidl/nn-ocidl-iconnectionpointcontainer)|Opcional|Sim (por meio da ATL)|
|[IDBAsynchStatus](/previous-versions/windows/desktop/ms709832(v=vs.85))|Opcional|Não|
|[IGetRow](/previous-versions/windows/desktop/ms718047(v=vs.85))|Opcional|Não|
|[IRowsetChange](/previous-versions/windows/desktop/ms715790(v=vs.85))|Opcional|Sim|
|[IRowsetChapterMember](/previous-versions/windows/desktop/ms725430(v=vs.85))|Opcional|Não|
|[IRowsetCurrentIndex](/previous-versions/windows/desktop/ms709700(v=vs.85))|Opcional|Não|
|[IRowsetFind](/previous-versions/windows/desktop/ms724221(v=vs.85))|Opcional|Não|
|[IRowsetIdentity](/previous-versions/windows/desktop/ms715913(v=vs.85))|Opcional (mas necessário para provedores de nível 0)|Sim|
|[IRowsetIndex](/previous-versions/windows/desktop/ms719604(v=vs.85))|Opcional|Não|
|[IRowsetLocate](/previous-versions/windows/desktop/ms721190(v=vs.85))|Opcional|Sim|
|[IRowsetRefresh](/previous-versions/windows/desktop/ms714892(v=vs.85))|Opcional|Não|
|[IRowsetScroll](/previous-versions/windows/desktop/ms712984(v=vs.85))|Opcional|Não|
|[IRowsetUpdate](/previous-versions/windows/desktop/ms714401(v=vs.85))|Opcional|Sim|
|[IRowsetView](/previous-versions/windows/desktop/ms709755(v=vs.85))|Opcional|Não|
|[ISupportErrorInfo](/previous-versions/windows/desktop/ms715816(v=vs.85))|Opcional|Sim|
|[IRowsetBookmark](/previous-versions/windows/desktop/ms714246(v=vs.85))|Opcional|Não|

O objeto de conjunto de linhas gerado `IAccessor`pelo `IRowset`assistente implementa `IRowsetInfo` , e por herança. O `IAccessorImpl` associa ambas as colunas de saída. Os `IRowset` identificadores de interface buscam linhas e dados. A `IRowsetInfo` interface manipula as propriedades do conjunto de linhas.

## <a name="see-also"></a>Consulte também

[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
