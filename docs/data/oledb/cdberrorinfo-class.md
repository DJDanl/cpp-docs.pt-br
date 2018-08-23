---
title: Classe CDBErrorInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CDBErrorInfo
- ATL::CDBErrorInfo
- ATL.CDBErrorInfo
- ATL.CDBErrorInfo.GetAllErrorInfo
- CDBErrorInfo::GetAllErrorInfo
- ATL::CDBErrorInfo::GetAllErrorInfo
- GetAllErrorInfo
- CDBErrorInfo.GetAllErrorInfo
- CDBErrorInfo::GetBasicErrorInfo
- ATL.CDBErrorInfo.GetBasicErrorInfo
- CDBErrorInfo.GetBasicErrorInfo
- ATL::CDBErrorInfo::GetBasicErrorInfo
- GetBasicErrorInfo
- CDBErrorInfo::GetCustomErrorObject
- ATL.CDBErrorInfo.GetCustomErrorObject
- CDBErrorInfo.GetCustomErrorObject
- ATL::CDBErrorInfo::GetCustomErrorObject
- GetCustomErrorObject
- GetErrorInfo
- ATL.CDBErrorInfo.GetErrorInfo
- CDBErrorInfo.GetErrorInfo
- ATL::CDBErrorInfo::GetErrorInfo
- CDBErrorInfo::GetErrorInfo
- ATL.CDBErrorInfo.GetErrorParameters
- CDBErrorInfo::GetErrorParameters
- ATL::CDBErrorInfo::GetErrorParameters
- CDBErrorInfo.GetErrorParameters
- GetErrorParameters
- CDBErrorInfo.GetErrorRecords
- ATL.CDBErrorInfo.GetErrorRecords
- ATL::CDBErrorInfo::GetErrorRecords
- GetErrorRecords
- CDBErrorInfo::GetErrorRecords
dev_langs:
- C++
helpviewer_keywords:
- CDBErrorInfo class
- GetAllErrorInfo method
- GetBasicErrorInfo method
- GetCustomErrorObject method
- GetErrorInfo method
- GetErrorParameters method
- GetErrorRecords method
ms.assetid: 9a5c18a2-ee3e-40f5-ab4c-581288d7f737
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: b7eaba589e729230c0392ac67eff2389d430f842
ms.sourcegitcommit: a41c4d096afca1e9b619bbbce045b77135d32ae2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/14/2018
ms.locfileid: "42573296"
---
# <a name="cdberrorinfo-class"></a>Classe CDBErrorInfo
Fornece suporte para processamento de erro OLE DB usando o OLE DB [IErrorRecords](/previous-versions/windows/desktop/ms718112\(v=vs.85\)) interface.  
  
## <a name="syntax"></a>Sintaxe

