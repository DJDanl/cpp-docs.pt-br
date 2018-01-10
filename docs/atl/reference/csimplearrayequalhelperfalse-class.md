---
title: Classe CSimpleArrayEqualHelperFalse | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CSimpleArrayEqualHelperFalse
- ATLSIMPCOLL/ATL::CSimpleArrayEqualHelperFalse
- ATLSIMPCOLL/ATL::CSimpleArrayEqualHelperFalse::IsEqual
dev_langs: C++
helpviewer_keywords: CSimpleArrayEqualHelperFalse class
ms.assetid: 6918af6f-d23d-49eb-8482-c44272f5ffeb
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 28d43b6a83842373c2fc169ce43022f1912c4e0f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="csimplearrayequalhelperfalse-class"></a>Classe CSimpleArrayEqualHelperFalse
Essa classe é um auxiliar de [CSimpleArray](../../atl/reference/csimplearray-class.md) classe.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>  
class CSimpleArrayEqualHelperFalse
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Uma classe derivada.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSimpleArrayEqualHelperFalse::IsEqual](#isequal)|(Estático) Retorna falso.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe de características é um complemento para o `CSimpleArray` classe. IT sempre retorna false e Além disso, chame `ATLASSERT` com um argumento de falso se ele já está referenciado. Em situações em que o teste de igualdade suficientemente não está definido, essa classe permite que uma matriz que contém elementos para operar corretamente para a maioria dos métodos, mas falhar de maneira bem definida para métodos que dependem de comparações como [CSimpleArray:: Localizar](../../atl/reference/csimplearray-class.md#find).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsimpcoll.h  
  
##  <a name="isequal"></a>CSimpleArrayEqualHelperFalse::IsEqual  
 Retorna false.  
  
```
static bool IsEqual(const T&, const T&);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna false.  
  
### <a name="remarks"></a>Comentários  
 Esse método sempre retorna false e chamará `ATLASSERT` com um argumento de false se referenciado. A finalidade de `CSimpleArrayEqualHelperFalse::IsEqual` é forçar métodos usando comparações de falha de maneira bem definida em testes de igualdade não foram definidas corretamente.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CSimpleArrayEqualHelper](../../atl/reference/csimplearrayequalhelper-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
