---
title: Classe CStringElementTraitsI | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CStringElementTraitsI
- CStringElementTraitsI
- ATL.CStringElementTraitsI
dev_langs:
- C++
helpviewer_keywords:
- CStringElementTraitsI class
ms.assetid: c23f92b1-91e5-400f-96ed-258b02622b7a
caps.latest.revision: 18
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
translationtype: Machine Translation
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: 995c4798f92db3b3f065bf2176ab52ff53d282b0
ms.lasthandoff: 02/25/2017

---
# <a name="cstringelementtraitsi-class"></a>Classe CStringElementTraitsI
Essa classe fornece funções estáticas relacionadas a cadeias de caracteres armazenadas em objetos de classe de coleção. Ele é semelhante ao [CStringElementTraits](../../atl/reference/cstringelementtraits-class.md), mas executa comparações diferenciam maiusculas de minúsculas.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <typename T, class CharTraits = CDefaultCharTraits<T ::XCHAR>>  
class CStringElementTraitsI : public CElementTraitsBase<T>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados a serem armazenados na coleção.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CStringElementTraitsI::INARGTYPE](#inargtype)|O tipo de dados a ser usado para adicionar elementos para o objeto de classe de coleção.|  
|[CStringElementTraitsI::OUTARGTYPE](#outargtype)|O tipo de dados a ser usado para recuperar os elementos do objeto de classe de coleção.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CStringElementTraitsI::CompareElements](#compareelements)|Chame essa função estática para comparar dois elementos de cadeia de caracteres para igualdade, ignorando as diferenças no caso.|  
|[CStringElementTraitsI::CompareElementsOrdered](#compareelementsordered)|Chame essa função estática para comparar dois elementos de cadeia de caracteres, ignorando as diferenças no caso.|  
|[CStringElementTraitsI::Hash](#hash)|Chame essa função estática para calcular um valor de hash para o elemento de cadeia de caracteres especificada.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece funções estáticas para comparar cadeias de caracteres e para criar um valor de hash. Essas funções são úteis ao usar uma classe de coleção para armazenar dados com base em cadeia de caracteres. Use [CStringRefElementTraits](../../atl/reference/cstringrefelementtraits-class.md) quando os objetos de cadeia de caracteres devem ser com tratada como referências.  
  
 Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)  
  
 `CStringElementTraitsI`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
##  <a name="a-namecompareelementsa--cstringelementtraitsicompareelements"></a><a name="compareelements"></a>CStringElementTraitsI::CompareElements  
 Chame essa função estática para comparar dois elementos de cadeia de caracteres para igualdade, ignorando as diferenças no caso.  
  
```
static bool CompareElements(INARGTYPE str1, INARGTYPE str2) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `str1`  
 O primeiro elemento de cadeia de caracteres.  
  
 `str2`  
 O segundo elemento de cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se os elementos forem iguais; caso contrário, false.  
  
### <a name="remarks"></a>Comentários  
 As comparações diferenciam maiusculas de minúsculas.  
  
##  <a name="a-namecompareelementsordereda--cstringelementtraitsicompareelementsordered"></a><a name="compareelementsordered"></a>CStringElementTraitsI::CompareElementsOrdered  
 Chame essa função estática para comparar dois elementos de cadeia de caracteres, ignorando as diferenças no caso.  
  
```
static int CompareElementsOrdered(INARGTYPE str1, INARGTYPE str2) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `str1`  
 O primeiro elemento de cadeia de caracteres.  
  
 `str2`  
 O segundo elemento de cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Zero se as cadeias de caracteres são idênticas, < 0="" if=""> `str1` é menor que `str2`, ou > 0 se `str1` é maior do que `str2`. O [CStringT::Compare](../../atl-mfc-shared/reference/cstringt-class.md#compare) método é usado para realizar as comparações.  

  
### <a name="remarks"></a>Comentários  
 As comparações diferenciam maiusculas de minúsculas.  
  
##  <a name="a-namehasha--cstringelementtraitsihash"></a><a name="hash"></a>CStringElementTraitsI::Hash  
 Chame essa função estática para calcular um valor de hash para o elemento de cadeia de caracteres especificada.  
  
```
static ULONG Hash(INARGTYPE str) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 O elemento de cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor de hash, calculado usando o conteúdo da sequência de caracteres.  
  
##  <a name="a-nameinargtypea--cstringelementtraitsiinargtype"></a><a name="inargtype"></a>CStringElementTraitsI::INARGTYPE  
 O tipo de dados a ser usado para adicionar elementos para o objeto de classe de coleção.  
  
```
typedef T::PCXSTR INARGTYPE;
```  
  
##  <a name="a-nameoutargtypea--cstringelementtraitsioutargtype"></a><a name="outargtype"></a>CStringElementTraitsI::OUTARGTYPE  
 O tipo de dados a ser usado para recuperar os elementos do objeto de classe de coleção.  
  
```
typedef T& OUTARGTYPE;
```  
  
## <a name="see-also"></a>Consulte também  
 [Classe CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classe CStringElementTraits](../../atl/reference/cstringelementtraits-class.md)

