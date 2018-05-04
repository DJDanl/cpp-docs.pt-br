---
title: Classe CDebugReportHook | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CDebugReportHook
- ATLUTIL/ATL::CDebugReportHook
- ATLUTIL/ATL::CDebugReportHook::CDebugReportHook
- ATLUTIL/ATL::CDebugReportHook::CDebugReportHookProc
- ATLUTIL/ATL::CDebugReportHook::RemoveHook
- ATLUTIL/ATL::CDebugReportHook::SetHook
- ATLUTIL/ATL::CDebugReportHook::SetPipeName
- ATLUTIL/ATL::CDebugReportHook::SetTimeout
dev_langs:
- C++
helpviewer_keywords:
- CDebugReportHook class
ms.assetid: 798076c3-6e63-4286-83b8-aa1bbcd0c20c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d84b2da8a347833513e0725695bb9d2bacd2951d
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="cdebugreporthook-class"></a>Classe CDebugReportHook
Use esta classe para enviar relatórios de depuração para um pipe nomeado.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CDebugReportHook
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDebugReportHook::CDebugReportHook](#cdebugreporthook)|Chamadas [SetPipeName](#setpipename), [SetTimeout](#settimeout), e [SetHook](#sethook).|  
|[CDebugReportHook:: ~ CDebugReportHook](#dtor)|Chamadas [CDebugReportHook::RemoveHook](#removehook).|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDebugReportHook::CDebugReportHookProc](#cdebugreporthookproc)|(Estático) A função de relatório personalizada que está conectada ao tempo de execução do C depurar o processo de geração de relatórios.|  
|[CDebugReportHook::RemoveHook](#removehook)|Chame esse método para parar de enviar relatórios de depuração para o pipe nomeado e restaure o gancho de relatório anterior.|  
|[CDebugReportHook::SetHook](#sethook)|Chame esse método para começar a enviar relatórios de depuração para o pipe nomeado.|  
|[CDebugReportHook::SetPipeName](#setpipename)|Chame este método para definir o computador e o nome do pipe para que os relatórios de depuração serão enviados.|  
|[CDebugReportHook::SetTimeout](#settimeout)|Chame esse método para definir o tempo em milissegundos que esta classe aguardará o pipe nomeado para se tornar disponível.|  
  
## <a name="remarks"></a>Comentários  
 Crie uma instância dessa classe em compilações de depuração dos seus serviços ou aplicativos a enviar relatórios de depuração para um pipe nomeado. Relatórios de depuração são gerados chamando [crtdbgreport](../../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md) ou usando um wrapper para essa função como o [ATLTRACE](debugging-and-error-reporting-macros.md#atltrace) e [ATLASSERT](debugging-and-error-reporting-macros.md#atlassert) macros.  
  
 Uso dessa classe permite que você depure interativamente os componentes executados não interativo [estações de janela](http://msdn.microsoft.com/library/windows/desktop/ms687096).  
  
 Observe que os relatórios de depuração são enviados usando o contexto de segurança subjacente do thread. Representação está temporariamente desabilitada para que os relatórios de depuração podem ser exibidos em situações onde a representação de usuários de baixo privilégio está ocorrendo, como em aplicativos da web.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlutil.h  
  
##  <a name="cdebugreporthook"></a>  CDebugReportHook::CDebugReportHook  
 Chamadas [SetPipeName](#setpipename), [SetTimeout](#settimeout), e [SetHook](#sethook).  
  
```
CDebugReportHook(
    LPCSTR szMachineName = ".",
    LPCSTR szPipeName = "AtlsDbgPipe",
    DWORD dwTimeout = 20000) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `szMachineName`  
 O nome da máquina para o qual a saída de depuração deve ser enviada. O padrão é o computador local.  
  
 `szPipeName`  
 O nome do pipe nomeado que a saída de depuração deve ser enviada.  
  
 `dwTimeout`  
 O tempo em milissegundos que esta classe aguardará o pipe nomeado para se tornar disponível.  
  
##  <a name="dtor"></a>  CDebugReportHook:: ~ CDebugReportHook  
 Chamadas [CDebugReportHook::RemoveHook](#removehook).  
  
```
~CDebugReportHook() throw();
```  
  
##  <a name="cdebugreporthookproc"></a>  CDebugReportHook::CDebugReportHookProc  
 A função de relatório personalizada que está conectada ao tempo de execução do C depurar o processo de geração de relatórios.  
  
```
static int __cdecl CDebugReportHookProc(
    int reportType,
    char* message,
    int* returnValue) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `reportType`  
 O tipo de relatório (_CRT_WARN, _CRT_ERROR ou _CRT_ASSERT).  
  
 `message`  
 A cadeia de caracteres da mensagem.  
  
 *ReturnValue*  
 O valor deve ser retornado por [crtdbgreport](../../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna FALSE se o gancho gerencia completamente a mensagem em questão para que nenhum relatório adicional é necessária. Retorna VERDADEIRO se `_CrtDbgReport` devem relatar a mensagem da maneira normal.  
  
### <a name="remarks"></a>Comentários  
 A função de relatório tenta abrir o pipe nomeado e se comunicar com o processo na outra extremidade. Se o pipe estiver ocupado, a função de relatório aguardará até que o pipe está livre ou o tempo limite expirar. O tempo limite pode ser definido por uma chamada para ou de construtor [CDebugReportHook::SetTimeout](#settimeout).  
  
 O código nessa função for executado no contexto de segurança subjacente no thread de chamada, ou seja, a representação está desabilitada para a duração dessa função.  
  
##  <a name="removehook"></a>  CDebugReportHook::RemoveHook  
 Chame esse método para parar de enviar relatórios de depuração para o pipe nomeado e restaure o gancho de relatório anterior.  
  
```
void RemoveHook() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Chamadas [crtsetreporthook2](../../c-runtime-library/reference/crtsetreporthook2-crtsetreporthookw2.md) para restaurar o gancho de relatório anterior.  
  
##  <a name="sethook"></a>  CDebugReportHook::SetHook  
 Chame esse método para começar a enviar relatórios de depuração para o pipe nomeado.  
  
```
void SetHook() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Chamadas [crtsetreporthook2](../../c-runtime-library/reference/crtsetreporthook2-crtsetreporthookw2.md) roteada por meio de relatórios de depuração [CDebugReportHookProc](#cdebugreporthookproc) ao pipe nomeado. Essa classe mantém controle sobre o gancho de relatório anterior para que ele possa ser restaurado quando [RemoveHook](#removehook) é chamado.  
  
##  <a name="setpipename"></a>  CDebugReportHook::SetPipeName  
 Chame este método para definir o computador e o nome do pipe para que os relatórios de depuração serão enviados.  
  
```
BOOL SetPipeName(
    LPCSTR szMachineName = ".",
    LPCSTR szPipeName = "AtlsDbgPipe") throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `szMachineName`  
 O nome da máquina para o qual a saída de depuração deve ser enviada.  
  
 `szPipeName`  
 O nome do pipe nomeado que a saída de depuração deve ser enviada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro no caso de sucesso, falso em caso de falha.  
  
##  <a name="settimeout"></a>  CDebugReportHook::SetTimeout  
 Chame esse método para definir o tempo em milissegundos que esta classe aguardará o pipe nomeado para se tornar disponível.  
  
```
void SetTimeout(DWORD dwTimeout);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwTimeout`  
 O tempo em milissegundos que esta classe aguardará o pipe nomeado para se tornar disponível.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../atl/reference/atl-classes.md)
