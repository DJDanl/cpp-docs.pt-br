---
title: Criando o controle de lista | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CListCtrl class [MFC], creating control
- list controls [MFC]
ms.assetid: a4cb1729-31b6-4d2b-a44b-367474848a39
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 42457e223bb7e12da64be54d757e05d0bac3a028
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33342040"
---
# <a name="creating-the-list-control"></a>Criando o controle de lista
Como a lista de controle ([CListCtrl](../mfc/reference/clistctrl-class.md)) é criada depende se você estiver usando o controle diretamente ou usando a classe [CListView](../mfc/reference/clistview-class.md) em vez disso. Se você usar `CListView`, a estrutura constrói o modo de exibição como parte da sua sequência de criação de documento/exibição. Criar o modo de exibição de lista cria o controle de lista também (os dois são iguais). O controle é criado no modo de exibição [OnCreate](../mfc/reference/cwnd-class.md#oncreate) função do manipulador. Nesse caso, o controle está pronto para adicionar itens, por meio de uma chamada para [GetListCtrl](../mfc/reference/clistview-class.md#getlistctrl).  
  
### <a name="to-use-clistctrl-directly-in-a-dialog-box"></a>Para usar CListCtrl diretamente em uma caixa de diálogo  
  
1.  No editor de caixa de diálogo, adicione um controle de lista para o recurso de modelo de caixa de diálogo. Especifique sua ID de controle.  
  
2.  Use o [Assistente para adição de variável de membro](../ide/adding-a-member-variable-visual-cpp.md) para adicionar uma variável de membro de tipo `CListCtrl` com a propriedade de controle. Você pode usar este membro para chamar `CListCtrl` funções de membro.  
  
3.  Use a janela Propriedades para mapear as funções de manipulador da classe de caixa de diálogo para mensagens de qualquer notificação de controle de lista, você precisa tratar (consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md)).  
  
4.  Em [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog), definir os estilos para o `CListCtrl`. Consulte [alterando estilos de controle de lista](../mfc/changing-list-control-styles.md). Isso determina o tipo de "view" estiver no controle, embora você possa alterar o modo de exibição mais tarde.  
  
### <a name="to-use-clistctrl-in-a-nondialog-window"></a>Para usar uma janela de nondialog CListCtrl  
  
1.  Defina o controle nas classes de exibição ou janela.  
  
2.  O controle de chamada [criar](../mfc/reference/clistctrl-class.md#create) função de membro, possivelmente em [OnInitialUpdate](../mfc/reference/cview-class.md#oninitialupdate), possivelmente como antecipado como a janela pai [OnCreate](../mfc/reference/cwnd-class.md#oncreate) (se você tiver a função do manipulador Subclassificação do controle). Defina estilos para o controle.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CListCtrl](../mfc/using-clistctrl.md)   
 [Controles](../mfc/controls-mfc.md)

