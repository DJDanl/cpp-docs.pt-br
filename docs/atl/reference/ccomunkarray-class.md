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
ms.openlocfilehash: 4577e77ac71bbb2e65c8c6168d0d28d5765d551f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50550248"
---
# <a name="ccomunkarray-class"></a>Classe CComUnkArray

Essa classe armazena `IUnknown` ponteiros e é projetado para ser usado como um parâmetro para o [IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md) classe de modelo.

## <a name="syntax"></a>Sintaxe

```
template<unsigned int nMaxSize>
class CComUnkArray
```

#### <a name="parameters"></a>Parâmetros

*nMaxSize*<br/>
O número máximo de `IUnknown` ponteiros que podem ser mantidos na matriz estática.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComUnkArray::CComUnkArray](#ccomunkarray)|Construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComUnkArray::Add](#add)|Chame este método para adicionar um `IUnknown` ponteiro para a matriz.|
|[CComUnkArray::begin](#begin)|Retorna um ponteiro para o primeiro `IUnknown` ponteiro na coleção.|
|[CComUnkArray::end](#end)|Retorna um ponteiro para a posição logo após o último `IUnknown` ponteiro na coleção.|
|[CComUnkArray::GetCookie](#getcookie)|Chame esse método para obter o cookie associado com um determinado `IUnknown` ponteiro.|
|[CComUnkArray::GetUnknown](#getunknown)|Chame esse método para obter o `IUnknown` ponteiro associado a um cookie especificado.|
|[CComUnkArray::Remove](#remove)|Chame esse método para remover um `IUnknown` ponteiro da matriz.|

## <a name="remarks"></a>Comentários

`CComUnkArray` contém um número fixo de `IUnknown` ponteiros, cada ponto de uma interface em uma conexão. `CComUnkArray` pode ser usado como um parâmetro para o [IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md) classe de modelo. `CComUnkArray<1>` é uma especialização de modelo de `CComUnkArray` que foi otimizado para o ponto de uma conexão.

O `CComUnkArray` métodos [begin](#begin) e [end](#end) pode ser usado para executar loop em todos os pontos de conexão (por exemplo, quando um evento é disparado).

Ver [adicionando pontos de Conexão a um objeto](../../atl/adding-connection-points-to-an-object.md) proxies de ponto para obter detalhes sobre como automatizar a criação de conexão.

> [!NOTE]
> **Observação** a classe [CComDynamicUnkArray](../../atl/reference/ccomdynamicunkarray-class.md) é usado pelo **Adicionar classe** assistente ao criar um controle que tem pontos de Conexão. Se você quiser especificar o número de pontos de Conexão manualmente, altere a referência de `CComDynamicUnkArray` à `CComUnkArray<` *n* `>`, onde *n* é o número de pontos de conexão Necessário.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="add"></a>  CComUnkArray::Add

Chame este método para adicionar um `IUnknown` ponteiro para a matriz.

```
DWORD Add(IUnknown* pUnk);
```

### <a name="parameters"></a>Parâmetros

*pUnk*<br/>
Chame este método para adicionar um `IUnknown` ponteiro para a matriz.

### <a name="return-value"></a>Valor de retorno

Retorna o cookie associado com o ponteiro recém-adicionada, ou 0 se a matriz não é grande o suficiente para conter o novo ponteiro.

##  <a name="begin"></a>  CComUnkArray::begin

Retorna um ponteiro para o início da coleção de `IUnknown` ponteiros de interface.

```
IUnknown**
    begin();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um `IUnknown` ponteiro de interface.

### <a name="remarks"></a>Comentários

A coleção contém ponteiros para interfaces armazenados localmente como `IUnknown`. Você converter cada `IUnknown` de interface para o tipo de interface real e, em seguida, chamar por meio dele. Você não precisa consultar a interface pela primeira vez.

Antes de usar o `IUnknown` interface, você deve verificar se ele não é nulo.

##  <a name="ccomunkarray"></a>  CComUnkArray::CComUnkArray

O construtor.

```
CComUnkArray();
```

### <a name="remarks"></a>Comentários

Define a coleção para manter `nMaxSize` `IUnknown` ponteiros e inicializa os ponteiros para NULL.

##  <a name="end"></a>  CComUnkArray::end

Retorna um ponteiro para a posição logo após o último `IUnknown` ponteiro na coleção.

```
IUnknown**
    end();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um `IUnknown` ponteiro de interface.

### <a name="remarks"></a>Comentários

O `CComUnkArray` métodos `begin` e `end` pode ser usado para executar loop em todos os pontos de conexão, por exemplo, quando um evento é disparado.

[!code-cpp[NVC_ATL_COM#44](../../atl/codesnippet/cpp/ccomunkarray-class_1.cpp)]

##  <a name="getcookie"></a>  CComUnkArray::GetCookie

Chame esse método para obter o cookie associado com um determinado `IUnknown` ponteiro.

```
DWORD WINAPI GetCookie(IUnknown** ppFind);
```

### <a name="parameters"></a>Parâmetros

*ppFind*<br/>
O `IUnknown` ponteiro para o qual o cookie associado é necessário.

### <a name="return-value"></a>Valor de retorno

Retorna o cookie associado a `IUnknown` ponteiro ou 0 se nenhuma correspondência `IUnknown` ponteiro for encontrado.

### <a name="remarks"></a>Comentários

Se houver mais de uma instância do mesmo `IUnknown` ponteiro, essa função retorna o cookie para o primeiro.

##  <a name="getunknown"></a>  CComUnkArray::GetUnknown

Chame esse método para obter o `IUnknown` ponteiro associado a um cookie especificado.

```
IUnknown* WINAPI GetUnknown(DWORD dwCookie);
```

### <a name="parameters"></a>Parâmetros

*dwCookie*<br/>
O cookie para o qual associado `IUnknown` ponteiro é necessário.

### <a name="return-value"></a>Valor de retorno

Retorna o `IUnknown` ponteiro, ou nulo se nenhum cookie correspondente for encontrado.

##  <a name="remove"></a>  CComUnkArray::Remove

Chame esse método para remover um `IUnknown` ponteiro da matriz.

```
BOOL Remove(DWORD dwCookie);
```

### <a name="parameters"></a>Parâmetros

*dwCookie*<br/>
O cookie referenciando o `IUnknown` ponteiro a ser removido da matriz.

### <a name="return-value"></a>Valor de retorno

Retorna TRUE se o ponteiro for removido, FALSE caso contrário.

## <a name="see-also"></a>Consulte também

[Classe CComDynamicUnkArray](../../atl/reference/ccomdynamicunkarray-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
