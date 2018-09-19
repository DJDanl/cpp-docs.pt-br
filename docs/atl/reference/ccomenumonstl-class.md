---
title: Classe CComEnumOnSTL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CComEnumOnSTL
- atlcom/ATL::CComEnumOnSTL
dev_langs:
- C++
helpviewer_keywords:
- CComEnumOnSTL class
ms.assetid: befe1a44-7a00-4f28-9a2e-cc0fa526643c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a4821ba572d2719ebba6c693cc39b96971002512
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46106318"
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

*Base de dados de*<br/>
Um enumerador de COM. Ver [IEnumString](/windows/desktop/api/objidl/nn-objidl-ienumstring) para obter um exemplo.

*piid*<br/>
Um ponteiro para a ID de interface da interface do enumerador.

*T*<br/>
O tipo de item exposto pela interface do enumerador.

*Copiar*<br/>
Um [copiar política](../../atl/atl-copy-policy-classes.md) classe.

*CollType*<br/>
Uma classe de contêiner da biblioteca padrão C++.

## <a name="remarks"></a>Comentários

`CComEnumOnSTL` define um objeto de enumerador COM base em uma coleção de biblioteca padrão C++. Essa classe pode ser usada por conta própria ou em conjunto com [ICollectionOnSTLImpl](../../atl/reference/icollectiononstlimpl-class.md). Etapas típicas para usar essa classe são descritas abaixo. Para obter mais informações, consulte [ATL coleções e enumeradores](../../atl/atl-collections-and-enumerators.md).

## <a name="to-use-this-class-with-icollectiononstlimpl"></a>Para usar essa classe com ICollectionOnSTLImpl:

- **TypeDef** uma especialização dessa classe.

- Use o **typedef** como o argumento de modelo final em uma especialização de `ICollectionOnSTLImpl`.

Ver [ATL coleções e enumeradores](../../atl/atl-collections-and-enumerators.md) para obter um exemplo.

## <a name="to-use-this-class-independently-of-icollectiononstlimpl"></a>Para usar essa classe independentemente ICollectionOnSTLImpl:

- **TypeDef** uma especialização dessa classe.

- Use o **typedef** como o argumento de modelo em uma especialização de `CComObject`.

- Criar uma instância da `CComObject` especialização.

- Inicializar o objeto de enumerador chamando [IEnumOnSTLImpl::Init](../../atl/reference/ienumonstlimpl-class.md#init).

- Retorne a interface de enumerador para o cliente.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

`Base`

[CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)

[IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md)

`CComEnumOnSTL`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

## <a name="example"></a>Exemplo

O código mostrado a seguir fornece uma função genérica para lidar com a criação e inicialização de um objeto de enumerador:

[!code-cpp[NVC_ATL_COM#34](../../atl/codesnippet/cpp/ccomenumonstl-class_1.h)]

Essa função de modelo pode ser usada para implementar o `_NewEnum` propriedade de uma interface de coleção, conforme mostrado abaixo:

[!code-cpp[NVC_ATL_COM#35](../../atl/codesnippet/cpp/ccomenumonstl-class_2.h)]

Esse código cria uma **typedef** para `CComEnumOnSTL` que expõe um vetor de `CComVariant`s por meio do `IEnumVariant` interface. O `CVariantCollection` classe especializada simplesmente `CreateSTLEnumerator` para trabalhar com objetos de enumerador desse tipo.

## <a name="see-also"></a>Consulte também

[IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md)<br/>
[Exemplo de ATLCollections: Demonstra Classes de política de cópia personalizada de ICollectionOnSTLImpl e CComEnumOnSTL](../../visual-cpp-samples.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)<br/>
[CComObjectThreadModel](atl-typedefs.md#ccomobjectthreadmodel)<br/>
[Classe IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md)
