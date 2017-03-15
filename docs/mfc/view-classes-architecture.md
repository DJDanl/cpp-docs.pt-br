---
title: "Classes de exibi&#231;&#227;o (arquitetura) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.classes.view"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "exibições de controle"
  - "exibições de formulário e registro"
  - "classes de exibição"
  - "classes de exibição, arquitetura"
ms.assetid: 8894579a-1436-441e-b985-83711061e495
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de exibi&#231;&#227;o (arquitetura)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

`CView` e suas classes derivadas são as janelas filho que representam a área do cliente de uma janela do quadro.  As exibições mostram dados e aceitam entrada para um documento.  
  
 Uma classe da exibição é associada a uma classe do documento e uma classe da janela do tableau que usa um objeto de documento modelo.  
  
 [CView](../Topic/CView%20Class.md)  
 A classe base para exibições específicas do aplicativo de dados de um documento.  Os dados da exibição das exibições e aceitam entrada do usuário para editar ou selecionar os dados.  Derivar a sua classe da exibição de `CView`.  
  
 [CScrollView](../mfc/reference/cscrollview-class.md)  
 A classe base para exibições com recursos de rolagem.  Derivar a sua classe da exibição de `CScrollView` para a rolagem automático.  
  
## Exibições de formulário e registrar  
 As exibições de formulário também são spool exibições.  Com base em um modelo da caixa de diálogo.  
  
 As exibições de registro são derivadas das exibições de formulário.  Além do modelo da caixa de diálogo, também têm uma conexão a um base de dados.  
  
 [CFormView](../mfc/reference/cformview-class.md)  
 Uma exibição de rolagem cujo layout é definido em um modelo da caixa de diálogo.  Derivar uma classe de `CFormView` para implementar uma interface do usuário com base em um modelo da caixa de diálogo.  
  
 [CDaoRecordView](../mfc/reference/cdaorecordview-class.md)  
 Fornece uma exibição de formulário conectada diretamente a um objeto do conjunto de registros \(DAO\) de objeto de acesso a dados.  Como todas as exibições de formulário, `CDaoRecordView` é baseado em um modelo da caixa de diálogo.  
  
 [CHtmlView](../mfc/reference/chtmlview-class.md)  
 Oferece suporte a um controle para a Web que procura em um aplicativo.  O controle oferece suporte a HTML dinâmico em MFC.  
  
 [COLEDBRecordView](../mfc/reference/coledbrecordview-class.md)  
 O oferece suporte de MFC OLE DB para exibições de formulário.  
  
 [CRecordView](../mfc/reference/crecordview-class.md)  
 Fornece uma exibição de formulário conectada diretamente a um objeto do conjunto de registros de ODBC.  Como todas as exibições de formulário, `CRecordView` é baseado em um modelo da caixa de diálogo.  
  
## Controle exibições  
 As exibições de controle exibem um controle como sua exibição.  
  
 [CCtrlView](../mfc/reference/cctrlview-class.md)  
 Qualquer classe base para exibe associado aos controles do windows.  Exibições com base em controles são descritas abaixo.  
  
 [CEditView](../Topic/CEditView%20Class.md)  
 Uma exibição que contém um controle de edição padrão do windows \(consulte [CEdit](../Topic/CEdit%20Class.md)\).  Os controles de edição dão suporte à edição de texto, pesquisando, substituindo, e rolando recursos.  
  
 [CRichEditView](../mfc/reference/cricheditview-class.md)  
 Uma exibição que contém um controle de edição avançado do windows \(consulte [CRichEditCtrl](../Topic/CRichEditCtrl%20Class.md)\).  Além dos recursos de um controle de edição, os controles de edição um amplo suporte para fontes, cores, formatação de parágrafo, e objetos OLE inseridos.  
  
 [CListView](../mfc/reference/clistview-class.md)  
 Uma exibição que contém o lista o controle [CListCtrl](../Topic/CListCtrl%20Class.md)\(consulte\).  Um controle da lista exibe os ícones e as cadeias de caracteres de forma semelhante ao painel direito do Explorador de Arquivos.  
  
 [CTreeView](../mfc/reference/ctreeview-class.md)  
 Uma exibição que contém um controle de árvore do windows \(consulte [CTreeCtrl](../mfc/reference/ctreectrl-class.md)\).  Ícones e cadeias de caracteres vídeos de um controle de árvore organizados em uma hierarquia de modo semelhante ao painel esquerdo do Explorador de Arquivos.  
  
## Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)