---
title: Recuperando dados a partir do objeto da caixa de diálogo
ms.date: 11/04/2016
helpviewer_keywords:
- dialog boxes [MFC], retrieving user data
- dialog box data [MFC]
- data [MFC], retrieving
- GetDlgItemText method [MFC]
- SetDlgItemText method [MFC]
- SetWindowText method [MFC]
- dialog box data [MFC], retrieving
- retrieving data [MFC]
- user input [MFC], retrieving from MFC dialog boxes
- capturing user input [MFC]
- dialog box controls [MFC], initializing values
- DDX (dialog data exchange) [MFC]
- MFC dialog boxes [MFC], retrieving user input
- data retrieval [MFC], dialog boxes
- data [MFC], dialog boxes
- DDX (dialog data exchange) [MFC], about DDX
- DDX (dialog data exchange) [MFC], retrieving data from Dialog object
- GetWindowText method [MFC]
ms.assetid: bdca2b61-6b53-4c2e-b426-8712c7a38ec0
ms.openlocfilehash: 903d76a1e672d05a3c093e528f7153562df8e3e5
ms.sourcegitcommit: 1e6386be9084f70def7b3b8b4bab319a117102b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2019
ms.locfileid: "71685575"
---
# <a name="retrieving-data-from-the-dialog-object"></a>Recuperando dados a partir do objeto da caixa de diálogo

A estrutura fornece uma maneira fácil de inicializar os valores de controles em uma caixa de diálogo e recuperar valores dos controles. A abordagem manual mais trabalhoso é chamar funções como as funções de membro `SetDlgItemText` e `GetDlgItemText` da classe `CWnd`, que se aplicam a janelas de controle. Com essas funções, você acessa cada controle individualmente para definir ou obter seu valor, chamando funções como `SetWindowText` e `GetWindowText`. A abordagem da estrutura automatiza a inicialização e a recuperação.

A campo DDX (caixa de diálogo de troca de dados) permite que você troque dados entre os controles na caixa de diálogo e as variáveis de membro no objeto Dialog mais facilmente. Esse intercâmbio funciona de ambas as maneiras. Para inicializar os controles na caixa de diálogo, você pode definir os valores dos membros de dados no objeto de diálogo e a estrutura transferirá os valores para os controles antes de a caixa de diálogo ser exibida. Então, você pode, a qualquer momento, atualizar os membros de dados da caixa de diálogo com os dados inseridos pelo usuário. Nesse ponto, você pode usar os dados referindo-se às variáveis de membro de dados.

Você também pode organizar os valores dos controles de caixa de diálogo para serem validados automaticamente com a validação de dados de caixa de diálogo (DDV).

CAMPO DDX e DDV são explicados com mais detalhes em [troca e validação de dados de diálogo](../mfc/dialog-data-exchange-and-validation.md).

Para uma caixa de diálogo modal, você pode recuperar os dados inseridos pelo usuário quando `DoModal` retorna IDOK, mas antes de o objeto da caixa de diálogo ser destruído. Para uma caixa de diálogo sem janela restrita, você pode recuperar dados do objeto de caixa de diálogo a qualquer momento chamando `UpdateData` com o argumento **true** e, em seguida, acessando as variáveis de membro da classe DIALOG. Esse assunto é discutido com mais detalhes em [troca e validação de dados de diálogo](../mfc/dialog-data-exchange-and-validation.md).

## <a name="see-also"></a>Consulte também

[Trabalhando com caixas de diálogo no MFC](../mfc/life-cycle-of-a-dialog-box.md)
