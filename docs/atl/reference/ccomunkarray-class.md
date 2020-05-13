---
title: Classe CComUnkArray
ms.date: 11/04/2016
f1_keywords:
- CComUnkArray
- ATLCOM/ATL::CComUnkArray
- ATLCOM/ATL::CComUnkArray::CComUnkArray
- ATLCOM/ATL::CComUnkArray::Add
- ATLCOM/ATL::CComUnkArray::begin
- ATLCOM/ATL::CComUnkArray::end
- ATLCOM/ATL::CComUnkArray::GetCookie
- ATLCOM/ATL::CComUnkArray::GetUnknown
- ATLCOM/ATL::CComUnkArray::Remove
helpviewer_keywords:
- connection points [C++], managing
- CComUnkArray class
ms.assetid: 5fd4b378-a7b5-4cc1-8866-8ab72a73639e
ms.openlocfilehash: c1d2f0296394d3979ef4f152e3f902c89adf5b45
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327298"
---
# <a name="ccomunkarray-class"></a>Classe CComUnkArray

Esta classe `IUnknown` armazena ponteiros e foi projetada para ser usada como parâmetro para a classe de modelo [IConnectionPointImpl.](../../atl/reference/iconnectionpointimpl-class.md)

## <a name="syntax"></a>Sintaxe

```
template<unsigned int nMaxSize>
class CComUnkArray
```

#### <a name="parameters"></a>Parâmetros

