---
title: Classe CComEnum | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComEnum
- atlcom/ATL::CComEnum
dev_langs: C++
helpviewer_keywords: CComEnum class
ms.assetid: bff7dd7b-eb6e-4d6e-96ed-2706e66c8b3b
caps.latest.revision: "20"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 417dcf3ff0d578c4febcefb5caa6989ed98bb209
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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
 `Base`  
 Um enumerador COM ( [IEnumXXXX](https://msdn.microsoft.com/library/ms680089.aspx)) interface.  
  
 `piid`  
 Um ponteiro para a ID de interface da interface do enumerador.  
  
 `T`  
 O tipo de item exposto pela interface do enumerador.  
  
 `Copy`  
 Um homogênea [Copiar classe política](../../atl/atl-copy-policy-classes.md).  
  
 `ThreadModel`  
 O modelo de threading da classe. Esse parâmetro padrão para o modelo de thread do objeto global usado no seu projeto.  
  
## <a name="remarks"></a>Comentários  
 `CComEnum`define um objeto de enumerador COM base em uma matriz. Essa classe é análoga a [CComEnumOnSTL](../../atl/reference/ccomenumonstl-class.md) que implementa um enumerador com base em um contêiner de biblioteca padrão C++. As etapas típicas para usar essa classe são descritas abaixo. Para obter mais informações, consulte [ATL coleções e enumeradores](../../atl/atl-collections-and-enumerators.md).  
  
## <a name="to-use-this-class"></a>Para usar essa classe:  
  
- `typedef`uma especialização dessa classe.  
  
-   Use o `typedef` como o argumento de modelo em uma especialização de `CComObject`.  
  
-   Criar uma instância do `CComObject` especialização.  
  
-   Inicializar o objeto de enumerador chamando [CComEnumImpl::Init](../../atl/reference/ccomenumimpl-class.md#init).  
  
-   Retorna a interface de enumerador para o cliente.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CComObjectRootBase`  
  
 `Base`  
  
 [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)  
  
 [CComEnumImpl](../../atl/reference/ccomenumimpl-class.md)  
  
 `CComEnum`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
## <a name="example"></a>Exemplo  
 O código mostrado abaixo fornece uma função reutilizável para criar e inicializar um objeto de enumerador.  
  
 [!code-cpp[NVC_ATL_COM#32](../../atl/codesnippet/cpp/ccomenum-class_1.h)]  
  
 Essa função de modelo pode ser usada para implementar o `_NewEnum` propriedade de uma interface de coleção, conforme mostrado abaixo:  
  
 [!code-cpp[NVC_ATL_COM#33](../../atl/codesnippet/cpp/ccomenum-class_2.h)]  
  
 Esse código cria um `typedef` para `CComEnum` que expõe um vetor de **VARIANT**s por meio de **IEnumVariant** interface. O **CVariantArrayCollection** classe simplesmente especializada **CreateEnumerator** para trabalhar com objetos de enumerador desse tipo e passa os argumentos necessários.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [CComObjectThreadModel](atl-typedefs.md#ccomobjectthreadmodel)   
 [Classe CComEnumImpl](../../atl/reference/ccomenumimpl-class.md)   
 [Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)
