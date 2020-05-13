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
ms.openlocfilehash: b235b190f237293932705e4d290ac963088722f3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326476"
---
# <a name="ipersiststorageimpl-class"></a>Classe IPersistStorageImpl

Esta classe implementa a interface [IPersistStorage.](/windows/win32/api/objidl/nn-objidl-ipersiststorage)

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class T>
class ATL_NO_VTABLE IPersistStorageImpl : public IPersistStorage
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IPersistStorageImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IPersistStorageImpl::GetClassID](#getclassid)|Recupera o CLSID do objeto.|
|[IPersistStorageImpl::HandsOffStorage](#handsoffstorage)|Instrui o objeto a liberar todos os objetos de armazenamento e entrar no modo HandsOff. A implementação da ATL retorna S_OK.|
|[IPersistStorageImpl::InitNew](#initnew)|Inicializa um novo armazenamento.|
|[IPersistStorageImpl::IsDirty](#isdirty)|Verifica se os dados do objeto mudaram desde que foi salvo pela última vez.|
|[IPersistStorageImpl::Load](#load)|Carrega as propriedades do objeto a partir do armazenamento especificado.|
|[IPersistStorageImpl::Save](#save)|Salva as propriedades do objeto no armazenamento especificado.|
|[IPersistStorageImpl::SaveCompleted](#savecompleted)|Notifica um objeto de que ele pode retornar ao modo Normal para gravar em seu objeto de armazenamento. A implementação da ATL retorna S_OK.|

## <a name="remarks"></a>Comentários

`IPersistStorageImpl`implementa a interface [IPersistStorage,](/windows/win32/api/objidl/nn-objidl-ipersiststorage) que permite que um cliente solicite que seu objeto carregue e salve seus dados persistentes usando um armazenamento.

A implementação desta `T` classe requer classe `IPersistStreamInit` para disponibilizar `QueryInterface`uma implementação da interface via . Normalmente, isso `T` significa que a classe deve derivar do `IPersistStreamInit` [IPersistStreamInitImpl,](../../atl/reference/ipersiststreaminitimpl-class.md)fornecer uma entrada para o mapa [COM](com-map-macros.md)e usar um mapa de [propriedade](property-map-macros.md) para descrever os dados persistentes da classe.

**Artigos relacionados** [ATL Tutorial](../../atl/active-template-library-atl-tutorial.md), Criando um Projeto [ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IPersistStorage`

`IPersistStorageImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="ipersiststorageimplgetclassid"></a><a name="getclassid"></a>IPersistStorageImpl::GetClassID

Recupera o CLSID do objeto.

```
STDMETHOD(GetClassID)(CLSID* pClassID);
```

### <a name="remarks"></a>Comentários

Consulte [IPersist::GetClassID](/windows/win32/api/objidl/nf-objidl-ipersist-getclassid) no Windows SDK.

## <a name="ipersiststorageimplhandsoffstorage"></a><a name="handsoffstorage"></a>IPersistStorageImpl::HandsOffStorage

Instrui o objeto a liberar todos os objetos de armazenamento e entrar no modo HandsOff.

```
STDMETHOD(HandsOffStorage)(void);
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IPersistStorage::HandsOffStorage](/windows/win32/api/objidl/nf-objidl-ipersiststorage-handsoffstorage) no Windows SDK.

## <a name="ipersiststorageimplinitnew"></a><a name="initnew"></a>IPersistStorageImpl::InitNew

Inicializa um novo armazenamento.

```
STDMETHOD(InitNew)(IStorage*);
```

### <a name="remarks"></a>Comentários

A implementação ATL delega-se à interface [IPersistStreamInit.](/windows/win32/api/ocidl/nn-ocidl-ipersiststreaminit)

Consulte [IPersistStorage:InitNew](/windows/win32/api/objidl/nf-objidl-ipersiststorage-initnew) no SDK do Windows.

## <a name="ipersiststorageimplisdirty"></a><a name="isdirty"></a>IPersistStorageImpl::IsDirty

Verifica se os dados do objeto mudaram desde que foi salvo pela última vez.

```
STDMETHOD(IsDirty)(void);
```

### <a name="remarks"></a>Comentários

A implementação ATL delega-se à interface [IPersistStreamInit.](/windows/win32/api/ocidl/nn-ocidl-ipersiststreaminit)

Consulte [IPersistStorage:IsDirty](/windows/win32/api/objidl/nf-objidl-ipersiststorage-isdirty) no SDK do Windows.

## <a name="ipersiststorageimplload"></a><a name="load"></a>IPersistStorageImpl::Load

Carrega as propriedades do objeto a partir do armazenamento especificado.

```
STDMETHOD(Load)(IStorage* pStorage);
```

### <a name="remarks"></a>Comentários

A implementação ATL delega-se à interface [IPersistStreamInit.](/windows/win32/api/ocidl/nn-ocidl-ipersiststreaminit) `Load`usa um fluxo chamado "Conteúdo" para recuperar os dados do objeto. O método [Salvar](#save) cria originalmente esse fluxo.

Consulte [IPersistStorage:Load](/windows/win32/api/objidl/nf-objidl-ipersiststorage-load) in the Windows SDK.

## <a name="ipersiststorageimplsave"></a><a name="save"></a>IPersistStorageImpl::Save

Salva as propriedades do objeto no armazenamento especificado.

```
STDMETHOD(Save)(IStorage* pStorage, BOOL fSameAsLoad);
```

### <a name="remarks"></a>Comentários

A implementação ATL delega-se à interface [IPersistStreamInit.](/windows/win32/api/ocidl/nn-ocidl-ipersiststreaminit) Quando `Save` é chamado pela primeira vez, ele cria um fluxo chamado "Conteúdo" no armazenamento especificado. Este fluxo é então usado `Save` em chamadas posteriores para e em chamadas para [Carregar](#load).

Consulte [IPersistStorage:Salvar](/windows/win32/api/objidl/nf-objidl-ipersiststorage-save) no SDK do Windows.

## <a name="ipersiststorageimplsavecompleted"></a><a name="savecompleted"></a>IPersistStorageImpl::SaveCompleted

Notifica um objeto de que ele pode retornar ao modo Normal para gravar em seu objeto de armazenamento.

```
STDMETHOD(SaveCompleted)(IStorage*);
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IPersistStorage:SaveConcluído](/windows/win32/api/objidl/nf-objidl-ipersiststorage-savecompleted) no SDK do Windows.

## <a name="see-also"></a>Confira também

[Armazenamentos e Fluxos](/windows/win32/Stg/storages-and-streams)<br/>
[Classe IPersistStreamInitImpl](../../atl/reference/ipersiststreaminitimpl-class.md)<br/>
[Classe IPersistPropertyBagImpl](../../atl/reference/ipersistpropertybagimpl-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
