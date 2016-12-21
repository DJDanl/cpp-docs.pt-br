---
title: "Classe de CAcl | Microsoft Docs"
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
  - "CAcl"
  - "ATL::CAcl"
  - "ATLSECURITY/CAcl"
  - "ATL.CAcl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAcl"
ms.assetid: 20bcb9af-dc1c-4737-b923-3864776680d6
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAcl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe é um wrapper para uma estrutura de `ACL` \(lista de controle de acesso\).  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class CAcl  
  
```  
  
## Membros  
  
### Typedefs público  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAcl::CAccessMaskArray](../Topic/CAcl::CAccessMaskArray.md)|Uma matriz de S. `ACCESS_MASK`.|  
|[CAcl::CAceFlagArray](../Topic/CAcl::CAceFlagArray.md)|Uma matriz de S. `BYTE`.|  
|[CAcl::CAceTypeArray](../Topic/CAcl::CAceTypeArray.md)|Uma matriz de S. `BYTE`.|  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAcl::CAcl](../Topic/CAcl::CAcl.md)|o construtor.|  
|[CAcl::~CAcl](../Topic/CAcl::~CAcl.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAcl::GetAceCount](../Topic/CAcl::GetAceCount.md)|Retorna o número de objetos de \(ACE\) de entrada de controle de acesso.|  
|[CAcl::GetAclEntries](../Topic/CAcl::GetAclEntries.md)|Recupera as entradas de \(ACL\) da lista de controle de acesso do objeto de `CAcl` .|  
|[CAcl::GetAclEntry](../Topic/CAcl::GetAclEntry.md)|Recupera todas as informações sobre uma entrada em um objeto de `CAcl` .|  
|[CAcl::GetLength](../Topic/CAcl::GetLength.md)|Retorna o comprimento de ACL.|  
|[CAcl::GetPACL](../Topic/CAcl::GetPACL.md)|Retorna um ponteiro para um PACL \(ACL\).|  
|[CAcl::IsEmpty](../Topic/CAcl::IsEmpty.md)|Testar o objeto de `CAcl` para entradas.|  
|[CAcl::IsNull](../Topic/CAcl::IsNull.md)|Retorna o status do objeto de `CAcl` .|  
|[CAcl::RemoveAce](../Topic/CAcl::RemoveAce.md)|Remove ACE específico \(entrada de controle de acesso\) do objeto de `CAcl` .|  
|[CAcl::RemoveAces](../Topic/CAcl::RemoveAces.md)|Remove todos os aces \(entradas de controle de acesso\) de `CAcl` que se aplicam a `CSid`dado.|  
|[CAcl::SetEmpty](../Topic/CAcl::SetEmpty.md)|Marca o objeto de `CAcl` como vazia.|  
|[CAcl::SetNull](../Topic/CAcl::SetNull.md)|Marca o objeto de `CAcl` como `NULL`.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Const ACL de CAcl::operator \*](../Topic/CAcl::operator%20const%20ACL%20*.md)|Converte um objeto de `CAcl` a estrutura de `ACL` .|  
|[CAcl::operator \=](../Topic/CAcl::operator%20=.md)|Operador de atribuição.|  
  
## Comentários  
 A estrutura de **ACL** é o cabeçalho de uma ACL \(lista de controle de acesso\).  Uma ACL inclui uma lista seqüencial de zero ou mais [Aces](http://msdn.microsoft.com/library/windows/desktop/aa374868) \(entradas de controle de acesso\).  Os aces individuais em uma ACL são numerados de 0 *a n\-1* *em* , onde é o número do ACL.  Para editar uma ACL, uma entrada refere\-se a um aplicativo \(ACE\) de controle de acesso em ACL pelo índice.  
  
 Há dois tipos de ACL:  
  
-   Arbitrário  
  
-   Sistema  
  
 Uma ACL arbitrário é controlado pelo proprietário de um objeto ou qualquer um de **WRITE\_DAC** concedeu acesso ao objeto.  Especifica os usuários específicos de acesso e os grupos podem ter para um objeto.  Por exemplo, o proprietário de um arquivo pode usar uma ACL arbitrário para controlar quais usuários e grupos e eles não podem ter acesso ao arquivo.  
  
 Um objeto pode também ter informações de segurança do nível do sistema associado a ele, na forma de um sistema ACL controlado por um administrador do sistema.  Um sistema ACL pode permitir que o administrador do sistema audite qualquer tentativa para obter acesso a um objeto.  
  
 Para mais detalhes, consulte discussões de [ACL](http://msdn.microsoft.com/library/windows/desktop/aa374872) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter uma introdução ao modelo de controle de acesso no windows, consulte [controle de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374860) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## Requisitos  
 **Cabeçalho:** atlsecurity.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Funções de segurança globais](../../atl/reference/security-global-functions.md)