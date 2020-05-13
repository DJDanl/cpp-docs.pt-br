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
ms.openlocfilehash: 43932092621d44cfc8b07270df92e2765665f23f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327078"
---
# <a name="cdefaulthashtraits-class"></a>Classe CDefaultHashTraits

Esta classe fornece uma função estática para calcular valores de hash.

## <a name="syntax"></a>Sintaxe

```
template<typename T>
class CDefaultHashTraits
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados a serem armazenados na coleção.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDefaultHashTraits::Hash](#hash)|(Estática) Chame esta função para calcular um valor de hash para um determinado elemento.|

## <a name="remarks"></a>Comentários

Esta classe contém uma única função estática que retorna um valor de hash para um determinado elemento. Esta classe é utilizada pela [Classe CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md).

Para obter mais informações, consulte [ATL Collection Classes](../../atl/atl-collection-classes.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

## <a name="cdefaulthashtraitshash"></a><a name="hash"></a>CDefaultHashTraits::Hash

Chame esta função para calcular um valor de hash para um determinado elemento.

```
static ULONG Hash(const T& element) throw();
```

### <a name="parameters"></a>Parâmetros

*Elemento*<br/>
O elemento .

### <a name="return-value"></a>Valor retornado

Devolve o valor de hash.

### <a name="remarks"></a>Comentários

O algoritmo de hash padrão é muito simples: o valor de retorno é o número do elemento. Anular essa função se for necessário um algoritmo mais complicado.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
