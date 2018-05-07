---
title: Interfaces de objeto de conjunto de linhas | Microsoft Docs
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
ms.openlocfilehash: aaed092d0a67c80852216b6342d32820c7028c4b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="rowset-object-interfaces"></a>Interfaces de objeto do conjunto de linhas
A tabela a seguir mostra as interfaces obrigatórias e opcionais definidas por OLE DB para um objeto de conjunto de linhas.  
  
|Interface|Necessário?|Implementado por modelos OLE DB?|  
|---------------|---------------|--------------------------------------|  
|[IAccessor](https://msdn.microsoft.com/en-us/library/ms719672.aspx)|Obrigatório|Sim|  
|[IColumnsInfo](https://msdn.microsoft.com/en-us/library/ms724541.aspx)|Obrigatório|Sim|  
|[IConvertType](https://msdn.microsoft.com/en-us/library/ms715926.aspx)|Obrigatório|Sim|  
|[IRowset](https://msdn.microsoft.com/en-us/library/ms720986.aspx)|Obrigatório|Sim|  
|[IRowsetInfo](https://msdn.microsoft.com/en-us/library/ms724541.aspx)|Obrigatório|Sim|  
|[IChapteredRowset](https://msdn.microsoft.com/en-us/library/ms718180.aspx)|Opcional|Não|  
|[IColumnsInfo2](https://msdn.microsoft.com/en-us/library/ms712953.aspx)|Opcional|Não|  
|[IColumnsRowset](https://msdn.microsoft.com/en-us/library/ms722657.aspx)|Opcional|Não|  
|[IConnectionPointContainer](http://msdn.microsoft.com/library/windows/desktop/ms683857)|Opcional|Sim (por meio de ATL)|  
|[IDBAsynchStatus](https://msdn.microsoft.com/en-us/library/ms709832.aspx)|Opcional|Não|  
|[IGetRow](https://msdn.microsoft.com/en-us/library/ms718047.aspx)|Opcional|Não|  
|[IRowsetChange](https://msdn.microsoft.com/en-us/library/ms715790.aspx)|Opcional|Sim|  
|[IRowsetChapterMember](https://msdn.microsoft.com/en-us/library/ms725430.aspx)|Opcional|Não|  
|[IRowsetCurrentIndex](https://msdn.microsoft.com/en-us/library/ms709700.aspx)|Opcional|Não|  
|[IRowsetFind](https://msdn.microsoft.com/en-us/library/ms724221.aspx)|Opcional|Não|  
|[IRowsetIdentity](https://msdn.microsoft.com/en-us/library/ms715913.aspx)|Opcional (mas necessário para provedores de nível 0)|Sim|  
|[IRowsetIndex](https://msdn.microsoft.com/en-us/library/ms719604.aspx)|Opcional|Não|  
|[IRowsetLocate](https://msdn.microsoft.com/en-us/library/ms721190.aspx)|Opcional|Sim|  
|[IRowsetRefresh](https://msdn.microsoft.com/en-us/library/ms714892.aspx)|Opcional|Não|  
|[IRowsetScroll](https://msdn.microsoft.com/en-us/library/ms712984.aspx)|Opcional|Não|  
|[IRowsetUpdate](https://msdn.microsoft.com/en-us/library/ms714401.aspx)|Opcional|Sim|  
|[IRowsetView](https://msdn.microsoft.com/en-us/library/ms709755.aspx)|Opcional|Não|  
|[ISupportErrorInfo](https://msdn.microsoft.com/en-us/library/ms715816.aspx)|Opcional|Sim|  
|[IRowsetBookmark](https://msdn.microsoft.com/en-us/library/ms714246.aspx)|Opcional|Não|  
  
 O objeto de conjunto de linhas gerado pelo assistente implementa `IAccessor`, `IRowset`, e `IRowsetInfo` através de herança. O `IAccessorImpl` associa as duas colunas de saída. O `IRowset` interface manipula dados e busca linhas. O `IRowsetInfo` interface trata as propriedades do conjunto de linhas.  
  
## <a name="see-also"></a>Consulte também  
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)