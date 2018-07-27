---
title: Classe IDBCreateSessionImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- IDBCreateSessionImpl
- ATL.IDBCreateSessionImpl
- ATL::IDBCreateSessionImpl
- IDBCreateSessionImpl::CreateSession
- IDBCreateSessionImpl.CreateSession
- CreateSession
dev_langs:
- C++
helpviewer_keywords:
- IDBCreateSessionImpl class
- CreateSession method
ms.assetid: 48c02c5c-8362-45ac-af8e-bb119cf8c5c7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 02701b03de074823da3cc7fcd229056195fd9a85
ms.sourcegitcommit: b0d6777cf4b580d093eaf6104d80a888706e7578
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/26/2018
ms.locfileid: "39269453"
---
# <a name="idbcreatesessionimpl-class"></a>Classe IDBCreateSessionImpl
Fornece uma implementação para o [IDBCreateSession](https://msdn.microsoft.com/library/ms724076.aspx) interface.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class SessionClass>  
class ATL_NO_VTABLE IDBCreateSessionImpl   
   : public IDBCreateSession  
```  
  
### <a name="parameters"></a>Parâmetros  
 *T*  
 SUA CLASSE, DERIVADA DE  
  
 *SessionClass*  
 O objeto de sessão.  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h 
  
## <a name="members"></a>Membros  
  
### <a name="interface-methods"></a>Métodos de interface  
  
|||  
|-|-|  
|[CreateSession](#createsession)|Cria uma nova sessão do objeto de fonte de dados e retorna a interface solicitada a sessão recém-criada.|  
  
## <a name="remarks"></a>Comentários  
 Uma interface obrigatória em objetos de fonte de dados.  

## <a name="createsession"></a> Idbcreatesessionimpl:: CreateSession
Cria uma nova sessão do objeto de fonte de dados e retorna a interface solicitada a sessão recém-criada.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
      STDMETHOD(CreateSession)(IUnknown * pUnkOuter,   
   REFIID riid,   
   IUnknown ** ppDBSession);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [idbcreatesession::](https://msdn.microsoft.com/library/ms714942.aspx) na *referência do programador do OLE DB*.   
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)
