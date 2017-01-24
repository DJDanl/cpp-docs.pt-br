---
title: "Classe de CComPtr | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CComPtr"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComPtr"
ms.assetid: 22d9ea8d-ed66-4c34-940f-141db11e83bd
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComPtr
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma classe inteligente do ponteiro para gerenciar ponteiros da interface COM.  
  
## Sintaxe  
  
```  
  
      template<  
   class T   
>  
class CComPtr  
```  
  
#### Parâmetros  
 `T`  
 Uma interface COM que especifica o tipo de ponteiro para ser armazenado.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComPtr::CComPtr](../Topic/CComPtr::CComPtr.md)|o construtor.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComPtr::operator \=](../Topic/CComPtr::operator%20=.md)|Atribui um ponteiro para o ponteiro de membro.|  
  
## Comentários  
 Usa `CComPtr` e [CComQIPtr](../../atl/reference/ccomqiptr-class.md) de ATL gerenciar ponteiros da interface COM.  Ambos são derivados de [CComPtrBase](../../atl/reference/ccomptrbase-class.md), ambos e executam a contagem de referência automática.  
  
 **CComPtr** E as classes de [CComQIPtr](../../atl/reference/ccomqiptr-class.md) podem ajudar a eliminar vazamentos de memória executando a contagem de referência automática.  As seguintes funções ambas executam as mesmas operações lógicas; no entanto, observe como a segunda versão pode ser menos sujeita a erros usando a classe de **CComPtr** :  
  
 [!CODE [NVC_ATL_Utilities#130](../CodeSnippet/VS_Snippets_Cpp/NVC_ATL_Utilities#130)]  
  
 [!CODE [NVC_ATL_Utilities#131](../CodeSnippet/VS_Snippets_Cpp/NVC_ATL_Utilities#131)]  
  
 Em compilações de depuração, atlsd.lib link para o rastreamento de código.  
  
## Hierarquia de herança  
 [CComPtrBase](../../atl/reference/ccomptrbase-class.md)  
  
 `CComPtr`  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Consulte também  
 [CComPtr::CComPtr](../Topic/CComPtr::CComPtr.md)   
 [CComQIPtr::CComQIPtr](../Topic/CComQIPtr::CComQIPtr.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)