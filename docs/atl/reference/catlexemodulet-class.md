---
title: Classe CAtlExeModuleT | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAtlExeModuleT
- ATLBASE/ATL::CAtlExeModuleT
- ATLBASE/ATL::CAtlExeModuleT::CAtlExeModuleT
- ATLBASE/ATL::CAtlExeModuleT::InitializeCom
- ATLBASE/ATL::CAtlExeModuleT::ParseCommandLine
- ATLBASE/ATL::CAtlExeModuleT::PostMessageLoop
- ATLBASE/ATL::CAtlExeModuleT::PreMessageLoop
- ATLBASE/ATL::CAtlExeModuleT::RegisterClassObjects
- ATLBASE/ATL::CAtlExeModuleT::RevokeClassObjects
- ATLBASE/ATL::CAtlExeModuleT::Run
- ATLBASE/ATL::CAtlExeModuleT::RunMessageLoop
- ATLBASE/ATL::CAtlExeModuleT::UninitializeCom
- ATLBASE/ATL::CAtlExeModuleT::Unlock
- ATLBASE/ATL::CAtlExeModuleT::WinMain
- ATLBASE/ATL::CAtlExeModuleT::m_bDelayShutdown
- ATLBASE/ATL::CAtlExeModuleT::m_dwPause
- ATLBASE/ATL::CAtlExeModuleT::m_dwTimeOut
dev_langs:
- C++
helpviewer_keywords:
- CAtlExeModuleT class
ms.assetid: 82245f3d-91d4-44fa-aa86-7cc7fbd758d9
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c45b1f95aba4f11e6995bf5c4c1cfff00627e4b6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="catlexemodulet-class"></a>Classe CAtlExeModuleT
Essa classe representa o módulo para um aplicativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>  
class ATL_NO_VTABLE CAtlExeModuleT : public CAtlModuleT<T>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe derivada de `CAtlExeModuleT`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlExeModuleT::CAtlExeModuleT](#catlexemodulet)|O construtor.|  
|[CAtlExeModuleT:: ~ CAtlExeModuleT](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlExeModuleT::InitializeCom](#initializecom)|Inicializa COM.|  
|[CAtlExeModuleT::ParseCommandLine](#parsecommandline)|Analisa a linha de comando e executa o registro se necessário.|  
|[CAtlExeModuleT::PostMessageLoop](#postmessageloop)|Esse método é chamado imediatamente depois que o loop de mensagens será encerrado.|  
|[CAtlExeModuleT::PreMessageLoop](#premessageloop)|Este método é chamado imediatamente antes de entrar no loop de mensagem.|  
|[CAtlExeModuleT::RegisterClassObjects](#registerclassobjects)|Registra o objeto de classe.|  
|[CAtlExeModuleT::RevokeClassObjects](#revokeclassobjects)|Revoga o objeto da classe.|  
|[CAtlExeModuleT::Run](#run)|Esse método executa o código no módulo EXE para inicializar, execute o loop de mensagens e limpar.|  
|[CAtlExeModuleT::RunMessageLoop](#runmessageloop)|Esse método executa o loop de mensagens.|  
|[CAtlExeModuleT::UninitializeCom](#uninitializecom)|Uninitializes COM.|  
|[CAtlExeModuleT::Unlock](#unlock)|Contagem de bloqueios do módulo diminui.|  
|[CAtlExeModuleT::WinMain](#winmain)|Esse método implementa o código necessário para executar um executável.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlExeModuleT::m_bDelayShutdown](#m_bdelayshutdown)|Um sinalizador que indica que deve haver um atraso de desligar o módulo.|  
|[CAtlExeModuleT::m_dwPause](#m_dwpause)|Um valor de pausar usado para garantir que todos os objetos são liberados antes do desligamento.|  
|[CAtlExeModuleT::m_dwTimeOut](#m_dwtimeout)|Um valor de tempo limite usado para atrasar o descarregamento do módulo.|  
  
## <a name="remarks"></a>Comentários  
 `CAtlExeModuleT`representa o módulo para um aplicativo (EXE) e contém o código que suporta criando um EXE, processamento de linha de comando, registrando objetos de classe, executar o loop de mensagem e limpando na saída.  
  
 Essa classe foi projetada para melhorar o desempenho quando os objetos no servidor EXE continuamente são criados e destruídos. Após o último objeto COM é liberado, o arquivo EXE espera por uma duração especificada pelo [CAtlExeModuleT::m_dwTimeOut](#m_dwtimeout) membro de dados. Se não houver nenhuma atividade durante esse período (ou seja, não há objetos são criados), o processo de desligamento é iniciado.  
  
 O [CAtlExeModuleT::m_bDelayShutdown](#m_bdelayshutdown) membro de dados é um sinalizador usado para determinar se o arquivo EXE deve usar o mecanismo definido acima. Se estiver definido como false, o módulo será encerrado imediatamente.  
  
 Para obter mais informações sobre módulos no ATL, consulte [Classes de módulo ATL](../../atl/atl-module-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [_ATL_MODULE](atl-typedefs.md#_atl_module)  

  
 [CAtlModule](../../atl/reference/catlmodule-class.md)  
  
 [CAtlModuleT](../../atl/reference/catlmodulet-class.md)  
  
 `CAtlExeModuleT`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
  
##  <a name="catlexemodulet"></a>CAtlExeModuleT::CAtlExeModuleT  
 O construtor.  
  
```
CAtlExeModuleT() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Se não foi possível inicializar o módulo EXE, WinMain retornará imediatamente sem processamento adicional.  
  
##  <a name="dtor"></a>CAtlExeModuleT:: ~ CAtlExeModuleT  
 O destruidor.  
  
```
~CAtlExeModuleT() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados.  
  
##  <a name="initializecom"></a>CAtlExeModuleT::InitializeCom  
 Inicializa COM.  
  
```
static HRESULT InitializeCom() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Esse método é chamado a partir do construtor e pode ser substituído para inicializar o COM uma maneira diferente da implementação do padrão. A implementação padrão chama ou **CoInitializeEx (NULL, COINIT_MULTITHREADED)** ou **CoInitialize(NULL)** dependendo da configuração de projeto.  
  
 Substituir esse método normalmente requer substituição [CAtlExeModuleT::UninitializeCom](#uninitializecom).  
  
##  <a name="m_bdelayshutdown"></a>CAtlExeModuleT::m_bDelayShutdown  
 Um sinalizador que indica que deve haver um atraso de desligar o módulo.  
  
```
bool m_bDelayShutdown;
```  
  
### <a name="remarks"></a>Comentários  
 Consulte o [visão geral de CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md) para obter detalhes.  
  
##  <a name="m_dwpause"></a>CAtlExeModuleT::m_dwPause  
 Um valor de pausar usado para garantir que todos os objetos são desapareceu antes do desligamento.  
  
```
DWORD m_dwPause;
```  
  
### <a name="remarks"></a>Comentários  
 Altere este valor após a chamada [CAtlExeModuleT::InitializeCom](#initializecom) para definir o número de milissegundos, usado como o valor de pausar para desligar o servidor. O valor padrão é 1.000 milissegundos.  
  
##  <a name="m_dwtimeout"></a>CAtlExeModuleT::m_dwTimeOut  
 Um valor de tempo limite usado para atrasar o descarregamento do módulo.  
  
```
DWORD m_dwTimeOut;
```  
  
### <a name="remarks"></a>Comentários  
 Altere este valor após a chamada [CAtlExeModuleT::InitializeCom](#initializecom) para definir o número de milissegundos, usado como o valor de tempo limite para desligar o servidor. O valor padrão é 5.000 milissegundos. Consulte o [visão geral de CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md) para obter mais detalhes.  
  
##  <a name="parsecommandline"></a>CAtlExeModuleT::ParseCommandLine  
 Analisa a linha de comando e executa o registro se necessário.  
  
```
bool ParseCommandLine(LPCTSTR lpCmdLine, HRESULT* pnRetCode) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpCmdLine`  
 A linha de comando passada para o aplicativo.  
  
 `pnRetCode`  
 O HRESULT correspondente para o registro (se ela foi feita).  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará true se o aplicativo deve continuar em execução, caso contrário, false.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado de [CAtlExeModuleT::WinMain](#winmain) e pode ser substituído para manipular as opções de linha de comando. A implementação padrão verifica **/RegServer** e **/UnRegServer** argumentos de linha de comando e realiza o registro ou cancelamento de registro.  
  
##  <a name="postmessageloop"></a>CAtlExeModuleT::PostMessageLoop  
 Esse método é chamado imediatamente depois que o loop de mensagens será encerrado.  
  
```
HRESULT PostMessageLoop() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para executar a limpeza de aplicativo personalizado. A implementação padrão chama [CAtlExeModuleT::RevokeClassObjects](#revokeclassobjects).  
  
##  <a name="premessageloop"></a>CAtlExeModuleT::PreMessageLoop  
 Este método é chamado imediatamente antes de entrar no loop de mensagem.  
  
```
HRESULT PreMessageLoop(int nShowCmd) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nShowCmd`  
 O valor passado como o `nShowCmd` parâmetro WinMain.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para adicionar o código de inicialização personalizada para o aplicativo. A implementação padrão registra os objetos de classe.  
  
##  <a name="registerclassobjects"></a>CAtlExeModuleT::RegisterClassObjects  
 Registra o objeto da classe com OLE para que outros aplicativos possam se conectar a ele.  
  
```
HRESULT RegisterClassObjects(DWORD dwClsContext, DWORD dwFlags) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwClsContext*  
 Especifica o contexto no qual o objeto de classe é para ser executado. Os valores possíveis são CLSCTX_INPROC_SERVER, CLSCTX_INPROC_HANDLER ou CLSCTX_LOCAL_SERVER.  
  
 `dwFlags`  
 Determina os tipos de conexão para o objeto de classe. Os valores possíveis são REGCLS_SINGLEUSE, REGCLS_MULTIPLEUSE ou REGCLS_MULTI_SEPARATE.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK sucesso, S_FALSE se não houvesse nenhuma classe para registrar ou um erro HRESULT em caso de falha.  
  
##  <a name="revokeclassobjects"></a>CAtlExeModuleT::RevokeClassObjects  
 Remove o objeto de classe.  
  
```
HRESULT RevokeClassObjects() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK sucesso, S_FALSE se não houvesse nenhuma classe para registrar ou um erro HRESULT em caso de falha.  
  
##  <a name="run"></a>CAtlExeModuleT::Run  
 Esse método executa o código no módulo EXE para inicializar, execute o loop de mensagens e limpar.  
  
```
HRESULT Run(int nShowCmd = SW_HIDE) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nShowCmd`  
 Especifica como a janela a ser mostrado. Esse parâmetro pode ser um dos valores discutidos a [WinMain](http://msdn.microsoft.com/library/windows/desktop/ms633559) seção. O padrão é SW_HIDE.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Este método pode ser substituído. No entanto, na prática, é melhor para substituir [CAtlExeModuleT::PreMessageLoop](#premessageloop), [CAtlExeModuleT::RunMessageLoop](#runmessageloop), ou [CAtlExeModuleT::PostMessageLoop](#postmessageloop) em vez disso.  
  
##  <a name="runmessageloop"></a>CAtlExeModuleT::RunMessageLoop  
 Esse método executa o loop de mensagens.  
  
```
void RunMessageLoop() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método pode ser substituído para alterar o comportamento do loop de mensagem.  
  
##  <a name="uninitializecom"></a>CAtlExeModuleT::UninitializeCom  
 Uninitializes COM.  
  
```
static void UninitializeCom() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão este método simplesmente chama [CoUninitialize](http://msdn.microsoft.com/library/windows/desktop/ms688715) e é chamado a partir do destruidor. Substitua este método se você substituir [CAtlExeModuleT::InitializeCom](#initializecom).  
  
##  <a name="unlock"></a>CAtlExeModuleT::Unlock  
 Contagem de bloqueios do módulo diminui.  
  
```
LONG Unlock() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor que pode ser útil para um diagnóstico ou teste.  
  
##  <a name="winmain"></a>CAtlExeModuleT::WinMain  
 Esse método implementa o código necessário para executar um executável.  
  
```
int WinMain(int nShowCmd) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nShowCmd`  
 Especifica como a janela a ser mostrado. Esse parâmetro pode ser um dos valores discutidos a [WinMain](http://msdn.microsoft.com/library/windows/desktop/ms633559) seção.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor de retorno do executável.  
  
### <a name="remarks"></a>Comentários  
 Este método pode ser substituído. Se substituir [CAtlExeModuleT::PreMessageLoop](#premessageloop), [CAtlExeModuleT::PostMessageLoop](#postmessageloop), ou [CAtlExeModuleT::RunMessageLoop](#runmessageloop) não fornece flexibilidade suficiente , é possível substituir o `WinMain` função usando esse método.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo de ATLDuck](../../visual-cpp-samples.md)   
 [Classe CAtlModuleT](../../atl/reference/catlmodulet-class.md)   
 [Classe CAtlDllModuleT](../../atl/reference/catldllmodulet-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
