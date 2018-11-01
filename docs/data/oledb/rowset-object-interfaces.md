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
ms.openlocfilehash: 739c7d94e5df2d5edddc00bd3ae2703e07435c23
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50641006"
---
# <a name="rowset-object-interfaces"></a>Interfaces de objeto do conjunto de linhas

A tabela a seguir mostra as interfaces obrigatórias e opcionais definidas por OLE DB para um objeto de conjunto de linhas.

|Interface|Necessário?|Implementado por modelos OLE DB?|
|---------------|---------------|--------------------------------------|
|[IAccessor](/previous-versions/windows/desktop/ms719672)|Obrigatório|Sim|
|[IColumnsInfo](/previous-versions/windows/desktop/ms724541)|Obrigatório|Sim|
|[IConvertType](/previous-versions/windows/desktop/ms715926)|Obrigatório|Sim|
|[IRowset](/previous-versions/windows/desktop/ms720986)|Obrigatório|Sim|
|[IRowsetInfo](/previous-versions/windows/desktop/ms724541)|Obrigatório|Sim|
|[IChapteredRowset](/previous-versions/windows/desktop/ms718180)|Opcional|Não|
|[IColumnsInfo2](/previous-versions/windows/desktop/ms712953)|Opcional|Não|
|[IColumnsRowset](/previous-versions/windows/desktop/ms722657)|Opcional|Não|
|[IConnectionPointContainer](/windows/desktop/api/ocidl/nn-ocidl-iconnectionpointcontainer)|Opcional|Sim (por meio de ATL)|
|[IDBAsynchStatus](/previous-versions/windows/desktop/ms709832)|Opcional|Não|
|[IGetRow](/previous-versions/windows/desktop/ms718047)|Opcional|Não|
|[IRowsetChange](/previous-versions/windows/desktop/ms715790)|Opcional|Sim|
|[IRowsetChapterMember](/previous-versions/windows/desktop/ms725430)|Opcional|Não|
|[IRowsetCurrentIndex](/previous-versions/windows/desktop/ms709700)|Opcional|Não|
|[IRowsetFind](/previous-versions/windows/desktop/ms724221)|Opcional|Não|
|[IRowsetIdentity](/previous-versions/windows/desktop/ms715913)|Opcional (mas necessário para provedores de nível 0)|Sim|
|[IRowsetIndex](/previous-versions/windows/desktop/ms719604)|Opcional|Não|
|[IRowsetLocate](/previous-versions/windows/desktop/ms721190)|Opcional|Sim|
|[IRowsetRefresh](/previous-versions/windows/desktop/ms714892)|Opcional|Não|
|[IRowsetScroll](/previous-versions/windows/desktop/ms712984)|Opcional|Não|
|[IRowsetUpdate](/previous-versions/windows/desktop/ms714401)|Opcional|Sim|
|[IRowsetView](/previous-versions/windows/desktop/ms709755)|Opcional|Não|
|[ISupportErrorInfo](/previous-versions/windows/desktop/ms715816)|Opcional|Sim|
|[IRowsetBookmark](/previous-versions/windows/desktop/ms714246)|Opcional|Não|

O objeto de conjunto de linhas gerado pelo assistente implementa `IAccessor`, `IRowset`, e `IRowsetInfo` por meio da herança. O `IAccessorImpl` associa as duas colunas de saída. O `IRowset` interface manipula dados e busca linhas. O `IRowsetInfo` interface manipula as propriedades do conjunto de linhas.

## <a name="see-also"></a>Consulte também

[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
