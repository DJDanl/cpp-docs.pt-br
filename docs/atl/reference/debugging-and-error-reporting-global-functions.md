---
title: Funções globais de relatório de erros e de depuração | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- atlcomcli/ATL::AtlHresultFromLastError
- atlcom/ATL::AtlReportError
- atldef/ATL::AtlThrow
dev_langs:
- C++
helpviewer_keywords:
- functions [ATL], error reporting
ms.assetid: 11339c02-98cd-428d-b3b9-7deeb155a6a3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fb3257b5205587b27a83671ed8e610aad5373eef
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="debugging-and-error-reporting-global-functions"></a>Funções globais de relatório de erros e de depuração
Essas funções fornecem recursos úteis de depuração e rastreamento.  
  
|||  
|-|-|  
|[AtlHresultFromLastError](debugging-and-error-reporting-global-functions.md#atlhresultfromlasterror)|Retorna um `GetLastError` código de erro na forma de um HRESULT.|  
|[AtlHresultFromWin32](debugging-and-error-reporting-global-functions.md#atlhresultfromwin32)|Converte um código de erro do Win32 em HRESULT.|  
|[AtlReportError](debugging-and-error-reporting-global-functions.md#atlreporterror)|Configura **IErrorInfo** para fornecer detalhes do erro para um cliente.|  
|[AtlThrow](debugging-and-error-reporting-global-functions.md#atlthrow)|Gera uma `CAtlException`.|  
|[AtlThrowLastWin32](debugging-and-error-reporting-global-functions.md#atlthrowlastwin32)|Chame essa função para sinalizar um erro com base no resultado da função `GetLastError` do Windows.|  
  
##  <a name="atlhresultfromlasterror"></a>  AtlHresultFromLastError  
 Retorna o valor do código do último erro do thread de chamada na forma de HRESULT.  
  
```
HRESULT AtlHresultFromLastError();
```  
  
### <a name="remarks"></a>Comentários  
 `AtlHresultFromLastError` chamadas `GetLastError` obter último erro e retornará o erro após convertê-la a um HRESULT usando o **HRESULT_FROM_WIN32** macro.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcomcli.h  

##  <a name="atlhresultfromwin32"></a>  AtlHresultFromWin32  
 Converte um código de erro do Win32 em HRESULT.  
  
```
AtlHresultFromWin32(DWORD error);
```  
  
### <a name="parameters"></a>Parâmetros  
 *error*  
 O valor de erro para converter.  
  
### <a name="remarks"></a>Comentários  
 Converte um código de erro do Win32 em um HRESULT, usando a macro **HRESULT_FROM_WIN32**.  
  
> [!NOTE]
>  Em vez de usar **HRESULT_FROM_WIN32(GetLastError())**, use a função [AtlHresultFromLastError](debugging-and-error-reporting-global-functions.md#atlhresultfromlasterror).  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcomcli.h  

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
 `clsid`  
 [in] O CLSID do objeto relatando o erro.  
  
 `lpszDesc`  
 [in] A cadeia de caracteres que descreve o erro. As versões do Unicode especificam que `lpszDesc` é do tipo **LPCOLESTR**; a versão ANSI Especifica um tipo de `LPCSTR`.  
  
 `iid`  
 [in] O IID da interface definindo o erro ou `GUID_NULL` se o erro é definido pelo sistema operacional.  
  
 `hRes`  
 [in] O `HRESULT` serem retornadas ao chamador.  
  
 `nID`  
 [in] O identificador de recurso em que a cadeia de caracteres de descrição de erro é armazenada. Esse valor deve estar entre 0x0200 e 0xFFFF, inclusive. Em compilações de depuração, uma **ASSERT** ocorrerá se `nID` não indexa uma cadeia de caracteres válida. Em compilações de versão, a cadeia de caracteres de descrição de erro será definida como "Erro desconhecido".  
  
 `dwHelpID`  
 [in] O identificador de contexto de ajuda para o erro.  
  
 `lpszHelpFile`  
 [in] O caminho e o nome do arquivo de Ajuda que descreve o erro.  
  
 `hInst`  
 [in] O identificador para o recurso. Por padrão, esse parâmetro é **__AtlBaseModuleModule::GetResourceInstance**, onde **__AtlBaseModuleModule** é a instância global do [CAtlBaseModule](../../atl/reference/catlbasemodule-class.md) ou uma classe derivado dele.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o `hRes` parâmetro é diferente de zero, retorna o valor de `hRes`. Se `hRes` for zero, então as primeiras quatro versões do `AtlReportError` retornar `DISP_E_EXCEPTION`. As duas últimas versões retornam o resultado da macro **MAKE_HRESULT (1, FACILITY_ITF,** `nID` **)**.  
  
### <a name="remarks"></a>Comentários  
 A cadeia de caracteres *lpszDesc* é usado como a descrição de texto do erro. Quando o cliente recebe o `hRes` retornar de `AtlReportError`, o cliente pode acessar o **IErrorInfo** estrutura para obter detalhes sobre o erro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_COM#52](../../atl/codesnippet/cpp/debugging-and-error-reporting-global-functions_1.cpp)]  
  
> [!CAUTION]
>  Não use `AtlReportError` em C++ manipuladores catch. Algumas substituições dessas funções usam as macros de conversão de cadeia de caracteres ATL internamente, que por sua vez de usar o `_alloca` função internamente. Usando `AtlReportError` em um catch C++ manipulador pode causar exceções em manipuladores catch de C++.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
    
##  <a name="atlthrow"></a>  AtlThrow  
 Chame essa função para sinalizar um erro com base em um código de status `HRESULT`.  
  
```
__declspec(noreturn) inline void AtlThrow(HRESULT hr);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hr`  
 Valor padrão de HRESULT.  
  
### <a name="remarks"></a>Comentários  
 Essa função é usada pelo código ATL e MFC em caso de uma condição de erro. Ele também pode ser chamado de seu próprio código. A implementação padrão dessa função dependerá da definição do símbolo **_ATL_NO_EXCEPTIONS** e do tipo de projeto, MFC ou do ATL  
  
 Em todos os casos, essa função rastreia o HRESULT para o depurador.  
  
 No Visual Studio 2015 atualização 3 e posterior, essa função é atribuída __declspec(noreturn) para evitar avisos de SAL artificiais.  
  
 Se **_ATL_NO_EXCEPTIONS** não está definido em um projeto MFC, essa função lança um [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou um [COleException](../../mfc/reference/coleexception-class.md) com base no valor de HRESULT.  
  
 Se **_ATL_NO_EXCEPTIONS** não está definido em um projeto ATL, a função gera uma [CAtlException](../../atl/reference/catlexception-class.md).  
  
 Se **_ATL_NO_EXCEPTIONS** é definida, a função faz com que uma falha de asserção em vez de gerar uma exceção.  
  
 Projetos ATL, é possível fornecer sua própria implementação dessa função a ser usado pelo ATL em caso de falha. Para fazer isso, defina sua própria função com a mesma assinatura `AtlThrow` e #define `AtlThrow` para o nome da sua função. Isso deve ser feito antes de incluir atlexcept.h (o que significa que ele deve ser feito antes de incluindo todos os cabeçalhos ATL pois atlbase inclui atlexcept.h). Atributo sua função `__declspec(noreturn)` para evitar avisos de SAL artificiais.  
  
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
 Essa função rastreia o resultado de `GetLastError` para o depurador.  
  
 Se **_ATL_NO_EXCEPTIONS** não está definido em um projeto MFC, essa função lança um [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou um [COleException](../../mfc/reference/coleexception-class.md) com base no valor retornado por `GetLastError`.  
  
 Se **_ATL_NO_EXCEPTIONS** não está definido em um projeto ATL, a função gera uma [CAtlException](../../atl/reference/catlexception-class.md).  
  
 Se **_ATL_NO_EXCEPTIONS** é definida, a função faz com que uma falha de asserção em vez de gerar uma exceção.  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldef.h  
   
     
## <a name="see-also"></a>Consulte também  
 [Funções](../../atl/reference/atl-functions.md)   
 [Macros de relatórios de erros e depuração](../../atl/reference/debugging-and-error-reporting-macros.md)









