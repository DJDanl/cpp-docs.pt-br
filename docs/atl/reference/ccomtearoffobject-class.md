---
title: Classe CComTearOffObject
ms.date: 11/04/2016
f1_keywords:
- CComTearOffObject
- ATLCOM/ATL::CComTearOffObject
- ATLCOM/ATL::CComTearOffObject::CComTearOffObject
- ATLCOM/ATL::CComTearOffObject::AddRef
- ATLCOM/ATL::CComTearOffObject::QueryInterface
- ATLCOM/ATL::CComTearOffObject::Release
- ATLCOM/ATL::CComTearOffObjectBase
- ATLCOM/ATL::m_pOwner
helpviewer_keywords:
- tear-off interfaces, ATL
- tear-off interfaces
- CComTearOffObject class
ms.assetid: d974b598-c6b2-42b1-8360-9190d9d0fbf3
ms.openlocfilehash: 0d27a6fa3c0070cd32c78971a7544327c51d4393
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69496911"
---
# <a name="ccomtearoffobject-class"></a>Classe CComTearOffObject

Essa classe implementa uma interface de divisão.

## <a name="syntax"></a>Sintaxe

```
template<class Base>
class CComTearOffObject : public Base
```

#### <a name="parameters"></a>Parâmetros

*Polybase*<br/>
Sua classe retirada, derivada de `CComTearOffObjectBase` e as interfaces às quais você deseja que o objeto destacável dê suporte.

A ATL implementa suas interfaces retiradas em duas fases: `CComTearOffObjectBase` os métodos manipulam a contagem `QueryInterface`de referência `CComTearOffObject` e, enquanto implementam [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown).

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComTearOffObject::CComTearOffObject](#ccomtearoffobject)|O construtor.|
|[CComTearOffObject::~CComTearOffObject](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComTearOffObject::AddRef](#addref)|Incrementa a contagem de referência para um `CComTearOffObject` objeto.|
|[CComTearOffObject::QueryInterface](#queryinterface)|Retorna um ponteiro para a interface solicitada na sua classe destacável ou na classe Owner.|
|[CComTearOffObject::Release](#release)|Decrementa a contagem de referência de um `CComTearOffObject` objeto e destrói-o.|

### <a name="ccomtearoffobjectbase-methods"></a>Métodos CComTearOffObjectBase

|||
|-|-|
|[CComTearOffObjectBase](#ccomtearoffobjectbase)|Construtor.|

### <a name="ccomtearoffobjectbase-data-members"></a>Membros de dados do CComTearOffObjectBase

|||
|-|-|
|[m_pOwner](#m_powner)|Um ponteiro para um `CComObject` derivado da classe Owner.|

## <a name="remarks"></a>Comentários

`CComTearOffObject`implementa uma interface de divisão como um objeto separado que é instanciado somente quando essa interface é consultada. A redivisão é excluída quando sua contagem de referência se torna zero. Normalmente, você cria uma interface retirada para uma interface que raramente é usada, uma vez que usar uma remontagem salva um ponteiro vtable em todas as instâncias do seu objeto principal.

Você deve derivar a classe que implementa a divisão de `CComTearOffObjectBase` e de qualquer uma das interfaces às quais você deseja que o objeto retirado dê suporte. `CComTearOffObjectBase`é modelos na classe Owner e no modelo de thread. A classe Owner é a classe do objeto para o qual uma redivisão está sendo implementada. Se você não especificar um modelo de thread, o modelo de thread padrão será usado.

Você deve criar um mapa COM para sua classe destacável. Quando a ATL instancia a divisão, ela criará `CComTearOffObject<CYourTearOffClass>` ou. `CComCachedTearOffObject<CYourTearOffClass>`

Por exemplo, no exemplo de beepr, a `CBeeper2` classe é a classe de divisão e a `CBeeper` classe é a classe de proprietário:

[!code-cpp[NVC_ATL_COM#43](../../atl/codesnippet/cpp/ccomtearoffobject-class_1.h)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Base`

`CComTearOffObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="addref"></a>  CComTearOffObject::AddRef

Incrementa a contagem de referência do `CComTearOffObject` objeto em um.

```
STDMETHOD_(ULONG, AddRef)();
```

### <a name="return-value"></a>Valor de retorno

Um valor que pode ser útil para diagnóstico e teste.

##  <a name="ccomtearoffobject"></a>  CComTearOffObject::CComTearOffObject

O construtor.

```
CComTearOffObject(void* pv);
```

### <a name="parameters"></a>Parâmetros

*pv*<br/>
no Ponteiro que será convertido em um ponteiro para um `CComObject<Owner>` objeto.

### <a name="remarks"></a>Comentários

Incrementa a contagem de referência do proprietário em um.

##  <a name="dtor"></a>  CComTearOffObject::~CComTearOffObject

O destruidor.

```
~CComTearOffObject();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados, chama FinalRelease e decrementa a contagem de bloqueios de módulo.

##  <a name="ccomtearoffobjectbase"></a>  CComTearOffObject::CComTearOffObjectBase

O construtor.

```
CComTearOffObjectBase();
```

### <a name="remarks"></a>Comentários

Inicializa o membro [m_pOwner](#m_powner) como nulo.

##  <a name="m_powner"></a>  CComTearOffObject::m_pOwner

Um ponteiro para um objeto [CComObject](../../atl/reference/ccomobject-class.md) derivado do *proprietário*.

```
CComObject<Owner>* m_pOwner;
```

### <a name="parameters"></a>Parâmetros

*Proprietário*<br/>
no A classe para a qual uma redivisão está sendo implementada.

### <a name="remarks"></a>Comentários

O ponteiro é inicializado para NULL durante a construção.

##  <a name="queryinterface"></a>  CComTearOffObject::QueryInterface

Recupera um ponteiro para a interface solicitada.

```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
```

### <a name="parameters"></a>Parâmetros

*iid*<br/>
no O IID da interface que está sendo solicitada.

*ppvObject*<br/>
fora Um ponteiro para o ponteiro de interface identificado por *IID*ou NULL se a interface não for encontrada.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Consulta primeiro para interfaces em sua classe destacável. Se a interface não existir, o consultará a interface no objeto do proprietário. Se a interface solicitada `IUnknown`for, retornará `IUnknown` o do proprietário.

##  <a name="release"></a>  CComTearOffObject::Release

Decrementa a contagem de referência em um e, se a contagem de referência for zero, excluirá o `CComTearOffObject`.

```
STDMETHOD_ULONG Release();
```

### <a name="return-value"></a>Valor de retorno

Em compilações não depuradas, o sempre retorna zero. Em compilações de depuração, retorna um valor que pode ser útil para diagnóstico ou teste.

## <a name="see-also"></a>Consulte também

[Classe CComCachedTearOffObject](../../atl/reference/ccomcachedtearoffobject-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
