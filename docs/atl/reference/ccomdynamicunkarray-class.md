---
title: Classe CComDynamicUnkArray
ms.date: 11/04/2016
f1_keywords:
- CComDynamicUnkArray
- ATLCOM/ATL::CComDynamicUnkArray
- ATLCOM/ATL::CComDynamicUnkArray::CComDynamicUnkArray
- ATLCOM/ATL::CComDynamicUnkArray::Add
- ATLCOM/ATL::CComDynamicUnkArray::begin
- ATLCOM/ATL::CComDynamicUnkArray::clear
- ATLCOM/ATL::CComDynamicUnkArray::end
- ATLCOM/ATL::CComDynamicUnkArray::GetAt
- ATLCOM/ATL::CComDynamicUnkArray::GetCookie
- ATLCOM/ATL::CComDynamicUnkArray::GetSize
- ATLCOM/ATL::CComDynamicUnkArray::GetUnknown
- ATLCOM/ATL::CComDynamicUnkArray::Remove
helpviewer_keywords:
- connection points [C++], managing
- CComDynamicUnkArray class
ms.assetid: 202470d7-9a1b-498f-b96d-659d681acd65
ms.openlocfilehash: 57383823897a434f649c6c4af78e71fe6ff66a6a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327902"
---
# <a name="ccomdynamicunkarray-class"></a>Classe CComDynamicUnkArray

Esta classe armazena `IUnknown` uma matriz de ponteiros.

## <a name="syntax"></a>Sintaxe

```
class CComDynamicUnkArray
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComDynamicUnkArray::CComDynamicUnkArray](#ccomdynamicunkarray)|Construtor. Inicializa os valores de coleta para NULL e o tamanho da coleção para zero.|
|[CComDynamicUnkArray::~CComDynamicUnkArray](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComDynamicUnkArray::Adicionar](#add)|Chame este método `IUnknown` para adicionar um ponteiro à matriz.|
|[CComDynamicUnkArray::iniciar](#begin)|Retorna um ponteiro `IUnknown` para o primeiro ponteiro na coleção.|
|[CComDynamicUnkArray::clear](#clear)|Esvazia a matriz.|
|[CComDynamicUnkArray::end](#end)|Retorna um ponteiro para `IUnknown` um passado o último ponteiro na coleção.|
|[CComDynamicUnkArray::GetAt](#getat)|Recupera o elemento no índice especificado.|
|[CComDynamicUnkArray::GetCookie](#getcookie)|Chame este método para obter o `IUnknown` cookie associado a um determinado ponteiro.|
|[CComDynamicUnkArray::GetSize](#getsize)|Retorna o comprimento de uma matriz.|
|[CComDynamicUnkArray::GetUnknown](#getunknown)|Chame este método `IUnknown` para obter o ponteiro associado a um determinado cookie.|
|[CComDynamicUnkArray::Remove](#remove)|Chame este método `IUnknown` para remover um ponteiro da matriz.|

## <a name="remarks"></a>Comentários

`CComDynamicUnkArray`possui um conjunto de `IUnknown` ponteiros dinamicamente alocado, cada uma uma interface em um ponto de conexão. `CComDynamicUnkArray`pode ser usado como parâmetro para a classe de modelo [IConnectionPointImpl.](../../atl/reference/iconnectionpointimpl-class.md)

Os `CComDynamicUnkArray` métodos [de início](#begin) e [fim](#end) podem ser usados para fazer loop através de todos os pontos de conexão (por exemplo, quando um evento é acionado).

Consulte [Adicionar pontos de conexão a um objeto](../../atl/adding-connection-points-to-an-object.md) para obter detalhes sobre a criação automatizada de proxies de ponto de conexão.

> [!NOTE]
> **Nota** A `CComDynamicUnkArray` classe é usada pelo **assistente Adicionar classe** ao criar um controle que tenha Pontos de Conexão. Se desejar especificar o número de pontos de `CComDynamicUnkArray` conexão manualmente, altere a referência de `CComUnkArray<` *n* `>`, onde *n* é o número de pontos de conexão necessários.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="ccomdynamicunkarrayadd"></a><a name="add"></a>CComDynamicUnkArray::Adicionar

Chame este método `IUnknown` para adicionar um ponteiro à matriz.

```
DWORD Add(IUnknown* pUnk);
```

### <a name="parameters"></a>Parâmetros

*Punk*<br/>
O `IUnknown` ponteiro para adicionar à matriz.

### <a name="return-value"></a>Valor retornado

Retorna o cookie associado ao ponteiro recém-adicionado.

## <a name="ccomdynamicunkarraybegin"></a><a name="begin"></a>CComDynamicUnkArray::iniciar

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

## <a name="ccomdynamicunkarrayclear"></a><a name="clear"></a>CComDynamicUnkArray::clear

Esvazia a matriz.

```
void clear();
```

## <a name="ccomdynamicunkarrayccomdynamicunkarray"></a><a name="ccomdynamicunkarray"></a>CComDynamicUnkArray::CComDynamicUnkArray

O construtor.

```
CComDynamicUnkArray();
```

### <a name="remarks"></a>Comentários

Define o tamanho da coleção como zero e inicializa os valores para NULL. O destruidor libera a coleta, se necessário.

## <a name="ccomdynamicunkarrayccomdynamicunkarray"></a><a name="dtor"></a>CComDynamicUnkArray::~CComDynamicUnkArray

O destruidor.

```
~CComDynamicUnkArray();
```

### <a name="remarks"></a>Comentários

Libera recursos alocados pelo construtor da classe.

## <a name="ccomdynamicunkarrayend"></a><a name="end"></a>CComDynamicUnkArray::end

Retorna um ponteiro para `IUnknown` um passado o último ponteiro na coleção.

```
IUnknown**
    end();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro `IUnknown` para um ponteiro de interface.

