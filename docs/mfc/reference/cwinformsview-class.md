---
title: "Classe de CWinFormsView | Microsoft Docs"
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
  - "CWinFormsView"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CWinFormsView"
  - "MFC [C++], Suporte de formulários do windows"
  - "Formulários do Windows [C++], Suporte MFC"
ms.assetid: d597e397-6529-469b-88f5-7f65a6b9e895
caps.latest.revision: 26
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CWinFormsView
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade de genérico para hospedar um controle de formulários do windows como uma visualização MFC.  
  
## Sintaxe  
  
```  
class CWinFormsView : public CView;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWinFormsView::CWinFormsView](../Topic/CWinFormsView::CWinFormsView.md)|Constrói um objeto de `CWinFormsView` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWinFormsView::GetControl](../Topic/CWinFormsView::GetControl.md)|Recupera um ponteiro para o controle de formulários do windows.|  
  
### Operadores públicos  
  
|Nome||  
|----------|-|  
|[CWinFormsView::operator Control^](../Topic/CWinFormsView::operator%20Control%5E.md)|Converter um tipo como um ponteiro para um controle de formulários do windows.|  
  
## Comentários  
 O MFC usa a classe de `CWinFormsView` para hospedar um controle de formulários do windows do .NET Framework em uma visualização MFC.  O controle é um filho de exibição nativo e ocupa toda a área cliente do MFC.  O resultado é semelhante a uma visualização de `CFormView` , permitir que você aproveite do windows forms designer e o tempo de execução criar modos de exibição baseada em formulários usando ricas.  
  
 Para obter mais informações sobre como usar formulários do windows, consulte [Usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  
> [!NOTE]
>  O MFC windows trabalho de integração somente nos projetos que vinculam dinamicamente com MFC \(os projetos em AFXDLL que é definido\).  
  
> [!NOTE]
>  CWinFormsView não oferece suporte a janela separator MFC \([Classe de CSplitterWnd](../../mfc/reference/csplitterwnd-class.md)\).  Somente o controle separator de formulários do windows \(<xref:System.Windows.Forms.Splitter>\) é suportado atualmente.  
  
## Requisitos  
 **Cabeçalho:** afxwinforms.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CWinFormsControl](../../mfc/reference/cwinformscontrol-class.md)   
 [Classe de CWinFormsDialog](../Topic/CWinFormsDialog%20Class.md)   
 [Classe de CFormView](../../mfc/reference/cformview-class.md)