---
title: Classe CComEnum | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CComEnum
- atlcom/ATL::CComEnum
dev_langs:
- C++
helpviewer_keywords:
- CComEnum class
ms.assetid: bff7dd7b-eb6e-4d6e-96ed-2706e66c8b3b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 67904ec0c16fb1eddcf182d34f10cb09219dfc6e
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43767410"
---
# <a name="ccomenum-class"></a>Classe CComEnum

Essa classe define um objeto de enumerador COM base em uma matriz.

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

*Base de dados de*  
Uma interface de enumerador de COM. Ver [IEnumString](/windows/desktop/api/objidl/nn-objidl-ienumstring) para obter um exemplo.

*piid*  
Um ponteiro para a ID de interface da interface do enumerador.

*T*  
O tipo de item exposto pela interface do enumerador.

*Copiar*  
Um homogêneos [copie a classe da diretiva](../../atl/atl-copy-policy-classes.md).

*ThreadModel*  
O modelo de threading da classe. Esse parâmetro assume como padrão para o modelo de thread do objeto global usado no seu projeto.

## <a name="remarks"></a>Comentários

`CComEnum` define um objeto de enumerador COM base em uma matriz. Essa classe é análoga à [CComEnumOnSTL](../../atl/reference/ccomenumonstl-class.md) que implementa um enumerador com base em um contêiner de biblioteca padrão C++. Etapas típicas para usar essa classe são descritas abaixo. Para obter mais informações, consulte [ATL coleções e enumeradores](../../atl/atl-collections-and-enumerators.md).

## <a name="to-use-this-class"></a>Para usar essa classe:

- **TypeDef** uma especialização dessa classe.

- Use o **typedef** como o argumento de modelo em uma especialização de `CComObject`.

- Criar uma instância da `CComObject` especialização.

- Inicializar o objeto de enumerador chamando [CComEnumImpl::Init](../../atl/reference/ccomenumimpl-class.md#init).

- Retorne a interface de enumerador para o cliente.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

`Base`

[CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)

[CComEnumImpl](../../atl/reference/ccomenumimpl-class.md)

`CComEnum`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

## <a name="example"></a>Exemplo

O código mostrado abaixo fornece uma função reutilizável para criar e inicializar um objeto de enumerador.

[!code-cpp[NVC_ATL_COM#32](../../atl/codesnippet/cpp/ccomenum-class_1.h)]

Essa função de modelo pode ser usada para implementar o `_NewEnum` propriedade de uma interface de coleção, conforme mostrado abaixo:

[!code-cpp[NVC_ATL_COM#33](../../atl/codesnippet/cpp/ccomenum-class_2.h)]

Esse código cria uma **typedef** para `CComEnum` que expõe um vetor de variantes por meio de `IEnumVariant` interface. O `CVariantArrayCollection` classe especializada simplesmente `CreateEnumerator` para trabalhar com objetos de enumerador desse tipo e passa os argumentos necessários.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)   
[CComObjectThreadModel](atl-typedefs.md#ccomobjectthreadmodel)   
[Classe CComEnumImpl](../../atl/reference/ccomenumimpl-class.md)   
[Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)
