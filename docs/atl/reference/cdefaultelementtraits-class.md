---
title: Classe CDefaultElementTraits | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CDefaultElementTraits
- atlcoll/ATL::CDefaultElementTraits
dev_langs:
- C++
helpviewer_keywords:
- CDefaultElementTraits class
ms.assetid: ac5ee610-7957-4b7c-92b6-38ff72e4118e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 16574857f4f5bd4566fcef551fa5e56290b7ce6b
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32360956"
---
# <a name="cdefaultelementtraits-class"></a>Classe CDefaultElementTraits
Essa classe fornece funções e métodos padrão para uma classe de coleção.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <typename T>  
class CDefaultElementTraits : public CElementTraitsBase<T>,
    public CDefaultHashTraits<T>,
    public CDefaultCompareTraits<T>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados a serem armazenados na coleção.  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece métodos e funções estáticas padrão para mover, copiar, comparando e armazenados em um objeto de classe de coleção de elementos de hash. Essa classe é derivada suas funções e métodos de [CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md), [CDefaultHashTraits](../../atl/reference/cdefaulthashtraits-class.md), e [CDefaultCompareTraits](../../atl/reference/cdefaultcomparetraits-class.md)e é usada por [ CElementTraits](../../atl/reference/celementtraits-class.md), [CPrimitiveElementTraits](../../atl/reference/cprimitiveelementtraits-class.md), e [CHeapPtrElementTraits](../../atl/reference/cheapptrelementtraits-class.md).  
  
 Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
