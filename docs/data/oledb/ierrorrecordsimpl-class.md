---
title: Classe IErrorRecordsImpl
ms.date: 11/04/2016
f1_keywords:
- ATL::IErrorRecordsImpl
- ATL.IErrorRecordsImpl
- IErrorRecordsImpl
- GetErrorDescriptionString
- IErrorRecordsImpl.GetErrorDescriptionString
- IErrorRecordsImpl::GetErrorDescriptionString
- GetErrorGUID
- IErrorRecordsImpl.GetErrorGUID
- IErrorRecordsImpl::GetErrorGUID
- GetErrorHelpContext
- IErrorRecordsImpl::GetErrorHelpContext
- IErrorRecordsImpl.GetErrorHelpContext
- IErrorRecordsImpl::GetErrorHelpFile
- GetErrorHelpFile
- IErrorRecordsImpl.GetErrorHelpFile
- IErrorRecordsImpl.GetErrorSource
- GetErrorSource
- IErrorRecordsImpl::GetErrorSource
- IErrorRecordsImpl.AddErrorRecord
- AddErrorRecord
- IErrorRecordsImpl::AddErrorRecord
- ATL::IErrorRecordsImpl::GetBasicErrorInfo
- IErrorRecordsImpl::GetBasicErrorInfo
- GetBasicErrorInfo
- ATL.IErrorRecordsImpl.GetBasicErrorInfo
- IErrorRecordsImpl.GetBasicErrorInfo
- ATL::IErrorRecordsImpl::GetCustomErrorObject
- IErrorRecordsImpl::GetCustomErrorObject
- ATL.IErrorRecordsImpl.GetCustomErrorObject
- IErrorRecordsImpl.GetCustomErrorObject
- IErrorRecordsImpl.GetErrorInfo
- IErrorRecordsImpl::GetErrorInfo
- IErrorRecordsImpl::GetErrorParameters
- ATL.IErrorRecordsImpl.GetErrorParameters
- IErrorRecordsImpl.GetErrorParameters
- GetErrorParameters
- ATL::IErrorRecordsImpl::GetErrorParameters
- IErrorRecordsImpl::GetRecordCount
- ATL::IErrorRecordsImpl::GetRecordCount
- IErrorRecordsImpl.GetRecordCount
- ATL.IErrorRecordsImpl.GetRecordCount
- IErrorRecordsImpl::m_rgErrors
- IErrorRecordsImpl.m_rgErrors
- ATL.IErrorRecordsImpl.m_rgErrors
- m_rgErrors
- ATL::IErrorRecordsImpl::m_rgErrors
helpviewer_keywords:
- IErrorRecordsImpl class
- GetErrorDescriptionString method
- GetErrorGUID method
- GetErrorHelpContext method
- GetErrorHelpFile method
- GetErrorSource method
- AddErrorRecord method
- GetBasicErrorInfo method
- GetCustomErrorObject method
- GetErrorInfo method
- GetErrorParameters method
- GetRecordCount method
- m_rgErrors
ms.assetid: dea8e938-c5d8-45ab-86de-eb8fbf534ffb
ms.openlocfilehash: 189f97e72f1cb87de7e4c4a388128c2a76c42961
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88832432"
---
# <a name="ierrorrecordsimpl-class"></a>Classe IErrorRecordsImpl

Implementa a interface OLE DB [IErrorRecords](/previous-versions/windows/desktop/ms718112(v=vs.85)) , adicionando registros e recuperando registros de um membro de dados ([m_rgErrors](../../data/oledb/ierrorrecordsimpl-m-rgerrors.md)) do tipo **CAtlArray<** `RecordClass` **>** .

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class RecordClass = ATLERRORINFO>
class IErrorRecordsImpl : public IErrorRecords
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Uma classe derivada de `IErrorRecordsImpl` .

*RecordClass*<br/>
Uma classe que representa um objeto de erro OLE DB.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

