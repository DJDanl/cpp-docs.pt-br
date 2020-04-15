---
title: Classe IDataObjectImpl
ms.date: 11/04/2016
f1_keywords:
- IDataObjectImpl
- ATLCTL/ATL::IDataObjectImpl
- ATLCTL/ATL::IDataObjectImpl::DAdvise
- ATLCTL/ATL::IDataObjectImpl::DUnadvise
- ATLCTL/ATL::IDataObjectImpl::EnumDAdvise
- ATLCTL/ATL::IDataObjectImpl::EnumFormatEtc
- ATLCTL/ATL::IDataObjectImpl::FireDataChange
- ATLCTL/ATL::IDataObjectImpl::GetCanonicalFormatEtc
- ATLCTL/ATL::IDataObjectImpl::GetData
- ATLCTL/ATL::IDataObjectImpl::GetDataHere
- ATLCTL/ATL::IDataObjectImpl::QueryGetData
- ATLCTL/ATL::IDataObjectImpl::SetData
helpviewer_keywords:
- data transfer [C++]
- data transfer [C++], Uniform Data Transfer
- IDataObjectImpl class
- IDataObject, ATL implementation
ms.assetid: b680f0f7-7795-40a1-a0f6-f48768201c89
ms.openlocfilehash: 618f8248a03297120ae2504bcb30ba8f080b184d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329833"
---
# <a name="idataobjectimpl-class"></a>Classe IDataObjectImpl

