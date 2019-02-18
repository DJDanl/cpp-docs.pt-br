---
title: 'Como: Criar uma caixa de diálogo (C++)'
ms.date: 02/15/2019
f1_keywords:
- vc.editors.dialog
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
ms.openlocfilehash: c757c82978a5107374e6de2f8cff24319ed64f9c
ms.sourcegitcommit: 24592ba0a38c7c996ffd3d55fe1024231a59ccc2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/18/2019
ms.locfileid: "56336469"
---
# <a name="how-to-create-a-dialog-box-c"></a>Como: Criar uma caixa de diálogo (C++)

O local e o tamanho de uma caixa de diálogo de C++ e o local e tamanho dos controles dentro dele, são medidos em unidades de diálogo. Os valores para controles individuais e a caixa de diálogo aparecer no canto inferior direito do Visual Studio barra de status quando você seleciona.

Quando você estiver criando uma caixa de diálogo, você também pode simular e testar seu comportamento de tempo de execução sem compilar seu programa. Nesse modo, você pode:

- Digite o texto, selecione nas listas de caixa de combinação, ativar ou desativar as opções e escolha os comandos.

- Teste a ordem de tabulação.

- Teste o agrupamento de controles como botões de opção e caixas de seleção.

- Teste os atalhos de teclado para controles na caixa de diálogo.

   > [!NOTE]
   > Conexões com o código de caixa de diálogo feito com assistentes não são incluídas na simulação.

Quando você testa uma caixa de diálogo, ele normalmente é exibida em um local relativo à janela principal do programa. Se você tiver definido a caixa de diálogo **alinhamento absoluto** propriedade **verdadeiro**, a caixa de diálogo é exibida em uma posição relativa ao canto superior esquerdo da tela.

## <a name="to-create-a-new-dialog-box"></a>Para criar uma nova caixa de diálogo

1. Na [exibição de recurso](../windows/resource-view-window.md), clique com botão direito seu arquivo. RC e escolha **adicionar recurso** no menu de atalho.

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

1. No **adicionar recurso** caixa de diálogo, selecione **caixa de diálogo** no **tipo de recurso** lista e, em seguida, escolha **novo**.

   Se um sinal de adição (**+**) é exibido ao lado de **caixa de diálogo** tipo de recurso, isso significa que os modelos de caixa de diálogo estão disponíveis. Selecione o sinal de adição para expandir a lista de modelos, selecione um modelo e escolha **New**.

   A nova caixa de diálogo é aberta na **caixa de diálogo** editor.

   Você também pode [abrir caixas de diálogo existente no editor de caixa de diálogo para edição](../windows/viewing-and-editing-resources-in-a-resource-editor.md).

## <a name="to-create-a-dialog-box-that-a-user-cant-exit"></a>Para criar uma caixa de diálogo que um usuário não possam sair

Você pode criar uma caixa de diálogo de tempo de execução que um usuário não pode sair. Esse tipo de caixa de diálogo é útil para logons e para bloqueios de documento ou aplicativo.

1. No **propriedades** painel para a caixa de diálogo, defina as **Menu do sistema** propriedade a ser **false**.

   Essa configuração desabilita o menu de sistema de caixa de diálogo e **fechar** botão.

1. No formulário de caixa de diálogo, exclua o **cancele** e **Okey** botões.

   Em tempo de execução, um usuário não pode sair de uma caixa de diálogo modal que tem as seguintes características.

Para habilitar o teste desse tipo de caixa de diálogo, a função de caixa de diálogo test detecta quando **Esc** é pressionado. (**Esc** também é conhecido como a chave de virtual VK_ESCAPE.) Não importa como a caixa de diálogo é projetada para se comportar em tempo de execução, você pode encerrar o modo de teste pressionando **Esc**.

> [!NOTE]
> Para aplicativos do MFC para criar uma caixa de diálogo que os usuários não possam sair, você deve substituir o comportamento padrão do `OnOK` e `OnCancel` porque, mesmo se você excluir os botões associados, a caixa de diálogo ainda pode ser descartada, pressionando  **Insira** ou **Esc**.

## <a name="to-specify-the-location-and-size-of-a-dialog-box"></a>Para especificar o local e o tamanho de uma caixa de diálogo

Há três propriedades que podem ser definidas na [janela de propriedades](/visualstudio/ide/reference/properties-window) para especificar onde uma caixa de diálogo será exibida na tela. O **Center** propriedade é booliano; se você definir o valor como **verdadeiro**, a caixa de diálogo será sempre exibido no centro da tela. Se você defini-lo **falso**, em seguida, você pode definir o **XPos** e **YPos** propriedades para definir explicitamente onde na tela de caixa de diálogo será exibida. As propriedades de posição são valores de deslocamento do canto superior esquerdo da área de exibição, que é definida como `{X=0, Y=0}`. A posição também se baseia a **alinhamento absoluto** propriedade: se **verdadeiro**, as coordenadas são em relação à tela; se **False**, as coordenadas são relativas à caixa de diálogo janela do proprietário.

## <a name="to-test-a-dialog-box"></a>Para testar uma caixa de diálogo

1. Quando o **caixa de diálogo** editor é a janela ativa, na barra de menus, escolha **formato** > **caixa de diálogo de teste**.

1. Para encerrar a simulação, pressione **Esc** ou selecione o **fechar** botão na caixa de diálogo que você está testando.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Como: criar um recurso](../windows/how-to-create-a-resource.md)<br/>
[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Editor de caixa de diálogo](../windows/dialog-editor.md)<br/>
[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)<br/>