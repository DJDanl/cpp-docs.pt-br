---
title: "Classe de CDacl | Microsoft Docs"
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
  - "ATL::CDacl"
  - "CDacl"
  - "ATL.CDacl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDacl"
ms.assetid: 2dc76616-6362-4967-b6cf-e2d39ca37ddd
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDacl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe é um wrapper para uma estrutura de DACL \(lista de controle de acesso discricionário\).  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class CDacl : public CAcl  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDacl::CDacl](../Topic/CDacl::CDacl.md)|o construtor.|  
|[CDacl::~CDacl](../Topic/CDacl::~CDacl.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDacl::AddAllowedAce](../Topic/CDacl::AddAllowedAce.md)|Adiciona ACE permitido \(entrada de controle de acesso\) para o objeto de `CDacl` .|  
|[CDacl::AddDeniedAce](../Topic/CDacl::AddDeniedAce.md)|Adiciona ACE negado ao objeto de `CDacl` .|  
|[CDacl::GetAceCount](../Topic/CDacl::GetAceCount.md)|Retorna o número de \(entradas de controle de acesso\) no objeto de `CDacl` .|  
|[CDacl::RemoveAce](../Topic/CDacl::RemoveAce.md)|Remove ACE específico \(entrada de controle de acesso\) do objeto de `CDacl` .|  
|[CDacl::RemoveAllAces](../Topic/CDacl::RemoveAllAces.md)|Remove todos os aces contidos no objeto de `CDacl` .|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDacl::operator \=](../Topic/CDacl::operator%20=.md)|Operador de atribuição.|  
  
## Comentários  
 o descritor de segurança de um objeto pode conter DACL.  DACL contém zero ou mais aces \(entradas de controle de acesso\) que identificam os usuários e grupos que podem acessar o objeto.  Se DACL está vazia \(isto é, contém os aces zero\), nenhum acesso é concedido explicitamente, para que o acesso negado é implicitamente.  Em o entanto, se o descritor de segurança de um objeto não tem DACL, o objeto é desprotegido e todos tem acesso completo.  
  
 Para recuperar DACL de um objeto, você deve ser o proprietário do objeto ou ter acesso de READ\_CONTROL ao objeto.  Para alterar DACL de um objeto, você deve ter acesso de WRITE\_DAC ao objeto.  
  
 Use os métodos da classe fornecidos para criar, adicione, remova, e excluir aces do objeto de `CDacl` .  Consulte também [AtlGetDacl](../Topic/AtlGetDacl.md) e [AtlSetDacl](../Topic/AtlSetDacl.md).  
  
 Para obter uma introdução ao modelo de controle de acesso no windows, consulte [controle de acesso](http://msdn.microsoft.com/library/windows/desktop/aa374860) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## Hierarquia de herança  
 [CAcl](../../atl/reference/cacl-class.md)  
  
 `CDacl`  
  
## Requisitos  
 **Cabeçalho:** atlsecurity.h  
  
## Consulte também  
 [Exemplo de segurança](../../top/visual-cpp-samples.md)   
 [Classe de CAcl](../../atl/reference/cacl-class.md)   
 [ACLs](http://msdn.microsoft.com/library/windows/desktop/aa374872)   
 [ACEs](http://msdn.microsoft.com/library/windows/desktop/aa374868)   
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Funções de segurança globais](../../atl/reference/security-global-functions.md)