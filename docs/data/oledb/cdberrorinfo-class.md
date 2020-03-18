---
title: Classe CDBErrorInfo
ms.date: 11/04/2016
f1_keywords:
- CDBErrorInfo
- ATL::CDBErrorInfo
- ATL.CDBErrorInfo
- ATL.CDBErrorInfo.GetAllErrorInfo
- CDBErrorInfo::GetAllErrorInfo
- ATL::CDBErrorInfo::GetAllErrorInfo
- CDBErrorInfo.GetAllErrorInfo
- CDBErrorInfo::GetBasicErrorInfo
- ATL.CDBErrorInfo.GetBasicErrorInfo
- CDBErrorInfo.GetBasicErrorInfo
- ATL::CDBErrorInfo::GetBasicErrorInfo
- CDBErrorInfo::GetCustomErrorObject
- ATL.CDBErrorInfo.GetCustomErrorObject
- CDBErrorInfo.GetCustomErrorObject
- ATL::CDBErrorInfo::GetCustomErrorObject
- ATL.CDBErrorInfo.GetErrorInfo
- CDBErrorInfo.GetErrorInfo
- ATL::CDBErrorInfo::GetErrorInfo
- CDBErrorInfo::GetErrorInfo
- ATL.CDBErrorInfo.GetErrorParameters
- CDBErrorInfo::GetErrorParameters
- ATL::CDBErrorInfo::GetErrorParameters
- CDBErrorInfo.GetErrorParameters
- CDBErrorInfo.GetErrorRecords
- ATL.CDBErrorInfo.GetErrorRecords
- ATL::CDBErrorInfo::GetErrorRecords
- CDBErrorInfo::GetErrorRecords
helpviewer_keywords:
- CDBErrorInfo class
- GetAllErrorInfo method
- GetBasicErrorInfo method
- GetCustomErrorObject method
- GetErrorInfo method
- GetErrorParameters method
- GetErrorRecords method
ms.assetid: 9a5c18a2-ee3e-40f5-ab4c-581288d7f737
ms.openlocfilehash: 2d2b21652fd5ee3604c3c72c2168c3d9a495caf1
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447462"
---
# <a name="cdberrorinfo-class"></a>Classe CDBErrorInfo

Fornece suporte para OLE DB processamento de erro usando a interface OLE DB [IErrorRecords](/previous-versions/windows/desktop/ms718112(v=vs.85)) .

## <a name="syntax"></a>Sintaxe

```cpp
class CDBErrorInfo
```

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** atldbcli. h

## <a name="members"></a>Membros

### <a name="methods"></a>{1&gt;Métodos&lt;1}

