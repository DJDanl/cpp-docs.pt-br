---
title: Classe CElementTraitsBase | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CElementTraitsBase
- ATLCOLL/ATL::CElementTraitsBase
- ATLCOLL/ATL::CElementTraitsBase::INARGTYPE
- ATLCOLL/ATL::CElementTraitsBase::OUTARGTYPE
- ATLCOLL/ATL::CElementTraitsBase::CopyElements
- ATLCOLL/ATL::CElementTraitsBase::RelocateElements
dev_langs:
- C++
helpviewer_keywords:
- CElementTraitsBase class
ms.assetid: 75284caf-347e-4355-a7d8-efc708dd514a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7a0b9f3945d9bcfa0c77855c94ec7247cb9804cb
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="celementtraitsbase-class"></a>Classe CElementTraitsBase
Esta classe fornece uma cópia padrão e move os métodos para uma classe de coleção.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename T>  
class CElementTraitsBase
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados a serem armazenados na coleção.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CElementTraitsBase::INARGTYPE](#inargtype)|O tipo de dados a ser usado para a adição de elementos para o objeto de classe de coleção.|  
|[CElementTraitsBase::OUTARGTYPE](#outargtype)|O tipo de dados a ser usado para recuperar os elementos do objeto de classe de coleção.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CElementTraitsBase::CopyElements](#copyelements)|Chame esse método para copiar os elementos armazenados em um objeto de classe de coleção.|  
|[CElementTraitsBase::RelocateElements](#relocateelements)|Chame este método para realocar armazenados em um objeto de classe de coleção de elementos.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe base define métodos para copiar e realocação de elementos em uma classe de coleção. Ele é utilizado pelas classes [CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md), [CStringRefElementTraits](../../atl/reference/cstringrefelementtraits-class.md), e [CStringElementTraitsI](../../atl/reference/cstringelementtraitsi-class.md).  
  
 Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
##  <a name="copyelements"></a>  CElementTraitsBase::CopyElements  
 Chame esse método para copiar os elementos armazenados em um objeto de classe de coleção.  
  
```
static void CopyElements(
    T* pDest,
    const T* pSrc,
    size_t nElements);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDest`  
 Ponteiro para o primeiro elemento que receberá os dados copiados.  
  
 `pSrc`  
 Ponteiro para o primeiro elemento para copiar.  
  
 `nElements`  
 O número de elementos a serem copiados.  
  
### <a name="remarks"></a>Comentários  
 Os elementos de origem e destino não devem se sobrepor.  
  
##  <a name="inargtype"></a>  CElementTraitsBase::INARGTYPE  
 O tipo de dados a ser usado para adicionar elementos à coleção.  
  
```
typedef const T& INARGTYPE;
```  
  
##  <a name="outargtype"></a>  CElementTraitsBase::OUTARGTYPE  
 O tipo de dados a ser usado para recuperar os elementos da coleção.  
  
```
typedef T& OUTARGTYPE;
```  
  
##  <a name="relocateelements"></a>  CElementTraitsBase::RelocateElements  
 Chame este método para realocar armazenados em um objeto de classe de coleção de elementos.  
  
```
static void RelocateElements(
    T* pDest,
    T* pSrc,
    size_t nElements);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDest`  
 Ponteiro para o primeiro elemento que receberá os dados realocados.  
  
 `pSrc`  
 Ponteiro para o primeiro elemento a ser localizado.  
  
 `nElements`  
 O número de elementos a ser localizado.  
  
### <a name="remarks"></a>Comentários  
 Este método chama [memmove](../../c-runtime-library/reference/memmove-wmemmove.md), que é suficiente para a maioria dos tipos de dados. Se os objetos que estão sendo movidos contêm ponteiros para seus próprios membros, esse método precisa ser substituído.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
