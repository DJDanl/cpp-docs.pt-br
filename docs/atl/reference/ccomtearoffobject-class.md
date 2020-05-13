---
title: Classe Ccomtearoffobject
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
ms.openlocfilehash: de7528d3972991c233ee4b9037f609b89d0f7434
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327317"
---
# <a name="ccomtearoffobject-class"></a>Classe Ccomtearoffobject

Esta classe implementa uma interface de ruptura.

## <a name="syntax"></a>Sintaxe

```
template<class Base>
class CComTearOffObject : public Base
```

#### <a name="parameters"></a>Parâmetros

*Base*<br/>
Sua classe de tear-off, derivada `CComTearOffObjectBase` e das interfaces que você deseja que seu objeto tear-off suporte.

A ATL implementa suas interfaces de tear-off em duas fases — os `CComTearOffObjectBase` métodos lidam com a contagem de referência `QueryInterface`e, enquanto `CComTearOffObject` implementa o [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown).

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Ccomtearoffobject::Ccomtearoffobject](#ccomtearoffobject)|O construtor.|
|[Ccomtearoffobject::~Ccomtearoffobject](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Ccomtearoffobject::Addref](#addref)|Incrementa a contagem `CComTearOffObject` de referência para um objeto.|
|[CComTearOffObject::QueryInterface](#queryinterface)|Retorna um ponteiro para a interface solicitada na sua classe de tear-off ou na classe proprietário.|
|[Ccomtearoffobject::lançamento](#release)|Decreta a contagem de `CComTearOffObject` referência para um objeto e destrói-o.|

### <a name="ccomtearoffobjectbase-methods"></a>CComTearOffObjectBase Métodos de base

|||
|-|-|
|[Ccomtearoffobjectbase](#ccomtearoffobjectbase)|Construtor.|

### <a name="ccomtearoffobjectbase-data-members"></a>CComTearOffObjectBase Data Members

|||
|-|-|
|[m_pOwner](#m_powner)|Um ponteiro `CComObject` para um derivado da classe do proprietário.|

## <a name="remarks"></a>Comentários

`CComTearOffObject`implementa uma interface tear-off como um objeto separado que é instanciado somente quando essa interface é consultada. O tear-off é excluído quando sua contagem de referência se torna zero. Normalmente, você constrói uma interface de ruptura para uma interface que raramente é usada, uma vez que o uso de um tear-off salva um ponteiro vtable em todas as instâncias do seu objeto principal.

Você deve derivar a classe que `CComTearOffObjectBase` implementa o tear-off de e de quaisquer interfaces que você deseja que seu objeto de ruptura suporte. `CComTearOffObjectBase`é templatizado na classe proprietário e no modelo de rosca. A classe proprietária é a classe do objeto para o qual um tear-off está sendo implementado. Se você não especificar um modelo de segmento, o modelo de rosca padrão será usado.

Você deve criar um mapa COM para sua classe de tear-off. Quando a ATL instanciar o `CComTearOffObject<CYourTearOffClass>` tear-off, ele criará ou `CComCachedTearOffObject<CYourTearOffClass>`.

Por exemplo, na amostra BEEPER, a `CBeeper2` classe é `CBeeper` a classe tear-off e a classe é a classe proprietário:

[!code-cpp[NVC_ATL_COM#43](../../atl/codesnippet/cpp/ccomtearoffobject-class_1.h)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Base`

`CComTearOffObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="ccomtearoffobjectaddref"></a><a name="addref"></a>Ccomtearoffobject::Addref

Incrementa a contagem `CComTearOffObject` de referência do objeto por um.

```
STDMETHOD_(ULONG, AddRef)();
```

### <a name="return-value"></a>Valor retornado

Um valor que pode ser útil para diagnósticos e testes.

## <a name="ccomtearoffobjectccomtearoffobject"></a><a name="ccomtearoffobject"></a>Ccomtearoffobject::Ccomtearoffobject

O construtor.

```
CComTearOffObject(void* pv);
```

### <a name="parameters"></a>Parâmetros

*Pv*<br/>
[em] Ponteiro que será convertido em um `CComObject<Owner>` ponteiro para um objeto.

### <a name="remarks"></a>Comentários

Incrementa a contagem de referência do proprietário por um.

## <a name="ccomtearoffobjectccomtearoffobject"></a><a name="dtor"></a>Ccomtearoffobject::~Ccomtearoffobject

O destruidor.

```
~CComTearOffObject();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados, chama A Liberação Final e decreta a contagem de bloqueio do módulo.

## <a name="ccomtearoffobjectccomtearoffobjectbase"></a><a name="ccomtearoffobjectbase"></a>Ccomtearoffobject::CcomtearoffobjectBase

O construtor.

```
CComTearOffObjectBase();
```

### <a name="remarks"></a>Comentários

Inicializa o [membro m_pOwner](#m_powner) para NULL.

## <a name="ccomtearoffobjectm_powner"></a><a name="m_powner"></a>CComTearOffobject::m_pOwner

Um ponteiro para um objeto [CComObject](../../atl/reference/ccomobject-class.md) derivado do *Proprietário*.

```
CComObject<Owner>* m_pOwner;
```

### <a name="parameters"></a>Parâmetros

*Proprietário*<br/>
[em] A classe para a qual um rompimento está sendo implementado.

### <a name="remarks"></a>Comentários

O ponteiro é inicializado para NULL durante a construção.

## <a name="ccomtearoffobjectqueryinterface"></a><a name="queryinterface"></a>CComTearOffObject::QueryInterface

Recupera um ponteiro para a interface solicitada.

```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
```

### <a name="parameters"></a>Parâmetros

*Iid*<br/>
[em] O IID da interface que está sendo solicitado.

*Ppvobject*<br/>
[fora] Um ponteiro para o ponteiro de interface identificado por *iid*ou NULL se a interface não for encontrada.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Consultas primeiro para interfaces em sua classe de tear-off. Se a interface não estiver lá, consultas para a interface no objeto proprietário. Se a interface `IUnknown`solicitada for `IUnknown` , retorna o do proprietário.

## <a name="ccomtearoffobjectrelease"></a><a name="release"></a>Ccomtearoffobject::lançamento

Diminui a contagem de referência por um e, se a `CComTearOffObject`contagem de referência for zero, exclui o .

```
STDMETHOD_ULONG Release();
```

### <a name="return-value"></a>Valor retornado

Em construções não-depuradas, sempre retorna zero. Nas compilações de depuração, retorna um valor que pode ser útil para diagnósticos ou testes.

## <a name="see-also"></a>Confira também

[CComCachedTearOffObject Class](../../atl/reference/ccomcachedtearoffobject-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
