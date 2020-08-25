---
title: Funções globais do identificador de segurança
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
ms.openlocfilehash: e040cbb76e851bd323360f4f5ae602f9c73651d1
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88834473"
---
# <a name="security-identifier-global-functions"></a>Funções globais do identificador de segurança

Essas funções retornam objetos SID conhecidos comuns.

> [!IMPORTANT]
> As funções listadas na tabela a seguir não podem ser usadas em aplicativos que são executados no Windows Runtime.

|Nome|Descrição|
|-|-|
|[Sids::AccountOps](#accountops)|Retorna o SID DOMAIN_ALIAS_RID_ACCOUNT_OPS.|
|[Sids::Admins](#admins)|Retorna o SID DOMAIN_ALIAS_RID_ADMINS.|
|[Sids::AnonymousLogon](#anonymouslogon)|Retorna o SID SECURITY_ANONYMOUS_LOGON_RID.|
|[Sids::AuthenticatedUser](#authenticateduser)|Retorna o SID SECURITY_AUTHENTICATED_USER_RID.|
|[Sids::BackupOps](#backupops)|Retorna o SID DOMAIN_ALIAS_RID_BACKUP_OPS.|
|[Sids::Batch](#batch)|Retorna o SID SECURITY_BATCH_RID.|
|[Sids::CreatorGroup](#creatorgroup)|Retorna o SID SECURITY_CREATOR_GROUP_RID.|
|[Sids::CreatorGroupServer](#creatorgroupserver)|Retorna o SID SECURITY_CREATOR_GROUP_SERVER_RID.|
|[Sids::CreatorOwner](#creatorowner)|Retorna o SID SECURITY_CREATOR_OWNER_RID.|
|[Sids::CreatorOwnerServer](#creatorownerserver)|Retorna o SID SECURITY_CREATOR_OWNER_SERVER_RID.|
|[Sids::Dialup](#dialup)|Retorna o SID SECURITY_DIALUP_RID.|
|[Sids::Guests](#guests)|Retorna o SID DOMAIN_ALIAS_RID_GUESTS.|
|[Sids::Interactive](#interactive)|Retorna o SID SECURITY_INTERACTIVE_RID.|
|[Sids::Local](#local)|Retorna o SID SECURITY_LOCAL_RID.|
|[Sids::Network](#network)|Retorna o SID SECURITY_NETWORK_RID.|
|[SIDs:: NetworkService](#networkservice)|Retorna o SID SECURITY_NETWORK_SERVICE_RID.|
|[Sids::Null](#null)|Retorna o SID SECURITY_NULL_RID.|
|[Sids::PreW2KAccess](#prew2kaccess)|Retorna o SID DOMAIN_ALIAS_RID_PREW2KCOMPACCESS.|
|[Sids::PowerUsers](#powerusers)|Retorna o SID DOMAIN_ALIAS_RID_POWER_USERS.|
|[Sids::PrintOps](#printops)|Retorna o SID DOMAIN_ALIAS_RID_PRINT_OPS.|
|[Sids::Proxy](#proxy)|Retorna o SID SECURITY_PROXY_RID.|
|[Sids::RasServers](#rasservers)|Retorna o SID DOMAIN_ALIAS_RID_RAS_SERVERS.|
|[Sids::Replicator](#replicator)|Retorna o SID DOMAIN_ALIAS_RID_REPLICATOR.|
|[Sids::RestrictedCode](#restrictedcode)|Retorna o SID SECURITY_RESTRICTED_CODE_RID.|
|[Sids::Self](#self)|Retorna o SID SECURITY_PRINCIPAL_SELF_RID.|
|[Sids::ServerLogon](#serverlogon)|Retorna o SID SECURITY_SERVER_LOGON_RID.|
|[Sids::Service](#service)|Retorna o SID SECURITY_SERVICE_RID.|
|[Sids::System](#system)|Retorna o SID SECURITY_LOCAL_SYSTEM_RID.|
|[Sids::SystemOps](#systemops)|Retorna o SID DOMAIN_ALIAS_RID_SYSTEM_OPS.|
|[Sids::TerminalServer](#terminalserver)|Retorna o SID SECURITY_TERMINAL_SERVER_RID.|
|[Sids::Users](#users)|Retorna o SID DOMAIN_ALIAS_RID_USERS.|
|[Sids::World](#world)|Retorna o SID SECURITY_WORLD_RID.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLSecurity. h

## <a name="sidsaccountops"></a><a name="accountops"></a> SIDs:: AccountOps

Retorna o SID DOMAIN_ALIAS_RID_ACCOUNT_OPS.

```
CSid AccountOps() throw(...);
```

## <a name="sidsadmins"></a><a name="admins"></a> SIDs:: admins

Retorna o SID DOMAIN_ALIAS_RID_ADMINS.

```
CSid Admins() throw(...);
```

## <a name="sidsanonymouslogon"></a><a name="anonymouslogon"></a> SIDs:: AnonymousLogon

Retorna o SID SECURITY_ANONYMOUS_LOGON_RID.

```
CSid AnonymousLogon() throw(...);
```

## <a name="sidsauthenticateduser"></a><a name="authenticateduser"></a> SIDs:: AuthenticatedUser

Retorna o SID SECURITY_AUTHENTICATED_USER_RID.

```
CSid AuthenticatedUser() throw(...);
```

## <a name="sidsbackupops"></a><a name="backupops"></a> SIDs:: BackupOps

Retorna o SID DOMAIN_ALIAS_RID_BACKUP_OPS.

```
CSid BackupOps() throw(...);
```

## <a name="sidsbatch"></a><a name="batch"></a> SIDs:: batch

Retorna o SID SECURITY_BATCH_RID.

```
CSid Batch() throw(...);
```

## <a name="sidscreatorgroup"></a><a name="creatorgroup"></a> SIDs:: Creator

Retorna o SID SECURITY_CREATOR_GROUP_RID.

```
CSid CreatorGroup() throw(...);
```

## <a name="sidscreatorgroupserver"></a><a name="creatorgroupserver"></a> SIDs:: CreatorGroupServer

Retorna o SID SECURITY_CREATOR_GROUP_SERVER_RID.

```
CSid CreatorGroupServer() throw(...);
```

## <a name="sidscreatorowner"></a><a name="creatorowner"></a> SIDs:: CreatorOwner

Retorna o SID SECURITY_CREATOR_OWNER_RID.

```
CSid CreatorOwner() throw(...);
```

## <a name="sidscreatorownerserver"></a><a name="creatorownerserver"></a> SIDs:: CreatorOwnerServer

Retorna o SID SECURITY_CREATOR_OWNER_SERVER_RID.

```
CSid CreatorOwnerServer() throw(...);
```

## <a name="sidsdialup"></a><a name="dialup"></a> SIDs::D ialup

Retorna o SID SECURITY_DIALUP_RID.

```
CSid Dialup() throw(...);
```

## <a name="sidsguests"></a><a name="guests"></a> SIDs:: convidados

Retorna o SID DOMAIN_ALIAS_RID_GUESTS.

```
CSid Guests() throw(...);
```

## <a name="sidsinteractive"></a><a name="interactive"></a> SIDs:: Interactive

Retorna o SID SECURITY_INTERACTIVE_RID.

```
CSid Interactive() throw(...);
```

## <a name="sidslocal"></a><a name="local"></a> SIDs:: local

Retorna o SID SECURITY_LOCAL_RID.

```
CSid Local() throw(...);
```

## <a name="sidsnetwork"></a><a name="network"></a> SIDs:: Network

Retorna o SID SECURITY_NETWORK_RID.

```
CSid Network() throw(...);
```

## <a name="sidsnetworkservice"></a><a name="networkservice"></a> SIDs:: NetworkService

Retorna o SID SECURITY_NETWORK_SERVICE_RID.

```
CSid NetworkService() throw(...);
```

### <a name="remarks"></a>Comentários

Use o NetworkService para permitir que o usuário NT AUTHORITY\NetworkService Leia um objeto de segurança CPerfMon. O NetworkService adiciona um SecurityAttribute ao código ATLServer, que permitirá que a DLL faça logon na conta NetworkService no Windows XP Home Edition, no Windows XP Professional, no Windows Server 2003 e em um sistema operacional superior.

Quando os contadores de log personalizados são criados com a classe ATLServer CPerfMon no perfmon MMC, os contadores podem não aparecer ao exibir o arquivo de log, embora eles apareçam corretamente no modo de exibição em tempo real. CPerfMon os contadores de desempenho personalizados não têm as permissões necessárias para executar no serviço "Logs e Alertas de Desempenho" (smlogsvc.exe) nos sistemas operacionais Windows XP Home Edition, Windows XP Professional, Windows Server 2003 (ou superior). Esse serviço é executado na conta "NT AUTHORITY\NetworkService".

## <a name="sidsnull"></a><a name="null"></a> SIDs:: NULL

Retorna o SID SECURITY_NULL_RID.

```
CSid Null() throw(...);
```

## <a name="sidsprew2kaccess"></a><a name="prew2kaccess"></a> SIDs::P reW2KAccess

Retorna o SID DOMAIN_ALIAS_RID_PREW2KCOMPACCESS.

```
CSid PreW2KAccess() throw(...);
```

## <a name="sidspowerusers"></a><a name="powerusers"></a> SIDs::P owerUsers

Retorna o SID DOMAIN_ALIAS_RID_POWER_USERS.

```
CSid PowerUsers() throw(...);
```

## <a name="sidsprintops"></a><a name="printops"></a> SIDs::P rintOps

Retorna o SID DOMAIN_ALIAS_RID_PRINT_OPS.

```
CSid PrintOps() throw(...);
```

## <a name="sidsproxy"></a><a name="proxy"></a> SIDs::P Roxy

Retorna o SID SECURITY_PROXY_RID.

```
CSid Proxy() throw(...);
```

## <a name="sidsrasservers"></a><a name="rasservers"></a> SIDs:: RasServers

Retorna o SID DOMAIN_ALIAS_RID_RAS_SERVERS.

```
CSid RasServers() throw(...);
```

## <a name="sidsreplicator"></a><a name="replicator"></a> SIDs:: Replicator

Retorna o SID DOMAIN_ALIAS_RID_REPLICATOR.

```
CSid Replicator() throw(...);
```

## <a name="sidsrestrictedcode"></a><a name="restrictedcode"></a> SIDs:: RestrictedCode

Retorna o SID SECURITY_RESTRICTED_CODE_RID.

```
CSid RestrictedCode() throw(...);
```

## <a name="sidsself"></a><a name="self"></a> SIDs:: Self

Retorna o SID SECURITY_PRINCIPAL_SELF_RID.

```
CSid Self() throw(...);
```

## <a name="sidsserverlogon"></a><a name="serverlogon"></a> SIDs:: ServerLogon

Retorna o SID SECURITY_SERVER_LOGON_RID.

```
CSid ServerLogon() throw(...);
```

## <a name="sidsservice"></a><a name="service"></a> SIDs:: Service

Retorna o SID SECURITY_SERVICE_RID.

```
CSid Service() throw(...);
```

## <a name="sidssystem"></a><a name="system"></a> SIDs:: System

Retorna o SID SECURITY_LOCAL_SYSTEM_RID.

```
CSid System() throw(...);
```

## <a name="sidssystemops"></a><a name="systemops"></a> SIDs:: SystemOps

Retorna o SID DOMAIN_ALIAS_RID_SYSTEM_OPS.

```
CSid SystemOps() throw(...);
```

## <a name="sidsterminalserver"></a><a name="terminalserver"></a> SIDs:: TerminalServer

Retorna o SID SECURITY_TERMINAL_SERVER_RID.

```
CSid TerminalServer() throw(...);
```

## <a name="sidsusers"></a><a name="users"></a> SIDs:: usuários

Retorna o SID DOMAIN_ALIAS_RID_USERS.

```
CSid Users() throw(...);
```

## <a name="sidsworld"></a><a name="world"></a> SIDs:: World

Retorna o SID SECURITY_WORLD_RID.

```
CSid World() throw(...);
```

## <a name="see-also"></a>Confira também

[Funções](../../atl/reference/atl-functions.md)
