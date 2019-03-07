---
title: Controles de caixa de diálogo (C++) | Microsoft Docs
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
ms.openlocfilehash: 152113200fd7aa9ee87b749380e370fe4e6ad9ff
ms.sourcegitcommit: b4645761ce5acf8c2fc7a662334dd5a471ea976d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/07/2019
ms.locfileid: "57563349"
---
# <a name="dialog-box-controls-c"></a>Controles de caixa de diálogo (C++)

Você pode adicionar controles a uma caixa de diálogo usando o **Editor de caixa de diálogo** guia o [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox) que permite que você escolha o controle desejado e arraste-o para a caixa de diálogo. Por padrão, o **caixa de ferramentas** janela é definida como ocultar automaticamente. Ele aparece como uma guia na margem esquerda da sua solução quando o **Editor de caixa de diálogo** está aberto. No entanto, você pode fixar o **caixa de ferramentas** janela para a posição, selecionando a **ocultar automaticamente** botão no canto superior direito da janela. Para obter mais informações sobre como controlar o comportamento desta janela, consulte [gerenciamento de janela](/visualstudio/ide/customizing-window-layouts-in-visual-studio).

A maneira mais rápida para adicionar controles a uma caixa de diálogo, reposicionar os controles existentes ou mover os controles de uma caixa de diálogo para outra, é usar o método de arrastar e soltar. A posição do controle é descrita em uma linha pontilhada até que ele é colocado na caixa de diálogo. Quando você adiciona um controle a uma caixa de diálogo com o método de arrastar e soltar, o controle recebe uma altura padrão apropriada para esse tipo de controle.

Quando você adicionar um controle a uma caixa de diálogo ou reposicioná-lo, seu posicionamento final pode ser determinado por guias ou as margens, ou se você tiver ativada a grade de layout.

Depois de adicionar um controle à caixa de diálogo, você pode alterar as propriedades, como a legenda na [janela de propriedades](/visualstudio/ide/reference/properties-window). Você também pode selecionar vários controles e alterar suas propriedades de uma só vez.

Para obter mais informações sobre o **Editor de caixa de diálogo**, consulte como [adicionar, editar ou excluir controles](adding-editing-or-deleting-controls.md), [controles de Layout](../windows/arrangement-of-controls-on-dialog-boxes.md), e [valoresedefinirocontroledeacesso](../windows/defining-mnemonics-access-keys.md).

Para obter mais informações sobre os controles e caixas de diálogo, consulte [Classes de controle](../mfc/control-classes.md), [Classes da caixa de diálogo](../mfc/dialog-box-classes.md), e [estilos de barra de rolagem](../mfc/reference/styles-used-by-mfc.md#scroll-bar-styles).

Os controles padrão disponíveis na **caixa de ferramentas** padrão eventos são:

|Nome do controle|Evento padrão|
|---|---|
|[Controle de botão](../mfc/reference/cbutton-class.md)|BN_CLICKED|
|[Controle de caixa de seleção](../mfc/reference/styles-used-by-mfc.md#button-styles)|BN_CLICKED|
|[Controle de caixa de combinação](../mfc/reference/ccombobox-class.md)|CBN_SELCHANGE|
|[Controle de edição](../mfc/reference/cedit-class.md)|EN_CHANGE|
|Caixa de grupo|(não aplicável)|
|[Controle de caixa de listagem](../mfc/reference/clistbox-class.md)|LBN_SELCHANGE|
|[Controle de botão de opção](../mfc/reference/styles-used-by-mfc.md#button-styles)|BN_CLICKED|
|[Controle de texto estático](../mfc/reference/cstatic-class.md)|(não aplicável)|
|[Controle de imagem](../mfc/reference/cpictureholder-class.md)|(não aplicável)|
|[Controle Rich Editar 2.0](../mfc/using-cricheditctrl.md)|EN_CHANGE|
|[Controle de barra de rolagem](../mfc/reference/cscrollbar-class.md)|NM_THEMECHANGED|

> [!NOTE]
> Para obter mais informações sobre como usar o **RichEdit 1.0** controle com o MFC, consulte [usando o controle RichEdit 1.0 com MFC](../windows/using-the-richedit-1-0-control-with-mfc.md) e [exemplos de controle Editar Rich](../mfc/rich-edit-control-examples.md).

O [controles comuns do Windows](../mfc/controls-mfc.md) disponível na **caixa de ferramentas** para fornecer maior funcionalidade são:

|Nome do controle|Evento padrão|
|---|---|
|[Controle deslizante](../mfc/slider-control-styles.md)|NM_CUSTOMDRAW|
|[Controle de rotação](../mfc/using-cspinbuttonctrl.md)|UDN_DELTAPOS|
|[Controle de progresso](../mfc/styles-for-the-progress-control.md)|NM_CUSTOMDRAW|
|[Controle de tecla de acesso](../mfc/using-a-hot-key-control.md)|NM_OUTOFMEMORY|
|[Controle de lista](../mfc/list-control-and-list-view.md)|LVN_ITEMCHANGE|
|[Controle de árvore](../mfc/tree-control-styles.md)|TVN_SELCHANGE|
|[Controle de guia](../mfc/tab-controls-and-property-sheets.md)|TCN_SELCHANGE|
|[Controle de animação](../mfc/using-an-animation-control.md)|ACN_START|
|[Controle de seletor de tempo de data](../mfc/creating-the-date-and-time-picker-control.md)|DTN_DATETIMECHANGE|
|[Controle de calendário mensal](../mfc/month-calendar-control-examples.md)|MCN_SELCHANGE|
|[Controle de endereço IP](../mfc/reference/cipaddressctrl-class.md)|IPN_FIELDCHANGED|
|[Controle de caixa de combinação estendido](../mfc/creating-an-extended-combo-box-control.md)||
|Controle personalizado|TTN_GETDISPINFO|

## <a name="custom-controls"></a>Controles personalizados

O **Editor de caixa de diálogo** permite que você usar existente personalizados ou controles de usuário em um modelo de caixa de diálogo.

> [!NOTE]
> Controles personalizados nesse sentido não são deve ser confundido com controles ActiveX. Controles ActiveX foram chamados de controles personalizados do OLE. Além disso, não confunda esses controles com os controles desenhados pelo proprietário no Windows.

Essa funcionalidade destina-se a permitem que você use controles diferentes daqueles fornecidos pelo Windows. Em tempo de execução, o controle está associado uma classe de janela (não o mesmo que uma classe do C++). Uma maneira mais comum para realizar a mesma tarefa é instalar qualquer controle, como um controle estático, na caixa de diálogo. Em seguida, no tempo de execução, além de [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog) de função, remova esse controle e substituí-lo com seu próprio controle personalizado.

> [!NOTE]
> Essa é uma técnica antiga. É recomendável na maioria dos casos para escrever um controle ActiveX ou um controle comum do Windows de subclasse de hoje.

Para esses controles personalizados, você está limitado a:

- Definir o local na caixa de diálogo.

- Digitando uma legenda.

- Identifica o nome da classe do Windows do controle, pois o código do aplicativo deve registrar o controle com este nome.

- Digitar um valor hexadecimal de 32 bits que define o estilo do controle.

- Definindo o estilo estendido.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor de caixa de diálogo](../windows/dialog-editor.md)<br/>

<!--
[Adding Event Handlers for Dialog Box Controls](../windows/adding-event-handlers-for-dialog-box-controls.md)<br/>
[Dialog Box Controls and Variable Types](../ide/dialog-box-controls-and-variable-types.md)<br/>
[Controls](../mfc/controls-mfc.md)<br/>-->