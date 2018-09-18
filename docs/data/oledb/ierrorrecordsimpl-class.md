---
title: Classe IErrorRecordsImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
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
- GetCustomErrorObject
- GetErrorInfo
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 13e00d3d5ac7cb6cf6e4078ee24a7c3b02a2778e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46043385"
---
# <a name="ierrorrecordsimpl-class"></a>Classe IErrorRecordsImpl

Implementa o OLE DB [IErrorRecords](/previous-versions/windows/desktop/ms718112\(v=vs.85\)) interface, adicionar registros a e recuperar registros de um membro de dados ([m_rgErrors](../../data/oledb/ierrorrecordsimpl-m-rgerrors.md)) do tipo **CAtlArray <** `RecordClass`**>**.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class RecordClass = ATLERRORINFO>  
class IErrorRecordsImpl : public IErrorRecords  
```  
  
### <a name="parameters"></a>Parâmetros  

*T*<br/>
Uma classe derivada de `IErrorRecordsImpl`.  
  
*RecordClass*<br/>
Uma classe que representa um objeto de erro OLE DB.  

## <a name="requirements"></a>Requisitos  

**Cabeçalho:** atldb.h  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[GetErrorDescriptionString](#geterrordescriptionstring)|Obtém a cadeia de caracteres de descrição de erro de um registro de erro.|  
|[GetErrorGUID](#geterrorguid)|Obtém o GUID de erro de um registro de erro.|  
|[GetErrorHelpContext](#geterrorhelpcontext)|Obtém a ID de contexto de ajuda de um registro de erro.|  
|[GetErrorHelpFile](#geterrorhelpfile)|Obtém o nome do caminho completo do arquivo de ajuda de um registro de erro.|  
|[GetErrorSource](#geterrorsource)|Obtém o código de origem do erro de um registro de erro.|  
  
### <a name="interface-methods"></a>Métodos de interface  
  
|||  
|-|-|  
|[AddErrorRecord](#adderrorrecord)|Adiciona um registro para o objeto de erro OLE DB.|  
|[GetBasicErrorInfo](#getbasicerrorinfo)|Retorna informações básicas sobre o erro, como o código de retorno e o número de erro específico do provedor.|  
|[GetCustomErrorObject](#getcustomerrorobject)|Retorna um ponteiro para uma interface em um objeto de erro personalizada.|  
|[GetErrorInfo](#geterrorinfo)|Retorna um [IErrorInfo](/previous-versions/windows/desktop/ms718112\(v=vs.85\)) ponteiro de interface sobre o registro especificado.|  
|[GetErrorParameters](#geterrorparameters)|Retorna os parâmetros de erro.|  
|[GetRecordCount](#getrecordcount)|Retorna o número de registros no objeto de registro de OLE DB.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|[m_rgErrors](#rgerrors)|Uma matriz de registros de erro.|  

## <a name="geterrordescriptionstring"></a> Ierrorrecordsimpl:: Geterrordescriptionstring

Obtém a cadeia de caracteres de descrição de erro de um registro de erro.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
LPOLESTR GetErrorDescriptionString(ERRORINFO& rCurError);  
```  
  
#### <a name="parameters"></a>Parâmetros  

*rCurError*<br/>
Uma `ERRORINFO` registro em um `IErrorInfo` interface.  
  
### <a name="return-value"></a>Valor de retorno  

Um ponteiro para uma cadeia de caracteres que descreve o erro.  
  
## <a name="geterrorguid"></a> Ierrorrecordsimpl:: Geterrorguid

Obtém o GUID de erro de um registro de erro.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
REFGUID GetErrorGUID(ERRORINFO& rCurError);  
```  
  
#### <a name="parameters"></a>Parâmetros  

*rCurError*<br/>
Uma `ERRORINFO` registro em um `IErrorInfo` interface.  
  
### <a name="return-value"></a>Valor de retorno  

Uma referência a um GUID para o erro.  

## <a name="geterrorhelpcontext"></a> Ierrorrecordsimpl:: Geterrorhelpcontext

Obtém a ID de contexto de ajuda de um registro de erro.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
DWORD GetErrorHelpContext(ERRORINFO& rCurError);  
```  
  
#### <a name="parameters"></a>Parâmetros  

*rCurError*<br/>
Uma `ERRORINFO` registro em um `IErrorInfo` interface.  
  
### <a name="return-value"></a>Valor de retorno  

A ID do contexto de ajuda para o erro.  

## <a name="geterrorhelpfile"></a> Ierrorrecordsimpl:: Geterrorhelpfile

