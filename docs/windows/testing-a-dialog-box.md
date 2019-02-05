---
title: Criando uma caixa de diálogo (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- Test Dialog command
- testing, dialog boxes
- dialog boxes [C++], testing
- dialog boxes [C++], size
- dialog boxes [C++], positioning
ms.assetid: 45034ee9-c554-4f4b-8c46-6ddefdee8951
ms.openlocfilehash: 4a879f6bb1cdcd4b4897e510fb21d04500dfd3f2
ms.sourcegitcommit: 52c05e10b503e834c443ef11e7ca1987e332f876
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/05/2019
ms.locfileid: "55742681"
---
# <a name="designing-a-dialog-box-c"></a>Criando uma caixa de diálogo (C++)

O local e o tamanho de uma caixa de diálogo de C++ e o local e tamanho dos controles dentro dele, são medidos em unidades de diálogo. Os valores para controles individuais e a caixa de diálogo aparecer no canto inferior direito do Visual Studio barra de status quando você seleciona.

Quando você estiver criando uma caixa de diálogo, você também pode simular e testar seu comportamento de tempo de execução sem compilar seu programa. Nesse modo, você pode:

- Digite o texto, selecione nas listas de caixa de combinação, ativar ou desativar as opções e escolha os comandos.

- Teste a ordem de tabulação.

- Teste o agrupamento de controles como botões de opção e caixas de seleção.

- Teste os atalhos de teclado para controles na caixa de diálogo.

   > [!NOTE]
   > Conexões com o código de caixa de diálogo feito com assistentes não são incluídas na simulação.

Quando você testa uma caixa de diálogo, ele normalmente é exibida em um local relativo à janela principal do programa. Se você tiver definido a caixa de diálogo **alinhamento absoluto** propriedade **verdadeiro**, a caixa de diálogo é exibida em uma posição relativa ao canto superior esquerdo da tela.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index).

## <a name="to-specify-the-location-and-size-of-a-dialog-box"></a>Para especificar o local e o tamanho de uma caixa de diálogo

Há três propriedades que podem ser definidas na [janela de propriedades](/visualstudio/ide/reference/properties-window) para especificar onde uma caixa de diálogo será exibida na tela. O **Center** propriedade é booliano; se você definir o valor como **verdadeiro**, a caixa de diálogo será sempre exibido no centro da tela. Se você defini-lo **falso**, em seguida, você pode definir o **XPos** e **YPos** propriedades para definir explicitamente onde na tela de caixa de diálogo será exibida. As propriedades de posição são valores de deslocamento do canto superior esquerdo da área de exibição, que é definida como `{X=0, Y=0}`. A posição também se baseia a **alinhamento absoluto** propriedade: se **verdadeiro**, as coordenadas são em relação à tela; se **False**, as coordenadas são relativas à caixa de diálogo janela do proprietário.

## <a name="to-test-a-dialog-box"></a>Para testar uma caixa de diálogo

1. Quando o **caixa de diálogo** editor é a janela ativa, na barra de menus, escolha **formato** > **caixa de diálogo de teste**.

1. Para encerrar a simulação, pressione **Esc**, ou basta escolher o **fechar** botão na caixa de diálogo que você está testando.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)<br/>
[Editor de caixa de diálogo](../windows/dialog-editor.md)<br/>
[Mostrando ou ocultando a barra de ferramentas do Editor de Caixa de Diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md)