| Nome | Descrição |
|-|-|
|[GetErrorDescriptionString](#geterrordescriptionstring)|Obtém a cadeia de caracteres de descrição do erro de um registro de erro.|
|[GetErrorGUID](#geterrorguid)|Obtém o GUID de erro de um registro de erro.|
|[GetErrorHelpContext](#geterrorhelpcontext)|Obtém a ID de contexto da ajuda de um registro de erro.|
|[GetErrorHelpFile](#geterrorhelpfile)|Obtém o nome de caminho completo do arquivo de ajuda de um registro de erro.|
|[GetError](#geterrorsource)|Obtém o código-fonte do erro de um registro de erro.|

### <a name="interface-methods"></a>Métodos de interface

| Nome | Descrição |
|-|-|
|[AddErrorRecord](#adderrorrecord)|Adiciona um registro ao objeto de erro OLE DB.|
|[GetBasicErrorInfo](#getbasicerrorinfo)|Retorna informações básicas sobre o erro, como o código de retorno e o número de erro específico do provedor.|
|[GetCustomErrorObject](#getcustomerrorobject)|Retorna um ponteiro para uma interface em um objeto de erro personalizado.|
|[GetErrorInfo](#geterrorinfo)|Retorna um ponteiro de interface [IErrorInfo](/previous-versions/windows/desktop/ms718112(v=vs.85)) no registro especificado.|
|[GetErrorParameters](#geterrorparameters)|Retorna os parâmetros de erro.|
|[GetRecordCount](#getrecordcount)|Retorna o número de registros no objeto de registro OLE DB.|

### <a name="data-members"></a>Membros de dados

| Nome | Descrição |
|-|-|
|[m_rgErrors](#rgerrors)|Uma matriz de registros de erro.|

## <a name="ierrorrecordsimplgeterrordescriptionstring"></a><a name="geterrordescriptionstring"></a> IErrorRecordsImpl::GetErrorDescriptionString

Obtém a cadeia de caracteres de descrição do erro de um registro de erro.

### <a name="syntax"></a>Sintaxe

```cpp
LPOLESTR GetErrorDescriptionString(ERRORINFO& rCurError);
```

#### <a name="parameters"></a>parâmetros

*rCurError*<br/>
Um `ERRORINFO` registro em uma `IErrorInfo` interface.

### <a name="return-value"></a>Valor Retornado

Um ponteiro para uma cadeia de caracteres que descreve o erro.

## <a name="ierrorrecordsimplgeterrorguid"></a><a name="geterrorguid"></a> IErrorRecordsImpl::GetErrorGUID

Obtém o GUID de erro de um registro de erro.

### <a name="syntax"></a>Sintaxe

```cpp
REFGUID GetErrorGUID(ERRORINFO& rCurError);
```

#### <a name="parameters"></a>parâmetros

*rCurError*<br/>
Um `ERRORINFO` registro em uma `IErrorInfo` interface.

### <a name="return-value"></a>Valor Retornado

Uma referência a um GUID para o erro.

## <a name="ierrorrecordsimplgeterrorhelpcontext"></a><a name="geterrorhelpcontext"></a> IErrorRecordsImpl::GetErrorHelpContext

Obtém a ID de contexto da ajuda de um registro de erro.

### <a name="syntax"></a>Sintaxe

```cpp
DWORD GetErrorHelpContext(ERRORINFO& rCurError);
```

#### <a name="parameters"></a>parâmetros

*rCurError*<br/>
Um `ERRORINFO` registro em uma `IErrorInfo` interface.

### <a name="return-value"></a>Valor Retornado

A ID de contexto da ajuda para o erro.

## <a name="ierrorrecordsimplgeterrorhelpfile"></a><a name="geterrorhelpfile"></a> IErrorRecordsImpl::GetErrorHelpFile

Obtém o nome do caminho do arquivo de ajuda de um registro de erro.

### <a name="syntax"></a>Sintaxe

```cpp
LPOLESTR GetErrorHelpFile(ERRORINFO& rCurError);
```

#### <a name="parameters"></a>parâmetros

*rCurError*<br/>
Um `ERRORINFO` registro em uma `IErrorInfo` interface.

### <a name="return-value"></a>Valor Retornado

Ponteiro para uma cadeia de caracteres que contém o nome do caminho do arquivo de ajuda para o erro.

## <a name="ierrorrecordsimplgeterrorsource"></a><a name="geterrorsource"></a> IErrorRecordsImpl:: geterrorname

Obtém o código-fonte que causou o erro de um registro de erro.

### <a name="syntax"></a>Sintaxe

```cpp
LPOLESTR GetErrorSource(ERRORINFO& rCurError);
```

#### <a name="parameters"></a>parâmetros

*rCurError*<br/>
Um `ERRORINFO` registro em uma `IErrorInfo` interface.

### <a name="return-value"></a>Valor Retornado

Ponteiro para uma cadeia de caracteres que contém o código-fonte do erro.

## <a name="ierrorrecordsimpladderrorrecord"></a><a name="adderrorrecord"></a> IErrorRecordsImpl::AddErrorRecord

Adiciona um registro ao objeto de erro OLE DB.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(AddErrorRecord )(ERRORINFO *pErrorInfo,
   DWORD dwLookupID,
   DISPPARAMS *pdispparams,
   IUnknown *punkCustomError,
   DWORD dwDynamicErrorID);
```

#### <a name="parameters"></a>parâmetros

Consulte [IErrorRecords:: AddErrorRecord](/previous-versions/windows/desktop/ms725362(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="ierrorrecordsimplgetbasicerrorinfo"></a><a name="getbasicerrorinfo"></a> IErrorRecordsImpl::GetBasicErrorInfo

Retorna informações básicas sobre o erro, como o código de retorno e o número de erro específico do provedor.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(GetBasicErrorInfo )(ULONG ulRecordNum,
   ERRORINFO *pErrorInfo);
```

#### <a name="parameters"></a>parâmetros

Consulte [IErrorRecords:: GetBasicErrorInfo](/previous-versions/windows/desktop/ms723907(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="ierrorrecordsimplgetcustomerrorobject"></a><a name="getcustomerrorobject"></a> IErrorRecordsImpl::GetCustomErrorObject

Retorna um ponteiro para uma interface em um objeto de erro personalizado.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(GetCustomErrorObject )(ULONG ulRecordNum,
   REFIID riid,
   IUnknown **ppObject);
```

#### <a name="parameters"></a>parâmetros

Consulte [IErrorRecords:: GetCustomErrorObject](/previous-versions/windows/desktop/ms725417(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="ierrorrecordsimplgeterrorinfo"></a><a name="geterrorinfo"></a> IErrorRecordsImpl:: GetErrorInfo

Retorna um ponteiro de interface [IErrorInfo](/previous-versions/windows/desktop/ms718112(v=vs.85)) no registro especificado.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(GetErrorInfo )(ULONG ulRecordNum,
   LCID lcid,
   IErrorInfo **ppErrorInfo);
```

#### <a name="parameters"></a>parâmetros

Consulte [IErrorRecords:: GetErrorInfo](/previous-versions/windows/desktop/ms711230(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="ierrorrecordsimplgeterrorparameters"></a><a name="geterrorparameters"></a> IErrorRecordsImpl:: geterroparameters

Retorna os parâmetros de erro.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(GetErrorParameters )(ULONG ulRecordNum,
   DISPPARAMS *pdispparams);
```

#### <a name="parameters"></a>parâmetros

Consulte [IErrorRecords:: Geterroparameters](/previous-versions/windows/desktop/ms715793(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="ierrorrecordsimplgetrecordcount"></a><a name="getrecordcount"></a> IErrorRecordsImpl::GetRecordCount

Retorna o número de registros no objeto de registro OLE DB.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(GetRecordCount )(ULONG *pcRecords);
```

#### <a name="parameters"></a>parâmetros

Consulte [IErrorRecords:: GetRecordCount](/previous-versions/windows/desktop/ms722724(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="ierrorrecordsimplm_rgerrors"></a><a name="rgerrors"></a> IErrorRecordsImpl:: m_rgErrors

Uma matriz de registros de erro.

### <a name="syntax"></a>Sintaxe

```cpp
CAtlArray< RecordClass > m_rgErrors;
```

## <a name="see-also"></a>Confira também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo de provedor de OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)
