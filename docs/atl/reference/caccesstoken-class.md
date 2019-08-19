---
title: Classe CAccessToken
ms.date: 07/02/2019
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
helpviewer_keywords:
- CAccessToken class
ms.assetid: bb5c5945-56a5-4083-b442-76573cee83ab
ms.openlocfilehash: fa50282f3aa1f4db3ebf6306fa9dc3dab1311d1b
ms.sourcegitcommit: 46d24d6e70c03e05484923d9efc6ed5150e96a64
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2019
ms.locfileid: "68915907"
---
# <a name="caccesstoken-class"></a>Classe CAccessToken

Essa classe é um wrapper para um token de acesso.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
class CAccessToken
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAccessToken::~CAccessToken](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAccessToken::Attach](#attach)|Chame esse método para apropriar-se do identificador de token de acesso fornecido.|
|[CAccessToken::CheckTokenMembership](#checktokenmembership)|Chame esse método para determinar se um SID especificado está habilitado no `CAccessToken` objeto.|
|[CAccessToken::CreateImpersonationToken](#createimpersonationtoken)|Chame esse método para criar um novo token de acesso de representação.|
|[CAccessToken::CreatePrimaryToken](#createprimarytoken)|Chame esse método para criar um novo token primário.|
|[CAccessToken::CreateProcessAsUser](#createprocessasuser)|Chame esse método para criar um novo processo em execução no contexto de segurança do usuário representado pelo `CAccessToken` objeto.|
|[CAccessToken::CreateRestrictedToken](#createrestrictedtoken)|Chame esse método para criar um novo objeto restrito `CAccessToken` .|
|[CAccessToken::Detach](#detach)|Chame esse método para revogar a propriedade do token de acesso.|
|[CAccessToken::DisablePrivilege](#disableprivilege)|Chame esse método para desabilitar um privilégio no `CAccessToken` objeto.|
|[CAccessToken::DisablePrivileges](#disableprivileges)|Chame esse método para desabilitar um ou mais privilégios no `CAccessToken` objeto.|
|[CAccessToken::EnablePrivilege](#enableprivilege)|Chame esse método para habilitar um privilégio no `CAccessToken` objeto.|
|[CAccessToken::EnablePrivileges](#enableprivileges)|Chame esse método para habilitar um ou mais privilégios no `CAccessToken` objeto.|
|[CAccessToken::GetDefaultDacl](#getdefaultdacl)|Chame esse método para retornar a `CAccessToken` DACL padrão do objeto.|
|[CAccessToken::GetEffectiveToken](#geteffectivetoken)|Chame esse método para obter o `CAccessToken` objeto igual ao token de acesso em vigor para o thread atual.|
|[CAccessToken::GetGroups](#getgroups)|Chame esse método para retornar os `CAccessToken` grupos de tokens do objeto.|
|[CAccessToken::GetHandle](#gethandle)|Chame esse método para recuperar um identificador para o token de acesso.|
|[CAccessToken::GetImpersonationLevel](#getimpersonationlevel)|Chame esse método para obter o nível de representação do token de acesso.|
|[CAccessToken::GetLogonSessionId](#getlogonsessionid)|Chame esse método para obter a ID de sessão de logon associada `CAccessToken` ao objeto.|
|[CAccessToken::GetLogonSid](#getlogonsid)|Chame esse método para obter o Sid de logon associado `CAccessToken` ao objeto.|
|[CAccessToken::GetOwner](#getowner)|Chame esse método para obter o proprietário associado `CAccessToken` ao objeto.|
|[CAccessToken::GetPrimaryGroup](#getprimarygroup)|Chame esse método para obter o grupo primário associado `CAccessToken` ao objeto.|
|[CAccessToken::GetPrivileges](#getprivileges)|Chame esse método para obter os privilégios associados `CAccessToken` ao objeto.|
|[CAccessToken::GetProcessToken](#getprocesstoken)|Chame esse método para inicializar o `CAccessToken` com o token de acesso do processo fornecido.|
|[CAccessToken::GetProfile](#getprofile)|Chame esse método para obter o identificador que aponta para o perfil do usuário associado `CAccessToken` ao objeto.|
|[CAccessToken::GetSource](#getsource)|Chame esse método para obter a origem do `CAccessToken` objeto.|
|[CAccessToken::GetStatistics](#getstatistics)|Chame esse método para obter informações associadas `CAccessToken` ao objeto.|
|[CAccessToken::GetTerminalServicesSessionId](#getterminalservicessessionid)|Chame esse método para obter a ID de sessão dos serviços de terminal `CAccessToken` associada ao objeto.|
|[CAccessToken::GetThreadToken](#getthreadtoken)|Chame esse método para inicializar o `CAccessToken` com o token do thread fornecido.|
|[CAccessToken::GetTokenId](#gettokenid)|Chame esse método para obter a ID de token associada `CAccessToken` ao objeto.|
|[CAccessToken::GetType](#gettype)|Chame esse método para obter o tipo de token do `CAccessToken` objeto.|
|[CAccessToken::GetUser](#getuser)|Chame esse método para identificar o usuário associado `CAccessToken` ao objeto.|
|[CAccessToken::HKeyCurrentUser](#hkeycurrentuser)|Chame esse método para obter o identificador que aponta para o perfil do usuário associado `CAccessToken` ao objeto.|
|[CAccessToken::Impersonate](#impersonate)|Chame esse método para atribuir uma representação `CAccessToken` a um thread.|
|[CAccessToken::ImpersonateLoggedOnUser](#impersonateloggedonuser)|Chame esse método para permitir que o thread de chamada represente o contexto de segurança de um usuário conectado.|
|[CAccessToken::IsTokenRestricted](#istokenrestricted)|Chame esse método para testar se o `CAccessToken` objeto contém uma lista de SIDs restritos.|
|[CAccessToken::LoadUserProfile](#loaduserprofile)|Chame esse método para carregar o perfil do usuário associado `CAccessToken` ao objeto.|
|[CAccessToken::LogonUser](#logonuser)|Chame esse método para criar uma sessão de logon para o usuário associado às credenciais fornecidas.|
|[CAccessToken::OpenCOMClientToken](#opencomclienttoken)|Chame esse método de dentro de um servidor com que trate uma chamada de um cliente para `CAccessToken` inicializar o com o token de acesso do cliente com.|
|[CAccessToken::OpenNamedPipeClientToken](#opennamedpipeclienttoken)|Chame esse método de dentro de um servidor fazendo solicitações em um pipe nomeado para inicializar `CAccessToken` o com o token de acesso do cliente.|
|[CAccessToken::OpenRPCClientToken](#openrpcclienttoken)|Chame esse método de dentro de um servidor que manipula uma chamada de um cliente RPC para `CAccessToken` inicializar o com o token de acesso do cliente.|
|[CAccessToken::OpenThreadToken](#openthreadtoken)|Chame esse método para definir o nível de representação e, em `CAccessToken` seguida, inicialize o com o token do thread fornecido.|
|[CAccessToken::PrivilegeCheck](#privilegecheck)|Chame esse método para determinar se um conjunto especificado de privilégios está habilitado no `CAccessToken` objeto.|
|[CAccessToken::Revert](#revert)|Chame esse método para interromper um thread que está usando um token de representação.|
|[CAccessToken::SetDefaultDacl](#setdefaultdacl)|Chame esse método para definir a DACL padrão do `CAccessToken` objeto.|
|[CAccessToken::SetOwner](#setowner)|Chame esse método para definir o proprietário do `CAccessToken` objeto.|
|[CAccessToken::SetPrimaryGroup](#setprimarygroup)|Chame esse método para definir o grupo primário do `CAccessToken` objeto.|

## <a name="remarks"></a>Comentários

Um [token de acesso](/windows/desktop/SecAuthZ/access-tokens) é um objeto que descreve o contexto de segurança de um processo ou thread e é alocado para cada usuário conectado em um sistema Windows.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [controle de acesso](/windows/desktop/SecAuthZ/access-control) no SDK do Windows.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLSecurity. h

##  <a name="attach"></a>  CAccessToken::Attach

Chame esse método para apropriar-se do identificador de token de acesso fornecido.

```
void Attach(HANDLE hToken) throw();
```

### <a name="parameters"></a>Parâmetros

*hToken*<br/>
Um identificador para o token de acesso.

### <a name="remarks"></a>Comentários

Em compilações de depuração, ocorrerá um erro de `CAccessToken` asserção se o objeto já tiver a propriedade de um token de acesso.

##  <a name="dtor"></a>  CAccessToken::~CAccessToken

O destruidor.

```
virtual ~CAccessToken() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

##  <a name="checktokenmembership"></a>  CAccessToken::CheckTokenMembership

Chame esse método para determinar se um SID especificado está habilitado no `CAccessToken` objeto.

```
bool CheckTokenMembership(
    const CSid& rSid,
    bool* pbIsMember) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
Referência a um objeto de [classe CSid](../../atl/reference/csid-class.md) .

*pbIsMember*<br/>
Ponteiro para uma variável que recebe os resultados da verificação.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

O `CheckTokenMembership` método verifica a presença do Sid nos SIDs de usuário e grupo do token de acesso. Se o SID estiver presente e tiver o atributo SE_GROUP_ENABLED, *pbIsMember* será definido como true; caso contrário, ele será definido como FALSE.

Em compilações de depuração, ocorrerá um erro de asserção se *pbIsMember* não for um ponteiro válido.

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

*sil*<br/>
Especifica um tipo enumerado [SECURITY_IMPERSONATION_LEVEL](/windows/desktop/api/winnt/ne-winnt-security_impersonation_level) que fornece o nível de representação do novo token.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

`CreateImpersonationToken`chama [DuplicateToken](/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetoken) para criar um novo token de representação.

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
Especifica os direitos de acesso solicitados para o novo token. O padrão, MAXIMUM_ALLOWED, solicita todos os direitos de acesso válidos para o chamador. Consulte [direitos de acesso e máscaras de acesso](/windows/desktop/SecAuthZ/access-rights-and-access-masks) para obter mais informações sobre direitos de acesso.

*pTokenAttributes*<br/>
Ponteiro para uma estrutura [SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\)) que especifica um descritor de segurança para o novo token e determina se os processos filho podem herdar o token. Se *pTokenAttributes* for NULL, o token obterá um descritor de segurança padrão e o identificador não poderá ser herdado.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

`CreatePrimaryToken`chama [DuplicateTokenEx](/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetokenex) para criar um novo token primário.

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
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o módulo a ser executado. Este parâmetro não pode ser nulo.

*pCommandLine*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica a linha de comando a ser executada.

*pProcessInformation*<br/>
Ponteiro para uma [estrutura PROCESS_INFORMATION](/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_information) que recebe informações de identificação sobre o novo processo.

*pStartupInfo*<br/>
Ponteiro para uma estrutura [STARTUPINFO](/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa) que especifica como a janela principal para o novo processo deve aparecer.

*dwCreationFlags*<br/>
Especifica sinalizadores adicionais que controlam a classe de prioridade e a criação do processo. Consulte a função [CreateProcessAsUser](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) do Win32 para obter uma lista de sinalizadores.

*bLoadProfile*<br/>
Se for TRUE, o perfil do usuário será carregado com [LoadUserProfile](/windows/desktop/api/userenv/nf-userenv-loaduserprofilea).

*pProcessAttributes*<br/>
Ponteiro para uma estrutura [SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\)) que especifica um descritor de segurança para o novo processo e determina se os processos filho podem herdar o identificador retornado. Se *pProcessAttributes* for NULL, o processo obterá um descritor de segurança padrão e o identificador não poderá ser herdado.

*pThreadAttributes*<br/>
Ponteiro para uma estrutura [SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\)) que especifica um descritor de segurança para o novo thread e determina se os processos filho podem herdar o identificador retornado. Se *pThreadAttributes* for NULL, o thread obterá um descritor de segurança padrão e o identificador não poderá ser herdado.

*bInherit*<br/>
Indica se o novo processo herda identificadores do processo de chamada. Se for TRUE, cada identificador de abertura herdável no processo de chamada será herdado pelo novo processo. Os identificadores herdados têm o mesmo valor e os mesmos privilégios de acesso que os identificadores originais.

*pCurrentDirectory*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica a unidade e o diretório atuais para o novo processo. A cadeia de caracteres deve ser um caminho completo que inclui uma letra de unidade. Se esse parâmetro for nulo, o novo processo terá a mesma unidade e diretório atuais que o processo de chamada.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

`CreateProcessAsUser`usa a `CreateProcessAsUser` função do Win32 para criar um novo processo que é executado no contexto de segurança do usuário representado `CAccessToken` pelo objeto. Consulte a descrição da função [CreateProcessAsUser](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) para obter uma discussão completa dos parâmetros necessários.

Para que esse método seja bem sucedido, o objeto deve conter AssignPrimaryToken (a menos que seja um token restrito) e privilégios de `CAccessToken` IncreaseQuota.

##  <a name="createrestrictedtoken"></a>  CAccessToken::CreateRestrictedToken

Chame esse método para criar um novo objeto restrito `CAccessToken` .

```
bool CreateRestrictedToken(
    CAccessToken* pRestrictedToken,
    const CTokenGroups& SidsToDisable,
    const CTokenGroups& SidsToRestrict,
    const CTokenPrivileges& PrivilegesToDelete = CTokenPrivileges()) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pRestrictedToken*<br/>
O novo objeto restrito `CAccessToken` .

*SidsToDisable*<br/>
Um `CTokenGroups` objeto que especifica os SIDs somente de negação.

*SidsToRestrict*<br/>
Um `CTokenGroups` objeto que especifica os SIDs de restrição.

*PrivilegesToDelete*<br/>
Um `CTokenPrivileges` objeto que especifica os privilégios a serem excluídos no token restrito. O padrão cria um objeto vazio.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

`CreateRestrictedToken`usa a função Win32 [CreateRestrictedToken](/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createrestrictedtoken) para criar um novo `CAccessToken` objeto, com restrições.

> [!IMPORTANT]
>  Ao usar `CreateRestrictedToken`o, verifique o seguinte: o token existente é válido (e não é inserido pelo usuário) e *SidsToDisable* e *PrivilegesToDelete* são válidos (e não são inseridos pelo usuário). Se o método retornar FALSE, negue funcionalidade.

##  <a name="detach"></a>  CAccessToken::Detach

Chame esse método para revogar a propriedade do token de acesso.

```
HANDLE Detach() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o identificador para o `CAccessToken` que foi desanexado.

### <a name="remarks"></a>Comentários

Esse método revoga a `CAccessToken`Propriedade do token de acesso.

##  <a name="disableprivilege"></a>  CAccessToken::DisablePrivilege

Chame esse método para desabilitar um privilégio no `CAccessToken` objeto.

```
bool DisablePrivilege(
    LPCTSTR pszPrivilege,
    CTokenPrivileges* pPreviousState = NULL) throw(...);
```

### <a name="parameters"></a>Parâmetros

*pszPrivilege*<br/>
Ponteiro para uma cadeia de caracteres que contém o privilégio a `CAccessToken` ser desabilitado no objeto.

*pPreviousState*<br/>
Ponteiro para um `CTokenPrivileges` objeto que conterá o estado anterior dos privilégios.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

##  <a name="disableprivileges"></a>  CAccessToken::DisablePrivileges

Chame esse método para desabilitar um ou mais privilégios no `CAccessToken` objeto.

```
bool DisablePrivileges(
    const CAtlArray<LPCTSTR>& rPrivileges,
    CTokenPrivileges* pPreviousState = NULL) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rPrivileges*<br/>
Ponteiro para uma matriz de cadeias de caracteres que contém os privilégios `CAccessToken` a serem desabilitados no objeto.

*pPreviousState*<br/>
Ponteiro para um `CTokenPrivileges` objeto que conterá o estado anterior dos privilégios.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

##  <a name="enableprivilege"></a>  CAccessToken::EnablePrivilege

Chame esse método para habilitar um privilégio no `CAccessToken` objeto.

```
bool EnablePrivilege(
    LPCTSTR pszPrivilege,
    CTokenPrivileges* pPreviousState = NULL) throw(...);
```

### <a name="parameters"></a>Parâmetros

*pszPrivilege*<br/>
Ponteiro para uma cadeia de caracteres que contém o privilégio a `CAccessToken` ser habilitado no objeto.

*pPreviousState*<br/>
Ponteiro para um `CTokenPrivileges` objeto que conterá o estado anterior dos privilégios.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

##  <a name="enableprivileges"></a>  CAccessToken::EnablePrivileges

Chame esse método para habilitar um ou mais privilégios no `CAccessToken` objeto.

```
bool EnablePrivileges(
    const CAtlArray<LPCTSTR>& rPrivileges,
    CTokenPrivileges* pPreviousState = NULL) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rPrivileges*<br/>
Ponteiro para uma matriz de cadeias de caracteres que contém os privilégios `CAccessToken` a serem habilitados no objeto.

*pPreviousState*<br/>
Ponteiro para um `CTokenPrivileges` objeto que conterá o estado anterior dos privilégios.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

##  <a name="getdefaultdacl"></a>  CAccessToken::GetDefaultDacl

Chame esse método para retornar a `CAccessToken` DACL padrão do objeto.

```
bool GetDefaultDacl(CDacl* pDacl) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pDacl*<br/>
Ponteiro para o objeto da [classe CDacl](../../atl/reference/cdacl-class.md) que receberá `CAccessToken` a DACL padrão do objeto.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se a DACL padrão tiver sido recuperada; caso contrário, FALSE.

##  <a name="geteffectivetoken"></a>  CAccessToken::GetEffectiveToken

Chame esse método para obter o `CAccessToken` objeto igual ao token de acesso em vigor para o thread atual.

```
bool GetEffectiveToken(DWORD dwDesiredAccess) throw();
```

### <a name="parameters"></a>Parâmetros

*dwDesiredAccess*<br/>
Especifica uma máscara de acesso que especifica os tipos de acesso solicitados ao token de acesso. Esses tipos de acesso solicitados são comparados com a DACL do token para determinar quais acessos são concedidos ou negados.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

##  <a name="getgroups"></a>  CAccessToken::GetGroups

Chame esse método para retornar os `CAccessToken` grupos de tokens do objeto.

```
bool GetGroups(CTokenGroups* pGroups) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pGroups*<br/>
Ponteiro para o objeto da [classe CTokenGroups](../../atl/reference/ctokengroups-class.md) que receberá as informações do grupo.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

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
Ponteiro para um tipo de enumeração [SECURITY_IMPERSONATION_LEVEL](/windows/desktop/api/winnt/ne-winnt-security_impersonation_level) que receberá as informações de nível de representação.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

##  <a name="getlogonsessionid"></a>  CAccessToken::GetLogonSessionId

Chame esse método para obter a ID de sessão de logon associada `CAccessToken` ao objeto.

```
bool GetLogonSessionId(LUID* pluid) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pluid*<br/>
Ponteiro para um [LUID](/windows/desktop/api/winnt/ns-winnt-luid) que receberá a ID de sessão de logon.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Em compilações de depuração, ocorrerá um erro de asserção se *pluid* for um valor inválido.

##  <a name="getlogonsid"></a>  CAccessToken::GetLogonSid

Chame esse método para obter o Sid de logon associado `CAccessToken` ao objeto.

```
bool GetLogonSid(CSid* pSid) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSid*<br/>
Ponteiro para um objeto de [classe CSid](../../atl/reference/csid-class.md) .

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Em compilações de depuração, ocorrerá um erro de asserção se *psid* for um valor inválido.

##  <a name="getowner"></a>  CAccessToken::GetOwner

Chame esse método para obter o proprietário associado `CAccessToken` ao objeto.

```
bool GetOwner(CSid* pSid) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSid*<br/>
Ponteiro para um objeto de [classe CSid](../../atl/reference/csid-class.md) .

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

O proprietário é definido por padrão em todos os objetos criados enquanto esse token de acesso está em vigor.

##  <a name="getprimarygroup"></a>  CAccessToken::GetPrimaryGroup

Chame esse método para obter o grupo primário associado `CAccessToken` ao objeto.

```
bool GetPrimaryGroup(CSid* pSid) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSid*<br/>
Ponteiro para um objeto de [classe CSid](../../atl/reference/csid-class.md) .

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

O grupo é definido por padrão em todos os objetos criados enquanto esse token de acesso está em vigor.

##  <a name="getprivileges"></a>  CAccessToken::GetPrivileges

Chame esse método para obter os privilégios associados `CAccessToken` ao objeto.

```
bool GetPrivileges(CTokenPrivileges* pPrivileges) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pPrivileges*<br/>
Ponteiro para um objeto de [classe CTokenPrivileges](../../atl/reference/ctokenprivileges-class.md) que receberá os privilégios.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

##  <a name="getprocesstoken"></a>  CAccessToken::GetProcessToken

Chame esse método para inicializar o `CAccessToken` com o token de acesso do processo fornecido.

```
bool GetProcessToken(DWORD dwDesiredAccess, HANDLE hProcess = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*dwDesiredAccess*<br/>
Especifica uma máscara de acesso que especifica os tipos de acesso solicitados ao token de acesso. Esses tipos de acesso solicitados são comparados com a DACL do token para determinar quais acessos são concedidos ou negados.

*hProcess*<br/>
Identificador para o processo cujo token de acesso é aberto. Se o valor padrão de NULL for usado, o processo atual será usado.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Chama a função Win32 [OpenProcessToken](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocesstoken) .

##  <a name="getprofile"></a>  CAccessToken::GetProfile

Chame esse método para obter o identificador que aponta para o perfil do usuário associado `CAccessToken` ao objeto.

```
HANDLE GetProfile() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna um identificador que aponta para o perfil do usuário ou nulo se não existir nenhum perfil.

##  <a name="getsource"></a>  CAccessToken::GetSource

Chame esse método para obter a origem do `CAccessToken` objeto.

```
bool GetSource(TOKEN_SOURCE* pSource) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSource*<br/>
Ponteiro para uma estrutura [TOKEN_SOURCE](/windows/desktop/api/winnt/ns-winnt-token_source) .

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

##  <a name="getstatistics"></a>  CAccessToken::GetStatistics

Chame esse método para obter informações associadas `CAccessToken` ao objeto.

```
bool GetStatistics(TOKEN_STATISTICS* pStatistics) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pStatistics*<br/>
Ponteiro para uma estrutura [TOKEN_STATISTICS](/windows/desktop/api/winnt/ns-winnt-token_statistics) .

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

##  <a name="getterminalservicessessionid"></a>  CAccessToken::GetTerminalServicesSessionId

Chame esse método para obter a ID de sessão dos serviços de terminal `CAccessToken` associada ao objeto.

```
bool GetTerminalServicesSessionId(DWORD* pdwSessionId) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pdwSessionId*<br/>
A ID de sessão dos serviços de terminal.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

##  <a name="getthreadtoken"></a>  CAccessToken::GetThreadToken

Chame esse método para inicializar o `CAccessToken` com o token do thread fornecido.

```
bool GetThreadToken(
    DWORD dwDesiredAccess,
    HANDLE hThread = NULL,
    bool bOpenAsSelf = true) throw();
```

### <a name="parameters"></a>Parâmetros

*dwDesiredAccess*<br/>
Especifica uma máscara de acesso que especifica os tipos de acesso solicitados ao token de acesso. Esses tipos de acesso solicitados são comparados com a DACL do token para determinar quais acessos são concedidos ou negados.

*hThread*<br/>
Identificador para o thread cujo token de acesso é aberto.

*bOpenAsSelf*<br/>
Indica se a verificação de acesso deve ser feita no contexto de segurança do thread que chama o `GetThreadToken` método ou no contexto de segurança do processo para o thread de chamada.

Se esse parâmetro for FALSE, a verificação de acesso será executada usando o contexto de segurança para o thread de chamada. Se o thread estiver representando um cliente, esse contexto de segurança poderá ser o de um processo de cliente. Se esse parâmetro for TRUE, a verificação de acesso será feita usando o contexto de segurança do processo para o thread de chamada.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

##  <a name="gettokenid"></a>  CAccessToken::GetTokenId

Chame esse método para obter a ID de token associada `CAccessToken` ao objeto.

```
bool GetTokenId(LUID* pluid) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pluid*<br/>
Ponteiro para um [LUID](/windows/desktop/api/winnt/ns-winnt-luid) que receberá a ID do token.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

##  <a name="gettype"></a>  CAccessToken::GetType

Chame esse método para obter o tipo de token do `CAccessToken` objeto.

```
bool GetType(TOKEN_TYPE* pType) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pType*<br/>
Endereço da variável [TOKEN_TYPE](/windows/desktop/api/winnt/ne-winnt-token_type) que, em caso de êxito, recebe o tipo do token.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

O tipo de enumeração TOKEN_TYPE contém valores que diferenciam entre um token primário e um token de representação.

##  <a name="getuser"></a>  CAccessToken::GetUser

Chame esse método para identificar o usuário associado `CAccessToken` ao objeto.

```
bool GetUser(CSid* pSid) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSid*<br/>
Ponteiro para um objeto de [classe CSid](../../atl/reference/csid-class.md) .

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

##  <a name="hkeycurrentuser"></a>  CAccessToken::HKeyCurrentUser

Chame esse método para obter o identificador que aponta para o perfil do usuário associado `CAccessToken` ao objeto.

```
HKEY HKeyCurrentUser() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna um identificador que aponta para o perfil do usuário ou nulo se não existir nenhum perfil.

##  <a name="impersonate"></a>  CAccessToken::Impersonate

Chame esse método para atribuir uma representação `CAccessToken` a um thread.

```
bool Impersonate(HANDLE hThread = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*hThread*<br/>
Identificador para o thread ao qual atribuir o token de representação. Esse identificador deve ter sido aberto com direitos de acesso TOKEN_IMPERSONATE. Se *hThread* for NULL, o método fará com que o thread pare de usar um token de representação.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Em compilações de depuração, ocorrerá um erro `CAccessToken` de asserção se não tiver um ponteiro válido para um token.

A [classe CAutoRevertImpersonation](../../atl/reference/cautorevertimpersonation-class.md) pode ser usada para reverter automaticamente tokens de acesso representados.

##  <a name="impersonateloggedonuser"></a>  CAccessToken::ImpersonateLoggedOnUser

Chame esse método para permitir que o thread de chamada represente o contexto de segurança de um usuário conectado.

```
bool ImpersonateLoggedOnUser() const throw(...);
```

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

> [!IMPORTANT]
>  Se uma chamada para uma função de representação falhar por algum motivo, o cliente não será representado e a solicitação do cliente será feita no contexto de segurança do processo do qual a chamada foi feita. Se o processo estiver sendo executado como uma conta altamente privilegiada ou como um membro de um grupo administrativo, o usuário poderá executar ações que, de outra forma, não teriam de ser permitidas. Portanto, o valor de retorno para essa função sempre deve ser confirmado.

##  <a name="istokenrestricted"></a>  CAccessToken::IsTokenRestricted

Chame esse método para testar se o `CAccessToken` objeto contém uma lista de SIDs restritos.

```
bool IsTokenRestricted() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o objeto contiver uma lista de SIDs de restrição, FALSE se não houver nenhum Sid restrito ou se o método falhar.

##  <a name="loaduserprofile"></a>  CAccessToken::LoadUserProfile

Chame esse método para carregar o perfil do usuário associado `CAccessToken` ao objeto.

```
bool LoadUserProfile() throw(...);
```

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Em compilações de depuração, ocorrerá um erro de `CAccessToken` asserção se o não contiver um token válido ou se já existir um perfil de usuário.

##  <a name="logonuser"></a>  CAccessToken::LogonUser

Chame esse método para criar uma sessão de logon para o usuário associado às credenciais fornecidas.

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
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome de usuário. Esse é o nome da conta de usuário para fazer logon.

*pszDomain*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do domínio ou do servidor cujo banco de dados de conta contém a conta *pszUserName* .

*pszPassword*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica a senha de texto não criptografado para a conta de usuário especificada por *pszUserName*.

*dwLogonType*<br/>
Especifica o tipo de operação de logon a ser executada. Consulte [LogonUser](/windows/desktop/api/winbase/nf-winbase-logonusera) para obter mais detalhes.

*dwLogonProvider*<br/>
Especifica o provedor de logon. Consulte [LogonUser](/windows/desktop/api/winbase/nf-winbase-logonusera) para obter mais detalhes.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

O token de acesso resultante do logon será associado `CAccessToken`ao. Para que esse método seja bem sucedido, o `CAccessToken` objeto deve conter privilégios de SE_TCB_NAME, identificando o detentor como parte da base do computador confiável. Consulte [LogonUser](/windows/desktop/api/winbase/nf-winbase-logonusera) para obter mais informações sobre os privilégios necessários.

##  <a name="opencomclienttoken"></a>  CAccessToken::OpenCOMClientToken

Chame esse método de dentro de um servidor com que trate uma chamada de um cliente para `CAccessToken` inicializar o com o token de acesso do cliente com.

```
bool OpenCOMClientToken(
    DWORD dwDesiredAccess,
    bool bImpersonate = false,
    bool bOpenAsSelf = true) throw(...);
```

### <a name="parameters"></a>Parâmetros

*dwDesiredAccess*<br/>
Especifica uma máscara de acesso que especifica os tipos de acesso solicitados ao token de acesso. Esses tipos de acesso solicitados são comparados com a DACL do token para determinar quais acessos são concedidos ou negados.

*bImpersonate*<br/>
Se for TRUE, o thread atual representará o cliente COM de chamada se essa chamada for concluída com êxito. Se for FALSE, o token de acesso será aberto, mas o thread não terá um token de representação quando a chamada for concluída.

*bOpenAsSelf*<br/>
Indica se a verificação de acesso deve ser feita no contexto de segurança do thread que chama o método [GetThreadToken](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthread) ou no contexto de segurança do processo para o thread de chamada.

Se esse parâmetro for FALSE, a verificação de acesso será executada usando o contexto de segurança para o thread de chamada. Se o thread estiver representando um cliente, esse contexto de segurança poderá ser o de um processo de cliente. Se esse parâmetro for TRUE, a verificação de acesso será feita usando o contexto de segurança do processo para o thread de chamada.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

A [classe CAutoRevertImpersonation](../../atl/reference/cautorevertimpersonation-class.md) pode ser usada para reverter automaticamente tokens de acesso representados criados definindo o sinalizador *bImpersonate* como true.

##  <a name="opennamedpipeclienttoken"></a>  CAccessToken::OpenNamedPipeClientToken

Chame esse método de dentro de um servidor fazendo solicitações em um pipe nomeado para inicializar `CAccessToken` o com o token de acesso do cliente.

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
Especifica uma máscara de acesso que especifica os tipos de acesso solicitados ao token de acesso. Esses tipos de acesso solicitados são comparados com a DACL do token para determinar quais acessos são concedidos ou negados.

*bImpersonate*<br/>
Se for TRUE, o thread atual representará o cliente do pipe de chamada se essa chamada for concluída com êxito. Se for FALSE, o token de acesso será aberto, mas o thread não terá um token de representação quando a chamada for concluída.

*bOpenAsSelf*<br/>
Indica se a verificação de acesso deve ser feita no contexto de segurança do thread que chama o método [GetThreadToken](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthread) ou no contexto de segurança do processo para o thread de chamada.

Se esse parâmetro for FALSE, a verificação de acesso será executada usando o contexto de segurança para o thread de chamada. Se o thread estiver representando um cliente, esse contexto de segurança poderá ser o de um processo de cliente. Se esse parâmetro for TRUE, a verificação de acesso será feita usando o contexto de segurança do processo para o thread de chamada.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

A [classe CAutoRevertImpersonation](../../atl/reference/cautorevertimpersonation-class.md) pode ser usada para reverter automaticamente tokens de acesso representados criados definindo o sinalizador *bImpersonate* como true.

##  <a name="openrpcclienttoken"></a>  CAccessToken::OpenRPCClientToken

Chame esse método de dentro de um servidor que manipula uma chamada de um cliente RPC para `CAccessToken` inicializar o com o token de acesso do cliente.

```
bool OpenRPCClientToken(
    RPC_BINDING_HANDLE BindingHandle,
    DWORD dwDesiredAccess,
    bool bImpersonate = false,
    bool bOpenAsSelf = true) throw(...);
```

### <a name="parameters"></a>Parâmetros

*BindingHandle*<br/>
Identificador de associação no servidor que representa uma associação a um cliente.

*dwDesiredAccess*<br/>
Especifica uma máscara de acesso que especifica os tipos de acesso solicitados ao token de acesso. Esses tipos de acesso solicitados são comparados com a DACL do token para determinar quais acessos são concedidos ou negados.

*bImpersonate*<br/>
Se for TRUE, o thread atual representará o cliente RPC de chamada se essa chamada for concluída com êxito. Se for FALSE, o token de acesso será aberto, mas o thread não terá um token de representação quando a chamada for concluída.

*bOpenAsSelf*<br/>
Indica se a verificação de acesso deve ser feita no contexto de segurança do thread que chama o método [GetThreadToken](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthread) ou no contexto de segurança do processo para o thread de chamada.

Se esse parâmetro for FALSE, a verificação de acesso será executada usando o contexto de segurança para o thread de chamada. Se o thread estiver representando um cliente, esse contexto de segurança poderá ser o de um processo de cliente. Se esse parâmetro for TRUE, a verificação de acesso será feita usando o contexto de segurança do processo para o thread de chamada.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

A [classe CAutoRevertImpersonation](../../atl/reference/cautorevertimpersonation-class.md) pode ser usada para reverter automaticamente tokens de acesso representados criados definindo o sinalizador *bImpersonate* como true.

##  <a name="openthreadtoken"></a>  CAccessToken::OpenThreadToken

Chame esse método para definir o nível de representação e, em `CAccessToken` seguida, inicialize o com o token do thread fornecido.

```
bool OpenThreadToken(
    DWORD dwDesiredAccess,
    bool bImpersonate = false,
    bool bOpenAsSelf = true,
    SECURITY_IMPERSONATION_LEVEL sil = SecurityImpersonation) throw(...);
```

### <a name="parameters"></a>Parâmetros

*dwDesiredAccess*<br/>
Especifica uma máscara de acesso que especifica os tipos de acesso solicitados ao token de acesso. Esses tipos de acesso solicitados são comparados com a DACL do token para determinar quais acessos são concedidos ou negados.

*bImpersonate*<br/>
Se for TRUE, o thread será deixado no nível de representação solicitado depois que esse método for concluído. Se for FALSE, o thread será revertido para seu nível de representação original.

*bOpenAsSelf*<br/>
Indica se a verificação de acesso deve ser feita no contexto de segurança do thread que chama o método [GetThreadToken](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthread) ou no contexto de segurança do processo para o thread de chamada.

Se esse parâmetro for FALSE, a verificação de acesso será executada usando o contexto de segurança para o thread de chamada. Se o thread estiver representando um cliente, esse contexto de segurança poderá ser o de um processo de cliente. Se esse parâmetro for TRUE, a verificação de acesso será feita usando o contexto de segurança do processo para o thread de chamada.

*sil*<br/>
Especifica um tipo enumerado [SECURITY_IMPERSONATION_LEVEL](/windows/desktop/api/winnt/ne-winnt-security_impersonation_level) que fornece o nível de representação do token.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

`OpenThreadToken`é semelhante a [CAccessToken:: GetThreadToken](#getthreadtoken), mas define o nível de representação antes de `CAccessToken` inicializar o do token de acesso do thread.

A [classe CAutoRevertImpersonation](../../atl/reference/cautorevertimpersonation-class.md) pode ser usada para reverter automaticamente tokens de acesso representados criados definindo o sinalizador *bImpersonate* como true.

##  <a name="privilegecheck"></a>  CAccessToken::PrivilegeCheck

Chame esse método para determinar se um conjunto especificado de privilégios está habilitado no `CAccessToken` objeto.

```
bool PrivilegeCheck(
    PPRIVILEGE_SET RequiredPrivileges,
    bool* pbResult) const throw();
```

### <a name="parameters"></a>Parâmetros

*RequiredPrivileges*<br/>
Ponteiro para uma estrutura [PRIVILEGE_SET](/windows/desktop/api/winnt/ns-winnt-privilege_set) .

*pbResult*<br/>
Ponteiro para um valor que o método define para indicar se algum ou todos os privilégios especificados estão habilitados no `CAccessToken` objeto.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Quando `PrivilegeCheck` retorna, o `Attributes` membro de cada estrutura [LUID_AND_ATTRIBUTES](/windows/desktop/api/winnt/ns-winnt-luid_and_attributes) é definido como SE_PRIVILEGE_USED_FOR_ACCESS se o privilégio correspondente está habilitado. Esse método chama a função Win32 [PrivilegeCheck](/windows/desktop/api/securitybaseapi/nf-securitybaseapi-privilegecheck) .

##  <a name="revert"></a>  CAccessToken::Revert

Chame esse método para impedir que um thread use um token de representação.

```
bool Revert(HANDLE hThread = NULL) const throw();
```

### <a name="parameters"></a>Parâmetros

*hThread*<br/>
Manipule o thread para reverter a representação. Se *hThread* for NULL, o thread atual será assumido.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

A reversão dos tokens de representação pode ser executada automaticamente com a [classe CAutoRevertImpersonation](../../atl/reference/cautorevertimpersonation-class.md).

##  <a name="setdefaultdacl"></a>  CAccessToken::SetDefaultDacl

Chame esse método para definir a DACL padrão do `CAccessToken` objeto.

```
bool SetDefaultDacl(const CDacl& rDacl) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rDacl*<br/>
As novas informações de [classe CDacl](../../atl/reference/cdacl-class.md) padrão.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

A DACL padrão é a DACL usada por padrão quando novos objetos são criados com esse token de acesso em vigor.

##  <a name="setowner"></a>  CAccessToken::SetOwner

Chame esse método para definir o proprietário do `CAccessToken` objeto.

```
bool SetOwner(const CSid& rSid) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
O objeto da [classe CSid](../../atl/reference/csid-class.md) que contém as informações do proprietário.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

O proprietário é o proprietário padrão usado para novos objetos criados enquanto esse token de acesso está em vigor.

##  <a name="setprimarygroup"></a>  CAccessToken::SetPrimaryGroup

Chame esse método para definir o grupo primário do `CAccessToken` objeto.

```
bool SetPrimaryGroup(const CSid& rSid) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
O objeto da [classe CSid](../../atl/reference/csid-class.md) que contém as informações do grupo primário.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

O grupo primário é o grupo padrão para novos objetos criados enquanto esse token de acesso está em vigor.

## <a name="see-also"></a>Consulte também

[Exemplo de ATLSecurity](../../overview/visual-cpp-samples.md)<br/>
[Tokens de acesso](/windows/desktop/SecAuthZ/access-tokens)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
