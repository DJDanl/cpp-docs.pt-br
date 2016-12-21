---
title: "Classe _U_MENUorID | Microsoft Docs"
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
  - "ATL._U_MENUorID"
  - "ATL::_U_MENUorID"
  - "_U_MENUorID"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe U_MENUorID"
  - "Classe _U_MENUorID"
ms.assetid: cfc8032b-61b4-4a68-ba3a-92b82500ccae
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe _U_MENUorID
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece wrappers para **CreateWindow** e **CreateWindowEx**.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## Sintaxe  
  
```  
  
class _U_MENUorID  
  
```  
  
## Membros  
  
### Construtores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[\_U\_MENUorID::\_U\_MENUorID](../Topic/_U_MENUorID::_U_MENUorID.md)|O construtor.|  
  
### Membros de dados públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[\_U\_MENUorID::m\_hMenu](../Topic/_U_MENUorID::m_hMenu.md)|Um identificador para um menu.|  
  
## Comentários  
 Essa classe de adaptador do argumento permite que qualquer um dos IDs \(**UINT**s\) ou identificadores de menu \(`HMENU`s\) a serem passados para uma função sem exigir uma conversão explícita na parte do chamador.  
  
 Essa classe foi projetada para a implementação de invólucros para a API do Windows, principalmente o [CreateWindow](http://msdn.microsoft.com/library/windows/desktop/ms632679) e [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680) funções, dos quais aceitam um `HMENU` argumento pode ser um identificador de janela filho \(**UINT**\) em vez de um identificador de menu. Por exemplo, você pode ver essa classe em uso como um parâmetro para [CWindowImpl::Create](../Topic/CWindowImpl::Create.md).  
  
 A classe define duas sobrecargas de construtor: uma aceita um **UINT** argumento e o outro aceita um `HMENU` argumento. O **UINT** argumento apenas é convertido para um `HMENU` no construtor e o resultado armazenado no membro de dados da classe, [m\_hMenu](../Topic/_U_MENUorID::m_hMenu.md). O argumento para o `HMENU` construtor é armazenado diretamente, sem conversão.  
  
## Requisitos  
 **Cabeçalho:** atlwin.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)