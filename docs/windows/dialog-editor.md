---
title: Editor de caixa de diálogo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.dialog.dialog
- vc.editors.dialog.F1
dev_langs:
- C++
helpviewer_keywords:
- resource editors, Dialog editor
- editors, dialog boxes
- Dialog editor
- dialog boxes, editing
ms.assetid: d94884ef-2cca-49d8-9b58-775f34848134
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8c2f5339237bec053df6bf26fb161854f83f572a
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39651844"
---
# <a name="dialog-editor"></a>Editor de Caixa de Diálogo
O **caixa de diálogo** editor permite que você criar ou editar os recursos de caixa de diálogo. Abra o editor de caixa de diálogo clicando duas vezes no arquivo. rc da caixa de diálogo do **exibição de recurso** janela (**exibição** > **exibição de recurso**). Observe que **exibição de recurso** não está disponível nas edições Express.  
  
 Uma das primeiras etapas na tomada de uma caixa de diálogo Novo (ou o modelo de caixa de diálogo) é adicionando controles à caixa de diálogo. No **caixa de diálogo** editor, você pode organizar os controles de acordo com um determinado tamanho, forma ou alinhamento, ou você pode movê-los para trabalhar dentro da caixa de diálogo. Também é fácil excluir um controle.  
  
 Você pode armazenar uma caixa de diálogo como um modelo para que você possa reutilizá-lo. Também é fácil, você pode alternar entre a caixa de diálogo de criação e editando o código que implementa a ele.  
  
 Também é possível editar as propriedades de um ou vários controles no editor de caixa de diálogo. Você pode alterar a ordem de tabulação, ou seja, a ordem na qual os controles de obtém foco quando o **guia** tecla é pressionada, ou você pode definir uma chave de acesso (uma combinação de teclas) que permite aos usuários escolher um controle usando o teclado. Para obter uma lista das chaves de acesso predefinidas, consulte [teclas de aceleração para o Editor de caixa de diálogo](../windows/accelerator-keys-for-the-dialog-editor.md).  
  
 O **caixa de diálogo** editor também permite que você use os controles personalizados, incluindo os controles ActiveX. Além disso, você pode editar uma [exibição de formulário](../mfc/reference/cformview-class.md), [exibições de registro](../data/record-views-mfc-data-access.md), ou [barras da caixa de diálogo](../mfc/dialog-bars.md).  
  
 Começando com o Visual Studio 2015, você pode usar o editor de caixa de diálogo para definir layouts dinâmicos, que especificam como os controles de mover e redimensionem quando o usuário redimensiona uma caixa de diálogo. Para obter mais informações, consulte [Layout dinâmico](../mfc/dynamic-layout.md).  
  
-   [Criando uma nova caixa de diálogo](../windows/creating-a-new-dialog-box.md)  
  
-   [Criar uma caixa de diálogo que os usuários não possam sair no tempo de execução](../windows/creating-a-dialog-box-that-users-cannot-exit.md)  
  
-   [Mostrando ou ocultando a barra de ferramentas do Editor de Caixa de Diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md)  
  
-   [Alternar entre o Editor de caixa de diálogo e código](../windows/switching-between-dialog-box-controls-and-code.md)  
  
-   [Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)  
  
-   [Adicionando manipuladores de eventos a controles de caixa de diálogo](../windows/adding-event-handlers-for-dialog-box-controls.md)  
  
-   [Testando uma caixa de diálogo](../windows/testing-a-dialog-box.md)  
  
-   [Teclas de aceleração do Editor de Caixa de Diálogo](../windows/accelerator-keys-for-the-dialog-editor.md)  
  
-   [Solução de problemas do Editor de Caixa de Diálogo](../windows/troubleshooting-the-dialog-editor.md)  
  
    > [!TIP]
    >  Ao usar o **caixa de diálogo** editor, em muitos casos, você pode clicar no botão direito do mouse para exibir um menu de atalho de comandos usados com frequência.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Editores de recursos](../windows/resource-editors.md)   
 [Controles](../mfc/controls-mfc.md)   
 [Classes de controle](../mfc/control-classes.md)   
 [Classes de caixa de diálogo](../mfc/dialog-box-classes.md)   
 [Controles da caixa de diálogo e tipos de variável](../ide/dialog-box-controls-and-variable-types.md)