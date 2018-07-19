---
title: Classe CSimpleArrayEqualHelperFalse | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CSimpleArrayEqualHelperFalse
- ATLSIMPCOLL/ATL::CSimpleArrayEqualHelperFalse
- ATLSIMPCOLL/ATL::CSimpleArrayEqualHelperFalse::IsEqual
dev_langs:
- C++
helpviewer_keywords:
- CSimpleArrayEqualHelperFalse class
ms.assetid: 6918af6f-d23d-49eb-8482-c44272f5ffeb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a325da2edd4af8b8b0e6e965dc60df8c11bf8d30
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37882850"
---
# <a name="csimplearrayequalhelperfalse-class"></a>Classe CSimpleArrayEqualHelperFalse
Essa classe é um auxiliar para o [CSimpleArray](../../atl/reference/csimplearray-class.md) classe.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>  
class CSimpleArrayEqualHelperFalse
```  
  
#### <a name="parameters"></a>Parâmetros  
 *T*  
 Uma classe derivada.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSimpleArrayEqualHelperFalse::IsEqual](#isequal)|(Estático) Retorna falso.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe de características é um complemento para o `CSimpleArray` classe. IT sempre retorna false e Além disso, será chamada `ATLASSERT` com um argumento de false se ele nunca é referenciado. Em situações em que o teste de igualdade não está suficientemente definido, essa classe permite que uma matriz que contém elementos para operar corretamente para a maioria dos métodos, mas falhar de maneira bem definida para os métodos que dependem de comparações, como [CSimpleArray:: Localizar](../../atl/reference/csimplearray-class.md#find).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsimpcoll.h  
  
##  <a name="isequal"></a>  CSimpleArrayEqualHelperFalse::IsEqual  
 Retorna false.  
  
```
static bool IsEqual(const T&, const T&);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna false.  
  
### <a name="remarks"></a>Comentários  
 Esse método sempre retorna false e chamará `ATLASSERT` com um argumento FALSO se referenciado. A finalidade de `CSimpleArrayEqualHelperFalse::IsEqual` é forçar métodos usando comparações falhe de maneira bem definida, quando os testes de igualdade não foram definidos adequadamente.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CSimpleArrayEqualHelper](../../atl/reference/csimplearrayequalhelper-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
