---
title: Classe CAtlServiceModuleT | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CAtlServiceModuleT
- ATL.CAtlServiceModuleT
- CAtlServiceModuleT
dev_langs:
- C++
helpviewer_keywords:
- CAtlServiceModuleT class
ms.assetid: 8fc753ce-4a50-402b-9b4a-0a4ce5dd496c
caps.latest.revision: 20
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
ms.openlocfilehash: c8fcadca667b618d9e5f112d7910c8e6e6f6c65d
ms.lasthandoff: 02/25/2017

---
# <a name="catlservicemodulet-class"></a>Classe CAtlServiceModuleT
Essa classe implementa um serviço.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T, UINT nServiceNameID>  
class ATL_NO_VTABLE CAtlServiceModuleT : public CAtlExeModuleT<T>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Sua classe derivada de `CAtlServiceModuleT`.  
  
 *nServiceNameID*  
 O identificador de recurso do serviço.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlServiceModuleT::CAtlServiceModuleT](#catlservicemodulet)|O construtor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlServiceModuleT::Handler](#handler)|A rotina de manipulador para o serviço.|  
|[CAtlServiceModuleT::InitializeSecurity](#initializesecurity)|O padrão fornece configurações de segurança para o serviço.|  
|[CAtlServiceModuleT::Install](#install)|Instala e cria o serviço.|  
|[CAtlServiceModuleT::IsInstalled](#isinstalled)|Confirma que o serviço foi instalado.|  
|[CAtlServiceModuleT::LogEvent](#logevent)|Grava o log de eventos.|  
|[CAtlServiceModuleT::OnContinue](#oncontinue)|Substitua este método para continuar o serviço.|  
|[CAtlServiceModuleT::OnInterrogate](#oninterrogate)|Substitua este método para interrogar o serviço.|  
|[CAtlServiceModuleT::OnPause](#onpause)|Substitua este método para pausar o serviço.|  
|[CAtlServiceModuleT::OnShutdown](#onshutdown)|Substitui esse método para desligar o serviço|  
|[CAtlServiceModuleT::OnStop](#onstop)|Substituir este método para parar o serviço|  
|[CAtlServiceModuleT::OnUnknownRequest](#onunknownrequest)|Substituir este método para manipular solicitações desconhecidas para o serviço|  
|[CAtlServiceModuleT::ParseCommandLine](#parsecommandline)|Analisa a linha de comando e executa o registro se necessário.|  
|[CAtlServiceModuleT::PreMessageLoop](#premessageloop)|Este método é chamado imediatamente antes de entrar no loop de mensagem.|  
|[CAtlServiceModuleT::RegisterAppId](#registerappid)|Registra o serviço no registro.|  
|[CAtlServiceModuleT::Run](#run)|Executa o serviço.|  
|[CAtlServiceModuleT::ServiceMain](#servicemain)|O método chamado pelo Gerenciador de controle de serviço.|  
|[CAtlServiceModuleT::SetServiceStatus](#setservicestatus)|Atualiza o status do serviço.|  
|[CAtlServiceModuleT::Start](#start)|Chamado por `CAtlServiceModuleT::WinMain` quando o serviço é iniciado.|  
|[CAtlServiceModuleT::Uninstall](#uninstall)|Interrompe e remove o serviço.|  
|[CAtlServiceModuleT::Unlock](#unlock)|Contagem de bloqueio do serviço diminui.|  
|[CAtlServiceModuleT::UnregisterAppId](#unregisterappid)|Remove o serviço de registro.|  
|[CAtlServiceModuleT::WinMain](#winmain)|Este método implementa o código necessário para executar o serviço.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlServiceModuleT::m_bService](#m_bservice)|Sinalizador que indica que o programa é executado como um serviço.|  
|[CAtlServiceModuleT::m_dwThreadID](#m_dwthreadid)|Variável de membro armazenando o identificador de thread.|  
|[CAtlServiceModuleT::m_hServiceStatus](#m_hservicestatus)|Variável de membro armazenar um identificador para a estrutura de informações de status do serviço atual.|  
|[CAtlServiceModuleT::m_status](#m_status)|Variável de membro armazenar a estrutura de informações de status do serviço atual.|  
|[CAtlServiceModuleT::m_szServiceName](#m_szservicename)|O nome do serviço que está sendo registrado.|  
  
## <a name="remarks"></a>Comentários  
 `CAtlServiceModuleT`, derivada de [CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md), implementa um módulo de serviço de ATL. `CAtlServiceModuleT`fornece métodos para processamento de linha de comando, instalação, registro e remoção. Se a funcionalidade adicional é necessária, esses e outros métodos podem ser substituídos.  
  
 Esta classe substitui o obsoleto [classe CComModule](../../atl/reference/ccommodule-class.md) usado em versões anteriores do ATL. Consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [_ATL_MODULE](atl-typedefs.md#_atl_module)  
  
 [CAtlModule](../../atl/reference/catlmodule-class.md)  
  
 [CAtlModuleT](../../atl/reference/catlmodulet-class.md)  
  
 [CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md)  
  
 `CAtlServiceModuleT`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  
##  <a name="a-namecatlservicemoduleta--catlservicemoduletcatlservicemodulet"></a><a name="catlservicemodulet"></a>CAtlServiceModuleT::CAtlServiceModuleT  
 O construtor.  
  
```
CAtlServiceModuleT() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Inicializa os membros de dados e define o status do serviço inicial.  
  
##  <a name="a-namehandlera--catlservicemodulethandler"></a><a name="handler"></a>CAtlServiceModuleT::Handler  
 A rotina de manipulador para o serviço.  
  
```
void Handler(DWORD dwOpcode) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwOpcode*  
 Uma opção que define a operação de manipulador. Para obter detalhes, consulte os comentários.  
  
### <a name="remarks"></a>Comentários  
 Este é o código que chama o Gerenciador de controle de serviços (SCM) para recuperar o status das instruções de serviço e o problema como parar ou pausar. O SCM passa um código de operação, mostrado abaixo, `Handler` para indicar que o serviço deve fazer.  
  
|Código de operação|Significado|  
|--------------------|-------------|  
|SERVICE_CONTROL_STOP|Interrompe o serviço. Substituir o método [CAtlServiceModuleT::OnStop](#onstop) em atlbase. h para alterar o comportamento.|  
|SERVICE_CONTROL_PAUSE|Usuário foi implementado. Substituir o método vazio [CAtlServiceModuleT::OnPause](#onpause) em atlbase. h para pausar o serviço.|  
|SERVICE_CONTROL_CONTINUE|Usuário foi implementado. Substituir o método vazio [CAtlServiceModuleT::OnContinue](#oncontinue) em atlbase. h para continuar o serviço.|  
|SERVICE_CONTROL_INTERROGATE|Usuário foi implementado. Substituir o método vazio [CAtlServiceModuleT::OnInterrogate](#oninterrogate) em atlbase. h para interrogar o serviço.|  
|SERVICE_CONTROL_SHUTDOWN|Usuário foi implementado. Substituir o método vazio [CAtlServiceModuleT::OnShutdown](#onshutdown) em atlbase. h para desligar o serviço.|  
  
 Se o código de operação não for reconhecido, o método [CAtlServiceModuleT::OnUnknownRequest](#onunknownrequest) é chamado.  
  
 Um serviço do padrão gerado pelo ATL apenas lida com a instrução stop. Se o SCM passa a instrução stop, o serviço instrui o SCM que o programa está prestes a parar. Em seguida, chama o serviço `PostThreadMessage` para postar uma mensagem quit para si mesmo. Isso encerra o loop de mensagem e o serviço, por fim, será fechada.  
  
##  <a name="a-nameinitializesecuritya--catlservicemoduletinitializesecurity"></a><a name="initializesecurity"></a>CAtlServiceModuleT::InitializeSecurity  
 O padrão fornece configurações de segurança para o serviço.  
  
```
HRESULT InitializeSecurity() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 No Visual Studio .NET 2003, esse método não é implementado na classe base. O Assistente de projeto do Visual Studio inclui esse método no código gerado, mas um erro de compilação ocorrerá se um projeto criado em uma versão anterior do Visual C++ é compilado usando ATL 7.1. Qualquer classe que deriva de `CAtlServiceModuleT` devem implementar esse método na classe derivada.  
  
 Usar autenticação PKT nível, o nível de representação de RPC_C_IMP_LEVEL_IDENTIFY e um descritor de segurança apropriado de não-nulo na chamada para **CoInitializeSecurity**.  
  
 Para projetos de serviço nonattributed gerado pelo assistente, isso seria  
  
 [!code-cpp[NVC_ATL_Service n º&1;](../../atl/reference/codesnippet/cpp/catlservicemodulet-class_1.cpp)]  
  
 Para projetos de serviço atribuída, isso seria  
  
 [!code-cpp[NVC_ATL_ServiceAttrib n º&1;](../../atl/reference/codesnippet/cpp/catlservicemodulet-class_2.cpp)]  
  
##  <a name="a-nameinstalla--catlservicemoduletinstall"></a><a name="install"></a>CAtlServiceModuleT::Install  
 Instala e cria o serviço.  
  
```
BOOL Install() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro em caso de êxito, FALSE em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Instala o serviço para o banco de dados do Gerenciador de controle de serviços (SCM) e, em seguida, cria o objeto de serviço. Se o serviço não pôde ser criado, é exibida uma caixa de mensagem e o método retornará FALSE.  
  
##  <a name="a-nameisinstalleda--catlservicemoduletisinstalled"></a><a name="isinstalled"></a>CAtlServiceModuleT::IsInstalled  
 Confirma que o serviço foi instalado.  
  
```
BOOL IsInstalled() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna TRUE se o serviço for instalado, FALSO caso contrário.  
  
##  <a name="a-namelogeventa--catlservicemoduletlogevent"></a><a name="logevent"></a>CAtlServiceModuleT::LogEvent  
 Grava o log de eventos.  
  
```
void __cdecl LogEvent(LPCTSTR pszFormat, ...) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszFormat`  
 A cadeia de caracteres a ser gravada no log de eventos.  
  
 ...  
 Opcionais extras cadeias de caracteres a ser gravado no log de eventos.  
  
### <a name="remarks"></a>Comentários  
 Esse método grava detalhes em um log de eventos, usando a função [ReportEvent](http://msdn.microsoft.com/library/windows/desktop/aa363679). Se nenhum serviço estiver em execução, a cadeia de caracteres é enviada para o console.  
  
##  <a name="a-namembservicea--catlservicemoduletmbservice"></a><a name="m_bservice"></a>CAtlServiceModuleT::m_bService  
 Sinalizador que indica que o programa é executado como um serviço.  
  
```
BOOL m_bService;
```  
  
### <a name="remarks"></a>Comentários  
 Usado para diferenciar um serviço. EXE de um executável de aplicativo.  
  
##  <a name="a-namemdwthreadida--catlservicemoduletmdwthreadid"></a><a name="m_dwthreadid"></a>CAtlServiceModuleT::m_dwThreadID  
 Variável de membro armazenando o identificador de thread do serviço.  
  
```
DWORD m_dwThreadID;
```  
  
### <a name="remarks"></a>Comentários  
 Essa variável armazena o identificador de thread do thread atual.  
  
##  <a name="a-namemhservicestatusa--catlservicemoduletmhservicestatus"></a><a name="m_hservicestatus"></a>CAtlServiceModuleT::m_hServiceStatus  
 Variável de membro armazenar um identificador para a estrutura de informações de status do serviço atual.  
  
```
SERVICE_STATUS_HANDLE m_hServiceStatus;
```  
  
### <a name="remarks"></a>Comentários  
 O [SERVICE_STATUS](http://msdn.microsoft.com/library/windows/desktop/ms685996) estrutura contém informações sobre um serviço.  
  
##  <a name="a-namemstatusa--catlservicemoduletmstatus"></a><a name="m_status"></a>CAtlServiceModuleT::m_status  
 Variável de membro armazenar a estrutura de informações de status do serviço atual.  
  
```
SERVICE_STATUS m_status;
```  
  
### <a name="remarks"></a>Comentários  
 O [SERVICE_STATUS](http://msdn.microsoft.com/library/windows/desktop/ms685996) estrutura contém informações sobre um serviço.  
  
##  <a name="a-namemszservicenamea--catlservicemoduletmszservicename"></a><a name="m_szservicename"></a>CAtlServiceModuleT::m_szServiceName  
 O nome do serviço que está sendo registrado.  
  
```
TCHAR [256] m_szServiceName;
```  
  
### <a name="remarks"></a>Comentários  
 Uma cadeia terminada em nulo que armazena o nome do serviço.  
  
##  <a name="a-nameoncontinuea--catlservicemoduletoncontinue"></a><a name="oncontinue"></a>CAtlServiceModuleT::OnContinue  
 Substitua este método para continuar o serviço.  
  
```
void OnContinue() throw();
```  
  
##  <a name="a-nameoninterrogatea--catlservicemoduletoninterrogate"></a><a name="oninterrogate"></a>CAtlServiceModuleT::OnInterrogate  
 Substitua este método para interrogar o serviço.  
  
```
void OnInterrogate() throw();
```  
  
##  <a name="a-nameonpausea--catlservicemoduletonpause"></a><a name="onpause"></a>CAtlServiceModuleT::OnPause  
 Substitua este método para pausar o serviço.  
  
```
void OnPause() throw();
```  
  
##  <a name="a-nameonshutdowna--catlservicemoduletonshutdown"></a><a name="onshutdown"></a>CAtlServiceModuleT::OnShutdown  
 Substitua este método para desligar o serviço.  
  
```
void OnShutdown() throw();
```  
  
##  <a name="a-nameonstopa--catlservicemoduletonstop"></a><a name="onstop"></a>CAtlServiceModuleT::OnStop  
 Substitua este método para parar o serviço.  
  
```
void OnStop() throw();
```  
  
##  <a name="a-nameonunknownrequesta--catlservicemoduletonunknownrequest"></a><a name="onunknownrequest"></a>CAtlServiceModuleT::OnUnknownRequest  
 Substitua este método para manipular solicitações desconhecidas para o serviço.  
  
```
void OnUnknownRequest(DWORD /* dwOpcode*/) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 */\*dwOpcode\*/*  
 Reservado.  
  
##  <a name="a-nameparsecommandlinea--catlservicemoduletparsecommandline"></a><a name="parsecommandline"></a>CAtlServiceModuleT::ParseCommandLine  
 Analisa a linha de comando e executa o registro se necessário.  
  
```
bool ParseCommandLine(LPCTSTR lpCmdLine, HRESULT* pnRetCode) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpCmdLine`  
 A linha de comando.  
  
 `pnRetCode`  
 O HRESULT correspondente para o registro (se ele ocorreu).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro no êxito ou false se o arquivo RGS fornecido na linha de comando não pôde ser registrado.  
  
### <a name="remarks"></a>Comentários  
 Analisa a linha de comando e registra ou cancela o registro do arquivo RGS fornecido se necessário. Esse método chama [CAtlExeModuleT::ParseCommandLine](../../atl/reference/catlexemodulet-class.md#parsecommandline) para verificar se há **/RegServer** e **/UnregServer**. Adicionando o argumento **- serviço** registrará o serviço.  
  
##  <a name="a-namepremessageloopa--catlservicemoduletpremessageloop"></a><a name="premessageloop"></a>CAtlServiceModuleT::PreMessageLoop  
 Este método é chamado imediatamente antes de entrar no loop de mensagem.  
  
```
HRESULT PreMessageLoop(int nShowCmd) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nShowCmd`  
 Este parâmetro é passado para [CAtlExeModuleT::PreMessageLoop](../../atl/reference/catlexemodulet-class.md#premessageloop).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para adicionar o código de inicialização personalizado para o serviço.  
  
##  <a name="a-nameregisterappida--catlservicemoduletregisterappid"></a><a name="registerappid"></a>CAtlServiceModuleT::RegisterAppId  
 Registra o serviço no registro.  
  
```
inline HRESULT RegisterAppId(bool bService = false) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *bService*  
 Deve ser verdadeira para registrar como um serviço.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="a-nameruna--catlservicemoduletrun"></a><a name="run"></a>CAtlServiceModuleT::Run  
 Executa o serviço.  
  
```
HRESULT Run(int nShowCmd = SW_HIDE) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nShowCmd`  
 Especifica como a janela deve ser mostrado. Esse parâmetro pode ser um dos valores discutidos a [WinMain](http://msdn.microsoft.com/library/windows/desktop/ms633559) seção. O valor padrão é SW_HIDE.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Depois de ser chamado, **executar** chamadas [CAtlServiceModuleT::PreMessageLoop](#premessageloop), [CAtlExeModuleT::RunMessageLoop](../../atl/reference/catlexemodulet-class.md#runmessageloop), e [CAtlExeModuleT::PostMessageLoop](../../atl/reference/catlexemodulet-class.md#postmessageloop).  
  
##  <a name="a-nameservicemaina--catlservicemoduletservicemain"></a><a name="servicemain"></a>CAtlServiceModuleT::ServiceMain  
 Este método é chamado pelo Gerenciador de controle de serviço.  
  
```
void ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwArgc*  
 O argumento de argc.  
  
 *lpszArgv*  
 O argumento argv.  
  
### <a name="remarks"></a>Comentários  
 O Gerenciador de controle de serviços (SCM) chama `ServiceMain` quando você abre o aplicativo de serviços no painel de controle, selecione o serviço e clique em Iniciar.  
  
 Após o SCM chama `ServiceMain`, um serviço precisa dar o SCM uma função de manipulador. Essa função permite que o SCM obter o status do serviço e passar instruções específicas (como pausar ou parar). Em seguida, [CAtlServiceModuleT::Run](#run) é chamado para realizar o trabalho principal do serviço. **Executar** continua a executar até que o serviço é interrompido.  
  
##  <a name="a-namesetservicestatusa--catlservicemoduletsetservicestatus"></a><a name="setservicestatus"></a>CAtlServiceModuleT::SetServiceStatus  
 Esse método atualiza o status do serviço.  
  
```
void SetServiceStatus(DWORD dwState) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwState`  
 O novo status. Consulte [SetServiceStatus](http://msdn.microsoft.com/library/windows/desktop/ms686241) para os valores possíveis.  
  
### <a name="remarks"></a>Comentários  
 Atualiza as informações de status do Gerenciador de controle de serviço para o serviço. Ele é chamado por [CAtlServiceModuleT::Run](#run), [CAtlServiceModuleT::ServiceMain](#servicemain) e outros métodos de manipulador. O status também é armazenado na variável membro [CAtlServiceModuleT::m_status](#m_status).  
  
##  <a name="a-namestarta--catlservicemoduletstart"></a><a name="start"></a>CAtlServiceModuleT::Start  
 Chamado por `CAtlServiceModuleT::WinMain` quando o serviço é iniciado.  
  
```
HRESULT Start(int nShowCmd) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nShowCmd`  
 Especifica como a janela deve ser mostrado. Esse parâmetro pode ser um dos valores discutidos a [WinMain](http://msdn.microsoft.com/library/windows/desktop/ms633559) seção.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O [CAtlServiceModuleT::WinMain](#winmain) método manipula o registro e instalação, bem como as tarefas envolvidas na remoção de entradas do registro e desinstalar o módulo. Quando o serviço é executado, `WinMain` chamadas **iniciar**.  
  
##  <a name="a-nameuninstalla--catlservicemoduletuninstall"></a><a name="uninstall"></a>CAtlServiceModuleT::Uninstall  
 Interrompe e remove o serviço.  
  
```
BOOL Uninstall() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro em caso de êxito, FALSE em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Interrompe o serviço de execução e a remove do banco de dados do Gerenciador de controle de serviço.  
  
##  <a name="a-nameunlocka--catlservicemoduletunlock"></a><a name="unlock"></a>CAtlServiceModuleT::Unlock  
 Contagem de bloqueio do serviço diminui.  
  
```
LONG Unlock() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a contagem de bloqueio, que pode ser útil para o diagnóstico e depuração.  
  
##  <a name="a-nameunregisterappida--catlservicemoduletunregisterappid"></a><a name="unregisterappid"></a>CAtlServiceModuleT::UnregisterAppId  
 Remove o serviço de registro.  
  
```
HRESULT UnregisterAppId() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="a-namewinmaina--catlservicemoduletwinmain"></a><a name="winmain"></a>CAtlServiceModuleT::WinMain  
 Este método implementa o código necessário para iniciar o serviço.  
  
```
int WinMain(int nShowCmd) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nShowCmd`  
 Especifica como a janela deve ser mostrado. Esse parâmetro pode ser um dos valores discutidos a [WinMain](http://msdn.microsoft.com/library/windows/desktop/ms633559) seção.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor de retorno do serviço.  
  
### <a name="remarks"></a>Comentários  
 Este método processa a linha de comando (com [CAtlServiceModuleT::ParseCommandLine](#parsecommandline)) e, em seguida, inicia o serviço (usando [CAtlServiceModuleT::Start](#start)).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

