---
title: Funções globais de relatório de depuração e de erro
ms.date: 11/04/2016
f1_keywords:
- atlcomcli/ATL::AtlHresultFromLastError
- atlcom/ATL::AtlReportError
- atldef/ATL::AtlThrow
helpviewer_keywords:
- functions [ATL], error reporting
ms.assetid: 11339c02-98cd-428d-b3b9-7deeb155a6a3
ms.openlocfilehash: f7483b7473383958089b0c88d0b3c2645ddc2a4f
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79417708"
---
# <a name="debugging-and-error-reporting-global-functions"></a>Funções globais de relatório de depuração e de erro

Essas funções fornecem recursos úteis de depuração e rastreamento.

|||
|-|-|
|[AtlHresultFromLastError](debugging-and-error-reporting-global-functions.md#atlhresultfromlasterror)|Retorna um `GetLastError` código de erro na forma de um HRESULT.|
|[AtlHresultFromWin32](debugging-and-error-reporting-global-functions.md#atlhresultfromwin32)|Converte um código de erro do Win32 em HRESULT.|
|[AtlReportError](debugging-and-error-reporting-global-functions.md#atlreporterror)|Configura `IErrorInfo` para fornecer detalhes de erro para um cliente.|
|[AtlThrow](debugging-and-error-reporting-global-functions.md#atlthrow)|Lança `CAtlException`.|
|[AtlThrowLastWin32](debugging-and-error-reporting-global-functions.md#atlthrowlastwin32)|Chame essa função para sinalizar um erro com base no resultado da função `GetLastError` do Windows.|

##  <a name="atlhresultfromlasterror"></a>AtlHresultFromLastError

Retorna o valor do código do último erro do thread de chamada na forma de HRESULT.

```
HRESULT AtlHresultFromLastError();
```

### <a name="remarks"></a>Comentários

`AtlHresultFromLastError` chama `GetLastError` para obter o último erro e retorna o erro depois de convertê-lo em um HRESULT usando a macro HRESULT_FROM_WIN32.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcomcli. h

##  <a name="atlhresultfromwin32"></a>AtlHresultFromWin32

Converte um código de erro do Win32 em HRESULT.

```
AtlHresultFromWin32(DWORD error);
```

### <a name="parameters"></a>parâmetros

*error*<br/>
O valor de erro a ser convertido.

### <a name="remarks"></a>Comentários

Converte um código de erro Win32 em um HRESULT, usando a macro HRESULT_FROM_WIN32.

> [!NOTE]
>  Em vez de usar `HRESULT_FROM_WIN32(GetLastError())`, use a função [AtlHresultFromLastError](debugging-and-error-reporting-global-functions.md#atlhresultfromlasterror).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcomcli. h

##  <a name="atlreporterror"></a>AtlReportError

Configura a interface `IErrorInfo` para fornecer informações de erro aos clientes do objeto.

```
HRESULT WINAPI AtlReportError(
    const CLSID& clsid,
    LPCOLESTR lpszDesc,
    const IID& iid = GUID_NULL,
    HRESULT hRes = 0);

HRESULT WINAPI AtlReportError(
    const CLSID& clsid,
    LPCOLESTR lpszDesc,
    DWORD dwHelpID,
    LPCOLESTR lpszHelpFile,
    const IID& iid = GUID_NULL,
    HRESULT hRes = 0);

HRESULT WINAPI AtlReportError(
    const CLSID& clsid,
    LPCSTR lpszDesc,
    const IID& iid = GUID_NULL,
    HRESULT hRes = 0);

HRESULT WINAPI AtlReportError(
    const CLSID& clsid,
    LPCSTR lpszDesc,
    DWORD dwHelpID,
    LPCSTR lpszHelpFile,
    const IID& iid = GUID_NULL,
    HRESULT hRes = 0);

HRESULT WINAPI AtlReportError(
    const CLSID& clsid,
    UINT nID,
    const IID& iid = GUID_NULL,
    HRESULT hRes = 0,
    HINSTANCE hInst = _AtlBaseModule.GetResourceInstance());

HRESULT WINAPI AtlReportError(
    const CLSID& clsid,
    UINT nID,
    DWORD dwHelpID,
    LPCOLESTR lpszHelpFile,
    const IID& iid = GUID_NULL,
    HRESULT hRes = 0,
    HINSTANCE hInst = _AtlBaseModule.GetResourceInstance());
```

### <a name="parameters"></a>parâmetros

*CLSID*<br/>
no O CLSID do objeto que relata o erro.

*lpszDesc*<br/>
no A cadeia de caracteres que descreve o erro. As versões Unicode especificam que *lpszDesc* é do tipo LPCOLESTR; a versão ANSI especifica um tipo de LPCSTR.

*IID*<br/>
no O IID da interface que define o erro ou GUID_NULL se o erro for definido pelo sistema operacional.

*hRes*<br/>
no O HRESULT que você deseja retornar ao chamador.

*nID*<br/>
no O identificador de recurso em que a cadeia de caracteres de descrição do erro é armazenada. Esse valor deve estar entre 0x0200 e 0xFFFF, inclusive. Em compilações de depuração, uma **declaração** resultará se *NID* não indexar uma cadeia de caracteres válida. Em builds de versão, a cadeia de caracteres de descrição do erro será definida como "erro desconhecido".

*dwHelpID*<br/>
no O identificador de contexto da ajuda para o erro.

*lpszHelpFile*<br/>
no O caminho e o nome do arquivo de ajuda que descreve o erro.

*hInst*<br/>
no O identificador para o recurso. Por padrão, esse parâmetro é `__AtlBaseModuleModule::GetResourceInstance`, em que `__AtlBaseModuleModule` é a instância global de [CAtlBaseModule](../../atl/reference/catlbasemodule-class.md) ou uma classe derivada dele.

### <a name="return-value"></a>Valor retornado

Se o parâmetro *hRes* for diferente de zero, retornará o valor de *hRes*. Se *hRes* for zero, as primeiras quatro versões do `AtlReportError` retornarão DISP_E_EXCEPTION. As duas últimas versões retornam o resultado da macro **MAKE_HRESULT (1, FACILITY_ITF,** `nID` **)** .

### <a name="remarks"></a>Comentários

A cadeia de caracteres *lpszDesc* é usada como a descrição de texto do erro. Quando o cliente recebe o *hRes* retornado de `AtlReportError`, o cliente pode acessar a estrutura de `IErrorInfo` para obter detalhes sobre o erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#52](../../atl/codesnippet/cpp/debugging-and-error-reporting-global-functions_1.cpp)]

> [!CAUTION]
>  Não use `AtlReportError` em C++ manipuladores catch. Algumas substituições dessas funções usam as macros de conversão de cadeia de caracteres ATL internamente, que, por sua vez, usam a função `_alloca` internamente. O uso de `AtlReportError` C++ em um manipulador catch pode causar C++ exceções em manipuladores catch.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="atlthrow"></a>AtlThrow

Chame essa função para sinalizar um erro com base em um código de status HRESULT.

```
__declspec(noreturn) inline void AtlThrow(HRESULT hr);
```

### <a name="parameters"></a>parâmetros

*Human*<br/>
Valor de HRESULT padrão.

### <a name="remarks"></a>Comentários

Essa função é usada pelo código ATL e MFC no caso de uma condição de erro. Ele também pode ser chamado de seu próprio código. A implementação padrão dessa função depende da definição do símbolo _ATL_NO_EXCEPTIONS e do tipo de projeto, MFC ou ATL.

Em todos os casos, essa função rastreia o HRESULT para o depurador.

No Visual Studio 2015 atualização 3 e posterior, essa função é atribuída __declspec (noreturn) para evitar avisos SAL falsos.

Se _ATL_NO_EXCEPTIONS não estiver definido em um projeto MFC, essa função lançará um [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou um [COleException](../../mfc/reference/coleexception-class.md) com base no valor do HRESULT.

Se _ATL_NO_EXCEPTIONS não estiver definido em um projeto do ATL, a função lançará um [CAtlException](../../atl/reference/catlexception-class.md).

Se _ATL_NO_EXCEPTIONS for definido, a função causará uma falha de asserção em vez de lançar uma exceção.

Para projetos da ATL, é possível fornecer sua própria implementação dessa função a ser usada pela ATL no caso de uma falha. Para fazer isso, defina sua própria função com a mesma assinatura que `AtlThrow` e #define `AtlThrow` como o nome da sua função. Isso deve ser feito antes de incluir atlexcept. h (o que significa que ele deve ser feito antes de incluir todos os cabeçalhos de ATL, já que atlbase. h inclui atlexcept. h). Atributo sua função `__declspec(noreturn)` para evitar avisos de SAL falsos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#95](../../atl/codesnippet/cpp/debugging-and-error-reporting-global-functions_2.h)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldef. h

##  <a name="atlthrowlastwin32"></a>AtlThrowLastWin32

Chame essa função para sinalizar um erro com base no resultado da função `GetLastError` do Windows.

```
inline void AtlThrowLastWin32();
```

### <a name="remarks"></a>Comentários

Essa função rastreia o resultado de `GetLastError` para o depurador.

Se _ATL_NO_EXCEPTIONS não estiver definido em um projeto MFC, essa função lançará um [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou um [COleException](../../mfc/reference/coleexception-class.md) com base no valor retornado por `GetLastError`.

Se _ATL_NO_EXCEPTIONS não estiver definido em um projeto do ATL, a função lançará um [CAtlException](../../atl/reference/catlexception-class.md).

Se _ATL_NO_EXCEPTIONS for definido, a função causará uma falha de asserção em vez de lançar uma exceção.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldef. h

## <a name="see-also"></a>Confira também

[Funções](../../atl/reference/atl-functions.md)<br/>
[Macros de relatórios de erros e depuração](../../atl/reference/debugging-and-error-reporting-macros.md)
