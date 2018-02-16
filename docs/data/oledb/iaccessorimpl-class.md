---
title: Classe IAccessorImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- IAccessorImpl
dev_langs:
- C++
helpviewer_keywords:
- IAccessorImpl class
ms.assetid: 768606da-8b71-417c-a62c-88069ce7730d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 7cfc33432d12ac00c834d16f83cc26404e92c63e
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="iaccessorimpl-class"></a>Classe IAccessorImpl
Fornece uma implementação de [IAccessor](https://msdn.microsoft.com/en-us/library/ms719672.aspx) interface.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class T, 
          class BindType = ATLBINDINGS,
          class BindingVector = CAtlMap <HACCESSOR hAccessor, BindType* pBindingsStructure>>  
class ATL_NO_VTABLE IAccessorImpl : public IAccessorImplBase<BindType>  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Sua classe de objeto do conjunto de linhas ou de comando.  
  
 `BindType`  
 Unidade de armazenamento de informações de associação. O padrão é o **ATLBINDINGS** estrutura (consulte atldb.h).  
  
 `BindingVector`  
 Unidade de armazenamento de informações de coluna. O padrão é [CAtlMap](../../atl/reference/catlmap-class.md) onde o elemento chave é um **HACCESSOR** valor e o elemento de valor é um ponteiro para um `BindType` estrutura.  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[IAccessorImpl](../../data/oledb/iaccessorimpl-class.md)|O construtor.|  
  
### <a name="interface-methods"></a>Métodos de interface  
  
|||  
|-|-|  
|[AddRefAccessor](../../data/oledb/iaccessorimpl-addrefaccessor.md)|Adiciona uma contagem de referência a acessador existente.|  
|[CreateAccessor](../../data/oledb/iaccessorimpl-createaccessor.md)|Cria um acessador de um conjunto de associações.|  
|[GetBindings](../../data/oledb/iaccessorimpl-getbindings.md)|Retorna as associações em um acessador.|  
|[ReleaseAccessor](../../data/oledb/iaccessorimpl-releaseaccessor.md)|Libera um acessador.|  
  
## <a name="remarks"></a>Comentários  
 Isso é obrigatório em conjuntos de linhas e comandos. OLE DB requer provedores implementar um **HACCESSOR**, que é uma marca para uma matriz de [DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx) estruturas. **HACCESSOR**s fornecidos pelo `IAccessorImpl` são endereços do `BindType` estruturas. Por padrão, `BindType` é definido como um **ATLBINDINGS** na `IAccessorImpl`da definição do modelo. `BindType` Fornece um mecanismo usado pelo `IAccessorImpl` para controlar o número de elementos no seu **DBBINDING** , bem como os sinalizadores de contagem e o acessador de uma referência de matriz.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)