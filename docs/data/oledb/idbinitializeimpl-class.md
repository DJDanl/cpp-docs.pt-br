---
title: Classe IDBInitializeImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL.IDBInitializeImpl<T>
- ATL::IDBInitializeImpl<T>
- IDBInitializeImpl
- ATL::IDBInitializeImpl
- ATL.IDBInitializeImpl
dev_langs: C++
helpviewer_keywords: IDBInitializeImpl class
ms.assetid: e4182f81-0443-44f5-a0d3-e7e075d6f883
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: a7a51023f167eee5fbd4082486409f4e11a15547
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="idbinitializeimpl-class"></a>Classe IDBInitializeImpl
Fornece uma implementação para o [IDBInitialize](https://msdn.microsoft.com/en-us/library/ms713706.aspx) interface.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class T>  
class ATL_NO_VTABLE IDBInitializeImpl : public IDBInitialize  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe derivada de `IDBInitializeImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[IDBInitializeImpl](../../data/oledb/idbinitializeimpl-idbinitializeimpl.md)|O construtor.|  
  
### <a name="interface-methods"></a>Métodos de interface  
  
|||  
|-|-|  
|[Inicializar](../../data/oledb/idbinitializeimpl-initialize.md)|Inicia o provedor.|  
|[Não inicializar](../../data/oledb/idbinitializeimpl-uninitialize.md)|Interrompe o provedor.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|[m_dwStatus](../../data/oledb/idbinitializeimpl-m-dwstatus.md)|Sinalizadores de fonte de dados.|  
|[m_pCUtlPropInfo](../../data/oledb/idbinitializeimpl-m-pcutlpropinfo.md)|Um ponteiro para a implementação de informações de propriedades de banco de dados.|  
  
## <a name="remarks"></a>Comentários  
 Uma interface obrigatória em objetos de fonte de dados e uma interface opcional em enumeradores.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)