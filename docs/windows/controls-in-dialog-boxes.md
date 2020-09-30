---
title: Controles da caixa de diálogo (C++) | Microsoft Docs
ms.date: 02/15/2019
f1_keywords:
- Custom Control
helpviewer_keywords:
- controls [C++], dialog boxes
- dialog box controls [C++], about dialog box controls
- dialog box controls
- controls [C++], templates
- custom controls [C++], dialog boxes
- custom controls [C++]
- dialog box controls [C++], custom (user) controls
- Dialog Editor [C++], custom controls
ms.assetid: e216c4f9-2fd4-429d-889a-8ebce7bad177
ms.openlocfilehash: 449e60e968916f7741422ca2766375ad29afd062
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91505705"
---
# <a name="dialog-box-controls-c"></a>Controles da caixa de diálogo (C++)

Você pode adicionar controles a uma caixa de diálogo usando a guia **Editor de caixa** de [ferramentas](/visualstudio/ide/reference/toolbox) , que permite escolher o controle desejado e arrastá-lo para a caixa de diálogo. Por padrão, a janela **caixa de ferramentas** é definida como ocultar automaticamente. Ele aparece como uma guia na margem esquerda da solução quando o editor de **caixa de diálogo** está aberto. No entanto, você pode fixar a janela **caixa de ferramentas** em posição selecionando o botão **ocultar automaticamente** no canto superior direito da janela. Para obter mais informações sobre como controlar o comportamento dessa janela, consulte [Gerenciamento de janelas](/visualstudio/ide/customizing-window-layouts-in-visual-studio).

A maneira mais rápida de adicionar controles a uma caixa de diálogo, reposicionar controles existentes ou mover controles de uma caixa de diálogo para outra, é usar o método arrastar e soltar. A posição do controle é descrita em uma linha pontilhada até ser removida para a caixa de diálogo. Quando você adiciona um controle a uma caixa de diálogo com o método arrastar e soltar, o controle recebe uma altura padrão apropriada para esse tipo de controle.

Quando você adiciona um controle a uma caixa de diálogo ou o reposiciona, seu posicionamento final pode ser determinado por guias ou margens, ou se você tiver a grade de layout ativada.

Depois de adicionar um controle à caixa de diálogo, você pode alterar propriedades como sua legenda na [janela Propriedades](/visualstudio/ide/reference/properties-window). Você também pode selecionar vários controles e alterar suas propriedades de uma só vez.

Para obter mais informações sobre **o editor de caixa de diálogo**, consulte como [Adicionar, editar ou excluir controles](adding-editing-or-deleting-controls.md), [controles de layout](../windows/arrangement-of-controls-on-dialog-boxes.md)e [Definir acesso e valores de controle](../windows/defining-mnemonics-access-keys.md).

