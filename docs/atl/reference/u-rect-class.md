---
title: "Classe de _U_RECT | Microsoft Docs"
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
  - "ATL::_U_RECT"
  - "_U_RECT"
  - "ATL._U_RECT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de _U_RECT"
  - "Classe de U_RECT"
ms.assetid: 5f880a2d-09cf-4327-bf32-a3519c4dcd63
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de _U_RECT
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe do adaptador do argumento permite ponteiros ou referências de `RECT` a ser passados para uma função que é implementada em termos de ponteiros.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class _U_RECT  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[\_U\_RECT::\_U\_RECT](../Topic/_U_RECT::_U_RECT.md)|o construtor.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[\_U\_RECT::m\_lpRect](../Topic/_U_RECT::m_lpRect.md)|Ponteiro para `RECT`.|  
  
## Comentários  
 A classe define duas sobrecargas de construtor: se aceita um argumento de **RECT&** e o outro aceita um argumento de `LPRECT` .  O primeiro construtor armazena o endereço de argumento de referência membro de dados da classe no único, [m\_lpRect](../Topic/_U_RECT::m_lpRect.md).  O argumento para o construtor do ponteiro é armazenado diretamente sem conversão.  
  
## Requisitos  
 **Cabeçalho:** atlwin.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)