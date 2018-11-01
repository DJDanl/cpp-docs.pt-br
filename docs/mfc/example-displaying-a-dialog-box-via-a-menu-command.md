---
title: 'Exemplo: exibindo uma caixa de diálogo por meio de um comando Menu'
ms.date: 11/04/2016
helpviewer_keywords:
- MFC dialog boxes [MFC], examples
- MFC dialog boxes [MFC], displaying
- modeless dialog boxes [MFC], displaying
- dialog boxes [MFC], MFC
- modal dialog boxes [MFC], displaying
- examples [MFC], dialog boxes
- menu items [MFC], examples
ms.assetid: e8692549-acd7-478f-9c5e-ba310ce8cccd
ms.openlocfilehash: 830ba27945ce8da2abd52c7f29d786d098113151
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50483480"
---
# <a name="example-displaying-a-dialog-box-via-a-menu-command"></a>Exemplo: exibindo uma caixa de diálogo por meio de um comando Menu

Este tópico contém procedimentos para:

- Exiba uma caixa de diálogo modal por meio de um comando de menu.

- Exiba uma caixa de diálogo sem janela restrita por meio de um comando de menu.

Ambos os procedimentos de exemplo são para aplicativos MFC e funcionará em um aplicativo que você criar com o [Assistente de aplicativo MFC](../mfc/reference/mfc-application-wizard.md).

Os procedimentos usam os nomes e valores a seguir:

|Item|Nome ou valor|
|----------|-------------------|
|Aplicativo|DisplayDialog|
|Comando de menu|Testar o comando de menu do modo de exibição; ID do comando = ID_VIEW_TEST|
|Caixa de diálogo|Caixa de diálogo de teste; Classe = CTestDialog; Arquivo de cabeçalho = TestDialog.h; Variável = testdlg, ptestdlg|
|Manipulador de comandos|OnViewTest|

### <a name="to-display-a-modal-dialog-box"></a>Para exibir uma caixa de diálogo modal

1. Criar o comando de menu. ver [criando Menus ou itens de Menu](../windows/creating-a-menu.md).

1. Criar a caixa de diálogo; ver [iniciar o Editor de caixa de diálogo](../windows/creating-a-new-dialog-box.md).

1. Adicione uma classe para sua caixa de diálogo. Ver [adicionando uma classe](../ide/adding-a-class-visual-cpp.md) para obter mais informações.

1. Na **modo de exibição de classe**, selecione a classe de documento (CDisplayDialogDoc). Na janela **Propriedades**, clique no botão **Eventos**. Clique duas vezes a ID do comando menu (ID_VIEW_TEST) no painel esquerdo do **propriedades** janela e selecione **comando**. No painel direito, clique na seta para baixo e selecione  **\<Adicionar > OnViewTest**.

   Se você tiver adicionado o comando de menu ao mainframe de um aplicativo MDI, selecione a classe de aplicativo (CDisplayDialogApp) em vez disso.

1. Adicione a seguinte instrução CDisplayDialogDoc.cpp (ou CDisplayDialogApp.cpp) de inclusão depois existente inclui instruções:

   [!code-cpp[NVC_MFCControlLadenDialog#42](../mfc/codesnippet/cpp/example-displaying-a-dialog-box-via-a-menu-command_1.cpp)]

1. Adicione o seguinte código ao `OnViewTest` para implementar a função:

   [!code-cpp[NVC_MFCControlLadenDialog#43](../mfc/codesnippet/cpp/example-displaying-a-dialog-box-via-a-menu-command_2.cpp)]

### <a name="to-display-a-modeless-dialog-box"></a>Para exibir uma caixa de diálogo sem janela restrita

1. Fazer as quatro primeiras etapas para exibir uma caixa de diálogo modal, porém selecione a classe de exibição (CDisplayDialogView) na etapa 4.

1. Edite DisplayDialogView.h:

   - Declare a classe de caixa de diálogo anterior a declaração de primeira classe:

         [!code-cpp[NVC_MFCControlLadenDialog#44](../mfc/codesnippet/cpp/example-displaying-a-dialog-box-via-a-menu-command_3.h)]

   - Declare um ponteiro para a caixa de diálogo após a seção pública de atributos:

         [!code-cpp[NVC_MFCControlLadenDialog#45](../mfc/codesnippet/cpp/example-displaying-a-dialog-box-via-a-menu-command_4.h)]

1. Edite DisplayDialogView.cpp:

   - Adicione que o seguinte incluir uma instrução depois que o existente inclui instruções:

         [!code-cpp[NVC_MFCControlLadenDialog#42](../mfc/codesnippet/cpp/example-displaying-a-dialog-box-via-a-menu-command_1.cpp)]

   - Adicione o seguinte código ao construtor:

         [!code-cpp[NVC_MFCControlLadenDialog#46](../mfc/codesnippet/cpp/example-displaying-a-dialog-box-via-a-menu-command_5.cpp)]

   - Adicione o seguinte código para o destruidor:

         [!code-cpp[NVC_MFCControlLadenDialog#47](../mfc/codesnippet/cpp/example-displaying-a-dialog-box-via-a-menu-command_6.cpp)]

   - Adicione o seguinte código ao `OnViewTest` para implementar a função:

         [!code-cpp[NVC_MFCControlLadenDialog#48](../mfc/codesnippet/cpp/example-displaying-a-dialog-box-via-a-menu-command_7.cpp)]

## <a name="see-also"></a>Consulte também

[Caixas de diálogo](../mfc/dialog-boxes.md)<br/>
[Caixas de diálogo modais e sem janela restrita](../mfc/modal-and-modeless-dialog-boxes.md)
