---
title: CReBar vs. CReBarCtrl
ms.date: 11/04/2016
helpviewer_keywords:
- CReBar class [MFC], vs. CReBarCtrl
- rebar controls [MFC], CReBarCtrl class [MFC]
- GetReBarCtrl class [MFC]
ms.assetid: 7f9c1d7e-5d5f-4956-843c-69ed3df688d0
ms.openlocfilehash: 05decc095e43426044c4487b9aca05268642f915
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620453"
---
# <a name="crebar-vs-crebarctrl"></a>CReBar vs. CReBarCtrl

O MFC fornece duas classes para criar rebarras: [CReBar](reference/crebar-class.md) e [CReBarCtrl](reference/crebarctrl-class.md) (que encapsula a API de controle comum do Windows). `CReBar`fornece toda a funcionalidade do controle comum de rebar e trata de muitas das configurações de controle comuns e estruturas necessárias para você.

`CReBarCtrl`é uma classe wrapper para o controle rebar do Win32 e, portanto, pode ser mais fácil de implementar se você não pretende integrar o rebar à arquitetura do MFC. Se você planeja usar `CReBarCtrl` e integrar o rebar à arquitetura do MFC, deve tomar cuidado adicional para comunicar as manipulações de controle rebar ao MFC. Essa comunicação não é difícil; no entanto, ele é um trabalho adicional que é desnecessário quando você usa o `CReBar` .

O Visual C++ fornece duas maneiras de aproveitar o controle comum de rebar.

- Crie o rebar usando `CReBar` e, em seguida, chame [CReBar:: GetReBarCtrl](reference/crebar-class.md#getrebarctrl) para obter acesso às `CReBarCtrl` funções de membro.

    > [!NOTE]
    >  `CReBar::GetReBarCtrl`é uma função de membro embutida que converte **esse** ponteiro do objeto rebar. Isso significa que, em tempo de execução, a chamada de função não tem sobrecarga.

- Crie o rebar usando o construtor de [CReBarCtrl](reference/crebarctrl-class.md).

Qualquer um dos métodos fornecerá acesso às funções de membro do controle rebar. Quando você chama `CReBar::GetReBarCtrl` , ele retorna uma referência a um `CReBarCtrl` objeto para que você possa usar qualquer conjunto de funções de membro. Consulte [CReBar](reference/crebar-class.md) para obter informações sobre como construir e criar um rebar usando `CReBar` .

## <a name="see-also"></a>Consulte também

[Usando CReBarCtrl](using-crebarctrl.md)<br/>
[Controles](controls-mfc.md)
