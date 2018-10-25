---
title: Classe CStringElementTraitsI | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CStringElementTraitsI
- ATLCOLL/ATL::CStringElementTraitsI
- ATLCOLL/ATL::CStringElementTraitsI::INARGTYPE
- ATLCOLL/ATL::CStringElementTraitsI::OUTARGTYPE
- ATLCOLL/ATL::CStringElementTraitsI::CompareElements
- ATLCOLL/ATL::CStringElementTraitsI::CompareElementsOrdered
- ATLCOLL/ATL::CStringElementTraitsI::Hash
dev_langs:
- C++
helpviewer_keywords:
- CStringElementTraitsI class
ms.assetid: c23f92b1-91e5-400f-96ed-258b02622b7a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 29df4bd550a5de232b5ced0510e8dbfc68e59d42
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50060748"
---
# <a name="cstringelementtraitsi-class"></a>Classe CStringElementTraitsI

Essa classe fornece funções estáticas relacionadas a cadeias de caracteres armazenadas em objetos de classe de coleção. Ele é semelhante ao [CStringElementTraits](../../atl/reference/cstringelementtraits-class.md), mas executa comparações de maiusculas e minúsculas.

## <a name="syntax"></a>Sintaxe

```
template <typename T, class CharTraits = CDefaultCharTraits<T ::XCHAR>>
class CStringElementTraitsI : public CElementTraitsBase<T>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados a serem armazenados na coleção.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CStringElementTraitsI::INARGTYPE](#inargtype)|O tipo de dados a ser usado para adicionar elementos ao objeto de classe da coleção.|
|[CStringElementTraitsI::OUTARGTYPE](#outargtype)|O tipo de dados a ser usado para recuperar os elementos do objeto de classe da coleção.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CStringElementTraitsI::CompareElements](#compareelements)|Chame essa função estática para comparar dois elementos de cadeia de caracteres de igualdade, ignorando as diferenças no caso.|
|[CStringElementTraitsI::CompareElementsOrdered](#compareelementsordered)|Chame essa função estática para comparar dois elementos de cadeia de caracteres, ignorando as diferenças no caso.|
|[CStringElementTraitsI::Hash](#hash)|Chame essa função estática para calcular um valor de hash para o elemento de cadeia de caracteres fornecida.|

## <a name="remarks"></a>Comentários

Essa classe fornece funções estáticas para comparar cadeias de caracteres e para a criação de um valor de hash. Essas funções são úteis ao usar uma classe de coleção para armazenar dados com base em cadeia de caracteres. Use [CStringRefElementTraits](../../atl/reference/cstringrefelementtraits-class.md) quando os objetos de cadeia de caracteres devem ser com manipuladas como referências.

Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)

`CStringElementTraitsI`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

##  <a name="compareelements"></a>  CStringElementTraitsI::CompareElements

Chame essa função estática para comparar dois elementos de cadeia de caracteres de igualdade, ignorando as diferenças no caso.

```
static bool CompareElements(INARGTYPE str1, INARGTYPE str2) throw();
```

### <a name="parameters"></a>Parâmetros

*str1*<br/>
O primeiro elemento da cadeia de caracteres.

*str2*<br/>
O segundo elemento de cadeia de caracteres.

### <a name="return-value"></a>Valor de retorno

Retorna true se os elementos são iguais, caso contrário, false.

### <a name="remarks"></a>Comentários

As comparações diferenciam maiusculas de minúsculas.

##  <a name="compareelementsordered"></a>  CStringElementTraitsI::CompareElementsOrdered

Chame essa função estática para comparar dois elementos de cadeia de caracteres, ignorando as diferenças no caso.

```
static int CompareElementsOrdered(INARGTYPE str1, INARGTYPE str2) throw();
```

### <a name="parameters"></a>Parâmetros

*str1*<br/>
O primeiro elemento da cadeia de caracteres.

*str2*<br/>
O segundo elemento de cadeia de caracteres.

### <a name="return-value"></a>Valor de retorno

Zero se as cadeias de caracteres são idênticas, < 0 se *str1* é menor que *str2*, ou > 0 se *str1* é maior que *str2*. O [CStringT::Compare](../../atl-mfc-shared/reference/cstringt-class.md#compare) método é usado para realizar as comparações.

### <a name="remarks"></a>Comentários

As comparações diferenciam maiusculas de minúsculas.

##  <a name="hash"></a>  CStringElementTraitsI::Hash

Chame essa função estática para calcular um valor de hash para o elemento de cadeia de caracteres fornecida.

```
static ULONG Hash(INARGTYPE str) throw();
```

### <a name="parameters"></a>Parâmetros

*str*<br/>
O elemento de cadeia de caracteres.

### <a name="return-value"></a>Valor de retorno

Retorna um valor de hash, calculado usando o conteúdo da cadeia de caracteres.

##  <a name="inargtype"></a>  CStringElementTraitsI::INARGTYPE

O tipo de dados a ser usado para adicionar elementos ao objeto de classe da coleção.

```
typedef T::PCXSTR INARGTYPE;
```

##  <a name="outargtype"></a>  CStringElementTraitsI::OUTARGTYPE

O tipo de dados a ser usado para recuperar os elementos do objeto de classe da coleção.

```
typedef T& OUTARGTYPE;
```

## <a name="see-also"></a>Consulte também

[Classe CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CStringElementTraits](../../atl/reference/cstringelementtraits-class.md)
