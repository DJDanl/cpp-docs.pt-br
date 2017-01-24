---
title: "Classe de CMiniFrameWnd | Microsoft Docs"
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
  - "CMiniFrameWnd"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMiniFrameWnd"
  - "mini-linguagem quadro do windows"
  - "barras de ferramentas [C++]"
ms.assetid: b8f534ed-0532-4d8e-9657-5595cf677749
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMiniFrameWnd
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa uma janela do quadro de metade\- altura vista normalmente em torno de barras de ferramentas flutuante.  
  
## Sintaxe  
  
```  
class CMiniFrameWnd : public CFrameWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMiniFrameWnd::CMiniFrameWnd](../Topic/CMiniFrameWnd::CMiniFrameWnd.md)|Constrói um objeto de `CMiniFrameWnd` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMiniFrameWnd::Create](../Topic/CMiniFrameWnd::Create.md)|Cria um objeto de `CMiniFrameWnd` após a compilação.|  
|[CMiniFrameWnd::CreateEx](../Topic/CMiniFrameWnd::CreateEx.md)|Cria um objeto de `CMiniFrameWnd` \(com opções adicionais\) após a compilação.|  
  
## Comentários  
 Essas janelas de mini\-linguagem quadro se comportam como o windows normais de quadro chave, exceto que não têm botões minimizar\/maximizar ou menus e você só precisam único clique no menu do sistema demiti\-los.  
  
 Para usar um objeto de `CMiniFrameWnd` , defina o primeiro objeto.  Chame a função de membro de [Criar](../Topic/CMiniFrameWnd::Create.md) para exibir a janela de mini\-linguagem quadro.  
  
 Para obter mais informações sobre como usar objetos de `CMiniFrameWnd` , consulte o artigo [Barras de ferramentas e flutuante de encaixe](../../mfc/docking-and-floating-toolbars.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CFrameWnd](../../mfc/reference/cframewnd-class.md)  
  
 `CMiniFrameWnd`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [Classe de CFrameWnd](../../mfc/reference/cframewnd-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CFrameWnd](../../mfc/reference/cframewnd-class.md)