---
title: Classe ICommandImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: ICommandImpl
dev_langs: C++
helpviewer_keywords: ICommandImpl class
ms.assetid: ef285fef-0d66-45e6-a762-b03357098e3b
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: c553effb6ad6a4aa9571eed62f30e4e83910afbd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="icommandimpl-class"></a>Classe ICommandImpl
Fornece a implementação para o [ICommand](https://msdn.microsoft.com/en-us/library/ms709737.aspx) interface.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class T, class CommandBase = ICommand>   
class ATL_NO_VTABLE ICommandImpl : public CommandBase  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe derivada de `ICommandImpl`.  
  
 `CommandBase`  
 Uma interface de comando. O padrão é `ICommand`.  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[CancelExecution](../../data/oledb/icommandimpl-cancelexecution.md)|Cancela a execução do comando atual.|  
|[Cancelar](../../data/oledb/icommandimpl-cancel.md)|Cancela a execução do comando atual.|  
|[CreateRowset](../../data/oledb/icommandimpl-createrowset.md)|Cria um objeto de conjunto de linhas.|  
|[Executar](../../data/oledb/icommandimpl-execute.md)|Executa o comando.|  
|[GetDBSession](../../data/oledb/icommandimpl-getdbsession.md)|Retorna um ponteiro de interface para a sessão que criou o comando.|  
|[ICommandImpl](../../data/oledb/icommandimpl-icommandimpl.md)|O construtor.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|[m_bCancel](../../data/oledb/icommandimpl-m-bcancel.md)|Indica se o comando deve ser cancelada.|  
|[m_bCancelWhenExecuting](../../data/oledb/icommandimpl-m-bcancelwhenexecuting.md)|Indica se o comando deve ser cancelada durante a execução.|  
|[m_bIsExecuting](../../data/oledb/icommandimpl-m-bisexecuting.md)|Indica se o comando está em execução.|  
  
## <a name="remarks"></a>Comentários  
 Uma interface obrigatória no objeto de comando.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)