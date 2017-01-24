---
title: "Classe de CSingleDocTemplate | Microsoft Docs"
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
  - "CSingleDocTemplate"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSingleDocTemplate"
  - "modelos de documento, único"
  - "interface (SDI) do documento único, aplicativos"
  - "modelos, SDI"
ms.assetid: 4f3a8212-81ee-48a0-ad22-e0ed7c36a391
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSingleDocTemplate
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define um modelo de documento que implementa a interface \(SDI\) do único documento.  
  
## Sintaxe  
  
```  
class CSingleDocTemplate : public CDocTemplate  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSingleDocTemplate::CSingleDocTemplate](../Topic/CSingleDocTemplate::CSingleDocTemplate.md)|Constrói um objeto de `CSingleDocTemplate` .|  
  
## Comentários  
 Um aplicativo de SDI usa a janela de quadro chave para exibir um documento; somente um documento pode ser aberto por vez.  
  
 Um modelo de documento define a relação entre três tipos de classes:  
  
-   Uma classe de documento, que você derivar de **CDocument**.  
  
-   Uma classe de visualização, que exibe dados da classe do documento listados acima.  Você pode derivar essa classe de `CView`, de `CScrollView`, de `CFormView`, ou de `CEditView`.  \(Você também pode usar `CEditView` diretamente.\)  
  
-   Uma classe de janela do quadro, que contém o modo de exibição.  Para um modelo de documento de SDI, você pode derivar essa classe de `CFrameWnd`; se você não precisa personalizar o comportamento da janela do quadro chave, você pode usar `CFrameWnd` diretamente sem derivar sua própria classe.  
  
 Um aplicativo de SDI suporta normalmente um tipo de documento, portanto tem apenas um objeto de `CSingleDocTemplate` .  Somente um documento pode ser aberto por vez.  
  
 Você não precisa chamar as funções de membro de `CSingleDocTemplate` exceto o construtor.  a estrutura trata objetos de `CSingleDocTemplate` internamente.  
  
 Para obter mais informações sobre como usar `CSingleDocTemplate`, consulte [Modelos de documento e o processo de criação do documento\/exibição](../../mfc/document-templates-and-the-document-view-creation-process.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CDocTemplate](../../mfc/reference/cdoctemplate-class.md)  
  
 `CSingleDocTemplate`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [Exemplo DOCKTOOL MFC](../../top/visual-cpp-samples.md)   
 [Classe de CDocTemplate](../../mfc/reference/cdoctemplate-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CDocTemplate](../../mfc/reference/cdoctemplate-class.md)   
 [Classe de CDocument](../Topic/CDocument%20Class.md)   
 [Classe de CFrameWnd](../../mfc/reference/cframewnd-class.md)   
 [Classe de CMultiDocTemplate](../../mfc/reference/cmultidoctemplate-class.md)   
 [Classe de CView](../Topic/CView%20Class.md)   
 [Classe de CWinApp](../../mfc/reference/cwinapp-class.md)