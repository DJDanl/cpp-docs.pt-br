---
title: "Funções globais do identificador de segurança | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- atlsecurity/ATL::Sids::AccountOps
- atlsecurity/ATL::Sids::Admins
- atlsecurity/ATL::Sids::AnonymousLogon
- atlsecurity/ATL::Sids::AuthenticatedUser
- atlsecurity/ATL::Sids::BackupOps
- atlsecurity/ATL::Sids::Batch
- atlsecurity/ATL::Sids::CreatorGroup
- atlsecurity/ATL::Sids::CreatorGroupServer
- atlsecurity/ATL::Sids::CreatorOwner
- atlsecurity/ATL::Sids::CreatorOwnerServer
- atlsecurity/ATL::Sids::Dialup
- atlsecurity/ATL::Sids::Guests
- atlsecurity/ATL::Sids::Interactive
- atlsecurity/ATL::Sids::Local
- atlsecurity/ATL::Sids::Network
- atlsecurity/ATL::Sids::NetworkService
- atlsecurity/ATL::Sids::Null
- atlsecurity/ATL::Sids::PowerUsers
- atlsecurity/ATL::Sids::PrintOps
- atlsecurity/ATL::Sids::Proxy
- atlsecurity/ATL::Sids::RasServers
- atlsecurity/ATL::Sids::Replicator
- atlsecurity/ATL::Sids::RestrictedCode
- atlsecurity/ATL::Sids::Self
- atlsecurity/ATL::Sids::ServerLogon
- atlsecurity/ATL::Sids::Service
- atlsecurity/ATL::Sids::System
- atlsecurity/ATL::Sids::SystemOps
- atlsecurity/ATL::Sids::TerminalServer
- atlsecurity/ATL::Sids::Users
- atlsecurity/ATL::Sids::World
dev_langs:
- C++
helpviewer_keywords:
- security IDs [C++]
- SIDs [C++], returning SID objects
ms.assetid: 85404dcb-c59b-4535-ab3d-66cfa37e87de
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6975b6b73c6d81fc9347a2395cd36747ce235b2a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="security-identifier-global-functions"></a>Funções globais do identificador de segurança
Essas funções retornam SID bem conhecido comuns de objetos.  
  
> [!IMPORTANT]
>  As funções listadas na tabela a seguir não podem ser usadas em aplicativos que são executados o tempo de execução do Windows.  
  
