---
title: Classe CDefaultCompareTraits
ms.date: 11/04/2016
f1_keywords:
- CDefaultCompareTraits
- ATLCOLL/ATL::CDefaultCompareTraits
- ATLCOLL/ATL::CDefaultCompareTraits::CompareElements
- ATLCOLL/ATL::CDefaultCompareTraits::CompareElementsOrdered
helpviewer_keywords:
- CDefaultCompareTraits class
ms.assetid: a17e2740-e7b4-48f2-aeb7-c80ce84b63f7
ms.openlocfilehash: b7f51ccd266fce1b5d614dfe2c725e20fde6f297
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50575299"
---
# <a name="cdefaultcomparetraits-class"></a>Classe CDefaultCompareTraits

Essa classe fornece funções de comparação de elemento de padrão.

## <a name="syntax"></a>Sintaxe

```
template<typename T>
class CDefaultCompareTraits
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados a serem armazenados na coleção.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDefaultCompareTraits::CompareElements](#compareelements)|(Estático) Chame essa função para comparar dois elementos quanto à igualdade.|
|[CDefaultCompareTraits::CompareElementsOrdered](#compareelementsordered)|(Estático) Chame essa função para determinar o elemento maior e menor.|

## <a name="remarks"></a>Comentários

Essa classe contém duas funções estáticas para comparar elementos armazenados em um objeto de classe de coleção. Essa classe é utilizada pela [classe CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md).

Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

##  <a name="compareelements"></a>  CDefaultCompareTraits::CompareElements

Chame essa função para comparar dois elementos quanto à igualdade.

```
static bool CompareElements(const T& element1, const T& element2);
```

### <a name="parameters"></a>Parâmetros

*element1*<br/>
O primeiro elemento.

*element2*<br/>
O segundo elemento.

### <a name="return-value"></a>Valor de retorno

Retorna true se os elementos são iguais, caso contrário, false.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função é a igualdade (**==**) operador. Para objetos diferentes tipos de dados simples, essa função talvez precise ser substituído.

##  <a name="compareelementsordered"></a>  CDefaultCompareTraits::CompareElementsOrdered

Chame essa função para determinar o elemento maior e menor.

```
static int CompareElementsOrdered(const T& element1, const T& element2);
```

### <a name="parameters"></a>Parâmetros

*element1*<br/>
O primeiro elemento.

*element2*<br/>
O segundo elemento.

### <a name="return-value"></a>Valor de retorno

Retorna um inteiro com base na tabela a seguir:

|Condição|Valor retornado|
|---------------|------------------|
|*element1* < *element2*|<0|
|*element1* == *element2*|0|
|*element1* > *element2*|>0|

### <a name="remarks"></a>Comentários

A implementação padrão dessa função usa o **==**, **\<**, e **>** operadores. Para objetos diferentes tipos de dados simples, essa função talvez precise ser substituído.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
