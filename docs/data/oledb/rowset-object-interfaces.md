---
title: Interfaces de objeto do conjunto de linhas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- interfaces, OLE DB
- OLE DB, interfaces
- rowset objects [OLE DB]
- OLE DB provider templates, object interfaces
- interfaces, list of
ms.assetid: 0d7a5d48-2fe4-434f-a84b-157c1fdc3494
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 2050a444ca228554cfbb3b6bba2693c55e53c4a2
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43217544"
---
# <a name="rowset-object-interfaces"></a>Interfaces de objeto do conjunto de linhas
A tabela a seguir mostra as interfaces obrigatórias e opcionais definidas por OLE DB para um objeto de conjunto de linhas.  
  
|Interface|Necessário?|Implementado por modelos OLE DB?|  
|---------------|---------------|--------------------------------------|  
|[IAccessor](/previous-versions/windows/desktop/ms719672\(v=vs.85\))|Obrigatório|Sim|  
|[IColumnsInfo](/previous-versions/windows/desktop/ms724541\(v=vs.85\))|Obrigatório|Sim|  
|[IConvertType](/previous-versions/windows/desktop/ms715926\(v=vs.85\))|Obrigatório|Sim|  
|[IRowset](/previous-versions/windows/desktop/ms720986\(v=vs.85\))|Obrigatório|Sim|  
|[IRowsetInfo](/previous-versions/windows/desktop/ms724541\(v=vs.85\))|Obrigatório|Sim|  
|[IChapteredRowset](/previous-versions/windows/desktop/ms718180\(v=vs.85\))|Opcional|Não|  
|[IColumnsInfo2](/previous-versions/windows/desktop/ms712953\(v=vs.85\))|Opcional|Não|  
|[IColumnsRowset](/previous-versions/windows/desktop/ms722657\(v=vs.85\))|Opcional|Não|  
|[IConnectionPointContainer](/windows/desktop/api/ocidl/nn-ocidl-iconnectionpointcontainer)|Opcional|Sim (por meio de ATL)|  
|[IDBAsynchStatus](/previous-versions/windows/desktop/ms709832\(v=vs.85\))|Opcional|Não|  
|[IGetRow](/previous-versions/windows/desktop/ms718047\(v=vs.85\))|Opcional|Não|  
|[IRowsetChange](/previous-versions/windows/desktop/ms715790\(v=vs.85\))|Opcional|Sim|  
|[IRowsetChapterMember](/previous-versions/windows/desktop/ms725430\(v=vs.85\))|Opcional|Não|  
|[IRowsetCurrentIndex](/previous-versions/windows/desktop/ms709700\(v=vs.85\))|Opcional|Não|  
|[IRowsetFind](/previous-versions/windows/desktop/ms724221\(v=vs.85\))|Opcional|Não|  
|[IRowsetIdentity](/previous-versions/windows/desktop/ms715913\(v=vs.85\))|Opcional (mas necessário para provedores de nível 0)|Sim|  
|[IRowsetIndex](/previous-versions/windows/desktop/ms719604\(v=vs.85\))|Opcional|Não|  
|[IRowsetLocate](/previous-versions/windows/desktop/ms721190\(v=vs.85\))|Opcional|Sim|  
|[IRowsetRefresh](/previous-versions/windows/desktop/ms714892\(v=vs.85\))|Opcional|Não|  
|[IRowsetScroll](/previous-versions/windows/desktop/ms712984\(v=vs.85\))|Opcional|Não|  
|[IRowsetUpdate](/previous-versions/windows/desktop/ms714401\(v=vs.85\))|Opcional|Sim|  
|[IRowsetView](/previous-versions/windows/desktop/ms709755\(v=vs.85\))|Opcional|Não|  
|[ISupportErrorInfo](/previous-versions/windows/desktop/ms715816\(v=vs.85\))|Opcional|Sim|  
|[IRowsetBookmark](/previous-versions/windows/desktop/ms714246\(v=vs.85\))|Opcional|Não|  
  
 O objeto de conjunto de linhas gerado pelo assistente implementa `IAccessor`, `IRowset`, e `IRowsetInfo` por meio da herança. O `IAccessorImpl` associa as duas colunas de saída. O `IRowset` interface manipula dados e busca linhas. O `IRowsetInfo` interface manipula as propriedades do conjunto de linhas.  
  
## <a name="see-also"></a>Consulte também  
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)