|||  
|-|-|  
|[SIDs::AccountOps](#accountops)|Retorna o SID DOMAIN_ALIAS_RID_ACCOUNT_OPS.|  
|[SIDs::Admins](#admins)|Retorna o SID DOMAIN_ALIAS_RID_ADMINS.|  
|[SIDs::AnonymousLogon](#anonymouslogon)|Retorna o SID SECURITY_ANONYMOUS_LOGON_RID.|  
|[SIDs::AuthenticatedUser](#authenticateduser)|Retorna o SID SECURITY_AUTHENTICATED_USER_RID.|  
|[SIDs::BackupOps](#backupops)|Retorna o SID DOMAIN_ALIAS_RID_BACKUP_OPS.|  
|[SIDs::batch](#batch)|Retorna o SID SECURITY_BATCH_RID.|  
|[SIDs::CreatorGroup](#creatorgroup)|Retorna o SID SECURITY_CREATOR_GROUP_RID.|  
|[SIDs::CreatorGroupServer](#creatorgroupserver)|Retorna o SID SECURITY_CREATOR_GROUP_SERVER_RID.|  
|[SIDs::CreatorOwner](#creatorowner)|Retorna o SID SECURITY_CREATOR_OWNER_RID.|  
|[SIDs::CreatorOwnerServer](#creatorownerserver)|Retorna o SID SECURITY_CREATOR_OWNER_SERVER_RID.|  
|[SIDs::dialup](#dialup)|Retorna o SID SECURITY_DIALUP_RID.|  
|[SIDs::Guests](#guests)|Retorna o SID DOMAIN_ALIAS_RID_GUESTS.|  
|[SIDs::Interactive](#interactive)|Retorna o SID SECURITY_INTERACTIVE_RID.|  
|[SIDs::local](#local)|Retorna o SID SECURITY_LOCAL_RID.|  
|[SIDs::Network](#network)|Retorna o SID SECURITY_NETWORK_RID.|  
|[SIDs::NetworkService](#networkservice)|Retorna o SID SECURITY_NETWORK_SERVICE_RID.|  
|[SIDs::null](#null)|Retorna o SID SECURITY_NULL_RID.|  
|[SIDs::PreW2KAccess](#prew2kaccess)|Retorna o SID DOMAIN_ALIAS_RID_PREW2KCOMPACCESS.|  
|[SIDs::PowerUsers](#powerusers)|Retorna o SID DOMAIN_ALIAS_RID_POWER_USERS.|  
|[SIDs::PrintOps](#printops)|Retorna o SID DOMAIN_ALIAS_RID_PRINT_OPS.|  
|[SIDs::proxy](#proxy)|Retorna o SID SECURITY_PROXY_RID.|  
|[SIDs::RasServers](#rasservers)|Retorna o SID DOMAIN_ALIAS_RID_RAS_SERVERS.|  
|[SIDs::Replicator](#replicator)|Retorna o SID DOMAIN_ALIAS_RID_REPLICATOR.|  
|[SIDs::RestrictedCode](#restrictedcode)|Retorna o SID SECURITY_RESTRICTED_CODE_RID.|  
|[SIDs::Self](#self)|Retorna o SID SECURITY_PRINCIPAL_SELF_RID.|  
|[SIDs::ServerLogon](#serverlogon)|Retorna o SID SECURITY_SERVER_LOGON_RID.|  
|[SIDs::Service](#service)|Retorna o SID SECURITY_SERVICE_RID.|  
|[SIDs::System](#system)|Retorna o SID SECURITY_LOCAL_SYSTEM_RID.|  
|[SIDs::SystemOps](#systemops)|Retorna o SID DOMAIN_ALIAS_RID_SYSTEM_OPS.|  
|[SIDs::terminalserver](#terminalserver)|Retorna o SID SECURITY_TERMINAL_SERVER_RID.|  
|[SIDs::Users](#users)|Retorna o SID DOMAIN_ALIAS_RID_USERS.|  
|[SIDs::World](#world)|Retorna o SID SECURITY_WORLD_RID.|  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsecurity.h 

##  <a name="accountops"></a>SIDs::AccountOps  
 Retorna o SID DOMAIN_ALIAS_RID_ACCOUNT_OPS.    
  
```
CSid AccountOps() throw(...);
```  
  
##  <a name="admins"></a>SIDs::Admins  
 Retorna o SID DOMAIN_ALIAS_RID_ADMINS.  
```
CSid Admins() throw(...);
```  
  
##  <a name="anonymouslogon"></a>SIDs::AnonymousLogon  
 Retorna o SID SECURITY_ANONYMOUS_LOGON_RID.  
```
CSid AnonymousLogon() throw(...);
```  
  
##  <a name="authenticateduser"></a>SIDs::AuthenticatedUser  
 Retorna o SID SECURITY_AUTHENTICATED_USER_RID.  
```
CSid AuthenticatedUser() throw(...);
```  
  
##  <a name="backupops"></a>SIDs::BackupOps  
 Retorna o SID DOMAIN_ALIAS_RID_BACKUP_OPS.  
```
CSid BackupOps() throw(...);
```  
  
##  <a name="batch"></a>SIDs::batch  
 Retorna o SID SECURITY_BATCH_RID.  
```
CSid Batch() throw(...);
```  
  
##  <a name="creatorgroup"></a>SIDs::CreatorGroup  
 Retorna o SID SECURITY_CREATOR_GROUP_RID.  
```
CSid CreatorGroup() throw(...);
```  
  
##  <a name="creatorgroupserver"></a>SIDs::CreatorGroupServer  
 Retorna o SID SECURITY_CREATOR_GROUP_SERVER_RID.  
```
CSid CreatorGroupServer() throw(...);
```  
  
##  <a name="creatorowner"></a>SIDs::CreatorOwner  
 Retorna o SID SECURITY_CREATOR_OWNER_RID.  
```
CSid CreatorOwner() throw(...);
```  
  
##  <a name="creatorownerserver"></a>SIDs::CreatorOwnerServer  
 Retorna o SID SECURITY_CREATOR_OWNER_SERVER_RID.  
```
CSid CreatorOwnerServer() throw(...);
```  
  
##  <a name="dialup"></a>SIDs::dialup  
 Retorna o SID SECURITY_DIALUP_RID.  
```
CSid Dialup() throw(...);
```  
  
##  <a name="guests"></a>SIDs::Guests  
 Retorna o SID DOMAIN_ALIAS_RID_GUESTS.  
```
CSid Guests() throw(...);
```  
  
##  <a name="interactive"></a>SIDs::Interactive  
 Retorna o SID SECURITY_INTERACTIVE_RID.  
```
CSid Interactive() throw(...);
```  
  
##  <a name="local"></a>SIDs::local  
 Retorna o SID SECURITY_LOCAL_RID.  
```
CSid Local() throw(...);
```  
  
##  <a name="network"></a>SIDs::Network  
 Retorna o SID SECURITY_NETWORK_RID.  
```
CSid Network() throw(...);
```  
  
##  <a name="networkservice"></a>SIDs::NetworkService  
 Retorna o SID SECURITY_NETWORK_SERVICE_RID.  
```
CSid NetworkService() throw(...);
```  
  
### <a name="remarks"></a>Comentários  
 Use NetworkService para permitir que o usuário NT AUTHORITY\NetworkService ler um objeto de segurança CPerfMon. NetworkService adiciona um SecurityAttribute ao código ATLServer que permitirá que a DLL de logon na conta NetworkService em [!INCLUDE[WinXpFamily](../../atl/reference/includes/winxpfamily_md.md)] e sistema de operacional maior.  
  
 Quando os contadores de log personalizado são criados com a classe ATLServer CPerfMon no MMC Perfmon, os contadores podem não aparecer ao exibir o arquivo de log, embora eles sejam exibidos corretamente no modo de exibição em tempo real. Contadores de desempenho personalizados CPerfMon não tem as permissões necessárias para executar sob o serviço de "Logs e alertas de desempenho" (smlogsvc.exe) [!INCLUDE[WinXpFamily](../../atl/reference/includes/winxpfamily_md.md)] (ou superior) sistemas operacionais. Esse serviço é executado sob a conta "NT AUTHORITY\NetworkService".  
  
##  <a name="null"></a>SIDs::null  
 Retorna o SID SECURITY_NULL_RID.  
```
CSid Null() throw(...);
```  
  
##  <a name="prew2kaccess"></a>SIDs::PreW2KAccess  
 Retorna o SID DOMAIN_ALIAS_RID_PREW2KCOMPACCESS.  
```
CSid PreW2KAccess() throw(...);
```  
  
##  <a name="powerusers"></a>SIDs::PowerUsers  
 Retorna o SID DOMAIN_ALIAS_RID_POWER_USERS.  
```
CSid PowerUsers() throw(...);
```  
  
##  <a name="printops"></a>SIDs::PrintOps  
 Retorna o SID DOMAIN_ALIAS_RID_PRINT_OPS.  
```
CSid PrintOps() throw(...);
```  
  
##  <a name="proxy"></a>SIDs::proxy  
 Retorna o SID SECURITY_PROXY_RID.  
```
CSid Proxy() throw(...);
```  
  
##  <a name="rasservers"></a>SIDs::RasServers  
 Retorna o SID DOMAIN_ALIAS_RID_RAS_SERVERS.  
```
CSid RasServers() throw(...);
```  
  
##  <a name="replicator"></a>SIDs::Replicator  
 Retorna o SID DOMAIN_ALIAS_RID_REPLICATOR.  
```
CSid Replicator() throw(...);
```  
  
##  <a name="restrictedcode"></a>SIDs::RestrictedCode  
 Retorna o SID SECURITY_RESTRICTED_CODE_RID.  
```
CSid RestrictedCode() throw(...);
```  
  
##  <a name="self"></a>SIDs::Self  
 Retorna o SID SECURITY_PRINCIPAL_SELF_RID.  
```
CSid Self() throw(...);
```  
  
##  <a name="serverlogon"></a>SIDs::ServerLogon  
 Retorna o SID SECURITY_SERVER_LOGON_RID.  
```
CSid ServerLogon() throw(...);
```  
  
##  <a name="service"></a>SIDs::Service  
 Retorna o SID SECURITY_SERVICE_RID.  
```
CSid Service() throw(...);
```  
  
##  <a name="system"></a>SIDs::System  
 Retorna o SID SECURITY_LOCAL_SYSTEM_RID.  
```
CSid System() throw(...);
```  
  
##  <a name="systemops"></a>SIDs::SystemOps  
 Retorna o SID DOMAIN_ALIAS_RID_SYSTEM_OPS.  
```
CSid SystemOps() throw(...);
```  
  
##  <a name="terminalserver"></a>SIDs::terminalserver  
 Retorna o SID SECURITY_TERMINAL_SERVER_RID.  
```
CSid TerminalServer() throw(...);
```  
  
##  <a name="users"></a>SIDs::Users  
 Retorna o SID DOMAIN_ALIAS_RID_USERS.  
```
CSid Users() throw(...);
```  
  
##  <a name="world"></a>SIDs::World  
 Retorna o SID SECURITY_WORLD_RID.  
```
CSid World() throw(...);
```  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../atl/reference/atl-functions.md)
