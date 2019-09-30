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
ms.openlocfilehash: 9a0199577ea46520c2eadc308812de8a1ce4b514
ms.sourcegitcommit: 1e6386be9084f70def7b3b8b4bab319a117102b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2019
ms.locfileid: "71685809"
---
# <a name="dialog-data-exchange"></a>Troca de dados da caixa de diálogo

Se você usar o mecanismo campo DDX, defina os valores iniciais das variáveis de membro do objeto Dialog, normalmente no manipulador `OnInitDialog` ou no construtor da caixa de diálogo. Imediatamente antes de a caixa de diálogo ser exibida, o mecanismo campo DDX da estrutura transfere os valores das variáveis de membro para os controles na caixa de diálogo, onde aparecem quando a própria caixa de diálogo aparece em resposta a `DoModal` ou `Create`. A implementação padrão de `OnInitDialog` em `CDialog` chama a função membro `UpdateData` da classe `CWnd` para inicializar os controles na caixa de diálogo.

O mesmo mecanismo transfere valores dos controles para as variáveis de membro quando o usuário clica no botão OK (ou sempre que você chama a função de membro `UpdateData` com o argumento **true**). O mecanismo de validação de dados da caixa de diálogo valida todos os itens de dados para os quais você especificou regras de validação.

A figura a seguir ilustra a troca de dados de caixa de diálogo.

Caixa de diálogo ![troca]de dados(../mfc/media/vc379d1.gif "caixa de dialogo troca de dados") <br/>
Troca de dados da caixa de diálogo

`UpdateData` funciona em ambas as direções, conforme especificado pelo parâmetro **bool** passado para ele. Para executar a troca, `UpdateData` configura um objeto `CDataExchange` e chama a substituição da função membro `DoDataExchange` da sua classe @no__t de caixa de diálogo. `DoDataExchange` usa um argumento do tipo `CDataExchange`. O objeto `CDataExchange` passado para `UpdateData` representa o contexto da troca, definindo tais informações como a direção da troca.

Quando você (ou um assistente de código) substituir `DoDataExchange`, especifique uma chamada para uma função campo DDX por membro de dados (Control). Cada função campo DDX sabe como trocar dados em ambas as direções com base no contexto fornecido pelo argumento `CDataExchange` passado para o `DoDataExchange` por `UpdateData`.

O MFC fornece muitas funções campo DDX para diferentes tipos de troca. O exemplo a seguir mostra uma substituição `DoDataExchange` na qual duas funções campo DDX e uma função DDV são chamadas:

[!code-cpp[NVC_MFCControlLadenDialog#49](../mfc/codesnippet/cpp/dialog-data-exchange_1.cpp)]

As linhas `DDX_` e `DDV_` são um mapa de dados. As funções campo DDX e DDV de exemplo mostradas são para um controle de caixa de seleção e um controle de caixa de edição, respectivamente.

Se o usuário cancelar uma caixa de diálogo modal, a função de membro `OnCancel` terminará a caixa de diálogo e `DoModal` retornará o valor **IDCANCEL**. Nesse caso, nenhum dado é trocado entre a caixa de diálogo e o objeto de diálogo.

## <a name="see-also"></a>Consulte também

[Troca e validação de dados da caixa de diálogo](../mfc/dialog-data-exchange-and-validation.md)<br/>
[Trabalhando com caixas de diálogo no MFC](../mfc/life-cycle-of-a-dialog-box.md)<br/>
[Validação dos dados da caixa de diálogo](../mfc/dialog-data-validation.md)
