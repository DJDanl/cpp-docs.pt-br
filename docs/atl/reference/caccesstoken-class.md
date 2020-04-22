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
ms.openlocfilehash: f7a2ee2f9d633c1ed743621eec5b2f7cc04c0e0b
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81748832"
---
# <a name="caccesstoken-class"></a>Classe CAccessToken

Esta aula é um invólucro para um token de acesso.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

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
|[CAccessToken::Anexo](#attach)|Chame este método para tomar posse da alça de token de acesso dada.|
|[CAccessToken::CheckTokenMembership](#checktokenmembership)|Chame este método para determinar se um SID `CAccessToken` especificado está habilitado no objeto.|
|[CAccessToken::Criar personificaçãoToken](#createimpersonationtoken)|Chame este método para criar um novo token de acesso de representação.|
|[CAccessToken::CreatePrimaryToken](#createprimarytoken)|Chame este método para criar um novo token primário.|
|[CAccessToken::CreateProcessAsUser](#createprocessasuser)|Chame esse método para criar um novo processo em execução no contexto de segurança do usuário representado pelo `CAccessToken` objeto.|
|[CAccessToken::CreateRestrictedToken](#createrestrictedtoken)|Chame este método para criar `CAccessToken` um objeto novo e restrito.|
|[CAccessToken::Detach](#detach)|Chame este método para revogar a propriedade do token de acesso.|
|[CAccessToken::DisablePrivilege](#disableprivilege)|Chame este método para desativar `CAccessToken` um privilégio no objeto.|
|[CAccessToken::DisablePrivileges](#disableprivileges)|Chame este método para desativar um ou `CAccessToken` mais privilégios no objeto.|
|[CAccessToken::Habilitarprivilégio](#enableprivilege)|Chame este método para habilitar um privilégio no `CAccessToken` objeto.|
|[CAccessToken::Habilitarprivilégios](#enableprivileges)|Chame este método para ativar um `CAccessToken` ou mais privilégios no objeto.|
|[CAccessToken::GetDefaultDacl](#getdefaultdacl)|Chame este método `CAccessToken` para retornar o DACL padrão do objeto.|
|[CAccessToken::GetEffectiveToken](#geteffectivetoken)|Chame este método `CAccessToken` para obter o objeto igual ao token de acesso em vigor para o segmento atual.|
|[CAccessToken::GetGroups](#getgroups)|Chame este método `CAccessToken` para retornar os grupos de token do objeto.|
|[CAccessToken::GetHandle](#gethandle)|Chame este método para recuperar uma alça para o token de acesso.|
|[CAccessToken::GetImpersonationLevel](#getimpersonationlevel)|Chame este método para obter o nível de personificação a partir do token de acesso.|
|[CAccessToken::GetLogonSessionId](#getlogonsessionid)|Chame este método para obter o ID `CAccessToken` da sessão de logon associado ao objeto.|
|[CAccessToken::GetLogonSid](#getlogonsid)|Chame este método para obter o `CAccessToken` LOGON SID associado ao objeto.|
|[CAccessToken::GetOwner](#getowner)|Chame este método para que `CAccessToken` o proprietário seja associado ao objeto.|
|[CAccessToken::GetPrimaryGroup](#getprimarygroup)|Chame este método para obter o `CAccessToken` grupo principal associado ao objeto.|
|[CAccessToken::GetPrivileges](#getprivileges)|Chame este método para obter os `CAccessToken` privilégios associados ao objeto.|
|[CAccessToken::GetProcessToken](#getprocesstoken)|Chame este método para `CAccessToken` inicializar o com o token de acesso do processo dado.|
|[CAccessToken::GetProfile](#getprofile)|Chame este método para obter a alça apontando `CAccessToken` para o perfil do usuário associado ao objeto.|
|[CAccessToken::GetSource](#getsource)|Chame este método para obter `CAccessToken` a fonte do objeto.|
|[CAccessToken::GetStatistics](#getstatistics)|Ligue para este método para `CAccessToken` obter informações associadas ao objeto.|
|[CAccessToken::GetTerminalServicesSessionId](#getterminalservicessessionid)|Chame este método para obter o ID `CAccessToken` de sessão de serviços de terminal associado ao objeto.|
|[CAccessToken::GetThreadToken](#getthreadtoken)|Chame este método para `CAccessToken` inicializar o com o token do segmento dado.|
|[CAccessToken::GetTokenId](#gettokenid)|Chame este método para obter o ID de token associado ao `CAccessToken` objeto.|
|[CAccessToken::GetType](#gettype)|Chame este método para obter o `CAccessToken` tipo de token do objeto.|
|[CAccessToken::GetUser](#getuser)|Chame este método para identificar `CAccessToken` o usuário associado ao objeto.|
|[CAccessToken::HKeyCurrentUser](#hkeycurrentuser)|Chame este método para obter a alça apontando `CAccessToken` para o perfil do usuário associado ao objeto.|
|[CAccessToken::Personificação](#impersonate)|Chame este método para atribuir `CAccessToken` uma representação a um segmento.|
|[CAccessToken::personificação eLoggedOnUser](#impersonateloggedonuser)|Chame esse método para permitir que o segmento de chamada se impersonatifemente o contexto de segurança de um usuário conectado.|
|[CAccessToken::IsTokenRestricted](#istokenrestricted)|Chame este método para `CAccessToken` testar se o objeto contém uma lista de SIDs restritos.|
|[CAccessToken::LoadUserProfile](#loaduserprofile)|Chame este método para carregar o `CAccessToken` perfil do usuário associado ao objeto.|
|[CAccessToken::LogonUser](#logonuser)|Chame este método para criar uma sessão de logon para o usuário associado às credenciais dadas.|
|[CAccessToken::OpenCOMClientToken](#opencomclienttoken)|Chame esse método de dentro de um servidor COM manipulando uma chamada de um cliente para inicializar o `CAccessToken` com o token de acesso do cliente COM.|
|[CAccessToken:OpenNamedPipeClientToken](#opennamedpipeclienttoken)|Chame esse método de dentro de um servidor que `CAccessToken` recebe solicitações sobre um tubo nomeado para inicializar o com o token de acesso do cliente.|
|[CAccessToken::OpenRPCClientToken](#openrpcclienttoken)|Chame esse método de dentro de um servidor que manuseie uma chamada de um cliente RPC para inicializar o `CAccessToken` com o token de acesso do cliente.|
|[CAccessToken::OpenThreadToken](#openthreadtoken)|Chame este método para definir o nível de `CAccessToken` representação e, em seguida, inicializar o com o token a partir do segmento dado.|
|[CAccessToken::PrivilegeCheck](#privilegecheck)|Chame este método para determinar se um conjunto especificado `CAccessToken` de privilégios está ativado no objeto.|
|[CAccessToken::Reverter](#revert)|Chame este método para parar um segmento que está usando um token de representação.|
|[CAccessToken::SetDefaultDacl](#setdefaultdacl)|Chame este método para definir o `CAccessToken` DACL padrão do objeto.|
|[CAccessToken::SetOwner](#setowner)|Chame este método para definir `CAccessToken` o proprietário do objeto.|
|[CAccessToken::SetPrimaryGroup](#setprimarygroup)|Chame este método para definir `CAccessToken` o grupo principal do objeto.|

## <a name="remarks"></a>Comentários

Um [token de acesso](/windows/win32/SecAuthZ/access-tokens) é um objeto que descreve o contexto de segurança de um processo ou segmento e é alocado para cada usuário conectado em um sistema Windows.

Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [Control de acesso](/windows/win32/SecAuthZ/access-control) no Windows SDK.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity.h

## <a name="caccesstokenattach"></a><a name="attach"></a>CAccessToken::Anexo

Chame este método para tomar posse da alça de token de acesso dada.

```cpp
void Attach(HANDLE hToken) throw();
```

### <a name="parameters"></a>Parâmetros

*hToken*<br/>
Uma alça para o token de acesso.

### <a name="remarks"></a>Comentários

Nas compilações de depuração, um `CAccessToken` erro de afirmação ocorrerá se o objeto já tiver a propriedade de um token de acesso.

## <a name="caccesstokencaccesstoken"></a><a name="dtor"></a>CAccessToken::~CAccessToken

O destruidor.

```
virtual ~CAccessToken() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

## <a name="caccesstokenchecktokenmembership"></a><a name="checktokenmembership"></a>CAccessToken::CheckTokenMembership

Chame este método para determinar se um SID `CAccessToken` especificado está habilitado no objeto.

```
bool CheckTokenMembership(
    const CSid& rSid,
    bool* pbIsMember) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
Referência a um objeto [Classe CSid.](../../atl/reference/csid-class.md)

*pbIsMember*<br/>
Ponteiro para uma variável que recebe os resultados do cheque.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

O `CheckTokenMembership` método verifica a presença do SID nos SIDs do usuário e do grupo do token de acesso. Se o SID estiver presente e tiver o atributo *SE_GROUP_ENABLED, o pbIsMember* será definido como TRUE; caso contrário, é definido como FALSO.

Nas compilações de depuração, um erro de afirmação ocorrerá se *o pbIsMember* não for um ponteiro válido.

> [!NOTE]
> O `CAccessToken` objeto deve ser um símbolo de representação e não um token primário.

## <a name="caccesstokencreateimpersonationtoken"></a><a name="createimpersonationtoken"></a>CAccessToken::Criar personificaçãoToken

Chame este método para criar um token de acesso de representação.

```
bool CreateImpersonationToken(
    CAccessToken* pImp,
    SECURITY_IMPERSONATION_LEVEL sil = SecurityImpersonation) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pImp*<br/>
Ponteiro para `CAccessToken` o novo objeto.

*Sil*<br/>
Especifica um [SECURITY_IMPERSONATION_LEVEL](/windows/win32/api/winnt/ne-winnt-security_impersonation_level) tipo enumerado que fornece o nível de representação do novo token.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

`CreateImpersonationToken`chama [DuplicateToken](/windows/win32/api/securitybaseapi/nf-securitybaseapi-duplicatetoken) para criar um novo token de representação.

## <a name="caccesstokencreateprimarytoken"></a><a name="createprimarytoken"></a>CAccessToken::CreatePrimaryToken

Chame este método para criar um novo token primário.

```
bool CreatePrimaryToken(
    CAccessToken* pPri,
    DWORD dwDesiredAccess = MAXIMUM_ALLOWED,
    const CSecurityAttributes* pTokenAttributes = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pPri*<br/>
Ponteiro para `CAccessToken` o novo objeto.

*dwDesiredAccess*<br/>
Especifica os direitos de acesso solicitados para o novo token. O padrão, MAXIMUM_ALLOWED, solicita todos os direitos de acesso válidos para o chamador. Consulte [Direitos de Acesso e Máscaras de Acesso](/windows/win32/SecAuthZ/access-rights-and-access-masks) para obter mais informações sobre direitos de acesso.

*pTokenAttributes*<br/>
Ponteiro para uma estrutura [de SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\)) que especifica um descritor de segurança para o novo token e determina se os processos filho podem herdar o token. Se *pTokenAttributes* for NULL, o token recebe um descritor de segurança padrão e o cabo não pode ser herdado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

`CreatePrimaryToken`chama [DuplicateTokenEx](/windows/win32/api/securitybaseapi/nf-securitybaseapi-duplicatetokenex) para criar um novo token principal.

## <a name="caccesstokencreateprocessasuser"></a><a name="createprocessasuser"></a>CAccessToken::CreateProcessAsUser

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

*pNome do aplicativo*<br/>
Pointer para uma seqüência de terminadas nula que especifica o módulo a ser executado. Este parâmetro pode não ser NULO.

*pCommandLine*<br/>
Ponteiro para uma seqüência de terminadas nula que especifica a linha de comando a ser executada.

*pProcessInformation*<br/>
Ponteiro para uma [estrutura PROCESS_INFORMATION](/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_information) que recebe informações de identificação sobre o novo processo.

*pStartupInfo*<br/>
Ponteiro para uma estrutura [STARTUPINFO](/windows/win32/api/processthreadsapi/ns-processthreadsapi-startupinfow) que especifica como a janela principal para o novo processo deve aparecer.

*Dwcreationflags*<br/>
Especifica bandeiras adicionais que controlam a classe prioritária e a criação do processo. Consulte a função Win32 [CreateProcessAsUser](/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessasuserw) para obter uma lista de sinalizadores.

*bLoadProfile*<br/>
Se TRUE, o perfil do usuário estiver carregado com [LoadUserProfile](/windows/win32/api/userenv/nf-userenv-loaduserprofilew).

*pProcessAttributes*<br/>
Ponteiro para uma estrutura [de SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\)) que especifica um descritor de segurança para o novo processo e determina se os processos filho podem herdar a alça retornada. Se *pProcessAttributes* for NULL, o processo obtém um descritor de segurança padrão e a alça não pode ser herdada.

*pThreadAttributes*<br/>
Ponteiro para uma estrutura [de SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\)) que especifica um descritor de segurança para o novo segmento e determina se os processos filho podem herdar a alça retornada. Se *pThreadAttributes* for NULL, o segmento recebe um descritor de segurança padrão e a alça não pode ser herdada.

*bHer*<br/>
Indica se o novo processo herda do processo de chamada. Se TRUE, cada alça aberta herdada no processo de chamada é herdada pelo novo processo. As alças herdadas têm o mesmo valor e privilégios de acesso que as alças originais.

*pCurrentDirectory*<br/>
Pointer para uma seqüência de seqüência de terminadas nula que especifica a unidade atual e o diretório para o novo processo. A seqüência deve ser um caminho completo que inclui uma letra de unidade. Se esse parâmetro for NULO, o novo processo terá a mesma unidade e diretório atual que o processo de chamada.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

`CreateProcessAsUser`usa `CreateProcessAsUser` a função Win32 para criar um novo processo que é `CAccessToken` executado no contexto de segurança do usuário representado pelo objeto. Consulte a descrição da função [CreateProcessAsUser](/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessasuserw) para uma discussão completa dos parâmetros necessários.

Para que este método `CAccessToken` tenha sucesso, o objeto deve conter privilégios AtribuiçãoPrimaryToken (a menos que seja um token restrito) e privilégios IncreaseQuota.

## <a name="caccesstokencreaterestrictedtoken"></a><a name="createrestrictedtoken"></a>CAccessToken::CreateRestrictedToken

Chame este método para criar `CAccessToken` um objeto novo e restrito.

```
bool CreateRestrictedToken(
    CAccessToken* pRestrictedToken,
    const CTokenGroups& SidsToDisable,
    const CTokenGroups& SidsToRestrict,
    const CTokenPrivileges& PrivilegesToDelete = CTokenPrivileges()) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pRestrictedToken*<br/>
O novo `CAccessToken` objeto restrito.

*SidsToDisable*<br/>
Um `CTokenGroups` objeto que especifica os SIDs somente negados.

*SidsToRestrict*<br/>
Um `CTokenGroups` objeto que especifica os SIDs de restrição.

*PrivilégiosPara excluir*<br/>
Um `CTokenPrivileges` objeto que especifica os privilégios a serem excluídos no token restrito. O padrão cria um objeto vazio.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

`CreateRestrictedToken`usa a função [CreateRestrictedToken](/windows/win32/api/securitybaseapi/nf-securitybaseapi-createrestrictedtoken) Win32 `CAccessToken` para criar um novo objeto, com restrições.

> [!IMPORTANT]
> Ao `CreateRestrictedToken`usar, certifique-se de que o token existente é válido (e não inserido pelo usuário) e *Os SidsToDisable* e *PrivilegesToDelete* são válidos (e não inseridos pelo usuário). Se o método retornar FALSO, negue a funcionalidade.

## <a name="caccesstokendetach"></a><a name="detach"></a>CAccessToken::Detach

Chame este método para revogar a propriedade do token de acesso.

```
HANDLE Detach() throw();
```

### <a name="return-value"></a>Valor retornado

Devolve a alça `CAccessToken` ao que foi desapegado.

### <a name="remarks"></a>Comentários

Este método revoga `CAccessToken`a propriedade do token de acesso.

## <a name="caccesstokendisableprivilege"></a><a name="disableprivilege"></a>CAccessToken::DisablePrivilege

Chame este método para desativar `CAccessToken` um privilégio no objeto.

```
bool DisablePrivilege(
    LPCTSTR pszPrivilege,
    CTokenPrivileges* pPreviousState = NULL) throw(...);
```

### <a name="parameters"></a>Parâmetros

*pszPrivilege*<br/>
Ponteiro para uma seqüência contendo o `CAccessToken` privilégio de desativar no objeto.

*pPreviousState*<br/>
Ponteiro para `CTokenPrivileges` um objeto que conterá o estado anterior dos privilégios.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="caccesstokendisableprivileges"></a><a name="disableprivileges"></a>CAccessToken::DisablePrivileges

Chame este método para desativar um ou `CAccessToken` mais privilégios no objeto.

```
bool DisablePrivileges(
    const CAtlArray<LPCTSTR>& rPrivileges,
    CTokenPrivileges* pPreviousState = NULL) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rPrivileges*<br/>
Ponteiro para uma matriz de strings contendo os `CAccessToken` privilégios para desativar no objeto.

*pPreviousState*<br/>
Ponteiro para `CTokenPrivileges` um objeto que conterá o estado anterior dos privilégios.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="caccesstokenenableprivilege"></a><a name="enableprivilege"></a>CAccessToken::Habilitarprivilégio

Chame este método para habilitar um privilégio no `CAccessToken` objeto.

```
bool EnablePrivilege(
    LPCTSTR pszPrivilege,
    CTokenPrivileges* pPreviousState = NULL) throw(...);
```

### <a name="parameters"></a>Parâmetros

*pszPrivilege*<br/>
Ponteiro para uma seqüência contendo `CAccessToken` o privilégio de habilitar no objeto.

*pPreviousState*<br/>
Ponteiro para `CTokenPrivileges` um objeto que conterá o estado anterior dos privilégios.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="caccesstokenenableprivileges"></a><a name="enableprivileges"></a>CAccessToken::Habilitarprivilégios

Chame este método para ativar um `CAccessToken` ou mais privilégios no objeto.

```
bool EnablePrivileges(
    const CAtlArray<LPCTSTR>& rPrivileges,
    CTokenPrivileges* pPreviousState = NULL) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rPrivileges*<br/>
Ponteiro para uma matriz de strings contendo os `CAccessToken` privilégios para habilitar no objeto.

*pPreviousState*<br/>
Ponteiro para `CTokenPrivileges` um objeto que conterá o estado anterior dos privilégios.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="caccesstokengetdefaultdacl"></a><a name="getdefaultdacl"></a>CAccessToken::GetDefaultDacl

Chame este método `CAccessToken` para retornar o DACL padrão do objeto.

```
bool GetDefaultDacl(CDacl* pDacl) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pDacl*<br/>
Ponteiro para o objeto [Classe CDacl](../../atl/reference/cdacl-class.md) que receberá o `CAccessToken` DACL padrão do objeto.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o DACL padrão tiver sido recuperado, FALSO de outra forma.

## <a name="caccesstokengeteffectivetoken"></a><a name="geteffectivetoken"></a>CAccessToken::GetEffectiveToken

Chame este método `CAccessToken` para obter o objeto igual ao token de acesso em vigor para o segmento atual.

```
bool GetEffectiveToken(DWORD dwDesiredAccess) throw();
```

### <a name="parameters"></a>Parâmetros

*dwDesiredAccess*<br/>
Especifica uma máscara de acesso que especifica os tipos de acesso solicitados ao token de acesso. Esses tipos de acesso solicitados são comparados com o DACL do token para determinar quais acessos são concedidos ou negados.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="caccesstokengetgroups"></a><a name="getgroups"></a>CAccessToken::GetGroups

Chame este método `CAccessToken` para retornar os grupos de token do objeto.

```
bool GetGroups(CTokenGroups* pGroups) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pGroups*<br/>
Ponteiro para o objeto [CTokenGroups Class](../../atl/reference/ctokengroups-class.md) que receberá as informações do grupo.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="caccesstokengethandle"></a><a name="gethandle"></a>CAccessToken::GetHandle

Chame este método para recuperar uma alça para o token de acesso.

```
HANDLE GetHandle() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna uma alça `CAccessToken` para o token de acesso do objeto.

## <a name="caccesstokengetimpersonationlevel"></a><a name="getimpersonationlevel"></a>CAccessToken::GetImpersonationLevel

Chame este método para obter o nível de personificação a partir do token de acesso.

```
bool GetImpersonationLevel(
    SECURITY_IMPERSONATION_LEVEL* pImpersonationLevel) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pSiononLevel*<br/>
Ponteiro para [um](/windows/win32/api/winnt/ne-winnt-security_impersonation_level) SECURITY_IMPERSONATION_LEVEL tipo de enumeração que receberá as informações de nível de representação.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="caccesstokengetlogonsessionid"></a><a name="getlogonsessionid"></a>CAccessToken::GetLogonSessionId

Chame este método para obter o ID `CAccessToken` da sessão de logon associado ao objeto.

```
bool GetLogonSessionId(LUID* pluid) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pluid*<br/>
Ponteiro para um [LUID](/windows/win32/api/winnt/ns-winnt-luid) que receberá o ID da sessão de logon.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Nas compilações de depuração, um erro de afirmação ocorrerá se *pluid* for um valor inválido.

## <a name="caccesstokengetlogonsid"></a><a name="getlogonsid"></a>CAccessToken::GetLogonSid

Chame este método para obter o `CAccessToken` LOGON SID associado ao objeto.

```
bool GetLogonSid(CSid* pSid) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*Psid*<br/>
Ponteiro para um objeto [Classe CSid.](../../atl/reference/csid-class.md)

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Nas compilações de depuração, um erro de afirmação ocorrerá se *o pSid* for um valor inválido.

## <a name="caccesstokengetowner"></a><a name="getowner"></a>CAccessToken::GetOwner

Chame este método para que `CAccessToken` o proprietário seja associado ao objeto.

```
bool GetOwner(CSid* pSid) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*Psid*<br/>
Ponteiro para um objeto [Classe CSid.](../../atl/reference/csid-class.md)

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

O proprietário é definido por padrão em qualquer objeto criado enquanto este token de acesso estiver em vigor.

## <a name="caccesstokengetprimarygroup"></a><a name="getprimarygroup"></a>CAccessToken::GetPrimaryGroup

Chame este método para obter o `CAccessToken` grupo principal associado ao objeto.

```
bool GetPrimaryGroup(CSid* pSid) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*Psid*<br/>
Ponteiro para um objeto [Classe CSid.](../../atl/reference/csid-class.md)

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

O grupo é definido por padrão em qualquer objeto criado enquanto este token de acesso estiver em vigor.

## <a name="caccesstokengetprivileges"></a><a name="getprivileges"></a>CAccessToken::GetPrivileges

Chame este método para obter os `CAccessToken` privilégios associados ao objeto.

```
bool GetPrivileges(CTokenPrivileges* pPrivileges) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pPrivileges*<br/>
Pointer para um objeto [CTokenPrivileges Class](../../atl/reference/ctokenprivileges-class.md) que receberá os privilégios.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="caccesstokengetprocesstoken"></a><a name="getprocesstoken"></a>CAccessToken::GetProcessToken

Chame este método para `CAccessToken` inicializar o com o token de acesso do processo dado.

```
bool GetProcessToken(DWORD dwDesiredAccess, HANDLE hProcess = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*dwDesiredAccess*<br/>
Especifica uma máscara de acesso que especifica os tipos de acesso solicitados ao token de acesso. Esses tipos de acesso solicitados são comparados com o DACL do token para determinar quais acessos são concedidos ou negados.

*Hprocess*<br/>
Manuseie o processo cujo token de acesso está aberto. Se o valor padrão do NULL for usado, o processo atual será usado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Chama a função [OpenProcessToken](/windows/win32/api/processthreadsapi/nf-processthreadsapi-openprocesstoken) Win32.

## <a name="caccesstokengetprofile"></a><a name="getprofile"></a>CAccessToken::GetProfile

Chame este método para obter a alça apontando `CAccessToken` para o perfil do usuário associado ao objeto.

```
HANDLE GetProfile() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna uma alça apontando para o perfil do usuário ou NULL se não houver nenhum perfil.

## <a name="caccesstokengetsource"></a><a name="getsource"></a>CAccessToken::GetSource

Chame este método para obter `CAccessToken` a fonte do objeto.

```
bool GetSource(TOKEN_SOURCE* pSource) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*Psource*<br/>
Ponteiro para uma estrutura [TOKEN_SOURCE.](/windows/win32/api/winnt/ns-winnt-token_source)

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="caccesstokengetstatistics"></a><a name="getstatistics"></a>CAccessToken::GetStatistics

Ligue para este método para `CAccessToken` obter informações associadas ao objeto.

```
bool GetStatistics(TOKEN_STATISTICS* pStatistics) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pEstatísticas*<br/>
Ponteiro para uma estrutura [TOKEN_STATISTICS.](/windows/win32/api/winnt/ns-winnt-token_statistics)

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="caccesstokengetterminalservicessessionid"></a><a name="getterminalservicessessionid"></a>CAccessToken::GetTerminalServicesSessionId

Chame este método para obter o ID `CAccessToken` de sessão de serviços de terminal associado ao objeto.

```
bool GetTerminalServicesSessionId(DWORD* pdwSessionId) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pdwSessionId*<br/>
O ID da sessão de serviços do terminal.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="caccesstokengetthreadtoken"></a><a name="getthreadtoken"></a>CAccessToken::GetThreadToken

Chame este método para `CAccessToken` inicializar o com o token do segmento dado.

```
bool GetThreadToken(
    DWORD dwDesiredAccess,
    HANDLE hThread = NULL,
    bool bOpenAsSelf = true) throw();
```

### <a name="parameters"></a>Parâmetros

*dwDesiredAccess*<br/>
Especifica uma máscara de acesso que especifica os tipos de acesso solicitados ao token de acesso. Esses tipos de acesso solicitados são comparados com o DACL do token para determinar quais acessos são concedidos ou negados.

*Hthread*<br/>
Manuseie o segmento cujo token de acesso está aberto.

*bOpenAsSelf*<br/>
Indica se a verificação de acesso deve ser feita `GetThreadToken` contra o contexto de segurança do segmento que chama o método ou contra o contexto de segurança do processo para o segmento de chamada.

Se este parâmetro for FALSO, a verificação de acesso será realizada usando o contexto de segurança do segmento de chamada. Se o segmento está se passando por um cliente, esse contexto de segurança pode ser o de um processo de cliente. Se esse parâmetro for TRUE, a verificação de acesso será feita usando o contexto de segurança do processo para o segmento de chamada.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="caccesstokengettokenid"></a><a name="gettokenid"></a>CAccessToken::GetTokenId

Chame este método para obter o ID de token associado ao `CAccessToken` objeto.

```
bool GetTokenId(LUID* pluid) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*pluid*<br/>
Ponteiro para um [LUID](/windows/win32/api/winnt/ns-winnt-luid) que receberá o ID de token.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="caccesstokengettype"></a><a name="gettype"></a>CAccessToken::GetType

Chame este método para obter o `CAccessToken` tipo de token do objeto.

```
bool GetType(TOKEN_TYPE* pType) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*Ptype*<br/>
Endereço da [variável TOKEN_TYPE](/windows/win32/api/winnt/ne-winnt-token_type) que, no sucesso, recebe o tipo de token.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

O TOKEN_TYPE tipo de enumeração contém valores que diferenciam entre um token primário e um token de representação.

## <a name="caccesstokengetuser"></a><a name="getuser"></a>CAccessToken::GetUser

Chame este método para identificar `CAccessToken` o usuário associado ao objeto.

```
bool GetUser(CSid* pSid) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*Psid*<br/>
Ponteiro para um objeto [Classe CSid.](../../atl/reference/csid-class.md)

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="caccesstokenhkeycurrentuser"></a><a name="hkeycurrentuser"></a>CAccessToken::HKeyCurrentUser

Chame este método para obter a alça apontando `CAccessToken` para o perfil do usuário associado ao objeto.

```
HKEY HKeyCurrentUser() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna uma alça apontando para o perfil do usuário ou NULL se não houver nenhum perfil.

## <a name="caccesstokenimpersonate"></a><a name="impersonate"></a>CAccessToken::Personificação

Chame este método para atribuir `CAccessToken` uma representação a um segmento.

```
bool Impersonate(HANDLE hThread = NULL) const throw(...);
```

### <a name="parameters"></a>Parâmetros

*Hthread*<br/>
Manuseie o segmento para atribuir o token de representação. Esta alça deve ter sido aberta com direitos de acesso TOKEN_IMPERSONATE. Se *hThread* for NULL, o método faz com que o segmento pare de usar um token de representação.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Nas compilações de depuração, `CAccessToken` um erro de afirmação ocorrerá se não tiver um ponteiro válido para um token.

A [classe CAutoRevertImpersonation](../../atl/reference/cautorevertimpersonation-class.md) pode ser usada para reverter automaticamente tokens de acesso personificados.

## <a name="caccesstokenimpersonateloggedonuser"></a><a name="impersonateloggedonuser"></a>CAccessToken::personificação eLoggedOnUser

Chame esse método para permitir que o segmento de chamada se impersonatifemente o contexto de segurança de um usuário conectado.

```
bool ImpersonateLoggedOnUser() const throw(...);
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

> [!IMPORTANT]
> Se uma chamada para uma função de representação falhar por qualquer motivo, o cliente não será personificado e a solicitação do cliente é feita no contexto de segurança do processo a partir do qual a chamada foi feita. Se o processo estiver sendo executado como uma conta altamente privilegiada, ou como membro de um grupo administrativo, o usuário poderá realizar ações que ele ou ela seria desautorizado. Portanto, o valor de retorno para esta função deve ser sempre confirmado.

## <a name="caccesstokenistokenrestricted"></a><a name="istokenrestricted"></a>CAccessToken::IsTokenRestricted

Chame este método para `CAccessToken` testar se o objeto contém uma lista de SIDs restritos.

```
bool IsTokenRestricted() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o objeto contiver uma lista de SIDs restritos, FALSOs se não houver SIDs restritos ou se o método falhar.

## <a name="caccesstokenloaduserprofile"></a><a name="loaduserprofile"></a>CAccessToken::LoadUserProfile

Chame este método para carregar o `CAccessToken` perfil do usuário associado ao objeto.

```
bool LoadUserProfile() throw(...);
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Nas compilações de depuração, um `CAccessToken` erro de afirmação ocorrerá se o não contiver um token válido ou se um perfil de usuário já existir.

## <a name="caccesstokenlogonuser"></a><a name="logonuser"></a>CAccessToken::LogonUser

Chame este método para criar uma sessão de logon para o usuário associado às credenciais dadas.

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
Pointer para uma seqüência de terminadas nula que especifica o nome de usuário. Este é o nome da conta de usuário para fazer logon.

*pszDomínio*<br/>
Pointer para uma seqüência de terminação nula que especifica o nome do domínio ou servidor cujo banco de dados de conta contém a conta *pszUserName.*

*pszPassword*<br/>
Pointer para uma seqüência de terminadas nula que especifica a senha de texto claro para a conta de usuário especificada por *pszUserName*.

*dwLogonType*<br/>
Especifica o tipo de operação de logon a ser realizado. Consulte [LogonUser](/windows/win32/api/winbase/nf-winbase-logonuserw) para obter mais detalhes.

*dwLogonProvider*<br/>
Especifica o provedor de logon. Consulte [LogonUser](/windows/win32/api/winbase/nf-winbase-logonuserw) para obter mais detalhes.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

O token de acesso resultante do logon `CAccessToken`será associado ao . Para que este método `CAccessToken` tenha sucesso, o objeto deve conter privilégios SE_TCB_NAME, identificando o titular como parte da base de computador confiável. Consulte [LogonUser](/windows/win32/api/winbase/nf-winbase-logonuserw) para obter mais informações sobre os privilégios necessários.

## <a name="caccesstokenopencomclienttoken"></a><a name="opencomclienttoken"></a>CAccessToken::OpenCOMClientToken

Chame esse método de dentro de um servidor COM manipulando uma chamada de um cliente para inicializar o `CAccessToken` com o token de acesso do cliente COM.

```
bool OpenCOMClientToken(
    DWORD dwDesiredAccess,
    bool bImpersonate = false,
    bool bOpenAsSelf = true) throw(...);
```

### <a name="parameters"></a>Parâmetros

*dwDesiredAccess*<br/>
Especifica uma máscara de acesso que especifica os tipos de acesso solicitados ao token de acesso. Esses tipos de acesso solicitados são comparados com o DACL do token para determinar quais acessos são concedidos ou negados.

*bPersonificar*<br/>
Se TRUE, o segmento atual se passará pelo cliente COM chamada se essa chamada for concluída com sucesso. Se FALSE, o token de acesso será aberto, mas o segmento não terá um token de representação quando esta chamada for concluída.

*bOpenAsSelf*<br/>
Indica se a verificação de acesso deve ser feita contra o contexto de segurança do segmento que chama o método [GetThreadToken](/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentthread) ou contra o contexto de segurança do processo para o segmento de chamada.

Se este parâmetro for FALSO, a verificação de acesso será realizada usando o contexto de segurança do segmento de chamada. Se o segmento está se passando por um cliente, esse contexto de segurança pode ser o de um processo de cliente. Se esse parâmetro for TRUE, a verificação de acesso será feita usando o contexto de segurança do processo para o segmento de chamada.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

A [Classe CAutoRevertImpersonation](../../atl/reference/cautorevertimpersonation-class.md) pode ser usada para reverter automaticamente os tokens de acesso personificados criados definindo o sinalizador *bImpersonate* para TRUE.

## <a name="caccesstokenopennamedpipeclienttoken"></a><a name="opennamedpipeclienttoken"></a>CAccessToken:OpenNamedPipeClientToken

Chame esse método de dentro de um servidor que `CAccessToken` recebe solicitações sobre um tubo nomeado para inicializar o com o token de acesso do cliente.

```
bool OpenNamedPipeClientToken(
    HANDLE hPipe,
    DWORD dwDesiredAccess,
    bool bImpersonate = false,
    bool bOpenAsSelf = true) throw(...);
```

### <a name="parameters"></a>Parâmetros

*hPipe*<br/>
Manuseie um cano chamado.

*dwDesiredAccess*<br/>
Especifica uma máscara de acesso que especifica os tipos de acesso solicitados ao token de acesso. Esses tipos de acesso solicitados são comparados com o DACL do token para determinar quais acessos são concedidos ou negados.

*bPersonificar*<br/>
Se TRUE, o segmento atual se passará pelo cliente do tubo de chamada se essa chamada for concluída com sucesso. Se FALSE, o token de acesso será aberto, mas o segmento não terá um token de representação quando esta chamada for concluída.

*bOpenAsSelf*<br/>
Indica se a verificação de acesso deve ser feita contra o contexto de segurança do segmento que chama o método [GetThreadToken](/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentthread) ou contra o contexto de segurança do processo para o segmento de chamada.

Se este parâmetro for FALSO, a verificação de acesso será realizada usando o contexto de segurança do segmento de chamada. Se o segmento está se passando por um cliente, esse contexto de segurança pode ser o de um processo de cliente. Se esse parâmetro for TRUE, a verificação de acesso será feita usando o contexto de segurança do processo para o segmento de chamada.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

A [Classe CAutoRevertImpersonation](../../atl/reference/cautorevertimpersonation-class.md) pode ser usada para reverter automaticamente os tokens de acesso personificados criados definindo o sinalizador *bImpersonate* para TRUE.

## <a name="caccesstokenopenrpcclienttoken"></a><a name="openrpcclienttoken"></a>CAccessToken::OpenRPCClientToken

Chame esse método de dentro de um servidor que manuseie uma chamada de um cliente RPC para inicializar o `CAccessToken` com o token de acesso do cliente.

```
bool OpenRPCClientToken(
    RPC_BINDING_HANDLE BindingHandle,
    DWORD dwDesiredAccess,
    bool bImpersonate = false,
    bool bOpenAsSelf = true) throw(...);
```

### <a name="parameters"></a>Parâmetros

*BindingHandle*<br/>
Alça de vinculação no servidor que representa uma vinculação a um cliente.

*dwDesiredAccess*<br/>
Especifica uma máscara de acesso que especifica os tipos de acesso solicitados ao token de acesso. Esses tipos de acesso solicitados são comparados com o DACL do token para determinar quais acessos são concedidos ou negados.

*bPersonificar*<br/>
Se TRUE, o segmento atual se passará pelo cliente RPC que chama se essa chamada for concluída com sucesso. Se FALSE, o token de acesso será aberto, mas o segmento não terá um token de representação quando esta chamada for concluída.

*bOpenAsSelf*<br/>
Indica se a verificação de acesso deve ser feita contra o contexto de segurança do segmento que chama o método [GetThreadToken](/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentthread) ou contra o contexto de segurança do processo para o segmento de chamada.

Se este parâmetro for FALSO, a verificação de acesso será realizada usando o contexto de segurança do segmento de chamada. Se o segmento está se passando por um cliente, esse contexto de segurança pode ser o de um processo de cliente. Se esse parâmetro for TRUE, a verificação de acesso será feita usando o contexto de segurança do processo para o segmento de chamada.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

A [Classe CAutoRevertImpersonation](../../atl/reference/cautorevertimpersonation-class.md) pode ser usada para reverter automaticamente os tokens de acesso personificados criados definindo o sinalizador *bImpersonate* para TRUE.

## <a name="caccesstokenopenthreadtoken"></a><a name="openthreadtoken"></a>CAccessToken::OpenThreadToken

Chame este método para definir o nível de `CAccessToken` representação e, em seguida, inicializar o com o token a partir do segmento dado.

```
bool OpenThreadToken(
    DWORD dwDesiredAccess,
    bool bImpersonate = false,
    bool bOpenAsSelf = true,
    SECURITY_IMPERSONATION_LEVEL sil = SecurityImpersonation) throw(...);
```

### <a name="parameters"></a>Parâmetros

*dwDesiredAccess*<br/>
Especifica uma máscara de acesso que especifica os tipos de acesso solicitados ao token de acesso. Esses tipos de acesso solicitados são comparados com o DACL do token para determinar quais acessos são concedidos ou negados.

*bPersonificar*<br/>
Se TRUE, o segmento será deixado no nível de representação solicitado após a conclusão deste método. Se FALSE, o segmento voltará ao seu nível original de representação.

*bOpenAsSelf*<br/>
Indica se a verificação de acesso deve ser feita contra o contexto de segurança do segmento que chama o método [GetThreadToken](/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentthread) ou contra o contexto de segurança do processo para o segmento de chamada.

Se este parâmetro for FALSO, a verificação de acesso será realizada usando o contexto de segurança do segmento de chamada. Se o segmento está se passando por um cliente, esse contexto de segurança pode ser o de um processo de cliente. Se esse parâmetro for TRUE, a verificação de acesso será feita usando o contexto de segurança do processo para o segmento de chamada.

*Sil*<br/>
Especifica um [SECURITY_IMPERSONATION_LEVEL](/windows/win32/api/winnt/ne-winnt-security_impersonation_level) tipo enumerado que fornece o nível de personificação do token.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

`OpenThreadToken`é semelhante ao [CAccessToken::GetThreadToken,](#getthreadtoken)mas define o nível `CAccessToken` de personificação antes de inicializar o token de acesso do segmento.

A [Classe CAutoRevertImpersonation](../../atl/reference/cautorevertimpersonation-class.md) pode ser usada para reverter automaticamente os tokens de acesso personificados criados definindo o sinalizador *bImpersonate* para TRUE.

## <a name="caccesstokenprivilegecheck"></a><a name="privilegecheck"></a>CAccessToken::PrivilegeCheck

Chame este método para determinar se um conjunto especificado `CAccessToken` de privilégios está ativado no objeto.

```
bool PrivilegeCheck(
    PPRIVILEGE_SET RequiredPrivileges,
    bool* pbResult) const throw();
```

### <a name="parameters"></a>Parâmetros

*Privilégios obrigatórios*<br/>
Ponteiro para uma estrutura [PRIVILEGE_SET.](/windows/win32/api/winnt/ns-winnt-privilege_set)

*pbResult*<br/>
Ponteiro para um valor que o método define para indicar se algum `CAccessToken` ou todos os privilégios especificados estão habilitados no objeto.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Quando `PrivilegeCheck` retorna, `Attributes` o membro de [cada](/windows/win32/api/winnt/ns-winnt-luid_and_attributes) LUID_AND_ATTRIBUTES estrutura é definido para SE_PRIVILEGE_USED_FOR_ACCESS se o privilégio correspondente estiver habilitado. Este método chama a função [PrivilegeCheck](/windows/win32/api/securitybaseapi/nf-securitybaseapi-privilegecheck) Win32.

## <a name="caccesstokenrevert"></a><a name="revert"></a>CAccessToken::Reverter

Chame este método para impedir que um segmento use um token de representação.

```
bool Revert(HANDLE hThread = NULL) const throw();
```

### <a name="parameters"></a>Parâmetros

*Hthread*<br/>
Manuseie o fio para reverter a personificação. Se *hThread* for NULL, a linha atual será assumida.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

A reversão dos tokens de representação pode ser realizada automaticamente com a [Classe CAutoRevertImpersonation](../../atl/reference/cautorevertimpersonation-class.md).

## <a name="caccesstokensetdefaultdacl"></a><a name="setdefaultdacl"></a>CAccessToken::SetDefaultDacl

Chame este método para definir o `CAccessToken` DACL padrão do objeto.

```
bool SetDefaultDacl(const CDacl& rDacl) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rDacl*<br/>
As novas informações padrão [da Classe CDacl.](../../atl/reference/cdacl-class.md)

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

O DACL padrão é o DACL que é usado por padrão quando novos objetos são criados com este token de acesso em vigor.

## <a name="caccesstokensetowner"></a><a name="setowner"></a>CAccessToken::SetOwner

Chame este método para definir `CAccessToken` o proprietário do objeto.

```
bool SetOwner(const CSid& rSid) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
O objeto [Classe CSid](../../atl/reference/csid-class.md) contendo as informações do proprietário.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

O proprietário é o proprietário padrão que é usado para novos objetos criados enquanto este token de acesso está em vigor.

## <a name="caccesstokensetprimarygroup"></a><a name="setprimarygroup"></a>CAccessToken::SetPrimaryGroup

Chame este método para definir `CAccessToken` o grupo principal do objeto.

```
bool SetPrimaryGroup(const CSid& rSid) throw(...);
```

### <a name="parameters"></a>Parâmetros

*rSid*<br/>
O objeto [Classe CSid](../../atl/reference/csid-class.md) contendo as informações do grupo principal.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

O grupo principal é o grupo padrão para novos objetos criados enquanto esse token de acesso estiver em vigor.

## <a name="see-also"></a>Confira também

[Amostra de ATLSecurity](../../overview/visual-cpp-samples.md)<br/>
[Tokens de acesso](/windows/win32/SecAuthZ/access-tokens)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
