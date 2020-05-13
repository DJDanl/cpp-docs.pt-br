---
title: Classe CDefaultComparetraits
ms.date: 11/04/2016
f1_keywords:
- CDefaultCompareTraits
- ATLCOLL/ATL::CDefaultCompareTraits
- ATLCOLL/ATL::CDefaultCompareTraits::CompareElements
- ATLCOLL/ATL::CDefaultCompareTraits::CompareElementsOrdered
helpviewer_keywords:
- CDefaultCompareTraits class
ms.assetid: a17e2740-e7b4-48f2-aeb7-c80ce84b63f7
ms.openlocfilehash: 8262800ef613424c37c53931d97dd4b1b1a71321
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327071"
---
# <a name="cdefaultcomparetraits-class"></a>Classe CDefaultComparetraits

Esta classe fornece funções de comparação de elementos padrão.

## <a name="syntax"></a>Sintaxe

```
template<typename T>
class CDefaultCompareTraits
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados a serem armazenados na coleção.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDefaultCompareTraits::CompareElements](#compareelements)|(Estática) Chame esta função para comparar dois elementos para a igualdade.|
|[CDefaultCompareTraits::CompareElementsPedido](#compareelementsordered)|(Estática) Chame esta função para determinar o elemento maior e menor.|

## <a name="remarks"></a>Comentários

Esta classe contém duas funções estáticas para comparar elementos armazenados em um objeto de classe de coleção. Esta classe é utilizada pela [Classe CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md).

Para obter mais informações, consulte [ATL Collection Classes](../../atl/atl-collection-classes.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

## <a name="cdefaultcomparetraitscompareelements"></a><a name="compareelements"></a>CDefaultCompareTraits::CompareElements

Chame esta função para comparar dois elementos para a igualdade.

```
static bool CompareElements(const T& element1, const T& element2);
```

### <a name="parameters"></a>Parâmetros

*elemento1*<br/>
O primeiro elemento.

*elemento2*<br/>
O segundo elemento.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se os elementos são iguais, falsos de outra forma.

### <a name="remarks"></a>Comentários

A implementação padrão desta função**==** é o operador de igualdade ( ) Para outros objetos que não sejam simples tipos de dados, essa função pode precisar ser substituída.

## <a name="cdefaultcomparetraitscompareelementsordered"></a><a name="compareelementsordered"></a>CDefaultCompareTraits::CompareElementsPedido

Chame esta função para determinar o elemento maior e menor.

```
static int CompareElementsOrdered(const T& element1, const T& element2);
```

### <a name="parameters"></a>Parâmetros

*elemento1*<br/>
O primeiro elemento.

*elemento2*<br/>
O segundo elemento.

### <a name="return-value"></a>Valor retornado

Retorna um inteiro com base na tabela a seguir:

|Condição|Valor retornado|
|---------------|------------------|
|*elemento1* < *elemento2*|<0|
|*elemento1* == *elemento2*|0|
|*elemento1* > *elemento2*|>0|

### <a name="remarks"></a>Comentários

A implementação padrão desta **==** **\<** função **>** utiliza os operadores e operadores. Para outros objetos que não sejam simples tipos de dados, essa função pode precisar ser substituída.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
