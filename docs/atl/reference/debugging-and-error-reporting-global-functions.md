---
title: Depuração e verificação de funções globais de relatórios
ms.date: 11/04/2016
f1_keywords:
- atlcomcli/ATL::AtlHresultFromLastError
- atlcom/ATL::AtlReportError
- atldef/ATL::AtlThrow
helpviewer_keywords:
- functions [ATL], error reporting
ms.assetid: 11339c02-98cd-428d-b3b9-7deeb155a6a3
ms.openlocfilehash: f7636b1f4e13340b223edd8c63c39bbeb21c8bd0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330201"
---
# <a name="debugging-and-error-reporting-global-functions"></a>Depuração e verificação de funções globais de relatórios

Essas funções fornecem instalações úteis de depuração e rastreamento.

|||
|-|-|
|[AtlHresultFromLastError](debugging-and-error-reporting-global-functions.md#atlhresultfromlasterror)|Retorna `GetLastError` um código de erro na forma de um HRESULT.|
|[AtlHresultFromWin32](debugging-and-error-reporting-global-functions.md#atlhresultfromwin32)|Converte um código de erro do Win32 em HRESULT.|
|[AtlReportError](debugging-and-error-reporting-global-functions.md#atlreporterror)|Configura-se `IErrorInfo` para fornecer detalhes de erro a um cliente.|
|[AtlThrow](debugging-and-error-reporting-global-functions.md#atlthrow)|Lança `CAtlException`.|
|[AtlThrowLastWin32](debugging-and-error-reporting-global-functions.md#atlthrowlastwin32)|Chame essa função para sinalizar um erro com base no resultado da função `GetLastError` do Windows.|

## <a name="atlhresultfromlasterror"></a><a name="atlhresultfromlasterror"></a>AtlHresultFromLastError

Retorna o valor do código do último erro do thread de chamada na forma de HRESULT.

```
HRESULT AtlHresultFromLastError();
```

### <a name="remarks"></a>Comentários

`AtlHresultFromLastError`chamadas `GetLastError` para obter o último erro e retorna o erro depois de convertê-lo em um HRESULT usando a HRESULT_FROM_WIN32 macro.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcomcli.h

## <a name="atlhresultfromwin32"></a><a name="atlhresultfromwin32"></a>AtlHresultFromWin32

Converte um código de erro do Win32 em HRESULT.

```
AtlHresultFromWin32(DWORD error);
```

### <a name="parameters"></a>Parâmetros

*error*<br/>
O valor de erro para converter.

### <a name="remarks"></a>Comentários

Converte um código de erro Win32 em um HRESULT, usando a HRESULT_FROM_WIN32 de macro.

> [!NOTE]
> Em vez `HRESULT_FROM_WIN32(GetLastError())`de usar, use a função [AtlHresultFromLastError](debugging-and-error-reporting-global-functions.md#atlhresultfromlasterror).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcomcli.h

## <a name="atlreporterror"></a><a name="atlreporterror"></a>Atlreporterror

Configura a `IErrorInfo` interface para fornecer informações de erro aos clientes do objeto.

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
[em] O CLSID do objeto que relata o erro.

*Lpszdesc*<br/>
[em] A seqüência descrevendo o erro. As versões unicode especificam que *o lpszDesc* é do tipo LPCOLESTR; a versão ANSI especifica um tipo de LPCSTR.

*Iid*<br/>
[em] O IID da interface que define o erro ou GUID_NULL se o erro for definido pelo sistema operacional.

*Hres*<br/>
[em] O HRESULT que você deseja retornou ao chamador.

*nID*<br/>
[em] O identificador de recursos onde a seqüência de descrição de erro é armazenada. Esse valor deve ficar entre 0x0200 e 0xFFFF, inclusive. Nas compilações de depuração, um **ASSERT** resultará se *o nID* não indexar uma seqüência de string válida. Nas compilações de versão, a seqüência de descrição de erro será definida como "Erro desconhecido".

*dwHelpID*<br/>
[em] O identificador de contexto de ajuda para o erro.

*lpszHelpFile*<br/>
[em] O caminho e o nome do arquivo de ajuda descrevendo o erro.

*Hinst*<br/>
[em] A alça do recurso. Por padrão, este `__AtlBaseModuleModule::GetResourceInstance`parâmetro `__AtlBaseModuleModule` é , onde está a instância global do [CAtlBaseModule](../../atl/reference/catlbasemodule-class.md) ou uma classe derivada dele.

### <a name="return-value"></a>Valor retornado

Se o parâmetro *hRes* não for zero, reaverá o valor de *hRes*. Se *hRes* é zero, então `AtlReportError` as quatro primeiras versões de retorno DISP_E_EXCEPTION. As duas últimas versões retornam o resultado do **MAKE_HRESULT macro( 1,** `nID` **FACILITY_ITF)**.

### <a name="remarks"></a>Comentários

O *lpszDesc* de string é usado como a descrição de texto do erro. Quando o cliente recebe os *hRes* de `AtlReportError`que `IErrorInfo` você retorna, o cliente pode acessar a estrutura para obter detalhes sobre o erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#52](../../atl/codesnippet/cpp/debugging-and-error-reporting-global-functions_1.cpp)]

> [!CAUTION]
> Não use `AtlReportError` em manipuladores de captura C++.. Algumas substituições dessas funções usam internamente as macros de conversão `_alloca` de string ATL, que por sua vez usam a função internamente. O `AtlReportError` uso em um manipulador de captura C++ pode causar exceções em manipuladores de captura C++.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="atlthrow"></a><a name="atlthrow"></a>Atlthrow

Chame esta função para sinalizar um erro com base em um código de status HRESULT.

```
__declspec(noreturn) inline void AtlThrow(HRESULT hr);
```

### <a name="parameters"></a>Parâmetros

*Hr*<br/>
Valor Padrão HRESULT.

### <a name="remarks"></a>Comentários

Esta função é usada pelo código ATL e MFC no caso de uma condição de erro. Também pode ser chamado do seu próprio código. A implementação padrão desta função depende da definição do símbolo _ATL_NO_EXCEPTIONS e do tipo de projeto, MFC ou ATL.

Em todos os casos, esta função rastreia o HRESULT até o depurador.

No Visual Studio 2015 Update 3 e posterior, essa função é atribuída __declspec(sem retorno) para evitar avisos SAL espúrios.

Se _ATL_NO_EXCEPTIONS não for definida em um projeto MFC, essa função será lançada em uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou uma [COleException](../../mfc/reference/coleexception-class.md) com base no valor do HRESULT.

Se _ATL_NO_EXCEPTIONS não for definida em um projeto ATL, a função lançará uma [CAtlException](../../atl/reference/catlexception-class.md).

Se _ATL_NO_EXCEPTIONS for definida, a função causa uma falha de afirmação em vez de abrir uma exceção.

Para projetos ATL, é possível fornecer sua própria implementação desta função para ser usada pela ATL em caso de falha. Para isso, defina sua própria função `AtlThrow` com `AtlThrow` a mesma assinatura e #define ser o nome da sua função. Isso deve ser feito antes de incluir atlexcept.h (o que significa que deve ser feito antes de incluir quaisquer cabeçalhos ATL, uma vez que atlbase.h inclui atlexcept.h). Atribua `__declspec(noreturn)` sua função para evitar avisos SAL espúrios.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#95](../../atl/codesnippet/cpp/debugging-and-error-reporting-global-functions_2.h)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldef.h

## <a name="atlthrowlastwin32"></a><a name="atlthrowlastwin32"></a>AtlThrowLastWin32

Chame essa função para sinalizar um erro com base no resultado da função `GetLastError` do Windows.

```
inline void AtlThrowLastWin32();
```

### <a name="remarks"></a>Comentários

Esta função rastreia o `GetLastError` resultado do depurador.

Se _ATL_NO_EXCEPTIONS não for definida em um projeto MFC, essa função lançará uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou uma [COleException](../../mfc/reference/coleexception-class.md) com base no valor retornado por `GetLastError`.

Se _ATL_NO_EXCEPTIONS não for definida em um projeto ATL, a função lançará uma [CAtlException](../../atl/reference/catlexception-class.md).

Se _ATL_NO_EXCEPTIONS for definida, a função causa uma falha de afirmação em vez de abrir uma exceção.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldef.h

## <a name="see-also"></a>Confira também

[Funções](../../atl/reference/atl-functions.md)<br/>
[Macros de depuração e relatório de erros](../../atl/reference/debugging-and-error-reporting-macros.md)
