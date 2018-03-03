---
title: "Exemplo: Exibindo uma caixa de diálogo por meio de um comando de Menu | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- MFC dialog boxes [MFC], examples
- MFC dialog boxes [MFC], displaying
- modeless dialog boxes [MFC], displaying
- dialog boxes [MFC], MFC
- modal dialog boxes [MFC], displaying
- examples [MFC], dialog boxes
- menu items [MFC], examples
ms.assetid: e8692549-acd7-478f-9c5e-ba310ce8cccd
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e2715e1b64c1565d122f6eec012a8a33c2525ac9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="example-displaying-a-dialog-box-via-a-menu-command"></a>Exemplo: exibindo uma caixa de diálogo por meio de um comando Menu
Este tópico contém procedimentos para:  
  
-   Exibe uma caixa de diálogo modal por meio de um comando de menu.  
  
-   Exibe uma caixa de diálogo sem janela restrita por meio de um comando de menu.  
  
 Ambos os procedimentos de exemplo são para aplicativos MFC e funcionará em um aplicativo que você criar com o [Assistente de aplicativo MFC](../mfc/reference/mfc-application-wizard.md).  
  
 Os procedimentos usam os nomes e valores a seguir:  
  
|Item|Nome ou valor|  
|----------|-------------------|  
|Aplicativo|DisplayDialog|  
|Comando de menu|Comando de teste no menu de exibição; ID do comando = ID_VIEW_TEST|  
|Caixa de diálogo|Caixa de diálogo de teste Classe = CTestDialog; Arquivo de cabeçalho = TestDialog.h; Variável = testdlg, ptestdlg|  
|Manipulador de comando|OnViewTest|  
  
### <a name="to-display-a-modal-dialog-box"></a>Para exibir uma caixa de diálogo modal  
  
1.  Criar o comando de menu. consulte [criando Menus ou itens de Menu](../windows/creating-a-menu.md).  
  
2.  Criar a caixa de diálogo; consulte [iniciar o Editor de caixa de diálogo](../windows/creating-a-new-dialog-box.md).  
  
3.  Adicione uma classe para a caixa de diálogo. Consulte [adicionando uma classe](../ide/adding-a-class-visual-cpp.md) para obter mais informações.  
  
4.  Em **exibição de classe**, selecione a classe de documento (CDisplayDialogDoc). Na janela **Propriedades**, clique no botão **Eventos**. Clique duas vezes a ID do comando de menu (ID_VIEW_TEST) no painel esquerdo do **propriedades** janela e selecione **comando**. No painel direito, clique na seta para baixo e selecione  **\<Adicionar > OnViewTest**.  
  
     Se você adicionou o comando de menu para o mainframe de um aplicativo MDI, selecione a classe do aplicativo (CDisplayDialogApp).  
  
5.  Adicione o seguinte incluir a instrução CDisplayDialogDoc.cpp (ou CDisplayDialogApp.cpp) após existente incluir instruções:  
  
     [!code-cpp[NVC_MFCControlLadenDialog#42](../mfc/codesnippet/cpp/example-displaying-a-dialog-box-via-a-menu-command_1.cpp)]  
  
6.  Adicione o seguinte código para `OnViewTest` para implementar a função:  
  
     [!code-cpp[NVC_MFCControlLadenDialog#43](../mfc/codesnippet/cpp/example-displaying-a-dialog-box-via-a-menu-command_2.cpp)]  
  
### <a name="to-display-a-modeless-dialog-box"></a>Para exibir uma caixa de diálogo sem janela restrita  
  
1.  Faça as quatro primeiras etapas para exibir uma caixa de diálogo modal, porém selecione a classe de exibição (CDisplayDialogView) na etapa 4.  
  
2.  Edite DisplayDialogView.h:  
  
    -   Declare a classe de caixa de diálogo anterior a declaração de primeira classe:  
  
         [!code-cpp[NVC_MFCControlLadenDialog#44](../mfc/codesnippet/cpp/example-displaying-a-dialog-box-via-a-menu-command_3.h)]  
  
    -   Declare um ponteiro para a caixa de diálogo após a seção de atributos pública:  
  
         [!code-cpp[NVC_MFCControlLadenDialog#45](../mfc/codesnippet/cpp/example-displaying-a-dialog-box-via-a-menu-command_4.h)]  
  
3.  Edite DisplayDialogView.cpp:  
  
    -   Incluir a seguinte instrução após existente incluir instruções:  
  
         [!code-cpp[NVC_MFCControlLadenDialog#42](../mfc/codesnippet/cpp/example-displaying-a-dialog-box-via-a-menu-command_1.cpp)]  
  
    -   Adicione o seguinte código para o construtor:  
  
         [!code-cpp[NVC_MFCControlLadenDialog#46](../mfc/codesnippet/cpp/example-displaying-a-dialog-box-via-a-menu-command_5.cpp)]  
  
    -   Adicione o seguinte código para o destruidor:  
  
         [!code-cpp[NVC_MFCControlLadenDialog#47](../mfc/codesnippet/cpp/example-displaying-a-dialog-box-via-a-menu-command_6.cpp)]  
  
    -   Adicione o seguinte código para `OnViewTest` para implementar a função:  
  
         [!code-cpp[NVC_MFCControlLadenDialog#48](../mfc/codesnippet/cpp/example-displaying-a-dialog-box-via-a-menu-command_7.cpp)]  
  
 Além disso, consulte o seguinte artigo da Base de dados de Conhecimento:  
  
-   Q251059: Como: fornecer seu próprio nome de classe de janela para uma caixa de diálogo MFC  
  
## <a name="see-also"></a>Consulte também  
 [Caixas de diálogo](../mfc/dialog-boxes.md)   
 [Caixas de diálogo modais e sem janela restrita](../mfc/modal-and-modeless-dialog-boxes.md)

