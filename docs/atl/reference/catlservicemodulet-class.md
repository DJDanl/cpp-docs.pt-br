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
ms.openlocfilehash: 5d87eada997d0bbfe44cd07a819f6b012a7a3a20
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81321332"
---
# <a name="catlservicemodulet-class"></a>Classe CAtlServiceModuleT

Esta classe implementa um serviço.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class T, UINT nServiceNameID>
class ATL_NO_VTABLE CAtlServiceModuleT : public CAtlExeModuleT<T>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe derivada de `CAtlServiceModuleT`.

*nServiceNameID*<br/>
O identificador de recursos do serviço.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlServiceModuleT::CAtlServiceModuleT](#catlservicemodulet)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlServiceModuleT::Manipulador](#handler)|A rotina de manipulador para o serviço.|
|[CAtlServiceModuleT::InitializeSecurity](#initializesecurity)|Fornece as configurações de segurança padrão para o serviço.|
|[CAtlServiceModuleT::Instalar](#install)|Instala e cria o serviço.|
|[CAtlServiceModuleT::IsInstalled](#isinstalled)|Confirma que o serviço foi instalado.|
|[CAtlServiceModuleT::LogEvent](#logevent)|Escreve para o registro de eventos.|
|[CAtlServiceModuleT::OnContinuar](#oncontinue)|Anular este método para continuar o serviço.|
|[CAtlServiceModuleT::OnInterrogado](#oninterrogate)|Anular este método para interrogar o serviço.|
|[CAtlServiceModuleT::OnPause](#onpause)|Anular este método para pausar o serviço.|
|[CAtlServiceModuleT::OnShutdown](#onshutdown)|Anular este método para desligar o serviço|
|[CAtlServiceModuleT::OnStop](#onstop)|Anular este método para interromper o serviço|
|[CAtlServiceModuleT::OnUnknownRequest](#onunknownrequest)|Anular este método para lidar com solicitações desconhecidas ao serviço|
|[CAtlServiceModuleT::ParseCommandLine](#parsecommandline)|Analisa a linha de comando e realiza o registro, se necessário.|
|[CAtlServiceModuleT::PreMessageLoop](#premessageloop)|Este método é chamado imediatamente antes de entrar no loop de mensagem.|
|[CAtlServiceModuleT::RegisterAppId](#registerappid)|Registra o serviço no registro.|
|[CAtlServiceModuleT::Execução](#run)|Comanda o serviço.|
|[CAtlServiceModuleT::ServiceMain](#servicemain)|O método chamado pelo Gerente de Controle de Serviços.|
|[CAtlServiceModuleT::SetServiceStatus](#setservicestatus)|Atualiza o status do serviço.|
|[CAtlServiceModuleT::Iniciar](#start)|Chamado `CAtlServiceModuleT::WinMain` por quando o serviço começa.|
|[CAtlServiceModuleT::Desinstalar](#uninstall)|Pára e remove o serviço.|
|[CAtlServiceModuleT::Desbloquear](#unlock)|Decreta a contagem de bloqueios do serviço.|
|[CAtlServiceModuleT::UnregisterAppId](#unregisterappid)|Remove o serviço do registro.|
|[CAtlServiceModuleT::WinMain](#winmain)|Este método implementa o código necessário para executar o serviço.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlServiceModuleT::m_bService](#m_bservice)|Bandeira indicando que o programa está sendo executado como um serviço.|
|[CAtlServiceModuleT::m_dwThreadID](#m_dwthreadid)|Variável membro armazenando o identificador de segmento.|
|[CAtlServiceModuleT::m_hServiceStatus](#m_hservicestatus)|Variável membro armazenando uma alça para a estrutura de informações de status para o serviço atual.|
|[CAtlServiceModuleT::m_status](#m_status)|Variável membro armazenando a estrutura de informações de status para o serviço atual.|
|[CAtlServiceModuleT::m_szServiceName](#m_szservicename)|O nome do serviço sendo registrado.|

## <a name="remarks"></a>Comentários

`CAtlServiceModuleT`, derivado do [CAtlExeModuleT,](../../atl/reference/catlexemodulet-class.md)implementa um módulo ATL Service. `CAtlServiceModuleT`fornece métodos para processamento, instalação, registro e remoção de linhas de comando. Se for necessária uma funcionalidade extra, esses e outros métodos podem ser substituídos.

Esta classe substitui a obsoleta [Classe CComModule](../../atl/reference/ccommodule-class.md) usada em versões anteriores do ATL. Consulte [atl module classes](../../atl/atl-module-classes.md) para obter mais detalhes.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[_ATL_MODULE](atl-typedefs.md#_atl_module)

[Catlmodule](../../atl/reference/catlmodule-class.md)

[Catlmodulet](../../atl/reference/catlmodulet-class.md)

[Catlexemodulet](../../atl/reference/catlexemodulet-class.md)

`CAtlServiceModuleT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="catlservicemoduletcatlservicemodulet"></a><a name="catlservicemodulet"></a>CAtlServiceModuleT::CAtlServiceModuleT

O construtor.

```
CAtlServiceModuleT() throw();
```

### <a name="remarks"></a>Comentários

Inicializa os membros de dados e define o status inicial do serviço.

## <a name="catlservicemodulethandler"></a><a name="handler"></a>CAtlServiceModuleT::Manipulador

A rotina de manipulador para o serviço.

```
void Handler(DWORD dwOpcode) throw();
```

### <a name="parameters"></a>Parâmetros

*dwOpcode*<br/>
Um interruptor que define a operação do manipulador. Para mais detalhes, consulte as observações.

### <a name="remarks"></a>Comentários

Este é o código que o Service Control Manager (SCM) chama para recuperar o status do serviço e emitir instruções como parar ou pausar. O SCM passa um código de `Handler` operação, mostrado abaixo, para indicar o que o serviço deve fazer.

|Código de operação|Significado|
|--------------------|-------------|
|SERVICE_CONTROL_STOP|Interrompe o serviço. Substituir o método [CAtlServiceModuleT::OnStop](#onstop) em atlbase.h para alterar o comportamento.|
|SERVICE_CONTROL_PAUSE|Usuário implementado. Anular o método vazio [CAtlServiceModuleT::OnPause](#onpause) em atlbase.h para pausar o serviço.|
|SERVICE_CONTROL_CONTINUE|Usuário implementado. Anular o método vazio [CAtlServiceModuleT::OnContinuar](#oncontinue) em atlbase.h para continuar o serviço.|
|SERVICE_CONTROL_INTERROGATE|Usuário implementado. Anular o método vazio [CAtlServiceModuleT::OnInterrogado](#oninterrogate) em atlbase.h para interrogar o serviço.|
|SERVICE_CONTROL_SHUTDOWN|Usuário implementado. Anular o método vazio [CAtlServiceModuleT::OnShutdown](#onshutdown) em atlbase.h para desligar o serviço.|

Se o código de operação não for reconhecido, o método [CAtlServiceModuleT::OnUnknownRequest](#onunknownrequest) será chamado.

Um serviço padrão gerado pela ATL só lida com a instrução de parada. Se o SCM passar a instrução de parada, o serviço diz ao SCM que o programa está prestes a parar. O serviço `PostThreadMessage` então liga para postar uma mensagem de demissão para si mesmo. Isso encerra o loop de mensagem e o serviço será finalmente encerrado.

## <a name="catlservicemoduletinitializesecurity"></a><a name="initializesecurity"></a>CAtlServiceModuleT::InitializeSecurity

Fornece as configurações de segurança padrão para o serviço.

```
HRESULT InitializeSecurity() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Qualquer classe derivada `CAtlServiceModuleT` deve implementar este método na classe derivada.

Use autenticação em nível de PKT, nível de representação de RPC_C_IMP_LEVEL_IDENTIFY e `CoInitializeSecurity`um descritor de segurança não nulo apropriado na chamada para .

Para projetos de serviçonão atribuídos por assistente, isso seria em

[!code-cpp[NVC_ATL_Service#1](../../atl/reference/codesnippet/cpp/catlservicemodulet-class_1.cpp)]

Para projetos de serviços atribuídos, isso seria em

[!code-cpp[NVC_ATL_ServiceAttrib#1](../../atl/reference/codesnippet/cpp/catlservicemodulet-class_2.cpp)]

## <a name="catlservicemoduletinstall"></a><a name="install"></a>CAtlServiceModuleT::Instalar

Instala e cria o serviço.

```
BOOL Install() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Instala o serviço no banco de dados SCM (Service Control Manager, gerente de controle de serviço) e, em seguida, cria o objeto de serviço. Se o serviço não puder ser criado, uma caixa de mensagem será exibida e o método retorna FALSO.

## <a name="catlservicemoduletisinstalled"></a><a name="isinstalled"></a>CAtlServiceModuleT::IsInstalled

Confirma que o serviço foi instalado.

```
BOOL IsInstalled() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o serviço estiver instalado, FALSO de outra forma.

## <a name="catlservicemoduletlogevent"></a><a name="logevent"></a>CAtlServiceModuleT::LogEvent

Escreve para o registro de eventos.

```
void __cdecl LogEvent(LPCTSTR pszFormat, ...) throw();
```

### <a name="parameters"></a>Parâmetros

*Pszformat*<br/>
A cadeia de caracteres a ser gravada no log de eventos.

*...*<br/>
Cordas extras opcionais a serem escritas no registro de eventos.

### <a name="remarks"></a>Comentários

Este método grava detalhes em um registro de eventos, usando a função [ReportEvent](/windows/win32/api/winbase/nf-winbase-reporteventw). Se nenhum serviço estiver sendo executado, a seqüência será enviada para o console.

## <a name="catlservicemoduletm_bservice"></a><a name="m_bservice"></a>CAtlServiceModuleT::m_bService

Bandeira indicando que o programa está sendo executado como um serviço.

```
BOOL m_bService;
```

### <a name="remarks"></a>Comentários

Usado para distinguir um SERVICE EXE de um EXE de aplicativo.

## <a name="catlservicemoduletm_dwthreadid"></a><a name="m_dwthreadid"></a>CAtlServiceModuleT::m_dwThreadID

Variável membro armazenando o identificador de segmento do Serviço.

```
DWORD m_dwThreadID;
```

### <a name="remarks"></a>Comentários

Esta variável armazena o identificador de segmento do segmento atual.

## <a name="catlservicemoduletm_hservicestatus"></a><a name="m_hservicestatus"></a>CAtlServiceModuleT::m_hServiceStatus

Variável membro armazenando uma alça para a estrutura de informações de status para o serviço atual.

```
SERVICE_STATUS_HANDLE m_hServiceStatus;
```

### <a name="remarks"></a>Comentários

A estrutura [SERVICE_STATUS](/windows/win32/api/winsvc/ns-winsvc-service_status) contém informações sobre um serviço.

## <a name="catlservicemoduletm_status"></a><a name="m_status"></a>CAtlServiceModuleT::m_status

Variável membro armazenando a estrutura de informações de status para o serviço atual.

```
SERVICE_STATUS m_status;
```

### <a name="remarks"></a>Comentários

A estrutura [SERVICE_STATUS](/windows/win32/api/winsvc/ns-winsvc-service_status) contém informações sobre um serviço.

## <a name="catlservicemoduletm_szservicename"></a><a name="m_szservicename"></a>CAtlServiceModuleT::m_szServiceName

O nome do serviço sendo registrado.

```
TCHAR [256] m_szServiceName;
```

### <a name="remarks"></a>Comentários

Uma seqüência de terminante nula que armazena o nome do serviço.

## <a name="catlservicemoduletoncontinue"></a><a name="oncontinue"></a>CAtlServiceModuleT::OnContinuar

Anular este método para continuar o serviço.

```
void OnContinue() throw();
```

## <a name="catlservicemoduletoninterrogate"></a><a name="oninterrogate"></a>CAtlServiceModuleT::OnInterrogado

Anular este método para interrogar o serviço.

```
void OnInterrogate() throw();
```

## <a name="catlservicemoduletonpause"></a><a name="onpause"></a>CAtlServiceModuleT::OnPause

Anular este método para pausar o serviço.

```
void OnPause() throw();
```

## <a name="catlservicemoduletonshutdown"></a><a name="onshutdown"></a>CAtlServiceModuleT::OnShutdown

Anular este método para desligar o serviço.

```
void OnShutdown() throw();
```

## <a name="catlservicemoduletonstop"></a><a name="onstop"></a>CAtlServiceModuleT::OnStop

Anular este método para interromper o serviço.

```
void OnStop() throw();
```

## <a name="catlservicemoduletonunknownrequest"></a><a name="onunknownrequest"></a>CAtlServiceModuleT::OnUnknownRequest

Anular este método para lidar com solicitações desconhecidas ao serviço.

```
void OnUnknownRequest(DWORD /* dwOpcode*/) throw();
```

### <a name="parameters"></a>Parâmetros

*dwOpcode*<br/>
Reservado.

## <a name="catlservicemoduletparsecommandline"></a><a name="parsecommandline"></a>CAtlServiceModuleT::ParseCommandLine

Analisa a linha de comando e realiza o registro, se necessário.

```
bool ParseCommandLine(LPCTSTR lpCmdLine, HRESULT* pnRetCode) throw();
```

### <a name="parameters"></a>Parâmetros

*lpCmdLine*<br/>
A linha de comando.

*pnRetCode*<br/>
O HRESULT corresponde ao registro (se ocorreu).

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro no sucesso ou falso se o arquivo RGS fornecido na linha de comando não puder ser registrado.

### <a name="remarks"></a>Comentários

Analisa a linha de comando e registra ou desregistra o arquivo RGS fornecido, se necessário. Este método chama [CAtlExeModuleT::ParseCommandLine](../../atl/reference/catlexemodulet-class.md#parsecommandline) para verificar **/RegServer** e **/UnregServer**. Adicionando o argumento **-/O serviço** registrará o serviço.

## <a name="catlservicemoduletpremessageloop"></a><a name="premessageloop"></a>CAtlServiceModuleT::PreMessageLoop

Este método é chamado imediatamente antes de entrar no loop de mensagem.

```
HRESULT PreMessageLoop(int nShowCmd) throw();
```

### <a name="parameters"></a>Parâmetros

*nShowCmd*<br/>
Este parâmetro é passado para [CAtlExeModuleT::PreMessageLoop](../../atl/reference/catlexemodulet-class.md#premessageloop).

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Substituir este método para adicionar código de inicialização personalizado para o Serviço.

## <a name="catlservicemoduletregisterappid"></a><a name="registerappid"></a>CAtlServiceModuleT::RegisterAppId

Registra o serviço no registro.

```
inline HRESULT RegisterAppId(bool bService = false) throw();
```

### <a name="parameters"></a>Parâmetros

*bService*<br/>
Deve ser verdadeiro registrar-se como um serviço.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="catlservicemoduletrun"></a><a name="run"></a>CAtlServiceModuleT::Execução

Comanda o serviço.

```
HRESULT Run(int nShowCmd = SW_HIDE) throw();
```

### <a name="parameters"></a>Parâmetros

*nShowCmd*<br/>
Especifica como a janela deve ser mostrada. Este parâmetro pode ser um dos valores discutidos na seção [WinMain.](/windows/win32/api/winbase/nf-winbase-winmain) O valor padrão é SW_HIDE.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Após ser `Run` chamado, chama [CAtlServiceModuleT::PreMessageLoop](#premessageloop), [CAtlExeModuleT::RunMessageLoop](../../atl/reference/catlexemodulet-class.md#runmessageloop)e [CAtlExeModuleT::PostMessageLoop](../../atl/reference/catlexemodulet-class.md#postmessageloop).

## <a name="catlservicemoduletservicemain"></a><a name="servicemain"></a>CAtlServiceModuleT::ServiceMain

Este método é chamado pelo Gerente de Controle de Serviços.

```
void ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv) throw();
```

### <a name="parameters"></a>Parâmetros

*dwArgc*<br/>
O argumento argc.

*lpszArgv*<br/>
O argumento argv.

### <a name="remarks"></a>Comentários

O SCM (Service Control `ServiceMain` Manager, gerente de controle de serviços) liga quando você abre o aplicativo Serviços no Painel de Controle, seleciona o serviço e clica em Iniciar.

Após as chamadas `ServiceMain`do SCM, um serviço deve dar ao SCM uma função de manipulador. Esta função permite que o SCM obtenha o status do serviço e passe instruções específicas (como pausaou ou parada). Posteriormente, [CAtlServiceModuleT::Run](#run) é chamado para executar o trabalho principal do serviço. `Run`continua a ser executado até que o serviço seja interrompido.

## <a name="catlservicemoduletsetservicestatus"></a><a name="setservicestatus"></a>CAtlServiceModuleT::SetServiceStatus

Este método atualiza o status do serviço.

```
void SetServiceStatus(DWORD dwState) throw();
```

### <a name="parameters"></a>Parâmetros

*Dwstate*<br/>
O novo status. Consulte [SetServiceStatus](/windows/win32/api/winsvc/nf-winsvc-setservicestatus) para obter possíveis valores.

### <a name="remarks"></a>Comentários

Atualiza as informações de status do Gerenciador de Controle de Serviço para o serviço. Ele é chamado por [CAtlServiceModuleT::Run,](#run) [CAtlServiceModuleT::ServiceMain](#servicemain) e outros métodos de manipulador. O status também é armazenado na variável membro [CAtlServiceModuleT::m_status](#m_status).

## <a name="catlservicemoduletstart"></a><a name="start"></a>CAtlServiceModuleT::Iniciar

Chamado `CAtlServiceModuleT::WinMain` por quando o serviço começa.

```
HRESULT Start(int nShowCmd) throw();
```

### <a name="parameters"></a>Parâmetros

*nShowCmd*<br/>
Especifica como a janela deve ser mostrada. Este parâmetro pode ser um dos valores discutidos na seção [WinMain.](/windows/win32/api/winbase/nf-winbase-winmain)

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

O método [CAtlServiceModuleT::WinPrincipal](#winmain) lida tanto com registro quanto com instalação, bem como tarefas envolvidas na remoção de entradas de registro e na desinstalação do módulo. Quando o serviço `WinMain` é `Start`executado, chamadas .

## <a name="catlservicemoduletuninstall"></a><a name="uninstall"></a>CAtlServiceModuleT::Desinstalar

Pára e remove o serviço.

```
BOOL Uninstall() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Impede que o serviço seja executado e o remove do banco de dados do Service Control Manager.

## <a name="catlservicemoduletunlock"></a><a name="unlock"></a>CAtlServiceModuleT::Desbloquear

Decreta a contagem de bloqueios do serviço.

```
LONG Unlock() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a contagem de bloqueios, que pode ser útil para diagnósticos e depuração.

## <a name="catlservicemoduletunregisterappid"></a><a name="unregisterappid"></a>CAtlServiceModuleT::UnregisterAppId

Remove o serviço do registro.

```
HRESULT UnregisterAppId() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="catlservicemoduletwinmain"></a><a name="winmain"></a>CAtlServiceModuleT::WinMain

Este método implementa o código necessário para iniciar o serviço.

```
int WinMain(int nShowCmd) throw();
```

### <a name="parameters"></a>Parâmetros

*nShowCmd*<br/>
Especifica como a janela deve ser mostrada. Este parâmetro pode ser um dos valores discutidos na seção [WinMain.](/windows/win32/api/winbase/nf-winbase-winmain)

### <a name="return-value"></a>Valor retornado

Devolve o valor de retorno do serviço.

### <a name="remarks"></a>Comentários

Este método processa a linha de comando (com [CAtlServiceModuleT::ParseCommandLine](#parsecommandline)) e, em seguida, inicia o serviço (usando [CAtlServiceModuleT::Start](#start)).

## <a name="see-also"></a>Confira também

[Classe CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
