---
title: Como definir o acesso e os valores de controleC++()
ms.date: 02/15/2019
helpviewer_keywords:
- access keys [C++], adding
- keyboard shortcuts [C++], controls
- dialog box controls [C++], mnemonics
- access keys [C++], checking
- mnemonics [C++], checking for duplicate
- mnemonics
- mnemonics [C++], dialog box controls
- keyboard shortcuts [C++], uniqueness checking
- Check Mnemonics command
- controls [C++], access keys
- access keys [C++]
- combo boxes [C++], Data property
- controls [C++], testing values in combo boxes
- combo boxes [C++], adding values
- combo boxes [C++], previewing values
- Data property
- combo boxes [C++], testing values
ms.assetid: 60a85435-aa30-4c5c-98b6-42fb045b9eb2
ms.openlocfilehash: 8ebd8d48b68581bf00215b4ca14f5ac0a543a3c0
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79443904"
---
# <a name="how-to-define-control-access-and-values-c"></a>Como definir o acesso e os valores de controleC++()

## <a name="tab-order"></a>Ordem de tabulação

A ordem de tabulação é a ordem na qual a tecla **Tab** move o foco de entrada de um controle para o próximo dentro de uma caixa de diálogo. Geralmente, a ordem de tabulação prossegue da esquerda para a direita e de cima para baixo em uma caixa de diálogo. Cada controle tem uma propriedade **TabStop** que determina se um controle recebe o foco de entrada.

- Para definir o foco de entrada para um controle, na [janela Propriedades](/visualstudio/ide/reference/properties-window), selecione **verdadeiro** ou **falso** na propriedade **TabStop** .

Até mesmo controles que não têm a propriedade **TabStop** definida como **true** precisam fazer parte da ordem de tabulação, especialmente para controles que não têm legendas. O texto estático que contém uma tecla de acesso para um controle relacionado deve preceder imediatamente o controle relacionado na ordem de tabulação.

> [!NOTE]
> Se a caixa de diálogo contiver controles sobrepostos, a alteração da ordem de tabulação poderá mudar a maneira como os controles são exibidos. Os controles que são fornecidos posteriormente na ordem de tabulação são sempre exibidos na parte superior de todos os controles sobrepostos que os precedem na ordem de tabulação.

- Para exibir a ordem de tabulação atual de todos os controles, vá para **formato** de menu > **ordem de tabulação**ou pressione **Ctrl** + **D**.

   Um número no canto superior esquerdo de cada controle mostra seu lugar na ordem de tabulação atual.

- Para alterar a ordem de tabulação de todos os controles, vá para o **formato** de menu > **ordem de tabulação** e defina a ordem de tabulação selecionando cada controle na ordem que você deseja que a tecla **Tab** siga.

- Para alterar a ordem de tabulação de dois ou mais controles, vá para **formato** de menu > **ordem de tabulação**. Mantenha a tecla **Ctrl** pressionada e selecione o controle em que a alteração deve ser iniciada e, em seguida, solte a tecla **Ctrl** e selecione os controles na ordem que você deseja que a tecla **Tab** acompanhe a partir desse ponto.

   Por exemplo, se você quiser alterar a ordem dos controles `7` por meio de `9`, mantenha pressionada a **tecla CTRL**e, em seguida, selecione controlar `6` primeiro.

- Para definir um controle específico para número `1`ou primeiro na ordem de tabulação, clique duas vezes no controle.

> [!TIP]
> Depois de inserir o modo de **ordem de tabulação** , pressione **ESC** ou **Enter** para sair do modo de **ordem de tabulação** e desabilitar a capacidade de alterar a ordem de tabulação.

## <a name="mnemonics-access-keys"></a>Mnemônicos (chaves de acesso)

Normalmente, os usuários de teclado movem o foco de entrada de um controle para outro em uma caixa de diálogo com as teclas **Tab** e **Arrow** . No entanto, você pode definir uma chave de acesso (um nome de mnemônico ou de fácil memorização) que permite aos usuários escolher um controle pressionando uma única chave.

### <a name="to-define-an-access-key-for-a-control-with-a-visible-caption-push-buttons-check-boxes-and-radio-buttons"></a>Para definir uma tecla de acesso para um controle com uma legenda visível (botões de push, caixas de seleção e botões de opção)

1. Selecione o controle na caixa de diálogo.

1. Na [janela Propriedades](/visualstudio/ide/reference/properties-window), na propriedade **legenda** , digite um novo nome para o controle, digitando um e comercial (`&`) na frente da letra que você deseja como a tecla de acesso para esse controle. Por exemplo, `&Radio1`.

1. Pressione **Enter**.

   Um sublinhado aparece na legenda exibida para indicar a chave de acesso, por exemplo, **R**adio1.

### <a name="to-define-an-access-key-for-a-control-without-a-visible-caption"></a>Para definir uma chave de acesso para um controle sem uma legenda visível

1. Crie uma legenda para o controle usando um controle de **texto estático** na [caixa de ferramentas](/visualstudio/ide/reference/toolbox).

1. Na legenda de texto estático, digite um e comercial (`&`) na frente da letra que você deseja como a tecla de acesso.

1. Verifique se o controle de texto estático precede imediatamente o controle que ele rotula na ordem de tabulação.

> [!NOTE]
> Todas as chaves de acesso dentro de uma caixa de diálogo devem ser exclusivas. Para verificar se há chaves de acesso duplicadas, vá para o **formato** de menu > **marque mnemônicos**.

