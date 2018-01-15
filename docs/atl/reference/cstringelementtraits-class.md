---
title: Classe CStringElementTraits | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CStringElementTraits
- CSTRINGT/ATL::CStringElementTraits
- CSTRINGT/ATL::CStringElementTraits::INARGTYPE
- CSTRINGT/ATL::CStringElementTraits::OUTARGTYPE
- CSTRINGT/ATL::CStringElementTraits::CompareElements
- CSTRINGT/ATL::CStringElementTraits::CompareElementsOrdered
- CSTRINGT/ATL::CStringElementTraits::CopyElements
- CSTRINGT/ATL::CStringElementTraits::Hash
- CSTRINGT/ATL::CStringElementTraits::RelocateElements
dev_langs: C++
helpviewer_keywords: CStringElementTraits class
ms.assetid: 74d7134b-099d-4455-bf91-3e68ccbf95bc
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 025c9aa66a8647fd5d8ca9803aedb50b27ed3be1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cstringelementtraits-class"></a>Classe CStringElementTraits
Essa classe fornece funções estáticas usadas pelas classes de coleção armazenar `CString` objetos.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <typename T>  
class CStringElementTraits
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados a serem armazenados na coleção.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CStringElementTraits::INARGTYPE](#inargtype)|O tipo de dados a ser usado para a adição de elementos para o objeto de classe de coleção.|  
|[CStringElementTraits::OUTARGTYPE](#outargtype)|O tipo de dados a ser usado para recuperar os elementos do objeto de classe de coleção.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CStringElementTraits::CompareElements](#compareelements)|(Estático) Chame essa função para comparar dois elementos de cadeia de caracteres para fins de igualdade.|  
|[CStringElementTraits::CompareElementsOrdered](#compareelementsordered)|(Estático) Chame essa função para comparar dois elementos de cadeia de caracteres.|  
|[CStringElementTraits::CopyElements](#copyelements)|(Estático) Chamar esta função para copiar `CString` armazenados em um objeto de classe de coleção de elementos.|  
|[CStringElementTraits::Hash](#hash)|(Estático) Chame essa função para calcular um valor de hash para o elemento de cadeia de caracteres especificada.|  
|[CStringElementTraits::RelocateElements](#relocateelements)|(Estático) Chamar essa função para realocar `CString` armazenados em um objeto de classe de coleção de elementos.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece funções estáticas para copiar, mover e comparação de cadeias de caracteres e para criar um valor de hash. Essas funções são úteis ao usar uma classe de coleção para armazenar dados com base em cadeia de caracteres. Use [CStringElementTraitsI](../../atl/reference/cstringelementtraitsi-class.md) quando comparações de maiusculas e minúsculas são necessárias. Use [CStringRefElementTraits](../../atl/reference/cstringrefelementtraits-class.md) quando os objetos de cadeia de caracteres devem ser tratadas como referências.  
  
 Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** cstringt.h  
  
##  <a name="compareelements"></a>CStringElementTraits::CompareElements  
 Chame esta função estática para comparar dois elementos de cadeia de caracteres para fins de igualdade.  
  
```
static bool CompareElements(INARGTYPE str1, INARGTYPE str2);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str1`  
 O primeiro elemento da cadeia de caracteres.  
  
 `str2`  
 O segundo elemento de cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se os elementos forem iguais; caso contrário, false.  
  
##  <a name="compareelementsordered"></a>CStringElementTraits::CompareElementsOrdered  
 Chame a função estática para comparar dois elementos de cadeia de caracteres.  
  
```
static int CompareElementsOrdered(INARGTYPE str1, INARGTYPE str2);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str1`  
 O primeiro elemento da cadeia de caracteres.  
  
 `str2`  
 O segundo elemento de cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Zero se as cadeias de caracteres forem idênticas, < 0 se `str1` é menor que `str2`, ou > 0 se `str1` é maior do que `str2`. O [CStringT::Compare](../../atl-mfc-shared/reference/cstringt-class.md#compare) método é usado para realizar as comparações.  

  
##  <a name="copyelements"></a>CStringElementTraits::CopyElements  
 Chame a função estática para copiar `CString` armazenados em um objeto de classe de coleção de elementos.  
  
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
  
##  <a name="hash"></a>CStringElementTraits::Hash  
 Chame a função estática para calcular um valor de hash para o elemento de cadeia de caracteres especificada.  
  
```
static ULONG Hash(INARGTYPE str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 O elemento de cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor de hash calculado usando o conteúdo da cadeia de caracteres.  
  
##  <a name="inargtype"></a>CStringElementTraits::INARGTYPE  
 O tipo de dados a ser usado para a adição de elementos para o objeto de classe de coleção.  
  
```
typedef T::PCXSTR INARGTYPE;
```  
  
##  <a name="outargtype"></a>CStringElementTraits::OUTARGTYPE  
 O tipo de dados a ser usado para recuperar os elementos do objeto de classe de coleção.  
  
```
typedef T& OUTARGTYPE;
```  
  
##  <a name="relocateelements"></a>CStringElementTraits::RelocateElements  
 Chame a função estática para realocar `CString` armazenados em um objeto de classe de coleção de elementos.  
  
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
 Chama a função estática [memmove](../../c-runtime-library/reference/memmove-wmemmove.md), que é suficiente para a maioria dos tipos de dados. Se os objetos que estão sendo movidos contêm ponteiros para seus próprios membros, essa função estática precisará ser substituído.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)   
 [Classe CStringElementTraitsI](../../atl/reference/cstringelementtraitsi-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
