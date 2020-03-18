---
title: 'Como: criar uma caixa de diálogo (C++)'
ms.date: 02/15/2019
helpviewer_keywords:
- dialog boxes [C++], creating
- Dialog Editor [C++], creating dialog boxes
- modal dialog boxes [C++], logon screens
- logon screens
- Test Dialog command
- testing, dialog boxes
- dialog boxes [C++], testing
- dialog boxes [C++], size
- dialog boxes [C++], positioning
ms.assetid: 303de801-c4f8-42e1-b622-353f6423f688
ms.openlocfilehash: 380cf58180913f538c1c326d6aaf49947b694063
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79445422"
---
# <a name="how-to-create-a-dialog-box-c"></a>Como: criar uma caixa de diálogo (C++)

O local e o tamanho de C++ uma caixa de diálogo e o local e o tamanho dos controles dentro dela, são medidos em unidades de diálogo. Os valores para controles individuais e a caixa de diálogo aparecem no canto inferior direito da barra de status do Visual Studio quando você os seleciona.

> [!NOTE]
> Se o seu projeto ainda não contiver um arquivo. rc, consulte [criando um novo arquivo de script de recurso](../windows/how-to-create-a-resource-script-file.md).

## <a name="how-to"></a>Como

O **Editor de caixa de diálogo** permite que você:

### <a name="to-create-a-new-dialog-box"></a>Para criar uma nova caixa de diálogo

1. Em [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources), clique com o botão direito do mouse no arquivo *. rc* e selecione **Adicionar recurso**.

1. Na caixa de diálogo **Adicionar recurso** , selecione **diálogo** na lista **tipo de recurso** e escolha **novo**.

   Se um sinal de adição ( **+** ) aparecer ao lado do tipo de recurso de caixa de **diálogo** , isso significará que os modelos de caixas de diálogo estão disponíveis. Selecione o sinal de adição para expandir a lista de modelos, selecione um modelo e escolha **novo**.

   A caixa de diálogo novo é aberta no **Editor de caixa de diálogo**.

Você também pode abrir caixas de diálogo existentes no editor de caixa de diálogo para edição.

### <a name="to-create-a-dialog-box-that-a-user-cant-exit"></a>Para criar uma caixa de diálogo que um usuário não pode sair

Você pode criar uma caixa de diálogo de tempo de execução que um usuário não pode sair. Esse tipo de caixa de diálogo é útil para logons e para bloqueios de aplicativo ou de documento.

1. No painel **Propriedades** da caixa de diálogo, defina a propriedade **menu do sistema** como **false**.

   Essa configuração desabilita o menu do sistema da caixa de diálogo e o botão **fechar** .

1. No formulário da caixa de diálogo, exclua os botões **Cancelar** e **OK** .

   Em tempo de execução, um usuário não pode sair de uma caixa de diálogo modal que tem essas características.

Para habilitar o teste desse tipo de caixa de diálogo, a função de caixa de diálogo teste detecta quando **ESC** é pressionado. A **ESC** também é conhecida como a chave virtual VK_ESCAPE. Não importa como a caixa de diálogo é projetada para se comportar no tempo de execução, você pode encerrar o modo de teste pressionando **ESC**.

> [!NOTE]
> Para aplicativos MFC, para criar uma caixa de diálogo que os usuários não podem sair, você deve substituir o comportamento padrão de `OnOK` e `OnCancel` porque, mesmo que você exclua os botões associados, a caixa de diálogo ainda pode ser descartada pressionando **Enter** ou **ESC**.

### <a name="to-specify-the-location-and-size-of-a-dialog-box"></a>Para especificar o local e o tamanho de uma caixa de diálogo

Há propriedades que podem ser definidas na [janela Propriedades](/visualstudio/ide/reference/properties-window) para especificar onde uma caixa de diálogo aparecerá na tela.

- A propriedade do **Centro** booliano.

   Se você definir o valor como **true**, a caixa de diálogo aparecerá sempre no centro da tela. Se você definir essa propriedade como **false**, poderá então definir as propriedades **XPos** e **YPos** .

- As propriedades **XPos** e **YPos** que são usadas para definir explicitamente onde a caixa de diálogo será exibida.

   Essas propriedades de posição são valores de deslocamento do canto superior esquerdo da área de exibição, que é definida como `{X=0, Y=0}`.

- A propriedade de **alinhamento absoluta** que afeta a posição.

   Se **for true**, as coordenadas serão relativas à tela. Se **for false**, as coordenadas serão relativas à janela do proprietário da caixa de diálogo.

### <a name="to-test-a-dialog-box"></a>Para testar uma caixa de diálogo

Quando você estiver criando uma caixa de diálogo, poderá simular e testar seu comportamento de tempo de execução sem compilar seu programa. Nesse modo, você pode:

- Digite o texto, selecione em listas de caixas de combinação, ative ou desabilite as opções e escolha comandos.

- Testar a ordem de tabulação.

- Teste o agrupamento de controles, como botões de opção e caixas de seleção.

- Teste os atalhos de teclado para controles na caixa de diálogo.

> [!NOTE]
> As conexões com o código da caixa de diálogo feita usando assistentes não estão incluídas na simulação.

Quando você testa uma caixa de diálogo, ela normalmente é exibida em um local relativo à janela do programa principal. Se você tiver definido a propriedade de **alinhamento absoluta** da caixa de diálogo como **true**, a caixa de diálogo será exibida em uma posição relativa ao canto superior esquerdo da tela.

1. Quando o **Editor de caixa de diálogo** for a janela ativa, vá para **formato** de menu > caixa de **diálogo de teste**.

1. Para encerrar a simulação, pressione **ESC** ou selecione o botão **fechar** na caixa de diálogo que você está testando.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

Win32

## <a name="see-also"></a>Consulte também

[Editor de caixa de diálogo](../windows/dialog-editor.md)<br/>
[Como: gerenciar controles da caixa de diálogo](../windows/controls-in-dialog-boxes.md)<br/>