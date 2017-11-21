---
title: Exibir Classes (Windows) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.classes.view
dev_langs: C++
helpviewer_keywords:
- form and record views [MFC]
- splitter window classes [MFC]
- view classes [MFC], Windows
ms.assetid: b11683fb-9f43-4de3-9499-2b55775f9870
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 0148ead7a978389f763efbe9ee6306ec7a5839cd
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="view-classes-windows"></a>Classes de exibição (Windows)
`CView`e suas classes derivadas são janelas filho que representam a área cliente de uma janela do quadro. Modos de exibição mostram dados e aceitam entrada de um documento.  
  
 Uma classe de exibição está associada uma classe de documento e uma classe de janela do quadro usando um objeto de modelo de documento.  
  
 [CView](../mfc/reference/cview-class.md)  
 A classe base para modos de exibição específicos do aplicativo de dados do documento. Modos de exibição exibem dados e aceitam a entrada do usuário para editar ou selecionar os dados. Derive a classe de exibição ou classes de `CView`.  
  
 [CScrollView](../mfc/reference/cscrollview-class.md)  
 A classe base para visualizações com recursos de rolagem. Derive sua classe de exibição da `CScrollView` de rolagem automática.  
  
## <a name="form-and-record-views"></a>Formulário e exibições de registro  
 Modos de exibição de formulário também são rolando exibições. Eles se baseiam em um modelo de caixa de diálogo.  
  
 Exibições de registro são derivadas de modos de exibição de formulário. Além do modelo de caixa de diálogo, eles também têm uma conexão para um banco de dados.  
  
 [CFormView](../mfc/reference/cformview-class.md)  
 Um modo de exibição de rolagem cujo layout é definido em um modelo de caixa de diálogo. Derive uma classe de `CFormView` para implementar uma interface de usuário com base em um modelo de caixa de diálogo.  
  
 [CDaoRecordView](../mfc/reference/cdaorecordview-class.md)  
 Fornece um formulário de exibição conectada diretamente a um objeto de conjunto de registros do objeto de acesso a dados (DAO). Como todos os modos de exibição de formulário, um `CDaoRecordView` baseia-se em um modelo de caixa de diálogo.  
  
 [CRecordView](../mfc/reference/crecordview-class.md)  
 Fornece um formulário de exibição conectada diretamente a um objeto de conjunto de registros de conectividade de banco de dados aberto (ODBC). Como todos os modos de exibição de formulário, um `CRecordView` baseia-se em um modelo de caixa de diálogo.  
  
 [CHtmlEditView](../mfc/reference/chtmleditview-class.md)  
 Um modo de exibição de formulário que fornece a funcionalidade da plataforma de edição de HTML de WebBrowser.  
  
## <a name="control-views"></a>Modos de exibição de controle  
 Modos de exibição de controle exibem um controle como sua exibição.  
  
 [CCtrlView](../mfc/reference/cctrlview-class.md)  
 A classe base para todos os modos de exibição associados a controles de Windows. Os modos de exibição com base nos controles descritos abaixo.  
  
 [CEditView](../mfc/reference/ceditview-class.md)  
 Controle de edição de uma exibição que contém um padrão de Windows (consulte [CEdit](../mfc/reference/cedit-class.md)). Edite controles suporte de edição, pesquisar, substituindo e recursos de rolagem.  
  
 [CRichEditView](../mfc/reference/cricheditview-class.md)  
 Controle de edição de uma exibição que contém um avançado do Windows (consulte [CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)). Além dos recursos de um controle de edição, edição avançada controles suporte fontes, cores, formatação de parágrafo e objetos OLE inseridos.  
  
 [CListView](../mfc/reference/clistview-class.md)  
 Uma exibição que contém um controle de lista do Windows (consulte [CListCtrl](../mfc/reference/clistctrl-class.md)). Um controle de lista exibe uma coleção de itens, cada consiste em um ícone e um rótulo, de maneira semelhante para o painel direito do Explorador de arquivos.  
  
 [CTreeView](../mfc/reference/ctreeview-class.md)  
 Uma exibição que contém um controle de árvore do Windows (consulte [CTreeCtrl](../mfc/reference/ctreectrl-class.md)). Um controle de árvore exibe uma lista hierárquica de ícones e rótulos organizados de maneira semelhante ao painel esquerdo do Explorador de arquivos.  
  
## <a name="related-classes"></a>Classes relacionadas  
 `CSplitterWnd`permite que você tenha vários modos de exibição em uma janela do quadro. `CPrintDialog`e `CPrintInfo` suporte para o recurso de impressão e visualização de impressão dos modos de exibição. `CRichEditDoc`e `CRichEditCntrItem` são usados com `CRichEditView` para implementar recursos de contêiner OLE.  
  
 [CSplitterWnd](../mfc/reference/csplitterwnd-class.md)  
 Uma janela que o usuário pode ser dividida em vários painéis. Esses painéis podem ser redimensionáveis pelo usuário ou tamanho fixo.  
  
 [CPrintDialog](../mfc/reference/cprintdialog-class.md)  
 Fornece uma caixa de diálogo padrão para imprimir um arquivo.  
  
 [CPrintInfo](../mfc/reference/cprintinfo-structure.md)  
 Uma estrutura que contém informações sobre um trabalho de visualização de impressão ou impressão. Usado por `CView`da arquitetura de impressão.  
  
 [CRichEditDoc](../mfc/reference/cricheditdoc-class.md)  
 Mantém a lista de itens de cliente OLE que estão em um `CRichEditView`.  
  
 [CRichEditCntrItem](../mfc/reference/cricheditcntritem-class.md)  
 Fornece acesso de cliente para uma OLE item armazenada em um `CRichEditView`.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

