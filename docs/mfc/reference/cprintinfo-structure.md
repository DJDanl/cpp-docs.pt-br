---
title: "Estrutura de CPrintInfo | Microsoft Docs"
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
  - "CPrintInfo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura de CPrintInfo"
ms.assetid: 0b3de849-d050-4386-9a14-f4c1a25684f7
caps.latest.revision: 21
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura de CPrintInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Informações sobre repositórios um trabalho de impressão ou de visualização de impressão.  
  
## Sintaxe  
  
```  
struct CPrintInfo  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPrintInfo::GetFromPage](../Topic/CPrintInfo::GetFromPage.md)|Retorna o número da primeira página que está sendo impressa.|  
|[CPrintInfo::GetMaxPage](../Topic/CPrintInfo::GetMaxPage.md)|Retorna o número da última página do documento.|  
|[CPrintInfo::GetMinPage](../Topic/CPrintInfo::GetMinPage.md)|Retorna o número da primeira página do documento.|  
|[CPrintInfo::GetOffsetPage](../Topic/CPrintInfo::GetOffsetPage.md)|Retorna o número das páginas que precede a primeira página de um item de DocObject que está sendo impresso em um trabalho de impressão combinados de DocObject.|  
|[CPrintInfo::GetToPage](../Topic/CPrintInfo::GetToPage.md)|Retorna o número da última página que está sendo impressa.|  
|[CPrintInfo::SetMaxPage](../Topic/CPrintInfo::SetMaxPage.md)|Define o número da última página do documento.|  
|[CPrintInfo::SetMinPage](../Topic/CPrintInfo::SetMinPage.md)|Define o número da primeira página do documento.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPrintInfo::m\_bContinuePrinting](../Topic/CPrintInfo::m_bContinuePrinting.md)|Contém um sinalizador que indica se a estrutura deve continuar o loop de impressão.|  
|[CPrintInfo::m\_bDirect](../Topic/CPrintInfo::m_bDirect.md)|Contém um sinalizador que indica se o documento está sendo impresso diretamente \(sem exibir a caixa de diálogo de impressão\).|  
|[CPrintInfo::m\_bDocObject](../Topic/CPrintInfo::m_bDocObject.md)|Contém um sinalizador que indica se o documento que está sendo impresso é um DocObject.|  
|[CPrintInfo::m\_bPreview](../Topic/CPrintInfo::m_bPreview.md)|Contém um sinalizador que indica se o documento está sendo visualizado.|  
|[CPrintInfo::m\_dwFlags](../Topic/CPrintInfo::m_dwFlags.md)|Especifica operações de impressão de DocObject.|  
|[CPrintInfo::m\_lpUserData](../Topic/CPrintInfo::m_lpUserData.md)|Contém um ponteiro para a estrutura criados pelo usuário.|  
|[CPrintInfo::m\_nCurPage](../Topic/CPrintInfo::m_nCurPage.md)|Identifica o número de página atualmente sendo impressa.|  
|[CPrintInfo::m\_nJobNumber](../Topic/CPrintInfo::m_nJobNumber.md)|Especifica o número de trabalho atribuído pelo sistema operacional para o trabalho de impressão atual|  
|[CPrintInfo::m\_nNumPreviewPages](../Topic/CPrintInfo::m_nNumPreviewPages.md)|Identifica o número de páginas exibidas na janela de visualização; 1 ou 2.|  
|[CPrintInfo::m\_nOffsetPage](../Topic/CPrintInfo::m_nOffsetPage.md)|Especifica o deslocamento de um determinado DocObject os primeiro em um trabalho de impressão combinados de DocObject.|  
|[CPrintInfo::m\_pPD](../Topic/CPrintInfo::m_pPD.md)|Contém um ponteiro para o objeto de `CPrintDialog` usado para a caixa de diálogo de impressão.|  
|[CPrintInfo::m\_rectDraw](../Topic/CPrintInfo::m_rectDraw.md)|Especifica um retângulo que define a área útil da página atual.|  
|[CPrintInfo::m\_strPageDesc](../Topic/CPrintInfo::m_strPageDesc.md)|Contém uma cadeia de caracteres de formato para exibição de páginas número.|  
  
## Comentários  
 `CPrintInfo` é uma estrutura e não tem uma classe base.  
  
 A estrutura cria um objeto de `CPrintInfo` cada vez que o comando de impressão ou de visualização de impressão é escolhido e destrói\-o quando o comando é concluído.  
  
 `CPrintInfo` contém informações sobre o trabalho de impressão no dataset, como o intervalo de páginas ser impresso, e o status atual de trabalho de impressão, como a página que está sendo impressa no momento.  As informações são armazenadas em um objeto associado de [CPrintDialog](../Topic/CPrintDialog%20Class.md) ; este objeto contém os valores inseridos pelo usuário na caixa de diálogo de impressão.  
  
 Um objeto de `CPrintInfo` é transmitido entre a estrutura e a classe de exibição durante o processo de impressão e usado para trocar informações entre os dois.  Por exemplo, a estrutura informa a classe de exibição que a página do documento para imprimir atribuir um valor ao membro de `m_nCurPage` de `CPrintInfo`; a classe de exibição recupera o valor e executa a impressão atual da página especificada.  
  
 Um exemplo é o caso em que o comprimento do documento não é conhecido até ser impresso.  Em esta situação, o teste de classe de exibição para o final do documento sempre que uma página é impressa.  Quando o final é alcançada, a classe de visualização define o membro de `m_bContinuePrinting` de `CPrintInfo` a **Falso**; isso informa a estrutura para interromper o loop de impressão.  
  
 `CPrintInfo` é usado pelas funções de membro de `CView` listados em “consulta também.” Para obter mais informações sobre a arquitetura de impressão fornecida pela biblioteca de classes da Microsoft foundation, consulte [Quadro do windows](../../mfc/frame-windows.md) e [Arquitetura do documento\/exibição](../Topic/Document-View%20Architecture.md) e os artigos [Imprimindo](../../mfc/printing.md) e [imprimir: documentos com várias páginas](../../mfc/multipage-documents.md).  
  
## Hierarquia de herança  
 `CPrintInfo`  
  
## Requisitos  
 **Cabeçalho:** afxext.h  
  
## Consulte também  
 [O MFC exemplos DIBLOOK](../../top/visual-cpp-samples.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [CView::OnBeginPrinting](../Topic/CView::OnBeginPrinting.md)   
 [CView::OnEndPrinting](../Topic/CView::OnEndPrinting.md)   
 [CView::OnEndPrintPreview](../Topic/CView::OnEndPrintPreview.md)   
 [CView::OnPrepareDC](../Topic/CView::OnPrepareDC.md)   
 [CView::OnPreparePrinting](../Topic/CView::OnPreparePrinting.md)   
 [CView::OnPrint](../Topic/CView::OnPrint.md)