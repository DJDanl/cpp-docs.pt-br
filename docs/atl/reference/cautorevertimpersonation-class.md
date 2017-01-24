---
title: "Classe de CAutoRevertImpersonation | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "ATL::CAutoRevertImpersonation"
  - "CAutoRevertImpersonation"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAutoRevertImpersonation"
ms.assetid: 43732849-1940-4bd4-9d52-7a5698bb8838
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAutoRevertImpersonation
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe retornar objetos de [CAccessToken](../Topic/CAccessToken%20Class.md) a um estado nonimpersonating quando sai do escopo.  
  
## Sintaxe  
  
```  
  
class CAutoRevertImpersonation  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAutoRevertImpersonation::CAutoRevertImpersonation](../Topic/CAutoRevertImpersonation::CAutoRevertImpersonation.md)|Constrói um objeto de `CAutoRevertImpersonation`|  
|[CAutoRevertImpersonation::~CAutoRevertImpersonation](../Topic/CAutoRevertImpersonation::~CAutoRevertImpersonation.md)|Destrói o objeto e reverter a representação do token de acesso.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAutoRevertImpersonation::Attach](../Topic/CAutoRevertImpersonation::Attach.md)|Automatiza a reversão de representação de um token de acesso.|  
|[CAutoRevertImpersonation::Detach](../Topic/CAutoRevertImpersonation::Detach.md)|Cancela a reversão automática de representação.|  
|[CAutoRevertImpersonation::GetAccessToken](../Topic/CAutoRevertImpersonation::GetAccessToken.md)|Obtém a atual do token de acesso associada a este objeto.|  
  
## Comentários  
 [token de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374909) é um objeto que descreve o contexto de segurança de um processo ou de um segmento e é atribuído a cada usuário efetuado logon em um sistema do Windows NT 2000 ou Windows.  Estes tokens de acesso podem ser representados com a classe de `CAccessToken` .  
  
 A as vezes é necessário representar símbolos de acesso.  Essa classe é fornecida como uma conveniência, mas não executa a representação dos tokens de acesso; executa somente a reversão automático para um estado nonimpersonated.  Isso ocorre porque a representação de token de acesso pode ser executada várias maneiras diferentes.  
  
 Para obter uma introdução ao modelo de controle de acesso no windows, consulte [controle de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374860) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## Requisitos  
 **Cabeçalho:** atlsecurity.h  
  
## Consulte também  
 [exemplo de ATLSecurity](../../top/visual-cpp-samples.md)   
 [Access Tokens](http://msdn.microsoft.com/library/windows/desktop/aa374909)   
 [Visão geral de classe](../../atl/atl-class-overview.md)