---
title: Classe IPersistStorageImpl
ms.date: 11/04/2016
f1_keywords:
- IPersistStorageImpl
- ATLCOM/ATL::IPersistStorageImpl
- ATLCOM/ATL::IPersistStorageImpl::GetClassID
- ATLCOM/ATL::IPersistStorageImpl::HandsOffStorage
- ATLCOM/ATL::IPersistStorageImpl::InitNew
- ATLCOM/ATL::IPersistStorageImpl::IsDirty
- ATLCOM/ATL::IPersistStorageImpl::Load
- ATLCOM/ATL::IPersistStorageImpl::Save
- ATLCOM/ATL::IPersistStorageImpl::SaveCompleted
helpviewer_keywords:
- storage, ATL
- IPersistStorageImpl class
ms.assetid: d652f02c-239c-47c7-9a50-3e9fc3014fff
ms.openlocfilehash: a5b5dd4e5be43d01f00687ed9b96a3f27abcad0f
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69495699"
---
# <a name="ipersiststorageimpl-class"></a>Classe IPersistStorageImpl

Essa classe implementa a interface [IPersistStorage](/windows/win32/api/objidl/nn-objidl-ipersiststorage) .

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template <class T>
class ATL_NO_VTABLE IPersistStorageImpl : public IPersistStorage
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IPersistStorageImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IPersistStorageImpl::GetClassID](#getclassid)|Recupera o CLSID do objeto.|
|[IPersistStorageImpl::HandsOffStorage](#handsoffstorage)|Instrui o objeto a liberar todos os objetos de armazenamento e a entrar no modo HandsOff. A implementação da ATL retorna S_OK.|
|[IPersistStorageImpl::InitNew](#initnew)|Inicializa um novo armazenamento.|
|[IPersistStorageImpl::IsDirty](#isdirty)|Verifica se os dados do objeto foram alterados desde que foram salvos pela última vez.|
|[IPersistStorageImpl::Load](#load)|Carrega as propriedades do objeto do armazenamento especificado.|
|[IPersistStorageImpl::Save](#save)|Salva as propriedades do objeto no armazenamento especificado.|
|[IPersistStorageImpl::SaveCompleted](#savecompleted)|Notifica um objeto que ele pode retornar ao modo normal para gravar em seu objeto de armazenamento. A implementação da ATL retorna S_OK.|

## <a name="remarks"></a>Comentários

`IPersistStorageImpl`implementa a interface [IPersistStorage](/windows/win32/api/objidl/nn-objidl-ipersiststorage) , que permite que um cliente solicite que o objeto seja carregado e salve seus dados persistentes usando um armazenamento.

A implementação dessa classe requer que a `T` classe faça uma implementação `IPersistStreamInit` da interface disponível por meio `QueryInterface`do. Normalmente, isso significa que `T` a classe deve derivar de [IPersistStreamInitImpl](../../atl/reference/ipersiststreaminitimpl-class.md), fornecer `IPersistStreamInit` uma entrada para no [mapa com](com-map-macros.md)e usar um [mapa de propriedade](property-map-macros.md) para descrever os dados persistentes da classe.

**Artigos relacionados** [Tutorial do ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IPersistStorage`

`IPersistStorageImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="getclassid"></a>  IPersistStorageImpl::GetClassID

Recupera o CLSID do objeto.

```
STDMETHOD(GetClassID)(CLSID* pClassID);
```

### <a name="remarks"></a>Comentários

Consulte [IPersist:: GetClassID](/windows/win32/api/objidl/nf-objidl-ipersist-getclassid) na SDK do Windows.

##  <a name="handsoffstorage"></a>  IPersistStorageImpl::HandsOffStorage

Instrui o objeto a liberar todos os objetos de armazenamento e a entrar no modo HandsOff.

```
STDMETHOD(HandsOffStorage)(void);
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IPersistStorage:: HandsOffStorage](/windows/win32/api/objidl/nf-objidl-ipersiststorage-handsoffstorage) na SDK do Windows.

##  <a name="initnew"></a>  IPersistStorageImpl::InitNew

Inicializa um novo armazenamento.

```
STDMETHOD(InitNew)(IStorage*);
```

### <a name="remarks"></a>Comentários

A implementação da ATL delega para a interface [IPersistStreamInit](/windows/win32/api/ocidl/nn-ocidl-ipersiststreaminit) .

Consulte [IPersistStorage: InitNew](/windows/win32/api/objidl/nf-objidl-ipersiststorage-initnew) no SDK do Windows.

##  <a name="isdirty"></a>  IPersistStorageImpl::IsDirty

Verifica se os dados do objeto foram alterados desde que foram salvos pela última vez.

```
STDMETHOD(IsDirty)(void);
```

### <a name="remarks"></a>Comentários

A implementação da ATL delega para a interface [IPersistStreamInit](/windows/win32/api/ocidl/nn-ocidl-ipersiststreaminit) .

Consulte [IPersistStorage: IsDirty](/windows/win32/api/objidl/nf-objidl-ipersiststorage-isdirty) no SDK do Windows.

##  <a name="load"></a>  IPersistStorageImpl::Load

Carrega as propriedades do objeto do armazenamento especificado.

```
STDMETHOD(Load)(IStorage* pStorage);
```

### <a name="remarks"></a>Comentários

A implementação da ATL delega para a interface [IPersistStreamInit](/windows/win32/api/ocidl/nn-ocidl-ipersiststreaminit) . `Load`usa um fluxo chamado "conteúdo" para recuperar os dados do objeto. O método [Save](#save) originalmente cria esse fluxo.

Consulte [IPersistStorage: carregar](/windows/win32/api/objidl/nf-objidl-ipersiststorage-load) no SDK do Windows.

##  <a name="save"></a>  IPersistStorageImpl::Save

Salva as propriedades do objeto no armazenamento especificado.

```
STDMETHOD(Save)(IStorage* pStorage, BOOL fSameAsLoad);
```

### <a name="remarks"></a>Comentários

A implementação da ATL delega para a interface [IPersistStreamInit](/windows/win32/api/ocidl/nn-ocidl-ipersiststreaminit) . Quando `Save` é chamado pela primeira vez, ele cria um fluxo chamado "conteúdo" no armazenamento especificado. Esse fluxo é usado em chamadas posteriores para `Save` e em chamadas para [carregar](#load).

Consulte [IPersistStorage: Save](/windows/win32/api/objidl/nf-objidl-ipersiststorage-save) no SDK do Windows.

##  <a name="savecompleted"></a>  IPersistStorageImpl::SaveCompleted

Notifica um objeto que ele pode retornar ao modo normal para gravar em seu objeto de armazenamento.

```
STDMETHOD(SaveCompleted)(IStorage*);
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IPersistStorage: SaveCompleted](/windows/win32/api/objidl/nf-objidl-ipersiststorage-savecompleted) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Armazenamentos e fluxos](/windows/win32/Stg/storages-and-streams)<br/>
[Classe IPersistStreamInitImpl](../../atl/reference/ipersiststreaminitimpl-class.md)<br/>
[Classe IPersistPropertyBagImpl](../../atl/reference/ipersistpropertybagimpl-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
