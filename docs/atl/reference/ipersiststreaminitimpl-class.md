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
ms.openlocfilehash: 7a350a4349cb825795a18dd860a2482952b04dcb
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69496148"
---
# <a name="ipersiststreaminitimpl-class"></a>Classe IPersistStreamInitImpl

Essa classe implementa `IUnknown` e fornece uma implementação padrão da interface [IPersistStreamInit](/windows/win32/api/ocidl/nn-ocidl-ipersiststreaminit) .

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

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

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IPersistStreamInitImpl::GetClassID](#getclassid)|Recupera o CLSID do objeto.|
|[IPersistStreamInitImpl::GetSizeMax](#getsizemax)|Recupera o tamanho do fluxo necessário para salvar os dados do objeto. A implementação da ATL retorna E_NOTIMPL.|
|[IPersistStreamInitImpl::InitNew](#initnew)|Inicializa um objeto recém-criado.|
|[IPersistStreamInitImpl::IsDirty](#isdirty)|Verifica se os dados do objeto foram alterados desde que foram salvos pela última vez.|
|[IPersistStreamInitImpl::Load](#load)|Carrega as propriedades do objeto a partir do fluxo especificado.|
|[IPersistStreamInitImpl::Save](#save)|Salva as propriedades do objeto no fluxo especificado.|

## <a name="remarks"></a>Comentários

A interface [IPersistStreamInit](/windows/win32/api/ocidl/nn-ocidl-ipersiststreaminit) permite que um cliente solicite que o objeto carregue e salve seus dados persistentes em um único fluxo. Fornece uma implementação padrão dessa interface e implementa `IUnknown` enviando informações para o dispositivo de despejo em compilações de depuração. `IPersistStreamInitImpl`

**Artigos relacionados** [Tutorial do ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IPersistStreamInit`

`IPersistStreamInitImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="getclassid"></a>  IPersistStreamInitImpl::GetClassID

Recupera o CLSID do objeto.

```
STDMETHOD(GetClassID)(CLSID* pClassID);
```

### <a name="remarks"></a>Comentários

Consulte [IPersist:: GetClassID](/windows/win32/api/objidl/nf-objidl-ipersist-getclassid) na SDK do Windows.

##  <a name="getsizemax"></a>  IPersistStreamInitImpl::GetSizeMax

Recupera o tamanho do fluxo necessário para salvar os dados do objeto.

```
STDMETHOD(GetSizeMax)(ULARGE_INTEGER FAR* pcbSize);
```

### <a name="return-value"></a>Valor de retorno

Retorna E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IPersistStreamInit:: GetSizeMax](/windows/win32/api/ocidl/nf-ocidl-ipersiststreaminit-getsizemax) na SDK do Windows.

##  <a name="initnew"></a>  IPersistStreamInitImpl::InitNew

Inicializa um objeto recém-criado.

```
STDMETHOD(InitNew)();
```

### <a name="remarks"></a>Comentários

Consulte [IPersistStreamInit:: InitNew](/windows/win32/api/ocidl/nf-ocidl-ipersiststreaminit-initnew) na SDK do Windows.

##  <a name="isdirty"></a>  IPersistStreamInitImpl::IsDirty

Verifica se os dados do objeto foram alterados desde que foram salvos pela última vez.

```
STDMETHOD(IsDirty)();
```

### <a name="remarks"></a>Comentários

Consulte [IPersistStreamInit:: IsDirty](/windows/win32/api/ocidl/nf-ocidl-ipersiststreaminit-isdirty) no SDK do Windows.

##  <a name="load"></a>  IPersistStreamInitImpl::Load

Carrega as propriedades do objeto a partir do fluxo especificado.

```
STDMETHOD(Load)(LPSTREAM pStm);
```

### <a name="remarks"></a>Comentários

A ATL usa o mapa de propriedades do objeto para recuperar essas informações.

Consulte [IPersistStreamInit:: Load](/windows/win32/api/ocidl/nf-ocidl-ipersiststreaminit-load) no SDK do Windows.

##  <a name="save"></a>  IPersistStreamInitImpl::Save

Salva as propriedades do objeto no fluxo especificado.

```
STDMETHOD(Save)(LPSTREAM pStm, BOOL fClearDirty);
```

### <a name="remarks"></a>Comentários

A ATL usa o mapa de propriedades do objeto para armazenar essas informações.

Consulte [IPersistStreamInit:: Save](/windows/win32/api/ocidl/nf-ocidl-ipersiststreaminit-save) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Armazenamentos e fluxos](/windows/win32/Stg/storages-and-streams)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
