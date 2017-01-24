---
title: "Classe de CHandle | Microsoft Docs"
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
  - "ATL.CHandle"
  - "ATL::CHandle"
  - "CHandle"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CHandle"
ms.assetid: 883e9db5-40ec-4e29-9c74-4dd2ddd2e35d
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CHandle
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para criar e usar um objeto de manipular.  
  
## Sintaxe  
  
```  
  
class CHandle  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CHandle::CHandle](../Topic/CHandle::CHandle.md)|o construtor.|  
|[CHandle::~CHandle](../Topic/CHandle::~CHandle.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CHandle::Attach](../Topic/CHandle::Attach.md)|Chamar esse método para anexar o objeto de `CHandle` a um identificador existente.|  
|[CHandle::Close](../Topic/CHandle::Close.md)|Chamar esse método para fechar um objeto de `CHandle` .|  
|[CHandle::Detach](../Topic/CHandle::Detach.md)|Chamar esse método para desanexar uma alça de um objeto de `CHandle` .|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[ALÇA de CHandle::operator](../Topic/CHandle::operator%20HANDLE.md)|Retorna o valor de forma armazenada.|  
|[CHandle::operator \=](../Topic/CHandle::operator%20=.md)|Operador de atribuição.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CHandle::m\_h](../Topic/CHandle::m_h.md)|A variável de membro que armazena o identificador.|  
  
## Comentários  
 Um objeto de `CHandle` pode ser usado sempre que um identificador é necessária: a principal diferença é que o objeto de `CHandle` será excluído automaticamente.  
  
> [!NOTE]
>  Algumas funções da API usarão NULL como um identificador vazia ou inválido, enquanto outros usam INVALID\_HANDLE\_VALUE.  Usos de`CHandle` somente ANULAM e manipulará INVALID\_HANDLE\_VALUE como um identificador real.  Se você chamar a API que podem retornar INVALID\_HANDLE\_VALUE, você deve verificar se esse valor antes de chamar [CHandle::Attach](../Topic/CHandle::Attach.md) ou de passá\-lo para o construtor de `CHandle` , e passa pelo contrário NULL.  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)