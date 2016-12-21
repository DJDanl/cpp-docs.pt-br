---
title: "Classe de CTokenPrivileges | Microsoft Docs"
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
  - "ATL::CTokenPrivileges"
  - "CTokenPrivileges"
  - "ATL.CTokenPrivileges"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CTokenPrivileges"
ms.assetid: 89590105-f001-4014-870d-142926091231
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CTokenPrivileges
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe é um wrapper para a estrutura de **TOKEN\_PRIVILEGES** .  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class CTokenPrivileges  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CTokenPrivileges::CTokenPrivileges](../Topic/CTokenPrivileges::CTokenPrivileges.md)|o construtor.|  
|[CTokenPrivileges::~CTokenPrivileges](../Topic/CTokenPrivileges::~CTokenPrivileges.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CTokenPrivileges::Add](../Topic/CTokenPrivileges::Add.md)|Adiciona um ou mais privilégios para o objeto de `CTokenPrivileges` .|  
|[CTokenPrivileges::Delete](../Topic/CTokenPrivileges::Delete.md)|Exclui um privilégio do objeto de `CTokenPrivileges` .|  
|[CTokenPrivileges::DeleteAll](../Topic/CTokenPrivileges::DeleteAll.md)|Exclui todos os privilégios de objeto de `CTokenPrivileges` .|  
|[CTokenPrivileges::GetCount](../Topic/CTokenPrivileges::GetCount.md)|Retorna o número de entradas de privilégio no objeto de `CTokenPrivileges` .|  
|[CTokenPrivileges::GetDisplayNames](../Topic/CTokenPrivileges::GetDisplayNames.md)|Recupera nomes para exibição para os privilégios contidos no objeto de `CTokenPrivileges` .|  
|[CTokenPrivileges::GetLength](../Topic/CTokenPrivileges::GetLength.md)|Retorna o tamanho do buffer em bytes necessários para manter a estrutura de **TOKEN\_PRIVILEGES** representada pelo objeto de `CTokenPrivileges` .|  
|[CTokenPrivileges::GetLuidsAndAttributes](../Topic/CTokenPrivileges::GetLuidsAndAttributes.md)|Recupera os identificadores exclusivos localmente \(LUIDs\) e sinalizadores de atributo de objeto de `CTokenPrivileges` .|  
|[CTokenPrivileges::GetNamesAndAttributes](../Topic/CTokenPrivileges::GetNamesAndAttributes.md)|Recupera os sinalizadores e nomes de atributo de privilégios do objeto de `CTokenPrivileges` .|  
|[CTokenPrivileges::GetPTOKEN\_PRIVILEGES](../Topic/CTokenPrivileges::GetPTOKEN_PRIVILEGES.md)|Retorna um ponteiro para a estrutura de **TOKEN\_PRIVILEGES** .|  
|[CTokenPrivileges::LookupPrivilege](../Topic/CTokenPrivileges::LookupPrivilege.md)|Recupera o atributo associado com um determinado nome de privilégios.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Const TOKEN\_PRIVILEGES de CTokenPrivileges::operator \*](../Topic/CTokenPrivileges::operator%20const%20TOKEN_PRIVILEGES%20*.md)|Converter um valor a um ponteiro para a estrutura de **TOKEN\_PRIVILEGES** .|  
|[CTokenPrivileges::operator \=](../Topic/CTokenPrivileges::operator%20=.md)|Operador de atribuição.|  
  
## Comentários  
 [token de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374909) é um objeto que descreve o contexto de segurança de um processo ou de um segmento e é atribuído a cada usuário efetuado logon em um sistema do Windows NT 2000 ou Windows.  
  
 O token de acesso é usado para descrever os vários privilégios de segurança concedidos a cada usuário.  Um privilégio consiste em um número de 64 bits chamado um identificador exclusivo \(localmente[LUID](http://msdn.microsoft.com/library/windows/desktop/aa379261)\) e uma cadeia de caracteres de descritor.  
  
 A classe de `CTokenPrivileges` é um wrapper para a estrutura de [TOKEN\_PRIVILEGES](http://msdn.microsoft.com/library/windows/desktop/aa379630) e contém 0 ou mais privilégios.  Os aplicativos podem ser adicionados, excluído, ou consultado fornecidos usando os métodos da classe.  
  
 Para obter uma introdução ao modelo de controle de acesso no windows, consulte [controle de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374860) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## Requisitos  
 **Cabeçalho:** atlsecurity.h  
  
## Consulte também  
 [Exemplo de segurança](../../top/visual-cpp-samples.md)   
 [TOKEN\_PRIVILEGES](http://msdn.microsoft.com/library/windows/desktop/aa379630)   
 [LUID](http://msdn.microsoft.com/library/windows/desktop/aa379261)   
 [LUID\_AND\_ATTRIBUTES](http://msdn.microsoft.com/library/windows/desktop/aa379263)   
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Funções de segurança globais](../../atl/reference/security-global-functions.md)