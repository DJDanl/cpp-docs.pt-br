---
title: Classe CDebugReportHook
ms.date: 11/04/2016
f1_keywords:
- CDebugReportHook
- ATLUTIL/ATL::CDebugReportHook
- ATLUTIL/ATL::CDebugReportHook::CDebugReportHook
- ATLUTIL/ATL::CDebugReportHook::CDebugReportHookProc
- ATLUTIL/ATL::CDebugReportHook::RemoveHook
- ATLUTIL/ATL::CDebugReportHook::SetHook
- ATLUTIL/ATL::CDebugReportHook::SetPipeName
- ATLUTIL/ATL::CDebugReportHook::SetTimeout
helpviewer_keywords:
- CDebugReportHook class
ms.assetid: 798076c3-6e63-4286-83b8-aa1bbcd0c20c
ms.openlocfilehash: 7187448b2ba2c9d3ab0399aa3e75ce8d757bfec1
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69496768"
---
# <a name="cdebugreporthook-class"></a>Classe CDebugReportHook

Use esta classe para enviar relatórios de depuração a um pipe nomeado.

## <a name="syntax"></a>Sintaxe

```
class CDebugReportHook
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDebugReportHook::CDebugReportHook](#cdebugreporthook)|Chama [SetPipeName](#setpipename), [setTimeout](#settimeout)e [SetHook](#sethook).|
|[CDebugReportHook:: ~ CDebugReportHook](#dtor)|Chama [CDebugReportHook:: RemoveHook](#removehook).|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDebugReportHook::CDebugReportHookProc](#cdebugreporthookproc)|Auto-estática A função de relatório personalizada que é conectada ao processo de relatório de depuração em tempo de execução do C.|
|[CDebugReportHook::RemoveHook](#removehook)|Chame esse método para interromper o envio de relatórios de depuração para o pipe nomeado e restaurar o gancho de relatório anterior.|
|[CDebugReportHook::SetHook](#sethook)|Chame esse método para começar a enviar relatórios de depuração para o pipe nomeado.|
|[CDebugReportHook::SetPipeName](#setpipename)|Chame esse método para definir o computador e o nome do pipe para o qual os relatórios de depuração serão enviados.|
|[CDebugReportHook::SetTimeout](#settimeout)|Chame esse método para definir o tempo em milissegundos que essa classe aguardará até que o pipe nomeado se torne disponível.|

## <a name="remarks"></a>Comentários

Crie uma instância dessa classe em Depurar compilações de seus serviços ou aplicativos para enviar relatórios de depuração a um pipe nomeado. Os relatórios de depuração são gerados chamando [_CrtDbgReport](../../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md) ou usando um wrapper para essa função, como as macros [AtlTrace](debugging-and-error-reporting-macros.md#atltrace) e [ATLASSERT](debugging-and-error-reporting-macros.md#atlassert) .

O uso dessa classe permite que você depure interativamente os componentes executados em [estações de janelas](/windows/win32/winstation/window-stations)não interativas.

Observe que os relatórios de depuração são enviados usando o contexto de segurança subjacente do thread. A representação é temporariamente desabilitada para que os relatórios de depuração possam ser exibidos em situações em que a representação de usuários com poucos privilégios está ocorrendo, como em aplicativos Web.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil. h

##  <a name="cdebugreporthook"></a>  CDebugReportHook::CDebugReportHook

Chama [SetPipeName](#setpipename), [setTimeout](#settimeout)e [SetHook](#sethook).

```
CDebugReportHook(
    LPCSTR szMachineName = ".",
    LPCSTR szPipeName = "AtlsDbgPipe",
    DWORD dwTimeout = 20000) throw();
