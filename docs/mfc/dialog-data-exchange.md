---
title: "Troca de dados de caixa de diálogo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 35f280228d523c7401e2a90ca395a79a9c87cd51
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="dialog-data-exchange"></a>Troca de dados da caixa de diálogo
Se você usar o mecanismo DDX, você definir os valores iniciais da caixa de diálogo variáveis de membro do objeto, normalmente em seu `OnInitDialog` manipulador ou o construtor de caixa de diálogo. Imediatamente antes da caixa de diálogo é exibida, mecanismo DDX do framework transfere os valores das variáveis de membro para os controles na caixa de diálogo, em que aparecem quando a caixa de diálogo aparece em resposta a `DoModal` ou **criar** . A implementação padrão de `OnInitDialog` na `CDialog` chama o `UpdateData` função de membro de classe `CWnd` para inicializar os controles na caixa de diálogo.  
  
 O mesmo mecanismo transfere os valores dos controles para as variáveis de membro quando o usuário clica no botão Okey (ou sempre que você chamar o `UpdateData` função membro com o argumento **TRUE**). O mecanismo de validação de dados de caixa de diálogo valida os itens de dados para o qual você especificou as regras de validação.  
  
 A figura a seguir ilustra a troca de dados de caixa de diálogo.  
  
 ![Troca de dados de caixa de diálogo](../mfc/media/vc379d1.gif "vc379d1")  
Troca de dados da caixa de diálogo  
  
 `UpdateData`funciona em ambas as direções, conforme especificado pelo **BOOL** parâmetro passado para ele. Para executar o exchange, `UpdateData` configura um `CDataExchange` objeto e chamadas de substituição da sua classe de caixa de diálogo do `CDialog`do `DoDataExchange` função de membro. `DoDataExchange`aceita um argumento do tipo `CDataExchange`. O `CDataExchange` objeto passado para `UpdateData` representa o contexto do exchange, a definição de tais informações como a direção da troca.  
  
 Quando você (ou um Assistente de código) substituir `DoDataExchange`, especifique uma chamada para uma função DDX por membro de dados (controle). Cada função DDX sabe a troca de dados em ambas as direções com base no contexto fornecido pelo `CDataExchange` argumento passado para o `DoDataExchange` por `UpdateData`.  
  
 MFC fornece muitas funções DDX para diferentes tipos de troca. A exemplo a seguir mostra um `DoDataExchange` no qual DDX duas funções e uma função DDV são chamados de substituição:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#49](../mfc/codesnippet/cpp/dialog-data-exchange_1.cpp)]  
  
 O `DDX_` e `DDV_` linhas são um mapa de dados. As funções DDX e DDV de exemplo mostradas são para um controle de caixa de seleção e um controle de caixa de edição, respectivamente.  
  
 Se o usuário cancelar a caixa de diálogo modal, o `OnCancel` função membro encerra a caixa de diálogo e `DoModal` retorna o valor **IDCANCEL**. Nesse caso, não há dados são trocados entre a caixa de diálogo e o objeto de caixa de diálogo.  
  
## <a name="see-also"></a>Consulte também  
 [Caixa de diálogo dados Exchange e validação](../mfc/dialog-data-exchange-and-validation.md)   
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)   
 [Validação dos dados da caixa de diálogo](../mfc/dialog-data-validation.md)

