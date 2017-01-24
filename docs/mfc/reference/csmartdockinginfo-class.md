---
title: "Classe de CSmartDockingInfo | Microsoft Docs"
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
  - "CSmartDockingInfo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSmartDockingInfo"
ms.assetid: cab04f38-4bc1-4378-9337-c56fc87fbd68
caps.latest.revision: 27
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSmartDockingInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define a aparência de marcadores inteligentes de encaixe.  
  
## Sintaxe  
  
```  
class CSmartDockingInfo : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|`CSmartDockingInfo::CSmartDockingInfo`|Construtor padrão.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSmartDockingInfo::CopyTo](../Topic/CSmartDockingInfo::CopyTo.md)|Copia os parâmetros inteligentes atuais de informações de encaixe no objeto fornecido de [CSmartDockingInfo](../../mfc/reference/csmartdockinginfo-class.md) .|  
  
### Membros de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSmartDockingInfo::m\_bUseThemeColorInShading](../Topic/CSmartDockingInfo::m_bUseThemeColorInShading.md)|Especifica se usar o tema atual colorem quando a estrutura exibir marcadores inteligentes de encaixe.|  
|[CSmartDockingInfo::m\_clrBaseBackground](../Topic/CSmartDockingInfo::m_clrBaseBackground.md)|Especifica a cor do plano de fundo de base de marcadores inteligentes de encaixe.|  
|[CSmartDockingInfo::m\_clrToneDest](../Topic/CSmartDockingInfo::m_clrToneDest.md)|Especifica a cor que substitui `m_clrToneSrc` em bitmaps inteligentes do marcador de encaixe.|  
|[CSmartDockingInfo::m\_clrToneSrc](../Topic/CSmartDockingInfo::m_clrToneSrc.md)|Especifica a cor de bitmaps inteligentes do marcador de encaixe.|  
|[CSmartDockingInfo::m\_clrTransparent](../Topic/CSmartDockingInfo::m_clrTransparent.md)|Especifica a cor de bitmaps inteligentes do marcador de encaixe quando são transparentes.|  
|[CSmartDockingInfo::m\_nCentralGroupOffset](../Topic/CSmartDockingInfo::m_nCentralGroupOffset.md)|Especifica o deslocamento do grupo central de marcadores inteligentes de encaixe dos limites do retângulo central do grupo.|  
|[CSmartDockingInfo::m\_sizeTotal](../Topic/CSmartDockingInfo::m_sizeTotal.md)|Especifica o tamanho total de todos os marcadores inteligentes de encaixe em um grupo.|  
|[CSmartDockingInfo::m\_uiMarkerBmpResID](../Topic/CSmartDockingInfo::m_uiMarkerBmpResID.md)|Define os IDs de recurso de bitmaps que a estrutura usa para os marcadores inteligentes de encaixe que não são realçadas.|  
|[CSmartDockingInfo::m\_uiMarkerLightBmpResID](../Topic/CSmartDockingInfo::m_uiMarkerLightBmpResID.md)|Define os IDs de recurso de bitmaps que a estrutura usa para os marcadores inteligentes de encaixe que são realçadas.|  
  
## Comentários  
 A estrutura lida com marcadores inteligentes de encaixe internamente.  A ilustração a seguir mostra os marcadores inteligentes padrão de encaixe:  
  
 ![marcadores de encaixe inteligente padrão](../../mfc/reference/media/nextsdmarkers.png "nextSDmarkers")  
  
 Em essa figura, a imagem à esquerda mostra um marcador inteligente de encaixe do grupo central que não tenha o encaixe a um guia ativado.  A imagem a seguir mostra uma entre a borda direita o marcador inteligente de encaixe.  A imagem à direita mostra um marcador inteligente de encaixe do grupo central que tenha o encaixe a um guia ativado.  O marcador inteligente de encaixe do grupo central tem um bitmap principal e cinco bitmaps inteligentes do marcador de encaixe.  
  
 Você pode personalizar os seguintes parâmetros de marcadores inteligentes de encaixe:  
  
-   Cor.  Por exemplo, você pode substituir a cor azul os marcadores na figura com qualquer cor definido pelo usuário.  
  
-   Cor de transparência.  
  
-   Deslocamento de um marcador inteligente de encaixe no grupo central da borda do retângulo delimitador.  
  
-   o bitmap principal que representa o grupo central.  
  
-   Bitmaps que representa os marcadores inteligentes regulares e destaque de encaixe.  
  
 A ilustração a seguir mostra um exemplo dos marcadores inteligentes de encaixe que foram personalizados:  
  
 ![Marcadores personalizados de encaixe inteligente](../Image/nextSDmarkersCustom.png "nextSDmarkersCustom")  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CSmartDockingInfo](../../mfc/reference/csmartdockinginfo-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxDockingManager.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CObject](../Topic/CObject%20Class.md)