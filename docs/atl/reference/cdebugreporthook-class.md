---
title: Classe CDebugReportHook | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
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
caps.latest.revision: 22
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
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 632167d4f78ef930673450d6d087f32e91b6541f
ms.lasthandoff: 02/25/2017

---
# <a name="cdebugreporthook-class"></a>Classe CDebugReportHook
Use esta classe para enviar relatórios de depuração para um pipe nomeado.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CDebugReportHook
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDebugReportHook::CDebugReportHook](#cdebugreporthook)|Chamadas [SetPipeName](#setpipename), [SetTimeout](#settimeout), e [SetHook](#sethook).|  
|[CDebugReportHook:: ~ CDebugReportHook](#dtor)|Chamadas [CDebugReportHook::RemoveHook](#removehook).|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDebugReportHook::CDebugReportHookProc](#cdebugreporthookproc)|(Estático) A função personalizada de relatório que está conectada ao tempo de execução do C depurar o processo de emissão.|  
|[CDebugReportHook::RemoveHook](#removehook)|Chame esse método para parar de enviar relatórios de depuração para o pipe nomeado e restaure o gancho do relatório anterior.|  
|[CDebugReportHook::SetHook](#sethook)|Chame esse método para começar a enviar relatórios de depuração para o pipe nomeado.|  
|[CDebugReportHook::SetPipeName](#setpipename)|Chame esse método para definir a máquina e o nome do pipe ao qual os relatórios de depuração serão enviados.|  
|[CDebugReportHook::SetTimeout](#settimeout)|Chame esse método para definir o tempo em milissegundos que essa classe aguardará o pipe nomeado para se tornarem disponíveis.|  
  
## <a name="remarks"></a>Comentários  
 Crie uma instância dessa classe em compilações de depuração de seus serviços ou aplicativos de enviar relatórios de depuração para um pipe nomeado. Relatórios de depuração são gerados chamando [crtdbgreport](../../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md) ou usando um wrapper para essa função, como o [ATLTRACE](http://msdn.microsoft.com/library/c796baa5-e2b9-4814-a27d-d800590b102e) e [ATLASSERT](http://msdn.microsoft.com/library/98e3e0fc-77e2-499b-a6f6-b17a21c6fbd3) macros.  
  
 Uso dessa classe permite que você depure interativamente componentes em execução não-interativa [estações de janela](http://msdn.microsoft.com/library/windows/desktop/ms687096).  
  
 Observe que os relatórios de depuração são enviados usando o contexto de segurança subjacente do thread. Representação está temporariamente desabilitada para que os relatórios de depuração podem ser exibidos em situações onde a representação de usuários de baixo privilégio está ocorrendo, como em aplicativos da web.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlutil.h  
  
##  <a name="cdebugreporthook"></a>CDebugReportHook::CDebugReportHook  
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
 O nome do pipe nomeado para o qual a saída de depuração deve ser enviada.  
  
 `dwTimeout`  
 O tempo em milissegundos que essa classe aguardará o pipe nomeado para se tornarem disponíveis.  
  
##  <a name="dtor"></a>CDebugReportHook:: ~ CDebugReportHook  
 Chamadas [CDebugReportHook::RemoveHook](#removehook).  
  
```
~CDebugReportHook() throw();
```  
  
##  <a name="cdebugreporthookproc"></a>CDebugReportHook::CDebugReportHookProc  
 A função personalizada de relatório que está conectada ao tempo de execução do C depurar o processo de emissão.  
  
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
 A cadeia de caracteres de mensagem.  
  
 *returnValue*  
 O valor deve ser retornado por [crtdbgreport](../../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna FALSE se o gancho tratar completamente a mensagem em questão para que nenhum relatório adicional é necessária. Retorna TRUE se `_CrtDbgReport` deve relatar a mensagem da maneira normal.  
  
### <a name="remarks"></a>Comentários  
 A função de relatório tenta abrir o pipe nomeado e se comunicar com o processo na outra extremidade. Se o pipe estiver ocupado, a função de relatório aguardará até que o pipe é gratuito ou o tempo limite expirar. O tempo limite pode ser definido pelo construtor ou uma chamada para [CDebugReportHook::SetTimeout](#settimeout).  
  
 O código nessa função é executado no contexto de segurança subjacente do thread de chamada, ou seja, a representação está desativada para a duração dessa função.  
  
##  <a name="removehook"></a>CDebugReportHook::RemoveHook  
 Chame esse método para parar de enviar relatórios de depuração para o pipe nomeado e restaure o gancho do relatório anterior.  
  
```
void RemoveHook() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Chamadas [crtsetreporthook2](../../c-runtime-library/reference/crtsetreporthook2-crtsetreporthookw2.md) para restaurar o gancho do relatório anterior.  
  
##  <a name="sethook"></a>CDebugReportHook::SetHook  
 Chame esse método para começar a enviar relatórios de depuração para o pipe nomeado.  
  
```
void SetHook() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Chamadas [crtsetreporthook2](../../c-runtime-library/reference/crtsetreporthook2-crtsetreporthookw2.md) roteadas através de relatórios de depuração [CDebugReportHookProc](#cdebugreporthookproc) ao pipe nomeado. Essa classe mantém controle sobre o gancho de relatório anterior para que ele possa ser restaurado quando [RemoveHook](#removehook) é chamado.  
  
##  <a name="setpipename"></a>CDebugReportHook::SetPipeName  
 Chame esse método para definir a máquina e o nome do pipe ao qual os relatórios de depuração serão enviados.  
  
```
BOOL SetPipeName(
    LPCSTR szMachineName = ".",
    LPCSTR szPipeName = "AtlsDbgPipe") throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `szMachineName`  
 O nome da máquina para o qual a saída de depuração deve ser enviada.  
  
 `szPipeName`  
 O nome do pipe nomeado para o qual a saída de depuração deve ser enviada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro em caso de êxito, FALSE em caso de falha.  
  
##  <a name="settimeout"></a>CDebugReportHook::SetTimeout  
 Chame esse método para definir o tempo em milissegundos que essa classe aguardará o pipe nomeado para se tornarem disponíveis.  
  
```
void SetTimeout(DWORD dwTimeout);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwTimeout`  
 O tempo em milissegundos que essa classe aguardará o pipe nomeado para se tornarem disponíveis.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../atl/reference/atl-classes.md)

