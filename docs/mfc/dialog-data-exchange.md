---
title: Troca de dados da caixa de diálogo
ms.date: 11/19/2018
helpviewer_keywords:
- initializing dialog boxes
- canceling data exchange
- dialog box data, retrieving
- DDX (dialog data exchange), data exchange mechanism
- dialog boxes [MFC], initializing
- dialog boxes [MFC], retrieving user input using DDX
- dialog box data
- dialog boxes [MFC], data exchange
- CDataExchange class [MFC], using DDX
- DoDataExchange method [MFC]
- user input [MFC], retrieving from MFC dialog boxes
- capturing user input [MFC]
- transferring dialog box data
- DDX (dialog data exchange), canceling
- UpdateData method [MFC]
- retrieving dialog box data [MFC]
ms.assetid: 4675f63b-41d2-45ed-b6c3-235ad8ab924b
ms.openlocfilehash: 338630aef358d9490461179288d5c45a2d3b821c
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57302294"
---
# <a name="dialog-data-exchange"></a>Troca de dados da caixa de diálogo

Se você usar o mecanismo DDX, você defina os valores iniciais da caixa de diálogo variáveis de membro do objeto, normalmente no seu `OnInitDialog` manipulador ou o construtor de caixa de diálogo. Imediatamente antes da caixa de diálogo for exibida, mecanismo DDX da estrutura transfere os valores das variáveis de membro para os controles na caixa de diálogo, onde eles aparecem quando a caixa de diálogo é exibida em resposta às `DoModal` ou `Create`. A implementação padrão de `OnInitDialog` na `CDialog` chamadas a `UpdateData` a função de membro da classe `CWnd` para inicializar os controles na caixa de diálogo.

O mesmo mecanismo transfere valores dos controles para as variáveis de membro quando o usuário clica no botão Okey (ou sempre que você chamar o `UpdateData` função de membro com o argumento **verdadeiro**). O mecanismo de validação de dados de caixa de diálogo valida quaisquer itens de dados para o qual você especificou as regras de validação.

A figura a seguir ilustra a troca de dados de caixa de diálogo.

![Troca de dados de caixa de diálogo](../mfc/media/vc379d1.gif "troca de dados de caixa de diálogo") <br/>
Troca de dados da caixa de diálogo

`UpdateData` funciona em ambas as direções, conforme especificado pelo **BOOL** parâmetro passado para ele. Para executar o exchange `UpdateData` configura uma `CDataExchange` objeto e chamadas de sua classe de caixa de diálogo Substituir da `CDialog`do `DoDataExchange` função de membro. `DoDataExchange` usa um argumento do tipo `CDataExchange`. O `CDataExchange` objeto passado para `UpdateData` representa o contexto do exchange, definindo tais informações como a direção da troca.

Quando você (ou um Assistente de código) substitui `DoDataExchange`, você especifica uma chamada para uma função DDX por membro de dados (controle). Cada função DDX sabe como a troca de dados em ambas as direções com base no contexto fornecido pelo `CDataExchange` argumento passado para seus `DoDataExchange` por `UpdateData`.

MFC fornece muitas funções DDX para tipos diferentes do exchange. A exemplo a seguir mostra um `DoDataExchange` no qual DDX duas funções e uma função DDV são chamados de substituição:

[!code-cpp[NVC_MFCControlLadenDialog#49](../mfc/codesnippet/cpp/dialog-data-exchange_1.cpp)]

O `DDX_` e `DDV_` linhas são um mapa de dados. As funções de amostra DDX e DDV mostradas são para um controle de caixa de seleção e um controle de caixa de edição, respectivamente.

Se o usuário cancelar a caixa de diálogo modal, o `OnCancel` função de membro termina a caixa de diálogo e `DoModal` retorna o valor **IDCANCEL**. Nesse caso, não há dados são trocados entre a caixa de diálogo e o objeto de caixa de diálogo.

## <a name="see-also"></a>Consulte também

[Troca e validação de dados da caixa de diálogo](../mfc/dialog-data-exchange-and-validation.md)<br/>
[Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)<br/>
[Validação dos dados da caixa de diálogo](../mfc/dialog-data-validation.md)
