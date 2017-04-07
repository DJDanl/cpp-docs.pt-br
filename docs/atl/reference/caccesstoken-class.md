---
title: Classe CAccessToken | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
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
caps.latest.revision: 24
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
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: 79845a2be4f79a1ee94a9440e8508bcb0e38bcdd
ms.lasthandoff: 02/25/2017

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
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAccessToken:: ~ CAccessToken](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAccessToken::Attach](#attach)|Chame esse método para apropriar-se de que o identificador de token de acesso.|  
|[CAccessToken::CheckTokenMembership](#checktokenmembership)|Chame esse método para determinar se um SID específico está habilitado no `CAccessToken` objeto.|  
|[CAccessToken::CreateImpersonationToken](#createimpersonationtoken)|Chame esse método para criar um novo token de acesso de representação.|  
|[CAccessToken::CreatePrimaryToken](#createprimarytoken)|Chame esse método para criar um novo token primário.|  
|[CAccessToken::CreateProcessAsUser](#createprocessasuser)|Chame esse método para criar um novo processo em execução no contexto de segurança do usuário representado pelo `CAccessToken` objeto.|  
|[CAccessToken::CreateRestrictedToken](#createrestrictedtoken)|Chame esse método para criar um novo restrito `CAccessToken` objeto.|  
|[CAccessToken::Detach](#detach)|Chame esse método para revogar a propriedade do token de acesso.|  
|[CAccessToken::DisablePrivilege](#disableprivilege)|Chame esse método para desabilitar um privilégio no `CAccessToken` objeto.|  
|[CAccessToken::DisablePrivileges](#disableprivileges)|Chame esse método para desabilitar um ou mais privilégios no `CAccessToken` objeto.|  
|[CAccessToken::EnablePrivilege](#enableprivilege)|Chame esse método para ativar um privilégio no `CAccessToken` objeto.|  
|[CAccessToken::EnablePrivileges](#enableprivileges)|Chame esse método para habilitar um ou mais privilégios no `CAccessToken` objeto.|  
|[CAccessToken::GetDefaultDacl](#getdefaultdacl)|Chame este método para retornar o `CAccessToken` do objeto padrão DACL.|  
|[CAccessToken::GetEffectiveToken](#geteffectivetoken)|Chame este método para obter o `CAccessToken` objeto igual ao token de acesso em vigor para o thread atual.|  
|[CAccessToken::GetGroups](#getgroups)|Chame este método para retornar o `CAccessToken` grupos de token do objeto.|  
|[CAccessToken::GetHandle](#gethandle)|Chame esse método para recuperar um identificador para o token de acesso.|  
|[CAccessToken::GetImpersonationLevel](#getimpersonationlevel)|Chame esse método para obter o nível de representação do token de acesso.|  
|[CAccessToken::GetLogonSessionId](#getlogonsessionid)|Chamar esse método para obter a ID de sessão de Logon associado a `CAccessToken` objeto.|  
|[CAccessToken::GetLogonSid](#getlogonsid)|Chame esse método para obter o SID de Logon associado a `CAccessToken` objeto.|  
|[CAccessToken::GetOwner](#getowner)|Chame esse método para obter o proprietário associado a `CAccessToken` objeto.|  
|[CAccessToken::GetPrimaryGroup](#getprimarygroup)|Chame esse método para obter o grupo primário associado a `CAccessToken` objeto.|  
|[CAccessToken::GetPrivileges](#getprivileges)|Chame esse método para obter os privilégios associados a `CAccessToken` objeto.|  
|[CAccessToken::GetProcessToken](#getprocesstoken)|Chame este método para inicializar o `CAccessToken` com o token de acesso de um determinado processo.|  
|[CAccessToken::GetProfile](#getprofile)|Chame esse método para obter o identificador apontando para o perfil de usuário associado a `CAccessToken` objeto.|  
|[CAccessToken::GetSource](#getsource)|Chame esse método para obter a origem do `CAccessToken` objeto.|  
|[CAccessToken::GetStatistics](#getstatistics)|Chame esse método para obter informações associadas a `CAccessToken` objeto.|  
|[CAccessToken::GetTerminalServicesSessionId](#getterminalservicessessionid)|Chame esse método para obter a ID de sessão de serviços de Terminal associados a `CAccessToken` objeto.|  
|[CAccessToken::GetThreadToken](#getthreadtoken)|Chame este método para inicializar o `CAccessToken` com o token do thread de determinado.|  
|[CAccessToken::GetTokenId](#gettokenid)|Chame esse método para obter a ID do Token associado a `CAccessToken` objeto.|  
|[CAccessToken::GetType](#gettype)|Chame esse método para obter o tipo de token do `CAccessToken` objeto.|  
|[CAccessToken::GetUser](#getuser)|Chame esse método para identificar o usuário associado a `CAccessToken` objeto.|  
|[CAccessToken::HKeyCurrentUser](#hkeycurrentuser)|Chame esse método para obter o identificador apontando para o perfil de usuário associado a `CAccessToken` objeto.|  
|[CAccessToken::Impersonate](#impersonate)|Chame esse método para atribuir uma representação `CAccessToken` a um thread.|  
|[CAccessToken::ImpersonateLoggedOnUser](#impersonateloggedonuser)|Chame esse método para permitir que o thread de chamada representar o contexto de segurança de um usuário conectado.|  
|[CAccessToken::IsTokenRestricted](#istokenrestricted)|Chamar esse método para testar se o `CAccessToken` objeto contém uma lista de SIDs restritos.|  
|[CAccessToken::LoadUserProfile](#loaduserprofile)|Chame esse método para carregar o perfil de usuário associado a `CAccessToken` objeto.|  
|[CAccessToken::LogonUser](#logonuser)|Chame esse método para criar uma sessão de logon do usuário associados com as credenciais fornecidas.|  
|[CAccessToken::OpenCOMClientToken](#opencomclienttoken)|Chamar esse método de dentro de um servidor COM tratamento de uma chamada de um cliente para inicializar o `CAccessToken` com o token de acesso do cliente COM.|  
|[CAccessToken::OpenNamedPipeClientToken](#opennamedpipeclienttoken)|Chamar esse método de dentro de um servidor levando solicitações em um pipe nomeado para inicializar o `CAccessToken` com o token de acesso do cliente.|  
|[CAccessToken::OpenRPCClientToken](#openrpcclienttoken)|Chamar esse método de dentro de um servidor de tratar uma chamada de um cliente RPC para inicializar o `CAccessToken` com o token de acesso do cliente.|  
|[CAccessToken::OpenThreadToken](#openthreadtoken)|Chamar esse método para definir o nível de representação e, em seguida, inicialize o `CAccessToken` com o token do thread de determinado.|  
|[CAccessToken::PrivilegeCheck](#privilegecheck)|Chame esse método para determinar se um conjunto específico de privilégios estão habilitados no **CAccessToken** objeto.|  
|[CAccessToken::Revert](#revert)|Chame esse método para interromper um thread que está usando um token de representação.|  
|[CAccessToken::SetDefaultDacl](#setdefaultdacl)|Chame esse método para definir o padrão de DACL do `CAccessToken` objeto.|  
|[CAccessToken::SetOwner](#setowner)|Chame esse método para definir o proprietário do `CAccessToken` objeto.|  
|[CAccessToken::SetPrimaryGroup](#setprimarygroup)|Chamar esse método para definir o grupo primário de `CAccessToken` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Um [token de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374909) é um objeto que descreve o contexto de segurança de um processo ou thread e alocado para cada usuário conectado em um sistema Windows NT ou Windows 2000.  
  
 Para obter uma introdução ao modelo de controle de acesso no Windows, consulte [o controle de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374860) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsecurity. h  
  
##  <a name="attach"></a>CAccessToken::Attach  
 Chame esse método para apropriar-se de que o identificador de token de acesso.  
  
```
void Attach(HANDLE hToken) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *hToken*  
 Um identificador para o token de acesso.  
  
### <a name="remarks"></a>Comentários  
 Em compilações de depuração, asserção ocorrerá um erro se o `CAccessToken` objeto já tem a propriedade de um token de acesso.  
  
##  <a name="dtor"></a>CAccessToken:: ~ CAccessToken  
 O destruidor.  
  
```
virtual ~CAccessToken() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados.  
  
##  <a name="checktokenmembership"></a>CAccessToken::CheckTokenMembership  
 Chame esse método para determinar se um SID específico está habilitado no `CAccessToken` objeto.  
  
```
bool CheckTokenMembership(
    const CSid& rSid, 
    bool* pbIsMember) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rSid`  
 Referência a um [classe CSid](../../atl/reference/csid-class.md) objeto.  
  
 `pbIsMember`  
 Ponteiro para uma variável que recebe os resultados da verificação.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O `CheckTokenMembership` método verifica a presença do SID de usuário e grupo SIDs do token de acesso. Se o SID está presente e tem o atributo SE_GROUP_ENABLED, *pbIsMember* é definido como true; caso contrário, ele é definido como false.  
  
 Em compilações de depuração, um erro de asserção ocorrerá se `pbIsMember` não é um ponteiro válido.  
  
> [!NOTE]
>  O `CAccessToken` objeto deve ser um token de representação e não um token primário.  
  
##  <a name="createimpersonationtoken"></a>CAccessToken::CreateImpersonationToken  
 Chame esse método para criar um token de acesso de representação.  
  
```
bool CreateImpersonationToken(
    CAccessToken* pImp, 
    SECURITY_IMPERSONATION_LEVEL sil = SecurityImpersonation) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pImp`  
 Ponteiro para o novo `CAccessToken` objeto.  
  
 `sil`  
 Especifica um [SECURITY_IMPERSONATION_LEVEL](http://msdn.microsoft.com/library/windows/desktop/aa379572) que fornece o nível de representação do novo símbolo de tipo enumerado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 `CreateImpersonationToken`chamadas [DuplicateToken](http://msdn.microsoft.com/library/windows/desktop/aa446616) para criar um novo token de representação.  
  
##  <a name="createprimarytoken"></a>CAccessToken::CreatePrimaryToken  
 Chame esse método para criar um novo token primário.  
  
```
bool CreatePrimaryToken(
    CAccessToken* pPri,
    DWORD dwDesiredAccess = MAXIMUM_ALLOWED,
    const CSecurityAttributes* pTokenAttributes = NULL) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pPri*  
 Ponteiro para o novo `CAccessToken` objeto.  
  
 `dwDesiredAccess`  
 Especifica os direitos de acesso solicitado para o novo token. O padrão, MAXIMUM_ALLOWED, solicitações de todos os direitos de acesso que são válidos para o chamador. Consulte [direitos de acesso e as máscaras de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374902) para mais em direitos de acesso.  
  
 *pTokenAttributes*  
 Ponteiro para uma [SECURITY_ATTRIBUTES](http://msdn.microsoft.com/library/windows/desktop/aa379560) estrutura que especifica um descritor de segurança para o novo token e determina se os processos filho podem herdar o token. Se *pTokenAttributes* for NULL, o token obtém um descritor de segurança padrão e o identificador não pode ser herdado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 `CreatePrimaryToken`chamadas [DuplicateTokenEx](http://msdn.microsoft.com/library/windows/desktop/aa446617) para criar um novo token primário.  
  
##  <a name="createprocessasuser"></a>CAccessToken::CreateProcessAsUser  
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
 *pApplicationName*  
 Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o módulo para executar. Esse parâmetro não pode ser NULL.  
  
 *pCommandLine*  
 Ponteiro para uma cadeia de caracteres terminada em nulo que especifica a linha de comando para executar.  
  
 *pProcessInformation*  
 Ponteiro para uma [PROCESS_INFORMATION](http://msdn.microsoft.com/library/windows/desktop/ms684873) estrutura que recebe informações de identificação sobre o novo processo.  
  
 *pStartupInfo*  
 Ponteiro para uma [STARTUPINFO](http://msdn.microsoft.com/library/windows/desktop/ms686331) estrutura que especifica como a janela principal para o novo processo deve aparecer.  
  
 `dwCreationFlags`  
 Especifica os sinalizadores adicionais que controlam a classe de prioridade e a criação do processo. Consulte a função Win32 [CreateProcessAsUser](http://msdn.microsoft.com/library/windows/desktop/ms682429) para obter uma lista de sinalizadores.  
  
 *bLoadProfile*  
 Se true, o perfil do usuário é carregado com [LoadUserProfile](http://msdn.microsoft.com/library/windows/desktop/bb762281).  
  
 *pProcessAttributes*  
 Ponteiro para uma [SECURITY_ATTRIBUTES](http://msdn.microsoft.com/library/windows/desktop/aa379560) estrutura que especifica um descritor de segurança para o novo processo e determina se os processos filho podem herdar o identificador retornado. Se *pProcessAttributes* for NULL, o processo obtém um descritor de segurança padrão e o identificador não pode ser herdado.  
  
 *pThreadAttributes*  
 Ponteiro para uma [SECURITY_ATTRIBUTES](http://msdn.microsoft.com/library/windows/desktop/aa379560) estrutura que especifica um descritor de segurança para o novo thread e determina se os processos filho podem herdar o identificador retornado. Se *pThreadAttributes* for NULL, o thread obtém um descritor de segurança padrão e o identificador não pode ser herdado.  
  
 *caixa de seleção bHerdar*  
 Indica se o novo processo herda identificadores do processo de chamada. Se true, cada identificador aberto herdável no processo de chamada é herdado pelo processo de novo. Identificadores herdados têm os mesmos privilégios de acesso e o valor como os identificadores originais.  
  
 *pCurrentDirectory*  
 Ponteiro para uma cadeia de caracteres terminada em nulo que especifica a unidade atual e o diretório para o novo processo. A cadeia de caracteres deve ser um caminho completo que inclui uma letra de unidade. Se esse parâmetro for NULL, o novo processo terá a mesma unidade e pasta atuais como o processo de chamada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 **CreateProcessAsUser** usa o `CreateProcessAsUser` função do Win32 para criar um novo processo é executado no contexto de segurança do usuário representado pelo `CAccessToken` objeto. Consulte a descrição do [CreateProcessAsUser](http://msdn.microsoft.com/library/windows/desktop/ms682429) função para uma discussão completa sobre os parâmetros necessários.  
  
 Para esse método seja bem-sucedido, o `CAccessToken` objeto deve conter AssignPrimaryToken (a menos que ele seja um token restrito) e privilégios do IncreaseQuota.  
  
##  <a name="createrestrictedtoken"></a>CAccessToken::CreateRestrictedToken  
 Chame esse método para criar um novo restrito `CAccessToken` objeto.  
  
```
bool CreateRestrictedToken(
    CAccessToken* pRestrictedToken,
    const CTokenGroups& SidsToDisable,
    const CTokenGroups& SidsToRestrict,
    const CTokenPrivileges& PrivilegesToDelete = CTokenPrivileges()) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pRestrictedToken*  
 O novo restrito `CAccessToken` objeto.  
  
 `SidsToDisable`  
 Um `CTokenGroups` objeto que especifica as SIDs somente de negação.  
  
 *SidsToRestrict*  
 Um `CTokenGroups` objeto que especifica os SIDs de restrição.  
  
 `PrivilegesToDelete`  
 Um `CTokenPrivileges` objeto que especifica os privilégios para excluir o token restrito. O padrão cria um objeto vazio.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 `CreateRestrictedToken`usa o [CreateRestrictedToken](http://msdn.microsoft.com/library/windows/desktop/aa446583) função do Win32 para criar um novo `CAccessToken` objeto, com restrições.  
  
> [!NOTE]
>  Este método só está disponível no Windows 2000 ou posterior.  
  
> [!IMPORTANT]
>  Ao usar `CreateRestrictedToken`, verifique o seguinte: o token existente é válido (e não digitado pelo usuário) e `SidsToDisable` e `PrivilegesToDelete` são válidas (e não digitado pelo usuário). Se o método retornar false, nega funcionalidade.  
  
##  <a name="detach"></a>CAccessToken::Detach  
 Chame esse método para revogar a propriedade do token de acesso.  
  
```
HANDLE Detach() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o identificador para o `CAccessToken` que foi desanexado.  
  
### <a name="remarks"></a>Comentários  
 Esse método revoga o `CAccessToken`da propriedade do token de acesso.  
  
##  <a name="disableprivilege"></a>CAccessToken::DisablePrivilege  
 Chame esse método para desabilitar um privilégio no `CAccessToken` objeto.  
  
```
bool DisablePrivilege(
    LPCTSTR pszPrivilege,
    CTokenPrivileges* pPreviousState = NULL) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszPrivilege`  
 Ponteiro para uma cadeia de caracteres que contém o privilégio para desativar o `CAccessToken` objeto.  
  
 `pPreviousState`  
 Ponteiro para uma `CTokenPrivileges` objeto contendo o estado anterior dos privilégios.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
##  <a name="disableprivileges"></a>CAccessToken::DisablePrivileges  
 Chame esse método para desabilitar um ou mais privilégios no `CAccessToken` objeto.  
  
```
bool DisablePrivileges(
    const CAtlArray<LPCTSTR>& rPrivileges,
    CTokenPrivileges* pPreviousState = NULL) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rPrivileges`  
 Ponteiro para uma matriz de cadeias de caracteres que contém os privilégios para desativar o `CAccessToken` objeto.  
  
 `pPreviousState`  
 Ponteiro para uma `CTokenPrivileges` objeto contendo o estado anterior dos privilégios.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
##  <a name="enableprivilege"></a>CAccessToken::EnablePrivilege  
 Chame esse método para ativar um privilégio no `CAccessToken` objeto.  
  
```
bool EnablePrivilege(
    LPCTSTR pszPrivilege,
    CTokenPrivileges* pPreviousState = NULL) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszPrivilege`  
 Ponteiro para uma cadeia de caracteres que contém o privilégio para habilitar o `CAccessToken` objeto.  
  
 `pPreviousState`  
 Ponteiro para uma `CTokenPrivileges` objeto contendo o estado anterior dos privilégios.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
##  <a name="enableprivileges"></a>CAccessToken::EnablePrivileges  
 Chame esse método para habilitar um ou mais privilégios no `CAccessToken` objeto.  
  
```
bool EnablePrivileges(
    const CAtlArray<LPCTSTR>& rPrivileges,
    CTokenPrivileges* pPreviousState = NULL) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rPrivileges`  
 Ponteiro para uma matriz de cadeias de caracteres que contém os privilégios necessários para habilitar o `CAccessToken` objeto.  
  
 `pPreviousState`  
 Ponteiro para uma `CTokenPrivileges` objeto contendo o estado anterior dos privilégios.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
##  <a name="getdefaultdacl"></a>CAccessToken::GetDefaultDacl  
 Chame este método para retornar o `CAccessToken` do objeto padrão DACL.  
  
```
bool GetDefaultDacl(CDacl* pDacl) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDacl`  
 Ponteiro para o [CDacl classe](../../atl/reference/cdacl-class.md) objeto que receberá o **CAccessToken** do objeto padrão DACL.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se a DACL padrão tiver sido recuperado, FALSO caso contrário.  
  
##  <a name="geteffectivetoken"></a>CAccessToken::GetEffectiveToken  
 Chame este método para obter o `CAccessToken` objeto igual ao token de acesso em vigor para o thread atual.  
  
```
bool GetEffectiveToken(DWORD dwDesiredAccess) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwDesiredAccess`  
 Especifica uma máscara de acesso que especifica os tipos solicitados de acesso ao token de acesso. Esses tipos de acesso solicitado são comparados com a DACL do token para determinar quais acessos são concedidos ou negados.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
##  <a name="getgroups"></a>CAccessToken::GetGroups  
 Chame este método para retornar o `CAccessToken` grupos de token do objeto.  
  
```
bool GetGroups(CTokenGroups* pGroups) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pGroups*  
 Ponteiro para o [CTokenGroups classe](../../atl/reference/ctokengroups-class.md) objeto que receberá as informações do grupo.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
##  <a name="gethandle"></a>CAccessToken::GetHandle  
 Chame esse método para recuperar um identificador para o token de acesso.  
  
```
HANDLE GetHandle() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um identificador para o `CAccessToken` o token de acesso do objeto.  
  
##  <a name="getimpersonationlevel"></a>CAccessToken::GetImpersonationLevel  
 Chame esse método para obter o nível de representação do token de acesso.  
  
```
bool GetImpersonationLevel(
    SECURITY_IMPERSONATION_LEVEL* pImpersonationLevel) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pImpersonationLevel*  
 Ponteiro para uma [SECURITY_IMPERSONATION_LEVEL](http://msdn.microsoft.com/library/windows/desktop/aa379572) tipo de enumeração que receberá as informações do nível de representação.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
##  <a name="getlogonsessionid"></a>CAccessToken::GetLogonSessionId  
 Chamar esse método para obter a ID de sessão de Logon associado a `CAccessToken` objeto.  
  
```
bool GetLogonSessionId(LUID* pluid) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pluid`  
 Ponteiro para uma [LUID](http://msdn.microsoft.com/library/windows/desktop/aa379261) que receberá a ID da sessão de Logon.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Em compilações de depuração, um erro de asserção ocorrerá se `pluid` é um valor inválido.  
  
##  <a name="getlogonsid"></a>CAccessToken::GetLogonSid  
 Chame esse método para obter o SID de Logon associado a `CAccessToken` objeto.  
  
```
bool GetLogonSid(CSid* pSid) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pSid`  
 Ponteiro para uma [classe CSid](../../atl/reference/csid-class.md) objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Em compilações de depuração, um erro de asserção ocorrerá se *pSid* é um valor inválido.  
  
##  <a name="getowner"></a>CAccessToken::GetOwner  
 Chame esse método para obter o proprietário associado a `CAccessToken` objeto.  
  
```
bool GetOwner(CSid* pSid) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pSid`  
 Ponteiro para uma [classe CSid](../../atl/reference/csid-class.md) objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O proprietário é definido por padrão em todos os objetos criados enquanto esse token de acesso estiver em vigor.  
  
##  <a name="getprimarygroup"></a>CAccessToken::GetPrimaryGroup  
 Chame esse método para obter o grupo primário associado a `CAccessToken` objeto.  
  
```
bool GetPrimaryGroup(CSid* pSid) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pSid`  
 Ponteiro para uma [classe CSid](../../atl/reference/csid-class.md) objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O grupo é definido por padrão em todos os objetos criados enquanto esse token de acesso estiver em vigor.  
  
##  <a name="getprivileges"></a>CAccessToken::GetPrivileges  
 Chame esse método para obter os privilégios associados a `CAccessToken` objeto.  
  
```
bool GetPrivileges(CTokenPrivileges* pPrivileges) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPrivileges`  
 Ponteiro para uma [CTokenPrivileges classe](../../atl/reference/ctokenprivileges-class.md) objeto que recebe os privilégios.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
##  <a name="getprocesstoken"></a>CAccessToken::GetProcessToken  
 Chame este método para inicializar o `CAccessToken` com o token de acesso de um determinado processo.  
  
```
bool GetProcessToken(DWORD dwDesiredAccess, HANDLE hProcess = NULL) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwDesiredAccess`  
 Especifica uma máscara de acesso que especifica os tipos solicitados de acesso ao token de acesso. Esses tipos de acesso solicitado são comparados com a DACL do token para determinar quais acessos são concedidos ou negados.  
  
 *hProcess*  
 Identificador do processo cujo token de acesso é aberto. Se o valor padrão de `NULL` é usado, o processo atual é usado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `true` com êxito, `false` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Chamadas de [OpenProcessToken](http://msdn.microsoft.com/library/aa379295\(vs.85\).aspx) função do Win32.  
  
##  <a name="getprofile"></a>CAccessToken::GetProfile  
 Chame esse método para obter o identificador apontando para o perfil de usuário associado a `CAccessToken` objeto.  
  
```
HANDLE GetProfile() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um identificador apontando para o perfil de usuário, ou nulo se não existe nenhum perfil.  
  
##  <a name="getsource"></a>CAccessToken::GetSource  
 Chame esse método para obter a origem do `CAccessToken` objeto.  
  
```
bool GetSource(TOKEN_SOURCE* pSource) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pSource*  
 Ponteiro para uma [TOKEN_SOURCE](http://msdn.microsoft.com/library/windows/desktop/aa379631) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
##  <a name="getstatistics"></a>CAccessToken::GetStatistics  
 Chame esse método para obter informações associadas a `CAccessToken` objeto.  
  
```
bool GetStatistics(TOKEN_STATISTICS* pStatistics) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pStatistics*  
 Ponteiro para uma [TOKEN_STATISTICS](http://msdn.microsoft.com/library/windows/desktop/aa379632) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
##  <a name="getterminalservicessessionid"></a>CAccessToken::GetTerminalServicesSessionId  
 Chame esse método para obter a ID de sessão de serviços de Terminal associados a `CAccessToken` objeto.  
  
```
bool GetTerminalServicesSessionId(DWORD* pdwSessionId) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pdwSessionId*  
 A ID de sessão dos serviços de Terminal.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
##  <a name="getthreadtoken"></a>CAccessToken::GetThreadToken  
 Chame este método para inicializar o `CAccessToken` com o token do thread de determinado.  
  
```
bool GetThreadToken(
    DWORD dwDesiredAccess,
    HANDLE hThread = NULL,
    bool bOpenAsSelf = true) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwDesiredAccess`  
 Especifica uma máscara de acesso que especifica os tipos solicitados de acesso ao token de acesso. Esses tipos de acesso solicitado são comparados com a DACL do token para determinar quais acessos são concedidos ou negados.  
  
 `hThread`  
 Manipula o thread cujo token de acesso é aberto.  
  
 `bOpenAsSelf`  
 Indica se a verificação de acesso deve ser feita no contexto de segurança de chamada do thread a `GetThreadToken` método ou no contexto de segurança do processo para o thread de chamada.  
  
 Se esse parâmetro for false, a verificação de acesso é executada usando o contexto de segurança para o thread de chamada. Se o thread estiver representando um cliente, nesse contexto de segurança pode ser de um processo de cliente. Se esse parâmetro for true, a verificação de acesso é feita usando o contexto de segurança do processo para o thread de chamada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
##  <a name="gettokenid"></a>CAccessToken::GetTokenId  
 Chame esse método para obter a ID do Token associado a `CAccessToken` objeto.  
  
```
bool GetTokenId(LUID* pluid) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pluid`  
 Ponteiro para uma [LUID](http://msdn.microsoft.com/library/windows/desktop/aa379261) que receberá a ID do Token.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
##  <a name="gettype"></a>CAccessToken::GetType  
 Chame esse método para obter o tipo de token do `CAccessToken` objeto.  
  
```
bool GetType(TOKEN_TYPE* pType) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pType`  
 Endereço do [TOKEN_TYPE](http://msdn.microsoft.com/library/windows/desktop/aa379633) variável que, em caso de sucesso, recebe o tipo do token.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O **TOKEN_TYPE** tipo de enumeração contém valores que fazem distinção entre um token primário e um token de representação.  
  
##  <a name="getuser"></a>CAccessToken::GetUser  
 Chame esse método para identificar o usuário associado a `CAccessToken` objeto.  
  
```
bool GetUser(CSid* pSid) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pSid`  
 Ponteiro para uma [classe CSid](../../atl/reference/csid-class.md) objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
##  <a name="hkeycurrentuser"></a>CAccessToken::HKeyCurrentUser  
 Chame esse método para obter o identificador apontando para o perfil de usuário associado a `CAccessToken` objeto.  
  
```
HKEY HKeyCurrentUser() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um identificador apontando para o perfil de usuário, ou nulo se não existe nenhum perfil.  
  
##  <a name="impersonate"></a>CAccessToken::Impersonate  
 Chame esse método para atribuir uma representação `CAccessToken` a um thread.  
  
```
bool Impersonate(HANDLE hThread = NULL) const throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hThread`  
 Manipula o thread para atribuir o token de representação. Esse identificador deve ter aberto com direitos de acesso TOKEN_IMPERSONATE. Se `hThread` for NULL, o método faz com que o thread parar de usar um token de representação.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Em compilações de depuração, um erro de asserção ocorrerá se `CAccessToken` não tem um ponteiro válido para um token.  
  
 O [CAutoRevertImpersonation classe](../../atl/reference/cautorevertimpersonation-class.md) pode ser usado para reverter automaticamente os tokens de acesso representado.  
  
##  <a name="impersonateloggedonuser"></a>CAccessToken::ImpersonateLoggedOnUser  
 Chame esse método para permitir que o thread de chamada representar o contexto de segurança de um usuário conectado.  
  
```
bool ImpersonateLoggedOnUser() const throw(...);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
  
> [!IMPORTANT]
>  Se uma chamada para uma função de representação falhar por algum motivo, o cliente não é representado e a solicitação do cliente é feita no contexto de segurança do processo em que a chamada foi feita. Se o processo é executado como uma conta altamente privilegiada, ou como um membro de um grupo administrativo, o usuário poderá executar ações ele seria contrário não permitida. Portanto, o valor de retorno para esta função sempre deve ser confirmado.  
  
##  <a name="istokenrestricted"></a>CAccessToken::IsTokenRestricted  
 Chamar esse método para testar se o `CAccessToken` objeto contém uma lista de SIDs restritos.  
  
```
bool IsTokenRestricted() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true se o objeto contém uma lista de SIDs, FALSO se não houver nenhuma restrição SIDs de restrição ou se o método falhar.  
  
##  <a name="loaduserprofile"></a>CAccessToken::LoadUserProfile  
 Chame esse método para carregar o perfil de usuário associado a `CAccessToken` objeto.  
  
```
bool LoadUserProfile() throw(...);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Em compilações de depuração, asserção ocorrerá um erro se o `CAccessToken` não contém um token válido, ou se um usuário de perfil já existe.  
  
##  <a name="logonuser"></a>CAccessToken::LogonUser  
 Chame esse método para criar uma sessão de logon do usuário associados com as credenciais fornecidas.  
  
```
bool LogonUser(
    LPCTSTR pszUserName,
    LPCTSTR pszDomain,
    LPCTSTR pszPassword,
    DWORD dwLogonType = LOGON32_LOGON_INTERACTIVE,
    DWORD dwLogonProvider = LOGON32_PROVIDER_DEFAULT) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszUserName`  
 Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome de usuário. Esse é o nome da conta de usuário para efetuar logon.  
  
 *pszDomain*  
 Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do domínio ou do servidor cuja conta de banco de dados contém o `pszUserName` conta.  
  
 `pszPassword`  
 Ponteiro para uma cadeia de caracteres terminada em nulo que especifica a senha de texto não criptografado para a conta de usuário especificada pelo `pszUserName`.  
  
 *dwLogonType*  
 Especifica o tipo de operação de logon para executar. Consulte [LogonUser](http://msdn.microsoft.com/library/windows/desktop/aa378184) para obter mais detalhes.  
  
 *dwLogonProvider*  
 Especifica o provedor de logon. Consulte [LogonUser](http://msdn.microsoft.com/library/windows/desktop/aa378184) para obter mais detalhes.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O acesso ao token resultante de logon será associado a `CAccessToken`. Para esse método seja bem-sucedido, o `CAccessToken` objeto deve conter privilégios SE_TCB_NAME, identificando o proprietário como parte do computador confiável base. Consulte [LogonUser](http://msdn.microsoft.com/library/windows/desktop/aa378184) para obter mais informações sobre os privilégios necessários.  
  
##  <a name="opencomclienttoken"></a>CAccessToken::OpenCOMClientToken  
 Chamar esse método de dentro de um servidor COM tratamento de uma chamada de um cliente para inicializar o `CAccessToken` com o token de acesso do cliente COM.  
  
```
bool OpenCOMClientToken(
    DWORD dwDesiredAccess,
    bool bImpersonate = false,
    bool bOpenAsSelf = true) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwDesiredAccess`  
 Especifica uma máscara de acesso que especifica os tipos solicitados de acesso ao token de acesso. Esses tipos de acesso solicitado são comparados com a DACL do token para determinar quais acessos são concedidos ou negados.  
  
 `bImpersonate`  
 Se for true, o thread atual representará o cliente COM chamada se essa chamada for concluída com êxito. Se for false, o token de acesso será aberto, mas o thread não terá um token de representação quando essa chamada é concluída.  
  
 `bOpenAsSelf`  
 Indica se a verificação de acesso deve ser feita no contexto de segurança de chamada do thread a [GetThreadToken](http://msdn.microsoft.com/library/windows/desktop/ms683182) método ou no contexto de segurança do processo para o thread de chamada.  
  
 Se esse parâmetro for false, a verificação de acesso é executada usando o contexto de segurança para o thread de chamada. Se o thread estiver representando um cliente, nesse contexto de segurança pode ser de um processo de cliente. Se esse parâmetro for true, a verificação de acesso é feita usando o contexto de segurança do processo para o thread de chamada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O [CAutoRevertImpersonation classe](../../atl/reference/cautorevertimpersonation-class.md) pode ser usado para reverter automaticamente os tokens de acesso representado criados pela definição de `bImpersonate` sinalizador como *true*.  
  
##  <a name="opennamedpipeclienttoken"></a>CAccessToken::OpenNamedPipeClientToken  
 Chamar esse método de dentro de um servidor levando solicitações em um pipe nomeado para inicializar o `CAccessToken` com o token de acesso do cliente.  
  
```
bool OpenNamedPipeClientToken(
    HANDLE hPipe,
    DWORD dwDesiredAccess,
    bool bImpersonate = false,
    bool bOpenAsSelf = true) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hPipe*  
 Identificador para um pipe nomeado.  
  
 `dwDesiredAccess`  
 Especifica uma máscara de acesso que especifica os tipos solicitados de acesso ao token de acesso. Esses tipos de acesso solicitado são comparados com a DACL do token para determinar quais acessos são concedidos ou negados.  
  
 `bImpersonate`  
 Se for true, o thread atual representará o cliente da chamada pipe se essa chamada for concluída com êxito. Se for false, o token de acesso será aberto, mas o thread não terá um token de representação quando essa chamada é concluída.  
  
 `bOpenAsSelf`  
 Indica se a verificação de acesso deve ser feita no contexto de segurança de chamada do thread a [GetThreadToken](http://msdn.microsoft.com/library/windows/desktop/ms683182) método ou no contexto de segurança do processo para o thread de chamada.  
  
 Se esse parâmetro for false, a verificação de acesso é executada usando o contexto de segurança para o thread de chamada. Se o thread estiver representando um cliente, nesse contexto de segurança pode ser de um processo de cliente. Se esse parâmetro for true, a verificação de acesso é feita usando o contexto de segurança do processo para o thread de chamada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O [CAutoRevertImpersonation classe](../../atl/reference/cautorevertimpersonation-class.md) pode ser usado para reverter automaticamente os tokens de acesso representado criados pela definição de `bImpersonate` sinalizador como *true*.  
  
##  <a name="openrpcclienttoken"></a>CAccessToken::OpenRPCClientToken  
 Chamar esse método de dentro de um servidor de tratar uma chamada de um cliente RPC para inicializar o `CAccessToken` com o token de acesso do cliente.  
  
```
bool OpenRPCClientToken(
    RPC_BINDING_HANDLE BindingHandle,
    DWORD dwDesiredAccess,
    bool bImpersonate = false,
    bool bOpenAsSelf = true) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 *BindingHandle*  
 Identificador de ligação no servidor que representa uma associação a um cliente.  
  
 `dwDesiredAccess`  
 Especifica uma máscara de acesso que especifica os tipos solicitados de acesso ao token de acesso. Esses tipos de acesso solicitado são comparados com a DACL do token para determinar quais acessos são concedidos ou negados.  
  
 `bImpersonate`  
 Se for true, o thread atual representará o cliente da chamada RPC se essa chamada for concluída com êxito. Se for false, o token de acesso será aberto, mas o thread não terá um token de representação quando essa chamada é concluída.  
  
 `bOpenAsSelf`  
 Indica se a verificação de acesso deve ser feita no contexto de segurança de chamada do thread a [GetThreadToken](http://msdn.microsoft.com/library/windows/desktop/ms683182) método ou no contexto de segurança do processo para o thread de chamada.  
  
 Se esse parâmetro for false, a verificação de acesso é executada usando o contexto de segurança para o thread de chamada. Se o thread estiver representando um cliente, nesse contexto de segurança pode ser de um processo de cliente. Se esse parâmetro for true, a verificação de acesso é feita usando o contexto de segurança do processo para o thread de chamada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O [CAutoRevertImpersonation classe](../../atl/reference/cautorevertimpersonation-class.md) pode ser usado para reverter automaticamente os tokens de acesso representado criados pela definição de `bImpersonate` sinalizador como *true*.  
  
##  <a name="openthreadtoken"></a>CAccessToken::OpenThreadToken  
 Chamar esse método para definir o nível de representação e, em seguida, inicialize o `CAccessToken` com o token do thread de determinado.  
  
```
bool OpenThreadToken(
    DWORD dwDesiredAccess,
    bool bImpersonate = false,
    bool bOpenAsSelf = true,
    SECURITY_IMPERSONATION_LEVEL sil = SecurityImpersonation) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwDesiredAccess`  
 Especifica uma máscara de acesso que especifica os tipos solicitados de acesso ao token de acesso. Esses tipos de acesso solicitado são comparados com a DACL do token para determinar quais acessos são concedidos ou negados.  
  
 `bImpersonate`  
 Se for true, o thread será deixado no nível de representação solicitado após a conclusão desse método. Se for false, o thread será revertido para seu nível de representação original.  
  
 `bOpenAsSelf`  
 Indica se a verificação de acesso deve ser feita no contexto de segurança de chamada do thread a [GetThreadToken](http://msdn.microsoft.com/library/windows/desktop/ms683182) método ou no contexto de segurança do processo para o thread de chamada.  
  
 Se esse parâmetro for false, a verificação de acesso é executada usando o contexto de segurança para o thread de chamada. Se o thread estiver representando um cliente, nesse contexto de segurança pode ser de um processo de cliente. Se esse parâmetro for true, a verificação de acesso é feita usando o contexto de segurança do processo para o thread de chamada.  
  
 `sil`  
 Especifica um [SECURITY_IMPERSONATION_LEVEL](http://msdn.microsoft.com/library/windows/desktop/aa379572) que fornece o nível de representação do símbolo de tipo enumerado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 `OpenThreadToken`é semelhante ao [CAccessToken::GetThreadToken](#getthreadtoken), mas define o nível de representação antes de inicializar o `CAccessToken` do token de acesso do thread.  
  
 O [CAutoRevertImpersonation classe](../../atl/reference/cautorevertimpersonation-class.md) pode ser usado para reverter automaticamente os tokens de acesso representado criados pela definição de `bImpersonate` sinalizador como *true*.  
  
##  <a name="privilegecheck"></a>CAccessToken::PrivilegeCheck  
 Chame esse método para determinar se um conjunto específico de privilégios estão habilitados no **CAccessToken** objeto.  
  
```
bool PrivilegeCheck(
    PPRIVILEGE_SET RequiredPrivileges,
     bool* pbResult) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *RequiredPrivileges*  
 Ponteiro para uma [PRIVILEGE_SET](http://msdn.microsoft.com/library/windows/desktop/aa379307) estrutura.  
  
 *pbResult*  
 O método de ponteiro para um valor define para indicar se algum ou todos os privilégios especificados estão habilitados no `CAccessToken` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Quando `PrivilegeCheck` retorna, o **atributos** membro de cada [LUID_AND_ATTRIBUTES](http://msdn.microsoft.com/library/windows/desktop/aa379263) estrutura é definida como SE_PRIVILEGE_USED_FOR_ACCESS se o privilégio correspondente está habilitado. Esse método chama o [PrivilegeCheck](http://msdn.microsoft.com/library/windows/desktop/aa379304) função do Win32.  
  
##  <a name="revert"></a>CAccessToken::Revert  
 Chame esse método para interromper um thread usa um token de representação.  
  
```
bool Revert(HANDLE hThread = NULL) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `hThread`  
 Manipula o thread ao reverter a representação. Se *hThread* for NULL, o thread atual é assumido.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 A reversão de tokens de representação pode ser executada automaticamente com o [CAutoRevertImpersonation classe](../../atl/reference/cautorevertimpersonation-class.md).  
  
##  <a name="setdefaultdacl"></a>CAccessToken::SetDefaultDacl  
 Chame esse método para definir o padrão de DACL do `CAccessToken` objeto.  
  
```
bool SetDefaultDacl(const CDacl& rDacl) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rDacl`  
 O novo padrão [CDacl classe](../../atl/reference/cdacl-class.md) informações.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 A DACL padrão será a DACL é usada por padrão quando novos objetos são criados com esse token de acesso em vigor.  
  
##  <a name="setowner"></a>CAccessToken::SetOwner  
 Chame esse método para definir o proprietário do `CAccessToken` objeto.  
  
```
bool SetOwner(const CSid& rSid) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rSid`  
 O [CSid classe](../../atl/reference/csid-class.md) que contém as informações do proprietário do objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O proprietário é o proprietário padrão que é usado para novos objetos criados enquanto esse token de acesso estiver em vigor.  
  
##  <a name="setprimarygroup"></a>CAccessToken::SetPrimaryGroup  
 Chamar esse método para definir o grupo primário de `CAccessToken` objeto.  
  
```
bool SetPrimaryGroup(const CSid& rSid) throw(...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rSid`  
 O [classe CSid](../../atl/reference/csid-class.md) objeto que contém as informações de grupo primário.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna true em caso de êxito, false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O grupo primário é o grupo padrão para novos objetos criados enquanto esse token de acesso estiver em vigor.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo de ATLSecurity](../../visual-cpp-samples.md)   
 [Tokens de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374909)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

