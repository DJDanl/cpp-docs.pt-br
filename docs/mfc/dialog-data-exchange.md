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
ms.openlocfilehash: c12953ab0b9922788747246a97115188b2f686ed
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84616819"
---
# <a name="dialog-data-exchange"></a>Troca de dados da caixa de diálogo

Se você usar o mecanismo campo DDX, defina os valores iniciais das variáveis de membro do objeto Dialog, normalmente no `OnInitDialog` manipulador ou no construtor da caixa de diálogo. Imediatamente antes de a caixa de diálogo ser exibida, o mecanismo campo DDX da estrutura transfere os valores das variáveis de membro para os controles na caixa de diálogo, onde aparecem quando a própria caixa de diálogo aparece em resposta a `DoModal` ou `Create` . A implementação padrão de `OnInitDialog` no `CDialog` chama a `UpdateData` função de membro da classe `CWnd` para inicializar os controles na caixa de diálogo.

O mesmo mecanismo transfere valores dos controles para as variáveis de membro quando o usuário clica no botão OK (ou sempre que você chama a `UpdateData` função de membro com o argumento **true**). O mecanismo de validação de dados da caixa de diálogo valida todos os itens de dados para os quais você especificou regras de validação.

A figura a seguir ilustra a troca de dados de caixa de diálogo.

![Troca de dados da caixa de diálogo](../mfc/media/vc379d1.gif "Troca de dados da caixa de diálogo") <br/>
Troca de dados da caixa de diálogo

`UpdateData`funciona em ambas as direções, conforme especificado pelo parâmetro **bool** passado para ele. Para executar a troca, o `UpdateData` configura um `CDataExchange` objeto e chama a substituição da função de membro da sua classe de caixa de diálogo `CDialog` `DoDataExchange` . `DoDataExchange`usa um argumento do tipo `CDataExchange` . O `CDataExchange` objeto passado para `UpdateData` representa o contexto da troca, definindo informações como a direção da troca.

Quando você (ou um assistente de código) for substituído `DoDataExchange` , especifique uma chamada para uma função campo DDX por membro de dados (Control). Cada função campo DDX sabe como trocar dados em ambas as direções com base no contexto fornecido pelo `CDataExchange` argumento passado para seu `DoDataExchange` por `UpdateData` .

O MFC fornece muitas funções campo DDX para diferentes tipos de troca. O exemplo a seguir mostra uma `DoDataExchange` substituição em que duas funções campo DDX e uma função DDV são chamadas:

[!code-cpp[NVC_MFCControlLadenDialog#49](codesnippet/cpp/dialog-data-exchange_1.cpp)]

As `DDX_` `DDV_` linhas e são um mapa de dados. As funções campo DDX e DDV de exemplo mostradas são para um controle de caixa de seleção e um controle de caixa de edição, respectivamente.

Se o usuário cancelar uma caixa de diálogo modal, a `OnCancel` função de membro terminará a caixa de diálogo e `DoModal` retornará o valor **IDCANCEL**. Nesse caso, nenhum dado é trocado entre a caixa de diálogo e o objeto de diálogo.

## <a name="see-also"></a>Consulte também

[Troca e validação de dados da caixa de diálogo](dialog-data-exchange-and-validation.md)<br/>
[Trabalhar com caixas de diálogo no MFC](life-cycle-of-a-dialog-box.md)<br/>
[Validação dos dados da caixa de diálogo](dialog-data-validation.md)
