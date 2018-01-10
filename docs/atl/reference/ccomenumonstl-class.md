---
title: Classe CComEnumOnSTL | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComEnumOnSTL
- atlcom/ATL::CComEnumOnSTL
dev_langs: C++
helpviewer_keywords: CComEnumOnSTL class
ms.assetid: befe1a44-7a00-4f28-9a2e-cc0fa526643c
caps.latest.revision: "21"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d42d99baf154bc5434f2d771aeaabb71c5502b30
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ccomenumonstl-class"></a>Classe CComEnumOnSTL
Essa classe define um objeto de enumerador COM base em uma coleção de biblioteca padrão C++.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Base,
    const IID* piid, class T, class Copy, class CollType, class ThreadModel = CComObjectThreadModel>  
class ATL_NO_VTABLE CComEnumOnSTL : public IEnumOnSTLImpl<Base, piid,
 T,
    Copy,
 CollType>,
    public CComObjectRootEx<ThreadModel>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Base`  
 Um enumerador COM ( [IEnumXXXX](https://msdn.microsoft.com/library/ms680089.aspx)) interface.  
  
 `piid`  
 Um ponteiro para a ID de interface da interface do enumerador.  
  
 `T`  
 O tipo de item exposto pela interface do enumerador.  
  
 `Copy`  
 Um [copiar política](../../atl/atl-copy-policy-classes.md) classe.  
  
 `CollType`  
 Uma classe de contêiner da biblioteca padrão C++.  
  
## <a name="remarks"></a>Comentários  
 `CComEnumOnSTL`define um objeto de enumerador COM base em uma coleção de biblioteca padrão C++. Essa classe pode ser usada sozinha ou em conjunto com [ICollectionOnSTLImpl](../../atl/reference/icollectiononstlimpl-class.md). As etapas típicas para usar essa classe são descritas abaixo. Para obter mais informações, consulte [ATL coleções e enumeradores](../../atl/atl-collections-and-enumerators.md).  
  
## <a name="to-use-this-class-with-icollectiononstlimpl"></a>Para usar essa classe com ICollectionOnSTLImpl:  
  
- `typedef`uma especialização dessa classe.  
  
-   Use o `typedef` como o argumento de modelo final em uma especialização de `ICollectionOnSTLImpl`.  
  
 Consulte [ATL coleções e enumeradores](../../atl/atl-collections-and-enumerators.md) para obter um exemplo.  
  
## <a name="to-use-this-class-independently-of-icollectiononstlimpl"></a>Para usar essa classe independentemente ICollectionOnSTLImpl:  
  
- `typedef`uma especialização dessa classe.  
  
-   Use o `typedef` como o argumento de modelo em uma especialização de `CComObject`.  
  
-   Criar uma instância do `CComObject` especialização.  
  
-   Inicializar o objeto de enumerador chamando [IEnumOnSTLImpl::Init](../../atl/reference/ienumonstlimpl-class.md#init).  
  
-   Retorna a interface de enumerador para o cliente.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CComObjectRootBase`  
  
 `Base`  
  
 [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)  
  
 [IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md)  
  
 `CComEnumOnSTL`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
## <a name="example"></a>Exemplo  
 O código mostrado a seguir fornece uma função genérica para lidar com a criação e a inicialização de um objeto de enumerador:  
  
 [!code-cpp[NVC_ATL_COM#34](../../atl/codesnippet/cpp/ccomenumonstl-class_1.h)]  
  
 Essa função de modelo pode ser usada para implementar o `_NewEnum` propriedade de uma interface de coleção, conforme mostrado abaixo:  
  
 [!code-cpp[NVC_ATL_COM#35](../../atl/codesnippet/cpp/ccomenumonstl-class_2.h)]  
  
 Esse código cria um `typedef` para `CComEnumOnSTL` que expõe um vetor de `CComVariant`s por meio do **IEnumVariant** interface. O **CVariantCollection** classe simplesmente especializada **CreateSTLEnumerator** para trabalhar com objetos de enumerador desse tipo.  
  
## <a name="see-also"></a>Consulte também  
 [IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md)   
 [ATLCollections: Demonstra ICollectionOnSTLImpl, CComEnumOnSTL e Classes de política personalizada de cópia](../../visual-cpp-samples.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)   
 [CComObjectThreadModel](atl-typedefs.md#ccomobjectthreadmodel)   
 [Classe IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md)
