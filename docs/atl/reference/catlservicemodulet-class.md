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
ms.openlocfilehash: 095d909fefe0053b742368f260cf61937c2f5426
ms.sourcegitcommit: 46d24d6e70c03e05484923d9efc6ed5150e96a64
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2019
ms.locfileid: "68915864"
---
# <a name="catlservicemodulet-class"></a>Classe CAtlServiceModuleT

Essa classe implementa um serviço do.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

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
|[CAtlServiceModuleT::InitializeSecurity](#initializesecurity)|Fornece as configurações de segurança padrão para o serviço.|
|[CAtlServiceModuleT::Install](#install)|Instala e cria o serviço.|
|[CAtlServiceModuleT::IsInstalled](#isinstalled)|Confirma que o serviço foi instalado.|
|[CAtlServiceModuleT::LogEvent](#logevent)|Grava no log de eventos.|
|[CAtlServiceModuleT::OnContinue](#oncontinue)|Substitua esse método para continuar o serviço.|
|[CAtlServiceModuleT::OnInterrogate](#oninterrogate)|Substitua esse método para interrogar o serviço.|
|[CAtlServiceModuleT::OnPause](#onpause)|Substitua esse método para pausar o serviço.|
|[CAtlServiceModuleT::OnShutdown](#onshutdown)|Substituir este método para desligar o serviço|
|[CAtlServiceModuleT::OnStop](#onstop)|Substituir este método para interromper o serviço|
|[CAtlServiceModuleT::OnUnknownRequest](#onunknownrequest)|Substituir este método para manipular solicitações desconhecidas para o serviço|
|[CAtlServiceModuleT::ParseCommandLine](#parsecommandline)|Analisa a linha de comando e executa o registro, se necessário.|
|[CAtlServiceModuleT::PreMessageLoop](#premessageloop)|Esse método é chamado imediatamente antes de entrar no loop de mensagem.|
|[CAtlServiceModuleT::RegisterAppId](#registerappid)|Registra o serviço no registro.|
|[CAtlServiceModuleT::Run](#run)|Executa o serviço.|
|[CAtlServiceModuleT::ServiceMain](#servicemain)|O método chamado pelo Gerenciador de controle de serviço.|
|[CAtlServiceModuleT::SetServiceStatus](#setservicestatus)|Atualiza o status do serviço.|
|[CAtlServiceModuleT::Start](#start)|Chamado pelo `CAtlServiceModuleT::WinMain` quando o serviço é iniciado.|
|[CAtlServiceModuleT::Uninstall](#uninstall)|Para e remove o serviço.|
|[CAtlServiceModuleT::Unlock](#unlock)|Decrementa a contagem de bloqueios do serviço.|
|[CAtlServiceModuleT::UnregisterAppId](#unregisterappid)|Remove o serviço do registro.|
|[CAtlServiceModuleT::WinMain](#winmain)|Esse método implementa o código necessário para executar o serviço.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlServiceModuleT::m_bService](#m_bservice)|Sinalizador que indica que o programa está sendo executado como um serviço.|
|[CAtlServiceModuleT::m_dwThreadID](#m_dwthreadid)|Variável de membro que armazena o identificador de thread.|
|[CAtlServiceModuleT::m_hServiceStatus](#m_hservicestatus)|Variável de membro que armazena um identificador para a estrutura de informações de status do serviço atual.|
|[CAtlServiceModuleT::m_status](#m_status)|Variável de membro que armazena a estrutura de informações de status para o serviço atual.|
|[CAtlServiceModuleT::m_szServiceName](#m_szservicename)|O nome do serviço que está sendo registrado.|

## <a name="remarks"></a>Comentários

`CAtlServiceModuleT`, derivado de [CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md), implementa um módulo de serviço do ATL. `CAtlServiceModuleT`fornece métodos para o processamento de linha de comando, instalação, registro e remoção. Se a funcionalidade extra for necessária, esses e outros métodos poderão ser substituídos.

Essa classe substitui a [classe CComModule](../../atl/reference/ccommodule-class.md) obsoleta usada em versões anteriores do ATL. Consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

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

Inicializa os membros de dados e define o status inicial do serviço.

##  <a name="handler"></a>Manipulador CAtlServiceModuleT::

A rotina do manipulador para o serviço.

```
void Handler(DWORD dwOpcode) throw();
```

### <a name="parameters"></a>Parâmetros

*dwOpcode*<br/>
Uma opção que define a operação do manipulador. Para obter detalhes, consulte os comentários.

### <a name="remarks"></a>Comentários

Este é o código que o Gerenciador de controle de serviço (SCM) chama para recuperar o status do serviço e as instruções do problema, como parar ou pausar. O SCM passa um código de operação, mostrado abaixo, `Handler` para indicar o que o serviço deve fazer.

|Código da operação|Significado|
|--------------------|-------------|
|SERVICE_CONTROL_STOP|Interrompe o serviço. Substitua o método [CAtlServiceModuleT:: OnStop](#onstop) em atlbase. h para alterar o comportamento.|
|SERVICE_CONTROL_PAUSE|Implementado pelo usuário. Substitua o método vazio [CAtlServiceModuleT::](#onpause) OnPause em atlbase. h para pausar o serviço.|
|SERVICE_CONTROL_CONTINUE|Implementado pelo usuário. Substitua o método vazio [CAtlServiceModuleT:: OnContinue](#oncontinue) em atlbase. h para continuar o serviço.|
|SERVICE_CONTROL_INTERROGATE|Implementado pelo usuário. Substitua o método vazio [CAtlServiceModuleT::](#oninterrogate) OnInterrogate em atlbase. h para interrogar o serviço.|
|SERVICE_CONTROL_SHUTDOWN|Implementado pelo usuário. Substitua o método vazio [CAtlServiceModuleT:: OnShutdown](#onshutdown) em atlbase. h para desligar o serviço.|

Se o código de operação não for reconhecido, o método [CAtlServiceModuleT:: OnUnknownRequest](#onunknownrequest) será chamado.

Um serviço padrão gerado pelo ATL trata apenas da instrução Stop. Se o SCM passar na instrução Stop, o serviço dirá ao SCM que o programa está prestes a parar. O serviço então chama `PostThreadMessage` para postar uma mensagem de Quit para ela mesma. Isso encerra o loop de mensagem e o serviço, por fim, fechará.

##  <a name="initializesecurity"></a>  CAtlServiceModuleT::InitializeSecurity

Fornece as configurações de segurança padrão para o serviço.

```
HRESULT InitializeSecurity() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Qualquer classe derivada de `CAtlServiceModuleT` deve implementar esse método na classe derivada.

Use a autenticação em nível de PKT, o nível de representação de RPC_C_IMP_LEVEL_IDENTIFY e um descritor de segurança não nulo `CoInitializeSecurity`apropriado na chamada para.

Para projetos de serviço não atributo gerados por assistente, isso estaria em

[!code-cpp[NVC_ATL_Service#1](../../atl/reference/codesnippet/cpp/catlservicemodulet-class_1.cpp)]

Para projetos de serviço atribuído, isso estaria em

[!code-cpp[NVC_ATL_ServiceAttrib#1](../../atl/reference/codesnippet/cpp/catlservicemodulet-class_2.cpp)]

##  <a name="install"></a>  CAtlServiceModuleT::Install

Instala e cria o serviço.

```
BOOL Install() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Instala o serviço no banco de dados SCM (Gerenciador de controle de serviço) e cria o objeto de serviço. Se o serviço não pôde ser criado, uma caixa de mensagem é exibida e o método retorna FALSE.

##  <a name="isinstalled"></a>  CAtlServiceModuleT::IsInstalled

Confirma que o serviço foi instalado.

```
BOOL IsInstalled() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna TRUE se o serviço estiver instalado; caso contrário, FALSE.

##  <a name="logevent"></a>  CAtlServiceModuleT::LogEvent

Grava no log de eventos.

```
void __cdecl LogEvent(LPCTSTR pszFormat, ...) throw();
```

### <a name="parameters"></a>Parâmetros

*pszFormat*<br/>
A cadeia de caracteres a ser gravada no log de eventos.

*...*<br/>
Cadeias de caracteres extras opcionais a serem gravadas no log de eventos.

### <a name="remarks"></a>Comentários

Esse método grava detalhes em um log de eventos, usando a função [ReportEvent](/windows/desktop/api/winbase/nf-winbase-reporteventa). Se nenhum serviço estiver em execução, a cadeia de caracteres será enviada ao console.

##  <a name="m_bservice"></a>  CAtlServiceModuleT::m_bService

Sinalizador que indica que o programa está sendo executado como um serviço.

```
BOOL m_bService;
```

### <a name="remarks"></a>Comentários

Usado para distinguir um EXE de serviço de um aplicativo EXE.

##  <a name="m_dwthreadid"></a>  CAtlServiceModuleT::m_dwThreadID

Variável de membro que armazena o identificador de thread do serviço.

```
DWORD m_dwThreadID;
```

### <a name="remarks"></a>Comentários

Essa variável armazena o identificador de thread do thread atual.

##  <a name="m_hservicestatus"></a>  CAtlServiceModuleT::m_hServiceStatus

Variável de membro que armazena um identificador para a estrutura de informações de status do serviço atual.

```
SERVICE_STATUS_HANDLE m_hServiceStatus;
```

### <a name="remarks"></a>Comentários

A estrutura [SERVICE_STATUS](/windows/desktop/api/winsvc/ns-winsvc-service_status) contém informações sobre um serviço.

##  <a name="m_status"></a>  CAtlServiceModuleT::m_status

Variável de membro que armazena a estrutura de informações de status para o serviço atual.

```
SERVICE_STATUS m_status;
```

### <a name="remarks"></a>Comentários

A estrutura [SERVICE_STATUS](/windows/desktop/api/winsvc/ns-winsvc-service_status) contém informações sobre um serviço.

##  <a name="m_szservicename"></a>  CAtlServiceModuleT::m_szServiceName

O nome do serviço que está sendo registrado.

```
TCHAR [256] m_szServiceName;
```

### <a name="remarks"></a>Comentários

Uma cadeia de caracteres terminada em nulo que armazena o nome do serviço.

##  <a name="oncontinue"></a>  CAtlServiceModuleT::OnContinue

Substitua esse método para continuar o serviço.

```
void OnContinue() throw();
```

##  <a name="oninterrogate"></a>  CAtlServiceModuleT::OnInterrogate

Substitua esse método para interrogar o serviço.

```
void OnInterrogate() throw();
```

##  <a name="onpause"></a>  CAtlServiceModuleT::OnPause

Substitua esse método para pausar o serviço.

```
void OnPause() throw();
```

##  <a name="onshutdown"></a>  CAtlServiceModuleT::OnShutdown

Substitua esse método para desligar o serviço.

```
void OnShutdown() throw();
```

##  <a name="onstop"></a>  CAtlServiceModuleT::OnStop

Substitua esse método para interromper o serviço.

```
void OnStop() throw();
```

##  <a name="onunknownrequest"></a>  CAtlServiceModuleT::OnUnknownRequest

Substitua esse método para manipular solicitações desconhecidas para o serviço.

```
void OnUnknownRequest(DWORD /* dwOpcode*/) throw();
```

### <a name="parameters"></a>Parâmetros

*dwOpcode*<br/>
Reservado.

##  <a name="parsecommandline"></a>  CAtlServiceModuleT::ParseCommandLine

Analisa a linha de comando e executa o registro, se necessário.

```
bool ParseCommandLine(LPCTSTR lpCmdLine, HRESULT* pnRetCode) throw();
```

### <a name="parameters"></a>Parâmetros

*lpCmdLine*<br/>
A linha de comando.

*pnRetCode*<br/>
O HRESULT correspondente ao registro (se tiver ocorrido).

### <a name="return-value"></a>Valor de retorno

Retorna true em caso de êxito ou false se o arquivo RGS fornecido na linha de comando não pôde ser registrado.

### <a name="remarks"></a>Comentários

Analisa a linha de comando e registra ou cancela o registro do arquivo RGS fornecido, se necessário. Esse método chama [CAtlExeModuleT::P arsecommandline](../../atl/reference/catlexemodulet-class.md#parsecommandline) para verificar o **/RegServer** e o **opção/UnregServer**. Adicionar o argumento **-/Service** registrará o serviço.

##  <a name="premessageloop"></a>  CAtlServiceModuleT::PreMessageLoop

Esse método é chamado imediatamente antes de entrar no loop de mensagem.

```
HRESULT PreMessageLoop(int nShowCmd) throw();
```

### <a name="parameters"></a>Parâmetros

*nShowCmd*<br/>
Esse parâmetro é passado para [CAtlExeModuleT::P remessageloop](../../atl/reference/catlexemodulet-class.md#premessageloop).

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Substitua esse método para adicionar o código de inicialização personalizado para o serviço.

##  <a name="registerappid"></a>  CAtlServiceModuleT::RegisterAppId

Registra o serviço no registro.

```
inline HRESULT RegisterAppId(bool bService = false) throw();
```

### <a name="parameters"></a>Parâmetros

*bService*<br/>
Deve ser verdadeiro para registrar como um serviço.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

##  <a name="run"></a>  CAtlServiceModuleT::Run

Executa o serviço.

```
HRESULT Run(int nShowCmd = SW_HIDE) throw();
```

### <a name="parameters"></a>Parâmetros

*nShowCmd*<br/>
Especifica como a janela deve ser mostrada. Esse parâmetro pode ser um dos valores discutidos na seção [WinMain](/windows/desktop/api/winbase/nf-winbase-winmain) . O valor padrão é SW_HIDE.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Depois de ser chamado `Run` , chama [CAtlServiceModuleT::P remessageloop](#premessageloop), [CAtlExeModuleT:: RunMessageLoop](../../atl/reference/catlexemodulet-class.md#runmessageloop)e [CAtlExeModuleT::P ostmessageloop](../../atl/reference/catlexemodulet-class.md#postmessageloop).

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

As chamadas `ServiceMain` do Gerenciador de controle de serviço (SCM) quando você abre o aplicativo de serviços no painel de controle, selecionam o serviço e clicam em Iniciar.

Após as chamadas `ServiceMain`de SCM, um serviço deve dar ao SCM uma função de manipulador. Essa função permite que o SCM obtenha o status do serviço e passe instruções específicas (como pausar ou parar). Subsequentemente, [CAtlServiceModuleT:: Run](#run) é chamado para executar o trabalho principal do serviço. `Run`continua a ser executado até que o serviço seja interrompido.

##  <a name="setservicestatus"></a>  CAtlServiceModuleT::SetServiceStatus

Esse método atualiza o status do serviço.

```
void SetServiceStatus(DWORD dwState) throw();
```

### <a name="parameters"></a>Parâmetros

*dwState*<br/>
O novo status. Consulte [falha em SetServiceStatus](/windows/desktop/api/winsvc/nf-winsvc-setservicestatus) para obter os valores possíveis.

### <a name="remarks"></a>Comentários

Atualiza as informações de status do Gerenciador de controle de serviço para o serviço. Ele é chamado por [CAtlServiceModuleT:: Run](#run), [CAtlServiceModuleT:: não Main](#servicemain) e outros métodos de manipulador. O status também é armazenado na variável de membro [CAtlServiceModuleT:: m_status](#m_status).

##  <a name="start"></a>  CAtlServiceModuleT::Start

Chamado pelo `CAtlServiceModuleT::WinMain` quando o serviço é iniciado.

```
HRESULT Start(int nShowCmd) throw();
```

### <a name="parameters"></a>Parâmetros

*nShowCmd*<br/>
Especifica como a janela deve ser mostrada. Esse parâmetro pode ser um dos valores discutidos na seção [WinMain](/windows/desktop/api/winbase/nf-winbase-winmain) .

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

O método [CAtlServiceModuleT:: WinMain](#winmain) manipula o registro e a instalação, bem como as tarefas envolvidas na remoção de entradas do registro e na desinstalação do módulo. Quando o serviço é executado, `WinMain` o `Start`chama.

##  <a name="uninstall"></a>CAtlServiceModuleT:: desinstalar

Para e remove o serviço.

```
BOOL Uninstall() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Interrompe a execução do serviço e o Remove do banco de dados do Gerenciador de controle de serviço.

##  <a name="unlock"></a>CAtlServiceModuleT:: desbloquear

Decrementa a contagem de bloqueios do serviço.

```
LONG Unlock() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna a contagem de bloqueios, que pode ser útil para diagnóstico e depuração.

##  <a name="unregisterappid"></a>  CAtlServiceModuleT::UnregisterAppId

Remove o serviço do registro.

```
HRESULT UnregisterAppId() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

##  <a name="winmain"></a>  CAtlServiceModuleT::WinMain

Esse método implementa o código necessário para iniciar o serviço.

```
int WinMain(int nShowCmd) throw();
```

### <a name="parameters"></a>Parâmetros

*nShowCmd*<br/>
Especifica como a janela deve ser mostrada. Esse parâmetro pode ser um dos valores discutidos na seção [WinMain](/windows/desktop/api/winbase/nf-winbase-winmain) .

### <a name="return-value"></a>Valor de retorno

Retorna o valor de retorno do serviço.

### <a name="remarks"></a>Comentários

Esse método processa a linha de comando (com [CAtlServiceModuleT::P arsecommandline](#parsecommandline)) e, em seguida, inicia o serviço (usando [CAtlServiceModuleT:: Start](#start)).

## <a name="see-also"></a>Consulte também

[Classe CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
