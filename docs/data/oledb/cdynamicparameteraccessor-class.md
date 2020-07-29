---
title: Classe CDynamicParameterAccessor
ms.date: 02/14/2018
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
ms.openlocfilehash: b7125390013e417123f09a5cc7f58be9ea87db56
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216460"
---
# <a name="cdynamicparameteraccessor-class"></a>Classe CDynamicParameterAccessor

Semelhante a [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) , mas obtém informações de parâmetro a serem definidas chamando a interface [ICommandWithParameters](/sql/relational-databases/native-client-ole-db-interfaces/icommandwithparameters) .

## <a name="syntax"></a>Sintaxe

```cpp
class CDynamicParameterAccessor : public CDynamicAccessor
```

## <a name="requirements"></a>Requisitos

**Cabeçalho**: atldbcli. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[CDynamicParameterAccessor](#cdynamicparameteraccessor)|O construtor.|
|[GetParam](#getparam)|Recupera os dados do parâmetro do buffer.|
|[GetParamCount](#getparamcount)|Recupera o número de parâmetros no acessador.|
|[GetParamIO](#getparamio)|Determina se o parâmetro especificado é um parâmetro de entrada ou de saída.|
|[GetParamLength](#getparamlength)|Recupera o comprimento do parâmetro especificado armazenado no buffer.|
|[GetParamName](#getparamname)|Recupera o nome de um parâmetro especificado.|
|[GetParamStatus](#getparamstatus)|Recupera o status do parâmetro especificado armazenado no buffer.|
|[GetParamString](#getparamstring)|Recupera os dados de cadeia de caracteres do parâmetro especificado armazenado no buffer.|
|[GetParamType](#getparamtype)|Recupera o tipo de dados de um parâmetro especificado.|
|[SetParam](#setparam)|Define o buffer usando os dados do parâmetro.|
|[SetParamLength](#setparamlength)|Define o comprimento do parâmetro especificado armazenado no buffer.|
|[SetParamStatus](#setparamstatus)|Define o status do parâmetro especificado armazenado no buffer.|
|[SetParamString](#setparamstring)|Define os dados de cadeia de caracteres do parâmetro especificado armazenado no buffer.|

## <a name="remarks"></a>Comentários

O provedor deve dar suporte ao `ICommandWithParameters` consumidor para usar essa classe.

As informações de parâmetro são armazenadas em um buffer criado e gerenciado por essa classe. Obtenha dados de parâmetro do buffer usando [GetParam](../../data/oledb/cdynamicparameteraccessor-getparam.md) e [GetParamType](../../data/oledb/cdynamicparameteraccessor-getparamtype.md).

Para obter um exemplo que demonstra como usar essa classe para executar um procedimento armazenado SQL Server e obter os valores de parâmetro de saída, consulte o código de exemplo [DynamicConsumer](https://github.com/Microsoft/VCSamples/tree/master/VC2008Samples/ATL/OLEDB/Consumer/DynamicConsumer) no repositório do [Microsoft VCSamples](https://github.com/Microsoft/VCSamples) no github.

## <a name="cdynamicparameteraccessorcdynamicparameteraccessor"></a><a name="cdynamicparameteraccessor"></a>CDynamicParameterAccessor::CDynamicParameterAccessor

O construtor.

### <a name="syntax"></a>Sintaxe

```cpp
typedef CDynamicParameterAccessor _ParamClass;
CDynamicParameterAccessor(
   DBBLOBHANDLINGENUM eBlobHandling = DBBLOBHANDLING_DEFAULT,
   DBLENGTH nBlobSize = 8000 )
   : CDynamicAccessor(eBlobHandling, nBlobSize )
```

#### <a name="parameters"></a>parâmetros

*eBlobHandling*<br/>
Especifica como os dados de BLOB serão manipulados. O valor padrão é DBBLOBHANDLING_DEFAULT. Consulte [CDynamicAccessor:: SetBlobHandling](../../data/oledb/cdynamicaccessor-setblobhandling.md) para obter uma descrição dos valores de DBBLOBHANDLINGENUM.

*nBlobSize*<br/>
O tamanho máximo do BLOB em bytes; os dados de coluna sobre esse valor são tratados como um BLOB. O valor padrão é 8.000. Consulte [CDynamicAccessor:: SetBlobSizeLimit](../../data/oledb/cdynamicaccessor-setblobsizelimit.md) para obter detalhes.

### <a name="remarks"></a>Comentários

Consulte o construtor [CDynamicAccessor:: CDynamicAccessor](../../data/oledb/cdynamicaccessor-cdynamicaccessor.md) para obter mais informações sobre manipulação de BLOB.

## <a name="cdynamicparameteraccessorgetparam"></a><a name="getparam"></a>CDynamicParameterAccessor:: GetParam

Recupera os dados sem cadeia de caracteres para um parâmetro especificado do buffer de parâmetros.

### <a name="syntax"></a>Sintaxe

```cpp
template <class ctype>bool GetParam(DBORDINAL nParam,
   ctype* pData) const throw();

template <class ctype> bool GetParam(TCHAR* pParamName,
   ctype* pData) const throw();

void* GetParam(DBORDINAL nParam) const throw();

void* GetParam(TCHAR* pParamName) const throw();
```

#### <a name="parameters"></a>parâmetros

*ctype*<br/>
Um parâmetro de modelo que é o tipo de dados.

*nParam*<br/>
no O número do parâmetro (deslocamento de 1). O parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem na chamada de procedimento armazenado ou SQL. Consulte [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.

*pParamName*<br/>
no O nome do parâmetro.

*pData*<br/>
fora O ponteiro para a memória que contém os dados recuperados do buffer.

### <a name="return-value"></a>Valor retornado

Para versões não-modelo, aponta para a memória que contém os dados recuperados do buffer. Para versões de modelo, retorna **`true`** em caso de êxito ou **`false`** falha.

Use `GetParam` para recuperar dados de parâmetro que não são de cadeia de caracteres do buffer. Use [GetParamString](../../data/oledb/cdynamicparameteraccessor-getparamstring.md) para recuperar dados de parâmetro de cadeia de caracteres do buffer.

## <a name="cdynamicparameteraccessorgetparamcount"></a><a name="getparamcount"></a>CDynamicParameterAccessor::GetParamCount

Recupera o número de parâmetros armazenados no buffer.

### <a name="syntax"></a>Sintaxe

```cpp
DB_UPARAMS GetParamCount() const throw();
```

### <a name="return-value"></a>Valor retornado

O número de parâmetros.

## <a name="cdynamicparameteraccessorgetparamio"></a><a name="getparamio"></a>CDynamicParameterAccessor::GetParamIO

Determina se o parâmetro especificado é um parâmetro de entrada ou de saída.

### <a name="syntax"></a>Sintaxe

```cpp
bool GetParamIO(DBORDINAL nParam,
   DBPARAMIO* pParamIO) const throw();
```

#### <a name="parameters"></a>parâmetros

*nParam*<br/>
no O número do parâmetro (deslocamento de 1). O parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem na chamada de procedimento armazenado ou SQL. Consulte [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.

*pParamIO*<br/>
Um ponteiro para a variável que contém o `DBPARAMIO` tipo (entrada ou saída) do parâmetro especificado. Ela é definida da seguinte maneira:

```cpp
typedef DWORD DBPARAMIO;

enum DBPARAMIOENUM {
    DBPARAMIO_NOTPARAM   = 0,
    DBPARAMIO_INPUT      = 0x1,
    DBPARAMIO_OUTPUT     = 0x2
};
```

### <a name="return-value"></a>Valor retornado

Retorna **`true`** em caso de êxito ou **`false`** falha.

## <a name="cdynamicparameteraccessorgetparamlength"></a><a name="getparamlength"></a>CDynamicParameterAccessor::GetParamLength

Recupera o comprimento do parâmetro especificado armazenado no buffer.

### <a name="syntax"></a>Sintaxe

```cpp
bool GetParamLength(DBORDINAL nParam,
   DBLENGTH* pLength);

DBLENGTH* GetParamLength(DBORDINAL nParam) const throw();
```

#### <a name="parameters"></a>parâmetros

*nParam*<br/>
no O número do parâmetro (deslocamento de 1). O parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem na chamada de procedimento armazenado ou SQL. Consulte [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.

*pLength*<br/>
fora Um ponteiro para a variável que contém o comprimento em bytes do parâmetro especificado.

### <a name="remarks"></a>Comentários

A primeira substituição retorna **`true`** em caso de êxito ou **`false`** falha. A segunda substituição aponta para a memória que contém o comprimento do parâmetro.

## <a name="cdynamicparameteraccessorgetparamname"></a><a name="getparamname"></a>CDynamicParameterAccessor:: GetParamName

Recupera o nome do parâmetro especificado.

### <a name="syntax"></a>Sintaxe

```cpp
LPOLESTR GetParamName(DBORDINAL nParam) const throw();
```

#### <a name="parameters"></a>parâmetros

*nParam*<br/>
no O número do parâmetro (deslocamento de 1). O parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem na chamada de procedimento armazenado ou SQL. Consulte [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.

### <a name="return-value"></a>Valor retornado

O nome do parâmetro especificado.

## <a name="cdynamicparameteraccessorgetparamstatus"></a><a name="getparamstatus"></a>CDynamicParameterAccessor::GetParamStatus

Recupera o status do parâmetro especificado armazenado no buffer.

### <a name="syntax"></a>Sintaxe

```cpp
bool GetParamStatus(DBORDINAL nParam,
   DBSTATUS* pStatus);

DBSTATUS* GetParamStatus(DBORDINAL nParam) const throw();
```

#### <a name="parameters"></a>parâmetros

*nParam*<br/>
no O número do parâmetro (deslocamento de 1). O parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem na chamada de procedimento armazenado ou SQL. Consulte [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.

*pStatus*<br/>
fora Um ponteiro para a variável que contém o status de DBSTATUS do parâmetro especificado. Para obter informações sobre valores de DBSTATUS, consulte [status](/previous-versions/windows/desktop/ms722617(v=vs.85)) na *referência do programador de OLE DB*ou pesquise por DBSTATUS em OLEDB. h.

### <a name="remarks"></a>Comentários

A primeira substituição retorna **`true`** em caso de êxito ou **`false`** falha. A segunda substituição aponta para a memória que contém o status do parâmetro especificado.

## <a name="cdynamicparameteraccessorgetparamstring"></a><a name="getparamstring"></a>CDynamicParameterAccessor:: GetParamString

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

#### <a name="parameters"></a>parâmetros

*nParam*<br/>
no O número do parâmetro (deslocamento de 1). O parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem na chamada de procedimento armazenado ou SQL. Consulte [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.

*strOutput*<br/>
fora Os `CSimpleStringA` dados de cadeia de caracteres ANSI () ou Unicode ( `CSimpleStringW` ) do parâmetro especificado. Você deve passar um parâmetro do tipo `CString` , por exemplo:

[!code-cpp[NVC_OLEDB_Consumer#9](../../data/oledb/codesnippet/cpp/cdynamicparameteraccessor-getparamstring_1.cpp)]

*pBuffer*<br/>
fora Um ponteiro para os dados de cadeia de caracteres ANSI (**Char**) ou Unicode (**WCHAR**) do parâmetro especificado.

*pMaxLen*<br/>
fora Um ponteiro para o tamanho do buffer apontado por *pBuffer* (em caracteres, incluindo o nulo de terminação).

### <a name="remarks"></a>Comentários

Retorna **`true`** em caso de êxito ou **`false`** falha.

Se *pBuffer* for NULL, esse método definirá o tamanho de buffer necessário na memória apontada por *pMaxLen* e retornará **`true`** sem copiar os dados.

Esse método falhará se o buffer *pBuffer* não for grande o suficiente para conter a cadeia de caracteres inteira.

Use `GetParamString` para recuperar dados de parâmetro de cadeia de caracteres do buffer. Use [GetParam](../../data/oledb/cdynamicparameteraccessor-getparam.md) para recuperar dados de parâmetro que não são de cadeia de caracteres do buffer.

## <a name="cdynamicparameteraccessorgetparamtype"></a><a name="getparamtype"></a>CDynamicParameterAccessor:: GetParamType

Recupera o tipo de dados de um parâmetro especificado.

### <a name="syntax"></a>Sintaxe

```cpp
bool GetParamType(DBORDINAL nParam,
   DBTYPE* pType) const throw();
```

#### <a name="parameters"></a>parâmetros

*nParam*<br/>
no O número do parâmetro (deslocamento de 1). O parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem na chamada de procedimento armazenado ou SQL. Consulte [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.

*pType*<br/>
fora Um ponteiro para a variável que contém o tipo de dados do parâmetro especificado.

### <a name="return-value"></a>Valor retornado

Retorna **`true`** em caso de êxito ou **`false`** falha.

## <a name="cdynamicparameteraccessorsetparam"></a><a name="setparam"></a>CDynamicParameterAccessor:: SetParam

Define o buffer de parâmetro usando os dados especificados (não cadeia de caracteres).

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

#### <a name="parameters"></a>parâmetros

*ctype*<br/>
Um parâmetro de modelo que é o tipo de dados.

*nParam*<br/>
no O número do parâmetro (deslocamento de 1). O parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem na chamada de procedimento armazenado ou SQL. Por exemplo:

[!code-cpp[NVC_OLEDB_Consumer#8](../../data/oledb/codesnippet/cpp/cdynamicparameteraccessor-setparam_1.cpp)]

*pParamName*<br/>
no O nome do parâmetro.

*pData*<br/>
no O ponteiro para a memória que contém os dados a serem gravados no buffer.

*status*<br/>
no O status da coluna DBSTATUS. Para obter informações sobre valores de DBSTATUS, consulte [status](/previous-versions/windows/desktop/ms722617(v=vs.85)) na *referência do programador de OLE DB*ou pesquise por DBSTATUS em OLEDB. h.

### <a name="return-value"></a>Valor retornado

Retorna **`true`** em caso de êxito ou **`false`** falha.

Use `SetParam` para definir dados de parâmetro que não são de cadeia de caracteres no buffer. Use [SetParamString](../../data/oledb/cdynamicparameteraccessor-setparamstring.md) para definir dados de parâmetro de cadeia de caracteres no buffer.

## <a name="cdynamicparameteraccessorsetparamlength"></a><a name="setparamlength"></a>CDynamicParameterAccessor::SetParamLength

Define o comprimento do parâmetro especificado armazenado no buffer.

### <a name="syntax"></a>Sintaxe

```cpp
bool SetParamLength(DBORDINAL nParam,
   DBLENGTH length);
```

#### <a name="parameters"></a>parâmetros

*nParam*<br/>
no O número do parâmetro (deslocamento de 1). O parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem na chamada de procedimento armazenado ou SQL. Consulte [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.

*length*<br/>
no O comprimento em bytes do parâmetro especificado.

### <a name="remarks"></a>Comentários

Retorna **`true`** em caso de êxito ou **`false`** falha.

## <a name="cdynamicparameteraccessorsetparamstatus"></a><a name="setparamstatus"></a>CDynamicParameterAccessor::SetParamStatus

Define o status do parâmetro especificado armazenado no buffer.

### <a name="syntax"></a>Sintaxe

```cpp
bool SetParamStatus(DBORDINAL nParam,
   DBSTATUS status);
```

#### <a name="parameters"></a>parâmetros

*nParam*<br/>
no O número do parâmetro (deslocamento de 1). O parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem na chamada de procedimento armazenado ou SQL. Consulte [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.

*status*<br/>
no O status de DBSTATUS do parâmetro especificado. Para obter informações sobre valores de DBSTATUS, consulte [status](/previous-versions/windows/desktop/ms722617(v=vs.85)) na *referência do programador de OLE DB*ou pesquise por DBSTATUS em OLEDB. h.

### <a name="remarks"></a>Comentários

Retorna **`true`** em caso de êxito ou **`false`** falha.

## <a name="cdynamicparameteraccessorsetparamstring"></a><a name="setparamstring"></a>CDynamicParameterAccessor:: SetParamString

Define os dados de cadeia de caracteres do parâmetro especificado armazenado no buffer.

### <a name="syntax"></a>Sintaxe

```cpp
bool SetParamString(DBORDINAL nParam,
   constCHAR* pString,
   DBSTATUS status = DBSTATUS_S_OK) throw();bool SetParamString(DBORDINAL nParam,
   constWCHAR* pString,
   DBSTATUS status = DBSTATUS_S_OK) throw();
```

#### <a name="parameters"></a>parâmetros

*nParam*<br/>
no O número do parâmetro (deslocamento de 1). O parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem na chamada de procedimento armazenado ou SQL. Consulte [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.

*pString*<br/>
no Um ponteiro para os dados de cadeia de caracteres ANSI (**Char**) ou Unicode (**WCHAR**) do parâmetro especificado. Consulte DBSTATUS em OLEDB. h.

*status*<br/>
no O status de DBSTATUS do parâmetro especificado. Para obter informações sobre valores de DBSTATUS, consulte [status](/previous-versions/windows/desktop/ms722617(v=vs.85)) na *referência do programador de OLE DB*ou pesquise por DBSTATUS em OLEDB. h.

### <a name="remarks"></a>Comentários

Retorna **`true`** em caso de êxito ou **`false`** falha.

`SetParamString`falhará se você tentar definir uma cadeia de caracteres maior que o tamanho máximo especificado para *pString*.

Use `SetParamString` para definir dados de parâmetro de cadeia de caracteres no buffer. Use [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para definir dados de parâmetro que não são de cadeia de caracteres no buffer.

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)<br/>
[Classe CAccessor](../../data/oledb/caccessor-class.md)<br/>
[Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)<br/>
[Classe CManualAccessor](../../data/oledb/cmanualaccessor-class.md)
