---
title: Classe CStringElementTraits | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
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
dev_langs:
- C++
helpviewer_keywords:
- CStringElementTraits class
ms.assetid: 74d7134b-099d-4455-bf91-3e68ccbf95bc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 43581995e8979ec733d8c82374896009c843166b
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43766640"
---
# <a name="cstringelementtraits-class"></a>Classe CStringElementTraits

Essa classe fornece funções estáticas usadas pelas classes de coleção armazenando `CString` objetos.

## <a name="syntax"></a>Sintaxe

```
template <typename T>  
class CStringElementTraits
```

#### <a name="parameters"></a>Parâmetros

*T*  
O tipo de dados a serem armazenados na coleção.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CStringElementTraits::INARGTYPE](#inargtype)|O tipo de dados a ser usado para adicionar elementos ao objeto de classe da coleção.|
|[CStringElementTraits::OUTARGTYPE](#outargtype)|O tipo de dados a ser usado para recuperar os elementos do objeto de classe da coleção.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CStringElementTraits::CompareElements](#compareelements)|(Estático) Chame essa função para comparar dois elementos de cadeia de caracteres quanto à igualdade.|
|[CStringElementTraits::CompareElementsOrdered](#compareelementsordered)|(Estático) Chame essa função para comparar dois elementos de cadeia de caracteres.|
|[CStringElementTraits::CopyElements](#copyelements)|(Estático) Chame essa função para copiar `CString` elementos armazenados em um objeto de classe de coleção.|
|[CStringElementTraits::Hash](#hash)|(Estático) Chame essa função para calcular um valor de hash para o elemento de cadeia de caracteres fornecida.|
|[CStringElementTraits::RelocateElements](#relocateelements)|(Estático) Chame essa função para realocar `CString` elementos armazenados em um objeto de classe de coleção.|

## <a name="remarks"></a>Comentários

Essa classe fornece funções estáticas para copiar, mover e comparando cadeias de caracteres e para a criação de um valor de hash. Essas funções são úteis ao usar uma classe de coleção para armazenar dados com base em cadeia de caracteres. Use [CStringElementTraitsI](../../atl/reference/cstringelementtraitsi-class.md) quando as comparações de maiusculas e minúsculas são necessárias. Use [CStringRefElementTraits](../../atl/reference/cstringrefelementtraits-class.md) quando os objetos de cadeia de caracteres devem ser tratados como referências.

Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** cstringt. h

##  <a name="compareelements"></a>  CStringElementTraits::CompareElements

Chame essa função estática para comparar dois elementos de cadeia de caracteres quanto à igualdade.

```
static bool CompareElements(INARGTYPE str1, INARGTYPE str2);
```

### <a name="parameters"></a>Parâmetros

*str1*  
O primeiro elemento da cadeia de caracteres.

*str2*  
O segundo elemento de cadeia de caracteres.

### <a name="return-value"></a>Valor de retorno

Retorna true se os elementos são iguais, caso contrário, false.

##  <a name="compareelementsordered"></a>  CStringElementTraits::CompareElementsOrdered

Chame essa função estática para comparar dois elementos de cadeia de caracteres.

```
static int CompareElementsOrdered(INARGTYPE str1, INARGTYPE str2);
```

### <a name="parameters"></a>Parâmetros

*str1*  
O primeiro elemento da cadeia de caracteres.

*str2*  
O segundo elemento de cadeia de caracteres.

### <a name="return-value"></a>Valor de retorno

Zero se as cadeias de caracteres são idênticas, < 0 se *str1* é menor que *str2*, ou > 0 se *str1* é maior que *str2*. O [CStringT::Compare](../../atl-mfc-shared/reference/cstringt-class.md#compare) método é usado para realizar as comparações.  

##  <a name="copyelements"></a>  CStringElementTraits::CopyElements

Chame essa função estática para copiar `CString` elementos armazenados em um objeto de classe de coleção.

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

##  <a name="hash"></a>  CStringElementTraits::Hash

Chame essa função estática para calcular um valor de hash para o elemento de cadeia de caracteres fornecida.

```
static ULONG Hash(INARGTYPE str);
```

### <a name="parameters"></a>Parâmetros

*str*  
O elemento de cadeia de caracteres.

### <a name="return-value"></a>Valor de retorno

Retorna um valor de hash, calculado usando o conteúdo da cadeia de caracteres.

##  <a name="inargtype"></a>  CStringElementTraits::INARGTYPE

O tipo de dados a ser usado para adicionar elementos ao objeto de classe da coleção.

```
typedef T::PCXSTR INARGTYPE;
```

##  <a name="outargtype"></a>  CStringElementTraits::OUTARGTYPE

O tipo de dados a ser usado para recuperar os elementos do objeto de classe da coleção.

```
typedef T& OUTARGTYPE;
```

##  <a name="relocateelements"></a>  CStringElementTraits::RelocateElements

Chame essa função estática para realocar `CString` elementos armazenados em um objeto de classe de coleção.

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

Chama a função estática [memmove](../../c-runtime-library/reference/memmove-wmemmove.md), que é suficiente para a maioria dos tipos de dados. Se os objetos que estão sendo movidos contêm ponteiros para os seus próprios membros, essa função estática precisará ser substituído.

## <a name="see-also"></a>Consulte também

[Classe CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)   
[Classe CStringElementTraitsI](../../atl/reference/cstringelementtraitsi-class.md)   
[Visão geral da classe](../../atl/atl-class-overview.md)
