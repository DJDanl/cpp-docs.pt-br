---
title: Criando uma folha de propriedades sem janela restrita
ms.date: 11/04/2016
helpviewer_keywords:
- modeless property sheets
- property sheets, modeless
- Create method [MFC], property sheets
ms.assetid: eafd8a92-cc67-4a69-a5fb-742c920d1ae8
ms.openlocfilehash: 39285927b67091f5b8762dab56009712d806d259
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57302254"
---
# <a name="creating-a-modeless-property-sheet"></a>Criando uma folha de propriedades sem janela restrita

Normalmente, as folhas de propriedades que você cria será modais. Ao usar uma folha de propriedades modal, o usuário deve fechar a folha de propriedades antes de usar qualquer outra parte do aplicativo. Este artigo descreve métodos que você pode usar para criar uma folha de propriedades sem janela restrita que permite ao usuário manter a folha de propriedades aberta durante o uso de outras partes do aplicativo.

Para exibir uma folha de propriedades como uma caixa de diálogo sem janela restrita, em vez de como uma caixa de diálogo modal, chame [CPropertySheet::Create](../mfc/reference/cpropertysheet-class.md#create) em vez de [DoModal](../mfc/reference/cpropertysheet-class.md#domodal). Você também deve implementar algumas tarefas adicionais para dar suporte a uma folha de propriedades sem janela restrita.

Uma das tarefas adicionais está trocando dados entre a folha de propriedades e o objeto externo que ele está modificando quando a folha de propriedades é aberta. Isso geralmente é a mesma tarefa de caixas de diálogo sem janela restrita padrão. Parte dessa tarefa é implementar um canal de comunicação entre a folha de propriedades sem janela restrita e o objeto externo ao qual aplicam as configurações de propriedade. Essa implementação é muito mais fácil se você derivar uma classe de [CPropertySheet](../mfc/reference/cpropertysheet-class.md) para sua folha de propriedades sem janela restrita. Este artigo pressupõe que você tenha feito isso.

Um método de comunicação entre a folha de propriedades sem janela restrita e externo (a seleção atual em uma exibição, por exemplo) do objeto é definir um ponteiro de folha de propriedades para o objeto externo. Definir uma função (chamado semelhante `SetMyExternalObject`) na `CPropertySheet`-derivado da classe para alterar o ponteiro sempre que o foco é alterado de um objeto externo para outro. O `SetMyExternalObject` função precisar redefinir as configurações para cada página de propriedades para refletir o objeto externo recém-selecionado. Para fazer isso, o `SetMyExternalObject` função deve ser capaz de acessar o [CPropertyPage](../mfc/reference/cpropertypage-class.md) objetos que pertencem ao `CPropertySheet` classe.

A maneira mais conveniente para fornecer acesso a páginas de propriedade de uma folha de propriedades é inserir a `CPropertyPage` objetos no `CPropertySheet`-objeto derivado. Inserindo `CPropertyPage` objetos na `CPropertySheet`-objeto derivado difere de design comum para caixas de diálogo modal, em que o proprietário da folha de propriedades cria a `CPropertyPage` objetos e os passa para a folha de propriedades por meio de [ CPropertySheet::AddPage](../mfc/reference/cpropertysheet-class.md#addpage).

Há diversas alternativas de interface do usuário para determinar quando as configurações da folha de propriedades sem janela restrita devem ser aplicadas a um objeto externo. Uma alternativa é aplicar as configurações da página de propriedades atual sempre que o usuário altera qualquer valor. Outra alternativa é fornecer um botão Aplicar, que permite ao usuário a se acumular alterações nas páginas de propriedades antes de confirmá-las para o objeto externo. Para obter informações sobre maneiras de lidar com o botão Aplicar, consulte o artigo [manipulando o botão Aplicar](../mfc/handling-the-apply-button.md).

## <a name="see-also"></a>Consulte também

[Folhas de propriedades](../mfc/property-sheets-mfc.md)<br/>
[Trocando dados](../mfc/exchanging-data.md)<br/>
[Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)
