---
title: "Classe de CMultiDocTemplate | Microsoft Docs"
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
  - "CMultiDocTemplate"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMultiDocTemplate"
  - "MDI, modelo"
ms.assetid: 5b8aa328-e461-41d0-b388-00594535e119
caps.latest.revision: 21
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMultiDocTemplate
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define um modelo de documento que implementa a interface de documentos múltiplos \(MDI\).  
  
## Sintaxe  
  
```  
  
class CMultiDocTemplate : public CDocTemplate  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMultiDocTemplate::CMultiDocTemplate](../Topic/CMultiDocTemplate::CMultiDocTemplate.md)|Constrói um objeto de `CMultiDocTemplate` .|  
  
## Comentários  
 Um aplicativo MDI usa a janela de quadro chave como um espaço de trabalho que o usuário pode abrir zero ou mais janelas de quadro de documento, cada um de eles exibe um documento.  Para obter uma descrição mais detalhada MDI, consulte *o windows interface diretrizes de design de software*.  
  
 Um modelo de documento define as relações entre três tipos de classes:  
  
-   Uma classe de documento, que você derivar de [CDocument](../Topic/CDocument%20Class.md).  
  
-   Uma classe de visualização, que exibe dados da classe do documento listados acima.  Você pode derivar essa classe de [CView](../Topic/CView%20Class.md), de `CScrollView`, de `CFormView`, ou de `CEditView`.  \(Você também pode usar `CEditView` diretamente.\)  
  
-   Uma classe de janela do quadro, que contém o modo de exibição.  Para um modelo de documento MDI, você pode derivar essa classe de `CMDIChildWnd`, ou, se você não precisa personalizar o comportamento do windows do quadro do documento, você pode usar [CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md) diretamente sem derivar sua própria classe.  
  
 Um aplicativo MDI pode suportar mais de um tipo de documento, e documentos de diferentes tipos podem estar abertos ao mesmo tempo.  Seu aplicativo tiver um modelo de documento para cada tipo de documento que suporta.  Por exemplo, se seu aplicativo MDI suporta planilhas e documentos de texto, o aplicativo tem dois objetos de `CMultiDocTemplate` .  
  
 O aplicativo usa os modelos de documento quando o usuário cria um novo documento.  Se o aplicativo suporta mais de um tipo de documento, a estrutura obtém os nomes dos tipos de documento suporte de modelos de documento e exibi\-los em uma lista na caixa de diálogo de Arquivo.  Uma vez que o usuário tiver selecionado um tipo de documento, o aplicativo cria uma classe de objeto de documento, um objeto da janela de quadro chave, e um objeto de exibição e os anexa entre si.  
  
 Você não precisa chamar as funções de membro de `CMultiDocTemplate` exceto o construtor.  a estrutura trata objetos de `CMultiDocTemplate` internamente.  
  
 Para obter mais informações sobre `CMultiDocTemplate`, consulte [Modelos de documento e o processo de criação do documento\/exibição](../../mfc/document-templates-and-the-document-view-creation-process.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CDocTemplate](../../mfc/reference/cdoctemplate-class.md)  
  
 `CMultiDocTemplate`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [Classe de CDocTemplate](../../mfc/reference/cdoctemplate-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CDocTemplate](../../mfc/reference/cdoctemplate-class.md)   
 [Classe de CSingleDocTemplate](../../mfc/reference/csingledoctemplate-class.md)   
 [Classe de CWinApp](../../mfc/reference/cwinapp-class.md)