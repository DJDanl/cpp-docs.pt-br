---
title: Classe IRowsetNotifyImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL.IRowsetNotifyImpl
- ATL::IRowsetNotifyImpl
- IRowsetNotifyImpl
dev_langs:
- C++
helpviewer_keywords:
- IRowsetNotifyImpl class
ms.assetid: fbfd0cb2-38ff-4b42-899a-8de902f834b8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 860b735863acbcac869a4a297984084946aaf028
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33106252"
---
# <a name="irowsetnotifyimpl-class"></a>Classe IRowsetNotifyImpl
Implementa e registra [IRowsetNotify](https://msdn.microsoft.com/en-us/library/ms712959.aspx) no consumidor (também conhecido como o "sink") para que ele possa manipular notificações.  
  
## <a name="syntax"></a>Sintaxe

```cpp
class ATL_NO_VTABLE IRowsetNotifyImpl : public IRowsetNotify  
```  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[OnFieldChange](../../data/oledb/irowsetnotifyimpl-onfieldchange.md)|Notifica o consumidor sobre qualquer alteração no valor de uma coluna.|  
|[OnRowChange](../../data/oledb/irowsetnotifyimpl-onrowchange.md)|Notifica o consumidor sobre a primeira alteração em uma linha ou sobre qualquer alteração que afete toda a linha.|  
|[OnRowsetChange](../../data/oledb/irowsetnotifyimpl-onrowsetchange.md)|Notifica o consumidor sobre qualquer alteração que afete todo o conjunto de linhas.|  
  
## <a name="remarks"></a>Comentários  
 Consulte [recebendo notificações](../../data/oledb/receiving-notifications.md) sobre como implementar a interface de ponto de conexão do consumidor.  
  
 `IRowsetNotifyImpl` Fornece uma implementação fictícia para `IRowsetNotify`, com funções vazias para o `IRowsetNotify` métodos [OnFieldChange](https://msdn.microsoft.com/en-us/library/ms715961.aspx), [OnRowChange](https://msdn.microsoft.com/en-us/library/ms722694.aspx), e [OnRowsetChange](https://msdn.microsoft.com/en-us/library/ms722669.aspx). Se você herdar desta classe ao implementar um `IRowsetNotify` interface, você pode implementar apenas os métodos que você precisa. Você também precisa fornecer implementações vazias para os outros métodos por conta própria.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [IRowsetNotify](https://msdn.microsoft.com/en-us/library/ms712959.aspx)   
 [Classe IRowsetNotifyCP](../../data/oledb/irowsetnotifycp-class.md)