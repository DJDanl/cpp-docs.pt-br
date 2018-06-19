---
title: Classe CPrimitiveElementTraits | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CPrimitiveElementTraits
- ATLCOLL/ATL::CPrimitiveElementTraits
- ATLCOLL/ATL::CPrimitiveElementTraits::INARGTYPE
- ATLCOLL/ATL::CPrimitiveElementTraits::OUTARGTYPE
dev_langs:
- C++
helpviewer_keywords:
- CPrimitiveElementTraits class
ms.assetid: 21c1cea8-2c5a-486c-b65c-85490f3ed4e6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3bec944c4b9a505cc817dbe7aa3ce09a317954f7
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32359137"
---
# <a name="cprimitiveelementtraits-class"></a>Classe CPrimitiveElementTraits
Essa classe fornece métodos padrão e funções para uma classe de coleção composta de tipos de dados primitivos.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <typename T>  
class CPrimitiveElementTraits : public CDefaultElementTraits<T>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados a ser armazenado no objeto de classe de coleção.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPrimitiveElementTraits::INARGTYPE](#inargtype)|O tipo de dados a ser usado para a adição de elementos para o objeto de classe de coleção.|  
|[CPrimitiveElementTraits::OUTARGTYPE](#outargtype)|O tipo de dados a ser usado para recuperar os elementos do objeto de classe de coleção.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece métodos para mover, copiar, comparar e armazenados em um objeto de classe de coleção de elementos de tipo de dados primitivos de hash e funções estáticas padrão.  
  
 Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CDefaultCompareTraits](../../atl/reference/cdefaultcomparetraits-class.md)  
  
 [CDefaultHashTraits](../../atl/reference/cdefaulthashtraits-class.md)  
  
 [CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)  
  
 [CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)  
  
 `CPrimitiveElementTraits`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
##  <a name="inargtype"></a>  CPrimitiveElementTraits::INARGTYPE  
 O tipo de dados a ser usado para a adição de elementos para o objeto de classe de coleção.  
  
```
typedef T INARGTYPE;
```  
  
##  <a name="outargtype"></a>  CPrimitiveElementTraits::OUTARGTYPE  
 O tipo de dados a ser usado para recuperar os elementos do objeto de classe de coleção.  
  
```
typedef T& OUTARGTYPE;
```  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
