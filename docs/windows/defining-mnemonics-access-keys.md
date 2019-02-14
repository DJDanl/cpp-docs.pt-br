---
title: Definir valores e controlar o acesso
ms.date: 11/04/2016
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
ms.openlocfilehash: 3a885ad57ba05304d51cb45d0b498d81ad37a148
ms.sourcegitcommit: eb2b34a24e6edafb727e87b138499fa8945f981e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2019
ms.locfileid: "56264849"
---
# <a name="defining-control-access-and-values"></a>Definir valores e controlar o acesso

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="change-the-tab-order-of-controls"></a>Alterar a ordem de tabulação dos controles

A ordem de tabulação é a ordem na qual o **guia** tecla move o foco de entrada de um controle para o próximo dentro de uma caixa de diálogo. Normalmente, a ordem de tabulação prossegue da esquerda para a direita e de cima para baixo em uma caixa de diálogo. Cada controle tem um **Tabstop** propriedade que determina se um controle recebe foco de entrada.

### <a name="to-set-input-focus-for-a-control"></a>Para definir o foco de entrada para um controle

No [janela de propriedades](/visualstudio/ide/reference/properties-window), selecione **verdadeiro** ou **False** no **Tabstop** propriedade.

Até mesmo os controles que não têm o **Tabstop** propriedade definida como **verdadeiro** precisam fazer parte da ordem de tabulação. Ordem de tabulação é importante, por exemplo, quando você [definir chaves de acesso (mnemônicos)](../windows/defining-mnemonics-access-keys.md) para controles que não têm legendas. Texto estático que contém uma chave de acesso para um controle relacionada deve preceder imediatamente o controle relacionado na ordem de tabulação.

> [!NOTE]
> Se a caixa de diálogo contém controles sobrepostos, alterando a ordem de tabulação pode alterar a maneira como os controles são exibidos. Controles que acompanham a ordem de tabulação são sempre exibidos na parte superior de todos os controles sobrepostos que precedem-os na ordem de tabulação.

### <a name="to-view-the-current-tab-order-for-all-controls-in-a-dialog-box"></a>Para exibir a ordem de tabulação para todos os controles em uma caixa de diálogo

Sobre o **formato** menu, selecione **ordem de tabulação**.

\- ou -

- Pressione **Ctrl** + **1!d**.

### <a name="to-change-the-tab-order-for-all-controls-in-a-dialog-box"></a>Para alterar a ordem de tabulação para todos os controles em uma caixa de diálogo

1. Sobre o **formato** menu, selecione **ordem de tabulação**.

   Um número no canto superior esquerdo de cada controle mostra seu lugar na ordem de tabulação atual.

1. Definir a ordem de tabulação, clicando em cada controle na ordem em que você deseja que o **guia** chave a seguir.

1. Pressione **Enter** para sair **ordem de tabulação** modo.

   > [!TIP]
   > Depois de digitar **ordem de tabulação** modo, você pode pressionar **Esc** ou **Enter** para desabilitar a capacidade de alterar a ordem de tabulação.

### <a name="to-change-the-tab-order-for-two-or-more-controls"></a>Para alterar a ordem de tabulação para dois ou mais controles

1. Dos **formato** menu, escolha **ordem de tabulação**.

1. Especifique onde começará a alteração na ordem. Primeiro, mantenha pressionada a **Ctrl** da chave, selecione o controle e selecione aquele em que você deseja a ordem alterada para começar.

   Por exemplo, se você quiser alterar a ordem dos controles `7` por meio `9`, mantenha pressionada **Ctrl**, em seguida, selecione o controle `6` primeiro.

   > [!NOTE]
   > Para definir um controle específico para número `1` (primeiro na ordem de tabulação), clique duas vezes no controle.

1. Versão de **Ctrl** da chave, em seguida, selecione os controles na ordem em que você deseja que o **guia** chave a serem seguidos a partir desse ponto.

1. Pressione **Enter** para sair **ordem de tabulação** modo.

## <a name="define-mnemonics-access-keys"></a>Definir mnemônica (teclas de acesso)

