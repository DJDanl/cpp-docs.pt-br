---
title: "Funções globais de identificador de segurança | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- security IDs [C++]
- SIDs [C++], returning SID objects
ms.assetid: 85404dcb-c59b-4535-ab3d-66cfa37e87de
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
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: 9e51fe30b0519514df34f1a77b1e731f51047520
ms.lasthandoff: 02/25/2017

---
# <a name="security-identifier-global-functions"></a>Funções globais de identificador de segurança
Essas funções retornam objetos de SID conhecido comuns.  
  
> [!IMPORTANT]
>  As funções listadas na tabela a seguir não podem ser usadas em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
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
 **Cabeçalho:** atlsecurity. h 

##  <a name="a-nameaccountopsa--sidsaccountops"></a><a name="accountops"></a>SIDs::AccountOps  
 Retorna o SID DOMAIN_ALIAS_RID_ACCOUNT_OPS.    
  
```
CSid AccountOps() throw(...);
```  
  
##  <a name="a-nameadminsa--sidsadmins"></a><a name="admins"></a>SIDs::Admins  
 Retorna o SID DOMAIN_ALIAS_RID_ADMINS.  
```
CSid Admins() throw(...);
```  
  
##  <a name="a-nameanonymouslogona--sidsanonymouslogon"></a><a name="anonymouslogon"></a>SIDs::AnonymousLogon  
 Retorna o SID SECURITY_ANONYMOUS_LOGON_RID.  
```
CSid AnonymousLogon() throw(...);
```  
  
##  <a name="a-nameauthenticatedusera--sidsauthenticateduser"></a><a name="authenticateduser"></a>SIDs::AuthenticatedUser  
 Retorna o SID SECURITY_AUTHENTICATED_USER_RID.  
```
CSid AuthenticatedUser() throw(...);
```  
  
##  <a name="a-namebackupopsa--sidsbackupops"></a><a name="backupops"></a>SIDs::BackupOps  
 Retorna o SID DOMAIN_ALIAS_RID_BACKUP_OPS.  
```
CSid BackupOps() throw(...);
```  
  
##  <a name="a-namebatcha--sidsbatch"></a><a name="batch"></a>SIDs::batch  
 Retorna o SID SECURITY_BATCH_RID.  
```
CSid Batch() throw(...);
```  
  
##  <a name="a-namecreatorgroupa--sidscreatorgroup"></a><a name="creatorgroup"></a>SIDs::CreatorGroup  
 Retorna o SID SECURITY_CREATOR_GROUP_RID.  
```
CSid CreatorGroup() throw(...);
```  
  
##  <a name="a-namecreatorgroupservera--sidscreatorgroupserver"></a><a name="creatorgroupserver"></a>SIDs::CreatorGroupServer  
 Retorna o SID SECURITY_CREATOR_GROUP_SERVER_RID.  
```
CSid CreatorGroupServer() throw(...);
```  
  
##  <a name="a-namecreatorownera--sidscreatorowner"></a><a name="creatorowner"></a>SIDs::CreatorOwner  
 Retorna o SID SECURITY_CREATOR_OWNER_RID.  
```
CSid CreatorOwner() throw(...);
```  
  
##  <a name="a-namecreatorownerservera--sidscreatorownerserver"></a><a name="creatorownerserver"></a>SIDs::CreatorOwnerServer  
 Retorna o SID SECURITY_CREATOR_OWNER_SERVER_RID.  
```
CSid CreatorOwnerServer() throw(...);
```  
  
##  <a name="a-namedialupa--sidsdialup"></a><a name="dialup"></a>SIDs::dialup  
 Retorna o SID SECURITY_DIALUP_RID.  
```
CSid Dialup() throw(...);
```  
  
##  <a name="a-nameguestsa--sidsguests"></a><a name="guests"></a>SIDs::Guests  
 Retorna o SID DOMAIN_ALIAS_RID_GUESTS.  
```
CSid Guests() throw(...);
```  
  
##  <a name="a-nameinteractivea--sidsinteractive"></a><a name="interactive"></a>SIDs::Interactive  
 Retorna o SID SECURITY_INTERACTIVE_RID.  
```
CSid Interactive() throw(...);
```  
  
##  <a name="a-namelocala--sidslocal"></a><a name="local"></a>SIDs::local  
 Retorna o SID SECURITY_LOCAL_RID.  
```
CSid Local() throw(...);
```  
  
##  <a name="a-namenetworka--sidsnetwork"></a><a name="network"></a>SIDs::Network  
 Retorna o SID SECURITY_NETWORK_RID.  
```
CSid Network() throw(...);
```  
  
##  <a name="a-namenetworkservicea--sidsnetworkservice"></a><a name="networkservice"></a>SIDs::NetworkService  
 Retorna o SID SECURITY_NETWORK_SERVICE_RID.  
```
CSid NetworkService() throw(...);
```  
  
