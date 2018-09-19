---
title: Classe CDynamicParameterAccessor | Microsoft Docs
ms.custom: ''
ms.date: 02/14/2018
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL.CDynamicParameterAccessor
- ATL::CDynamicParameterAccessor
- CDynamicParameterAccessor
- CDynamicParameterAccessor::CDynamicParameterAccessor
- CDynamicParameterAccessor.CDynamicParameterAccessor
- CDynamicParameterAccessor::GetParam
- ATL.CDynamicParameterAccessor.GetParam
- CDynamicParameterAccessor::GetParam<ctype>
- CDynamicParameterAccessor.GetParam
- GetParam
- ATL::CDynamicParameterAccessor::GetParam<ctype>
- ATL::CDynamicParameterAccessor::GetParam
- ATL::CDynamicParameterAccessor::GetParamCount
- CDynamicParameterAccessor::GetParamCount
- CDynamicParameterAccessor.GetParamCount
- GetParamCount
- ATL.CDynamicParameterAccessor.GetParamCount
- GetParamIO
- CDynamicParameterAccessor::GetParamIO
- ATL.CDynamicParameterAccessor.GetParamIO
- CDynamicParameterAccessor.GetParamIO
- ATL::CDynamicParameterAccessor::GetParamIO
- ATL::CDynamicParameterAccessor::GetParamLength
- ATL.CDynamicParameterAccessor.GetParamLength
- CDynamicParameterAccessor.GetParamLength
- CDynamicParameterAccessor::GetParamLength
- GetParamLength
- CDynamicParameterAccessor::GetParamName
- ATL.CDynamicParameterAccessor.GetParamName
- GetParamName
- CDynamicParameterAccessor.GetParamName
- ATL::CDynamicParameterAccessor::GetParamName
- CDynamicParameterAccessor::GetParamStatus
- CDynamicParameterAccessor.GetParamStatus
- ATL.CDynamicParameterAccessor.GetParamStatus
- ATL::CDynamicParameterAccessor::GetParamStatus
- GetParamStatus
- CDynamicParameterAccessor.GetParamString
- GetParamString
- CDynamicParameterAccessor::GetParamString
- ATL.CDynamicParameterAccessor.GetParamString
- ATL::CDynamicParameterAccessor::GetParamString
- CDynamicParameterAccessor.GetParamType
- CDynamicParameterAccessor:GetParamType
- CDynamicParameterAccessor::GetParamType
- ATL.CDynamicParameterAccessor.GetParamType
- GetParamType
- ATL::CDynamicParameterAccessor::GetParamType
- ATL::CDynamicParameterAccessor::SetParam
- ATL::CDynamicParameterAccessor::SetParam<ctype>
- CDynamicParameterAccessor.SetParam
- ATL.CDynamicParameterAccessor.SetParam
- SetParam
- CDynamicParameterAccessor:SetParam
- CDynamicParameterAccessor::SetParam<ctype>
- CDynamicParameterAccessor::SetParam
- ATL::CDynamicParameterAccessor::SetParamLength
- CDynamicParameterAccessor.SetParamLength
- ATL.CDynamicParameterAccessor.SetParamLength
- CDynamicParameterAccessor::SetParamLength
- SetParamLength
- CDynamicParameterAccessor::SetParamStatus
- ATL.CDynamicParameterAccessor.SetParamStatus
- ATL::CDynamicParameterAccessor::SetParamStatus
- CDynamicParameterAccessor.SetParamStatus
- SetParamStatus
- ATL.CDynamicParameterAccessor.SetParamString
- ATL::CDynamicParameterAccessor::SetParamString
- SetParamString
- CDynamicParameterAccessor::SetParamString
- CDynamicParameterAccessor.SetParamString
dev_langs:
- C++
helpviewer_keywords:
- CDynamicParameterAccessor class
- CDynamicParameterAccessor class, constructor
- CDynamicParameterAccessor method
- GetParam method
- GetParamCount method
- GetParamIO method
- GetParamLength method
- GetParamName method
- GetParamStatus method
- GetParamString method
- GetParamType method
- SetParam method
- SetParamLength method
- SetParamStatus method
- SetParamString method
ms.assetid: 5f22626e-e80d-491f-8b3b-cedc50331960
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: a92f52f7d97e3c89de3d147c2c1b798d4af6d3a4
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46019452"
---
# <a name="cdynamicparameteraccessor-class"></a>Classe CDynamicParameterAccessor

