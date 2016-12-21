---
title: "Classe de CWinTraitsOR | Microsoft Docs"
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
  - "ATL.CWinTraitsOR"
  - "ATL::CWinTraitsOR"
  - "CWinTraitsOR"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CWinTraitsOR"
  - "estilos de janela, valores padrão para ATL"
ms.assetid: 1eb7b1e8-a9bd-411b-a30a-35a8a10af989
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CWinTraitsOR
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece um método para padronizar os estilos usados para criar um objeto da janela.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      template <  
DWORD t_dwStyle= 0,  
DWORDt_dwExStyle= 0,  
class TWinTraits = CControlWinTraits   
>  
class CWinTraitsOR  
```  
  
#### Parâmetros  
 `t_dwStyle`  
 Estilos de janela padrão.  
  
 `t_dwExStyle`  
 Estilos estendidos de janela default.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWinTraitsOR::GetWndExStyle](../Topic/CWinTraitsOR::GetWndExStyle.md)|Recupera os estilos estendidos para o objeto de `CWinTraitsOR` .|  
|[CWinTraitsOR::GetWndStyle](../Topic/CWinTraitsOR::GetWndStyle.md)|Recupera os estilos padrão para o objeto de `CWinTraitsOR` .|  
  
## Comentários  
 Essa classe de [traços da janela](../../atl/understanding-window-traits.md) fornece um método simples para padronizar os estilos usados para a criação de um objeto da janela de ATL.  Use uma especialização de essa classe como um parâmetro de modelo a [CWindowImpl](../Topic/CWindowImpl%20Class.md) ou outro de classes da janela de ATL para especificar o mínimo de padrão definido e estilos estendidos para ser usados para instâncias de classe da janela.  
  
 Use uma especialização este modelo se você quiser garantir que determinados estilos são definidos para todas as instâncias da classe da janela para permitir que outros estilos ser definido em uma base por instância na chamada a [CWindowImpl::Create](../Topic/CWindowImpl::Create.md).  
  
 Se você desejar fornecer os estilos de janela padrão que serão usados somente quando nenhum outro estilo é especificado na chamada a `CWindowImpl::Create`, use [CWinTraits](../../atl/reference/cwintraits-class.md) em vez de isso.  
  
## Requisitos  
 **Cabeçalho:** atlwin.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [A janela de traços entendendo](../../atl/understanding-window-traits.md)