Obtém o nome do caminho do arquivo de ajuda de um registro de erro.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
LPOLESTR GetErrorHelpFile(ERRORINFO& rCurError);  
```  
  
#### <a name="parameters"></a>Parâmetros  

*rCurError*<br/>
Uma `ERRORINFO` registro em um `IErrorInfo` interface.  
  
### <a name="return-value"></a>Valor de retorno  

Ponteiro para uma cadeia de caracteres que contém o nome do caminho do arquivo de ajuda para o erro.

## <a name="geterrorsource"></a> Ierrorrecordsimpl:: Geterrorsource

Obtém o código-fonte que causou o erro de um registro de erro.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
LPOLESTR GetErrorSource(ERRORINFO& rCurError);  
```  
  
#### <a name="parameters"></a>Parâmetros  

*rCurError*<br/>
Uma `ERRORINFO` registro em um `IErrorInfo` interface.  
  
### <a name="return-value"></a>Valor de retorno  

Ponteiro para uma cadeia de caracteres que contém o código-fonte para o erro. 

## <a name="adderrorrecord"></a> Ierrorrecordsimpl:: Adderrorrecord

Adiciona um registro para o objeto de erro OLE DB.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD(AddErrorRecord )(ERRORINFO *pErrorInfo,  
   DWORD dwLookupID,  
   DISPPARAMS *pdispparams,  
   IUnknown *punkCustomError,  
   DWORD dwDynamicErrorID);  
```  
  
#### <a name="parameters"></a>Parâmetros  

Ver [IErrorRecords::AddErrorRecord](/previous-versions/windows/desktop/ms725362\(v=vs.85\)) na *referência do programador do OLE DB*.  

## <a name="getbasicerrorinfo"></a> Ierrorrecordsimpl:: Getbasicerrorinfo

Retorna informações básicas sobre o erro, como o código de retorno e o número de erro específico do provedor.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD(GetBasicErrorInfo )(ULONG ulRecordNum,  
   ERRORINFO *pErrorInfo);  
```  
  
#### <a name="parameters"></a>Parâmetros  

Ver [IErrorRecords::GetBasicErrorInfo](/previous-versions/windows/desktop/ms723907\(v=vs.85\)) na *referência do programador do OLE DB*. 

## <a name="getcustomerrorobject"></a> Ierrorrecordsimpl:: Getcustomerrorobject

Retorna um ponteiro para uma interface em um objeto de erro personalizada.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD(GetCustomErrorObject )(ULONG ulRecordNum,  
   REFIID riid,  
   IUnknown **ppObject);  
```  
  
#### <a name="parameters"></a>Parâmetros  

Ver [IErrorRecords::GetCustomErrorObject](/previous-versions/windows/desktop/ms725417\(v=vs.85\)) na *referência do programador do OLE DB*.  

## <a name="geterrorinfo"></a> Ierrorrecordsimpl:: Geterrorinfo

Retorna um [IErrorInfo](/previous-versions/windows/desktop/ms718112\(v=vs.85\)) ponteiro de interface sobre o registro especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD(GetErrorInfo )(ULONG ulRecordNum,  
   LCID lcid,  
   IErrorInfo **ppErrorInfo);  
```  
  
#### <a name="parameters"></a>Parâmetros  

Ver [IErrorRecords::GetErrorInfo](/previous-versions/windows/desktop/ms711230\(v=vs.85\)) na *referência do programador do OLE DB*.

## <a name="geterrorparameters"></a> Ierrorrecordsimpl:: Geterrorparameters

Retorna os parâmetros de erro.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD(GetErrorParameters )(ULONG ulRecordNum,  
   DISPPARAMS *pdispparams);  
```  
  
#### <a name="parameters"></a>Parâmetros  

Ver [IErrorRecords::GetErrorParameters](/previous-versions/windows/desktop/ms715793\(v=vs.85\)) na *referência do programador do OLE DB*.  

## <a name="getrecordcount"></a> Ierrorrecordsimpl:: Getrecordcount

Retorna o número de registros no objeto de registro de OLE DB.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD(GetRecordCount )(ULONG *pcRecords);  
```  
  
#### <a name="parameters"></a>Parâmetros  

Ver [IErrorRecords::GetRecordCount](/previous-versions/windows/desktop/ms722724\(v=vs.85\)) na *referência do programador do OLE DB*.  

## <a name="rgerrors"></a> Ierrorrecordsimpl:: M_rgerrors

Uma matriz de registros de erro.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
CAtlArray< RecordClass > m_rgErrors;  
```  
  
## <a name="see-also"></a>Consulte também  

[Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)