Normalmente, os usuários de teclado movem o foco de entrada de um controle para outro em uma caixa de diálogo com o **guia** e **seta** chaves. No entanto, você pode definir uma chave de acesso (um nome mnemônico ou fácil de lembrar) que permite aos usuários escolher um controle pressionando uma tecla única.

### <a name="to-define-an-access-key-for-a-control-with-a-visible-caption-push-buttons-check-boxes-and-radio-buttons"></a>Para definir uma chave de acesso para um controle com uma legenda visível (botões de ação, caixas de seleção e botões de opção)

1. Selecione o controle na caixa de diálogo.

2. No [janela de propriedades](/visualstudio/ide/reference/properties-window), no **legenda** propriedade, digite um novo nome para o controle, digitando um e comercial (`&`) na frente da letra que você deseja como a chave de acesso para o controle. Por exemplo, `&Radio1`.

3. Pressione **ENTER**.

   Um sublinhado será exibido na legenda exibida para indicar a chave de acesso, por exemplo, **R**adio1.

### <a name="to-define-an-access-key-for-a-control-without-a-visible-caption"></a>Para definir uma chave de acesso para um controle sem uma legenda visível

1. Faça uma legenda para o controle, usando um **texto estático** no controlar a [caixa de ferramentas](/visualstudio/ide/reference/toolbox).

2. Na legenda de texto estático, digite um e comercial (`&`) na frente da letra que você deseja como a chave de acesso.

3. Verifique se o controle de texto estático que precede o controle rotula na ordem de tabulação.

Todas as chaves de acesso dentro de uma caixa de diálogo devem ser exclusivas.

### <a name="to-check-for-duplicate-access-keys"></a>Para verificar se há teclas de acesso duplicadas

1. Sobre o **formato** menu, clique em **Verificar mnemônicos**.

## <a name="add-values-to-a-combo-box-control"></a>Adicionar valores a um controle de caixa de combinação

Você pode adicionar valores a um controle de caixa de combinação, desde que você tenha o **caixa de diálogo** editor aberto.

> [!TIP]
> É uma boa ideia adicionar todos os valores à caixa de combinação *antes de* você dimensiona a caixa na **caixa de diálogo** editor, ou você pode truncar o texto que deve aparecer no controle de caixa de combinação.

### <a name="to-enter-values-into-a-combo-box-control"></a>Para inserir valores em um controle de caixa de combinação

1. Selecione o controle de caixa de combinação clicando nele.

1. No [janela de propriedades](/visualstudio/ide/reference/properties-window), role para baixo até a **dados** propriedade.

   > [!NOTE]
   > Se você estiver exibindo as propriedades agrupadas por tipo, **dados** aparece na **Misc** propriedades.

1. Selecione a área de valor para o **dados** propriedade e digite os valores de dados, separados por ponto e vírgula.

   > [!NOTE]
   > Não coloque espaços entre os valores como espaços interferem colocando em ordem alfabética na lista suspensa.

1. Pressione **Enter** quando tiver terminado de adicionar os valores.

Para obter informações sobre como aumentar a parte suspensa de uma caixa de combinação, consulte [definindo o tamanho da caixa de combinação e sua lista de suspensa](setting-the-size-of-the-combo-box-and-its-drop-down-list.md).

> [!NOTE]
> Você não pode adicionar valores para projetos do Win32 usando esse procedimento (o **dados** propriedade fica esmaecida para projetos do Win32). Como projetos do Win32 não têm bibliotecas que adicionam essa funcionalidade, você deve adicionar valores para uma caixa de combinação com um projeto do Win32 por meio de programação.

### <a name="to-test-the-appearance-of-values-in-a-combo-box"></a>Para testar a aparência dos valores em uma caixa de combinação

Depois de inserir valores na **dados** propriedade, selecione a **teste** botão o [barra de ferramentas do Editor de caixa de diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md).

   Tente rolar para baixo na lista de todo o valor. Valores são exibidos exatamente como eles são digitados a **dados** propriedade no **propriedades** janela. Não há nenhum ortografia ou verificação de maiusculas e minúsculas.

   Pressione **Esc** para retornar para o **caixa de diálogo** editor.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)<br/>
[Controles](../mfc/controls-mfc.md)