### <a name="remarks"></a>Comentários  
 Use NetworkService para permitir que o usuário NT AUTHORITY\NetworkService ler um objeto de segurança CPerfMon. NetworkService adiciona uma SecurityAttribute ao código ATLServer que permitirá que a DLL de logon na conta NetworkService no [!INCLUDE[WinXpFamily](../../atl/reference/includes/winxpfamily_md.md)] e maior do sistema operacional.  
  
 Quando os contadores de log personalizado são criados com a classe ATLServer CPerfMon no MMC do Perfmon, os contadores podem não aparecer ao exibir o arquivo de log, embora eles sejam exibidos corretamente no modo de exibição em tempo real. Contadores de desempenho personalizados CPerfMon não tem as permissões necessárias para executar o serviço 'Logs e alertas de desempenho "(smlogsvc.exe) [!INCLUDE[WinXpFamily](../../atl/reference/includes/winxpfamily_md.md)] (ou superior) sistemas operacionais. Esse serviço é executado sob a conta "NT AUTHORITY\NetworkService".  
  
##  <a name="a-namenulla--sidsnull"></a><a name="null"></a>SIDs::null  
 Retorna o SID SECURITY_NULL_RID.  
```
CSid Null() throw(...);
```  
  
##  <a name="a-nameprew2kaccessa--sidsprew2kaccess"></a><a name="prew2kaccess"></a>SIDs::PreW2KAccess  
 Retorna o SID DOMAIN_ALIAS_RID_PREW2KCOMPACCESS.  
```
CSid PreW2KAccess() throw(...);
```  
  
##  <a name="a-namepowerusersa--sidspowerusers"></a><a name="powerusers"></a>SIDs::PowerUsers  
 Retorna o SID DOMAIN_ALIAS_RID_POWER_USERS.  
```
CSid PowerUsers() throw(...);
```  
  
##  <a name="a-nameprintopsa--sidsprintops"></a><a name="printops"></a>SIDs::PrintOps  
 Retorna o SID DOMAIN_ALIAS_RID_PRINT_OPS.  
```
CSid PrintOps() throw(...);
```  
  
##  <a name="a-nameproxya--sidsproxy"></a><a name="proxy"></a>SIDs::proxy  
 Retorna o SID SECURITY_PROXY_RID.  
```
CSid Proxy() throw(...);
```  
  
##  <a name="a-namerasserversa--sidsrasservers"></a><a name="rasservers"></a>SIDs::RasServers  
 Retorna o SID DOMAIN_ALIAS_RID_RAS_SERVERS.  
```
CSid RasServers() throw(...);
```  
  
##  <a name="a-namereplicatora--sidsreplicator"></a><a name="replicator"></a>SIDs::Replicator  
 Retorna o SID DOMAIN_ALIAS_RID_REPLICATOR.  
```
CSid Replicator() throw(...);
```  
  
##  <a name="a-namerestrictedcodea--sidsrestrictedcode"></a><a name="restrictedcode"></a>SIDs::RestrictedCode  
 Retorna o SID SECURITY_RESTRICTED_CODE_RID.  
```
CSid RestrictedCode() throw(...);
```  
  
##  <a name="a-nameselfa--sidsself"></a><a name="self"></a>SIDs::Self  
 Retorna o SID SECURITY_PRINCIPAL_SELF_RID.  
```
CSid Self() throw(...);
```  
  
##  <a name="a-nameserverlogona--sidsserverlogon"></a><a name="serverlogon"></a>SIDs::ServerLogon  
 Retorna o SID SECURITY_SERVER_LOGON_RID.  
```
CSid ServerLogon() throw(...);
```  
  
##  <a name="a-nameservicea--sidsservice"></a><a name="service"></a>SIDs::Service  
 Retorna o SID SECURITY_SERVICE_RID.  
```
CSid Service() throw(...);
```  
  
##  <a name="a-namesystema--sidssystem"></a><a name="system"></a>SIDs::System  
 Retorna o SID SECURITY_LOCAL_SYSTEM_RID.  
```
CSid System() throw(...);
```  
  
##  <a name="a-namesystemopsa--sidssystemops"></a><a name="systemops"></a>SIDs::SystemOps  
 Retorna o SID DOMAIN_ALIAS_RID_SYSTEM_OPS.  
```
CSid SystemOps() throw(...);
```  
  
##  <a name="a-nameterminalservera--sidsterminalserver"></a><a name="terminalserver"></a>SIDs::terminalserver  
 Retorna o SID SECURITY_TERMINAL_SERVER_RID.  
```
CSid TerminalServer() throw(...);
```  
  
##  <a name="a-nameusersa--sidsusers"></a><a name="users"></a>SIDs::Users  
 Retorna o SID DOMAIN_ALIAS_RID_USERS.  
```
CSid Users() throw(...);
```  
  
##  <a name="a-nameworlda--sidsworld"></a><a name="world"></a>SIDs::World  
 Retorna o SID SECURITY_WORLD_RID.  
```
CSid World() throw(...);
```  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../atl/reference/atl-functions.md)

