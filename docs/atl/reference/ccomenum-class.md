---
title: Classe CComEnum
ms.date: 11/04/2016
f1_keywords:
- CComEnum
- atlcom/ATL::CComEnum
helpviewer_keywords:
- CComEnum class
ms.assetid: bff7dd7b-eb6e-4d6e-96ed-2706e66c8b3b
ms.openlocfilehash: 7252eb2fa5d34618a1c38484a2506bae27a1106a
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497216"
---
# <a name="ccomenum-class"></a>Classe CComEnum

Essa classe define um objeto enumerador COM com base em uma matriz.

## <a name="syntax"></a>Sintaxe

```
template <class Base,
    const IID* piid, class T, class Copy, class ThreadModel = CcomObjectThreadModel>
class ATL_NO_VTABLE CComEnum : public CComEnumImpl<Base, piid,
T,
    Copy>,
public CComObjectRootEx<ThreadModel>
```

#### <a name="parameters"></a>Parâmetros

*Polybase*<br/>
Uma interface de enumerador COM. Consulte [IEnumString](/windows/win32/api/objidl/nn-objidl-ienumstring) para obter um exemplo.

*piid*<br/>
Um ponteiro para a ID de interface da interface do enumerador.

*T*<br/>
O tipo de item exposto pela interface do enumerador.

*Copiar*<br/>
Uma [classe de política de cópia](../../atl/atl-copy-policy-classes.md)homogênea.

*ThreadModel*<br/>
O modelo de Threading da classe. Esse parâmetro assume como padrão o modelo de thread de objeto global usado em seu projeto.

## <a name="remarks"></a>Comentários

`CComEnum`define um objeto enumerador COM com base em uma matriz. Essa classe é análoga a [CComEnumOnSTL](../../atl/reference/ccomenumonstl-class.md) que implementa um enumerador com base C++ em um contêiner de biblioteca padrão. As etapas típicas para usar essa classe são descritas abaixo. Para obter mais informações, consulte [coleções e enumeradores do ATL](../../atl/atl-collections-and-enumerators.md).

## <a name="to-use-this-class"></a>Para usar esta classe:

- **typedef** uma especialização desta classe.

- Use o **typedef** como o argumento de modelo em uma especialização de `CComObject`.

- Crie uma instância da `CComObject` especialização.

- Inicialize o objeto enumerador chamando [CComEnumImpl:: init](../../atl/reference/ccomenumimpl-class.md#init).

- Retornar a interface do enumerador para o cliente.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

`Base`

[CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)

[CComEnumImpl](../../atl/reference/ccomenumimpl-class.md)

`CComEnum`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

## <a name="example"></a>Exemplo

O código mostrado abaixo fornece uma função reutilizável para criar e inicializar um objeto enumerador.

[!code-cpp[NVC_ATL_COM#32](../../atl/codesnippet/cpp/ccomenum-class_1.h)]

Essa função de modelo pode ser usada para implementar `_NewEnum` a propriedade de uma interface de coleção, conforme mostrado abaixo:

[!code-cpp[NVC_ATL_COM#33](../../atl/codesnippet/cpp/ccomenum-class_2.h)]

Esse código cria um **typedef** para `CComEnum` que expõe um vetor de variantes por meio `IEnumVariant` da interface. A `CVariantArrayCollection` classe simplesmente é `CreateEnumerator` especializada em trabalhar com objetos enumeradores desse tipo e passa os argumentos necessários.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[CComObjectThreadModel](atl-typedefs.md#ccomobjectthreadmodel)<br/>
[Classe CComEnumImpl](../../atl/reference/ccomenumimpl-class.md)<br/>
[Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)
