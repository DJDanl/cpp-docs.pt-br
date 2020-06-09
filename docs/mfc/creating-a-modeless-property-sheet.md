---
title: Criando uma folha de propriedades sem janela restrita
ms.date: 11/04/2016
helpviewer_keywords:
- modeless property sheets
- property sheets, modeless
- Create method [MFC], property sheets
ms.assetid: eafd8a92-cc67-4a69-a5fb-742c920d1ae8
ms.openlocfilehash: 7a44d96adf0a25a401fbc2e561bd7d32758a37d2
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84617164"
---
# <a name="creating-a-modeless-property-sheet"></a>Criando uma folha de propriedades sem janela restrita

Normalmente, as folhas de propriedades que você criar serão modais. Ao usar uma folha de propriedades modal, o usuário deve fechar a folha de propriedades antes de usar qualquer outra parte do aplicativo. Este artigo descreve os métodos que você pode usar para criar uma folha de propriedades sem janela restrita que permite ao usuário manter a folha de propriedades aberta ao usar outras partes do aplicativo.

Para exibir uma folha de propriedades como uma caixa de diálogo sem janela restrita em vez de como uma caixa de diálogo modal, chame [CPropertySheet:: Create](reference/cpropertysheet-class.md#create) em vez de [DoModal](reference/cpropertysheet-class.md#domodal). Você também deve implementar algumas tarefas extras para dar suporte a uma folha de propriedades sem janela restrita.

Uma das tarefas adicionais é a troca de dados entre a folha de propriedades e o objeto externo que ele está modificando quando a folha de propriedades está aberta. Geralmente, essa é a mesma tarefa que para caixas de diálogo sem janela restrita de modelos. Parte dessa tarefa é implementar um canal de comunicação entre a folha de propriedades sem janela restrita e o objeto externo ao qual as configurações de propriedade se aplicam. Essa implementação é muito mais fácil se você derivar uma classe de [CPropertySheet](reference/cpropertysheet-class.md) para sua folha de propriedades sem janela restrita. Este artigo pressupõe que você tenha feito isso.

Um método para a comunicação entre a folha de propriedades sem janela restrita e o objeto externo (a seleção atual em uma exibição, por exemplo) é definir um ponteiro da folha de propriedades para o objeto externo. Defina uma função (chamada de algo como `SetMyExternalObject` ) na `CPropertySheet` classe derivada para alterar o ponteiro sempre que o foco for alterado de um objeto externo para outro. A `SetMyExternalObject` função precisa redefinir as configurações para cada página de propriedades para refletir o objeto externo selecionado recentemente. Para fazer isso, a `SetMyExternalObject` função deve ser capaz de acessar os objetos [CPropertyPage](reference/cpropertypage-class.md) que pertencem à `CPropertySheet` classe.

A maneira mais conveniente de fornecer acesso a páginas de propriedades dentro de uma folha de propriedades é inserir os `CPropertyPage` objetos no `CPropertySheet` objeto derivado. A inserção de `CPropertyPage` objetos no `CPropertySheet` objeto derivado difere do design típico para caixas de diálogo modais, em que o proprietário da folha de Propriedades cria os `CPropertyPage` objetos e os passa para a folha de propriedades por meio de [CPropertySheet:: AddPage](reference/cpropertysheet-class.md#addpage).

Há muitas alternativas de interface do usuário para determinar quando as configurações da folha de propriedades sem janela restrita devem ser aplicadas a um objeto externo. Uma alternativa é aplicar as configurações da página de propriedades atual sempre que o usuário alterar qualquer valor. Outra alternativa é fornecer um botão Apply, que permite ao usuário acumular alterações nas páginas de propriedades antes de confirmá-las para o objeto externo. Para obter informações sobre maneiras de lidar com o botão aplicar, consulte o artigo [manipulando o botão Aplicar](handling-the-apply-button.md).

## <a name="see-also"></a>Consulte também

[Folhas de propriedades](property-sheets-mfc.md)<br/>
[Trocando dados](exchanging-data.md)<br/>
[Trabalhar com caixas de diálogo no MFC](life-cycle-of-a-dialog-box.md)
