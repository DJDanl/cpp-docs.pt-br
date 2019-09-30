---
title: Criando uma folha de propriedades sem janela restrita
ms.date: 11/04/2016
helpviewer_keywords:
- modeless property sheets
- property sheets, modeless
- Create method [MFC], property sheets
ms.assetid: eafd8a92-cc67-4a69-a5fb-742c920d1ae8
ms.openlocfilehash: 90f6dcd5659d308a4b39d6a7d5a42003fc1f2111
ms.sourcegitcommit: 1e6386be9084f70def7b3b8b4bab319a117102b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2019
ms.locfileid: "71685689"
---
# <a name="creating-a-modeless-property-sheet"></a>Criando uma folha de propriedades sem janela restrita

Normalmente, as folhas de propriedades que você criar serão modais. Ao usar uma folha de propriedades modal, o usuário deve fechar a folha de propriedades antes de usar qualquer outra parte do aplicativo. Este artigo descreve os métodos que você pode usar para criar uma folha de propriedades sem janela restrita que permite ao usuário manter a folha de propriedades aberta ao usar outras partes do aplicativo.

Para exibir uma folha de propriedades como uma caixa de diálogo sem janela restrita em vez de como uma caixa de diálogo modal, chame [CPropertySheet:: Create](../mfc/reference/cpropertysheet-class.md#create) em vez de [DoModal](../mfc/reference/cpropertysheet-class.md#domodal). Você também deve implementar algumas tarefas extras para dar suporte a uma folha de propriedades sem janela restrita.

Uma das tarefas adicionais é a troca de dados entre a folha de propriedades e o objeto externo que ele está modificando quando a folha de propriedades está aberta. Geralmente, essa é a mesma tarefa que para caixas de diálogo sem janela restrita de modelos. Parte dessa tarefa é implementar um canal de comunicação entre a folha de propriedades sem janela restrita e o objeto externo ao qual as configurações de propriedade se aplicam. Essa implementação é muito mais fácil se você derivar uma classe de [CPropertySheet](../mfc/reference/cpropertysheet-class.md) para sua folha de propriedades sem janela restrita. Este artigo pressupõe que você tenha feito isso.

Um método para a comunicação entre a folha de propriedades sem janela restrita e o objeto externo (a seleção atual em uma exibição, por exemplo) é definir um ponteiro da folha de propriedades para o objeto externo. Defina uma função (chamada de algo como `SetMyExternalObject`) na classe derivada `CPropertySheet` para alterar o ponteiro sempre que o foco for alterado de um objeto externo para outro. A função `SetMyExternalObject` precisa redefinir as configurações de cada página de propriedades para refletir o objeto externo selecionado recentemente. Para fazer isso, a função `SetMyExternalObject` deve ser capaz de acessar os objetos [CPropertyPage](../mfc/reference/cpropertypage-class.md) que pertencem à classe `CPropertySheet`.

A maneira mais conveniente de fornecer acesso a páginas de propriedades em uma folha de propriedades é inserir os objetos `CPropertyPage` no objeto-1 @no__t derivado. A inserção de objetos `CPropertyPage` no objeto derivado de-1 @no__t difere do design típico para caixas de diálogo modais, em que o proprietário da folha de Propriedades cria os objetos `CPropertyPage` e os passa para a folha de propriedades por meio de [CPropertySheet:: AddPage](../mfc/reference/cpropertysheet-class.md#addpage).

Há muitas alternativas de interface do usuário para determinar quando as configurações da folha de propriedades sem janela restrita devem ser aplicadas a um objeto externo. Uma alternativa é aplicar as configurações da página de propriedades atual sempre que o usuário alterar qualquer valor. Outra alternativa é fornecer um botão Apply, que permite ao usuário acumular alterações nas páginas de propriedades antes de confirmá-las para o objeto externo. Para obter informações sobre maneiras de lidar com o botão aplicar, consulte o artigo [manipulando o botão Aplicar](../mfc/handling-the-apply-button.md).

## <a name="see-also"></a>Consulte também

[Folhas de propriedades](../mfc/property-sheets-mfc.md)<br/>
[Trocando dados](../mfc/exchanging-data.md)<br/>
[Trabalhando com caixas de diálogo no MFC](../mfc/life-cycle-of-a-dialog-box.md)
