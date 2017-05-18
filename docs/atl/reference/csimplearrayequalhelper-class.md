---
title: Classe CSimpleArrayEqualHelper | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CSimpleArrayEqualHelper
- ATLSIMPCOLL/ATL::CSimpleArrayEqualHelper
- ATLSIMPCOLL/ATL::CSimpleArrayEqualHelper::IsEqual
dev_langs:
- C++
helpviewer_keywords:
- CSimpleArrayEqualHelper class
ms.assetid: a2b55d89-78c9-42ef-842c-5304c6d20ad6
caps.latest.revision: 19
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: 4a87879683257c66de5fe4e720dd29fa4c47031d
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="csimplearrayequalhelper-class"></a>Classe CSimpleArrayEqualHelper
Essa classe é um auxiliar de [CSimpleArray](../../atl/reference/csimplearray-class.md) classe.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>  
class CSimpleArrayEqualHelper
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Uma classe derivada.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSimpleArrayEqualHelper::IsEqual](#isequal)|(Estático) Testa dois `CSimpleArray` elementos de igualdade do objeto.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe de características é um suplemento de `CSimpleArray` classe. Ele fornece um método para comparar dois elementos armazenados em uma `CSimpleArray` objeto. Por padrão, os elementos são comparados usando **operator=()**, mas se a matriz contém tipos de dados complexos que não possuem seu próprios operador de igualdade, você precisará substituir essa classe.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsimpcoll.h  
  
##  <a name="isequal"></a>CSimpleArrayEqualHelper::IsEqual  
 Testa dois `CSimpleArray` elementos de igualdade do objeto.  
  
```
static bool IsEqual(
    const T& t1,
    const T& t2);
```  
  
### <a name="parameters"></a>Parâmetros  
 *T1*  
 Um objeto do tipo T.  
  
 *T2*  
 Um objeto do tipo T.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se os elementos forem iguais; caso contrário, false.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CSimpleArray](../../atl/reference/csimplearray-class.md)   
 [Classe CSimpleArrayEqualHelperFalse](../../atl/reference/csimplearrayequalhelperfalse-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

