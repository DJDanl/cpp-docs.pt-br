---
title: Classe IPersistStreamInitImpl
ms.date: 11/04/2016
f1_keywords:
- IPersistStreamInitImpl
- ATLCOM/ATL::IPersistStreamInitImpl
- ATLCOM/ATL::IPersistStreamInitImpl::GetClassID
- ATLCOM/ATL::IPersistStreamInitImpl::GetSizeMax
- ATLCOM/ATL::IPersistStreamInitImpl::InitNew
- ATLCOM/ATL::IPersistStreamInitImpl::IsDirty
- ATLCOM/ATL::IPersistStreamInitImpl::Load
- ATLCOM/ATL::IPersistStreamInitImpl::Save
helpviewer_keywords:
- IPersistStreamInit ATL implementation
- IPersistStreamInitImpl class
- streams, ATL
ms.assetid: ef217c3c-020f-4cf8-871e-ef68e57865b8
ms.openlocfilehash: 0d6ac4639ac0cfb97416ca80b7a2ec3903d7b8e6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326456"
---
# <a name="ipersiststreaminitimpl-class"></a>Classe IPersistStreamInitImpl

Essa classe `IUnknown` implementa e fornece uma implementação padrão da interface [IPersistStreamInit.](/windows/win32/api/ocidl/nn-ocidl-ipersiststreaminit)

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class ATL_NO_VTABLE IPersistStreamInitImpl
   : public IPersistStreamInit
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IPersistStreamInitImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[iPersiststreamInitImpl::GetClassID](#getclassid)|Recupera o CLSID do objeto.|
|[iPersiststreamInitImpl::GetSizeMax](#getsizemax)|Recupera o tamanho do fluxo necessário para salvar os dados do objeto. A implementação da ATL retorna E_NOTIMPL.|
|[iPersiststreamInitImpl::InitNew](#initnew)|Inicializa um objeto recém-criado.|
|[iPersiststreamInitImpl::IsDirty](#isdirty)|Verifica se os dados do objeto mudaram desde que foi salvo pela última vez.|
|[iPersiststreamInitImpl::Load](#load)|Carrega as propriedades do objeto a partir do fluxo especificado.|
|[iPersiststreamInitImpl::Save](#save)|Salva as propriedades do objeto no fluxo especificado.|

## <a name="remarks"></a>Comentários

A interface [IPersistStreamInit](/windows/win32/api/ocidl/nn-ocidl-ipersiststreaminit) permite que um cliente solicite que seu objeto seja carregado e salve seus dados persistentes em um único fluxo. A `IPersistStreamInitImpl` classe fornece uma implementação `IUnknown` padrão dessa interface e implementa enviando informações para o dispositivo de despejo em compilações de depuração.

**Artigos relacionados** [ATL Tutorial](../../atl/active-template-library-atl-tutorial.md), Criando um Projeto [ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IPersistStreamInit`

`IPersistStreamInitImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="ipersiststreaminitimplgetclassid"></a><a name="getclassid"></a>iPersiststreamInitImpl::GetClassID

Recupera o CLSID do objeto.

```
STDMETHOD(GetClassID)(CLSID* pClassID);
```

### <a name="remarks"></a>Comentários

Consulte [IPersist::GetClassID](/windows/win32/api/objidl/nf-objidl-ipersist-getclassid) no Windows SDK.

## <a name="ipersiststreaminitimplgetsizemax"></a><a name="getsizemax"></a>iPersiststreamInitImpl::GetSizeMax

Recupera o tamanho do fluxo necessário para salvar os dados do objeto.

```
STDMETHOD(GetSizeMax)(ULARGE_INTEGER FAR* pcbSize);
```

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [iPersistStreamInit::GetSizeMax](/windows/win32/api/ocidl/nf-ocidl-ipersiststreaminit-getsizemax) no Windows SDK.

## <a name="ipersiststreaminitimplinitnew"></a><a name="initnew"></a>iPersiststreamInitImpl::InitNew

Inicializa um objeto recém-criado.

```
STDMETHOD(InitNew)();
```

### <a name="remarks"></a>Comentários

Consulte [iPersistStreamInit::InitNew](/windows/win32/api/ocidl/nf-ocidl-ipersiststreaminit-initnew) no Windows SDK.

## <a name="ipersiststreaminitimplisdirty"></a><a name="isdirty"></a>iPersiststreamInitImpl::IsDirty

Verifica se os dados do objeto mudaram desde que foi salvo pela última vez.

```
STDMETHOD(IsDirty)();
```

### <a name="remarks"></a>Comentários

Consulte [iPersistStreamInit::IsDirty](/windows/win32/api/ocidl/nf-ocidl-ipersiststreaminit-isdirty) no Windows SDK.

## <a name="ipersiststreaminitimplload"></a><a name="load"></a>iPersiststreamInitImpl::Load

Carrega as propriedades do objeto a partir do fluxo especificado.

```
STDMETHOD(Load)(LPSTREAM pStm);
```

### <a name="remarks"></a>Comentários

O ATL usa o mapa de propriedade do objeto para recuperar essas informações.

Consulte [iPersistStreamInit::Load](/windows/win32/api/ocidl/nf-ocidl-ipersiststreaminit-load) in the Windows SDK.

## <a name="ipersiststreaminitimplsave"></a><a name="save"></a>iPersiststreamInitImpl::Save

Salva as propriedades do objeto no fluxo especificado.

```
STDMETHOD(Save)(LPSTREAM pStm, BOOL fClearDirty);
```

### <a name="remarks"></a>Comentários

A ATL usa o mapa de propriedade do objeto para armazenar essas informações.

Consulte [iPersistStreamInit::Salvar](/windows/win32/api/ocidl/nf-ocidl-ipersiststreaminit-save) no SDK do Windows.

## <a name="see-also"></a>Confira também

[Armazenamentos e Fluxos](/windows/win32/Stg/storages-and-streams)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
