---
title: Classe CAtlServiceModuleT
ms.date: 05/06/2019
f1_keywords:
- CAtlServiceModuleT
- ATLBASE/ATL::CAtlServiceModuleT
- ATLBASE/ATL::CAtlServiceModuleT::CAtlServiceModuleT
- ATLBASE/ATL::CAtlServiceModuleT::Handler
- ATLBASE/ATL::CAtlServiceModuleT::InitializeSecurity
- ATLBASE/ATL::CAtlServiceModuleT::Install
- ATLBASE/ATL::CAtlServiceModuleT::IsInstalled
- ATLBASE/ATL::CAtlServiceModuleT::LogEvent
- ATLBASE/ATL::CAtlServiceModuleT::OnContinue
- ATLBASE/ATL::CAtlServiceModuleT::OnInterrogate
- ATLBASE/ATL::CAtlServiceModuleT::OnPause
- ATLBASE/ATL::CAtlServiceModuleT::OnShutdown
- ATLBASE/ATL::CAtlServiceModuleT::OnStop
- ATLBASE/ATL::CAtlServiceModuleT::OnUnknownRequest
- ATLBASE/ATL::CAtlServiceModuleT::ParseCommandLine
- ATLBASE/ATL::CAtlServiceModuleT::PreMessageLoop
- ATLBASE/ATL::CAtlServiceModuleT::RegisterAppId
- ATLBASE/ATL::CAtlServiceModuleT::Run
- ATLBASE/ATL::CAtlServiceModuleT::ServiceMain
- ATLBASE/ATL::CAtlServiceModuleT::SetServiceStatus
- ATLBASE/ATL::CAtlServiceModuleT::Start
- ATLBASE/ATL::CAtlServiceModuleT::Uninstall
- ATLBASE/ATL::CAtlServiceModuleT::Unlock
- ATLBASE/ATL::CAtlServiceModuleT::UnregisterAppId
- ATLBASE/ATL::CAtlServiceModuleT::WinMain
- ATLBASE/ATL::CAtlServiceModuleT::m_bService
- ATLBASE/ATL::CAtlServiceModuleT::m_dwThreadID
- ATLBASE/ATL::CAtlServiceModuleT::m_hServiceStatus
- ATLBASE/ATL::CAtlServiceModuleT::m_status
- ATLBASE/ATL::CAtlServiceModuleT::m_szServiceName
helpviewer_keywords:
- CAtlServiceModuleT class
ms.assetid: 8fc753ce-4a50-402b-9b4a-0a4ce5dd496c
ms.openlocfilehash: 1d44e356d907afcb261c0b4a765f8807bb54dc19
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65221180"
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

*T*<br/>
Sua classe derivada de `CAtlServiceModuleT`.