|||
|-|-|
|[GetAllErrorInfo](#getallerrorinfo)|Retorna todas as informações de erro contidas em um registro de erro.|
|[GetBasicErrorInfo](#getbasicerrorinfo)|Chama [IErrorRecords:: GetBasicErrorInfo](/previous-versions/windows/desktop/ms723907(v=vs.85)) para retornar informações básicas sobre o erro especificado.|
|[GetCustomErrorObject](#getcustomerrorobject)|Chama [IErrorRecords:: GetCustomErrorObject](/previous-versions/windows/desktop/ms725417(v=vs.85)) para retornar um ponteiro para uma interface em um objeto de erro personalizado.|
|[GetErrorInfo](#geterrorinfo)|Chama [IErrorRecords:: GetErrorInfo](/previous-versions/windows/desktop/ms711230(v=vs.85)) para retornar um ponteiro de interface `IErrorInfo` para o registro especificado.|
|[GetErrorParameters](#geterrorparameters)|Chama [IErrorRecords:: Geterroparameters](/previous-versions/windows/desktop/ms715793(v=vs.85)) para retornar os parâmetros de erro.|
|[GetErrorRecords](#geterrorrecords)|Obtém registros de erro para o objeto especificado.|

## <a name="remarks"></a>Comentários

Essa interface retorna um ou mais registros de erro ao usuário. Chame [CDBErrorInfo:: GetErrorRecords](../../data/oledb/cdberrorinfo-geterrorrecords.md) primeiro para obter uma contagem de registros de erro. Em seguida, chame uma das funções de acesso, como [CDBErrorInfo:: GetAllErrorInfo](../../data/oledb/cdberrorinfo-getallerrorinfo.md), para recuperar informações de erro para cada registro.

## <a name="getallerrorinfo"></a>CDBErrorInfo::GetAllErrorInfo

Retorna todos os tipos de informações de erro contidas em um registro de erro.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetAllErrorInfo(ULONG ulRecordNum,
   LCID lcid,  BSTR* pbstrDescription,
   BSTR* pbstrSource = NULL,
   GUID* pguid = NULL,
   DWORD* pdwHelpContext = NULL,
   BSTR* pbstrHelpFile = NULL) const throw();
```

#### <a name="parameters"></a>Parâmetros

*ulRecordNum*<br/>
no O número de base zero do registro para o qual retornar informações de erro.

*lcid*<br/>
no A ID de localidade para as informações de erro a serem retornadas.

*pbstrDescription*<br/>
fora Um ponteiro para uma descrição de texto do erro ou NULL se não houver suporte para a localidade. Consulte Observações.

*pbstrSource*<br/>
fora Um ponteiro para uma cadeia de caracteres que contém o nome do componente que gerou o erro.

*pguid*<br/>
fora Um ponteiro para o GUID da interface que definiu o erro.

*pdwHelpContext*<br/>
fora Um ponteiro para a ID de contexto da ajuda para o erro.

*pbstrHelpFile*<br/>
fora Um ponteiro para uma cadeia de caracteres que contém o caminho para o arquivo de ajuda que descreve o erro.

### <a name="return-value"></a>Valor retornado

S_OK se tiver êxito. Consulte [IErrorRecords:: GetErrorInfo](/previous-versions/windows/desktop/ms711230(v=vs.85)) na *referência do programador de OLE DB* para outros valores de retorno.

### <a name="remarks"></a>Comentários

O valor de saída de *pbstrDescription* é obtido internamente chamando `IErrorInfo::GetDescription`, que define o valor como NULL se a localidade não for suportada ou se ambas das seguintes condições forem verdadeiras:

1. o valor de *LCID* não é inglês dos EUA e

1. o valor de *LCID* não é igual ao valor retornado por GetUserDefaultLCID.

## <a name="getbasicerrorinfo"></a>CDBErrorInfo::GetBasicErrorInfo

Chama [IErrorRecords:: GetBasicErrorInfo](/previous-versions/windows/desktop/ms723907(v=vs.85)) para retornar informações básicas sobre o erro, como o código de retorno e o número de erro específico do provedor.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetBasicErrorInfo(ULONG ulRecordNum,
   ERRORINFO* pErrorInfo) const throw();
```

#### <a name="parameters"></a>Parâmetros

Consulte [IErrorRecords:: GetBasicErrorInfo](/previous-versions/windows/desktop/ms723907(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

## <a name="getcustomerrorobject"></a>CDBErrorInfo::GetCustomErrorObject

Chama [IErrorRecords:: GetCustomErrorObject](/previous-versions/windows/desktop/ms725417(v=vs.85)) para retornar um ponteiro para uma interface em um objeto de erro personalizado.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetCustomErrorObject(ULONG ulRecordNum,
   REFIID riid,IUnknown** ppObject) const throw();
```

#### <a name="parameters"></a>Parâmetros

Consulte [IErrorRecords:: GetCustomErrorObject](/previous-versions/windows/desktop/ms725417(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

## <a name="geterrorinfo"></a>CDBErrorInfo:: GetErrorInfo

Chama [IErrorRecords:: GetErrorInfo](/previous-versions/windows/desktop/ms711230(v=vs.85)) para retornar um ponteiro de interface [IErrorInfo](/previous-versions/windows/desktop/ms718112(v=vs.85)) para o registro especificado.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetErrorInfo(ULONG ulRecordNum,
   LCID lcid,IErrorInfo** ppErrorInfo) const throw();
```

#### <a name="parameters"></a>Parâmetros

Consulte [IErrorRecords:: GetErrorInfo](/previous-versions/windows/desktop/ms711230(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

## <a name="geterrorparameters"></a>CDBErrorInfo:: geterroparameters

Chama [IErrorRecords:: Geterroparameters](/previous-versions/windows/desktop/ms715793(v=vs.85)) para retornar os parâmetros de erro.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetErrorParameters(ULONG ulRecordNum,
   DISPPARAMS* pdispparams) const throw();
```

#### <a name="parameters"></a>Parâmetros

Consulte [IErrorRecords:: Geterroparameters](/previous-versions/windows/desktop/ms715793(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

## <a name="geterrorrecords"></a>CDBErrorInfo::GetErrorRecords

Obtém registros de erro para o objeto especificado.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetErrorRecords(IUnknown* pUnk,
   const IID& iid,
   ULONG* pcRecords) throw();

HRESULT GetErrorRecords(ULONG* pcRecords) throw();
```

#### <a name="parameters"></a>Parâmetros

*pUnk*<br/>
no Interface para o objeto para o qual obter registros de erro.

*IID*<br/>
no O IID da interface associada ao erro.

*pcRecords*<br/>
fora Um ponteiro para a contagem de registros de erro (baseado em um).

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Use a primeira forma da função se você quiser verificar de qual interface obter as informações de erro. Caso contrário, use o segundo formulário.

## <a name="see-also"></a>Consulte também

[DBViewer](../../overview/visual-cpp-samples.md)<br/>
[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)