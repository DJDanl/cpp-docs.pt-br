---
title: Funções globais de identificador de segurança
ms.date: 11/04/2016
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
helpviewer_keywords:
- security IDs [C++]
- SIDs [C++], returning SID objects
ms.assetid: 85404dcb-c59b-4535-ab3d-66cfa37e87de
ms.openlocfilehash: ab5d743c7c6abf7ee3a849a28916ebd32788ef40
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62274939"
---
# <a name="security-identifier-global-functions"></a>Funções globais de identificador de segurança

Essas funções retornam objetos de SID bem conhecido comuns.

> [!IMPORTANT]
>  As funções listadas na tabela a seguir não podem ser usadas em aplicativos executados no tempo de execução do Windows.

|||
|-|-|
|[Sids::AccountOps](#accountops)|Retorna o SID DOMAIN_ALIAS_RID_ACCOUNT_OPS.|
|[SIDs::Admins](#admins)|Retorna o SID DOMAIN_ALIAS_RID_ADMINS.|
|[Sids::AnonymousLogon](#anonymouslogon)|Retorna o SID SECURITY_ANONYMOUS_LOGON_RID.|
|[Sids::AuthenticatedUser](#authenticateduser)|Retorna o SID SECURITY_AUTHENTICATED_USER_RID.|
|[SIDs::BackupOps](#backupops)|Retorna o SID DOMAIN_ALIAS_RID_BACKUP_OPS.|
|[Sids::Batch](#batch)|Retorna o SID SECURITY_BATCH_RID.|
|[Sids::CreatorGroup](#creatorgroup)|Retorna o SID SECURITY_CREATOR_GROUP_RID.|
|[Sids::CreatorGroupServer](#creatorgroupserver)|Retorna o SID SECURITY_CREATOR_GROUP_SERVER_RID.|
|[Sids::CreatorOwner](#creatorowner)|Retorna o SID SECURITY_CREATOR_OWNER_RID.|
|[Sids::CreatorOwnerServer](#creatorownerserver)|Retorna o SID SECURITY_CREATOR_OWNER_SERVER_RID.|
|[SIDs::dialup](#dialup)|Retorna o SID SECURITY_DIALUP_RID.|
|[SIDs::Guests](#guests)|Retorna o SID DOMAIN_ALIAS_RID_GUESTS.|
|[Sids::Interactive](#interactive)|Retorna o SID SECURITY_INTERACTIVE_RID.|
|[Sids::Local](#local)|Retorna o SID SECURITY_LOCAL_RID.|
|[Sids::Network](#network)|Retorna o SID SECURITY_NETWORK_RID.|
|[Sids::NetworkService](#networkservice)|Retorna o SID SECURITY_NETWORK_SERVICE_RID.|
|[Sids::Null](#null)|Retorna o SID SECURITY_NULL_RID.|
|[Sids::PreW2KAccess](#prew2kaccess)|Retorna o SID DOMAIN_ALIAS_RID_PREW2KCOMPACCESS.|
|[SIDs::PowerUsers](#powerusers)|Retorna o SID DOMAIN_ALIAS_RID_POWER_USERS.|
|[Sids::PrintOps](#printops)|Retorna o SID DOMAIN_ALIAS_RID_PRINT_OPS.|
|[SIDs::proxy](#proxy)|Retorna o SID SECURITY_PROXY_RID.|
|[Sids::RasServers](#rasservers)|Retorna o SID DOMAIN_ALIAS_RID_RAS_SERVERS.|
|[Sids::Replicator](#replicator)|Retorna o SID DOMAIN_ALIAS_RID_REPLICATOR.|
|[Sids::RestrictedCode](#restrictedcode)|Retorna o SID SECURITY_RESTRICTED_CODE_RID.|
|[Sids::Self](#self)|Retorna o SID SECURITY_PRINCIPAL_SELF_RID.|
|[Sids::ServerLogon](#serverlogon)|Retorna o SID SECURITY_SERVER_LOGON_RID.|
|[SIDs::Service](#service)|Retorna o SID SECURITY_SERVICE_RID.|
|[SIDs::System](#system)|Retorna o SID SECURITY_LOCAL_SYSTEM_RID.|
|[Sids::SystemOps](#systemops)|Retorna o SID DOMAIN_ALIAS_RID_SYSTEM_OPS.|
|[Sids::TerminalServer](#terminalserver)|Retorna o SID SECURITY_TERMINAL_SERVER_RID.|
|[SIDs::Users](#users)|Retorna o SID DOMAIN_ALIAS_RID_USERS.|
|[Sids::World](#world)|Retorna o SID SECURITY_WORLD_RID.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsecurity. h

##  <a name="accountops"></a>  Sids::AccountOps

Retorna o SID DOMAIN_ALIAS_RID_ACCOUNT_OPS.

```
CSid AccountOps() throw(...);
```

##  <a name="admins"></a>  Sids::Admins

Retorna o SID DOMAIN_ALIAS_RID_ADMINS.

```
CSid Admins() throw(...);
```

##  <a name="anonymouslogon"></a>  SIDs::AnonymousLogon

Retorna o SID SECURITY_ANONYMOUS_LOGON_RID.

```
CSid AnonymousLogon() throw(...);
```

##  <a name="authenticateduser"></a>  Sids::AuthenticatedUser

Retorna o SID SECURITY_AUTHENTICATED_USER_RID.

```
CSid AuthenticatedUser() throw(...);
```

##  <a name="backupops"></a>  Sids::BackupOps

Retorna o SID DOMAIN_ALIAS_RID_BACKUP_OPS.

```
CSid BackupOps() throw(...);
```

##  <a name="batch"></a>  Sids::Batch

Retorna o SID SECURITY_BATCH_RID.

```
CSid Batch() throw(...);
```

##  <a name="creatorgroup"></a>  Sids::CreatorGroup

Retorna o SID SECURITY_CREATOR_GROUP_RID.

```
CSid CreatorGroup() throw(...);
```

##  <a name="creatorgroupserver"></a>  Sids::CreatorGroupServer

Retorna o SID SECURITY_CREATOR_GROUP_SERVER_RID.

```
CSid CreatorGroupServer() throw(...);
```

##  <a name="creatorowner"></a>  Sids::CreatorOwner

Retorna o SID SECURITY_CREATOR_OWNER_RID.

```
CSid CreatorOwner() throw(...);
```

##  <a name="creatorownerserver"></a>  Sids::CreatorOwnerServer

Retorna o SID SECURITY_CREATOR_OWNER_SERVER_RID.

```
CSid CreatorOwnerServer() throw(...);
```

##  <a name="dialup"></a>  Sids::Dialup

Retorna o SID SECURITY_DIALUP_RID.

```
CSid Dialup() throw(...);
```

##  <a name="guests"></a>  Sids::Guests

Retorna o SID DOMAIN_ALIAS_RID_GUESTS.

```
CSid Guests() throw(...);
```

##  <a name="interactive"></a>  Sids::Interactive

Retorna o SID SECURITY_INTERACTIVE_RID.

```
CSid Interactive() throw(...);
```

##  <a name="local"></a>  Sids::Local

Retorna o SID SECURITY_LOCAL_RID.

```
CSid Local() throw(...);
```

##  <a name="network"></a>  Sids::Network

Retorna o SID SECURITY_NETWORK_RID.

```
CSid Network() throw(...);
```

##  <a name="networkservice"></a>  Sids::NetworkService

Retorna o SID SECURITY_NETWORK_SERVICE_RID.

```
CSid NetworkService() throw(...);
```

### <a name="remarks"></a>Comentários

Use o NetworkService para permitir que o usuário NT AUTHORITY\NetworkService ler um objeto de segurança CPerfMon. NetworkService adiciona um SecurityAttribute ao código ATLServer que permitirá que a DLL de logon na conta NetworkService no Windows XP Home Edition, Windows XP Professional, Windows Server 2003 e o sistema de operacional maior.

Quando os contadores de log personalizado são criados com a classe ATLServer CPerfMon no MMC do Perfmon, os contadores podem não aparecer ao exibir o arquivo de log, embora eles sejam exibidos corretamente no modo de exibição em tempo real. Contadores de desempenho personalizados CPerfMon não tem as permissões necessárias para executar sob o serviço de "Logs e alertas de desempenho" (smlogsvc.exe) no Windows XP Home Edition, Windows XP Professional, Windows Server 2003 (ou posterior) de sistemas de operacionais. Esse serviço é executado sob a conta "NT AUTHORITY\NetworkService".

##  <a name="null"></a>  Sids::Null

Retorna o SID SECURITY_NULL_RID.

```
CSid Null() throw(...);
```

##  <a name="prew2kaccess"></a>  Sids::PreW2KAccess

Retorna o SID DOMAIN_ALIAS_RID_PREW2KCOMPACCESS.

```
CSid PreW2KAccess() throw(...);
```

##  <a name="powerusers"></a>  SIDs::PowerUsers

Retorna o SID DOMAIN_ALIAS_RID_POWER_USERS.

```
CSid PowerUsers() throw(...);
```

##  <a name="printops"></a>  Sids::PrintOps

Retorna o SID DOMAIN_ALIAS_RID_PRINT_OPS.

```
CSid PrintOps() throw(...);
```

##  <a name="proxy"></a>  SIDs::proxy

Retorna o SID SECURITY_PROXY_RID.

```
CSid Proxy() throw(...);
```

##  <a name="rasservers"></a>  Sids::RasServers

Retorna o SID DOMAIN_ALIAS_RID_RAS_SERVERS.

```
CSid RasServers() throw(...);
```

##  <a name="replicator"></a>  Sids::Replicator

Retorna o SID DOMAIN_ALIAS_RID_REPLICATOR.

```
CSid Replicator() throw(...);
```

##  <a name="restrictedcode"></a>  Sids::RestrictedCode

Retorna o SID SECURITY_RESTRICTED_CODE_RID.

```
CSid RestrictedCode() throw(...);
```

##  <a name="self"></a>  Sids::Self

Retorna o SID SECURITY_PRINCIPAL_SELF_RID.

```
CSid Self() throw(...);
```

##  <a name="serverlogon"></a>  Sids::ServerLogon

Retorna o SID SECURITY_SERVER_LOGON_RID.

```
CSid ServerLogon() throw(...);
```

##  <a name="service"></a>  Sids::Service

Retorna o SID SECURITY_SERVICE_RID.

```
CSid Service() throw(...);
```

##  <a name="system"></a>  SIDs::System

Retorna o SID SECURITY_LOCAL_SYSTEM_RID.

```
CSid System() throw(...);
```

##  <a name="systemops"></a>  Sids::SystemOps

Retorna o SID DOMAIN_ALIAS_RID_SYSTEM_OPS.

```
CSid SystemOps() throw(...);
```

##  <a name="terminalserver"></a>  Sids::TerminalServer

Retorna o SID SECURITY_TERMINAL_SERVER_RID.

```
CSid TerminalServer() throw(...);
```

##  <a name="users"></a>  SIDs::Users

Retorna o SID DOMAIN_ALIAS_RID_USERS.

```
CSid Users() throw(...);
```

##  <a name="world"></a>  Sids::World

Retorna o SID SECURITY_WORLD_RID.

```
CSid World() throw(...);
```

## <a name="see-also"></a>Consulte também

[Funções](../../atl/reference/atl-functions.md)