Para obter mais informações sobre controles e caixas de diálogo, consulte [classes de controle](../mfc/control-classes.md), classes de [caixa de diálogo](../mfc/dialog-box-classes.md)e [estilos de barra de rolagem](../mfc/reference/styles-used-by-mfc.md#scroll-bar-styles).

Os controles padrão disponíveis na **caixa de ferramentas** com eventos padrão são:

|Nome do controle|Evento padrão|
|---|---|
|[Controle de botão](../mfc/reference/cbutton-class.md)|BN_CLICKED|
|[Controle de caixa de seleção](../mfc/reference/styles-used-by-mfc.md#button-styles)|BN_CLICKED|
|[Controle de caixa de combinação](../mfc/reference/ccombobox-class.md)|CBN_SELCHANGE|
|[Controle de edição](../mfc/reference/cedit-class.md)|EN_CHANGE|
|Caixa de grupo|(não se aplica)|
|[Controle de caixa de listagem](../mfc/reference/clistbox-class.md)|LBN_SELCHANGE|
|[Controle de botão de opção](../mfc/reference/styles-used-by-mfc.md#button-styles)|BN_CLICKED|
|[Controle de texto estático](../mfc/reference/cstatic-class.md)|(não se aplica)|
|[Controle de imagem](../mfc/reference/cpictureholder-class.md)|(não se aplica)|
|[Controle rich edit 2,0](../mfc/using-cricheditctrl.md)|EN_CHANGE|
|[Controle da barra de rolagem](../mfc/reference/cscrollbar-class.md)|NM_THEMECHANGED|

> [!NOTE]
> Para obter mais informações sobre como usar o controle **richedit 1,0** com MFC, consulte [usando o controle RichEdit 1,0 com MFC](./adding-editing-or-deleting-controls.md) e [exemplos de controle de edição avançada](../mfc/rich-edit-control-examples.md).

Os [controles comuns do Windows](../mfc/controls-mfc.md) disponíveis na **caixa de ferramentas** para fornecer uma funcionalidade maior são:

|Nome do controle|Evento padrão|
|---|---|
|[Controle deslizante](../mfc/slider-control-styles.md)|NM_CUSTOMDRAW|
|[Controle de giro](../mfc/using-cspinbuttonctrl.md)|UDN_DELTAPOS|
|[Controle de progresso](../mfc/styles-for-the-progress-control.md)|NM_CUSTOMDRAW|
|[Controle de teclas de acesso](../mfc/using-a-hot-key-control.md)|NM_OUTOFMEMORY|
|[Controle de lista](../mfc/list-control-and-list-view.md)|LVN_ITEMCHANGE|
|[Controle de árvore](../mfc/tree-control-styles.md)|TVN_SELCHANGE|
|[Controle guia](../mfc/tab-controls-and-property-sheets.md)|TCN_SELCHANGE|
|[Controle de animação](../mfc/using-an-animation-control.md)|ACN_START|
|[Controle do seletor de data e hora](../mfc/creating-the-date-and-time-picker-control.md)|DTN_DATETIMECHANGE|
|[Controle de calendário mensal](../mfc/month-calendar-control-examples.md)|MCN_SELCHANGE|
|[Controle de endereço IP](../mfc/reference/cipaddressctrl-class.md)|IPN_FIELDCHANGED|
|[Controle de caixa de combinação estendida](../mfc/creating-an-extended-combo-box-control.md)||
|Controle personalizado|TTN_GETDISPINFO|

## <a name="custom-controls"></a>Controles personalizados

O **Editor** de caixa de diálogo permite que você use controles personalizados ou de usuário existentes em um modelo de caixas de diálogo.

> [!NOTE]
> Os controles personalizados nesse sentido não devem ser confundidos com controles ActiveX. Os controles ActiveX às vezes eram chamados de controles OLE personalizados. Além disso, não confunda esses controles com os controles desenhados pelo proprietário no Windows.

Essa funcionalidade destina-se a permitir que você use controles diferentes daqueles fornecidos pelo Windows. Em tempo de execução, o controle é associado a uma classe de janela (não o mesmo que uma classe C++). Uma maneira mais comum de realizar a mesma tarefa é instalar qualquer controle, como um controle estático, na caixa de diálogo. Em seguida, em tempo de execução, na função [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog) , remova esse controle e substitua-o pelo seu próprio controle personalizado.

> [!NOTE]
> Essa é uma técnica antiga. Hoje, você é avisado na maioria dos casos para escrever um controle ActiveX ou uma subclasse de um controle comum do Windows.

Para esses controles personalizados, você está limitado a:

- Configurando o local na caixa de diálogo.

- Digitando uma legenda.

- Identificação do nome da classe do controle do Windows, já que o código do aplicativo deve registrar o controle por esse nome.

- Digitando um valor hexadecimal de 32 bits que define o estilo do controle.

- Definindo o estilo estendido.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor de diálogo](../windows/dialog-editor.md)

<!--
[Adding Event Handlers for Dialog Box Controls](./adding-editing-or-deleting-controls.md)<br/>
[Dialog Box Controls and Variable Types](../ide/adding-a-member-variable-visual-cpp.md#dialog-box-controls-and-variable-types)<br/>
[Controls](../mfc/controls-mfc.md)<br/>-->
