---
title: Agrupando botões de opção em uma caixa de diálogo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.dialog.grouping
dev_langs:
- C++
helpviewer_keywords:
- member variables, adding to radio button groups
- variables, dialog box control member variables
- dialog box controls, grouping radio buttons
- grouping controls
- radio buttons, grouping on dialog boxes
ms.assetid: 3cc43f9e-56c8-4faa-9930-ce81733c69de
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: aee3245a65ccdccc32b40c313eecdd45cb3ea8bf
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="grouping-radio-buttons-on-a-dialog-box"></a>Agrupando botões de opção em uma caixa de diálogo
Quando você adiciona botões de opção para uma caixa de diálogo, tratá-los como um grupo, definindo uma propriedade de grupo na janela Propriedades para o primeiro botão no grupo. Uma ID de controle de botão de opção que aparece no [Assistente para adição de variável de membro](../ide/add-member-variable-wizard.md), permitindo que você adicione uma variável de membro do grupo de botões de opção.  
  
 Você pode ter mais de um grupo de botões de opção em uma caixa de diálogo, e cada grupo deve ser adicionado usando o procedimento a seguir.  
  
### <a name="to-add-a-group-of-radio-buttons-to-a-dialog-box"></a>Para adicionar um grupo de botões de opção para uma caixa de diálogo  
  
1.  Selecione o controle de botão de opção no [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox) e clique no local na caixa de diálogo onde você deseja colocar o controle.  
  
2.  Repita a etapa 1 para adicionar botões de opção quantas forem necessárias. Verifique se os botões de opção no grupo são consecutivos na ordem de tabulação (para obter mais informações, consulte [alterando a ordem dos controles de guia](../windows/changing-the-tab-order-of-controls.md)).  
  
3.  No [janela propriedades](/visualstudio/ide/reference/properties-window), defina o **grupo** propriedade o *primeiro* botão de opção na ordem de tabulação para **True**.  
  
     Alterando o **grupo** propriedade **True** adiciona o estilo WS_GROUP a entrada do botão no objeto de caixa de diálogo do script de recurso e garante que um usuário pode selecionar apenas um botão de opção por vez no botão grupo (quando o usuário clica em um botão de opção, a outros usuários no grupo são desmarcados).  
  
    > [!NOTE]
    >  Somente o primeiro botão de opção do grupo deve ter o **grupo** propriedade definida como **True**. Se você tiver controles adicionais que não fazem parte do grupo de botões, defina o **grupo** propriedade do primeiro controle *que está fora do grupo* para **True** também. Você pode identificar rapidamente o primeiro controle fora do grupo, pressionando CTRL + D para exibir a ordem de tabulação.  
  
### <a name="to-add-a-member-variable-for-the-radio-button-group"></a>Para adicionar uma variável de membro para o grupo de botões de opção  
  
1.  Clique o controle de botão de opção primeiro na ordem de tabulação (controle dominante e aquele com o **grupo** propriedade definida como True).  
  
2.  Escolha **Adicionar variável** no menu de atalho.  
  
3.  No [assistente Adicionar variável de membro](../ide/add-member-variable-wizard.md), selecione o **variável de controle de** caixa de seleção e, em seguida, selecione o **valor** botão de opção.  
  
4.  No **nome da variável** , digite um nome para a nova variável de membro.  
  
5.  No **tipo de variável** caixa de listagem, selecione **int** ou tipo **int**.  
  
6.  Agora você pode modificar seu código para especificar qual botão de opção deverá aparecer selecionado. Por exemplo, m_radioBox1 = 0; Seleciona o primeiro botão de opção no grupo.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
 Requisitos  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Organização dos controles em caixas de diálogo](../windows/arrangement-of-controls-on-dialog-boxes.md)   
 [Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)   
 [Controles](../mfc/controls-mfc.md)

