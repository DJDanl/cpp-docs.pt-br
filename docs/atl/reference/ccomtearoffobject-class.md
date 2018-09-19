---
title: Classe CComTearOffObject | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CComTearOffObject
- ATLCOM/ATL::CComTearOffObject
- ATLCOM/ATL::CComTearOffObject::CComTearOffObject
- ATLCOM/ATL::CComTearOffObject::AddRef
- ATLCOM/ATL::CComTearOffObject::QueryInterface
- ATLCOM/ATL::CComTearOffObject::Release
- ATLCOM/ATL::CComTearOffObjectBase
- ATLCOM/ATL::m_pOwner
dev_langs:
- C++
helpviewer_keywords:
- tear-off interfaces, ATL
- tear-off interfaces
- CComTearOffObject class
ms.assetid: d974b598-c6b2-42b1-8360-9190d9d0fbf3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ecbf2b415b93526fe856e21411431eb1f20b4c42
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46089574"
---
# <a name="ccomtearoffobject-class"></a>Classe CComTearOffObject

Essa classe implementa uma interface destacáveis.

## <a name="syntax"></a>Sintaxe

```
template<class Base>
class CComTearOffObject : public Base
```

#### <a name="parameters"></a>Parâmetros

*Base de dados de*<br/>
Sua classe destacável, derivada de `CComTearOffObjectBase` e as interfaces que você deseja que o seu objeto destacáveis para dar suporte.

ATL implementa suas interfaces destacáveis em duas fases — o `CComTearOffObjectBase` métodos lidam com a contagem de referência e `QueryInterface`, enquanto `CComTearOffObject` implementa [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown).

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComTearOffObject::CComTearOffObject](#ccomtearoffobject)|O construtor.|
|[CComTearOffObject:: ~ CComTearOffObject](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComTearOffObject::AddRef](#addref)|Incrementa a contagem de referência para um `CComTearOffObject` objeto.|
|[CComTearOffObject::QueryInterface](#queryinterface)|Retorna um ponteiro para a interface solicitada em sua classe destacáveis ou classe proprietária.|
|[CComTearOffObject::Release](#release)|Diminui a contagem de referência para um `CComTearOffObject` do objeto e destrói a ele.|

### <a name="ccomtearoffobjectbase-methods"></a>Métodos de CComTearOffObjectBase

|||
|-|-|
|[CComTearOffObjectBase](#ccomtearoffobjectbase)|Construtor.|

### <a name="ccomtearoffobjectbase-data-members"></a>Membros de dados CComTearOffObjectBase

|||
|-|-|
|[m_pOwner](#m_powner)|Um ponteiro para um `CComObject` derivado da classe de proprietário.|

## <a name="remarks"></a>Comentários

`CComTearOffObject` implementa uma interface destacáveis como um objeto separado que é instanciado apenas quando essa interface é consultada para. O destacável é excluído quando sua contagem de referência se torna zero. Normalmente, você pode criar uma interface destacáveis para uma interface que raramente é usada, já que usar um destacáveis salva um ponteiro vtable em todas as instâncias do seu objeto principal.

Você deve derivar a classe que implementa o destacáveis de `CComTearOffObjectBase` e de quaisquer interfaces que você deseja que o seu objeto destacáveis para dar suporte. `CComTearOffObjectBase` é modelada na classe proprietária e o modelo de thread. A classe de proprietário é a classe do objeto para o qual um destacável está sendo implementado. Se você não especificar um modelo de thread, o modelo de thread padrão será usado.

Você deve criar um mapa de COM para a sua classe destacáveis. Quando ATL instancia o destacáveis, ele criará `CComTearOffObject<CYourTearOffClass>` ou `CComCachedTearOffObject<CYourTearOffClass>`.

Por exemplo, no exemplo de PAGER, a `CBeeper2` é a classe destacáveis e o `CBeeper` é a classe de proprietário:

[!code-cpp[NVC_ATL_COM#43](../../atl/codesnippet/cpp/ccomtearoffobject-class_1.h)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Base`

`CComTearOffObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="addref"></a>  CComTearOffObject::AddRef

Incrementa a contagem de referência do `CComTearOffObject` objeto por um.

```
STDMETHOD_(ULONG, AddRef)();
```

### <a name="return-value"></a>Valor de retorno

Um valor que pode ser úteis para diagnóstico e teste.

##  <a name="ccomtearoffobject"></a>  CComTearOffObject::CComTearOffObject

O construtor.

```
CComTearOffObject(void* pv);
```

### <a name="parameters"></a>Parâmetros

*VP*<br/>
[in] Ponteiro será convertido em um ponteiro para um `CComObject<Owner>` objeto.

### <a name="remarks"></a>Comentários

Incrementa a contagem de referência do proprietário em um.

##  <a name="dtor"></a>  CComTearOffObject:: ~ CComTearOffObject

O destruidor.

```
~CComTearOffObject();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados, as chamadas FinalRelease e diminui o módulo de contagem de bloqueio.

##  <a name="ccomtearoffobjectbase"></a>  CComTearOffObject::CComTearOffObjectBase

O construtor.

```
CComTearOffObjectBase();
```

### <a name="remarks"></a>Comentários

Inicializa o [m_pOwner](#m_powner) membro como NULL.

##  <a name="m_powner"></a>  CComTearOffObject::m_pOwner

Um ponteiro para um [CComObject](../../atl/reference/ccomobject-class.md) objeto derivado *proprietário*.

```
CComObject<Owner>* m_pOwner;
```

### <a name="parameters"></a>Parâmetros

*Proprietário*<br/>
[in] A classe para o qual um destacável está sendo implementado.

### <a name="remarks"></a>Comentários

O ponteiro é inicializado como NULL durante a construção.

##  <a name="queryinterface"></a>  CComTearOffObject::QueryInterface

Recupera um ponteiro para a interface solicitada.

```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
```

### <a name="parameters"></a>Parâmetros

*IID*<br/>
[in] O IID da interface que está sendo solicitado.

*ppvObject*<br/>
[out] Um ponteiro para o ponteiro de interface identificado pelo *iid*, ou nulo se a interface não foi encontrada.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Consultas primeiro para interfaces em sua classe destacáveis. Se a interface não estiver lá, consultas para a interface no objeto do proprietário. Se for a interface solicitada `IUnknown`, retorna o `IUnknown` do proprietário.

##  <a name="release"></a>  CComTearOffObject::Release

Diminui a contagem de referência por um e, se a contagem de referência for zero, exclui o `CComTearOffObject`.

```
STDMETHOD_ULONG Release();
```

### <a name="return-value"></a>Valor de retorno

Em compilações sem depuração, sempre retornará zero. Em compilações de depuração, retorna um valor que pode ser úteis para diagnóstico ou teste.

## <a name="see-also"></a>Consulte também

[Classe CComCachedTearOffObject](../../atl/reference/ccomcachedtearoffobject-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
