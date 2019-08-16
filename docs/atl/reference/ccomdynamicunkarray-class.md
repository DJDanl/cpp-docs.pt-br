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
ms.openlocfilehash: d55a6d6bfbcc6921fa0633753365f5799388dc27
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497242"
---
# <a name="ccomdynamicunkarray-class"></a>Classe CComDynamicUnkArray

Essa classe armazena uma matriz de `IUnknown` ponteiros.

## <a name="syntax"></a>Sintaxe

```
class CComDynamicUnkArray
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComDynamicUnkArray::CComDynamicUnkArray](#ccomdynamicunkarray)|Construtor. Inicializa os valores da coleção como NULL e o tamanho da coleção como zero.|
|[CComDynamicUnkArray::~CComDynamicUnkArray](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComDynamicUnkArray::Add](#add)|Chame esse método para adicionar um `IUnknown` ponteiro à matriz.|
|[CComDynamicUnkArray::begin](#begin)|Retorna um ponteiro para o primeiro `IUnknown` ponteiro na coleção.|
|[CComDynamicUnkArray::clear](#clear)|Esvazia a matriz.|
|[CComDynamicUnkArray::end](#end)|Retorna um ponteiro para um após o último `IUnknown` ponteiro na coleção.|
|[CComDynamicUnkArray::GetAt](#getat)|Recupera o elemento no índice especificado.|
|[CComDynamicUnkArray::GetCookie](#getcookie)|Chame esse método para obter o cookie associado a um determinado `IUnknown` ponteiro.|
|[CComDynamicUnkArray::GetSize](#getsize)|Retorna o comprimento de uma matriz.|
|[CComDynamicUnkArray::GetUnknown](#getunknown)|Chame esse método para obter o `IUnknown` ponteiro associado a um determinado cookie.|
|[CComDynamicUnkArray::Remove](#remove)|Chame esse método para remover um `IUnknown` ponteiro da matriz.|

## <a name="remarks"></a>Comentários

`CComDynamicUnkArray`mantém uma matriz de `IUnknown` ponteiros alocada dinamicamente, cada uma com uma interface em um ponto de conexão. `CComDynamicUnkArray`pode ser usado como um parâmetro para a classe de modelo [IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md) .

Os `CComDynamicUnkArray` métodos [begin](#begin) e [end](#end) podem ser usados para executar um loop em todos os pontos de conexão (por exemplo, quando um evento é acionado).

Consulte [adicionando pontos de conexão a um objeto](../../atl/adding-connection-points-to-an-object.md) para obter detalhes sobre como automatizar a criação de proxies de ponto de conexão.

> [!NOTE]
> **Observação** A classe `CComDynamicUnkArray` é usada pelo Assistente para **Adicionar classe** ao criar um controle que tem pontos de conexão. Se você quiser especificar o número de pontos de conexão manualmente, altere a referência de `CComDynamicUnkArray` para `CComUnkArray<` *n* `>`, em que *n* é o número de pontos de conexão necessários.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="add"></a>  CComDynamicUnkArray::Add

Chame esse método para adicionar um `IUnknown` ponteiro à matriz.

```
DWORD Add(IUnknown* pUnk);
```

### <a name="parameters"></a>Parâmetros

*pUnk*<br/>
O `IUnknown` ponteiro a ser adicionado à matriz.

### <a name="return-value"></a>Valor de retorno

Retorna o cookie associado ao ponteiro recém-adicionado.

##  <a name="begin"></a>  CComDynamicUnkArray::begin

Retorna um ponteiro para o início da coleção de ponteiros de `IUnknown` interface.

```
IUnknown**
    begin();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um `IUnknown` ponteiro de interface.

### <a name="remarks"></a>Comentários

A coleção contém ponteiros para interfaces armazenadas localmente `IUnknown`como. Você converte cada `IUnknown` interface para o tipo de interface real e, em seguida, a chama. Você não precisa consultar a interface primeiro.

Antes de usar `IUnknown` a interface, você deve verificar se ela não é nula.

##  <a name="clear"></a>  CComDynamicUnkArray::clear

Esvazia a matriz.

```
void clear();
```

##  <a name="ccomdynamicunkarray"></a>  CComDynamicUnkArray::CComDynamicUnkArray

O construtor.

```
CComDynamicUnkArray();
```

### <a name="remarks"></a>Comentários

Define o tamanho da coleção como zero e inicializa os valores como NULL. O destruidor libera a coleção, se necessário.

##  <a name="dtor"></a>  CComDynamicUnkArray::~CComDynamicUnkArray

O destruidor.

```
~CComDynamicUnkArray();
```

### <a name="remarks"></a>Comentários

Libera recursos alocados pelo construtor de classe.

##  <a name="end"></a>  CComDynamicUnkArray::end

Retorna um ponteiro para um após o último `IUnknown` ponteiro na coleção.

```
IUnknown**
    end();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um `IUnknown` ponteiro de interface.

##  <a name="getat"></a>  CComDynamicUnkArray::GetAt

Recupera o elemento no índice especificado.

```
IUnknown* GetAt(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice do elemento a ser recuperado.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para uma interface [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) .

##  <a name="getcookie"></a>  CComDynamicUnkArray::GetCookie

Chame esse método para obter o cookie associado a um determinado `IUnknown` ponteiro.

```
DWORD WINAPI GetCookie(IUnknown** ppFind);
```

### <a name="parameters"></a>Parâmetros

*ppFind*<br/>
O `IUnknown` ponteiro para o qual o cookie associado é necessário.

### <a name="return-value"></a>Valor de retorno

Retorna o cookie associado `IUnknown` ao ponteiro ou zero se nenhum ponteiro correspondente `IUnknown` for encontrado.

### <a name="remarks"></a>Comentários

Se houver mais de uma instância do mesmo `IUnknown` ponteiro, essa função retornará o cookie para o primeiro.

##  <a name="getsize"></a>  CComDynamicUnkArray::GetSize

Retorna o comprimento de uma matriz.

```
int GetSize() const;
```

### <a name="return-value"></a>Valor de retorno

O comprimento da matriz.

##  <a name="getunknown"></a>  CComDynamicUnkArray::GetUnknown

Chame esse método para obter o `IUnknown` ponteiro associado a um determinado cookie.

```
IUnknown* WINAPI GetUnknown(DWORD dwCookie);
```

### <a name="parameters"></a>Parâmetros

*dwCookie*<br/>
O cookie para o qual o `IUnknown` ponteiro associado é necessário.

### <a name="return-value"></a>Valor de retorno

Retorna o `IUnknown` ponteiro ou nulo se nenhum cookie correspondente for encontrado.

##  <a name="remove"></a>  CComDynamicUnkArray::Remove

Chame esse método para remover um `IUnknown` ponteiro da matriz.

```
BOOL Remove(DWORD dwCookie);
```

### <a name="parameters"></a>Parâmetros

*dwCookie*<br/>
O cookie que faz `IUnknown` referência ao ponteiro a ser removido da matriz.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o ponteiro for removido; caso contrário, FALSE.

## <a name="see-also"></a>Consulte também

[Classe CComUnkArray](../../atl/reference/ccomunkarray-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
