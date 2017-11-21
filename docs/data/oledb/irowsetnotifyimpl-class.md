---
title: Classe IRowsetNotifyImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL.IRowsetNotifyImpl
- ATL::IRowsetNotifyImpl
- IRowsetNotifyImpl
dev_langs: C++
helpviewer_keywords: IRowsetNotifyImpl class
ms.assetid: fbfd0cb2-38ff-4b42-899a-8de902f834b8
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 7473e63c7ca67dff200d5cf96f1774ca9a2d6817
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="irowsetnotifyimpl-class"></a>Classe IRowsetNotifyImpl
Implementa e registra [IRowsetNotify](https://msdn.microsoft.com/en-us/library/ms712959.aspx) no consumidor (também conhecido como o "sink") para que ele possa manipular notificações.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class ATL_NO_VTABLE IRowsetNotifyImpl : public IRowsetNotify  
```  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[OnFieldChange](../../data/oledb/irowsetnotifyimpl-onfieldchange.md)|Notifica o consumidor de qualquer alteração no valor de uma coluna.|  
|[OnRowChange](../../data/oledb/irowsetnotifyimpl-onrowchange.md)|Notifica o consumidor da primeira alteração para uma linha ou de qualquer alteração que afeta toda a linha.|  
|[OnRowsetChange](../../data/oledb/irowsetnotifyimpl-onrowsetchange.md)|Notifica o consumidor de qualquer alteração que afetam todo o conjunto de linhas.|  
  
## <a name="remarks"></a>Comentários  
 Consulte [recebendo notificações](../../data/oledb/receiving-notifications.md) sobre como implementar a interface de ponto de conexão do consumidor.  
  
 `IRowsetNotifyImpl`Fornece uma implementação fictícia para `IRowsetNotify`, com funções vazias para o `IRowsetNotify` métodos [OnFieldChange](https://msdn.microsoft.com/en-us/library/ms715961.aspx), [OnRowChange](https://msdn.microsoft.com/en-us/library/ms722694.aspx), e [OnRowsetChange](https://msdn.microsoft.com/en-us/library/ms722669.aspx). Se você herdar desta classe ao implementar um `IRowsetNotify` interface, você pode implementar apenas os métodos que você precisa. Você também precisa fornecer implementações vazias para os outros métodos por conta própria.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [IRowsetNotify](https://msdn.microsoft.com/en-us/library/ms712959.aspx)   
 [Classe IRowsetNotifyCP](../../data/oledb/irowsetnotifycp-class.md)