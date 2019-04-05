---
title: 'Como: Definir controle de acesso e os valores (C++)'
ms.date: 02/15/2019
f1_keywords:
- vc.editors.dialog.combo
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
ms.openlocfilehash: c49913597f51ef231073b89d60ad9718b1113f44
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59041478"
---
# <a name="how-to-define-control-access-and-values-c"></a>Como: Definir controle de acesso e os valores (C++)

## <a name="tab-order"></a>Ordem de tabulação

A ordem de tabulação é a ordem na qual o **guia** tecla move o foco de entrada de um controle para o próximo dentro de uma caixa de diálogo. Normalmente, a ordem de tabulação prossegue da esquerda para a direita e de cima para baixo em uma caixa de diálogo. Cada controle tem um **Tabstop** propriedade que determina se um controle recebe foco de entrada.

- Para definir o foco de entrada para um controle na [janela propriedades](/visualstudio/ide/reference/properties-window), selecione **verdadeiro** ou **False** no **Tabstop** propriedade.

Até mesmo os controles que não têm o **Tabstop** propriedade definida como **verdadeiro** precisam fazer parte da ordem de tabulação, especialmente para os controles que não têm legendas. Texto estático que contém uma chave de acesso para um controle relacionada deve preceder imediatamente o controle relacionado na ordem de tabulação.

> [!NOTE]
> Se a caixa de diálogo contém controles sobrepostos, alterando a ordem de tabulação pode alterar a maneira como os controles são exibidos. Controles que acompanham a ordem de tabulação são sempre exibidos na parte superior de todos os controles sobrepostos que precedem-os na ordem de tabulação.

- Para exibir a ordem de tabulação para todos os controles, vá ao menu **formato** > **ordem de tabulação**, ou pressione **Ctrl** + **1!d**.

   Um número no canto superior esquerdo de cada controle mostra seu lugar na ordem de tabulação atual.

- Para alterar a ordem de tabulação para todos os controles, vá ao menu **formato** > **ordem de tabulação** e defina a ordem de tabulação, selecionando cada controle na ordem em que você deseja que o **guia** chave a seguir.

- Para alterar a ordem de tabulação para controles de duas ou mais, vá ao menu **formato** > **ordem de tabulação**. Mantenha pressionada a **Ctrl** da chave e selecione o controle em que a alteração na ordem começar e solte o **Ctrl** da chave e selecione os controles na ordem em que você deseja o **guia** chave para Siga a partir desse ponto.

   Por exemplo, se você quiser alterar a ordem dos controles `7` por meio `9`, mantenha pressionada **Ctrl**, em seguida, selecione o controle `6` primeiro.

- Para definir um controle específico para número `1`, ou primeiro na ordem de tabulação, clique duas vezes no controle.

> [!TIP]
> Depois de digitar **ordem de tabulação** modo, pressione **Esc** ou **Enter** para sair **ordem de tabulação** modo e desabilitar a capacidade de alterar a ordem de tabulação.

## <a name="mnemonics-access-keys"></a>Mnemônica (teclas de acesso)

Normalmente, os usuários de teclado movem o foco de entrada de um controle para outro em uma caixa de diálogo com o **guia** e **seta** chaves. No entanto, você pode definir uma chave de acesso (um nome mnemônico ou fácil de lembrar) que permite aos usuários escolher um controle pressionando uma tecla única.

### <a name="to-define-an-access-key-for-a-control-with-a-visible-caption-push-buttons-check-boxes-and-radio-buttons"></a>Para definir uma chave de acesso para um controle com uma legenda visível (botões de ação, caixas de seleção e botões de opção)

1. Selecione o controle na caixa de diálogo.

1. No [janela de propriedades](/visualstudio/ide/reference/properties-window), no **legenda** propriedade, digite um novo nome para o controle, digitando um e comercial (`&`) na frente da letra que você deseja como a chave de acesso para o controle. Por exemplo, `&Radio1`.

1. Pressione **ENTER**.

   Um sublinhado será exibido na legenda exibida para indicar a chave de acesso, por exemplo, **R**adio1.

### <a name="to-define-an-access-key-for-a-control-without-a-visible-caption"></a>Para definir uma chave de acesso para um controle sem uma legenda visível

1. Faça uma legenda para o controle, usando um **texto estático** no controlar a [caixa de ferramentas](/visualstudio/ide/reference/toolbox).

1. Na legenda de texto estático, digite um e comercial (`&`) na frente da letra que você deseja como a chave de acesso.

1. Verifique se o controle de texto estático que precede o controle rotula na ordem de tabulação.

> [!NOTE]
> Todas as chaves de acesso dentro de uma caixa de diálogo devem ser exclusivas. Para verificar se as chaves de acesso duplicadas, acesse o menu **formato** > **Verificar mnemônicos**.

## <a name="combo-box-values"></a>Valores da caixa de combinação

Você pode adicionar valores a um controle de caixa de combinação, desde que você tenha o **Editor de caixa de diálogo** abrir.

> [!TIP]
> É uma boa ideia adicionar todos os valores à caixa de combinação *antes de* você dimensiona a caixa na **Editor de caixa de diálogo**, ou você pode truncar o texto que deve aparecer no controle de caixa de combinação.

