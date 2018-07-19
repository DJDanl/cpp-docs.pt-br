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
ms.openlocfilehash: b70ae03c15fcdee4510e25815e516c3e17eb1a2a
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37879404"
---
# <a name="celementtraitsbase-class"></a>Classe CElementTraitsBase
Essa classe fornece uma cópia padrão e move os métodos para uma classe de coleção.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename T>  
class CElementTraitsBase
```  
  
#### <a name="parameters"></a>Parâmetros  
 *T*  
 O tipo de dados a serem armazenados na coleção.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CElementTraitsBase::INARGTYPE](#inargtype)|O tipo de dados a ser usado para adicionar elementos ao objeto de classe da coleção.|  
|[CElementTraitsBase::OUTARGTYPE](#outargtype)|O tipo de dados a ser usado para recuperar os elementos do objeto de classe da coleção.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CElementTraitsBase::CopyElements](#copyelements)|Chame esse método para copiar elementos armazenados em um objeto de classe de coleção.|  
|[CElementTraitsBase::RelocateElements](#relocateelements)|Chame esse método para realocar os elementos armazenados em um objeto de classe de coleção.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe base define métodos para copiar e realocação de elementos em uma classe de coleção. Ele é utilizado pelas classes [CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md), [CStringRefElementTraits](../../atl/reference/cstringrefelementtraits-class.md), e [CStringElementTraitsI](../../atl/reference/cstringelementtraitsi-class.md).  
  
 Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
##  <a name="copyelements"></a>  CElementTraitsBase::CopyElements  
 Chame esse método para copiar elementos armazenados em um objeto de classe de coleção.  
  
```
static void CopyElements(
    T* pDest,
    const T* pSrc,
    size_t nElements);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDest*  
 Ponteiro para o primeiro elemento que receberá os dados copiados.  
  
 *pSrc*  
 Ponteiro para o primeiro elemento para copiar.  
  
 *nElements*  
 O número de elementos a serem copiados.  
  
### <a name="remarks"></a>Comentários  
 Os elementos de origem e de destino não devem se sobrepor.  
  
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
 Chame esse método para realocar os elementos armazenados em um objeto de classe de coleção.  
  
```
static void RelocateElements(
    T* pDest,
    T* pSrc,
    size_t nElements);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDest*  
 Ponteiro para o primeiro elemento que receberá os dados realocados.  
  
 *pSrc*  
 Ponteiro para o primeiro elemento para realocar.  
  
 *nElements*  
 O número de elementos para realocar.  
  
### <a name="remarks"></a>Comentários  
 Este método chama [memmove](../../c-runtime-library/reference/memmove-wmemmove.md), que é suficiente para a maioria dos tipos de dados. Se os objetos que estão sendo movidos contêm ponteiros para os seus próprios membros, esse método precisará ser substituído.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
