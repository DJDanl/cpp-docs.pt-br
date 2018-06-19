---
title: Classe CSimpleArrayEqualHelper | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d6660f72dbd91a41670b3c5f8772d21caf4b8abc
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32362122"
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
 Essa classe de características é um suplemento de `CSimpleArray` classe. Ele fornece um método para comparar dois elementos armazenada em um `CSimpleArray` objeto. Por padrão, os elementos são comparados usando **operator=()**, mas se a matriz contém tipos de dados complexos que não têm seu próprios operador de igualdade, você precisará substituir essa classe.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsimpcoll.h  
  
##  <a name="isequal"></a>  CSimpleArrayEqualHelper::IsEqual  
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