*nMaxSize*<br/>
O número `IUnknown` máximo de ponteiros que podem ser mantidos na matriz estática.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComUnkArray::CComUnkArray](#ccomunkarray)|Construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComUnkArray::Adicionar](#add)|Chame este método `IUnknown` para adicionar um ponteiro à matriz.|
|[CComUnkArray::iniciar](#begin)|Retorna um ponteiro `IUnknown` para o primeiro ponteiro na coleção.|
|[CComUnkArray::end](#end)|Retorna um ponteiro para `IUnknown` um passado o último ponteiro na coleção.|
|[CComUnkArray::GetCookie](#getcookie)|Chame este método para obter o `IUnknown` cookie associado a um determinado ponteiro.|
|[CComUnkArray::GetUnknown](#getunknown)|Chame este método `IUnknown` para obter o ponteiro associado a um determinado cookie.|
|[CComUnkArray::Remove](#remove)|Chame este método `IUnknown` para remover um ponteiro da matriz.|

## <a name="remarks"></a>Comentários

`CComUnkArray`possui um número `IUnknown` fixo de ponteiros, cada uma uma interface em um ponto de conexão. `CComUnkArray`pode ser usado como parâmetro para a classe de modelo [IConnectionPointImpl.](../../atl/reference/iconnectionpointimpl-class.md) `CComUnkArray<1>`é uma especialização `CComUnkArray` de modelo que foi otimizado para um ponto de conexão.

Os `CComUnkArray` métodos [de início](#begin) e [fim](#end) podem ser usados para fazer loop através de todos os pontos de conexão (por exemplo, quando um evento é acionado).

Consulte [Adicionar pontos de conexão a um objeto](../../atl/adding-connection-points-to-an-object.md) para obter detalhes sobre a criação automatizada de proxies de ponto de conexão.

> [!NOTE]
> **Nota** A classe [CComDynamicUnkArray](../../atl/reference/ccomdynamicunkarray-class.md) é usada pelo **assistente Adicionar classe** ao criar um controle que tenha pontos de conexão. Se desejar especificar o número de pontos de `CComDynamicUnkArray` conexão manualmente, altere a referência de `CComUnkArray<` *n* `>`, onde *n* é o número de pontos de conexão necessários.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="ccomunkarrayadd"></a><a name="add"></a>CComUnkArray::Adicionar

Chame este método `IUnknown` para adicionar um ponteiro à matriz.

```
DWORD Add(IUnknown* pUnk);
```

### <a name="parameters"></a>Parâmetros

*Punk*<br/>
Chame este método `IUnknown` para adicionar um ponteiro à matriz.

### <a name="return-value"></a>Valor retornado

Retorna o cookie associado ao ponteiro recém-adicionado, ou 0 se a matriz não for grande o suficiente para conter o novo ponteiro.

## <a name="ccomunkarraybegin"></a><a name="begin"></a>CComUnkArray::iniciar

Retorna um ponteiro para o `IUnknown` início da coleção de ponteiros de interface.

```
IUnknown**
    begin();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro `IUnknown` para um ponteiro de interface.

### <a name="remarks"></a>Comentários

A coleção contém ponteiros para interfaces armazenadas localmente como `IUnknown`. Você lança `IUnknown` cada interface para o tipo de interface real e, em seguida, chamá-lo através dele. Você não precisa consultar a interface primeiro.

Antes de `IUnknown` usar a interface, você deve verificar se ela não é NULA.

## <a name="ccomunkarrayccomunkarray"></a><a name="ccomunkarray"></a>CComUnkArray::CComUnkArray

O construtor.

```
CComUnkArray();
```

### <a name="remarks"></a>Comentários

Define a coleção `nMaxSize` `IUnknown` para segurar ponteiros e inicializa os ponteiros para NULL.

## <a name="ccomunkarrayend"></a><a name="end"></a>CComUnkArray::end

Retorna um ponteiro para `IUnknown` um passado o último ponteiro na coleção.

```
IUnknown**
    end();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro `IUnknown` para um ponteiro de interface.

### <a name="remarks"></a>Comentários

Os `CComUnkArray` métodos `end` e podem ser usados `begin` para loop através de todos os pontos de conexão, por exemplo, quando um evento é disparado.

[!code-cpp[NVC_ATL_COM#44](../../atl/codesnippet/cpp/ccomunkarray-class_1.cpp)]

## <a name="ccomunkarraygetcookie"></a><a name="getcookie"></a>CComUnkArray::GetCookie

Chame este método para obter o `IUnknown` cookie associado a um determinado ponteiro.

```
DWORD WINAPI GetCookie(IUnknown** ppFind);
```

### <a name="parameters"></a>Parâmetros

*ppFind*<br/>
O `IUnknown` ponteiro para o qual o cookie associado é necessário.

### <a name="return-value"></a>Valor retornado

Retorna o cookie `IUnknown` associado ao ponteiro ou `IUnknown` 0 se nenhum ponteiro correspondente for encontrado.

### <a name="remarks"></a>Comentários

Se houver mais de uma `IUnknown` instância do mesmo ponteiro, esta função retorna o cookie para o primeiro.

## <a name="ccomunkarraygetunknown"></a><a name="getunknown"></a>CComUnkArray::GetUnknown

Chame este método `IUnknown` para obter o ponteiro associado a um determinado cookie.

```
IUnknown* WINAPI GetUnknown(DWORD dwCookie);
```

### <a name="parameters"></a>Parâmetros

*Dwcookie*<br/>
O cookie para `IUnknown` o qual o ponteiro associado é necessário.

### <a name="return-value"></a>Valor retornado

Retorna `IUnknown` o ponteiro ou NULL se nenhum cookie correspondente for encontrado.

## <a name="ccomunkarrayremove"></a><a name="remove"></a>CComUnkArray::Remove

Chame este método `IUnknown` para remover um ponteiro da matriz.

```
BOOL Remove(DWORD dwCookie);
```

### <a name="parameters"></a>Parâmetros

*Dwcookie*<br/>
O cookie que `IUnknown` faz referência ao ponteiro a ser removido da matriz.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o ponteiro for removido, FALSO de outra forma.

## <a name="see-also"></a>Confira também

[Classe CComDynamicUnkArray](../../atl/reference/ccomdynamicunkarray-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