```

### <a name="parameters"></a>Parâmetros

*szMachineName*<br/>
O nome do computador para o qual a saída de depuração deve ser enviada. O padrão é o computador local.

*szPipeName*<br/>
O nome do pipe nomeado para o qual a saída de depuração deve ser enviada.

*dwTimeout*<br/>
O tempo em milissegundos que essa classe aguardará até que o pipe nomeado se torne disponível.

##  <a name="dtor"></a>CDebugReportHook:: ~ CDebugReportHook

Chama [CDebugReportHook:: RemoveHook](#removehook).

```
~CDebugReportHook() throw();
```

##  <a name="cdebugreporthookproc"></a>  CDebugReportHook::CDebugReportHookProc

A função de relatório personalizada que é conectada ao processo de relatório de depuração em tempo de execução do C.

```
static int __cdecl CDebugReportHookProc(
    int reportType,
    char* message,
    int* returnValue) throw();
```

### <a name="parameters"></a>Parâmetros

*reportType*<br/>
O tipo do relatório (_CRT_WARN, _CRT_ERROR ou _CRT_ASSERT).

*message*<br/>
A cadeia de caracteres da mensagem.

*returnValue*<br/>
O valor que deve ser retornado por [_CrtDbgReport](../../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md).

### <a name="return-value"></a>Valor de retorno

Retornará FALSE se o gancho tratar a mensagem em questão completamente para que nenhum outro relatório seja necessário. Retorna true se `_CrtDbgReport` o deve relatar a mensagem da maneira normal.

### <a name="remarks"></a>Comentários

A função de relatório tenta abrir o pipe nomeado e se comunicar com o processo na outra extremidade. Se o pipe estiver ocupado, a função de relatório aguardará até que o pipe seja gratuito ou o tempo limite expire. O tempo limite pode ser definido pelo construtor ou uma chamada para [CDebugReportHook:: SetTimeout](#settimeout).

O código nessa função é executado no contexto de segurança subjacente do thread de chamada, ou seja, a representação é desabilitada durante essa função.

##  <a name="removehook"></a>  CDebugReportHook::RemoveHook

Chame esse método para interromper o envio de relatórios de depuração para o pipe nomeado e restaurar o gancho de relatório anterior.

```
void RemoveHook() throw();
```

### <a name="remarks"></a>Comentários

Chama [_CrtSetReportHook2](../../c-runtime-library/reference/crtsetreporthook2-crtsetreporthookw2.md) para restaurar o gancho de relatório anterior.

##  <a name="sethook"></a>  CDebugReportHook::SetHook

Chame esse método para começar a enviar relatórios de depuração para o pipe nomeado.

```
void SetHook() throw();
```

### <a name="remarks"></a>Comentários

Chama [_CrtSetReportHook2](../../c-runtime-library/reference/crtsetreporthook2-crtsetreporthookw2.md) para que os relatórios de depuração sejam roteados por meio de [CDebugReportHookProc](#cdebugreporthookproc) para o pipe nomeado. Essa classe controla o gancho de relatório anterior para que ele possa ser restaurado quando [RemoveHook](#removehook) é chamado.

##  <a name="setpipename"></a>  CDebugReportHook::SetPipeName

Chame esse método para definir o computador e o nome do pipe para o qual os relatórios de depuração serão enviados.

```
BOOL SetPipeName(
    LPCSTR szMachineName = ".",
    LPCSTR szPipeName = "AtlsDbgPipe") throw();
```

### <a name="parameters"></a>Parâmetros

*szMachineName*<br/>
O nome do computador para o qual a saída de depuração deve ser enviada.

*szPipeName*<br/>
O nome do pipe nomeado para o qual a saída de depuração deve ser enviada.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

##  <a name="settimeout"></a>  CDebugReportHook::SetTimeout

Chame esse método para definir o tempo em milissegundos que essa classe aguardará até que o pipe nomeado se torne disponível.

```
void SetTimeout(DWORD dwTimeout);
```

### <a name="parameters"></a>Parâmetros

*dwTimeout*<br/>
O tempo em milissegundos que essa classe aguardará até que o pipe nomeado se torne disponível.

## <a name="see-also"></a>Consulte também

[Classes](../../atl/reference/atl-classes.md)
