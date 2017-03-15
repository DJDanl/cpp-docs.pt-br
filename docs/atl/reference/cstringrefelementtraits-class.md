---
title: Classe CStringRefElementTraits | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CStringRefElementTraits
- ATL.CStringRefElementTraits
- ATL::CStringRefElementTraits
dev_langs:
- C++
helpviewer_keywords:
- CStringRefElementTraits class
ms.assetid: cc15062d-5627-46cc-ac2b-1744afdc2dbd
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
translationtype: Machine Translation
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: 3709a5d4aac02651e5b6fafd441499fea1f8eabc
ms.lasthandoff: 02/25/2017

---
# <a name="cstringrefelementtraits-class"></a>Classe CStringRefElementTraits
Essa classe fornece funções estáticas relacionadas a cadeias de caracteres armazenadas em objetos de classe de coleção. Os objetos de cadeia de caracteres são tratados como referências.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <typename T>  
class CStringRefElementTraits : public CElementTraitsBase<T>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados a serem armazenados na coleção.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CStringRefElementTraits::CompareElements](#compareelements)|Chame essa função estática para comparar dois elementos de cadeia de caracteres de igualdade.|  
|[CStringRefElementTraits::CompareElementsOrdered](#compareelementsordered)|Chame essa função estática para comparar dois elementos de cadeia de caracteres.|  
|[CStringRefElementTraits::Hash](#hash)|Chame essa função estática para calcular um valor de hash para o elemento de cadeia de caracteres especificada.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece funções estáticas para comparar cadeias de caracteres e para criar um valor de hash. Essas funções são úteis ao usar uma classe de coleção para armazenar dados com base em cadeia de caracteres. Ao contrário de [CStringElementTraits](../../atl/reference/cstringelementtraits-class.md) e [CStringElementTraitsI](../../atl/reference/cstringelementtraitsi-class.md), `CStringRefElementTraits` faz com que o `CString` argumentos a serem passados como **CString const < /** referências.  
  
 Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)  
  
 `CStringRefElementTraits`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
##  <a name="a-namecompareelementsa--cstringrefelementtraitscompareelements"></a><a name="compareelements"></a>CStringRefElementTraits::CompareElements  
 Chame essa função estática para comparar dois elementos de cadeia de caracteres de igualdade.  
  
```
static bool CompareElements(INARGTYPE element1, INARGTYPE element2) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `element1`  
 O primeiro elemento de cadeia de caracteres.  
  
 `element2`  
 O segundo elemento de cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se os elementos forem iguais; caso contrário, false.  
  
##  <a name="a-namecompareelementsordereda--cstringrefelementtraitscompareelementsordered"></a><a name="compareelementsordered"></a>CStringRefElementTraits::CompareElementsOrdered  
 Chame essa função estática para comparar dois elementos de cadeia de caracteres.  
  
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
  
##  <a name="a-namehasha--cstringrefelementtraitshash"></a><a name="hash"></a>CStringRefElementTraits::Hash  
 Chame essa função estática para calcular um valor de hash para o elemento de cadeia de caracteres especificada.  
  
```
static ULONG Hash(INARGTYPE str) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 O elemento de cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor de hash, calculado usando o conteúdo da sequência de caracteres.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

