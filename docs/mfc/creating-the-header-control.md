---
title: Criando o controle de cabeçalho | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CHeaderCtrl class [MFC], creating
- header controls [MFC], creating
ms.assetid: 7864d9d2-4a2c-4622-b58b-7b110a1e28d2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 18517f969dc64b0c1d9a51bcdc67a1655ec82d7c
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43214003"
---
# <a name="creating-the-header-control"></a>Criando o controle de cabeçalho
O controle de cabeçalho não está diretamente disponível no editor de caixa de diálogo (embora você pode adicionar um controle de lista, que inclui um controle de cabeçalho).  
  
### <a name="to-put-a-header-control-in-a-dialog-box"></a>Para colocar um controle de cabeçalho em uma caixa de diálogo  
  
1.  Inserir manualmente uma variável de membro do tipo [CHeaderCtrl](../mfc/reference/cheaderctrl-class.md) em sua classe de caixa de diálogo.  
  
2.  Na [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog), criar e definir os estilos para o `CHeaderCtrl`, posicioná-lo e exibi-lo.  
  
3.  Adicione itens ao controle de cabeçalho.  
  
4.  Use a janela de propriedades para mapear as funções do manipulador da classe de caixa de diálogo para qualquer notificação de controle de cabeçalho mensagens que você precisa manipular (consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md)).  
  
### <a name="to-put-a-header-control-in-a-view-not-a-clistview"></a>Para colocar um controle de cabeçalho em uma exibição (não um CListView)  
  
1.  Inserir uma [CHeaderCtrl](../mfc/reference/cheaderctrl-class.md) objeto em sua classe de exibição.  
  
2.  Estilo, posição e exibir a janela de controle de cabeçalho no modo de exibição [OnInitialUpdate](../mfc/reference/cview-class.md#oninitialupdate) função de membro.  
  
3.  Adicione itens ao controle de cabeçalho.  
  
4.  Use a janela de propriedades para mapear as funções de manipulador na classe de exibição para qualquer notificação de controle de cabeçalho mensagens que você precisa manipular (consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md)).  
  
 Em ambos os casos, o objeto de controle inserido é criado quando o objeto de exibição ou a caixa de diálogo é criado. Em seguida, você deve chamar [CHeaderCtrl::Create](../mfc/reference/cheaderctrl-class.md#create) para criar a janela de controle. Para posicionar o controle, chame [CHeaderCtrl::Layout](../mfc/reference/cheaderctrl-class.md#layout) para determinar o tamanho inicial e a posição do controle e [SetWindowPos](../mfc/reference/cwnd-class.md#setwindowpos) para definir a posição desejada. Em seguida, adicione itens conforme descrito em [adicionando itens ao controle de cabeçalho](../mfc/adding-items-to-the-header-control.md).  
  
 Para obter mais informações, consulte [criando um controle de cabeçalho](/windows/desktop/Controls/header-controls) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)   
 [Controles](../mfc/controls-mfc.md)

