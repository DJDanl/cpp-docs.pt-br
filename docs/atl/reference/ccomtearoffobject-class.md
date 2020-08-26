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
ms.openlocfilehash: 3eee1d33d5eded75d8805584a24e6b6f396a8369
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88833615"
---
# <a name="ccomtearoffobject-class"></a>Classe CComTearOffObject

Essa classe implementa uma interface de divisão.

## <a name="syntax"></a>Sintaxe

```
template<class Base>
class CComTearOffObject : public Base
```

#### <a name="parameters"></a>parâmetros

*Polybase*<br/>
Sua classe retirada, derivada de `CComTearOffObjectBase` e as interfaces às quais você deseja que o objeto destacável dê suporte.

A ATL implementa suas interfaces retiradas em duas fases: os `CComTearOffObjectBase` métodos manipulam a contagem de referência e `QueryInterface` , enquanto `CComTearOffObject` implementam [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown).

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComTearOffObject::CComTearOffObject](#ccomtearoffobject)|O construtor.|
|[CComTearOffObject:: ~ CComTearOffObject](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComTearOffObject:: AddRef](#addref)|Incrementa a contagem de referência para um `CComTearOffObject` objeto.|
|[CComTearOffObject:: QueryInterface](#queryinterface)|Retorna um ponteiro para a interface solicitada na sua classe destacável ou na classe Owner.|
|[CComTearOffObject:: versão](#release)|Decrementa a contagem de referência de um `CComTearOffObject` objeto e destrói-o.|

### <a name="ccomtearoffobjectbase-methods"></a>Métodos CComTearOffObjectBase

|Função|Descrição|
|-|-|
|[CComTearOffObjectBase](#ccomtearoffobjectbase)|Construtor.|

### <a name="ccomtearoffobjectbase-data-members"></a>Membros de dados do CComTearOffObjectBase

|Membro de dados|Descrição|
|-|-|
|[m_pOwner](#m_powner)|Um ponteiro para um `CComObject` derivado da classe Owner.|

## <a name="remarks"></a>Comentários

`CComTearOffObject` implementa uma interface de divisão como um objeto separado que é instanciado somente quando essa interface é consultada. A redivisão é excluída quando sua contagem de referência se torna zero. Normalmente, você cria uma interface retirada para uma interface que raramente é usada, uma vez que usar uma remontagem salva um ponteiro vtable em todas as instâncias do seu objeto principal.

Você deve derivar a classe que implementa a divisão de `CComTearOffObjectBase` e de qualquer uma das interfaces às quais você deseja que o objeto retirado dê suporte. `CComTearOffObjectBase` é modelos na classe Owner e no modelo de thread. A classe Owner é a classe do objeto para o qual uma redivisão está sendo implementada. Se você não especificar um modelo de thread, o modelo de thread padrão será usado.

Você deve criar um mapa COM para sua classe destacável. Quando a ATL instancia a divisão, ela criará `CComTearOffObject<CYourTearOffClass>` ou `CComCachedTearOffObject<CYourTearOffClass>` .

Por exemplo, no exemplo de BEEPr, a `CBeeper2` classe é a classe de divisão e a `CBeeper` classe é a classe de proprietário:

[!code-cpp[NVC_ATL_COM#43](../../atl/codesnippet/cpp/ccomtearoffobject-class_1.h)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Base`

`CComTearOffObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

## <a name="ccomtearoffobjectaddref"></a><a name="addref"></a> CComTearOffObject:: AddRef

Incrementa a contagem de referência do `CComTearOffObject` objeto em um.

```
STDMETHOD_(ULONG, AddRef)();
```

### <a name="return-value"></a>Valor Retornado

Um valor que pode ser útil para diagnóstico e teste.

## <a name="ccomtearoffobjectccomtearoffobject"></a><a name="ccomtearoffobject"></a> CComTearOffObject::CComTearOffObject

O construtor.

```
CComTearOffObject(void* pv);
```

### <a name="parameters"></a>parâmetros

*PV*<br/>
no Ponteiro que será convertido em um ponteiro para um `CComObject<Owner>` objeto.

### <a name="remarks"></a>Comentários

Incrementa a contagem de referência do proprietário em um.

## <a name="ccomtearoffobjectccomtearoffobject"></a><a name="dtor"></a> CComTearOffObject:: ~ CComTearOffObject

O destruidor.

```
~CComTearOffObject();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados, chama FinalRelease e decrementa a contagem de bloqueios de módulo.

## <a name="ccomtearoffobjectccomtearoffobjectbase"></a><a name="ccomtearoffobjectbase"></a> CComTearOffObject::CComTearOffObjectBase

O construtor.

```
CComTearOffObjectBase();
```

### <a name="remarks"></a>Comentários

Inicializa o membro [m_pOwner](#m_powner) como nulo.

## <a name="ccomtearoffobjectm_powner"></a><a name="m_powner"></a> CComTearOffObject:: m_pOwner

Um ponteiro para um objeto [CComObject](../../atl/reference/ccomobject-class.md) derivado do *proprietário*.

```
CComObject<Owner>* m_pOwner;
```

### <a name="parameters"></a>parâmetros

*Proprietário*<br/>
no A classe para a qual uma redivisão está sendo implementada.

### <a name="remarks"></a>Comentários

O ponteiro é inicializado para NULL durante a construção.

## <a name="ccomtearoffobjectqueryinterface"></a><a name="queryinterface"></a> CComTearOffObject:: QueryInterface

Recupera um ponteiro para a interface solicitada.

```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
```

### <a name="parameters"></a>parâmetros

*IID*<br/>
no O IID da interface que está sendo solicitada.

*ppvObject*<br/>
fora Um ponteiro para o ponteiro de interface identificado por *IID*ou NULL se a interface não for encontrada.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Consulta primeiro para interfaces em sua classe destacável. Se a interface não existir, o consultará a interface no objeto do proprietário. Se a interface solicitada for `IUnknown` , retornará o `IUnknown` do proprietário.

## <a name="ccomtearoffobjectrelease"></a><a name="release"></a> CComTearOffObject:: versão

Decrementa a contagem de referência em um e, se a contagem de referência for zero, excluirá o `CComTearOffObject` .

```
STDMETHOD_ULONG Release();
```

### <a name="return-value"></a>Valor Retornado

Em compilações não depuradas, o sempre retorna zero. Em compilações de depuração, retorna um valor que pode ser útil para diagnóstico ou teste.

## <a name="see-also"></a>Confira também

[Classe CComCachedTearOffObject](../../atl/reference/ccomcachedtearoffobject-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