## <a name="combo-box-values"></a>Valores da caixa de combinação

Você pode adicionar valores a um controle de caixa de combinação, contanto que tenha o **Editor de diálogo** aberto.

> [!TIP]
> É uma boa ideia adicionar todos os valores à caixa de combinação *antes* de dimensionar a caixa no editor de **caixas de diálogo**, ou você pode truncar o texto que deve aparecer no controle de combinação.

### <a name="to-enter-values-into-a-combo-box-control"></a>Para inserir valores em um controle de caixa de combinação

1. Escolha o controle caixa de combinação selecionando-o.

1. Na [janela Propriedades](/visualstudio/ide/reference/properties-window), role para baixo até a propriedade **Data** .

   > [!NOTE]
   > Se você estiver exibindo propriedades agrupadas por tipo, os **dados** aparecerão nas propriedades **diversas** .

1. Selecione a área valor para a propriedade **dados** e digite seus valores de dados, separados por ponto e vírgula.

   > [!NOTE]
   > Não coloque os espaços entre os valores porque os espaços interferem na ordem alfabética na lista suspensa.

1. Pressione **Enter** quando terminar de adicionar valores.

Para obter informações sobre como ampliar a parte suspensa de uma caixa de combinação, consulte [definindo o tamanho da caixa de combinação e sua lista suspensa](setting-the-size-of-the-combo-box-and-its-drop-down-list.md).

> [!NOTE]
> Você não pode adicionar valores a projetos Win32 usando este procedimento (a propriedade **Data** está esmaecida para projetos Win32). Como os projetos Win32 não têm bibliotecas que adicionam esse recurso, você deve adicionar valores a uma caixa de combinação com um projeto Win32 programaticamente.

### <a name="to-test-the-appearance-of-values-in-a-combo-box"></a>Para testar a aparência dos valores em uma caixa de combinação

1. Depois de inserir valores na propriedade **Data** , selecione o botão **testar** na barra de ferramentas do editor de [caixa de diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md).

1. Tente rolar para baixo a lista de valores inteiros. Os valores aparecem exatamente como são digitados na propriedade **Data** na janela **Propriedades** . Não há nenhuma verificação ortográfica ou de capitalização.

1. Pressione **ESC** para retornar ao editor de **caixa de diálogo** .

## <a name="radio-button-values"></a>Valores do botão de opção

Quando você adiciona botões de opção a uma caixa de diálogo, trate-os como um grupo definindo uma propriedade de **grupo** na janela **Propriedades** para o primeiro botão no grupo. Uma ID de controle para esse botão de opção aparece no [Assistente para Adicionar variável de membro](../ide/add-member-variable-wizard.md), permitindo que você adicione uma variável de membro para o grupo de botões de opção.

Você pode ter mais de um grupo de botões de opção em uma caixa de diálogo. Adicione cada grupo usando o procedimento a seguir.

### <a name="to-add-a-group-of-radio-buttons-to-a-dialog-box"></a>Para adicionar um grupo de botões de opção a uma caixa de diálogo

1. Selecione o controle de botão de opção na [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox) e escolha o local na caixa de diálogo onde posicionar o controle.

1. Repita a etapa acima para adicionar quantos botões de opção forem necessários. Verifique se os botões de opção no grupo são consecutivos na ordem de tabulação.

1. Na [janela Propriedades](/visualstudio/ide/reference/properties-window), defina a propriedade **Group** do *primeiro* botão de opção na ordem de tabulação como **true**.

   Alterar a propriedade de **grupo** para **true** adiciona o estilo de WS_GROUP à entrada do botão no objeto de caixa de diálogo do script de recurso e impede que o usuário possa selecionar mais de um botão de opção por vez no grupo de botões (se o usuário selecionar um botão de opção, os outros no grupo serão desmarcados).

   > [!NOTE]
   > Somente o primeiro botão de opção no grupo deve ter a propriedade **Group** definida como **true**. Se você tiver controles adicionais que não fazem parte do grupo de botões, defina a propriedade **Group** do primeiro controle *que está fora do grupo* como **true** também. Você pode identificar rapidamente o primeiro controle fora do grupo usando **Ctrl**+**D** para exibir a ordem de tabulação.

### <a name="to-add-a-member-variable-for-the-radio-button-group"></a>Para adicionar uma variável de membro para o grupo de botões de opção

1. Clique com o botão direito do mouse no primeiro controle de botão de opção na ordem de tabulação (o controle dominante e aquele com a propriedade de **grupo** definida como **true**) e escolha **Adicionar variável**.

1. No [Assistente Adicionar variável de membro](../ide/add-member-variable-wizard.md), marque a caixa de seleção **variável de controle** e, em seguida, selecione o botão de opção **valor** .

   - Na caixa **nome da variável** , digite um nome para a nova variável de membro.

   - Na caixa de listagem **tipo de variável** , selecione **int** ou digite *int*.

   Agora você pode modificar seu código para especificar qual botão de opção deve aparecer selecionado. Por exemplo, `m_radioBox1 = 0;` seleciona o primeiro botão de opção no grupo.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

Win32

## <a name="see-also"></a>Consulte também

[Gerenciar controles da caixa de diálogo](controls-in-dialog-boxes.md)<br/>
[Como: Adicionar, editar ou excluir controles](adding-editing-or-deleting-controls.md)<br/>
[Como: controles de layout](arrangement-of-controls-on-dialog-boxes.md)<br/>