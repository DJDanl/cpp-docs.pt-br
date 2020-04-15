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
ms.openlocfilehash: 621d32a14618327873e6e0cce856c5792e1f8c46
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327106"
---
# <a name="cdebugreporthook-class"></a>Classe CDebugReportHook

Use esta classe para enviar relatórios de depuração para um tubo chamado.

## <a name="syntax"></a>Sintaxe

```
class CDebugReportHook
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDebugReportHook::CDebugReportHook](#cdebugreporthook)|Chamadas [SetPipeName,](#setpipename) [SetTimeout](#settimeout)e [SetHook](#sethook).|
|[CDebugReportHook::~CDebugReportHook](#dtor)|Chamadas [CDebugReportHook::RemoveHook](#removehook).|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDebugReportHook::CDebugReportHookProc](#cdebugreporthookproc)|(Estática) A função de emissão de relatórios personalizado selada no processo de emissão de depuração em tempo de execução C.|
|[CDebugReportHook::RemoveHook](#removehook)|Chame este método para parar de enviar relatórios de depuração para o tubo nomeado e restaurar o gancho de relatório anterior.|
|[CDebugReportHook::SetHook](#sethook)|Chame este método para começar a enviar relatórios de depuração para o tubo nomeado.|
|[CDebugReportHook::SetPipeName](#setpipename)|Chame este método para definir a máquina e o nome do tubo para o qual os relatórios de depuração serão enviados.|
|[CDebugReportHook::SetTimeout](#settimeout)|Chame este método para definir a hora em milissegundos que esta classe esperará para que o tubo nomeado fique disponível.|

## <a name="remarks"></a>Comentários

Crie uma instância dessa classe em compilações de depuração de seus serviços ou aplicativos para enviar relatórios de depuração para um tubo nomeado. Os relatórios de depuração são gerados por chamada [_CrtDbgReport](../../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md) ou usando um invólucro para esta função, como as macros [ATLTRACE](debugging-and-error-reporting-macros.md#atltrace) e [ATLASSERT.](debugging-and-error-reporting-macros.md#atlassert)

O uso desta classe permite que você depurasse interativamente componentes em execução em estações de janela não [interativas](/windows/win32/winstation/window-stations).

Observe que os relatórios de depuração são enviados usando o contexto de segurança subjacente do segmento. A personificação é temporariamente desativada para que os relatórios de depuração possam ser visualizados em situações em que a representação de usuários de baixo privilégio está ocorrendo, como em aplicativos web.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil.h

## <a name="cdebugreporthookcdebugreporthook"></a><a name="cdebugreporthook"></a>CDebugReportHook::CDebugReportHook

Chamadas [SetPipeName,](#setpipename) [SetTimeout](#settimeout)e [SetHook](#sethook).

```
CDebugReportHook(
    LPCSTR szMachineName = ".",
    LPCSTR szPipeName = "AtlsDbgPipe",
    DWORD dwTimeout = 20000) throw();
```

### <a name="parameters"></a>Parâmetros

*szMachineName*<br/>
O nome da máquina para a qual a saída de depuração deve ser enviada. Padrão para a máquina local.

*szPipeName*<br/>
O nome do tubo nomeado para o qual a saída de depuração deve ser enviada.

*Dwtimeout*<br/>
O tempo em milissegundos que esta classe vai esperar para o tubo nomeado para ficar disponível.

## <a name="cdebugreporthookcdebugreporthook"></a><a name="dtor"></a>CDebugReportHook::~CDebugReportHook

Chamadas [CDebugReportHook::RemoveHook](#removehook).

```
~CDebugReportHook() throw();
```

## <a name="cdebugreporthookcdebugreporthookproc"></a><a name="cdebugreporthookproc"></a>CDebugReportHook::CDebugReportHookProc

A função de emissão de relatórios personalizado selada no processo de emissão de depuração em tempo de execução C.

```
static int __cdecl CDebugReportHookProc(
    int reportType,
    char* message,
    int* returnValue) throw();
```

### <a name="parameters"></a>Parâmetros

*Reporttype*<br/>
O tipo de relatório (_CRT_WARN, _CRT_ERROR ou _CRT_ASSERT).

*Mensagem*<br/>
A cadeia de caracteres da mensagem.

*Returnvalue*<br/>
O valor que deve ser devolvido por [_CrtDbgReport](../../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md).

### <a name="return-value"></a>Valor retornado

Retorna FALSO se o gancho manusear a mensagem em questão completamente para que não seja necessário mais relatórios. Retorna TRUE `_CrtDbgReport` se deve relatar a mensagem da maneira normal.

### <a name="remarks"></a>Comentários

A função de emissão de relatórios tenta abrir o tubo nomeado e comunicar-se com o processo na outra extremidade. Se o tubo estiver ocupado, a função de emissão de relatórios aguardará até que o tubo esteja livre ou o tempo expirar. O tempo livre pode ser definido pelo construtor ou uma chamada para [CDebugReportHook::SetTimeout](#settimeout).

O código nesta função é executado no contexto de segurança subjacente do segmento de chamada, ou seja, a personificação é desativada durante a duração desta função.

## <a name="cdebugreporthookremovehook"></a><a name="removehook"></a>CDebugReportHook::RemoveHook

Chame este método para parar de enviar relatórios de depuração para o tubo nomeado e restaurar o gancho de relatório anterior.

```
void RemoveHook() throw();
```

### <a name="remarks"></a>Comentários

Chamadas [_CrtSetReportHook2](../../c-runtime-library/reference/crtsetreporthook2-crtsetreporthookw2.md) para restaurar o gancho de relatório anterior.

## <a name="cdebugreporthooksethook"></a><a name="sethook"></a>CDebugReportHook::SetHook

Chame este método para começar a enviar relatórios de depuração para o tubo nomeado.

```
void SetHook() throw();
```

### <a name="remarks"></a>Comentários

As [chamadas _CrtSetReportHook2](../../c-runtime-library/reference/crtsetreporthook2-crtsetreporthookw2.md) de depurar relatórios encaminhados através do [CDebugReportHookProc](#cdebugreporthookproc) para o tubo nomeado. Esta classe mantém o controle do gancho de relatório anterior para que ele possa ser restaurado quando [RemoveHook](#removehook) é chamado.

## <a name="cdebugreporthooksetpipename"></a><a name="setpipename"></a>CDebugReportHook::SetPipeName

Chame este método para definir a máquina e o nome do tubo para o qual os relatórios de depuração serão enviados.

```
BOOL SetPipeName(
    LPCSTR szMachineName = ".",
    LPCSTR szPipeName = "AtlsDbgPipe") throw();
```

### <a name="parameters"></a>Parâmetros

*szMachineName*<br/>
O nome da máquina para a qual a saída de depuração deve ser enviada.

*szPipeName*<br/>
O nome do tubo nomeado para o qual a saída de depuração deve ser enviada.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="cdebugreporthooksettimeout"></a><a name="settimeout"></a>CDebugReportHook::SetTimeout

Chame este método para definir a hora em milissegundos que esta classe esperará para que o tubo nomeado fique disponível.

```
void SetTimeout(DWORD dwTimeout);
```

### <a name="parameters"></a>Parâmetros

*Dwtimeout*<br/>
O tempo em milissegundos que esta classe vai esperar para o tubo nomeado para ficar disponível.

## <a name="see-also"></a>Confira também

[Classes](../../atl/reference/atl-classes.md)
