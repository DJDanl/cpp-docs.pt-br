---
title: Criando o controle de guia | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- TCS_EX_REGISTERDROP
- TCS_EX_FLATSEPARATORS
dev_langs:
- C++
helpviewer_keywords:
- TCS_EX_REGISTERDROP extended style [MFC]
- tab controls [MFC], creating
- CTabCtrl class [MFC], creating
- TCS_EX_FLATSEPARATORS extended style
ms.assetid: 3a9c2d64-f5f4-41ea-84ab-fceb73c3dbdc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3945d441130d723bbda3d137f2adae637d56c2b6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33344085"
---
# <a name="creating-the-tab-control"></a>Criando o controle de tabulação
Como o controle de guia é criado depende se você estiver usando o controle em uma caixa de diálogo ou criá-lo em uma janela nondialog.  
  
### <a name="to-use-ctabctrl-directly-in-a-dialog-box"></a>Para usar CTabCtrl diretamente em uma caixa de diálogo  
  
1.  No editor de caixa de diálogo, adicione um controle de guia para o recurso de modelo de caixa de diálogo. Especifique sua ID de controle.  
  
2.  Use o [Assistente para adição de variável de membro](../ide/adding-a-member-variable-visual-cpp.md) para adicionar uma variável de membro de tipo [CTabCtrl](../mfc/reference/ctabctrl-class.md) com a propriedade de controle. Você pode usar este membro para chamar `CTabCtrl` funções de membro.  
  
3.  Funções de manipulador na classe de caixa de diálogo de quaisquer mensagens de notificação de controle de guia que você precisa tratar do mapa. Para obter mais informações, consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md).  
  
4.  Em [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog), definir os estilos para o `CTabCtrl`.  
  
### <a name="to-use-ctabctrl-in-a-nondialog-window"></a>Para usar CTabCtrl em uma janela de nondialog  
  
1.  Defina o controle nas classes de exibição ou janela.  
  
2.  O controle de chamada [criar](../mfc/reference/ctabctrl-class.md#create) função de membro, possivelmente em [OnInitialUpdate](../mfc/reference/cview-class.md#oninitialupdate), possivelmente como antecipado como a janela pai [OnCreate](../mfc/reference/cwnd-class.md#oncreate) (se você tiver a função do manipulador Subclassificação do controle). Defina estilos para o controle.  
  
 Após o `CTabCtrl` objeto tiver sido criado, você pode definir ou limpar procedimentos estendidos estilos:  
  
-   **TCS_EX_FLATSEPARATORS** o controle da guia desenhará separadores entre os itens da guia. Esse estilo estendido somente afeta guia controles que têm o **TCS_BUTTONS** e **TCS_FLATBUTTONS** estilos. Por padrão, o controle de guia com a criação de **TCS_FLATBUTTONS** estilo define esse estilo estendido.  
  
-   **TCS_EX_REGISTERDROP** gera controle guia **TCN_GETOBJECT** mensagens de notificação para solicitar um destino do objeto quando um objeto é arrastado sobre os itens da guia no controle.  
  
    > [!NOTE]
    >  Para receber o **TCN_GETOBJECT** notificação, você deverá inicializar as bibliotecas OLE com uma chamada para [AfxOleInit](../mfc/reference/ole-initialization.md#afxoleinit).  
  
 Esses estilos podem ser recuperados e definir, depois que o controle foi criado, com o respectivas chamadas para o [GetExtendedStyle](../mfc/reference/ctabctrl-class.md#getextendedstyle) e [SetExtendedStyle](../mfc/reference/ctabctrl-class.md#setextendedstyle) funções de membro.  
  
 Por exemplo, definir a **TCS_EX_FLATSEPARATORS** estilo com linhas de código a seguir:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#33](../mfc/codesnippet/cpp/creating-the-tab-control_1.cpp)]  
  
 Limpar o **TCS_EX_FLATSEPARATORS** de estilo de um `CTabCtrl` objeto com as seguintes linhas de código:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#34](../mfc/codesnippet/cpp/creating-the-tab-control_2.cpp)]  
  
 Isso removerá os separadores de aparecem entre os botões do seu `CTabCtrl` objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTabCtrl](../mfc/using-ctabctrl.md)   
 [Controles](../mfc/controls-mfc.md)

