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
ms.openlocfilehash: 472b01e169788ce3cf10f8ed9f2198c44cdeb88a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50645660"
---
# <a name="ipersiststreaminitimpl-class"></a>Classe IPersistStreamInitImpl

Essa classe implementa `IUnknown` e fornece uma implementação padrão do [IPersistStreamInit](/windows/desktop/api/ocidl/nn-ocidl-ipersiststreaminit) interface.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

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
|[IPersistStreamInitImpl::GetSizeMax](#getsizemax)|Recupera o tamanho do fluxo necessário para salvar os dados do objeto. A implementação de ATL retornará E_NOTIMPL.|
|[IPersistStreamInitImpl::InitNew](#initnew)|Inicializa um objeto recém-criado.|
|[IPersistStreamInitImpl::IsDirty](#isdirty)|Verifica se os dados do objeto foi alterado desde que foi salvo pela última vez.|
|[IPersistStreamInitImpl::Load](#load)|Carrega as propriedades do objeto do fluxo especificado.|
|[IPersistStreamInitImpl::Save](#save)|Salva as propriedades do objeto no fluxo especificado.|

## <a name="remarks"></a>Comentários

O [IPersistStreamInit](/windows/desktop/api/ocidl/nn-ocidl-ipersiststreaminit) interface permite que um cliente solicite que seu objeto carrega e salva os seus dados persistentes em um único fluxo. Classe `IPersistStreamInitImpl` fornece uma implementação padrão dessa interface e implementa `IUnknown` enviando informações para o despejo de compilações de dispositivo na depuração.

**Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IPersistStreamInit`

`IPersistStreamInitImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="getclassid"></a>  IPersistStreamInitImpl::GetClassID

Recupera o CLSID do objeto.

```
STDMETHOD(GetClassID)(CLSID* pClassID);
```

### <a name="remarks"></a>Comentários

Ver [IPersist::GetClassID](/windows/desktop/api/objidl/nf-objidl-ipersist-getclassid) no Windows SDK.

##  <a name="getsizemax"></a>  IPersistStreamInitImpl::GetSizeMax

Recupera o tamanho do fluxo necessário para salvar os dados do objeto.

```
STDMETHOD(GetSizeMax)(ULARGE_INTEGER FAR* pcbSize);
```

### <a name="return-value"></a>Valor de retorno

Retornará E_NOTIMPL.

### <a name="remarks"></a>Comentários

Ver [IPersistStreamInit::GetSizeMax](/windows/desktop/api/ocidl/nf-ocidl-ipersiststreaminit-getsizemax) no Windows SDK.

##  <a name="initnew"></a>  IPersistStreamInitImpl::InitNew

Inicializa um objeto recém-criado.

```
STDMETHOD(InitNew)();
```

### <a name="remarks"></a>Comentários

Ver [IPersistStreamInit::InitNew](/windows/desktop/api/ocidl/nf-ocidl-ipersiststreaminit-initnew) no Windows SDK.

##  <a name="isdirty"></a>  IPersistStreamInitImpl::IsDirty

Verifica se os dados do objeto foi alterado desde que foi salvo pela última vez.

```
STDMETHOD(IsDirty)();
```

### <a name="remarks"></a>Comentários

Ver [IPersistStreamInit::IsDirty](/windows/desktop/api/ocidl/nf-ocidl-ipersiststreaminit-isdirty) no Windows SDK.

##  <a name="load"></a>  IPersistStreamInitImpl::Load

Carrega as propriedades do objeto do fluxo especificado.

```
STDMETHOD(Load)(LPSTREAM pStm);
```

### <a name="remarks"></a>Comentários

ATL usa o mapa de propriedade do objeto para recuperar essas informações.

Ver [IPersistStreamInit::Load](/windows/desktop/api/ocidl/nf-ocidl-ipersiststreaminit-load) no Windows SDK.

##  <a name="save"></a>  IPersistStreamInitImpl::Save

Salva as propriedades do objeto no fluxo especificado.

```
STDMETHOD(Save)(LPSTREAM pStm, BOOL fClearDirty);
```

### <a name="remarks"></a>Comentários

ATL usa o mapa de propriedade do objeto para armazenar essas informações.

Ver [IPersistStreamInit::Save](/windows/desktop/api/ocidl/nf-ocidl-ipersiststreaminit-save) no Windows SDK.

## <a name="see-also"></a>Consulte também

[Fluxos e armazenamentos](/windows/desktop/Stg/storages-and-streams)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
