---
title: 'Exemplo: Exibindo uma caixa de diálogo por meio de um comando de Menu'
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
ms.openlocfilehash: 1e730125e47609f0bf87814b32962336cb752b04
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62173270"
---
# <a name="example-displaying-a-dialog-box-via-a-menu-command"></a>Exemplo: Exibindo uma caixa de diálogo por meio de um comando de Menu

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

   ```cpp
   #include "TestDialog.h"
   ```

1. Adicione o seguinte código ao `OnViewTest` para implementar a função:

   ```cpp
   CTestDialog testdlg;
   testdlg.DoModal();  
   ```

### <a name="to-display-a-modeless-dialog-box"></a>Para exibir uma caixa de diálogo sem janela restrita

1. Fazer as quatro primeiras etapas para exibir uma caixa de diálogo modal, porém selecione a classe de exibição (CDisplayDialogView) na etapa 4.

1. Edite DisplayDialogView.h:

   - Declare a classe de caixa de diálogo anterior a declaração de primeira classe:

   ```cpp
   class CTestDialog;
   ```

   - Declare um ponteiro para a caixa de diálogo após a seção pública de atributos:

   ```cpp
   CTestDialog* m_pTestDlg;
   ```

1. Edite DisplayDialogView.cpp:

   - Adicione que o seguinte incluir uma instrução depois que o existente inclui instruções:

   ```cpp
   #include "TestDialog.h"
   ```

   - Adicione o seguinte código ao construtor:

   ```cpp
   m_pTestDlg = NULL;
   ```

   - Adicione o seguinte código para o destruidor:

   ```cpp
   delete m_pTestDlg;
   ```

   - Adicione o seguinte código ao `OnViewTest` para implementar a função:

   ```cpp
   if (NULL == m_pTestDlg)
   {
      m_pTestDlg = new CTestDialog(this);
      m_pTestDlg->Create(CTestDialog::IDD, this);
   }
   m_pTestDlg->ShowWindow(SW_SHOW); 
   ```

## <a name="see-also"></a>Consulte também

[Caixas de diálogo](../mfc/dialog-boxes.md)<br/>
[Caixas de diálogo modais e sem janela restrita](../mfc/modal-and-modeless-dialog-boxes.md)
