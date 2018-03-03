---
title: Exibir Classes (arquitetura) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.classes.view
dev_langs:
- C++
helpviewer_keywords:
- form and record views [MFC]
- view classes [MFC]
- control views [MFC]
- view classes [MFC], architecture
ms.assetid: 8894579a-1436-441e-b985-83711061e495
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8b2761253da0907b1736754068fa196dda361a8d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="view-classes-architecture"></a>Classes de exibição (arquitetura)
`CView`e suas classes derivadas são janelas filho que representam a área cliente de uma janela do quadro. Modos de exibição mostram dados e aceitam entrada de um documento.  
  
 Uma classe de exibição está associada uma classe de documento e uma classe de janela do quadro usando um objeto de modelo de documento.  
  
 [CView](../mfc/reference/cview-class.md)  
 A classe base para modos de exibição específicos do aplicativo de dados do documento. Modos de exibição exibem dados e aceitam a entrada do usuário para editar ou selecionar os dados. Derive sua classe de exibição de `CView`.  
  
 [CScrollView](../mfc/reference/cscrollview-class.md)  
 A classe base para visualizações com recursos de rolagem. Derive sua classe de exibição da `CScrollView` de rolagem automática.  
  
## <a name="form-and-record-views"></a>Formulário e exibições de registro  
 Modos de exibição de formulário também são rolando exibições. Eles se baseiam em um modelo de caixa de diálogo.  
  
 Exibições de registro são derivadas de modos de exibição de formulário. Além do modelo de caixa de diálogo, eles também têm uma conexão para um banco de dados.  
  
 [CFormView](../mfc/reference/cformview-class.md)  
 Um modo de exibição de rolagem cujo layout é definido em um modelo de caixa de diálogo. Derive uma classe de `CFormView` para implementar uma interface de usuário com base em um modelo de caixa de diálogo.  
  
 [CDaoRecordView](../mfc/reference/cdaorecordview-class.md)  
 Fornece um formulário de exibição conectada diretamente a um objeto de conjunto de registros do objeto de acesso a dados (DAO). Como todos os modos de exibição de formulário, um `CDaoRecordView` baseia-se em um modelo de caixa de diálogo.  
  
 [CHtmlView](../mfc/reference/chtmlview-class.md)  
 Oferece suporte a um controle de navegação na Web em um aplicativo. O controle oferece suporte a HTML dinâmico em MFC.  
  
 [COLEDBRecordView](../mfc/reference/coledbrecordview-class.md)  
 Fornece suporte de OLE DB MFC para modos de exibição de formulário.  
  
 [CRecordView](../mfc/reference/crecordview-class.md)  
 Fornece um formulário de exibição conectada diretamente a um objeto de conjunto de registros de conectividade de banco de dados aberto (ODBC). Como todos os modos de exibição de formulário, um `CRecordView` baseia-se em um modelo de caixa de diálogo.  
  
## <a name="control-views"></a>Modos de exibição de controle  
 Modos de exibição de controle exibem um controle como sua exibição.  
  
 [CCtrlView](../mfc/reference/cctrlview-class.md)  
 A classe base para todos os modos de exibição associados a controles de Windows. Os modos de exibição com base nos controles descritos abaixo.  
  
 [CEditView](../mfc/reference/ceditview-class.md)  
 Controle de edição de uma exibição que contém um padrão de Windows (consulte [CEdit](../mfc/reference/cedit-class.md)). Edite controles suporte de edição, pesquisar, substituindo e recursos de rolagem.  
  
 [CRichEditView](../mfc/reference/cricheditview-class.md)  
 Controle de edição de uma exibição que contém um avançado do Windows (consulte [CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)). Além dos recursos de um controle de edição, edição avançada controles suporte fontes, cores, formatação de parágrafo e objetos OLE inseridos.  
  
 [CListView](../mfc/reference/clistview-class.md)  
 Uma exibição que contém um controle de lista do Windows (consulte [CListCtrl](../mfc/reference/clistctrl-class.md)). Um controle de lista exibe os ícones e cadeias de caracteres de maneira semelhante para o painel direito do Explorador de arquivos.  
  
 [CTreeView](../mfc/reference/ctreeview-class.md)  
 Uma exibição que contém um controle de árvore do Windows (consulte [CTreeCtrl](../mfc/reference/ctreectrl-class.md)). Um controle de árvore exibe ícones e organizadas em uma hierarquia de maneira semelhante ao painel esquerdo do Explorador de arquivos de cadeias de caracteres.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

