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
ms.openlocfilehash: a7c5993d1b96daaa73e7fc9509c93e66daed77f3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62245903"
---
# <a name="cdebugreporthook-class"></a>Classe CDebugReportHook

Use essa classe para enviar relatórios de depuração para um pipe nomeado.

## <a name="syntax"></a>Sintaxe

```
class CDebugReportHook
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDebugReportHook::CDebugReportHook](#cdebugreporthook)|Chamadas [SetPipeName](#setpipename), [SetTimeout](#settimeout), e [SetHook](#sethook).|
|[CDebugReportHook::~CDebugReportHook](#dtor)|Chamadas [CDebugReportHook::RemoveHook](#removehook).|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDebugReportHook::CDebugReportHookProc](#cdebugreporthookproc)|(Estático) A função de relatório personalizada que é vinculada à processo de relatório de depuração em tempo de execução C.|
|[CDebugReportHook::RemoveHook](#removehook)|Chame esse método para parar de enviar relatórios de depuração para o pipe nomeado e restaure o gancho de relatório anterior.|
|[CDebugReportHook::SetHook](#sethook)|Chame esse método para começar a enviar relatórios de depuração para o pipe nomeado.|
|[CDebugReportHook::SetPipeName](#setpipename)|Chame esse método para definir o computador e o nome do pipe para o qual os relatórios de depuração serão enviados.|
|[CDebugReportHook::SetTimeout](#settimeout)|Chame esse método para definir o tempo em milissegundos que essa classe irá esperar para o pipe nomeado para se tornar disponível.|

## <a name="remarks"></a>Comentários

Crie uma instância dessa classe em compilações de depuração de seus serviços ou aplicativos para enviar relatórios de depuração para um pipe nomeado. Relatórios de depuração são gerados chamando [crtdbgreport](../../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md) ou usando um wrapper para essa função, como o [ATLTRACE](debugging-and-error-reporting-macros.md#atltrace) e [{1&gt;ATLASSERT&lt;1](debugging-and-error-reporting-macros.md#atlassert) macros.

Uso dessa classe permite que você depure interativamente os componentes em execução no não interativa [estações de janela](/windows/desktop/winstation/window-stations).

Observe que os relatórios de depuração são enviados usando o contexto de segurança subjacente do thread. Representação está temporariamente desabilitada para que os relatórios de depuração podem ser exibidos em situações em que a representação de usuários de baixo privilégio está ocorrendo, como em aplicativos da web.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil

##  <a name="cdebugreporthook"></a>  CDebugReportHook::CDebugReportHook

Chamadas [SetPipeName](#setpipename), [SetTimeout](#settimeout), e [SetHook](#sethook).

```
CDebugReportHook(
    LPCSTR szMachineName = ".",
    LPCSTR szPipeName = "AtlsDbgPipe",
    DWORD dwTimeout = 20000) throw();
```

### <a name="parameters"></a>Parâmetros

*szMachineName*<br/>
O nome da máquina para o qual a saída de depuração deve ser enviada. O padrão é o computador local.

*szPipeName*<br/>
O nome do pipe nomeado para o qual a saída de depuração deve ser enviada.

*dwTimeout*<br/>
O tempo em milissegundos que essa classe irá esperar para o pipe nomeado para se tornar disponível.

##  <a name="dtor"></a>  CDebugReportHook::~CDebugReportHook

Chamadas [CDebugReportHook::RemoveHook](#removehook).

```
~CDebugReportHook() throw();
```

##  <a name="cdebugreporthookproc"></a>  CDebugReportHook::CDebugReportHookProc

A função de relatório personalizada que é vinculada à processo de relatório de depuração em tempo de execução C.

```
static int __cdecl CDebugReportHookProc(
    int reportType,
    char* message,
    int* returnValue) throw();
```

### <a name="parameters"></a>Parâmetros

*reportType*<br/>
O tipo de relatório (_CRT_WARN, crt_error ou _CRT_ASSERT).

*message*<br/>
A cadeia de caracteres da mensagem.

*returnValue*<br/>
O valor que deve ser retornado por [crtdbgreport](../../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md).

### <a name="return-value"></a>Valor de retorno

Retorna FALSE se o gancho tratar completamente a mensagem em questão para que nenhum relatório adicional seja necessária. Retorna VERDADEIRO se `_CrtDbgReport` deve relatar a mensagem da maneira normal.

### <a name="remarks"></a>Comentários

A função de relatório tenta abrir o pipe nomeado e se comunicar com o processo na outra extremidade. Se o pipe está ocupado, a função de relatório aguardará até que o pipe está livre ou o tempo limite expirar. O tempo limite pode ser definido por uma chamada para ou de construtor [CDebugReportHook::SetTimeout](#settimeout).

O código nessa função é executado no contexto de segurança subjacente no thread de chamada, ou seja, a representação está desabilitada para a duração dessa função.

##  <a name="removehook"></a>  CDebugReportHook::RemoveHook

Chame esse método para parar de enviar relatórios de depuração para o pipe nomeado e restaure o gancho de relatório anterior.

```
void RemoveHook() throw();
```

### <a name="remarks"></a>Comentários

Chamadas [_CrtSetReportHook2](../../c-runtime-library/reference/crtsetreporthook2-crtsetreporthookw2.md) para restaurar o gancho de relatório anterior.

##  <a name="sethook"></a>  CDebugReportHook::SetHook

Chame esse método para começar a enviar relatórios de depuração para o pipe nomeado.

```
void SetHook() throw();
```

### <a name="remarks"></a>Comentários

Chamadas [_CrtSetReportHook2](../../c-runtime-library/reference/crtsetreporthook2-crtsetreporthookw2.md) ter roteados por meio de relatórios de depuração [CDebugReportHookProc](#cdebugreporthookproc) ao pipe nomeado. Essa classe mantém controle sobre o gancho de relatório anterior para que ele possa ser restaurado quando [RemoveHook](#removehook) é chamado.

##  <a name="setpipename"></a>  CDebugReportHook::SetPipeName

Chame esse método para definir o computador e o nome do pipe para o qual os relatórios de depuração serão enviados.

```
BOOL SetPipeName(
    LPCSTR szMachineName = ".",
    LPCSTR szPipeName = "AtlsDbgPipe") throw();
```

### <a name="parameters"></a>Parâmetros

*szMachineName*<br/>
O nome da máquina para o qual a saída de depuração deve ser enviada.

*szPipeName*<br/>
O nome do pipe nomeado para o qual a saída de depuração deve ser enviada.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

##  <a name="settimeout"></a>  CDebugReportHook::SetTimeout

Chame esse método para definir o tempo em milissegundos que essa classe irá esperar para o pipe nomeado para se tornar disponível.

```
void SetTimeout(DWORD dwTimeout);
```

### <a name="parameters"></a>Parâmetros

*dwTimeout*<br/>
O tempo em milissegundos que essa classe irá esperar para o pipe nomeado para se tornar disponível.

## <a name="see-also"></a>Consulte também

[Classes](../../atl/reference/atl-classes.md)
