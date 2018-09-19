---
title: Classe IPersistStorageImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- storage, ATL
- IPersistStorageImpl class
ms.assetid: d652f02c-239c-47c7-9a50-3e9fc3014fff
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1479ced25a741e27a195b529b6bf8825b47ce41e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46099597"
---
# <a name="ipersiststorageimpl-class"></a>Classe IPersistStorageImpl

Essa classe implementa a [IPersistStorage](/windows/desktop/api/objidl/nn-objidl-ipersiststorage) interface.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

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
|[IPersistStorageImpl::HandsOffStorage](#handsoffstorage)|Instrui o objeto para liberar todos os objetos de armazenamento e entrar no modo de HandsOff. A implementação de ATL Retorna S_OK.|
|[IPersistStorageImpl::InitNew](#initnew)|Inicializa um novo armazenamento.|
|[IPersistStorageImpl::IsDirty](#isdirty)|Verifica se os dados do objeto foi alterado desde que foi salvo pela última vez.|
|[IPersistStorageImpl::Load](#load)|Carrega as propriedades do objeto de armazenamento especificado.|
|[IPersistStorageImpl::Save](#save)|Salva as propriedades do objeto para o armazenamento especificado.|
|[IPersistStorageImpl::SaveCompleted](#savecompleted)|Notifica um objeto que ele pode retornar ao modo Normal para gravar em seu objeto de armazenamento. A implementação de ATL Retorna S_OK.|

## <a name="remarks"></a>Comentários

`IPersistStorageImpl` implementa o [IPersistStorage](/windows/desktop/api/objidl/nn-objidl-ipersiststorage) de interface, que permite que um cliente para solicitar que o carregamento do objeto e salve seus dados persistentes usando um armazenamento.

A implementação dessa classe requer a classe `T` para tornar uma implementação do `IPersistStreamInit` disponíveis por meio da interface `QueryInterface`. Normalmente, isso significa que a classe `T` deve derivar de [IPersistStreamInitImpl](../../atl/reference/ipersiststreaminitimpl-class.md), forneça uma entrada para `IPersistStreamInit` no [mapa COM](com-map-macros.md)e usar um [mapa de propriedade](property-map-macros.md) a descrição de dados persistentes da classe.

**Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IPersistStorage`

`IPersistStorageImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="getclassid"></a>  IPersistStorageImpl::GetClassID

Recupera o CLSID do objeto.

```
STDMETHOD(GetClassID)(CLSID* pClassID);
```

### <a name="remarks"></a>Comentários

Ver [IPersist::GetClassID](/windows/desktop/api/objidl/nf-objidl-ipersist-getclassid) no Windows SDK.

##  <a name="handsoffstorage"></a>  IPersistStorageImpl::HandsOffStorage

Instrui o objeto para liberar todos os objetos de armazenamento e entrar no modo de HandsOff.

```
STDMETHOD(HandsOffStorage)(void);
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Ver [IPersistStorage::HandsOffStorage](/windows/desktop/api/objidl/nf-objidl-ipersiststorage-handsoffstorage) no Windows SDK.

##  <a name="initnew"></a>  IPersistStorageImpl::InitNew

Inicializa um novo armazenamento.

```
STDMETHOD(InitNew)(IStorage*);
```

### <a name="remarks"></a>Comentários

A implementação de ATL delega para o [IPersistStreamInit](/windows/desktop/api/ocidl/nn-ocidl-ipersiststreaminit) interface.

Ver [IPersistStorage:InitNew](/windows/desktop/api/objidl/nf-objidl-ipersiststorage-initnew) no Windows SDK.

##  <a name="isdirty"></a>  IPersistStorageImpl::IsDirty

Verifica se os dados do objeto foi alterado desde que foi salvo pela última vez.

```
STDMETHOD(IsDirty)(void);
```

### <a name="remarks"></a>Comentários

A implementação de ATL delega para o [IPersistStreamInit](/windows/desktop/api/ocidl/nn-ocidl-ipersiststreaminit) interface.

Ver [IPersistStorage:IsDirty](/windows/desktop/api/objidl/nf-objidl-ipersiststorage-isdirty) no Windows SDK.

##  <a name="load"></a>  IPersistStorageImpl::Load

Carrega as propriedades do objeto de armazenamento especificado.

```
STDMETHOD(Load)(IStorage* pStorage);
```

### <a name="remarks"></a>Comentários

A implementação de ATL delega para o [IPersistStreamInit](/windows/desktop/api/ocidl/nn-ocidl-ipersiststreaminit) interface. `Load` usa um fluxo chamado "Conteúdo" para recuperar os dados do objeto. O [salvar](#save) método originalmente cria esse fluxo.

Ver [IPersistStorage:Load](/windows/desktop/api/objidl/nf-objidl-ipersiststorage-load) no Windows SDK.

##  <a name="save"></a>  IPersistStorageImpl::Save

Salva as propriedades do objeto para o armazenamento especificado.

```
STDMETHOD(Save)(IStorage* pStorage, BOOL fSameAsLoad);
```

### <a name="remarks"></a>Comentários

A implementação de ATL delega para o [IPersistStreamInit](/windows/desktop/api/ocidl/nn-ocidl-ipersiststreaminit) interface. Quando `Save` é a primeira chamada, ele cria um fluxo nomeado "Conteúdo" em armazenamento especificado. Esse fluxo, em seguida, é usado em chamadas posteriores para `Save` e em chamadas para [carga](#load).

Ver [IPersistStorage:Save](/windows/desktop/api/objidl/nf-objidl-ipersiststorage-save) no Windows SDK.

##  <a name="savecompleted"></a>  IPersistStorageImpl::SaveCompleted

Notifica um objeto que ele pode retornar ao modo Normal para gravar em seu objeto de armazenamento.

```
STDMETHOD(SaveCompleted)(IStorage*);
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Ver [IPersistStorage:SaveCompleted](/windows/desktop/api/objidl/nf-objidl-ipersiststorage-savecompleted) no Windows SDK.

## <a name="see-also"></a>Consulte também

[Fluxos e armazenamentos](/windows/desktop/Stg/storages-and-streams)<br/>
[Classe IPersistStreamInitImpl](../../atl/reference/ipersiststreaminitimpl-class.md)<br/>
[Classe IPersistPropertyBagImpl](../../atl/reference/ipersistpropertybagimpl-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
