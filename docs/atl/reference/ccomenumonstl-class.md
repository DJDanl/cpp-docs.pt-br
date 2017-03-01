---
title: Classe CComEnumOnSTL | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComEnumOnSTL
dev_langs:
- C++
helpviewer_keywords:
- CComEnumOnSTL class
ms.assetid: befe1a44-7a00-4f28-9a2e-cc0fa526643c
caps.latest.revision: 21
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: 23e234f82ce8c77a6ebde50070475deeab59f362
ms.lasthandoff: 02/25/2017

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
 A [copiar diretiva](../../atl/atl-copy-policy-classes.md) classe.  
  
 `CollType`  
 Uma classe de contêiner da biblioteca padrão C++.  
  
## <a name="remarks"></a>Comentários  
 `CComEnumOnSTL`define um objeto de enumerador COM base em uma coleção de biblioteca padrão C++. Essa classe pode ser usada sozinha ou em conjunto com [ICollectionOnSTLImpl](../../atl/reference/icollectiononstlimpl-class.md). Etapas comuns de uso dessa classe são descritas abaixo. Para obter mais informações, consulte [ATL coleções e enumeradores](../../atl/atl-collections-and-enumerators.md).  
  
## <a name="to-use-this-class-with-icollectiononstlimpl"></a>Para usar essa classe com ICollectionOnSTLImpl:  
  
- `typedef`uma especialização da classe.  
  
-   Use o `typedef` como o argumento de modelo final em uma especialização de `ICollectionOnSTLImpl`.  
  
 Consulte [ATL coleções e enumeradores](../../atl/atl-collections-and-enumerators.md) para obter um exemplo.  
  
## <a name="to-use-this-class-independently-of-icollectiononstlimpl"></a>Para usar essa classe independentemente ICollectionOnSTLImpl:  
  
- `typedef`uma especialização da classe.  
  
-   Use o `typedef` como o argumento de modelo em uma especialização de `CComObject`.  
  
-   Criar uma instância do `CComObject` especialização.  
  
-   Inicializar o objeto enumerador chamando [IEnumOnSTLImpl::Init](../../atl/reference/ienumonstlimpl-class.md#init).  
  
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
  
 [!code-cpp[NVC_ATL_COM&#34;](../../atl/codesnippet/cpp/ccomenumonstl-class_1.h)]  
  
 Essa função de modelo pode ser usada para implementar o `_NewEnum` propriedade de uma interface de coleção, como mostrado abaixo:  
  
 [!code-cpp[NVC_ATL_COM&#35;](../../atl/codesnippet/cpp/ccomenumonstl-class_2.h)]  
  
 Esse código cria um `typedef` para `CComEnumOnSTL` que expõe um vetor de `CComVariant`s por meio do **IEnumVariant** interface. O **CVariantCollection** classe simplesmente especializada **CreateSTLEnumerator** para trabalhar com objetos do enumerador desse tipo.  
  
## <a name="see-also"></a>Consulte também  
 [IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md)   
 [ATLCollections: Demonstra ICollectionOnSTLImpl, CComEnumOnSTL e Classes de política de cópia personalizada](../../visual-cpp-samples.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)   
 [CComObjectThreadModel](atl-typedefs.md#ccomobjectthreadmodel)   
 [Classe IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md)