Semelhante ao [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) , mas obtém informações de parâmetro a ser definido por meio da chamada a [ICommandWithParameters](/sql/relational-databases/native-client-ole-db-interfaces/icommandwithparameters) interface.

## <a name="syntax"></a>Sintaxe

```cpp
class CDynamicParameterAccessor : public CDynamicAccessor
```

## <a name="requirements"></a>Requisitos

**Cabeçalho**: atldbcli.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[CDynamicParameterAccessor](#cdynamicparameteraccessor)|O construtor.|
|[GetParam](#getparam)|Recupera os dados de parâmetro do buffer.|
|[GetParamCount](#getparamcount)|Recupera o número de parâmetros no acessador.|
|[GetParamIO](#getparamio)|Determina se o parâmetro especificado é um parâmetro de entrada ou saído.|
|[GetParamLength](#getparamlength)|Recupera o comprimento do parâmetro especificado armazenado no buffer.|
|[GetParamName](#getparamname)|Recupera o nome de um parâmetro especificado.|
|[GetParamStatus](#getparamstatus)|Recupera o status do parâmetro especificado armazenado no buffer.|
|[GetParamString](#getparamstring)|Recupera os dados de cadeia de caracteres do parâmetro especificado armazenado no buffer.|
|[GetParamType](#getparamtype)|Recupera o tipo de dados de um parâmetro especificado.|
|[SetParam](#setparam)|Define o buffer usando os dados de parâmetro.|
|[SetParamLength](#setparamlength)|Define o comprimento do parâmetro especificado armazenado no buffer.|
|[SetParamStatus](#setparamstatus)|Define o status do parâmetro especificado armazenado no buffer.|
|[SetParamString](#setparamstring)|Define os dados de cadeia de caracteres do parâmetro especificado armazenado no buffer.|

## <a name="remarks"></a>Comentários

O provedor deve oferecer suporte `ICommandWithParameters` para o consumidor usar essa classe.

As informações de parâmetro são armazenadas em um buffer criadas e gerenciadas por esta classe. Obter dados de parâmetro do buffer usando [GetParam](../../data/oledb/cdynamicparameteraccessor-getparam.md) e [GetParamType](../../data/oledb/cdynamicparameteraccessor-getparamtype.md).

Para obter um exemplo que demonstra como usar essa classe para executar um procedimento armazenado do SQL Server e obter os valores de parâmetro de saída, consulte o [DynamicConsumer](https://github.com/Microsoft/VCSamples/tree/master/VC2008Samples/ATL/OLEDB/Consumer/DynamicConsumer) códigos de exemplo de [VCSamples Microsoft](https://github.com/Microsoft/VCSamples) repositório do GitHub.

## <a name="cdynamicparameteraccessor"></a> Cdynamicparameteraccessor:: Cdynamicparameteraccessor

O construtor.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
typedef CDynamicParameterAccessor _ParamClass;  
CDynamicParameterAccessor(DBBLOBHANDLINGENUM eBlobHandling = DBBLOBHANDLING_DEFAULT,   
   DBLENGTH nBlobSize = 8000 )   
   : CDynamicAccessor(eBlobHandling, nBlobSize )  
```  
  
#### <a name="parameters"></a>Parâmetros  

*eBlobHandling*<br/>
Especifica como os dados de BLOB deve ser tratada. O valor padrão é DBBLOBHANDLING_DEFAULT. Ver [cdynamicaccessor:: Setblobhandling](../../data/oledb/cdynamicaccessor-setblobhandling.md) para obter uma descrição dos valores DBBLOBHANDLINGENUM.  
  
*nBlobSize*<br/>
O tamanho máximo do BLOB em bytes. dados da coluna sobre esse valor são tratados como um BLOB. O valor padrão é de 8.000. Ver [cdynamicaccessor:: Setblobsizelimit](../../data/oledb/cdynamicaccessor-setblobsizelimit.md) para obter detalhes.  
  
### <a name="remarks"></a>Comentários  

Consulte a [cdynamicaccessor:: Cdynamicaccessor](../../data/oledb/cdynamicaccessor-cdynamicaccessor.md) construtor para obter mais informações sobre manipulação de BLOBs. 

## <a name="getparam"></a> Cdynamicparameteraccessor:: Getparam

Recupera os dados de não cadeia de caracteres para um parâmetro especificado do buffer de parâmetro.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
template <class ctype>bool GetParam(DBORDINAL nParam,   
   ctype* pData) const throw();  

template <class ctype> bool GetParam(TCHAR* pParamName,   
   ctype* pData) const throw();  

void* GetParam(DBORDINAL nParam) const throw();  

void* GetParam(TCHAR* pParamName) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  

*ctype*<br/>
Um parâmetro de modelo que é o tipo de dados.  
  
*nParam*<br/>
[in] O número do parâmetro (deslocamento de 1). O parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem no SQL ou chamada de procedimento armazenado. Ver [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.  
  
*pParamName*<br/>
[in] O nome do parâmetro.  
  
*pData*<br/>
[out] O ponteiro para a memória que contém os dados recuperados do buffer.  
  
### <a name="return-value"></a>Valor de retorno  

Para versões sem modelo, aponta para a memória que contém os dados recuperados do buffer. Para versões de modelo, retorna **verdadeira** em caso de sucesso ou **falso** em caso de falha.  
  
Use `GetParam` para recuperar dados de parâmetro de não cadeia de caracteres do buffer. Use [GetParamString](../../data/oledb/cdynamicparameteraccessor-getparamstring.md) para recuperar dados de parâmetro de cadeia de caracteres do buffer.  

## <a name="getparamcount"></a> Cdynamicparameteraccessor:: Getparamcount

Recupera o número de parâmetros armazenados no buffer.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
DB_UPARAMS GetParamCount() const throw();  
```  
  
### <a name="return-value"></a>Valor de retorno  

O número de parâmetros.  

## <a name="getparamio"></a> Cdynamicparameteraccessor:: Getparamio

Determina se o parâmetro especificado é um parâmetro de entrada ou saído.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
bool GetParamIO(DBORDINAL nParam,   
   DBPARAMIO* pParamIO) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  

*nParam*<br/>
[in] O número do parâmetro (deslocamento de 1). O parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem no SQL ou chamada de procedimento armazenado. Ver [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.  
  
*pParamIO*<br/>
Um ponteiro para a variável que contém o `DBPARAMIO` (entrada ou saída) o tipo do parâmetro especificado. Ele é definido da seguinte maneira:  
  
```cpp  
typedef DWORD DBPARAMIO;  
  
enum DBPARAMIOENUM {  
    DBPARAMIO_NOTPARAM   = 0,  
    DBPARAMIO_INPUT      = 0x1,  
    DBPARAMIO_OUTPUT     = 0x2  
};  
```  
  
### <a name="return-value"></a>Valor de retorno  

Retorna **verdadeira** em caso de sucesso ou **falso** em caso de falha.  

## <a name="getparamlength"></a> Cdynamicparameteraccessor:: Getparamlength

Recupera o comprimento do parâmetro especificado armazenado no buffer.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
bool GetParamLength(DBORDINAL nParam,  
   DBLENGTH* pLength);  

DBLENGTH* GetParamLength(DBORDINAL nParam) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  

*nParam*<br/>
[in] O número do parâmetro (deslocamento de 1). O parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem no SQL ou chamada de procedimento armazenado. Ver [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.  
  
*pLength*<br/>
[out] Um ponteiro para a variável que contém o comprimento em bytes do parâmetro especificado.  
  
### <a name="remarks"></a>Comentários  

A primeira substituição retorna **verdadeira** em caso de sucesso ou **falso** em caso de falha. A segunda substituição aponta para a memória que contém o comprimento do parâmetro. 

## <a name="getparamname"></a> Cdynamicparameteraccessor:: Getparamname

Recupera o nome do parâmetro especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
LPOLESTR GetParamName(DBORDINAL nParam) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  

*nParam*<br/>
[in] O número do parâmetro (deslocamento de 1). O parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem no SQL ou chamada de procedimento armazenado. Ver [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.  
  
### <a name="return-value"></a>Valor de retorno  

O nome do parâmetro especificado.  

## <a name="getparamstatus"></a> Cdynamicparameteraccessor:: Getparamstatus

Recupera o status do parâmetro especificado armazenado no buffer.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
bool GetParamStatus(DBORDINAL nParam,  
   DBSTATUS* pStatus);  

DBSTATUS* GetParamStatus(DBORDINAL nParam) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  

*nParam*<br/>
[in] O número do parâmetro (deslocamento de 1). O parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem no SQL ou chamada de procedimento armazenado. Ver [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.  
  
*pStatus*<br/>
[out] Um ponteiro para a variável que contém o status DBSTATUS do parâmetro especificado. Para obter informações sobre valores DBSTATUS, consulte [Status](/previous-versions/windows/desktop/ms722617\(v=vs.85\)) na *referência do programador DB OLE*, ou procurar DBSTATUS no OLEDB.  
  
### <a name="remarks"></a>Comentários  

A primeira substituição retorna **verdadeira** em caso de sucesso ou **falso** em caso de falha. A segunda substituição aponta para a memória que contém o status do parâmetro especificado.

## <a name="getparamstring"></a> Cdynamicparameteraccessor:: Getparamstring

Recupera os dados de cadeia de caracteres do parâmetro especificado armazenado no buffer.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
bool GetParamString(DBORDINAL nParam,  
   CSimpleStringA& strOutput) throw();

bool GetParamString(DBORDINAL nParam,  
   CSimpleStringW& strOutput) throw();
   
bool GetParamString(DBORDINAL nParam,  
   CHAR* pBuffer,  
   size_t* pMaxLen) throw();

bool GetParamString(DBORDINAL nParam,  
   WCHAR* pBuffer,  
   size_t* pMaxLen) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  

*nParam*<br/>
[in] O número do parâmetro (deslocamento de 1). O parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem no SQL ou chamada de procedimento armazenado. Ver [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.  
  
*strOutput*<br/>
[out] O ANSI (`CSimpleStringA`) ou Unicode (`CSimpleStringW`) dados do parâmetro especificado da cadeia de caracteres. Você deve passar um parâmetro de tipo `CString`, por exemplo:  
  
[!code-cpp[NVC_OLEDB_Consumer#9](../../data/oledb/codesnippet/cpp/cdynamicparameteraccessor-getparamstring_1.cpp)]  
  
*pBuffer*<br/>
[out] Um ponteiro para o ANSI (**CHAR**) ou Unicode (**WCHAR**) dados do parâmetro especificado da cadeia de caracteres.  
  
*pMaxLen*<br/>
[out] Um ponteiro para o tamanho do buffer apontado por *pBuffer* (em caracteres, incluindo o nulo de terminação).  
  
### <a name="remarks"></a>Comentários  

Retorna **verdadeira** em caso de sucesso ou **falso** em caso de falha.  
  
Se *pBuffer* for NULL, esse método definirá o tamanho do buffer na memória apontada por *pMaxLen* e retornar **verdadeiro** sem copiar os dados.  
  
Esse método irá falhar se o buffer *pBuffer* não é grande o suficiente para conter a cadeia de caracteres.  
  
Use `GetParamString` para recuperar dados de parâmetro de cadeia de caracteres do buffer. Use [GetParam](../../data/oledb/cdynamicparameteraccessor-getparam.md) para recuperar dados de parâmetro de não cadeia de caracteres do buffer.  

## <a name="getparamtype"></a> Cdynamicparameteraccessor:: Getparamtype

Recupera o tipo de dados de um parâmetro especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
bool GetParamType(DBORDINAL nParam,  
   DBTYPE* pType) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  

*nParam*<br/>
[in] O número do parâmetro (deslocamento de 1). O parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem no SQL ou chamada de procedimento armazenado. Ver [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.  
  
*PDigite*<br/>
[out] Um ponteiro para a variável que contém o tipo de dados do parâmetro especificado.  
  
### <a name="return-value"></a>Valor de retorno  

Retorna **verdadeira** em caso de sucesso ou **falso** em caso de falha.  

## <a name="setparam"></a> Cdynamicparameteraccessor:: SetParam

Define o buffer de parâmetro usando os dados (não-cadeia de caracteres) especificados.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
template <class ctype>
bool SetParam(DBORDINAL nParam,  
   constctype* pData,  
   DBSTATUS status = DBSTATUS_S_OK) throw();  

template <class ctype>  
bool SetParam(TCHAR* pParamName,  
   const ctype* pData,  
   DBSTATUS status = DBSTATUS_S_OK) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  

*ctype*<br/>
Um parâmetro de modelo que é o tipo de dados.  
  
*nParam*<br/>
[in] O número do parâmetro (deslocamento de 1). O parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem no SQL ou chamada de procedimento armazenado. Por exemplo:  
  
[!code-cpp[NVC_OLEDB_Consumer#8](../../data/oledb/codesnippet/cpp/cdynamicparameteraccessor-setparam_1.cpp)]  
  
*pParamName*<br/>
[in] O nome do parâmetro.  
  
*pData*<br/>
[in] O ponteiro para a memória que contém os dados a serem gravados no buffer.  
  
*status*<br/>
[in] O status da coluna DBSTATUS. Para obter informações sobre valores DBSTATUS, consulte [Status](/previous-versions/windows/desktop/ms722617\(v=vs.85\)) na *referência do programador DB OLE*, ou procurar DBSTATUS no OLEDB.  
  
### <a name="return-value"></a>Valor de retorno  

Retorna **verdadeira** em caso de sucesso ou **falso** em caso de falha.  
  
Use `SetParam` para definir dados de parâmetro de não cadeia de caracteres no buffer. Use [SetParamString](../../data/oledb/cdynamicparameteraccessor-setparamstring.md) para definir dados de parâmetro de cadeia de caracteres no buffer.  

## <a name="setparamlength"></a> Cdynamicparameteraccessor:: Setparamlength

Define o comprimento do parâmetro especificado armazenado no buffer.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
bool SetParamLength(DBORDINAL nParam,  
   DBLENGTH length);  
```  
  
#### <a name="parameters"></a>Parâmetros  

*nParam*<br/>
[in] O número do parâmetro (deslocamento de 1). O parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem no SQL ou chamada de procedimento armazenado. Ver [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.  
  
*length*<br/>
[in] O comprimento em bytes do parâmetro especificado.  
  
### <a name="remarks"></a>Comentários  

Retorna **verdadeira** em caso de sucesso ou **falso** em caso de falha. 

## <a name="setparamstatus"></a> Cdynamicparameteraccessor:: Setparamstatus

Define o status do parâmetro especificado armazenado no buffer.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
bool SetParamStatus(DBORDINAL nParam,  
   DBSTATUS status);  
```  
  
#### <a name="parameters"></a>Parâmetros  

*nParam*<br/>
[in] O número do parâmetro (deslocamento de 1). O parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem no SQL ou chamada de procedimento armazenado. Ver [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.  
  
*status*<br/>
[in] O status DBSTATUS do parâmetro especificado. Para obter informações sobre valores DBSTATUS, consulte [Status](/previous-versions/windows/desktop/ms722617\(v=vs.85\)) na *referência do programador DB OLE*, ou procurar DBSTATUS no OLEDB.  
  
### <a name="remarks"></a>Comentários  

Retorna **verdadeira** em caso de sucesso ou **falso** em caso de falha. 

## <a name="setparamstring"></a> Cdynamicparameteraccessor:: Setparamstring

Define os dados de cadeia de caracteres do parâmetro especificado armazenado no buffer.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
bool SetParamString(DBORDINAL nParam,   
   constCHAR* pString,   
   DBSTATUS status = DBSTATUS_S_OK) throw();bool SetParamString(DBORDINAL nParam,   
   constWCHAR* pString,   
   DBSTATUS status = DBSTATUS_S_OK) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  

*nParam*<br/>
[in] O número do parâmetro (deslocamento de 1). O parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem no SQL ou chamada de procedimento armazenado. Ver [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.  
  
*pString*<br/>
[in] Um ponteiro para o ANSI (**CHAR**) ou Unicode (**WCHAR**) dados do parâmetro especificado da cadeia de caracteres. Consulte DBSTATUS OLEDB.  
  
*status*<br/>
[in] O status DBSTATUS do parâmetro especificado. Para obter informações sobre valores DBSTATUS, consulte [Status](/previous-versions/windows/desktop/ms722617\(v=vs.85\)) na *referência do programador DB OLE*, ou procurar DBSTATUS no OLEDB.  
  
### <a name="remarks"></a>Comentários  

Retorna **verdadeira** em caso de sucesso ou **falso** em caso de falha.  
  
`SetParamString` falhará se você tentar definir uma cadeia de caracteres que é maior do que o tamanho máximo especificado para *pString*.  
  
Use `SetParamString` para definir dados de parâmetro de cadeia de caracteres no buffer. Use [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para definir dados de parâmetro de não cadeia de caracteres no buffer. 

## <a name="see-also"></a>Consulte também

[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)<br/>
[Classe CAccessor](../../data/oledb/caccessor-class.md)<br/>
[Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)<br/>
[Classe CManualAccessor](../../data/oledb/cmanualaccessor-class.md)  