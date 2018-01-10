---
title: Classe CStringRefElementTraits | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CStringRefElementTraits
- ATLCOLL/ATL::CStringRefElementTraits
- ATLCOLL/ATL::CStringRefElementTraits::CompareElements
- ATLCOLL/ATL::CStringRefElementTraits::CompareElementsOrdered
- ATLCOLL/ATL::CStringRefElementTraits::Hash
dev_langs: C++
helpviewer_keywords: CStringRefElementTraits class
ms.assetid: cc15062d-5627-46cc-ac2b-1744afdc2dbd
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c89a1e0d87550614fb8991ac3efe6bf369d147e7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
|[CStringRefElementTraits::CompareElements](#compareelements)|Chame esta função estática para comparar dois elementos de cadeia de caracteres para fins de igualdade.|  
|[CStringRefElementTraits::CompareElementsOrdered](#compareelementsordered)|Chame a função estática para comparar dois elementos de cadeia de caracteres.|  
|[CStringRefElementTraits::Hash](#hash)|Chame a função estática para calcular um valor de hash para o elemento de cadeia de caracteres especificada.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece funções estáticas para comparar cadeias de caracteres e para criar um valor de hash. Essas funções são úteis ao usar uma classe de coleção para armazenar dados com base em cadeia de caracteres. Ao contrário de [CStringElementTraits](../../atl/reference/cstringelementtraits-class.md) e [CStringElementTraitsI](../../atl/reference/cstringelementtraitsi-class.md), `CStringRefElementTraits` faz com que o `CString` argumentos a serem passados como **CString const &** referências.  
  
 Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)  
  
 `CStringRefElementTraits`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
##  <a name="compareelements"></a>CStringRefElementTraits::CompareElements  
 Chame esta função estática para comparar dois elementos de cadeia de caracteres para fins de igualdade.  
  
```
static bool CompareElements(INARGTYPE element1, INARGTYPE element2) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `element1`  
 O primeiro elemento da cadeia de caracteres.  
  
 `element2`  
 O segundo elemento de cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se os elementos forem iguais; caso contrário, false.  
  
##  <a name="compareelementsordered"></a>CStringRefElementTraits::CompareElementsOrdered  
 Chame a função estática para comparar dois elementos de cadeia de caracteres.  
  
```
static int CompareElementsOrdered(INARGTYPE str1, INARGTYPE str2) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `str1`  
 O primeiro elemento da cadeia de caracteres.  
  
 `str2`  
 O segundo elemento de cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Zero se as cadeias de caracteres forem idênticas, < 0 se `str1` é menor que `str2`, ou > 0 se `str1` é maior do que `str2`. O [CStringT::Compare](../../atl-mfc-shared/reference/cstringt-class.md#compare) método é usado para realizar as comparações.  
  
##  <a name="hash"></a>CStringRefElementTraits::Hash  
 Chame a função estática para calcular um valor de hash para o elemento de cadeia de caracteres especificada.  
  
```
static ULONG Hash(INARGTYPE str) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 O elemento de cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor de hash calculado usando o conteúdo da cadeia de caracteres.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
