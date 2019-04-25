---
title: Funções globais de relatório de erros e depuração
ms.date: 11/04/2016
f1_keywords:
- atlcomcli/ATL::AtlHresultFromLastError
- atlcom/ATL::AtlReportError
- atldef/ATL::AtlThrow
helpviewer_keywords:
- functions [ATL], error reporting
ms.assetid: 11339c02-98cd-428d-b3b9-7deeb155a6a3
ms.openlocfilehash: f7483b7473383958089b0c88d0b3c2645ddc2a4f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62276648"
---
# <a name="debugging-and-error-reporting-global-functions"></a>Funções globais de relatório de erros e depuração

Essas funções fornecem recursos úteis de depuração e rastreamento.

|||
|-|-|
|[AtlHresultFromLastError](debugging-and-error-reporting-global-functions.md#atlhresultfromlasterror)|Retorna um `GetLastError` código de erro na forma de um HRESULT.|
|[AtlHresultFromWin32](debugging-and-error-reporting-global-functions.md#atlhresultfromwin32)|Converte um código de erro do Win32 em HRESULT.|
|[AtlReportError](debugging-and-error-reporting-global-functions.md#atlreporterror)|Configura `IErrorInfo` para fornecer detalhes do erro para um cliente.|
|[AtlThrow](debugging-and-error-reporting-global-functions.md#atlthrow)|Gera uma `CAtlException`.|
|[AtlThrowLastWin32](debugging-and-error-reporting-global-functions.md#atlthrowlastwin32)|Chame essa função para sinalizar um erro com base no resultado da função `GetLastError` do Windows.|

##  <a name="atlhresultfromlasterror"></a>  AtlHresultFromLastError

Retorna o valor do código do último erro do thread de chamada na forma de HRESULT.

```
HRESULT AtlHresultFromLastError();
```

### <a name="remarks"></a>Comentários

`AtlHresultFromLastError` chamadas `GetLastError` para obter o último erro e retornará o erro após convertê-la para um HRESULT usando a macro HRESULT_FROM_WIN32.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcomcli. h

##  <a name="atlhresultfromwin32"></a>  AtlHresultFromWin32

Converte um código de erro do Win32 em HRESULT.

```
AtlHresultFromWin32(DWORD error);
```

### <a name="parameters"></a>Parâmetros

*error*<br/>
O valor de erro a ser convertido.

### <a name="remarks"></a>Comentários

Converte um código de erro do Win32 em HRESULT, usando a macro HRESULT_FROM_WIN32.

> [!NOTE]
>  Em vez de usar `HRESULT_FROM_WIN32(GetLastError())`, use a função [AtlHresultFromLastError](debugging-and-error-reporting-global-functions.md#atlhresultfromlasterror).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcomcli. h

##  <a name="atlreporterror"></a>  AtlReportError

Configura o `IErrorInfo` interface para fornecer informações de erro para os clientes do objeto.

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

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
[in] O CLSID do objeto relatando o erro.

*lpszDesc*<br/>
[in] A cadeia de caracteres que descreve o erro. As versões Unicode especificam que *lpszDesc* é do tipo LPCOLESTR; a versão ANSI Especifica um tipo de LPCSTR.

*iid*<br/>
[in] O IID da interface definindo o erro ou GUID_NULL se o erro é definido pelo sistema operacional.

*hRes*<br/>
[in] O HRESULT que você deseja é retornado ao chamador.

*nID*<br/>
[in] O identificador de recurso em que a cadeia de caracteres de descrição de erro é armazenada. Esse valor deve ficar entre 0x0200 e 0xFFFF, inclusive. Em compilações de depuração, uma **ASSERT** resultará se *nID* não indexa uma cadeia de caracteres válida. Em compilações de versão, a cadeia de caracteres de descrição de erro será definida como "Erro desconhecido".

*dwHelpID*<br/>
[in] O identificador de contexto de ajuda para o erro.

*lpszHelpFile*<br/>
[in] O caminho e nome do arquivo de Ajuda que descreve o erro.

*hInst*<br/>
[in] O identificador para o recurso. Por padrão, esse parâmetro é `__AtlBaseModuleModule::GetResourceInstance`, onde `__AtlBaseModuleModule` é a instância global do [CAtlBaseModule](../../atl/reference/catlbasemodule-class.md) ou a uma classe derivada.

### <a name="return-value"></a>Valor de retorno

Se o *hRes* parâmetro é diferente de zero, retorna o valor de *hRes*. Se *hRes* for zero, as quatro primeiras versões do `AtlReportError` retorna DISP_E_EXCEPTION. As duas últimas versões retornam o resultado da macro **MAKE_HRESULT (1, FACILITY_ITF,** `nID` **)**.

### <a name="remarks"></a>Comentários

A cadeia de caracteres *lpszDesc* é usado como a descrição de texto do erro. Quando o cliente recebe o *hRes* retornar do `AtlReportError`, o cliente pode acessar o `IErrorInfo` estrutura para obter detalhes sobre o erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#52](../../atl/codesnippet/cpp/debugging-and-error-reporting-global-functions_1.cpp)]

> [!CAUTION]
>  Não use `AtlReportError` em C++ manipuladores catch. Algumas substituições dessas funções usam as macros de conversão de cadeia de caracteres ATL internamente, que por sua vez de usar o `_alloca` funcionam internamente. Usando `AtlReportError` em um catch de C++ manipulador pode causar exceções em manipuladores catch de C++.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="atlthrow"></a>  AtlThrow

Chame essa função para sinalizar um erro com base em um código de status HRESULT.

```
__declspec(noreturn) inline void AtlThrow(HRESULT hr);
```

### <a name="parameters"></a>Parâmetros

*hr*<br/>
Valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Essa função é usada pelo código ATL e MFC em caso de uma condição de erro. Ele também pode ser chamado de seu próprio código. A implementação padrão dessa função depende a definição de _ATL_NO_EXCEPTIONS o símbolo e o tipo de projeto, MFC ou ATL.

Em todos os casos, essa função rastreia o HRESULT para o depurador.

No Visual Studio 2015 atualização 3 e posterior, essa função é atribuída __declspec(noreturn) para evitar avisos de SAL artificiais.

Se _ATL_NO_EXCEPTIONS não estiver definido em um projeto MFC, essa função gera uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou um [COleException](../../mfc/reference/coleexception-class.md) com base no valor de HRESULT.

Se _ATL_NO_EXCEPTIONS não está definido em um projeto ATL, a função gerará um [CAtlException](../../atl/reference/catlexception-class.md).

Se _ATL_NO_EXCEPTIONS for definida, a função faz com que uma falha de asserção em vez de gerar uma exceção.

Para projetos ATL, é possível fornecer sua própria implementação dessa função a ser usado pelo ATL em caso de falha. Para fazer isso, defina sua própria função com a mesma assinatura `AtlThrow` e #define `AtlThrow` para ser o nome da sua função. Isso deve ser feito antes de incluir atlexcept.h (o que significa que ele deve ser feito antes de incluir cabeçalhos ATL pois atlbase. h inclui atlexcept.h). Atributo sua função `__declspec(noreturn)` para evitar avisos de SAL artificiais.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#95](../../atl/codesnippet/cpp/debugging-and-error-reporting-global-functions_2.h)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldef.h

##  <a name="atlthrowlastwin32"></a>  AtlThrowLastWin32

Chame essa função para sinalizar um erro com base no resultado da função `GetLastError` do Windows.

```
inline void AtlThrowLastWin32();
```

### <a name="remarks"></a>Comentários

Essa função rastreia o resultado de `GetLastError` ao depurador.

Se _ATL_NO_EXCEPTIONS não estiver definido em um projeto MFC, essa função gera uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou um [COleException](../../mfc/reference/coleexception-class.md) com base no valor retornado por `GetLastError`.

Se _ATL_NO_EXCEPTIONS não está definido em um projeto ATL, a função gerará um [CAtlException](../../atl/reference/catlexception-class.md).

Se _ATL_NO_EXCEPTIONS for definida, a função faz com que uma falha de asserção em vez de gerar uma exceção.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldef.h

## <a name="see-also"></a>Consulte também

[Funções](../../atl/reference/atl-functions.md)<br/>
[Macros de relatórios de erros e depuração](../../atl/reference/debugging-and-error-reporting-macros.md)