*nServiceNameID*<br/>
O identificador de recurso do serviço.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlServiceModuleT::CAtlServiceModuleT](#catlservicemodulet)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlServiceModuleT::Handler](#handler)|A rotina do manipulador para o serviço.|
|[CAtlServiceModuleT::InitializeSecurity](#initializesecurity)|Fornece o padrão de configurações de segurança para o serviço.|
|[CAtlServiceModuleT::Install](#install)|Instala e cria o serviço.|
|[CAtlServiceModuleT::IsInstalled](#isinstalled)|Confirma que o serviço foi instalado.|
|[CAtlServiceModuleT::LogEvent](#logevent)|Grava o log de eventos.|
|[CAtlServiceModuleT::OnContinue](#oncontinue)|Substitua este método para continuar o serviço.|
|[CAtlServiceModuleT::OnInterrogate](#oninterrogate)|Substitua este método para interrogar o serviço.|
|[CAtlServiceModuleT::OnPause](#onpause)|Substitua este método para pausar o serviço.|
|[CAtlServiceModuleT::OnShutdown](#onshutdown)|Substitua este método para desligar o serviço|
|[CAtlServiceModuleT::OnStop](#onstop)|Substitua este método para parar o serviço|
|[CAtlServiceModuleT::OnUnknownRequest](#onunknownrequest)|Substitua este método para lidar com solicitações desconhecidas para o serviço|
|[CAtlServiceModuleT::ParseCommandLine](#parsecommandline)|Analisa a linha de comando e executa o registro se necessário.|
|[CAtlServiceModuleT::PreMessageLoop](#premessageloop)|Este método é chamado imediatamente antes de entrar no loop de mensagem.|
|[CAtlServiceModuleT::RegisterAppId](#registerappid)|Registra o serviço no registro.|
|[CAtlServiceModuleT::Run](#run)|Executa o serviço.|
|[CAtlServiceModuleT::ServiceMain](#servicemain)|O método chamado pelo Gerenciador de controle de serviço.|
|[CAtlServiceModuleT::SetServiceStatus](#setservicestatus)|Atualiza o status do serviço.|
|[CAtlServiceModuleT::Start](#start)|Chamado pelo `CAtlServiceModuleT::WinMain` quando o serviço é iniciado.|
|[CAtlServiceModuleT::Uninstall](#uninstall)|Interrompe e remove o serviço.|
|[CAtlServiceModuleT::Unlock](#unlock)|Diminui contagem de bloqueio do serviço.|
|[CAtlServiceModuleT::UnregisterAppId](#unregisterappid)|Remove o serviço do registro.|
|[CAtlServiceModuleT::WinMain](#winmain)|Esse método implementa o código necessário para executar o serviço.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlServiceModuleT::m_bService](#m_bservice)|Sinalizador que indica que o programa for executado como um serviço.|
|[CAtlServiceModuleT::m_dwThreadID](#m_dwthreadid)|Variável de membro armazena o identificador de thread.|
|[CAtlServiceModuleT::m_hServiceStatus](#m_hservicestatus)|Variável de membro armazenar um identificador para a estrutura de informações de status do serviço atual.|
|[CAtlServiceModuleT::m_status](#m_status)|Variável de membro armazenar a estrutura de informações de status do serviço atual.|
|[CAtlServiceModuleT::m_szServiceName](#m_szservicename)|O nome do serviço que está sendo registrado.|

## <a name="remarks"></a>Comentários

`CAtlServiceModuleT`, derivada de [CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md), implementa um módulo de serviço do ATL. `CAtlServiceModuleT` fornece métodos para processamento de linha de comando, a instalação, registro e remoção. Se a funcionalidade adicional for necessária, esses e outros métodos podem ser substituídos.

Essa classe substitui o obsoletos [classe CComModule](../../atl/reference/ccommodule-class.md) usado em versões anteriores do ATL. Ver [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[_ATL_MODULE](atl-typedefs.md#_atl_module)

[CAtlModule](../../atl/reference/catlmodule-class.md)

[CAtlModuleT](../../atl/reference/catlmodulet-class.md)

[CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md)

`CAtlServiceModuleT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="catlservicemodulet"></a>  CAtlServiceModuleT::CAtlServiceModuleT

O construtor.

```
CAtlServiceModuleT() throw();
```

### <a name="remarks"></a>Comentários

Inicializa os membros de dados e define o status do serviço inicial.

##  <a name="handler"></a>  CAtlServiceModuleT::Handler

A rotina do manipulador para o serviço.

```
void Handler(DWORD dwOpcode) throw();
```

### <a name="parameters"></a>Parâmetros

*dwOpcode*<br/>
Um comutador que define a operação do manipulador. Para obter detalhes, consulte os comentários.

### <a name="remarks"></a>Comentários

Este é o código que o Gerenciador de controle de serviço (SCM) chama para recuperar o status das instruções de serviço e o problema, como parar ou pausar. O SCM passa um código de operação, mostrado abaixo, `Handler` para indicar o que o serviço deve fazer.

|Código de operação|Significado|
|--------------------|-------------|
|SERVICE_CONTROL_STOP|Interrompe o serviço. Substitua o método [CAtlServiceModuleT::OnStop](#onstop) em atlbase. h para alterar o comportamento.|
|SERVICE_CONTROL_PAUSE|Usuário foi implementado. Substitua o método vazio [CAtlServiceModuleT::OnPause](#onpause) em atlbase. h para pausar o serviço.|
|SERVICE_CONTROL_CONTINUE|Usuário foi implementado. Substitua o método vazio [CAtlServiceModuleT::OnContinue](#oncontinue) em atlbase. h para continuar o serviço.|
|SERVICE_CONTROL_INTERROGATE|Usuário foi implementado. Substitua o método vazio [CAtlServiceModuleT::OnInterrogate](#oninterrogate) em atlbase. h para interrogar o serviço.|
|SERVICE_CONTROL_SHUTDOWN|Usuário foi implementado. Substitua o método vazio [CAtlServiceModuleT::OnShutdown](#onshutdown) em atlbase. h para desligar o serviço.|

Se o código de operação não for reconhecido, o método [CAtlServiceModuleT::OnUnknownRequest](#onunknownrequest) é chamado.

Um serviço do padrão gerado pelo ATL só lida com a instrução stop. Se o SCM passa a instrução stop, o serviço informa ao SCM que o programa está prestes a parar. Em seguida, chama o serviço `PostThreadMessage` para postar uma mensagem para si mesmo. Isso encerra o loop de mensagem e, por fim, o serviço fechará.

##  <a name="initializesecurity"></a>  CAtlServiceModuleT::InitializeSecurity

Fornece o padrão de configurações de segurança para o serviço.

```
HRESULT InitializeSecurity() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Qualquer classe que deriva de `CAtlServiceModuleT` devem implementar esse método na classe derivada.

Usar a autenticação de nível PKT, nível de representação de RPC_C_IMP_LEVEL_IDENTIFY e um descritor de segurança de não nulo apropriado na chamada para `CoInitializeSecurity`.

Para projetos de serviço nonattributed gerado pelo assistente, isso seria em

[!code-cpp[NVC_ATL_Service#1](../../atl/reference/codesnippet/cpp/catlservicemodulet-class_1.cpp)]

Para projetos de serviço atribuída, isso seria em

[!code-cpp[NVC_ATL_ServiceAttrib#1](../../atl/reference/codesnippet/cpp/catlservicemodulet-class_2.cpp)]

##  <a name="install"></a>  CAtlServiceModuleT::Install

Instala e cria o serviço.

```
BOOL Install() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

Instala o serviço para o banco de dados do Gerenciador de controle de serviço (SCM) e, em seguida, cria o objeto de serviço. Se o serviço não pôde ser criado, uma caixa de mensagem é exibida e o método retornará FALSE.

##  <a name="isinstalled"></a>  CAtlServiceModuleT::IsInstalled

Confirma que o serviço foi instalado.

```
BOOL IsInstalled() throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o serviço estiver instalado, FALSE caso contrário.

##  <a name="logevent"></a>  CAtlServiceModuleT::LogEvent

Grava o log de eventos.

```
void __cdecl LogEvent(LPCTSTR pszFormat, ...) throw();
```

### <a name="parameters"></a>Parâmetros

*pszFormat*<br/>
A cadeia de caracteres a ser gravada no log de eventos.

*...*<br/>
Opcionais extras cadeias de caracteres a serem gravados no log de eventos.

### <a name="remarks"></a>Comentários

Esse método grava detalhes em um log de eventos, usando a função [ReportEvent](/windows/desktop/api/winbase/nf-winbase-reporteventa). Se nenhum serviço está em execução, a cadeia de caracteres será enviada para o console.

##  <a name="m_bservice"></a>  CAtlServiceModuleT::m_bService

Sinalizador que indica que o programa for executado como um serviço.

```
BOOL m_bService;
```

### <a name="remarks"></a>Comentários

Usado para distinguir um serviço. EXE de um EXE do aplicativo.

##  <a name="m_dwthreadid"></a>  CAtlServiceModuleT::m_dwThreadID

Variável de membro armazena o identificador de thread do serviço.

```
DWORD m_dwThreadID;
```

### <a name="remarks"></a>Comentários

Essa variável armazena o identificador de thread do thread atual.

##  <a name="m_hservicestatus"></a>  CAtlServiceModuleT::m_hServiceStatus

Variável de membro armazenar um identificador para a estrutura de informações de status do serviço atual.

```
SERVICE_STATUS_HANDLE m_hServiceStatus;
```

### <a name="remarks"></a>Comentários

O [SERVICE_STATUS](/windows/desktop/api/winsvc/ns-winsvc-_service_status) estrutura contém informações sobre um serviço.

##  <a name="m_status"></a>  CAtlServiceModuleT::m_status

Variável de membro armazenar a estrutura de informações de status do serviço atual.

```
SERVICE_STATUS m_status;
```

### <a name="remarks"></a>Comentários

O [SERVICE_STATUS](/windows/desktop/api/winsvc/ns-winsvc-_service_status) estrutura contém informações sobre um serviço.

##  <a name="m_szservicename"></a>  CAtlServiceModuleT::m_szServiceName

O nome do serviço que está sendo registrado.

```
TCHAR [256] m_szServiceName;
```

### <a name="remarks"></a>Comentários

Uma cadeia terminada em nulo que armazena o nome do serviço.

##  <a name="oncontinue"></a>  CAtlServiceModuleT::OnContinue

Substitua este método para continuar o serviço.

```
void OnContinue() throw();
```

##  <a name="oninterrogate"></a>  CAtlServiceModuleT::OnInterrogate

Substitua este método para interrogar o serviço.

```
void OnInterrogate() throw();
```

##  <a name="onpause"></a>  CAtlServiceModuleT::OnPause

Substitua este método para pausar o serviço.

```
void OnPause() throw();
```

##  <a name="onshutdown"></a>  CAtlServiceModuleT::OnShutdown

Substitua este método para desligar o serviço.

```
void OnShutdown() throw();
```

##  <a name="onstop"></a>  CAtlServiceModuleT::OnStop

Substitua este método para parar o serviço.

```
void OnStop() throw();
```

##  <a name="onunknownrequest"></a>  CAtlServiceModuleT::OnUnknownRequest

Substitua este método para manipular solicitações desconhecidas para o serviço.

```
void OnUnknownRequest(DWORD /* dwOpcode*/) throw();
```

### <a name="parameters"></a>Parâmetros

*dwOpcode*<br/>
Reservado.

##  <a name="parsecommandline"></a>  CAtlServiceModuleT::ParseCommandLine

Analisa a linha de comando e executa o registro se necessário.

```
bool ParseCommandLine(LPCTSTR lpCmdLine, HRESULT* pnRetCode) throw();
```

### <a name="parameters"></a>Parâmetros

*lpCmdLine*<br/>
A linha de comando.

*pnRetCode*<br/>
O HRESULT que corresponde ao registro (se ela foi realizada).

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro no êxito ou falso se o arquivo RGS fornecido na linha de comando não pôde ser registrado.

### <a name="remarks"></a>Comentários

Analisa a linha de comando e registra ou cancela o registro do arquivo RGS fornecido se necessário. Este método chama [CAtlExeModuleT::ParseCommandLine](../../atl/reference/catlexemodulet-class.md#parsecommandline) para verificar se há **/RegServer** e **opção /UnregServer**. Adicionando o argumento **- / serviço** registrará o serviço.

##  <a name="premessageloop"></a>  CAtlServiceModuleT::PreMessageLoop

Este método é chamado imediatamente antes de entrar no loop de mensagem.

```
HRESULT PreMessageLoop(int nShowCmd) throw();
```

### <a name="parameters"></a>Parâmetros

*nShowCmd*<br/>
Esse parâmetro é passado para [CAtlExeModuleT::PreMessageLoop](../../atl/reference/catlexemodulet-class.md#premessageloop).

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Substitua este método para adicionar o código de inicialização personalizada para o serviço.

##  <a name="registerappid"></a>  CAtlServiceModuleT::RegisterAppId

Registra o serviço no registro.

```
inline HRESULT RegisterAppId(bool bService = false) throw();
```

### <a name="parameters"></a>Parâmetros

*bService*<br/>
Deve ser true para registrar como um serviço.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

##  <a name="run"></a>  CAtlServiceModuleT::Run

Executa o serviço.

```
HRESULT Run(int nShowCmd = SW_HIDE) throw();
```

### <a name="parameters"></a>Parâmetros

*nShowCmd*<br/>
Especifica como a janela a ser mostrado. Esse parâmetro pode ser um dos valores discutidos a [WinMain](/windows/desktop/api/winbase/nf-winbase-winmain) seção. O valor padrão é SW_HIDE.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Depois de ser chamado, `Run` chamadas [CAtlServiceModuleT::PreMessageLoop](#premessageloop), [CAtlExeModuleT::RunMessageLoop](../../atl/reference/catlexemodulet-class.md#runmessageloop), e [CAtlExeModuleT::PostMessageLoop](../../atl/reference/catlexemodulet-class.md#postmessageloop).

##  <a name="servicemain"></a>  CAtlServiceModuleT::ServiceMain

Esse método é chamado pelo Gerenciador de controle de serviço.

```
void ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv) throw();
```

### <a name="parameters"></a>Parâmetros

*dwArgc*<br/>
O argumento argc.

*lpszArgv*<br/>
O argumento argv.

### <a name="remarks"></a>Comentários

O Gerenciador de controle de serviço (SCM) chama `ServiceMain` quando você abre o aplicativo de serviços no painel de controle, selecione o serviço e clique em Iniciar.

Depois do SCM chama `ServiceMain`, um serviço deve fornecer o SCM uma função de manipulador. Essa função permite que o SCM obter o status do serviço e passar as instruções específicas (como pausar ou parar). Subsequentemente, [catlservicemodulet:: Run](#run) é chamado para executar o trabalho principal do serviço. `Run` continua sendo executado até que o serviço está parado.

##  <a name="setservicestatus"></a>  CAtlServiceModuleT::SetServiceStatus

Esse método atualiza o status do serviço.

```
void SetServiceStatus(DWORD dwState) throw();
```

### <a name="parameters"></a>Parâmetros

*dwState*<br/>
O novo status. Ver [SetServiceStatus](/windows/desktop/api/winsvc/nf-winsvc-setservicestatus) para os valores possíveis.

### <a name="remarks"></a>Comentários

Atualiza as informações de status do Gerenciador de controle de serviço para o serviço. Ele é chamado pelo [catlservicemodulet:: Run](#run), [catlservicemodulet:: Servicemain](#servicemain) e outros métodos de manipulador. O status também é armazenado na variável membro [CAtlServiceModuleT::m_status](#m_status).

##  <a name="start"></a>  CAtlServiceModuleT::Start

Chamado pelo `CAtlServiceModuleT::WinMain` quando o serviço é iniciado.

```
HRESULT Start(int nShowCmd) throw();
```

### <a name="parameters"></a>Parâmetros

*nShowCmd*<br/>
Especifica como a janela a ser mostrado. Esse parâmetro pode ser um dos valores discutidos a [WinMain](/windows/desktop/api/winbase/nf-winbase-winmain) seção.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

O [CAtlServiceModuleT::WinMain](#winmain) método manipula o registro e instalação, bem como as tarefas envolvidas na remoção de entradas do registro e desinstalar o módulo. Quando o serviço é executado, `WinMain` chamadas `Start`.

##  <a name="uninstall"></a>  CAtlServiceModuleT::Uninstall

Interrompe e remove o serviço.

```
BOOL Uninstall() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

Interrompe o serviço de execução e a remove do banco de dados do Gerenciador de controle de serviço.

##  <a name="unlock"></a>  CAtlServiceModuleT::Unlock

Diminui contagem de bloqueio do serviço.

```
LONG Unlock() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna a contagem de bloqueio, que pode ser útil para diagnóstico e depuração.

##  <a name="unregisterappid"></a>  CAtlServiceModuleT::UnregisterAppId

Remove o serviço do registro.

```
HRESULT UnregisterAppId() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

##  <a name="winmain"></a>  CAtlServiceModuleT::WinMain

Esse método implementa o código necessário para iniciar o serviço.

```
int WinMain(int nShowCmd) throw();
```

### <a name="parameters"></a>Parâmetros

*nShowCmd*<br/>
Especifica como a janela a ser mostrado. Esse parâmetro pode ser um dos valores discutidos a [WinMain](/windows/desktop/api/winbase/nf-winbase-winmain) seção.

### <a name="return-value"></a>Valor de retorno

Retorna o valor de retorno do serviço.

### <a name="remarks"></a>Comentários

Este método processa a linha de comando (com [CAtlServiceModuleT::ParseCommandLine](#parsecommandline)) e, em seguida, inicia o serviço (usando [catlservicemodulet:: Start](#start)).

## <a name="see-also"></a>Consulte também

[Classe CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
