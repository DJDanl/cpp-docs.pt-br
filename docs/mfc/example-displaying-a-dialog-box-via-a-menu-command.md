---
title: 'Exemplo: Exibindo uma caixa de diálogo por meio de um comando de menu'
ms.date: 09/07/2019
helpviewer_keywords:
- MFC dialog boxes [MFC], examples
- MFC dialog boxes [MFC], displaying
- modeless dialog boxes [MFC], displaying
- dialog boxes [MFC], MFC
- modal dialog boxes [MFC], displaying
- examples [MFC], dialog boxes
- menu items [MFC], examples
ms.assetid: e8692549-acd7-478f-9c5e-ba310ce8cccd
ms.openlocfilehash: 9b76d481bff6e98b915d71634dbf04a83a432736
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70907738"
---
# <a name="example-displaying-a-dialog-box-via-a-menu-command"></a>Exemplo: Exibindo uma caixa de diálogo por meio de um comando de menu

Este tópico contém procedimentos para:

- Exiba uma caixa de diálogo modal por meio de um comando de menu.

- Exibir uma caixa de diálogo sem janela restrita por meio de um comando de menu.

Ambos os procedimentos de exemplo são para aplicativos MFC e funcionarão em um aplicativo criado com o [Assistente de aplicativo do MFC](../mfc/reference/mfc-application-wizard.md).

Os procedimentos usam os seguintes nomes e valores:

|Item|Nome ou valor|
|----------|-------------------|
|Aplicativo|DisplayDialog|
|Comando de menu|Comando de teste no menu Exibir; ID do comando = ID_VIEW_TEST|
|Caixa de diálogo|Caixa de diálogo testar; Classe = CTestDialog; Arquivo de Cabeçalho = TestDialog. h; Variável = testdlg, ptestdlg|
|Manipulador de comandos|OnViewTest|

### <a name="to-display-a-modal-dialog-box"></a>Para exibir uma caixa de diálogo modal

1. Criar o comando de menu; consulte [criando menus ou itens de menu](../windows/creating-a-menu.md).

1. Criar a caixa de diálogo; consulte [iniciando o editor de caixa de diálogo](../windows/creating-a-new-dialog-box.md).

1. Adicione uma classe à caixa de diálogo. Consulte [adicionando uma classe](../ide/adding-a-class-visual-cpp.md) para obter mais informações.

1. Em **modo de exibição de classe**, selecione a classe de documento (CDisplayDialogDoc). Na janela **Propriedades**, clique no botão **Eventos**. Clique duas vezes na ID do comando de menu (ID_VIEW_TEST). Em seguida, clique na seta para baixo e selecione  **\<Adicionar > OnViewTest**.

   Se você adicionou o comando de menu ao mainframe de um aplicativo MDI, selecione a classe Application (CDisplayDialogApp) em seu lugar.

1. Adicione a seguinte instrução include a CDisplayDialogDoc. cpp (ou CDisplayDialogApp. cpp) após as instruções include existentes:

   ```cpp
   #include "TestDialog.h"
   ```

1. Adicione o seguinte código ao `OnViewTest` para implementar a função:

   ```cpp
   CTestDialog testdlg;
   testdlg.DoModal();  
   ```

### <a name="to-display-a-modeless-dialog-box"></a>Para exibir uma caixa de diálogo sem janela restrita

1. Execute as quatro primeiras etapas para exibir uma caixa de diálogo modal, exceto selecione a classe View (CDisplayDialogView) na etapa 4.

1. Edite DisplayDialogView. h:

   - Declare a classe da caixa de diálogo anterior à primeira declaração de classe:

   ```cpp
   class CTestDialog;
   ```

   - Declare um ponteiro para a caixa de diálogo após a seção atributos públicos:

   ```cpp
   CTestDialog* m_pTestDlg;
   ```

1. Edite DisplayDialogView. cpp:

   - Adicione a seguinte instrução include após as instruções include existentes:

   ```cpp
   #include "TestDialog.h"
   ```

   - Adicione o seguinte código ao construtor:

   ```cpp
   m_pTestDlg = NULL;
   ```

   - Adicione o seguinte código ao destruidor:

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