## <a name="ccomdynamicunkarraygetat"></a><a name="getat"></a>CComDynamicUnkArray::GetAt

Recupera o elemento no índice especificado.

```
IUnknown* GetAt(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice do elemento a ser recuperado.

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma interface [IUnknown.](/windows/win32/api/unknwn/nn-unknwn-iunknown)

## <a name="ccomdynamicunkarraygetcookie"></a><a name="getcookie"></a>CComDynamicUnkArray::GetCookie

Chame este método para obter o `IUnknown` cookie associado a um determinado ponteiro.

```
DWORD WINAPI GetCookie(IUnknown** ppFind);
```

### <a name="parameters"></a>Parâmetros

*ppFind*<br/>
O `IUnknown` ponteiro para o qual o cookie associado é necessário.

### <a name="return-value"></a>Valor retornado

Retorna o cookie `IUnknown` associado ao ponteiro ou `IUnknown` zero se nenhum ponteiro correspondente for encontrado.

### <a name="remarks"></a>Comentários

Se houver mais de uma `IUnknown` instância do mesmo ponteiro, esta função retorna o cookie para o primeiro.

## <a name="ccomdynamicunkarraygetsize"></a><a name="getsize"></a>CComDynamicUnkArray::GetSize

Retorna o comprimento de uma matriz.

```
int GetSize() const;
```

### <a name="return-value"></a>Valor retornado

O comprimento da matriz.

## <a name="ccomdynamicunkarraygetunknown"></a><a name="getunknown"></a>CComDynamicUnkArray::GetUnknown

Chame este método `IUnknown` para obter o ponteiro associado a um determinado cookie.

```
IUnknown* WINAPI GetUnknown(DWORD dwCookie);
```

### <a name="parameters"></a>Parâmetros

*Dwcookie*<br/>
O cookie para `IUnknown` o qual o ponteiro associado é necessário.

### <a name="return-value"></a>Valor retornado

Retorna `IUnknown` o ponteiro ou NULL se nenhum cookie correspondente for encontrado.

## <a name="ccomdynamicunkarrayremove"></a><a name="remove"></a>CComDynamicUnkArray::Remove

Chame este método `IUnknown` para remover um ponteiro da matriz.

```
BOOL Remove(DWORD dwCookie);
```

### <a name="parameters"></a>Parâmetros

*Dwcookie*<br/>
O cookie que `IUnknown` faz referência ao ponteiro a ser removido da matriz.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o ponteiro for removido; caso contrário, FALSO.

## <a name="see-also"></a>Confira também

[Classe CComUnkArray](../../atl/reference/ccomunkarray-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