### <a name="to-enter-values-into-a-combo-box-control"></a>Para inserir valores em um controle de caixa de combinação

1. Escolha a caixa de combinação controle de caixa, selecionando-o.

1. No [janela de propriedades](/visualstudio/ide/reference/properties-window), role para baixo até a **dados** propriedade.

   > [!NOTE]
   > Se você estiver exibindo as propriedades agrupadas por tipo, **dados** aparece na **Misc** propriedades.

1. Selecione a área de valor para o **dados** propriedade e digite os valores de dados, separados por ponto e vírgula.

   > [!NOTE]
   > Não coloque os espaços entre os valores como espaços interferem colocando em ordem alfabética na lista suspensa.

1. Pressione **Enter** quando tiver terminado de adicionar os valores.

Para obter informações sobre como aumentar a parte suspensa de uma caixa de combinação, consulte [definindo o tamanho da caixa de combinação e sua lista de suspensa](setting-the-size-of-the-combo-box-and-its-drop-down-list.md).

> [!NOTE]
> Você não pode adicionar valores para projetos do Win32 usando esse procedimento (o **dados** propriedade fica esmaecida para projetos do Win32). Como projetos do Win32 não têm bibliotecas que adicionam essa funcionalidade, você deve adicionar valores para uma caixa de combinação com um projeto do Win32 por meio de programação.

### <a name="to-test-the-appearance-of-values-in-a-combo-box"></a>Para testar a aparência dos valores em uma caixa de combinação

1. Depois de inserir valores na **dados** propriedade, selecione a **teste** botão o [barra de ferramentas do Editor de caixa de diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md).

1. Tente rolar para baixo na lista de todo o valor. Valores são exibidos exatamente como eles são digitados a **dados** propriedade no **propriedades** janela. Não há nenhum ortografia ou verificação de maiusculas e minúsculas.

1. Pressione **Esc** para retornar para o **caixa de diálogo** editor.

## <a name="radio-button-values"></a>Valores de botão de opção

Quando você adiciona botões de opção para uma caixa de diálogo, tratá-los como um grupo, definindo um **grupo** propriedade no **propriedades** janela para o primeiro botão no grupo. Então, aparecerá uma ID de controle para esse botão de opção na [Assistente para adição de variável de membro](../ide/add-member-variable-wizard.md), permitindo que você adicione uma variável de membro para o grupo de botões de opção.

Você pode ter mais de um grupo de botões de opção em uma caixa de diálogo. Adicione cada grupo usando o procedimento a seguir.

### <a name="to-add-a-group-of-radio-buttons-to-a-dialog-box"></a>Para adicionar um grupo de botões de opção para uma caixa de diálogo

1. Selecione o controle de botão de opção na [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox) e escolha o local na caixa de diálogo onde colocar o controle.

1. Repita a etapa acima para adicionar botões de opção quantas forem necessárias. Verifique se que os botões de opção no grupo são consecutivos na ordem de tabulação.

1. No [janela de propriedades](/visualstudio/ide/reference/properties-window), defina o **grupo** propriedade do *primeiro* botão de opção na ordem de tabulação para **True**.

   Alterando a **grupo** propriedade **verdadeiro** adiciona o estilo WS_GROUP a entrada do botão no objeto de caixa de diálogo do script de recurso e impede que o usuário pode selecionar mais de um botão de opção por vez em o grupo de botões (se o usuário seleciona um botão de opção, os outros no grupo é desmarcado).

   > [!NOTE]
   > Somente o primeiro botão de opção no grupo deve ter o **grupo** propriedade definida como **verdadeiro**. Se você tiver controles adicionais que não fazem parte do grupo de botões, defina as **grupo** propriedade do primeiro controle *que está fora do grupo* para **verdadeiro** também. Você pode identificar rapidamente o primeiro controle fora do grupo por meio **Ctrl**+**1!d** para exibir a ordem de tabulação.

### <a name="to-add-a-member-variable-for-the-radio-button-group"></a>Para adicionar uma variável de membro para o grupo de botões de opção

1. O primeiro controle de botão de opção na ordem de tabulação com o botão direito (o controle dominante e aquele com o **grupo** propriedade definida como **verdadeiro**) e escolha **Adicionar variável**.

1. No [assistente Adicionar variável de membro](../ide/add-member-variable-wizard.md), selecione o **variável de controle** caixa de seleção e, em seguida, selecione o **valor** botão de opção.

   - No **nome da variável** , digite um nome para a nova variável de membro.

   - No **tipo de variável** caixa de listagem, selecione **int** ou o tipo *int*.

   Agora você pode modificar seu código para especificar qual botão de opção deve aparecer selecionado. Por exemplo, `m_radioBox1 = 0;` seleciona o primeiro botão de opção no grupo.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Gerenciar controles de caixa de diálogo](controls-in-dialog-boxes.md)<br/>
[Como: Adicionar, editar ou excluir controles](adding-editing-or-deleting-controls.md)<br/>
[Como: Controles de layout](arrangement-of-controls-on-dialog-boxes.md)<br/>