```cpp
class CDBErrorInfo  
``` 

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h 
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[GetAllErrorInfo](#getallerrorinfo)|Retorna todas as informações de erro contidas em um registro de erro.|  
|[GetBasicErrorInfo](#getbasicerrorinfo)|Chamadas [IErrorRecords::GetBasicErrorInfo](/previous-versions/windows/desktop/ms723907\(v=vs.85\)) para retornar informações básicas sobre o erro especificado.|  
|[GetCustomErrorObject](#getcustomerrorobject)|Chamadas [IErrorRecords::GetCustomErrorObject](/previous-versions/windows/desktop/ms725417\(v=vs.85\)) para retornar um ponteiro para uma interface em um objeto de erro personalizada.|  
|[GetErrorInfo](#geterrorinfo)|Chamadas [IErrorRecords::GetErrorInfo](/previous-versions/windows/desktop/ms711230\(v=vs.85\)) para retornar um `IErrorInfo` ponteiro de interface para o registro especificado.|  
|[GetErrorParameters](#geterrorparameters)|Chamadas [IErrorRecords::GetErrorParameters](/previous-versions/windows/desktop/ms715793\(v=vs.85\)) para retornar os parâmetros de erro.|  
|[GetErrorRecords](#geterrorrecords)|Obtém os registros de erro para o objeto especificado.|  
  
## <a name="remarks"></a>Comentários  
 Essa interface retorna um ou mais registros de erro para o usuário. Chame [cdberrorinfo:: Geterrorrecords](../../data/oledb/cdberrorinfo-geterrorrecords.md) primeiro para obter uma contagem de registros de erro. Em seguida, chame um do acesso de funções, como [cdberrorinfo:: Getallerrorinfo](../../data/oledb/cdberrorinfo-getallerrorinfo.md), para recuperar informações de erro para cada registro.  
  
## <a name="getallerrorinfo"></a> Cdberrorinfo:: Getallerrorinfo
Retorna todos os tipos de informações de erro contidos em um registro de erro.  
  
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
 *ulRecordNum*  
 [in] O número com base em zero do registro para o qual retornar informações de erro.  
  
 *lcid*  
 [in] A ID de localidade para as informações de erro a ser retornado.  
  
 *pbstrDescription*  
 [out] Um ponteiro para uma descrição de texto do erro ou nulo se não há suporte para a localidade. Consulte Observações.  
  
 *pbstrSource*  
 [out] Um ponteiro para uma cadeia de caracteres que contém o nome do componente que gerou o erro.  
  
 *pguid*  
 [out] Um ponteiro para o GUID da interface que definiu o erro.  
  
 *pdwHelpContext*  
 [out] Um ponteiro para a ID de contexto de ajuda para o erro.  
  
 *pbstrHelpFile*  
 [out] Um ponteiro para uma cadeia de caracteres que contém o caminho para o arquivo de Ajuda que descreve o erro.  
  
### <a name="return-value"></a>Valor de retorno  
 S_OK se for bem-sucedido. Ver [IErrorRecords::GetErrorInfo](/previous-versions/windows/desktop/ms711230\(v=vs.85\)) na *referência do programador DB OLE* para outros valores de retorno.  
  
### <a name="remarks"></a>Comentários  
 O valor de saída *pbstrDescription* é obtida internamente chamando `IErrorInfo::GetDescription`, que define o valor como NULL se não há suporte para a localidade, ou se ambas as seguintes condições forem verdadeiras:  
  
1.  o valor de *lcid* não é dos EUA Inglês e  
  
2.  o valor de *lcid* é não é igual ao valor retornado por GetUserDefaultLCID. 

## <a name="getbasicerrorinfo"></a> Cdberrorinfo:: Getbasicerrorinfo
Chamadas [IErrorRecords::GetBasicErrorInfo](/previous-versions/windows/desktop/ms723907\(v=vs.85\)) para retornar informações básicas sobre o erro, como o código de retorno e o número de erro específico do provedor.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT GetBasicErrorInfo(ULONG ulRecordNum,   
   ERRORINFO* pErrorInfo) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [IErrorRecords::GetBasicErrorInfo](/previous-versions/windows/desktop/ms723907\(v=vs.85\)) na *referência do programador do OLE DB*.  
  
### <a name="return-value"></a>Valor de retorno  
 Um HRESULT padrão.  

## <a name="getcustomerrorobject"></a> Cdberrorinfo:: Getcustomerrorobject
Chamadas [IErrorRecords::GetCustomErrorObject](/previous-versions/windows/desktop/ms725417\(v=vs.85\)) para retornar um ponteiro para uma interface em um objeto de erro personalizada.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT GetCustomErrorObject(ULONG ulRecordNum,   
   REFIID riid,IUnknown** ppObject) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [IErrorRecords::GetCustomErrorObject](/previous-versions/windows/desktop/ms725417\(v=vs.85\)) na *referência do programador do OLE DB*.  
  
### <a name="return-value"></a>Valor de retorno  
 Um HRESULT padrão.  

## <a name="geterrorinfo"></a> Cdberrorinfo:: Geterrorinfo
Chamadas [IErrorRecords::GetErrorInfo](/previous-versions/windows/desktop/ms711230\(v=vs.85\)) para retornar uma [IErrorInfo](/previous-versions/windows/desktop/ms718112\(v=vs.85\)) ponteiro de interface para o registro especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT GetErrorInfo(ULONG ulRecordNum,   
   LCID lcid,IErrorInfo** ppErrorInfo) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [IErrorRecords::GetErrorInfo](/previous-versions/windows/desktop/ms711230\(v=vs.85\)) na *referência do programador do OLE DB*.  
  
### <a name="return-value"></a>Valor de retorno  
 Um HRESULT padrão.  

## <a name="geterrorparameters"></a> Cdberrorinfo:: Geterrorparameters
Chamadas [IErrorRecords::GetErrorParameters](/previous-versions/windows/desktop/ms715793\(v=vs.85\)) para retornar os parâmetros de erro.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT GetErrorParameters(ULONG ulRecordNum,   
   DISPPARAMS* pdispparams) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [IErrorRecords::GetErrorParameters](/previous-versions/windows/desktop/ms715793\(v=vs.85\)) na *referência do programador do OLE DB*.  
  
### <a name="return-value"></a>Valor de retorno  
 Um HRESULT padrão.  

## <a name="geterrorrecords"></a> Cdberrorinfo:: Geterrorrecords
Obtém os registros de erro para o objeto especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT GetErrorRecords(IUnknown* pUnk,   
   const IID& iid,   
   ULONG* pcRecords) throw();  

HRESULT GetErrorRecords(ULONG* pcRecords) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pUnk*  
 [in] A interface para o objeto para o qual obter os registros de erro.  
  
 *IID*  
 [in] O IID da interface associada ao erro.  
  
 *pcRecords*  
 [out] Um ponteiro para a contagem (baseado em um) dos registros de erro.  
  
### <a name="return-value"></a>Valor de retorno  
 Um HRESULT padrão.  
  
### <a name="remarks"></a>Comentários  
 Use a primeira forma da função se você quiser verificar qual interface para obter as informações de erro. Caso contrário, use o segundo formulário.  
  
## <a name="see-also"></a>Consulte também  
 [DBViewer](../../visual-cpp-samples.md)   
 [Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)