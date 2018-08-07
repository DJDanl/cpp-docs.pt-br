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
ms.openlocfilehash: 7712927a10fa34c5b6436aecd002c9621546638b
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39571497"
---
# <a name="grouping-radio-buttons-on-a-dialog-box"></a>Agrupando botões de opção em uma caixa de diálogo
Quando você adiciona botões de opção para uma caixa de diálogo, tratá-los como um grupo, definindo uma propriedade de grupo na janela Propriedades para o primeiro botão no grupo. Então, aparecerá uma ID de controle para esse botão de opção na [Assistente para adição de variável de membro](../ide/add-member-variable-wizard.md), permitindo que você adicione uma variável de membro para o grupo de botões de opção.  
  
 Você pode ter mais de um grupo de botões de opção em uma caixa de diálogo, e cada grupo deve ser adicionado usando o procedimento a seguir.  
  
### <a name="to-add-a-group-of-radio-buttons-to-a-dialog-box"></a>Para adicionar um grupo de botões de opção para uma caixa de diálogo  
  
1.  Selecione o controle de botão de opção na [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox) e clique no local na caixa de diálogo onde você deseja colocar o controle.  
  
2.  Repita a etapa 1 para adicionar botões de opção quantas forem necessárias. Certifique-se de que os botões de opção no grupo são consecutivos na ordem de tabulação (para obter mais informações, consulte [alterando a ordem dos controles da guia](../windows/changing-the-tab-order-of-controls.md)).  
  
3.  No [janela de propriedades](/visualstudio/ide/reference/properties-window), defina o **grupo** propriedade do *primeiro* botão de opção na ordem de tabulação para **True**.  
  
     Alterando a **grupo** propriedade **verdadeiro** adiciona o estilo WS_GROUP a entrada do botão no objeto de caixa de diálogo do script de recurso e garante que um usuário pode selecionar apenas um botão de opção por vez no botão grupo (quando o usuário clica em um botão de opção, os outros no grupo estão desmarcados).  
  
    > [!NOTE]
    >  Somente o primeiro botão de opção no grupo deve ter o **grupo** propriedade definida como **verdadeiro**. Se você tiver controles adicionais que não fazem parte do grupo de botões, defina as **grupo** propriedade do primeiro controle *que está fora do grupo* para **verdadeiro** também. Você pode identificar rapidamente o primeiro controle fora do grupo, pressionando CTRL + D para exibir a ordem de tabulação.  
  
### <a name="to-add-a-member-variable-for-the-radio-button-group"></a>Para adicionar uma variável de membro para o grupo de botões de opção  
  
1.  Clique com botão direito do controle de botão de rádio primeiro na ordem de tabulação (o controle dominante e aquele com o **grupo** propriedade definida como True).  
  
2.  Escolher **Adicionar variável** no menu de atalho.  
  
3.  No [assistente Adicionar variável de membro](../ide/add-member-variable-wizard.md), selecione o **variável de controle** caixa de seleção e, em seguida, selecione o **valor** botão de opção.  
  
4.  No **nome da variável** , digite um nome para a nova variável de membro.  
  
5.  No **tipo de variável** caixa de listagem, selecione **int** ou o tipo **int**.  
  
6.  Agora você pode modificar seu código para especificar qual botão de opção deve aparecer selecionado. Por exemplo, m_radioBox1 = 0; Seleciona o primeiro botão de opção no grupo.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
## <a name="requirements"></a>Requisitos  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Organização de controles em caixas de diálogo](../windows/arrangement-of-controls-on-dialog-boxes.md)   
 [Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)   
 [Controles](../mfc/controls-mfc.md)