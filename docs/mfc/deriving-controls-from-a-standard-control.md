---
title: Derivando controles a partir de um controle padrão
ms.date: 11/04/2016
helpviewer_keywords:
- standard controls [MFC], deriving controls from
- common controls [MFC], deriving from
- derived controls
- controls [MFC], derived
- Windows common controls [MFC], deriving from
- standard controls
ms.assetid: a6f84315-7007-4e0e-8576-78be81254802
ms.openlocfilehash: 54e43c8445bb6b8db4c6a7a4b28890e81be52d6c
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84616965"
---
# <a name="deriving-controls-from-a-standard-control"></a>Derivando controles a partir de um controle padrão

Assim como acontece com qualquer classe derivada de [CWnd](reference/cwnd-class.md), você pode modificar o comportamento de um controle derivando uma nova classe de uma classe de controle existente.

### <a name="to-create-a-derived-control-class"></a>Para criar uma classe de controle derivada

1. Derive sua classe de uma classe de controle existente e, opcionalmente, substitua a `Create` função membro para que ela forneça os argumentos necessários para a função de classe base `Create` .

1. Forneça funções de membro do manipulador de mensagens e entradas de mapa de mensagens para modificar o comportamento do controle em resposta a mensagens específicas do Windows. Consulte [mapeando mensagens para funções](reference/mapping-messages-to-functions.md).

1. Forneça novas funções de membro para estender a funcionalidade do controle (opcional).

Usar um controle derivado em uma caixa de diálogo requer trabalho extra. Os tipos e posições de controles em uma caixa de diálogo normalmente são especificados em um recurso de modelo de caixa de diálogo. Se você criar uma classe de controle derivado, não poderá especificá-la em um modelo de caixa de diálogo, pois o compilador de recurso não sabe nada sobre a classe derivada.

#### <a name="to-place-your-derived-control-in-a-dialog-box"></a>Para posicionar o controle derivado em uma caixa de diálogo

1. Incorpore um objeto da classe de controle derivada na declaração de sua classe de caixa de diálogo derivada.

1. Substitua a `OnInitDialog` função de membro na sua classe de caixa de diálogo para chamar a `SubclassDlgItem` função de membro para o controle derivado.

`SubclassDlgItem`"cria dinamicamente subclasses" um controle criado a partir de um modelo de caixa de diálogo. Quando um controle é dividido dinamicamente em uma subclasse, você se conecta ao Windows, processa algumas mensagens dentro de seu próprio aplicativo e, em seguida, passa as mensagens restantes para o Windows. Para obter mais informações, consulte a função membro [SubclassDlgItem](reference/cwnd-class.md#subclassdlgitem) da classe `CWnd` na *referência do MFC*. O exemplo a seguir mostra como você pode escrever uma substituição de `OnInitDialog` para chamar `SubclassDlgItem` :

[!code-cpp[NVC_MFCControlLadenDialog#3](codesnippet/cpp/deriving-controls-from-a-standard-control_1.cpp)]

Como o controle derivado é inserido na classe Dialog, ele será construído quando a caixa de diálogo for construída e será destruída quando a caixa de diálogo for destruída. Compare este código ao exemplo em [adicionando controles manualmente](adding-controls-by-hand.md).

## <a name="see-also"></a>Consulte também

[Criando e usando controles](making-and-using-controls.md)<br/>
[Controles](controls-mfc.md)
