---
title: Classe CDefaultHashTraits
ms.date: 11/04/2016
f1_keywords:
- CDefaultHashTraits
- ATLCOLL/ATL::CDefaultHashTraits
- ATLCOLL/ATL::CDefaultHashTraits::Hash
helpviewer_keywords:
- CDefaultHashTraits class
ms.assetid: d8ec4b37-6d58-447b-a0c1-8580c5b1ab85
ms.openlocfilehash: c8896ce27afc40ad095e02a2453628ffc05900da
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50466138"
---
# <a name="cdefaulthashtraits-class"></a>Classe CDefaultHashTraits

Essa classe fornece uma função estática para calcular valores de hash.

## <a name="syntax"></a>Sintaxe

```
template<typename T>
class CDefaultHashTraits
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados a serem armazenados na coleção.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDefaultHashTraits::Hash](#hash)|(Estático) Chame essa função para calcular um valor de hash para um determinado elemento.|

## <a name="remarks"></a>Comentários

Essa classe contém uma única função estática que retorna um valor de hash para um determinado elemento. Essa classe é utilizada pela [classe CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md).

Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

##  <a name="hash"></a>  CDefaultHashTraits::Hash

Chame essa função para calcular um valor de hash para um determinado elemento.

```
static ULONG Hash(const T& element) throw();
```

### <a name="parameters"></a>Parâmetros

*Elemento*<br/>
O elemento.

### <a name="return-value"></a>Valor de retorno

Retorna o valor de hash.

### <a name="remarks"></a>Comentários

O algoritmo de hash padrão é muito simple: o valor retornado é o número do elemento. Substitua essa função se um algoritmo mais complicado for necessário.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
