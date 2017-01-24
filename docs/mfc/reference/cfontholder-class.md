---
title: "Classe de CFontHolder | Microsoft Docs"
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
  - "CFontHolder"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CFontHolder"
  - "fontes personalizados"
  - "fontes, Controles ActiveX"
ms.assetid: 728ab472-0c97-440d-889f-1324c6e1b6b8
caps.latest.revision: 19
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CFontHolder
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa a propriedade conservada em estoque de fonte e encapsula funcionalidade de um objeto de fonte do windows e da interface de `IFont` .  
  
## Sintaxe  
  
```  
class CFontHolder  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFontHolder::CFontHolder](../Topic/CFontHolder::CFontHolder.md)|Constrói um objeto de `CFontHolder` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFontHolder::GetDisplayString](../Topic/CFontHolder::GetDisplayString.md)|Retorna a cadeia de caracteres exibida no navegador de propriedade do contêiner.|  
|[CFontHolder::GetFontDispatch](../Topic/CFontHolder::GetFontDispatch.md)|Retorna a interface de `IDispatch` da fonte.|  
|[CFontHolder::GetFontHandle](../Topic/CFontHolder::GetFontHandle.md)|Retorna um identificador a uma fonte do windows.|  
|[CFontHolder::InitializeFont](../Topic/CFontHolder::InitializeFont.md)|Inicializa um objeto de `CFontHolder` .|  
|[CFontHolder::QueryTextMetrics](../Topic/CFontHolder::QueryTextMetrics.md)|Recupera informações para a fonte relacionada.|  
|[CFontHolder::ReleaseFont](../Topic/CFontHolder::ReleaseFont.md)|Desliga o objeto de `CFontHolder` de `IFont` e `IFontNotification` interfaces.|  
|[CFontHolder::Select](../Topic/CFontHolder::Select.md)|Seleciona um recurso de fonte em um contexto de dispositivo.|  
|[CFontHolder::SetFont](../Topic/CFontHolder::SetFont.md)|Conecta o objeto de `CFontHolder` a interface de `IFont` .|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFontHolder::m\_pFont](../Topic/CFontHolder::m_pFont.md)|Um ponteiro para a interface de `IFont` do objeto de `CFontHolder` .|  
  
## Comentários  
 `CFontHolder` não tem uma classe base.  
  
 Use esta classe para implementar propriedades de fonte personalizado para o controle.  Para obter informações sobre como criar tais propriedades, consulte o artigo [Controles ActiveX: usando fontes](../../mfc/mfc-activex-controls-using-fonts.md).  
  
## Hierarquia de herança  
 `CFontHolder`  
  
## Requisitos  
 **Cabeçalho:** afxctl.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CPropExchange](../Topic/CPropExchange%20Class.md)