Esta classe fornece métodos para apoiar a transferência uniforme de dados e o gerenciamento de conexões.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class IDataObjectImpl
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IDataObjectImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IDataObjectImpl::DAconselhar](#dadvise)|Estabelece uma conexão entre o objeto de dados e um dissipador de aconselhamento. Isso permite que o dissipador de aconselhamento receba notificações de alterações no objeto.|
|[IDataObjectImpl::DUnadvise](#dunadvise)|Termina uma conexão previamente `DAdvise`estabelecida através de .|
|[IDataObjectImpl::EnumDAdvise](#enumdadvise)|Cria um enumerador para iterar através das conexões consultivas atuais.|
|[IDataObjectImpl::EnumFormatEtc](#enumformatetc)|Cria um enumerador para iterar através das `FORMATETC` estruturas suportadas pelo objeto de dados. A implementação da ATL retorna E_NOTIMPL.|
|[IDataObjectImpl::FireDataChange](#firedatachange)|Envia uma notificação de alteração de volta para cada pia de aconselhamento.|
|[IDataObjectImpl::GetCanonicalFormatEtc](#getcanonicalformatetc)|Recupera uma estrutura `FORMATETC` logicamente equivalente a uma que é mais complexa. A implementação da ATL retorna E_NOTIMPL.|
|[IDataObjectImpl::GetData](#getdata)|Transfere dados do objeto de dados para o cliente. Os dados são `FORMATETC` descritos em uma `STGMEDIUM` estrutura e são transferidos através de uma estrutura.|
|[IDataObjectImpl::GetDataHere](#getdatahere)|Semelhante `GetData`a , exceto `STGMEDIUM` que o cliente deve alocar a estrutura. A implementação da ATL retorna E_NOTIMPL.|
|[IDataObjectImpl::QueryGetData](#querygetdata)|Determina se o objeto de `FORMATETC` dados suporta uma estrutura específica para transferência de dados. A implementação da ATL retorna E_NOTIMPL.|
|[IDataObjectImpl::SetData](#setdata)|Transfere dados do cliente para o objeto de dados. A implementação da ATL retorna E_NOTIMPL.|

## <a name="remarks"></a>Comentários

A interface [IDataObject](/windows/win32/api/objidl/nn-objidl-idataobject) fornece métodos para suportar transferência uniforme de dados. `IDataObject`usa as estruturas de formato padrão [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) e [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) para recuperar e armazenar dados.

`IDataObject`também gerencia conexões para aconselhar sinks a lidar com notificações de alteração de dados. Para que o cliente receba notificações de alteração de dados do objeto de dados, o cliente deve implementar a interface [IAdviseSink](/windows/win32/api/objidl/nn-objidl-iadvisesink) em um objeto chamado dissipador de aconselhamento. Quando o cliente `IDataObject::DAdvise`então chama, uma conexão é estabelecida entre o objeto de dados e o dissipador de guia.

A `IDataObjectImpl` classe fornece `IDataObject` uma implementação padrão e implementa `IUnknown` enviando informações para o dispositivo de despejo em compilações de depuração.

**Artigos relacionados** [ATL Tutorial](../../atl/active-template-library-atl-tutorial.md), Criando um Projeto [ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IDataObject`

`IDataObjectImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

## <a name="idataobjectimpldadvise"></a><a name="dadvise"></a>IDataObjectImpl::DAconselhar

Estabelece uma conexão entre o objeto de dados e um dissipador de aconselhamento.

```
HRESULT DAdvise(
    FORMATETC* pformatetc,
    DWORD advf,
    IAdviseSink* pAdvSink,
    DWORD* pdwConnection);
```

### <a name="remarks"></a>Comentários

Isso permite que o dissipador de aconselhamento receba notificações de alterações no objeto.

Para encerrar a conexão, ligue para [o DUnadvise](#dunadvise).

Consulte [IDataObject::DAconselhar](/windows/win32/api/objidl/nf-objidl-idataobject-dadvise) no SDK do Windows.

## <a name="idataobjectimpldunadvise"></a><a name="dunadvise"></a>IDataObjectImpl::DUnadvise

Encerra uma conexão previamente estabelecida através [do DAdvise](#dadvise).

```
HRESULT DUnadvise(DWORD dwConnection);
```

### <a name="remarks"></a>Comentários

Consulte [IDataObject::DUnadvise](/windows/win32/api/objidl/nf-objidl-idataobject-dunadvise) no SDK do Windows.

## <a name="idataobjectimplenumdadvise"></a><a name="enumdadvise"></a>IDataObjectImpl::EnumDAdvise

Cria um enumerador para iterar através das conexões consultivas atuais.

```
HRESULT DAdvise(
    FORMATETC* pformatetc,
    DWORD advf,
    IAdviseSink* pAdvSink,
    DWORD* pdwConnection);
```

### <a name="remarks"></a>Comentários

Consulte [IDataObject::EnumDAdvise](/windows/win32/api/objidl/nf-objidl-idataobject-enumdadvise) no Windows SDK.

## <a name="idataobjectimplenumformatetc"></a><a name="enumformatetc"></a>IDataObjectImpl::EnumFormatEtc

Cria um enumerador para iterar através das `FORMATETC` estruturas suportadas pelo objeto de dados.

```
HRESULT EnumFormatEtc(
    DWORD dwDirection,
    IEnumFORMATETC** ppenumFormatEtc);
```

### <a name="remarks"></a>Comentários

Consulte [IDataObject::EnumFormatEtc](/windows/win32/api/objidl/nf-objidl-idataobject-enumformatetc) no Windows SDK.

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

## <a name="idataobjectimplfiredatachange"></a><a name="firedatachange"></a>IDataObjectImpl::FireDataChange

Envia uma notificação de alteração de volta para cada pia de aviso que está sendo gerenciada no momento.

```
HRESULT FireDataChange();
```

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="idataobjectimplgetcanonicalformatetc"></a><a name="getcanonicalformatetc"></a>IDataObjectImpl::GetCanonicalFormatEtc

Recupera uma estrutura `FORMATETC` logicamente equivalente a uma que é mais complexa.

```
HRESULT GetCanonicalFormatEtc(FORMATETC* pformatetcIn, FORMATETC* pformatetcOut);
```

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IDataObject::GetCanonicalFormatEtc](/windows/win32/api/objidl/nf-objidl-idataobject-getcanonicalformatetc) no Windows SDK.

## <a name="idataobjectimplgetdata"></a><a name="getdata"></a>IDataObjectImpl::GetData

Transfere dados do objeto de dados para o cliente.

```
HRESULT GetData(
    FORMATETC* pformatetcIn,
    STGMEDIUM* pmedium);
```

### <a name="remarks"></a>Comentários

O parâmetro *pformatetcIn* deve especificar um tipo médio de armazenamento de TYMED_MFPICT.

Consulte [IDataObject::GetData](/windows/win32/api/objidl/nf-objidl-idataobject-getdata) no Windows SDK.

## <a name="idataobjectimplgetdatahere"></a><a name="getdatahere"></a>IDataObjectImpl::GetDataHere

Semelhante `GetData`a , exceto `STGMEDIUM` que o cliente deve alocar a estrutura.

```
HRESULT GetDataHere(
    FORMATETC* pformatetc,
    STGMEDIUM* pmedium);
```

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IDataObject::GetDataHere](/windows/win32/api/objidl/nf-objidl-idataobject-getdatahere) no Windows SDK.

## <a name="idataobjectimplquerygetdata"></a><a name="querygetdata"></a>IDataObjectImpl::QueryGetData

Determina se o objeto de `FORMATETC` dados suporta uma estrutura específica para transferência de dados.

```
HRESULT QueryGetData(FORMATETC* pformatetc);
```

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IDataObject::QueryGetData](/windows/win32/api/objidl/nf-objidl-idataobject-querygetdata) no Windows SDK.

## <a name="idataobjectimplsetdata"></a><a name="setdata"></a>IDataObjectImpl::SetData

Transfere dados do cliente para o objeto de dados.

```
HRESULT SetData(
    FORMATETC* pformatetc,
    STGMEDIUM* pmedium,
    BOOL fRelease);
```

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IDataObject::SetData](/windows/win32/api/objidl/nf-objidl-idataobject-setdata) no Windows SDK.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
