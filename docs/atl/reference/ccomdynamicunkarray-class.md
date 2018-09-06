---
title: Classe CComDynamicUnkArray | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- connection points [C++], managing
- CComDynamicUnkArray class
ms.assetid: 202470d7-9a1b-498f-b96d-659d681acd65
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 71b36f19cc6e3deddbd5984e63b70c61a0ca8ea8
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43762763"
---
# <a name="ccomdynamicunkarray-class"></a>Classe CComDynamicUnkArray

Essa classe armazena uma matriz de `IUnknown` ponteiros.

## <a name="syntax"></a>Sintaxe

```
class CComDynamicUnkArray
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComDynamicUnkArray::CComDynamicUnkArray](#ccomdynamicunkarray)|Construtor. Inicializa os valores da coleção como NULL e o tamanho da coleção como zero.|
|[CComDynamicUnkArray:: ~ CComDynamicUnkArray](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComDynamicUnkArray::Add](#add)|Chame este método para adicionar um `IUnknown` ponteiro para a matriz.|
|[CComDynamicUnkArray::begin](#begin)|Retorna um ponteiro para o primeiro `IUnknown` ponteiro na coleção.|
|[CComDynamicUnkArray::clear](#clear)|Esvazia a matriz.|
|[CComDynamicUnkArray::end](#end)|Retorna um ponteiro para a posição logo após o último `IUnknown` ponteiro na coleção.|
|[CComDynamicUnkArray::GetAt](#getat)|Recupera o elemento no índice especificado.|
|[CComDynamicUnkArray::GetCookie](#getcookie)|Chame esse método para obter o cookie associado com um determinado `IUnknown` ponteiro.|
|[CComDynamicUnkArray::GetSize](#getsize)|Retorna o comprimento de uma matriz.|
|[CComDynamicUnkArray::GetUnknown](#getunknown)|Chame esse método para obter o `IUnknown` ponteiro associado a um cookie especificado.|
|[CComDynamicUnkArray::Remove](#remove)|Chame esse método para remover um `IUnknown` ponteiro da matriz.|

## <a name="remarks"></a>Comentários

`CComDynamicUnkArray` contém uma matriz alocada dinamicamente do `IUnknown` ponteiros, cada ponto de uma interface em uma conexão. `CComDynamicUnkArray` pode ser usado como um parâmetro para o [IConnectionPointImpl](../../atl/reference/iconnectionpointimpl-class.md) classe de modelo.

O `CComDynamicUnkArray` métodos [begin](#begin) e [end](#end) pode ser usado para executar loop em todos os pontos de conexão (por exemplo, quando um evento é disparado).

Ver [adicionando pontos de Conexão a um objeto](../../atl/adding-connection-points-to-an-object.md) proxies de ponto para obter detalhes sobre como automatizar a criação de conexão.

> [!NOTE]
> **Observação** a classe `CComDynamicUnkArray` é usado pelas **Adicionar classe** assistente ao criar um controle que tem pontos de Conexão. Se você quiser especificar o número de pontos de Conexão manualmente, altere a referência de `CComDynamicUnkArray` à `CComUnkArray<` *n* `>`, onde *n* é o número de pontos de conexão Necessário.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="add"></a>  CComDynamicUnkArray::Add

Chame este método para adicionar um `IUnknown` ponteiro para a matriz.

```
DWORD Add(IUnknown* pUnk);
```

### <a name="parameters"></a>Parâmetros

*pUnk*  
O `IUnknown` ponteiro para adicionar à matriz.

### <a name="return-value"></a>Valor de retorno

Retorna o cookie associado com o ponteiro recém-adicionado.

##  <a name="begin"></a>  CComDynamicUnkArray::begin

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

##  <a name="dtor"></a>  CComDynamicUnkArray:: ~ CComDynamicUnkArray

O destruidor.

```
~CComDynamicUnkArray();
```

### <a name="remarks"></a>Comentários

Libera os recursos alocados pelo construtor de classe.

##  <a name="end"></a>  CComDynamicUnkArray::end

Retorna um ponteiro para a posição logo após o último `IUnknown` ponteiro na coleção.

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

*nIndex*  
O índice do elemento a ser recuperado.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface.

##  <a name="getcookie"></a>  CComDynamicUnkArray::GetCookie

Chame esse método para obter o cookie associado com um determinado `IUnknown` ponteiro.

```
DWORD WINAPI GetCookie(IUnknown** ppFind);
```

### <a name="parameters"></a>Parâmetros

*ppFind*  
O `IUnknown` ponteiro para o qual o cookie associado é necessário.

### <a name="return-value"></a>Valor de retorno

Retorna o cookie associado a `IUnknown` ponteiro ou zero se nenhuma correspondência `IUnknown` ponteiro for encontrado.

### <a name="remarks"></a>Comentários

Se houver mais de uma instância do mesmo `IUnknown` ponteiro, essa função retorna o cookie para o primeiro.

##  <a name="getsize"></a>  CComDynamicUnkArray::GetSize

Retorna o comprimento de uma matriz.

```
int GetSize() const;
```

### <a name="return-value"></a>Valor de retorno

O comprimento da matriz.

##  <a name="getunknown"></a>  CComDynamicUnkArray::GetUnknown

Chame esse método para obter o `IUnknown` ponteiro associado a um cookie especificado.

```
IUnknown* WINAPI GetUnknown(DWORD dwCookie);
```

### <a name="parameters"></a>Parâmetros

*dwCookie*  
O cookie para o qual associado `IUnknown` ponteiro é necessário.

### <a name="return-value"></a>Valor de retorno

Retorna o `IUnknown` ponteiro, ou nulo se nenhum cookie correspondente for encontrado.

##  <a name="remove"></a>  CComDynamicUnkArray::Remove

Chame esse método para remover um `IUnknown` ponteiro da matriz.

```
BOOL Remove(DWORD dwCookie);
```

### <a name="parameters"></a>Parâmetros

*dwCookie*  
O cookie referenciando o `IUnknown` ponteiro a ser removido da matriz.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o ponteiro for removido; Caso contrário, FALSE.

## <a name="see-also"></a>Consulte também

[Classe CComUnkArray](../../atl/reference/ccomunkarray-class.md)   
[Visão geral da classe](../../atl/atl-class-overview.md)
