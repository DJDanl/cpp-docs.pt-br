---
title: Caixas de diálogo em OLE
ms.date: 11/04/2016
helpviewer_keywords:
- MFC dialog boxes [MFC], OLE dialog boxes
- OLE dialog boxes
- dialog boxes
- OLE dialog boxes [MFC], about OLE dialog boxes
- dialog boxes [MFC], about dialog boxes
- dialog boxes [MFC], OLE
- Insert object
ms.assetid: 73c41eb8-738a-4d02-9212-d3395bb09a3a
ms.openlocfilehash: 53e802e973ca78619252fcc4100a7cc50009f2ef
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50618498"
---
# <a name="dialog-boxes-in-ole"></a>Caixas de diálogo em OLE

Enquanto um usuário executa um aplicativo habilitado por OLE, há vezes quando o aplicativo precisa de informações do usuário para realizar a operação. As classes MFC OLE fornecem uma série de caixas de diálogo para coletar as informações necessárias. Este tópico lista as tarefas tratadas pelas caixas de diálogo OLE e as classes necessárias para exibir essas caixas de diálogo. Para obter detalhes sobre as caixas de diálogo OLE e as estruturas usadas para personalizar seu comportamento, consulte [referência da MFC](../mfc/mfc-desktop-applications.md).

*Inserir objeto*<br/>
Essa caixa de diálogo permite que o usuário inserir recém-criados ou objetos existentes no documento composto. Ele também permite que o usuário optar por exibir o item como um ícone e habilita o botão de comando de alteração de ícone. Quando o usuário escolhe Inserir objeto a partir do menu Editar, exiba essa caixa de diálogo. Use o [COleInsertDialog](../mfc/reference/coleinsertdialog-class.md) classe para exibir essa caixa de diálogo. Observe que você não é possível inserir um aplicativo MDI em si. Um aplicativo que é um contêiner/servidor não pode ser inserido no próprio, a menos que ele é um aplicativo SDI.

*Colar especial*<br/>
Essa caixa de diálogo permite que o usuário controlar o formato usado ao colar dados em um documento composto. O usuário pode escolher o formato dos dados, se deseja inserir ou vincular os dados e se deseja exibi-lo como um ícone. Quando o usuário escolhe Colar especial no menu Editar, exiba essa caixa de diálogo. Use o [COlePasteSpecialDialog](../mfc/reference/colepastespecialdialog-class.md) classe para exibir essa caixa de diálogo.

*Alterar ícone*<br/>
Essa caixa de diálogo permite que o usuário selecione qual ícone é exibido para representar o item vinculado ou inserido. Exiba esta caixa de diálogo quando o usuário escolhe alterar ícone no menu Editar ou escolhe o botão Alterar ícone no Colar especial ou caixas de diálogo de Convert. Também exibi-lo quando o usuário abre a caixa de diálogo Inserir objeto e escolhe exibir como ícone. Use o [COleChangeIconDialog](../mfc/reference/colechangeicondialog-class.md) classe para exibir essa caixa de diálogo.

*Converter*<br/>
Essa caixa de diálogo permite que o usuário altere o tipo de um item vinculado ou inserido. Por exemplo, se você tiver inserido um metarquivo em um documento composto e mais tarde deseja usar outro aplicativo para modificar o metarquivo incorporado, você pode usar a caixa de diálogo Converter. Geralmente, essa caixa de diálogo é exibida clicando *tipo de item* objeto no menu Editar e em seguida, no menu em cascata, em Converter. Use o [COleConvertDialog](../mfc/reference/coleconvertdialog-class.md) classe para exibir essa caixa de diálogo. Por exemplo, executar o exemplo OLE do MFC [OCLIENT](../visual-cpp-samples.md).

*Editar Links ou atualização*<br/>
A caixa de diálogo Editar Links permite que o usuário altere as informações sobre a origem de um objeto vinculado. A caixa de diálogo Links de atualização verifica as fontes de todos os itens vinculados na caixa de diálogo atual e exibe a caixa de diálogo Editar Links, se necessário. Exiba a caixa de diálogo Editar Links quando o usuário escolhe Links no menu Editar. A caixa de diálogo Links de atualização normalmente é exibida quando um documento composto é aberto pela primeira vez. Use o [COleLinksDialog](../mfc/reference/colelinksdialog-class.md) ou o [COleUpdateDialog](../mfc/reference/coleupdatedialog-class.md) de classe, dependendo de qual caixa de diálogo que você deseja exibir.

*Servidor ocupado ou não está respondendo*<br/>
A caixa de diálogo servidor ocupado é exibida quando o usuário tenta ativar um item e o servidor está atualmente não é possível manipular a solicitação, geralmente porque o servidor está em uso por outro usuário ou de tarefas. A caixa de diálogo servidor não respondendo será exibida se o servidor não responde à solicitação de ativação em todos os. Essas caixas de diálogo são exibidas por meio de `COleMessageFilter`, com base em uma implementação da interface OLE `IMessageFilter`, e o usuário pode decidir se deve tentar novamente a solicitação de ativação. Use o [COleBusyDialog](../mfc/reference/colebusydialog-class.md) classe para exibir essa caixa de diálogo.

## <a name="see-also"></a>Consulte também

[Caixas de diálogo](../mfc/dialog-boxes.md)<br/>
[Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)<br/>
[OLE](../mfc/ole-in-mfc.md)

