---
title: Classe CAccessToken | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CAccessToken
- ATLSECURITY/ATL::CAccessToken
- ATLSECURITY/ATL::CAccessToken::Attach
- ATLSECURITY/ATL::CAccessToken::CheckTokenMembership
- ATLSECURITY/ATL::CAccessToken::CreateImpersonationToken
- ATLSECURITY/ATL::CAccessToken::CreatePrimaryToken
- ATLSECURITY/ATL::CAccessToken::CreateProcessAsUser
- ATLSECURITY/ATL::CAccessToken::CreateRestrictedToken
- ATLSECURITY/ATL::CAccessToken::Detach
- ATLSECURITY/ATL::CAccessToken::DisablePrivilege
- ATLSECURITY/ATL::CAccessToken::DisablePrivileges
- ATLSECURITY/ATL::CAccessToken::EnablePrivilege
- ATLSECURITY/ATL::CAccessToken::EnablePrivileges
- ATLSECURITY/ATL::CAccessToken::GetDefaultDacl
- ATLSECURITY/ATL::CAccessToken::GetEffectiveToken
- ATLSECURITY/ATL::CAccessToken::GetGroups
- ATLSECURITY/ATL::CAccessToken::GetHandle
- ATLSECURITY/ATL::CAccessToken::GetImpersonationLevel
- ATLSECURITY/ATL::CAccessToken::GetLogonSessionId
- ATLSECURITY/ATL::CAccessToken::GetLogonSid
- ATLSECURITY/ATL::CAccessToken::GetOwner
- ATLSECURITY/ATL::CAccessToken::GetPrimaryGroup
- ATLSECURITY/ATL::CAccessToken::GetPrivileges
- ATLSECURITY/ATL::CAccessToken::GetProcessToken
- ATLSECURITY/ATL::CAccessToken::GetProfile
- ATLSECURITY/ATL::CAccessToken::GetSource
- ATLSECURITY/ATL::CAccessToken::GetStatistics
- ATLSECURITY/ATL::CAccessToken::GetTerminalServicesSessionId
- ATLSECURITY/ATL::CAccessToken::GetThreadToken
- ATLSECURITY/ATL::CAccessToken::GetTokenId
- ATLSECURITY/ATL::CAccessToken::GetType
- ATLSECURITY/ATL::CAccessToken::GetUser
- ATLSECURITY/ATL::CAccessToken::HKeyCurrentUser
- ATLSECURITY/ATL::CAccessToken::Impersonate
- ATLSECURITY/ATL::CAccessToken::ImpersonateLoggedOnUser
- ATLSECURITY/ATL::CAccessToken::IsTokenRestricted
- ATLSECURITY/ATL::CAccessToken::LoadUserProfile
- ATLSECURITY/ATL::CAccessToken::LogonUser
- ATLSECURITY/ATL::CAccessToken::OpenCOMClientToken
- ATLSECURITY/ATL::CAccessToken::OpenNamedPipeClientToken
- ATLSECURITY/ATL::CAccessToken::OpenRPCClientToken
- ATLSECURITY/ATL::CAccessToken::OpenThreadToken
- ATLSECURITY/ATL::CAccessToken::PrivilegeCheck
- ATLSECURITY/ATL::CAccessToken::Revert
- ATLSECURITY/ATL::CAccessToken::SetDefaultDacl
- ATLSECURITY/ATL::CAccessToken::SetOwner
- ATLSECURITY/ATL::CAccessToken::SetPrimaryGroup
dev_langs:
- C++
helpviewer_keywords:
- CAccessToken class
ms.assetid: bb5c5945-56a5-4083-b442-76573cee83ab
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ee8080c8e2caacb882f43425ab528a08dd2f8ea0
ms.sourcegitcommit: 3a141cf07b5411d5f1fdf6cf67c4ce928cf389c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/11/2018
ms.locfileid: "49083743"
---
# <a name="caccesstoken-class"></a>Classe CAccessToken

