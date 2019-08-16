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
ms.openlocfilehash: 8e3369edd0731ede0892a405ef3de4e7b4cfdef1
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69495937"
---
# <a name="idataobjectimpl-class"></a>Classe IDataObjectImpl

Essa classe fornece métodos para dar suporte a Transferência de Dados uniformes e gerenciar conexões.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class IDataObjectImpl
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IDataObjectImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IDataObjectImpl::DAdvise](#dadvise)|Estabelece uma conexão entre o objeto de dados e um coletor de aviso. Isso permite que o coletor de aviso receba notificações de alterações no objeto.|
|[IDataObjectImpl::DUnadvise](#dunadvise)|Encerra uma conexão estabelecida anteriormente por meio `DAdvise`do.|
|[IDataObjectImpl::EnumDAdvise](#enumdadvise)|Cria um enumerador para iterar pelas conexões de consultoria atuais.|
|[IDataObjectImpl::EnumFormatEtc](#enumformatetc)|Cria um enumerador para iterar `FORMATETC` pelas estruturas com suporte do objeto de dados. A implementação da ATL retorna E_NOTIMPL.|
|[IDataObjectImpl::FireDataChange](#firedatachange)|Envia uma notificação de alteração de volta para cada coletor de aviso.|
|[IDataObjectImpl::GetCanonicalFormatEtc](#getcanonicalformatetc)|Recupera uma estrutura equivalente `FORMATETC` logicamente para uma que seja mais complexa. A implementação da ATL retorna E_NOTIMPL.|
|[IDataObjectImpl::GetData](#getdata)|Transfere dados do objeto de dados para o cliente. Os dados são descritos em uma `FORMATETC` estrutura e são transferidos por meio `STGMEDIUM` de uma estrutura.|
|[IDataObjectImpl::GetDataHere](#getdatahere)|Semelhante a `GetData`, exceto que o cliente deve alocar a `STGMEDIUM` estrutura. A implementação da ATL retorna E_NOTIMPL.|
|[IDataObjectImpl::QueryGetData](#querygetdata)|Determina se o objeto de dados dá suporte `FORMATETC` a uma estrutura específica para transferir dados. A implementação da ATL retorna E_NOTIMPL.|
|[IDataObjectImpl::SetData](#setdata)|Transfere dados do cliente para o objeto de dados. A implementação da ATL retorna E_NOTIMPL.|

## <a name="remarks"></a>Comentários

A interface [IDataObject](/windows/win32/api/objidl/nn-objidl-idataobject) fornece métodos para dar suporte a transferência de dados uniformes. `IDataObject`usa as estruturas de formato padrão [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) e [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-stgmedium) para recuperar e armazenar dados.

`IDataObject`também gerencia conexões para avisar coletores para lidar com notificações de alteração de dados. Para que o cliente receba notificações de alteração de dados do objeto de dados, o cliente deve implementar a interface [IAdviseSink](/windows/win32/api/objidl/nn-objidl-iadvisesink) em um objeto chamado coletor de aviso. Quando o cliente chama `IDataObject::DAdvise`, uma conexão é estabelecida entre o objeto de dados e o coletor de aviso.

Fornece uma implementação padrão de `IDataObject` e implementa `IUnknown` enviando informações para o dispositivo de despejo em compilações de depuração. `IDataObjectImpl`

**Artigos relacionados** [Tutorial do ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IDataObject`

`IDataObjectImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl. h

##  <a name="dadvise"></a>  IDataObjectImpl::DAdvise

Estabelece uma conexão entre o objeto de dados e um coletor de aviso.

```
HRESULT DAdvise(
    FORMATETC* pformatetc,
    DWORD advf,
    IAdviseSink* pAdvSink,
    DWORD* pdwConnection);
```

### <a name="remarks"></a>Comentários

Isso permite que o coletor de aviso receba notificações de alterações no objeto.

Para encerrar a conexão, chame [DUnadvise](#dunadvise).

Consulte [IDataObject::D avisar](/windows/win32/api/objidl/nf-objidl-idataobject-dadvise) na SDK do Windows.

##  <a name="dunadvise"></a>  IDataObjectImpl::DUnadvise

Encerra uma conexão estabelecida anteriormente por meio de [DAdvise](#dadvise).

```
HRESULT DUnadvise(DWORD dwConnection);
```

### <a name="remarks"></a>Comentários

Consulte [IDataObject::D Unadvise](/windows/win32/api/objidl/nf-objidl-idataobject-dunadvise) na SDK do Windows.

##  <a name="enumdadvise"></a>  IDataObjectImpl::EnumDAdvise

Cria um enumerador para iterar pelas conexões de consultoria atuais.

```
HRESULT DAdvise(
    FORMATETC* pformatetc,
    DWORD advf,
    IAdviseSink* pAdvSink,
    DWORD* pdwConnection);
```

### <a name="remarks"></a>Comentários

Consulte [IDataObject:: EnumDAdvise](/windows/win32/api/objidl/nf-objidl-idataobject-enumdadvise) no SDK do Windows.

##  <a name="enumformatetc"></a>  IDataObjectImpl::EnumFormatEtc

Cria um enumerador para iterar `FORMATETC` pelas estruturas com suporte do objeto de dados.

```
HRESULT EnumFormatEtc(
    DWORD dwDirection,
    IEnumFORMATETC** ppenumFormatEtc);
```

### <a name="remarks"></a>Comentários

Consulte [IDataObject:: EnumFormatEtc](/windows/win32/api/objidl/nf-objidl-idataobject-enumformatetc) no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Retorna E_NOTIMPL.

##  <a name="firedatachange"></a>  IDataObjectImpl::FireDataChange

Envia uma notificação de alteração de volta para cada coletor de aviso que está sendo gerenciado no momento.

```
HRESULT FireDataChange();
```

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

##  <a name="getcanonicalformatetc"></a>  IDataObjectImpl::GetCanonicalFormatEtc

Recupera uma estrutura equivalente `FORMATETC` logicamente para uma que seja mais complexa.

```
HRESULT GetCanonicalFormatEtc(FORMATETC* pformatetcIn, FORMATETC* pformatetcOut);
```

### <a name="return-value"></a>Valor de retorno

Retorna E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IDataObject:: GetCanonicalFormatEtc](/windows/win32/api/objidl/nf-objidl-idataobject-getcanonicalformatetc) no SDK do Windows.

##  <a name="getdata"></a>  IDataObjectImpl::GetData

Transfere dados do objeto de dados para o cliente.

```
HRESULT GetData(
    FORMATETC* pformatetcIn,
    STGMEDIUM* pmedium);
```

### <a name="remarks"></a>Comentários

O parâmetro *pformatetcIn* deve especificar um tipo de mídia de armazenamento de TYMED_MFPICT.

Consulte [IDataObject:: GetData](/windows/win32/api/objidl/nf-objidl-idataobject-getdata) na SDK do Windows.

##  <a name="getdatahere"></a>  IDataObjectImpl::GetDataHere

Semelhante a `GetData`, exceto que o cliente deve alocar a `STGMEDIUM` estrutura.

```
HRESULT GetDataHere(
    FORMATETC* pformatetc,
    STGMEDIUM* pmedium);
```

### <a name="return-value"></a>Valor de retorno

Retorna E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IDataObject:: GetDataHere](/windows/win32/api/objidl/nf-objidl-idataobject-getdatahere) no SDK do Windows.

##  <a name="querygetdata"></a>  IDataObjectImpl::QueryGetData

Determina se o objeto de dados dá suporte `FORMATETC` a uma estrutura específica para transferir dados.

```
HRESULT QueryGetData(FORMATETC* pformatetc);
```

### <a name="return-value"></a>Valor de retorno

Retorna E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IDataObject:: QueryGetData](/windows/win32/api/objidl/nf-objidl-idataobject-querygetdata) no SDK do Windows.

##  <a name="setdata"></a>  IDataObjectImpl::SetData

Transfere dados do cliente para o objeto de dados.

```
HRESULT SetData(
    FORMATETC* pformatetc,
    STGMEDIUM* pmedium,
    BOOL fRelease);
```

### <a name="return-value"></a>Valor de retorno

Retorna E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IDataObject:: SetData](/windows/win32/api/objidl/nf-objidl-idataobject-setdata) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
