---
title: Controles em caixas de diálogo (C++) | Microsoft Docs
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
ms.openlocfilehash: 6360491ebb4478ee4ce22115eced7ed672866565
ms.sourcegitcommit: 24592ba0a38c7c996ffd3d55fe1024231a59ccc2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/18/2019
ms.locfileid: "56336508"
---
# <a name="controls-in-dialog-boxes-c"></a>Controles em caixas de diálogo (C++)

Você pode adicionar controles a uma caixa de diálogo usando o [guia do Editor de caixa de diálogo](../windows/dialog-editor-tab-toolbox.md) na [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox), que permite que você escolha o controle desejado e arraste-o para a caixa de diálogo. Por padrão, a janela de caixa de ferramentas é definida para ocultar automaticamente. Ele aparece como uma guia na margem esquerda da sua solução quando o editor de caixa de diálogo é aberto. No entanto, você pode fixar o **caixa de ferramentas** janela na posição clicando o **ocultar automaticamente** botão no canto superior direito da janela. Para obter mais informações sobre como controlar o comportamento desta janela, consulte [gerenciamento de janela](/visualstudio/ide/customizing-window-layouts-in-visual-studio).

A maneira mais rápida para adicionar controles a uma caixa de diálogo, reposicionar os controles existentes ou mover os controles de uma caixa de diálogo para outra, é usar o método de arrastar e soltar. A posição do controle é descrita em uma linha pontilhada até que ele é colocado na caixa de diálogo. Quando você adiciona um controle a uma caixa de diálogo com o método de arrastar e soltar, o controle recebe uma altura padrão apropriada para esse tipo de controle.

Quando você adicionar um controle a uma caixa de diálogo ou reposicioná-lo, seu posicionamento final pode ser determinado por guias ou as margens, ou se você tiver ativada a grade de layout.

Depois de adicionar um controle à caixa de diálogo, você pode alterar as propriedades, como a legenda na [janela de propriedades](/visualstudio/ide/reference/properties-window). Você pode selecionar vários controles e alterar suas propriedades de uma só vez.

- [Como: Adicionar, editar ou excluir controles](adding-editing-or-deleting-controls.md)

- [Como: Organizar os controles](../windows/arrangement-of-controls-on-dialog-boxes.md)

- [Como: Definir valores e controlar o acesso](../windows/defining-mnemonics-access-keys.md)

Os controles padrão disponíveis na **caixa de ferramentas** padrão eventos são:

|Nome do controle|Evento padrão|
|---|---|
|[Controle de botão](../mfc/reference/cbutton-class.md)|BN_CLICKED|
|[Controle de caixa de seleção](../mfc/reference/styles-used-by-mfc.md#button-styles)|BN_CLICKED|
|[Controle de caixa de combinação](../mfc/reference/ccombobox-class.md)|CBN_SELCHANGE|
|[Controle de edição](../mfc/reference/cedit-class.md)|EN_CHANGE|
|Caixa de grupo|(Não aplicável)|
|[Controle de caixa de listagem](../mfc/reference/clistbox-class.md)|LBN_SELCHANGE|
|[Controle de botão de opção](../mfc/reference/styles-used-by-mfc.md#button-styles)|BN_CLICKED|
|[Controle de texto estático](../mfc/reference/cstatic-class.md)|(Não aplicável)|
|[Controle de imagem](../mfc/reference/cpictureholder-class.md)|(Não aplicável)|
|[Controle Rich Editar 2.0](../mfc/using-cricheditctrl.md)|EN_CHANGE|
|[Controle de barra de rolagem](../mfc/reference/cscrollbar-class.md)|NM_THEMECHANGED|

Para obter mais informações sobre como usar o **RichEdit 1.0** controle com o MFC, consulte [usando o controle RichEdit 1.0 com MFC](../windows/using-the-richedit-1-0-control-with-mfc.md) e [exemplos de controle Editar Rich](../mfc/rich-edit-control-examples.md).

O [controles comuns do Windows](../mfc/controls-mfc.md) disponível na **caixa de ferramentas** fornecer funcionalidade aumentada em seu aplicativo. Entre elas estão:

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

Para obter mais informações, consulte [Classes de controle](../mfc/control-classes.md), [Classes da caixa de diálogo](../mfc/dialog-box-classes.md), e [estilos de barra de rolagem](../mfc/reference/styles-used-by-mfc.md#scroll-bar-styles).

## <a name="custom-controls"></a>Controles personalizados

O editor de caixa de diálogo permite usar existente "custom" ou controles de "usuário" em um modelo de caixa de diálogo.

> [!NOTE]
> Controles personalizados nesse sentido não são deve ser confundido com controles ActiveX. Controles ActiveX foram chamados de controles personalizados do OLE. Além disso, não confunda esses controles com os controles desenhados pelo proprietário no Windows.

Essa funcionalidade destina-se a permitem que você use controles diferentes daqueles fornecidos pelo Windows. Em tempo de execução, o controle está associado uma classe de janela (não o mesmo que uma classe do C++). Uma maneira mais comum para realizar a mesma tarefa é instalar qualquer controle, como um controle estático, na caixa de diálogo. Em seguida, no tempo de execução, além de [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog) de função, remova esse controle e substituí-lo com seu próprio controle personalizado.

Essa é uma técnica antiga. É recomendável na maioria dos casos para escrever um controle ActiveX ou um controle comum do Windows de subclasse de hoje.

Para esses controles personalizados, você está limitado a:

- Definir o local na caixa de diálogo.

- Digitando uma legenda.

- Identifica o nome da classe do Windows do controle (o código do aplicativo deve registrar o controle com esse nome).

- Digitar um valor hexadecimal de 32 bits que define o estilo do controle.

- Definindo o estilo estendido.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Adicionando manipuladores de eventos a controles de caixa de diálogo](../windows/adding-event-handlers-for-dialog-box-controls.md)<br/>
[Controles da caixa de diálogo e tipos de variável](../ide/dialog-box-controls-and-variable-types.md)<br/>
[Editor de caixa de diálogo](../windows/dialog-editor.md)<br/>
[Controles](../mfc/controls-mfc.md)<br/>