---
title: "Classe de CTokenGroups | Microsoft Docs"
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
  - "ATL::CTokenGroups"
  - "ATL.CTokenGroups"
  - "CTokenGroups"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CTokenGroups"
ms.assetid: 2ab08076-4b08-4487-bc70-ec6dee304190
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CTokenGroups
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe é um wrapper para a estrutura de **TOKEN\_GROUPS** .  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class CTokenGroups  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CTokenGroups::CTokenGroups](../Topic/CTokenGroups::CTokenGroups.md)|o construtor.|  
|[CTokenGroups::~CTokenGroups](../Topic/CTokenGroups::~CTokenGroups.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CTokenGroups::Add](../Topic/CTokenGroups::Add.md)|Adiciona `CSid` ou estrutura existente de **TOKEN\_GROUPS** ao objeto de `CTokenGroups` .|  
|[CTokenGroups::Delete](../Topic/CTokenGroups::Delete.md)|Exclui `CSid` e seus atributos associados do objeto de `CTokenGroups` .|  
|[CTokenGroups::DeleteAll](../Topic/CTokenGroups::DeleteAll.md)|Exclui todos os objetos de `CSid` e seus atributos associados do objeto de `CTokenGroups` .|  
|[CTokenGroups::GetCount](../Topic/CTokenGroups::GetCount.md)|Retorna o número de objetos de `CSid` e atributos associados contidos no objeto de **CTokenGroups** .|  
|[CTokenGroups::GetLength](../Topic/CTokenGroups::GetLength.md)|Retorna o tamanho do objeto de `CTokenGroups` .|  
|[CTokenGroups::GetPTOKEN\_GROUPS](../Topic/CTokenGroups::GetPTOKEN_GROUPS.md)|Recupera um ponteiro para a estrutura de **TOKEN\_GROUPS** .|  
|[CTokenGroups::GetSidsAndAttributes](../Topic/CTokenGroups::GetSidsAndAttributes.md)|Recupera os objetos e atributos de `CSid` que pertencem ao objeto de `CTokenGroups` .|  
|[CTokenGroups::LookupSid](../Topic/CTokenGroups::LookupSid.md)|Recupera os atributos associados com um objeto de `CSid` .|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Const TOKEN\_GROUPS de CTokenGroups::operator \*](../Topic/CTokenGroups::operator%20const%20TOKEN_GROUPS%20*.md)|Converte o objeto de `CTokenGroups` a um ponteiro para a estrutura de **TOKEN\_GROUPS** .|  
|[CTokenGroups::operator \=](../Topic/CTokenGroups::operator%20=.md)|Operador de atribuição.|  
  
## Comentários  
 [token de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374909) é um objeto que descreve o contexto de segurança de um processo ou de um segmento e é atribuído a cada usuário efetuado logon em um sistema do Windows NT 2000 ou Windows.  
  
 A classe de **CTokenGroups** é um wrapper para a estrutura de [TOKEN\_GROUPS](http://msdn.microsoft.com/library/windows/desktop/aa379624) , que contém informações sobre os identificadores de segurança \(SIDs\) do grupo em um token de acesso.  
  
 Para obter uma introdução ao modelo de controle de acesso no windows, consulte [controle de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374860) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## Requisitos  
 **Cabeçalho:** atlsecurity.h  
  
## Consulte também  
 [Exemplo de segurança](../../top/visual-cpp-samples.md)   
 [Classe de CSid](../../atl/reference/csid-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Funções de segurança globais](../../atl/reference/security-global-functions.md)