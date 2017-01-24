---
title: "Classe de CSid | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CSid"
  - "ATL::CSid"
  - "ATL.CSid"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSid"
ms.assetid: be58b7ca-5958-49c3-a833-ca341aaaf753
caps.latest.revision: 24
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSid
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe é um wrapper para uma estrutura de `SID` \(identificador de segurança\).  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class CSid  
  
```  
  
## Membros  
  
### Typedefs público  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSid::CSidArray](../Topic/CSid::CSidArray.md)|Uma matriz de objetos de `CSid` .|  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSid::CSid](../Topic/CSid::CSid.md)|o construtor.|  
|[CSid::~CSid](../Topic/CSid::~CSid.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSid::AccountName](../Topic/CSid::AccountName.md)|Retorna o nome da conta associada com o objeto de `CSid` .|  
|[CSid::Domain](../Topic/CSid::Domain.md)|Retorna o nome do domínio associado ao objeto de `CSid` .|  
|[CSid::EqualPrefix](../Topic/CSid::EqualPrefix.md)|Testa prefixos de `SID` \(identificador de segurança\) para igualdade.|  
|[CSid::GetLength](../Topic/CSid::GetLength.md)|Retorna o comprimento do objeto de `CSid` .|  
|[CSid::GetPSID](../Topic/CSid::GetPSID.md)|Retorna um ponteiro a estrutura de `SID` .|  
|[CSid::GetPSID\_IDENTIFIER\_AUTHORITY](../Topic/CSid::GetPSID_IDENTIFIER_AUTHORITY.md)|Retorna um ponteiro para a estrutura de **SID\_IDENTIFIER\_AUTHORITY** .|  
|[CSid::GetSubAuthority](../Topic/CSid::GetSubAuthority.md)|Retorna um subauthority especificado em uma estrutura de **SID** .|  
|[CSid::GetSubAuthorityCount](../Topic/CSid::GetSubAuthorityCount.md)|Retorna o número de subauthority.|  
|[CSid::IsValid](../Topic/CSid::IsValid.md)|Testar o objeto de `CSid` validade.|  
|[CSid::LoadAccount](../Topic/CSid::LoadAccount.md)|Atualiza o objeto de `CSid` dado o nome e o domínio de conta existente, ou uma estrutura de `SID` .|  
|[CSid::Sid](../Topic/CSid::Sid.md)|Retorna a cadeia de caracteres de identificação.|  
|[CSid::SidNameUse](../Topic/CSid::SidNameUse.md)|Retorna uma descrição do estado do objeto de `CSid` .|  
  
### Operadores  
  
|||  
|-|-|  
|[operador \=](../Topic/CSid::operator%20=.md)|Operador de atribuição.|  
|[const SID de operador \*](../Topic/CSid::operator%20const%20SID%20*.md)|Converte um objeto de `CSid` a um ponteiro a estrutura de `SID` .|  
  
### Operadores globais  
  
|||  
|-|-|  
|[\=\= de operador](../Topic/CSid::operator%20==.md)|Testando dois objetos de descritor de segurança para igualdade|  
|[operador\! \=](../Topic/CSid::operator%20!=.md)|Testando dois objetos de descritor de segurança para desigualdade|  
|[operador \<](../Topic/CSid::operator%20%3C.md)|Compara um valor relativo dos dois objetos de descritor de segurança.|  
|[operador \>](../Topic/CSid::operator%20%3E.md)|Compara um valor relativo dos dois objetos de descritor de segurança.|  
|[\<\= de operador](../Topic/CSid::operator%20%3C=.md)|Compara um valor relativo dos dois objetos de descritor de segurança.|  
|[\>\= de operador](../Topic/CSid::operator%20%3E=.md)|Compara um valor relativo dos dois objetos de descritor de segurança.|  
  
## Comentários  
 A estrutura de `SID` é uma estrutura de comprimento variável usada para identificar exclusivamente usuários ou grupos.  
  
 Aplicativos não devem alterar a estrutura de `SID` diretamente, mas usar o marcador os métodos fornecidos em esta classe envoltório.  Consulte também [AtlGetOwnerSid](../Topic/AtlGetOwnerSid.md), [AtlSetGroupSid](../Topic/AtlSetGroupSid.md), [AtlGetGroupSid](../Topic/AtlGetGroupSid.md), e [AtlSetOwnerSid](../Topic/AtlSetOwnerSid.md).  
  
 Para obter uma introdução ao modelo de controle de acesso no windows, consulte [controle de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374860) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## Requisitos  
 **Cabeçalho:** atlsecurity.h  
  
## Consulte também  
 [Exemplo de segurança](../../top/visual-cpp-samples.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Funções de segurança globais](../../atl/reference/security-global-functions.md)   
 [Referência alfabética dos operadores](../../atl/reference/atl-operators.md)