Essa classe é um wrapper para um token de acesso.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CAccessToken
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAccessToken::~CAccessToken](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAccessToken::Attach](#attach)|Chame esse método para apropriar-se de que o identificador de token de acesso indicada.|
|[CAccessToken::CheckTokenMembership](#checktokenmembership)|Chame esse método para determinar se um SID específico está habilitado no `CAccessToken` objeto.|
|[CAccessToken::CreateImpersonationToken](#createimpersonationtoken)|Chame esse método para criar um novo token de acesso de representação.|
|[CAccessToken::CreatePrimaryToken](#createprimarytoken)|Chame esse método para criar um novo token primário.|
|[CAccessToken::CreateProcessAsUser](#createprocessasuser)|Chame esse método para criar um novo processo em execução no contexto de segurança do usuário representado pelo `CAccessToken` objeto.|
|[CAccessToken::CreateRestrictedToken](#createrestrictedtoken)|Chame esse método para criar um novo restrito `CAccessToken` objeto.|
|[CAccessToken::Detach](#detach)|Chame esse método para revogar a propriedade do token de acesso.|
|[CAccessToken::DisablePrivilege](#disableprivilege)|Chame esse método para desabilitar um privilégio no `CAccessToken` objeto.|
|[CAccessToken::DisablePrivileges](#disableprivileges)|Chame esse método para desabilitar um ou mais privilégios no `CAccessToken` objeto.|
|[CAccessToken::EnablePrivilege](#enableprivilege)|Chame esse método para habilitar um privilégio no `CAccessToken` objeto.|
|[CAccessToken::EnablePrivileges](#enableprivileges)|Chame esse método para habilitar um ou mais privilégios no `CAccessToken` objeto.|
|[CAccessToken::GetDefaultDacl](#getdefaultdacl)|Chame esse método para retornar o `CAccessToken` do objeto padrão DACL.|
|[CAccessToken::GetEffectiveToken](#geteffectivetoken)|Chame esse método para obter o `CAccessToken` objeto igual ao token de acesso em vigor para o thread atual.|
|[CAccessToken::GetGroups](#getgroups)|Chame esse método para retornar o `CAccessToken` grupos de token do objeto.|
|[CAccessToken::GetHandle](#gethandle)|Chame esse método para recuperar um identificador para o token de acesso.|
|[CAccessToken::GetImpersonationLevel](#getimpersonationlevel)|Chame esse método para obter o nível de representação do token de acesso.|
|[CAccessToken::GetLogonSessionId](#getlogonsessionid)|Chame esse método para obter a ID de sessão de Logon associado a `CAccessToken` objeto.|
|[CAccessToken::GetLogonSid](#getlogonsid)|Chame esse método para obter o SID de Logon associado a `CAccessToken` objeto.|
|[CAccessToken::GetOwner](#getowner)|Chame esse método para obter o proprietário associado a `CAccessToken` objeto.|
|[CAccessToken::GetPrimaryGroup](#getprimarygroup)|Chame esse método para obter o grupo primário associado a `CAccessToken` objeto.|
|[CAccessToken::GetPrivileges](#getprivileges)|Chame esse método para obter os privilégios associados a `CAccessToken` objeto.|
|[CAccessToken::GetProcessToken](#getprocesstoken)|Chame este método para inicializar o `CAccessToken` com o token de acesso do processo especificado.|
|[CAccessToken::GetProfile](#getprofile)|Chame esse método para obter o identificador que aponta para o perfil de usuário associado a `CAccessToken` objeto.|
|[CAccessToken::GetSource](#getsource)|Chame esse método para obter a origem do `CAccessToken` objeto.|
|[CAccessToken::GetStatistics](#getstatistics)|Chame esse método para obter informações associadas a `CAccessToken` objeto.|
|[CAccessToken::GetTerminalServicesSessionId](#getterminalservicessessionid)|Chame esse método para obter a ID de sessão de serviços de Terminal associado com o `CAccessToken` objeto.|
|[CAccessToken::GetThreadToken](#getthreadtoken)|Chame este método para inicializar o `CAccessToken` com o token do thread especificado.|
|[CAccessToken::GetTokenId](#gettokenid)|Chame esse método para obter a ID do Token associado com o `CAccessToken` objeto.|
|[CAccessToken::GetType](#gettype)|Chame esse método para obter o tipo de token do `CAccessToken` objeto.|
|[CAccessToken::GetUser](#getuser)|Chame esse método para identificar o usuário associado com o `CAccessToken` objeto.|
|[CAccessToken::HKeyCurrentUser](#hkeycurrentuser)|Chame esse método para obter o identificador que aponta para o perfil de usuário associado a `CAccessToken` objeto.|
|[CAccessToken::Impersonate](#impersonate)|Chame esse método para atribuir uma representação `CAccessToken` a um thread.|
|[CAccessToken::ImpersonateLoggedOnUser](#impersonateloggedonuser)|Chame esse método para permitir que o thread de chamada representar o contexto de segurança de um logon do usuário.|
|[CAccessToken::IsTokenRestricted](#istokenrestricted)|Chame esse método para testar se o `CAccessToken` objeto contém uma lista de SIDs restritos.|
|[CAccessToken::LoadUserProfile](#loaduserprofile)|Chame esse método para carregar o perfil do usuário associado com o `CAccessToken` objeto.|
|[CAccessToken::LogonUser](#logonuser)|Chame esse método para criar uma sessão de logon para o usuário associado com as credenciais fornecidas.|
|[CAccessToken::OpenCOMClientToken](#opencomclienttoken)|Chame esse método de dentro de um servidor COM tratamento de uma chamada de um cliente para inicializar o `CAccessToken` com o token de acesso do cliente COM.|
|[CAccessToken::OpenNamedPipeClientToken](#opennamedpipeclienttoken)|Chame esse método de dentro de um servidor levando solicitações ao longo de um pipe nomeado para inicializar o `CAccessToken` com o token de acesso do cliente.|
|[CAccessToken::OpenRPCClientToken](#openrpcclienttoken)|Chame esse método de dentro de um servidor de tratamento de uma chamada de um cliente RPC para inicializar o `CAccessToken` com o token de acesso do cliente.|
|[CAccessToken::OpenThreadToken](#openthreadtoken)|Chame esse método para definir o nível de representação e, em seguida, inicialize o `CAccessToken` com o token do thread especificado.|
|[CAccessToken::PrivilegeCheck](#privilegecheck)|Chame esse método para determinar se um conjunto especificado de privilégios estão habilitadas no `CAccessToken` objeto.|
|[CAccessToken::Revert](#revert)|Chame esse método para interromper um thread que está usando um token de representação.|
|[CAccessToken::SetDefaultDacl](#setdefaultdacl)|Chame esse método para definir o padrão de DACL do `CAccessToken` objeto.|
|[CAccessToken::SetOwner](#setowner)|Chame esse método para definir o proprietário do `CAccessToken` objeto.|
|[CAccessToken::SetPrimaryGroup](#setprimarygroup)|Chame esse método para definir o grupo primário do `CAccessToken` objeto.|

## <a name="remarks"></a>Comentários

Uma [token de acesso](/windows/desktop/SecAuthZ/access-tokens) é um objeto que descreve o contexto de segurança de um processo ou thread e é alocado para cada usuário conectado no sistema Windows.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](/windows/desktop/SecAuthZ/access-control) no SDK do Windows.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity. h

##  <a name="attach"></a>  CAccessToken::Attach

Chame esse método para apropriar-se de que o identificador de token de acesso indicada.

```
void Attach(HANDLE hToken) throw();
```

### <a name="parameters"></a>Parâmetros

*hToken*<br/>
Um identificador para o token de acesso.

### <a name="remarks"></a>Comentários

Em compilações de depuração, um erro de asserção ocorrerá se o `CAccessToken` objeto já tem a propriedade de um token de acesso.

##  <a name="dtor"></a>  CAccessToken::~CAccessToken

O destruidor.

```
virtual ~CAccessToken() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

##  <a name="checktokenmembership"></a>  CAccessToken::CheckTokenMembership

Chame esse método para determinar se um SID específico está habilitado no `CAccessToken` objeto.

```
bool CheckTokenMembership(
    const CSid& rSid, 
    bool* pbIsMember) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
Referência a um [classe CSid](../../atl/reference/csid-class.md) objeto.

*pbIsMember*<br/>
Ponteiro para uma variável que recebe os resultados da verificação.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

O `CheckTokenMembership` método verifica a presença do SID no usuário e grupo SIDs do token de acesso. Se o SID está presente e tem o atributo de SE_GROUP_ENABLED *pbIsMember* é definido como TRUE; caso contrário, ele é definido como FALSE.

Em compilações de depuração, um erro de asserção ocorrerá se *pbIsMember* não é um ponteiro válido.

> [!NOTE]
>  O `CAccessToken` objeto deve ser um token de representação e não um token primário.

##  <a name="createimpersonationtoken"></a>  CAccessToken::CreateImpersonationToken

Chame esse método para criar um token de acesso de representação.

```
bool CreateImpersonationToken(
    CAccessToken* pImp, 
    SECURITY_IMPERSONATION_LEVEL sil = SecurityImpersonation) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pImp*<br/>
Ponteiro para o novo `CAccessToken` objeto.

*Sil*<br/>
Especifica um [SECURITY_IMPERSONATION_LEVEL](/windows/desktop/api/winnt/ne-winnt-_security_impersonation_level) que fornece o nível de representação do novo token de tipo enumerado.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

`CreateImpersonationToken` chamadas [DuplicateToken](https://msdn.microsoft.com/library/windows/desktop/aa446616) para criar um novo token de representação.

##  <a name="createprimarytoken"></a>  CAccessToken::CreatePrimaryToken

Chame esse método para criar um novo token primário.

```
bool CreatePrimaryToken(
    CAccessToken* pPri,
    DWORD dwDesiredAccess = MAXIMUM_ALLOWED,
    const CSecurityAttributes* pTokenAttributes = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pPri*<br/>
Ponteiro para o novo `CAccessToken` objeto.

*dwDesiredAccess*<br/>
Especifica os direitos de acesso solicitado para o novo token. O padrão, MAXIMUM_ALLOWED, solicitações de todos os direitos de acesso que são válidos para o chamador. Ver [direitos de acesso e máscaras de acesso](/windows/desktop/SecAuthZ/access-rights-and-access-masks) para obter mais direitos de acesso no.

*pTokenAttributes*<br/>
Ponteiro para um [SECURITY_ATTRIBUTES](https://msdn.microsoft.com/library/windows/desktop/aa379560) estrutura que especifica um descritor de segurança para o novo token e determina se os processos filho podem herdar o token. Se *pTokenAttributes* for NULL, o token obtém um descritor de segurança padrão e o identificador não pode ser herdado.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

`CreatePrimaryToken` chamadas [DuplicateTokenEx](https://msdn.microsoft.com/library/windows/desktop/aa446617) para criar um novo token primário.

##  <a name="createprocessasuser"></a>  CAccessToken::CreateProcessAsUser

Chame esse método para criar um novo processo em execução no contexto de segurança do usuário representado pelo `CAccessToken` objeto.

```
bool CreateProcessAsUser(
    LPCTSTR pApplicationName,
    LPTSTR pCommandLine,
    LPPROCESS_INFORMATION pProcessInformation,
    LPSTARTUPINFO pStartupInfo,
    DWORD dwCreationFlags = NORMAL_PRIORITY_CLASS,
    bool bLoadProfile = false,
    const CSecurityAttributes* pProcessAttributes = NULL,
    const CSecurityAttributes* pThreadAttributes = NULL,
    bool bInherit = false,
    LPCTSTR pCurrentDirectory = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*pApplicationName*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o módulo sejam executadas. Esse parâmetro não pode ser NULL.

*pCommandLine*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica a linha de comando para executar.

*pProcessInformation*<br/>
Ponteiro para um [PROCESS_INFORMATION](/windows/desktop/api/processthreadsapi/ns-processthreadsapi-_process_information) estrutura que recebe informações de identificação sobre o novo processo.

*pStartupInfo*<br/>
Ponteiro para um [STARTUPINFO](/windows/desktop/api/processthreadsapi/ns-processthreadsapi-_startupinfoa) estrutura que especifica como a janela principal para o novo processo deve ser exibidos.

*dwCreationFlags*<br/>
Especifica os sinalizadores adicionais que controlam a classe de prioridade e a criação do processo. Consulte a função Win32 [CreateProcessAsUser](https://msdn.microsoft.com/library/windows/desktop/ms682429) para obter uma lista dos sinalizadores.

*bLoadProfile*<br/>
Se for TRUE, o perfil do usuário é carregado com [LoadUserProfile](/windows/desktop/api/userenv/nf-userenv-loaduserprofilea).

*pProcessAttributes*<br/>
Ponteiro para um [SECURITY_ATTRIBUTES](https://msdn.microsoft.com/library/windows/desktop/aa379560) estrutura que especifica um descritor de segurança para o novo processo e determina se os processos filho podem herdar o identificador retornado. Se *pProcessAttributes* for NULL, o processo obtém um descritor de segurança padrão e o identificador não pode ser herdado.

*pThreadAttributes*<br/>
Ponteiro para um [SECURITY_ATTRIBUTES](https://msdn.microsoft.com/library/windows/desktop/aa379560) estrutura que especifica um descritor de segurança para o novo thread e determina se os processos filho podem herdar o identificador retornado. Se *pThreadAttributes* for NULL, o thread obtém um descritor de segurança padrão e o identificador não pode ser herdado.

*bInherit*<br/>
Indica se o novo processo herda os identificadores do processo de chamada. Se for TRUE, cada herdável identificador aberto no processo de chamada é herdado pelo novo processo. Identificadores herdados têm os mesmos privilégios de acesso e o valor que as alças originais.

*pCurrentDirectory*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica a unidade atual e o diretório para o novo processo. A cadeia de caracteres deve ser um caminho completo que inclui uma letra de unidade. Se esse parâmetro for NULL, o novo processo terá a mesma unidade atual e o diretório como o processo de chamada.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

`CreateProcessAsUser` usa o `CreateProcessAsUser` função do Win32 para criar um novo processo é executado no contexto de segurança do usuário representado pelo `CAccessToken` objeto. Consulte a descrição do [CreateProcessAsUser](https://msdn.microsoft.com/library/windows/desktop/ms682429) função para uma discussão completa sobre os parâmetros necessários.

Para esse método seja bem-sucedido, o `CAccessToken` objeto deve conter AssignPrimaryToken (a menos que ele é um token restrito) e privilégios IncreaseQuota.

##  <a name="createrestrictedtoken"></a>  CAccessToken::CreateRestrictedToken

Chame esse método para criar um novo restrito `CAccessToken` objeto.

```
bool CreateRestrictedToken(
    CAccessToken* pRestrictedToken,
    const CTokenGroups& SidsToDisable,
    const CTokenGroups& SidsToRestrict,
    const CTokenPrivileges& PrivilegesToDelete = CTokenPrivileges()) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pRestrictedToken*<br/>
O novo restrito `CAccessToken` objeto.

*SidsToDisable*<br/>
Um `CTokenGroups` objeto que especifica os SIDs somente de negação.

*SidsToRestrict*<br/>
Um `CTokenGroups` objeto que especifica os SIDs de restrição.

*PrivilegesToDelete*<br/>
Um `CTokenPrivileges` objeto que especifica os privilégios para excluir o token restrito. O padrão cria um objeto vazio.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

`CreateRestrictedToken` usa o [CreateRestrictedToken](https://msdn.microsoft.com/library/windows/desktop/aa446583) para criar uma nova função do Win32 `CAccessToken` objeto, com restrições.

> [!IMPORTANT]
>  Ao usar `CreateRestrictedToken`, verifique o seguinte: o token existente é válido (e não inserido pelo usuário) e *SidsToDisable* e *PrivilegesToDelete* são válidas (e não inserido pelo usuário). Se o método retorna FALSE, nega funcionalidade.

##  <a name="detach"></a>  CAccessToken::Detach

Chame esse método para revogar a propriedade do token de acesso.

```
HANDLE Detach() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o identificador para o `CAccessToken` que foi desanexado.

### <a name="remarks"></a>Comentários

Esse método revoga o `CAccessToken`da propriedade do token de acesso.

##  <a name="disableprivilege"></a>  CAccessToken::DisablePrivilege

Chame esse método para desabilitar um privilégio no `CAccessToken` objeto.

```
bool DisablePrivilege(
    LPCTSTR pszPrivilege,
    CTokenPrivileges* pPreviousState = NULL) throw(...);
```

### <a name="parameters"></a>Parâmetros

*pszPrivilege*<br/>
Ponteiro para uma cadeia de caracteres que contém o privilégio para desabilitar no `CAccessToken` objeto.

*pPreviousState*<br/>
Ponteiro para um `CTokenPrivileges` objeto que contém o estado anterior dos privilégios.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

##  <a name="disableprivileges"></a>  CAccessToken::DisablePrivileges

Chame esse método para desabilitar um ou mais privilégios no `CAccessToken` objeto.

```
bool DisablePrivileges(
    const CAtlArray<LPCTSTR>& rPrivileges,
    CTokenPrivileges* pPreviousState = NULL) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rPrivileges*<br/>
Ponteiro para uma matriz de cadeias de caracteres que contém os privilégios para desativar o `CAccessToken` objeto.

*pPreviousState*<br/>
Ponteiro para um `CTokenPrivileges` objeto que contém o estado anterior dos privilégios.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

##  <a name="enableprivilege"></a>  CAccessToken::EnablePrivilege

Chame esse método para habilitar um privilégio no `CAccessToken` objeto.

```
bool EnablePrivilege(
    LPCTSTR pszPrivilege,
    CTokenPrivileges* pPreviousState = NULL) throw(...);
```

### <a name="parameters"></a>Parâmetros

*pszPrivilege*<br/>
Ponteiro para uma cadeia de caracteres que contém o privilégio para habilitar o `CAccessToken` objeto.

*pPreviousState*<br/>
Ponteiro para um `CTokenPrivileges` objeto que contém o estado anterior dos privilégios.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

##  <a name="enableprivileges"></a>  CAccessToken::EnablePrivileges

Chame esse método para habilitar um ou mais privilégios no `CAccessToken` objeto.

```
bool EnablePrivileges(
    const CAtlArray<LPCTSTR>& rPrivileges,
    CTokenPrivileges* pPreviousState = NULL) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rPrivileges*<br/>
Ponteiro para uma matriz de cadeias de caracteres que contém os privilégios necessários para habilitar o `CAccessToken` objeto.

*pPreviousState*<br/>
Ponteiro para um `CTokenPrivileges` objeto que contém o estado anterior dos privilégios.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

##  <a name="getdefaultdacl"></a>  CAccessToken::GetDefaultDacl

Chame esse método para retornar o `CAccessToken` do objeto padrão DACL.

```
bool GetDefaultDacl(CDacl* pDacl) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pDacl*<br/>
Ponteiro para o [classe CDacl](../../atl/reference/cdacl-class.md) objeto que receberá o `CAccessToken` do objeto padrão DACL.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se a DACL padrão tiver sido recuperado, FALSE caso contrário.

##  <a name="geteffectivetoken"></a>  CAccessToken::GetEffectiveToken

Chame esse método para obter o `CAccessToken` objeto igual ao token de acesso em vigor para o thread atual.

```
bool GetEffectiveToken(DWORD dwDesiredAccess) throw();
```

### <a name="parameters"></a>Parâmetros

*dwDesiredAccess*<br/>
Especifica uma máscara de acesso que especifica os tipos de acesso para o token de acesso solicitados. Esses tipos de acesso solicitado são comparados com a DACL do token para determinar quais acessos são concedidos ou negados.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

##  <a name="getgroups"></a>  CAccessToken::GetGroups

Chame esse método para retornar o `CAccessToken` grupos de token do objeto.

```
bool GetGroups(CTokenGroups* pGroups) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pGroups*<br/>
Ponteiro para o [classe CTokenGroups](../../atl/reference/ctokengroups-class.md) objeto que receberá as informações de grupo.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

##  <a name="gethandle"></a>  CAccessToken::GetHandle

Chame esse método para recuperar um identificador para o token de acesso.

```
HANDLE GetHandle() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna um identificador para o `CAccessToken` token de acesso do objeto.

##  <a name="getimpersonationlevel"></a>  CAccessToken::GetImpersonationLevel

Chame esse método para obter o nível de representação do token de acesso.

```
bool GetImpersonationLevel(
    SECURITY_IMPERSONATION_LEVEL* pImpersonationLevel) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pImpersonationLevel*<br/>
Ponteiro para um [SECURITY_IMPERSONATION_LEVEL](/windows/desktop/api/winnt/ne-winnt-_security_impersonation_level) tipo de enumeração que receberá as informações de nível de representação.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

##  <a name="getlogonsessionid"></a>  CAccessToken::GetLogonSessionId

Chame esse método para obter a ID de sessão de Logon associado a `CAccessToken` objeto.

```
bool GetLogonSessionId(LUID* pluid) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pluid*<br/>
Ponteiro para um [LUID](/windows/desktop/api/winnt/ns-winnt-_luid) que receberá a ID da sessão de Logon.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

Em compilações de depuração, um erro de asserção ocorrerá se *pluid* é um valor inválido.

##  <a name="getlogonsid"></a>  CAccessToken::GetLogonSid

Chame esse método para obter o SID de Logon associado a `CAccessToken` objeto.

```
bool GetLogonSid(CSid* pSid) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSid*<br/>
Ponteiro para um [classe CSid](../../atl/reference/csid-class.md) objeto.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

Em compilações de depuração, um erro de asserção ocorrerá se *pSid* é um valor inválido.

##  <a name="getowner"></a>  CAccessToken::GetOwner

Chame esse método para obter o proprietário associado a `CAccessToken` objeto.

```
bool GetOwner(CSid* pSid) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSid*<br/>
Ponteiro para um [classe CSid](../../atl/reference/csid-class.md) objeto.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

O proprietário é definido por padrão em todos os objetos criados enquanto esse token de acesso está em vigor.

##  <a name="getprimarygroup"></a>  CAccessToken::GetPrimaryGroup

Chame esse método para obter o grupo primário associado a `CAccessToken` objeto.

```
bool GetPrimaryGroup(CSid* pSid) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSid*<br/>
Ponteiro para um [classe CSid](../../atl/reference/csid-class.md) objeto.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

O grupo é definido por padrão em todos os objetos criados enquanto esse token de acesso está em vigor.

##  <a name="getprivileges"></a>  CAccessToken::GetPrivileges

Chame esse método para obter os privilégios associados a `CAccessToken` objeto.

```
bool GetPrivileges(CTokenPrivileges* pPrivileges) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pPrivileges*<br/>
Ponteiro para um [classe CTokenPrivileges](../../atl/reference/ctokenprivileges-class.md) objeto que receberá os privilégios.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

##  <a name="getprocesstoken"></a>  CAccessToken::GetProcessToken

Chame este método para inicializar o `CAccessToken` com o token de acesso do processo especificado.

```
bool GetProcessToken(DWORD dwDesiredAccess, HANDLE hProcess = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*dwDesiredAccess*<br/>
Especifica uma máscara de acesso que especifica os tipos de acesso para o token de acesso solicitados. Esses tipos de acesso solicitado são comparados com a DACL do token para determinar quais acessos são concedidos ou negados.

*hProcess*<br/>
Identificador para o processo cujo token de acesso é aberto. Se o valor padrão de NULL é usado, o processo atual será usado.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

Chamadas a [OpenProcessToken](https://msdn.microsoft.com/library/aa379295) função do Win32.

##  <a name="getprofile"></a>  CAccessToken::GetProfile

Chame esse método para obter o identificador que aponta para o perfil de usuário associado a `CAccessToken` objeto.

```
HANDLE GetProfile() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna um identificador que aponta para o perfil de usuário, ou nulo se não existe nenhum perfil.

##  <a name="getsource"></a>  CAccessToken::GetSource

Chame esse método para obter a origem do `CAccessToken` objeto.

```
bool GetSource(TOKEN_SOURCE* pSource) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSource*<br/>
Ponteiro para um [TOKEN_SOURCE](/windows/desktop/api/winnt/ns-winnt-_token_source) estrutura.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

##  <a name="getstatistics"></a>  CAccessToken::GetStatistics

Chame esse método para obter informações associadas a `CAccessToken` objeto.

```
bool GetStatistics(TOKEN_STATISTICS* pStatistics) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pStatistics*<br/>
Ponteiro para um [TOKEN_STATISTICS](/windows/desktop/api/winnt/ns-winnt-_token_statistics) estrutura.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

##  <a name="getterminalservicessessionid"></a>  CAccessToken::GetTerminalServicesSessionId

Chame esse método para obter a ID de sessão de serviços de Terminal associado com o `CAccessToken` objeto.

```
bool GetTerminalServicesSessionId(DWORD* pdwSessionId) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pdwSessionId*<br/>
A ID de sessão dos serviços de Terminal.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

##  <a name="getthreadtoken"></a>  CAccessToken::GetThreadToken

Chame este método para inicializar o `CAccessToken` com o token do thread especificado.

```
bool GetThreadToken(
    DWORD dwDesiredAccess,
    HANDLE hThread = NULL,
    bool bOpenAsSelf = true) throw();
```

### <a name="parameters"></a>Parâmetros

*dwDesiredAccess*<br/>
Especifica uma máscara de acesso que especifica os tipos de acesso para o token de acesso solicitados. Esses tipos de acesso solicitado são comparados com a DACL do token para determinar quais acessos são concedidos ou negados.

*hThread*<br/>
Identificador para o thread cujo token de acesso é aberto.

*bOpenAsSelf*<br/>
Indica se a verificação de acesso deve ser feita no contexto de segurança de chamada do thread a `GetThreadToken` método ou em relação ao contexto de segurança do processo para o thread de chamada.

Se esse parâmetro for FALSE, a verificação de acesso é executada usando o contexto de segurança para o thread de chamada. Se o thread estiver representando um cliente, este contexto de segurança pode ser de um processo do cliente. Se esse parâmetro for TRUE, a verificação de acesso é feita usando o contexto de segurança do processo para o thread de chamada.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

##  <a name="gettokenid"></a>  CAccessToken::GetTokenId

Chame esse método para obter a ID do Token associado com o `CAccessToken` objeto.

```
bool GetTokenId(LUID* pluid) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pluid*<br/>
Ponteiro para um [LUID](/windows/desktop/api/winnt/ns-winnt-_luid) que receberá a ID do Token.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

##  <a name="gettype"></a>  CAccessToken::GetType

Chame esse método para obter o tipo de token do `CAccessToken` objeto.

```
bool GetType(TOKEN_TYPE* pType) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*PDigite*<br/>
Endereço do [TOKEN_TYPE](/windows/desktop/api/winnt/ne-winnt-_token_type) variável que, em caso de sucesso, recebe o tipo do token.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

O tipo de enumeração TOKEN_TYPE contém valores que fazem distinção entre um token primário e um token de representação.

##  <a name="getuser"></a>  CAccessToken::GetUser

Chame esse método para identificar o usuário associado com o `CAccessToken` objeto.

```
bool GetUser(CSid* pSid) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSid*<br/>
Ponteiro para um [classe CSid](../../atl/reference/csid-class.md) objeto.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

##  <a name="hkeycurrentuser"></a>  CAccessToken::HKeyCurrentUser

Chame esse método para obter o identificador que aponta para o perfil de usuário associado a `CAccessToken` objeto.

```
HKEY HKeyCurrentUser() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna um identificador que aponta para o perfil de usuário, ou nulo se não existe nenhum perfil.

##  <a name="impersonate"></a>  CAccessToken::Impersonate

Chame esse método para atribuir uma representação `CAccessToken` a um thread.

```
bool Impersonate(HANDLE hThread = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*hThread*<br/>
Identificador para o thread para atribuir o token de representação para. Esse identificador deve ter sido aberto com direitos de acesso TOKEN_IMPERSONATE. Se *hThread* for NULL, o método faz com que o thread para parar de usar um token de representação.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

Em compilações de depuração, um erro de asserção ocorrerá se `CAccessToken` não tem um ponteiro válido para um token.

O [classe CAutoRevertImpersonation](../../atl/reference/cautorevertimpersonation-class.md) pode ser usado para reverter automaticamente tokens de acesso representado.

##  <a name="impersonateloggedonuser"></a>  CAccessToken::ImpersonateLoggedOnUser

Chame esse método para permitir que o thread de chamada representar o contexto de segurança de um logon do usuário.

```
bool ImpersonateLoggedOnUser() const throw(...);
```

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

> [!IMPORTANT]
>  Se uma chamada para uma função de representação falhar por algum motivo, o cliente não é representado e o cliente é feita no contexto de segurança do processo do qual a chamada foi feita. Se o processo é executado como uma conta altamente privilegiada ou como um membro de um grupo administrativo, o usuário poderá executar ações ele ou ela seria caso contrário, não ser permitida. Portanto, o valor retornado para esta função sempre deve ser confirmado.

##  <a name="istokenrestricted"></a>  CAccessToken::IsTokenRestricted

Chame esse método para testar se o `CAccessToken` objeto contém uma lista de SIDs restritos.

```
bool IsTokenRestricted() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o objeto contém uma lista de SIDs de restrição, FALSE se não houver nenhum SIDs de restrição ou se o método falhar.

##  <a name="loaduserprofile"></a>  CAccessToken::LoadUserProfile

Chame esse método para carregar o perfil do usuário associado com o `CAccessToken` objeto.

```
bool LoadUserProfile() throw(...);
```

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

Em compilações de depuração, um erro de asserção ocorrerá se o `CAccessToken` não contém um token válido, ou se um usuário de perfil já existe.

##  <a name="logonuser"></a>  CAccessToken::LogonUser

Chame esse método para criar uma sessão de logon para o usuário associado com as credenciais fornecidas.

```
bool LogonUser(
    LPCTSTR pszUserName,
    LPCTSTR pszDomain,
    LPCTSTR pszPassword,
    DWORD dwLogonType = LOGON32_LOGON_INTERACTIVE,
    DWORD dwLogonProvider = LOGON32_PROVIDER_DEFAULT) throw();
```

### <a name="parameters"></a>Parâmetros

*pszUserName*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome de usuário. Esse é o nome da conta de usuário para fazer logon no.

*pszDomain*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do domínio ou servidor de banco de dados cujo conta contém o *pszUserName* conta.

*pszPassword*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica a senha de texto não criptografado para a conta de usuário especificada por *pszUserName*.

*dwLogonType*<br/>
Especifica o tipo de operação de logon a ser executada. Ver [LogonUser](/windows/desktop/api/winbase/nf-winbase-logonusera) para obter mais detalhes.

*dwLogonProvider*<br/>
Especifica o provedor de logon. Ver [LogonUser](/windows/desktop/api/winbase/nf-winbase-logonusera) para obter mais detalhes.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

O acesso resultante de token de logon será associado a `CAccessToken`. Para esse método seja bem-sucedido, o `CAccessToken` objeto deve manter privilégios SE_TCB_NAME, identificar o proprietário como parte do computador confiável base. Ver [LogonUser](/windows/desktop/api/winbase/nf-winbase-logonusera) para obter mais informações sobre os privilégios necessários.

##  <a name="opencomclienttoken"></a>  CAccessToken::OpenCOMClientToken

Chame esse método de dentro de um servidor COM tratamento de uma chamada de um cliente para inicializar o `CAccessToken` com o token de acesso do cliente COM.

```
bool OpenCOMClientToken(
    DWORD dwDesiredAccess,
    bool bImpersonate = false,
    bool bOpenAsSelf = true) throw(...);
```

### <a name="parameters"></a>Parâmetros

*dwDesiredAccess*<br/>
Especifica uma máscara de acesso que especifica os tipos de acesso para o token de acesso solicitados. Esses tipos de acesso solicitado são comparados com a DACL do token para determinar quais acessos são concedidos ou negados.

*bImpersonate*<br/>
Se for TRUE, o thread atual será representar o cliente COM chamada se essa chamada for concluída com êxito. Se for FALSE, o token de acesso será aberto, mas o thread não terá um token de representação quando esta chamada é concluída.

*bOpenAsSelf*<br/>
Indica se a verificação de acesso deve ser feita no contexto de segurança de chamada do thread a [GetThreadToken](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthread) método ou em relação ao contexto de segurança do processo para o thread de chamada.

Se esse parâmetro for FALSE, a verificação de acesso é executada usando o contexto de segurança para o thread de chamada. Se o thread estiver representando um cliente, este contexto de segurança pode ser de um processo do cliente. Se esse parâmetro for TRUE, a verificação de acesso é feita usando o contexto de segurança do processo para o thread de chamada.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

O [classe CAutoRevertImpersonation](../../atl/reference/cautorevertimpersonation-class.md) pode ser usado para reverter automaticamente tokens de acesso representado criados pela definição de *bImpersonate* sinalizador como TRUE.

##  <a name="opennamedpipeclienttoken"></a>  CAccessToken::OpenNamedPipeClientToken

Chame esse método de dentro de um servidor levando solicitações ao longo de um pipe nomeado para inicializar o `CAccessToken` com o token de acesso do cliente.

```
bool OpenNamedPipeClientToken(
    HANDLE hPipe,
    DWORD dwDesiredAccess,
    bool bImpersonate = false,
    bool bOpenAsSelf = true) throw(...);
```

### <a name="parameters"></a>Parâmetros

*hPipe*<br/>
Identificador para um pipe nomeado.

*dwDesiredAccess*<br/>
Especifica uma máscara de acesso que especifica os tipos de acesso para o token de acesso solicitados. Esses tipos de acesso solicitado são comparados com a DACL do token para determinar quais acessos são concedidos ou negados.

*bImpersonate*<br/>
Se for TRUE, o thread atual representar o cliente da chamada de pipe se essa chamada for concluída com êxito. Se for FALSE, o token de acesso será aberto, mas o thread não terá um token de representação quando esta chamada é concluída.

*bOpenAsSelf*<br/>
Indica se a verificação de acesso deve ser feita no contexto de segurança de chamada do thread a [GetThreadToken](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthread) método ou em relação ao contexto de segurança do processo para o thread de chamada.

Se esse parâmetro for FALSE, a verificação de acesso é executada usando o contexto de segurança para o thread de chamada. Se o thread estiver representando um cliente, este contexto de segurança pode ser de um processo do cliente. Se esse parâmetro for TRUE, a verificação de acesso é feita usando o contexto de segurança do processo para o thread de chamada.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

O [classe CAutoRevertImpersonation](../../atl/reference/cautorevertimpersonation-class.md) pode ser usado para reverter automaticamente tokens de acesso representado criados pela definição de *bImpersonate* sinalizador como TRUE.

##  <a name="openrpcclienttoken"></a>  CAccessToken::OpenRPCClientToken

Chame esse método de dentro de um servidor de tratamento de uma chamada de um cliente RPC para inicializar o `CAccessToken` com o token de acesso do cliente.

```
bool OpenRPCClientToken(
    RPC_BINDING_HANDLE BindingHandle,
    DWORD dwDesiredAccess,
    bool bImpersonate = false,
    bool bOpenAsSelf = true) throw(...);
```

### <a name="parameters"></a>Parâmetros

*BindingHandle*<br/>
Identificador de ligação no servidor que representa uma associação a um cliente.

*dwDesiredAccess*<br/>
Especifica uma máscara de acesso que especifica os tipos de acesso para o token de acesso solicitados. Esses tipos de acesso solicitado são comparados com a DACL do token para determinar quais acessos são concedidos ou negados.

*bImpersonate*<br/>
Se for TRUE, o thread atual representar o cliente da chamada de RPC se essa chamada for concluída com êxito. Se for FALSE, o token de acesso será aberto, mas o thread não terá um token de representação quando esta chamada é concluída.

*bOpenAsSelf*<br/>
Indica se a verificação de acesso deve ser feita no contexto de segurança de chamada do thread a [GetThreadToken](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthread) método ou em relação ao contexto de segurança do processo para o thread de chamada.

Se esse parâmetro for FALSE, a verificação de acesso é executada usando o contexto de segurança para o thread de chamada. Se o thread estiver representando um cliente, este contexto de segurança pode ser de um processo do cliente. Se esse parâmetro for TRUE, a verificação de acesso é feita usando o contexto de segurança do processo para o thread de chamada.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

O [classe CAutoRevertImpersonation](../../atl/reference/cautorevertimpersonation-class.md) pode ser usado para reverter automaticamente tokens de acesso representado criados pela definição de *bImpersonate* sinalizador como TRUE.

##  <a name="openthreadtoken"></a>  CAccessToken::OpenThreadToken

Chame esse método para definir o nível de representação e, em seguida, inicialize o `CAccessToken` com o token do thread especificado.

```
bool OpenThreadToken(
    DWORD dwDesiredAccess,
    bool bImpersonate = false,
    bool bOpenAsSelf = true,
    SECURITY_IMPERSONATION_LEVEL sil = SecurityImpersonation) throw(...);
```

### <a name="parameters"></a>Parâmetros

*dwDesiredAccess*<br/>
Especifica uma máscara de acesso que especifica os tipos de acesso para o token de acesso solicitados. Esses tipos de acesso solicitado são comparados com a DACL do token para determinar quais acessos são concedidos ou negados.

*bImpersonate*<br/>
Se for TRUE, o thread será deixado no nível de representação solicitado após a conclusão desse método. Se for FALSE, o thread será revertido para seu nível de representação original.

*bOpenAsSelf*<br/>
Indica se a verificação de acesso deve ser feita no contexto de segurança de chamada do thread a [GetThreadToken](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthread) método ou em relação ao contexto de segurança do processo para o thread de chamada.

Se esse parâmetro for FALSE, a verificação de acesso é executada usando o contexto de segurança para o thread de chamada. Se o thread estiver representando um cliente, este contexto de segurança pode ser de um processo do cliente. Se esse parâmetro for TRUE, a verificação de acesso é feita usando o contexto de segurança do processo para o thread de chamada.

*Sil*<br/>
Especifica um [SECURITY_IMPERSONATION_LEVEL](/windows/desktop/api/winnt/ne-winnt-_security_impersonation_level) que fornece o nível de representação do token de tipo enumerado.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

`OpenThreadToken` é semelhante à [CAccessToken::GetThreadToken](#getthreadtoken), mas define o nível de representação antes de inicializar o `CAccessToken` do token de acesso do thread.

O [classe CAutoRevertImpersonation](../../atl/reference/cautorevertimpersonation-class.md) pode ser usado para reverter automaticamente tokens de acesso representado criados pela definição de *bImpersonate* sinalizador como TRUE.

##  <a name="privilegecheck"></a>  CAccessToken::PrivilegeCheck

Chame esse método para determinar se um conjunto especificado de privilégios estão habilitadas no `CAccessToken` objeto.

```
bool PrivilegeCheck(
    PPRIVILEGE_SET RequiredPrivileges,
     bool* pbResult) const throw();
```

### <a name="parameters"></a>Parâmetros

*RequiredPrivileges*<br/>
Ponteiro para um [PRIVILEGE_SET](/windows/desktop/api/winnt/ns-winnt-_privilege_set) estrutura.

*pbResult*<br/>
O método define um ponteiro para um valor para indicar se algum ou todos o privilégio especificado estão habilitados no `CAccessToken` objeto.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

Quando `PrivilegeCheck` retorna, o `Attributes` membro de cada [LUID_AND_ATTRIBUTES](/windows/desktop/api/winnt/ns-winnt-_luid_and_attributes) estrutura é definida como SE_PRIVILEGE_USED_FOR_ACCESS se o privilégio correspondente está habilitado. Este método chama o [PrivilegeCheck](https://msdn.microsoft.com/library/windows/desktop/aa379304) função do Win32.

##  <a name="revert"></a>  CAccessToken::Revert

Chame esse método para interromper um thread que usa um token de representação.

```
bool Revert(HANDLE hThread = NULL) const throw();
```

### <a name="parameters"></a>Parâmetros

*hThread*<br/>
Identificador para o thread será revertida de representação. Se *hThread* for NULL, o thread atual será assumido.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

A reversão de tokens de representação pode ser executada automaticamente com o [classe CAutoRevertImpersonation](../../atl/reference/cautorevertimpersonation-class.md).

##  <a name="setdefaultdacl"></a>  CAccessToken::SetDefaultDacl

Chame esse método para definir o padrão de DACL do `CAccessToken` objeto.

```
bool SetDefaultDacl(const CDacl& rDacl) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rDacl*<br/>
O novo padrão [classe CDacl](../../atl/reference/cdacl-class.md) informações.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

A DACL padrão é o DACL que é usado por padrão quando novos objetos são criados com esse token de acesso em vigor.

##  <a name="setowner"></a>  CAccessToken::SetOwner

Chame esse método para definir o proprietário do `CAccessToken` objeto.

```
bool SetOwner(const CSid& rSid) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
O [classe CSid](../../atl/reference/csid-class.md) que contém as informações do proprietário do objeto.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

O proprietário é o proprietário padrão que é usado para novos objetos criados enquanto esse token de acesso está em vigor.

##  <a name="setprimarygroup"></a>  CAccessToken::SetPrimaryGroup

Chame esse método para definir o grupo primário do `CAccessToken` objeto.

```
bool SetPrimaryGroup(const CSid& rSid) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
O [classe CSid](../../atl/reference/csid-class.md) objeto que contém as informações de grupo primário.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

O grupo primário é o grupo padrão para novos objetos criados enquanto esse token de acesso estiver em vigor.

## <a name="see-also"></a>Consulte também

[Exemplo de ATLSecurity](../../visual-cpp-samples.md)<br/>
[Tokens de acesso](/windows/desktop/SecAuthZ/access-tokens)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
