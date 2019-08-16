---
title: Classe CComEnumOnSTL
ms.date: 11/04/2016
f1_keywords:
- CComEnumOnSTL
- atlcom/ATL::CComEnumOnSTL
helpviewer_keywords:
- CComEnumOnSTL class
ms.assetid: befe1a44-7a00-4f28-9a2e-cc0fa526643c
ms.openlocfilehash: ab11ea5e5347c9c8684e8710e9742fdbcad8a46b
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497160"
---
# <a name="ccomenumonstl-class"></a>Classe CComEnumOnSTL

Essa classe define um objeto enumerador COM com base C++ em uma coleção de bibliotecas padrão.

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

*Polybase*<br/>
Um enumerador COM. Consulte [IEnumString](/windows/win32/api/objidl/nn-objidl-ienumstring) para obter um exemplo.

*piid*<br/>
Um ponteiro para a ID de interface da interface do enumerador.

*T*<br/>
O tipo de item exposto pela interface do enumerador.

*Copiar*<br/>
Uma classe de [política de cópia](../../atl/atl-copy-policy-classes.md) .

*CollType*<br/>
Uma C++ classe de contêiner de biblioteca padrão.

## <a name="remarks"></a>Comentários

`CComEnumOnSTL`define um objeto enumerador COM com base C++ em uma coleção de bibliotecas padrão. Essa classe pode ser usada sozinha ou em conjunto com [ICollectionOnSTLImpl](../../atl/reference/icollectiononstlimpl-class.md). As etapas típicas para usar essa classe são descritas abaixo. Para obter mais informações, consulte [coleções e enumeradores do ATL](../../atl/atl-collections-and-enumerators.md).

## <a name="to-use-this-class-with-icollectiononstlimpl"></a>Para usar essa classe com ICollectionOnSTLImpl:

- **typedef** uma especialização desta classe.

- Use o **typedef** como o argumento de modelo final em uma especialização de `ICollectionOnSTLImpl`.

Consulte [coleções e enumeradores da ATL](../../atl/atl-collections-and-enumerators.md) para obter um exemplo.

## <a name="to-use-this-class-independently-of-icollectiononstlimpl"></a>Para usar essa classe independentemente do ICollectionOnSTLImpl:

- **typedef** uma especialização desta classe.

- Use o **typedef** como o argumento de modelo em uma especialização de `CComObject`.

- Crie uma instância da `CComObject` especialização.

- Inicialize o objeto enumerador chamando [IEnumOnSTLImpl:: init](../../atl/reference/ienumonstlimpl-class.md#init).

- Retornar a interface do enumerador para o cliente.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

`Base`

[CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)

[IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md)

`CComEnumOnSTL`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

## <a name="example"></a>Exemplo

O código mostrado abaixo fornece uma função genérica para manipular a criação e a inicialização de um objeto enumerador:

[!code-cpp[NVC_ATL_COM#34](../../atl/codesnippet/cpp/ccomenumonstl-class_1.h)]

Essa função de modelo pode ser usada para implementar `_NewEnum` a propriedade de uma interface de coleção, conforme mostrado abaixo:

[!code-cpp[NVC_ATL_COM#35](../../atl/codesnippet/cpp/ccomenumonstl-class_2.h)]

Esse código cria um **typedef** para `CComEnumOnSTL` que expõe um vetor de `CComVariant`s por meio da `IEnumVariant` interface. A `CVariantCollection` classe simplesmente é `CreateSTLEnumerator` especializada em trabalhar com objetos enumeradores desse tipo.

## <a name="see-also"></a>Consulte também

[IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md)<br/>
[Exemplo de ATLCollections: Demonstra ICollectionOnSTLImpl, CComEnumOnSTL e classes de política de cópia personalizada](../../overview/visual-cpp-samples.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)<br/>
[CComObjectThreadModel](atl-typedefs.md#ccomobjectthreadmodel)<br/>
[Classe IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md)
