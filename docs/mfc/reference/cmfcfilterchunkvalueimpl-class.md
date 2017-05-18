---
title: Classe CMFCFilterChunkValueImpl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCFilterChunkValueImpl
- AFXWIN/CMFCFilterChunkValueImpl
- AFXWIN/CMFCFilterChunkValueImpl::CMFCFilterChunkValueImpl
- AFXWIN/CMFCFilterChunkValueImpl::Clear
- AFXWIN/CMFCFilterChunkValueImpl::CopyChunk
- AFXWIN/CMFCFilterChunkValueImpl::CopyFrom
- AFXWIN/CMFCFilterChunkValueImpl::GetChunkGUID
- AFXWIN/CMFCFilterChunkValueImpl::GetChunkPID
- AFXWIN/CMFCFilterChunkValueImpl::GetChunkType
- AFXWIN/CMFCFilterChunkValueImpl::GetString
- AFXWIN/CMFCFilterChunkValueImpl::GetValue
- AFXWIN/CMFCFilterChunkValueImpl::GetValueNoAlloc
- AFXWIN/CMFCFilterChunkValueImpl::IsValid
- AFXWIN/CMFCFilterChunkValueImpl::SetBoolValue
- AFXWIN/CMFCFilterChunkValueImpl::SetDwordValue
- AFXWIN/CMFCFilterChunkValueImpl::SetFileTimeValue
- AFXWIN/CMFCFilterChunkValueImpl::SetInt64Value
- AFXWIN/CMFCFilterChunkValueImpl::SetIntValue
- AFXWIN/CMFCFilterChunkValueImpl::SetLongValue
- AFXWIN/CMFCFilterChunkValueImpl::SetSystemTimeValue
- AFXWIN/CMFCFilterChunkValueImpl::SetTextValue
- AFXWIN/CMFCFilterChunkValueImpl::SetChunk
dev_langs:
- C++
helpviewer_keywords:
- CMFCFilterChunkValueImpl class
ms.assetid: 3c833f23-5b88-4d08-9e09-ca6a8aec88bf
caps.latest.revision: 25
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 8de3cba19a60b8022df96a9edafd13677fa3fecb
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcfilterchunkvalueimpl-class"></a>Classe CMFCFilterChunkValueImpl
Esta é uma classe que simplifica a lógica de par de valores de bloco e de propriedade.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCFilterChunkValueImpl : public ATL::IFilterChunkValue;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCFilterChunkValueImpl:: ~ CMFCFilterChunkValueImpl](#_dtorcmfcfilterchunkvalueimpl)|Destructs o objeto.|  
|[CMFCFilterChunkValueImpl::CMFCFilterChunkValueImpl](#cmfcfilterchunkvalueimpl)|Constrói o objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCFilterChunkValueImpl::Clear](#clear)|Limpa o ChunkValue.|  
|[CMFCFilterChunkValueImpl::CopyChunk](#copychunk)|Copia essa parte de uma estrutura que descreve as características de um bloco.|  
|[CMFCFilterChunkValueImpl::CopyFrom](#copyfrom)|Inicializa este valor de parte de outro valor.|  
|[CMFCFilterChunkValueImpl::GetChunkGUID](#getchunkguid)|Recupera a parte GUID.|  
|[CMFCFilterChunkValueImpl::GetChunkPID](#getchunkpid)|Recupera a parte PID (ID de propriedade).|  
|[CMFCFilterChunkValueImpl::GetChunkType](#getchunktype)|Obtém parte tipo.|  
|[CMFCFilterChunkValueImpl::GetString](#getstring)|Recupera o valor de cadeia de caracteres.|  
|[CMFCFilterChunkValueImpl::GetValue](#getvalue)|Recupera o valor como uma propvariant alocado.|  
|[CMFCFilterChunkValueImpl::GetValueNoAlloc](#getvaluenoalloc)|Valor retorna não alocado (valor interno).|  
|[CMFCFilterChunkValueImpl::IsValid](#isvalid)|Verifica se o valor dessa propriedade é válido ou não.|  
|[CMFCFilterChunkValueImpl::SetBoolValue](#setboolvalue)|Sobrecarregado. Define a propriedade pela chave para um valor booleano.|  
|[CMFCFilterChunkValueImpl::SetDwordValue](#setdwordvalue)|Define a propriedade pela chave para uma DWORD.|  
|[CMFCFilterChunkValueImpl::SetFileTimeValue](#setfiletimevalue)|Define a propriedade pela chave para um filetime.|  
|[CMFCFilterChunkValueImpl::SetInt64Value](#setint64value)|Define a propriedade pela chave para int64.|  
|[CMFCFilterChunkValueImpl::SetIntValue](#setintvalue)|Define a propriedade pela chave para um inteiro.|  
|[CMFCFilterChunkValueImpl::SetLongValue](#setlongvalue)|Define a propriedade pela chave para um longo.|  
|[CMFCFilterChunkValueImpl::SetSystemTimeValue](#setsystemtimevalue)|Define a propriedade pela chave para um SystemTime.|  
|[CMFCFilterChunkValueImpl::SetTextValue](#settextvalue)|Define a propriedade pela chave para uma cadeia de caracteres Unicode.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCFilterChunkValueImpl::SetChunk](#setchunk)|Uma função auxiliar que define as propriedades comuns do bloco.|  
  
## <a name="remarks"></a>Comentários  
 Para usar, simplesmente crie uma classe CMFCFilterChunkValueImpl do tipo certo  
  
 Exemplo:  
  
 Bloco de CMFCFilterChunkValueImpl;  
  
 hr = parte. SetBoolValue(PKEY_IsAttachment, true);  
  
 ou  
  
 hr = parte. SetFileTimeValue (PKEY_ItemDate, ftLastModified);  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ATL::IFilterChunkValue`  
  
 [CMFCFilterChunkValueImpl](../../mfc/reference/cmfcfilterchunkvalueimpl-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="clear"></a>CMFCFilterChunkValueImpl::Clear  
 Limpa o ChunkValue.  
  
```  
void Clear();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="cmfcfilterchunkvalueimpl"></a>CMFCFilterChunkValueImpl::CMFCFilterChunkValueImpl  
 Constrói o objeto.  
  
```  
CMFCFilterChunkValueImpl();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="_dtorcmfcfilterchunkvalueimpl"></a>CMFCFilterChunkValueImpl:: ~ CMFCFilterChunkValueImpl  
 Destructs o objeto.  
  
```  
virtual ~CMFCFilterChunkValueImpl();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="copychunk"></a>CMFCFilterChunkValueImpl::CopyChunk  
 Copia essa parte de uma estrutura que descreve as características de um bloco.  
  
```  
HRESULT CopyChunk(STAT_CHUNK* pStatChunk);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pStatChunk`  
 Um ponteiro para o valor de destino que descrevem as características da parte.  
  
### <a name="return-value"></a>Valor de retorno  
 S_OK se for bem-sucedida; Caso contrário, um código de erro.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="copyfrom"></a>CMFCFilterChunkValueImpl::CopyFrom  
 Inicializa este valor de parte de outro valor.  
  
```  
void CopyFrom (IFilterChunkValue* pValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pValue`  
 Especifica o valor de origem para copiar de.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getchunkguid"></a>CMFCFilterChunkValueImpl::GetChunkGUID  
 Recupera a parte GUID.  
  
```  
REFGUID GetChunkGUID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a um GUID que identifica o fragmento.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getchunkpid"></a>CMFCFilterChunkValueImpl::GetChunkPID  
 Recupera a parte PID (ID de propriedade).  
  
```  
DWORD GetChunkPID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor DWORD que contém a ID da propriedade.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getchunktype"></a>CMFCFilterChunkValueImpl::GetChunkType  
 Recupera o tipo de bloco.  
  
```  
CHUNKSTATE GetChunkType() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor enumerado de CHUNKSTATE, que especifica se o bloco atual é uma propriedade do tipo texto ou uma propriedade de tipo de valor.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getstring"></a>CMFCFilterChunkValueImpl::GetString  
 Recupera o valor de cadeia de caracteres.  
  
```  
CString &GetString();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia de caracteres que contém o valor de bloco.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getvalue"></a>CMFCFilterChunkValueImpl::GetValue  
 Recupera o valor como uma propvariant alocado.  
  
```  
HRESULT GetValue(PROPVARIANT** ppPropVariant);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppPropVariant`  
 Quando a função retornar, este parâmetro contém o valor de bloco.  
  
### <a name="return-value"></a>Valor de retorno  
 S_OK se PROPVARIANT foi alocada com êxito e o valor de bloco foi copiado com êxito para `ppPropVariant`; caso contrário, um código de erro.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getvaluenoalloc"></a>CMFCFilterChunkValueImpl::GetValueNoAlloc  
 Retorna o valor alocado (valor interno).  
  
```  
PROPVARIANT GetValueNoAlloc ();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor atual do fragmento.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="isvalid"></a>CMFCFilterChunkValueImpl::IsValid  
 Verifica se o valor dessa propriedade é válido ou não.  
  
```  
BOOL IsValid() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o valor atual do fragmento é válido. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setboolvalue"></a>CMFCFilterChunkValueImpl::SetBoolValue  
 Sobrecarregado. Define a propriedade pela chave para um valor booleano.  
  
```  
HRESULT SetBoolValue(
    REFPROPERTYKEY pkey,  
    BOOL bVal,  
    CHUNKSTATE chunkType = CHUNK_VALUE,  
    LCID locale = 0,  
    DWORD cwcLenSource = 0,  
    DWORD cwcStartSource = 0,  
    CHUNK_BREAKTYPE chunkBreakType = CHUNK_NO_BREAK);

 
HRESULT SetBoolValue(
    REFPROPERTYKEY pkey,  
    VARIANT_BOOL bVal,  
    CHUNKSTATE chunkType = CHUNK_VALUE,  
    LCID locale = 0,  
    DWORD cwcLenSource = 0,  
    DWORD cwcStartSource = 0,  
    CHUNK_BREAKTYPE chunkBreakType = CHUNK_NO_BREAK);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pkey`  
 Especifica uma chave de propriedade.  
  
 `bVal`  
 Especifica o valor de bloco para definir.  
  
 `chunkType`  
 Sinalizadores de indicam se essa parte contém um tipo de texto ou uma propriedade de tipo de valor. Os valores de sinalizador são tirados da enumeração CHUNKSTATE.  
  
 `locale`  
 O idioma e um subidioma associadas a um bloco de texto. Localidade do bloco é usada por indexadores de documento para executar adequada quebra de texto. Se a parte é o tipo de texto nem um tipo de valor com tipo de dados VT_LPWSTR, VT_LPSTR ou VT_BSTR, este campo será ignorado.  
  
 `cwcLenSource`  
 O comprimento em caracteres do texto de origem da qual o bloco atual foi derivado. Um valor zero significa correspondência de caractere por caractere entre o texto de origem e o texto derivado. Um valor diferente de zero significa que nenhuma correspondência tal direta existe.  
  
 `cwcStartSource`  
 O deslocamento do qual o texto de origem para uma parte derivada inicia no bloco de código-fonte.  
  
 `chunkBreakType`  
 O tipo de intervalo que separa a parte anterior do bloco atual. Os valores são originados da enumeração CHUNK_BREAKTYPE.  
  
### <a name="return-value"></a>Valor de retorno  
 S_OK se for bem-sucedida; Caso contrário, um código de erro.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setchunk"></a>CMFCFilterChunkValueImpl::SetChunk  
 Uma função auxiliar que define as propriedades comuns do bloco.  
  
```  
HRESULT SetChunk(
    REFPROPERTYKEY pkey,  
    CHUNKSTATE chunkType=CHUNK_VALUE,  
    LCID locale=0,  
    DWORD cwcLenSource=0,  
    DWORD cwcStartSource=0,  
    CHUNK_BREAKTYPE chunkBreakType=CHUNK_NO_BREAK);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pkey`  
 Especifica uma chave de propriedade.  
  
 `chunkType`  
 Sinalizadores de indicam se essa parte contém um tipo de texto ou uma propriedade de tipo de valor. Os valores de sinalizador são tirados da enumeração CHUNKSTATE.  
  
 `locale`  
 O idioma e um subidioma associadas a um bloco de texto. Localidade do bloco é usada por indexadores de documento para executar adequada quebra de texto. Se a parte é o tipo de texto nem um tipo de valor com tipo de dados VT_LPWSTR, VT_LPSTR ou VT_BSTR, este campo será ignorado.  
  
 `cwcLenSource`  
 O comprimento em caracteres do texto de origem da qual o bloco atual foi derivado. Um valor zero significa correspondência de caractere por caractere entre o texto de origem e o texto derivado. Um valor diferente de zero significa que nenhuma correspondência tal direta existe.  
  
 `cwcStartSource`  
 O deslocamento do qual o texto de origem para uma parte derivada inicia no bloco de código-fonte.  
  
 `chunkBreakType`  
 O tipo de intervalo que separa a parte anterior do bloco atual. Os valores são originados da enumeração CHUNK_BREAKTYPE.  
  
### <a name="return-value"></a>Valor de retorno  
 S_OK se for bem-sucedida; Caso contrário, código de erro.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setdwordvalue"></a>CMFCFilterChunkValueImpl::SetDwordValue  
 Defina a propriedade pela chave para uma DWORD.  
  
```  
HRESULT SetDwordValue(
    REFPROPERTYKEY pkey,  
    DWORD dwVal,  
    CHUNKSTATE chunkType = CHUNK_VALUE,  
    LCID locale = 0,  
    DWORD cwcLenSource = 0,  
    DWORD cwcStartSource = 0,  
    CHUNK_BREAKTYPE chunkBreakType = CHUNK_NO_BREAK);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pkey`  
 Especifica uma chave de propriedade.  
  
 `dwVal`  
 Especifica o valor de bloco para definir.  
  
 `chunkType`  
 Sinalizadores de indicam se essa parte contém um tipo de texto ou uma propriedade de tipo de valor. Os valores de sinalizador são tirados da enumeração CHUNKSTATE.  
  
 `locale`  
 O idioma e um subidioma associadas a um bloco de texto. Localidade do bloco é usada por indexadores de documento para executar adequada quebra de texto. Se a parte é o tipo de texto nem um tipo de valor com tipo de dados VT_LPWSTR, VT_LPSTR ou VT_BSTR, este campo será ignorado.  
  
 `cwcLenSource`  
 O comprimento em caracteres do texto de origem da qual o bloco atual foi derivado. Um valor zero significa correspondência de caractere por caractere entre o texto de origem e o texto derivado. Um valor diferente de zero significa que nenhuma correspondência tal direta existe.  
  
 `cwcStartSource`  
 O deslocamento do qual o texto de origem para uma parte derivada inicia no bloco de código-fonte.  
  
 `chunkBreakType`  
 O tipo de intervalo que separa a parte anterior do bloco atual. Os valores são originados da enumeração CHUNK_BREAKTYPE.  
  
### <a name="return-value"></a>Valor de retorno  
 S_OK se for bem-sucedida; Caso contrário, um código de erro.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setfiletimevalue"></a>CMFCFilterChunkValueImpl::SetFileTimeValue  
 Defina a propriedade pela chave para um filetime.  
  
```  
HRESULT SetFileTimeValue(
    REFPROPERTYKEY pkey,  
    FILETIME dtVal,  
    CHUNKSTATE chunkType = CHUNK_VALUE,  
    LCID locale = 0,  
    DWORD cwcLenSource = 0,  
    DWORD cwcStartSource = 0,  
    CHUNK_BREAKTYPE chunkBreakType = CHUNK_NO_BREAK);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pkey`  
 Especifica uma chave de propriedade.  
  
 `dtVal`  
 Especifica o valor de bloco para definir.  
  
 `chunkType`  
 Sinalizadores de indicam se essa parte contém um tipo de texto ou uma propriedade de tipo de valor. Os valores de sinalizador são tirados da enumeração CHUNKSTATE.  
  
 `locale`  
 O idioma e um subidioma associadas a um bloco de texto. Localidade do bloco é usada por indexadores de documento para executar adequada quebra de texto. Se a parte é o tipo de texto nem um tipo de valor com tipo de dados VT_LPWSTR, VT_LPSTR ou VT_BSTR, este campo será ignorado.  
  
 `cwcLenSource`  
 O comprimento em caracteres do texto de origem da qual o bloco atual foi derivado. Um valor zero significa correspondência de caractere por caractere entre o texto de origem e o texto derivado. Um valor diferente de zero significa que nenhuma correspondência tal direta existe.  
  
 `cwcStartSource`  
 O deslocamento do qual o texto de origem para uma parte derivada inicia no bloco de código-fonte.  
  
 `chunkBreakType`  
 O tipo de intervalo que separa a parte anterior do bloco atual. Os valores são originados da enumeração CHUNK_BREAKTYPE.  
  
### <a name="return-value"></a>Valor de retorno  
 S_OK se for bem-sucedida; Caso contrário, um código de erro.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setint64value"></a>CMFCFilterChunkValueImpl::SetInt64Value  
 Defina a propriedade pela chave para int64.  
  
```  
HRESULT SetInt64Value(
    REFPROPERTYKEY pkey,  
    __int64 nVal,  
    CHUNKSTATE chunkType = CHUNK_VALUE,  
    LCID locale = 0,  
    DWORD cwcLenSource = 0,  
    DWORD cwcStartSource = 0,  
    CHUNK_BREAKTYPE chunkBreakType = CHUNK_NO_BREAK);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pkey`  
 Especifica uma chave de propriedade.  
  
 `nVal`  
 Especifica o valor de bloco para definir.  
  
 `chunkType`  
 Sinalizadores de indicam se essa parte contém um tipo de texto ou uma propriedade de tipo de valor. Os valores de sinalizador são tirados da enumeração CHUNKSTATE.  
  
 `locale`  
 O idioma e um subidioma associadas a um bloco de texto. Localidade do bloco é usada por indexadores de documento para executar adequada quebra de texto. Se a parte é o tipo de texto nem um tipo de valor com tipo de dados VT_LPWSTR, VT_LPSTR ou VT_BSTR, este campo será ignorado.  
  
 `cwcLenSource`  
 O comprimento em caracteres do texto de origem da qual o bloco atual foi derivado. Um valor zero significa correspondência de caractere por caractere entre o texto de origem e o texto derivado. Um valor diferente de zero significa que nenhuma correspondência tal direta existe.  
  
 `cwcStartSource`  
 O deslocamento do qual o texto de origem para uma parte derivada inicia no bloco de código-fonte.  
  
 `chunkBreakType`  
 O tipo de intervalo que separa a parte anterior do bloco atual. Os valores são originados da enumeração CHUNK_BREAKTYPE.  
  
### <a name="return-value"></a>Valor de retorno  
 S_OK se for bem-sucedida; Caso contrário, um código de erro.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setintvalue"></a>CMFCFilterChunkValueImpl::SetIntValue  
 Defina a propriedade pela chave para um inteiro.  
  
```  
HRESULT SetIntValue(
    REFPROPERTYKEY pkey,  
    int nVal,  
    CHUNKSTATE chunkType = CHUNK_VALUE,  
    LCID locale = 0,  
    DWORD cwcLenSource = 0,  
    DWORD cwcStartSource = 0,  
    CHUNK_BREAKTYPE chunkBreakType = CHUNK_NO_BREAK);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pkey`  
 Especifica uma chave de propriedade.  
  
 `nVal`  
 Especifica o valor de bloco para definir.  
  
 `chunkType`  
 Sinalizadores de indicam se essa parte contém um tipo de texto ou uma propriedade de tipo de valor. Os valores de sinalizador são tirados da enumeração CHUNKSTATE.  
  
 `locale`  
 O idioma e um subidioma associadas a um bloco de texto. Localidade do bloco é usada por indexadores de documento para executar adequada quebra de texto. Se a parte é o tipo de texto nem um tipo de valor com tipo de dados VT_LPWSTR, VT_LPSTR ou VT_BSTR, este campo será ignorado.  
  
 `cwcLenSource`  
 O comprimento em caracteres do texto de origem da qual o bloco atual foi derivado. Um valor zero significa correspondência de caractere por caractere entre o texto de origem e o texto derivado. Um valor diferente de zero significa que nenhuma correspondência tal direta existe.  
  
 `cwcStartSource`  
 O deslocamento do qual o texto de origem para uma parte derivada inicia no bloco de código-fonte.  
  
 `chunkBreakType`  
 O tipo de intervalo que separa a parte anterior do bloco atual. Os valores são originados da enumeração CHUNK_BREAKTYPE.  
  
### <a name="return-value"></a>Valor de retorno  
 S_OK se for bem-sucedida; Caso contrário, um código de erro.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setlongvalue"></a>CMFCFilterChunkValueImpl::SetLongValue  
 Defina a propriedade pela chave para um longo.  
  
```  
HRESULT SetLongValue(
    REFPROPERTYKEY pkey,  
    long lVal,  
    CHUNKSTATE chunkType = CHUNK_VALUE,  
    LCID locale = 0,  
    DWORD cwcLenSource = 0,  
    DWORD cwcStartSource = 0,  
    CHUNK_BREAKTYPE chunkBreakType = CHUNK_NO_BREAK);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pkey`  
 Especifica uma chave de propriedade.  
  
 `lVal`  
 Especifica o valor de bloco para definir.  
  
 `chunkType`  
 Sinalizadores de indicam se essa parte contém um tipo de texto ou uma propriedade de tipo de valor. Os valores de sinalizador são tirados da enumeração CHUNKSTATE.  
  
 `locale`  
 O idioma e um subidioma associadas a um bloco de texto. Localidade do bloco é usada por indexadores de documento para executar adequada quebra de texto. Se a parte é o tipo de texto nem um tipo de valor com tipo de dados VT_LPWSTR, VT_LPSTR ou VT_BSTR, este campo será ignorado.  
  
 `cwcLenSource`  
 O comprimento em caracteres do texto de origem da qual o bloco atual foi derivado. Um valor zero significa correspondência de caractere por caractere entre o texto de origem e o texto derivado. Um valor diferente de zero significa que nenhuma correspondência tal direta existe.  
  
 `cwcStartSource`  
 O deslocamento do qual o texto de origem para uma parte derivada inicia no bloco de código-fonte.  
  
 `chunkBreakType`  
 O tipo de intervalo que separa a parte anterior do bloco atual. Os valores são originados da enumeração CHUNK_BREAKTYPE.  
  
### <a name="return-value"></a>Valor de retorno  
 S_OK se for bem-sucedida; Caso contrário, um código de erro.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setsystemtimevalue"></a>CMFCFilterChunkValueImpl::SetSystemTimeValue  
 Define a propriedade pela chave para um SystemTime.  
  
```  
HRESULT SetSystemTimeValue(
    REFPROPERTYKEY pkey,  
    const SYSTEMTIME& systemTime,  
    CHUNKSTATE chunkType = CHUNK_VALUE,  
    LCID locale=0,  
    DWORD cwcLenSource=0,  
    DWORD cwcStartSource=0,  
    CHUNK_BREAKTYPE chunkBreakType=CHUNK_NO_BREAK);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pkey`  
 Especifica uma chave de propriedade.  
  
 `systemTime`  
 Especifica o valor de bloco para definir.  
  
 `chunkType`  
 Sinalizadores de indicam se essa parte contém um tipo de texto ou uma propriedade de tipo de valor. Os valores de sinalizador são tirados da enumeração CHUNKSTATE.  
  
 `locale`  
 O idioma e um subidioma associadas a um bloco de texto. Localidade do bloco é usada por indexadores de documento para executar adequada quebra de texto. Se a parte é o tipo de texto nem um tipo de valor com tipo de dados VT_LPWSTR, VT_LPSTR ou VT_BSTR, este campo será ignorado.  
  
 `cwcLenSource`  
 O comprimento em caracteres do texto de origem da qual o bloco atual foi derivado. Um valor zero significa correspondência de caractere por caractere entre o texto de origem e o texto derivado. Um valor diferente de zero significa que nenhuma correspondência tal direta existe.  
  
 `cwcStartSource`  
 O deslocamento do qual o texto de origem para uma parte derivada inicia no bloco de código-fonte.  
  
 `chunkBreakType`  
 O tipo de intervalo que separa a parte anterior do bloco atual. Os valores são originados da enumeração CHUNK_BREAKTYPE.  
  
### <a name="return-value"></a>Valor de retorno  
 S_OK se for bem-sucedida; Caso contrário, um código de erro.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="settextvalue"></a>CMFCFilterChunkValueImpl::SetTextValue  
 Define a propriedade pela chave para uma cadeia de caracteres Unicode.  
  
```  
HRESULT SetTextValue(
    REFPROPERTYKEY pkey,  
    LPCTSTR pszValue,  
    CHUNKSTATE chunkType = CHUNK_VALUE,  
    LCID locale = 0,  
    DWORD cwcLenSource = 0,  
    DWORD cwcStartSource = 0,  
    CHUNK_BREAKTYPE chunkBreakType = CHUNK_NO_BREAK);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pkey`  
 Especifica uma chave de propriedade.  
  
 `pszValue`  
 Especifica o valor de bloco para definir.  
  
 `chunkType`  
 Sinalizadores de indicam se essa parte contém um tipo de texto ou uma propriedade de tipo de valor. Os valores de sinalizador são tirados da enumeração CHUNKSTATE.  
  
 `locale`  
 O idioma e um subidioma associadas a um bloco de texto. Localidade do bloco é usada por indexadores de documento para executar adequada quebra de texto. Se a parte é o tipo de texto nem um tipo de valor com tipo de dados VT_LPWSTR, VT_LPSTR ou VT_BSTR, este campo será ignorado.  
  
 `cwcLenSource`  
 O comprimento em caracteres do texto de origem da qual o bloco atual foi derivado. Um valor zero significa correspondência de caractere por caractere entre o texto de origem e o texto derivado. Um valor diferente de zero significa que nenhuma correspondência tal direta existe.  
  
 `cwcStartSource`  
 O deslocamento do qual o texto de origem para uma parte derivada inicia no bloco de código-fonte.  
  
 `chunkBreakType`  
 O tipo de intervalo que separa a parte anterior do bloco atual. Os valores são originados da enumeração CHUNK_BREAKTYPE.  
  
### <a name="return-value"></a>Valor de retorno  
 S_OK se for bem-sucedida; Caso contrário, um código de erro.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

