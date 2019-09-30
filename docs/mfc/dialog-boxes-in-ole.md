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
ms.openlocfilehash: 997bfc0bda05f5a2520c102cb38777b533bcef95
ms.sourcegitcommit: 1e6386be9084f70def7b3b8b4bab319a117102b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2019
ms.locfileid: "71685781"
---
# <a name="dialog-boxes-in-ole"></a>Caixas de diálogo em OLE

Enquanto um usuário executa um aplicativo habilitado para OLE, há ocasiões em que o aplicativo precisa de informações do usuário para realizar a operação. As classes OLE do MFC fornecem várias caixas de diálogo para reunir as informações necessárias. Este tópico lista as tarefas tratadas pelas caixas de diálogo OLE e as classes necessárias para exibir essas caixas de diálogo. Para obter detalhes sobre as caixas de diálogo OLE e as estruturas usadas para personalizar seu comportamento, consulte [referência do MFC](../mfc/mfc-desktop-applications.md).

*Inserir objeto*<br/>
Essa caixa de diálogo permite que o usuário insira objetos recém-criados ou existentes no documento composto. Ele também permite que o usuário escolha Exibir o item como um ícone e habilita o botão de comando Alterar ícone. Exiba essa caixa de diálogo quando o usuário escolher Inserir objeto no menu Editar. Use a classe [COleInsertDialog](../mfc/reference/coleinsertdialog-class.md) para exibir essa caixa de diálogo. Observe que você não pode inserir um aplicativo MDI em si mesmo. Um aplicativo que é um contêiner/servidor não pode ser inserido em si, a menos que seja um aplicativo SDI.

*Colar especial*<br/>
Essa caixa de diálogo permite que o usuário controle o formato usado ao colar dados em um documento composto. O usuário pode escolher o formato dos dados, se deseja inserir ou vincular os dados, e se deseja exibi-los como um ícone. Exibir esta caixa de diálogo quando o usuário escolher colar especial no menu Editar. Use a classe [COlePasteSpecialDialog](../mfc/reference/colepastespecialdialog-class.md) para exibir essa caixa de diálogo.

*Alterar ícone*<br/>
Essa caixa de diálogo permite que o usuário selecione qual ícone é exibido para representar o item vinculado ou inserido. Exiba essa caixa de diálogo quando o usuário escolher alterar ícone no menu Editar ou escolher o botão Alterar ícone nas caixas de diálogo colar especial ou converter. Exiba-o também quando o usuário abrir a caixa de diálogo Inserir objeto e escolher exibir como ícone. Use a classe [COleChangeIconDialog](../mfc/reference/colechangeicondialog-class.md) para exibir essa caixa de diálogo.

*Vertê*<br/>
Essa caixa de diálogo permite que o usuário altere o tipo de um item inserido ou vinculado. Por exemplo, se você inseriu um metarquivo em um documento composto e, posteriormente, deseja usar outro aplicativo para modificar o metarquivo inserido, poderá usar a caixa de diálogo Converter. Essa caixa de diálogo geralmente é exibida ao clicar no objeto de *tipo de item* no menu Editar e, em seguida, no menu em cascata, clique em converter. Use a classe [COleConvertDialog](../mfc/reference/coleconvertdialog-class.md) para exibir essa caixa de diálogo. Para obter um exemplo, execute o exemplo de OLE do MFC [OCLIENT](../overview/visual-cpp-samples.md).

*Editar links ou atualizar links*<br/>
A caixa de diálogo Editar links permite que o usuário altere as informações sobre a origem de um objeto vinculado. A caixa de diálogo atualizar links verifica as fontes de todos os itens vinculados na caixa de diálogo atual e exibe a caixa de diálogo Editar links, se necessário. Exiba a caixa de diálogo Editar links quando o usuário escolher links no menu Editar. A caixa de diálogo atualizar links geralmente é exibida quando um documento composto é aberto pela primeira vez. Use a classe [COleLinksDialog](../mfc/reference/colelinksdialog-class.md) ou [COleUpdateDialog](../mfc/reference/coleupdatedialog-class.md) , dependendo da caixa de diálogo que você deseja exibir.

*Servidor ocupado ou servidor não respondendo*<br/>
A caixa de diálogo servidor ocupado é exibida quando o usuário tenta ativar um item e o servidor não é capaz de lidar com a solicitação no momento, geralmente porque o servidor está sendo usado por outro usuário ou tarefa. A caixa de diálogo servidor não respondendo será exibida se o servidor não responder à solicitação de ativação. Essas caixas de diálogo são exibidas via `COleMessageFilter`, com base em uma implementação da interface OLE `IMessageFilter`, e o usuário pode decidir se deseja tentar a solicitação de ativação novamente. Use a classe [COleBusyDialog](../mfc/reference/colebusydialog-class.md) para exibir essa caixa de diálogo.

## <a name="see-also"></a>Consulte também

[Caixas de diálogo](../mfc/dialog-boxes.md)<br/>
[Trabalhando com caixas de diálogo no MFC](../mfc/life-cycle-of-a-dialog-box.md)<br/>
[OLEDB](../mfc/ole-in-mfc.md)
