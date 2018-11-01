---
title: Adicionando funcionalidade ao controle de composição
ms.date: 11/04/2016
helpviewer_keywords:
- event handlers [C++], ActiveX controls
- composite controls, handling events
- ActiveX controls [C++], events
ms.assetid: 98f85681-9564-480d-af38-03f9733fe58b
ms.openlocfilehash: 1f0759c9182ad2a7e572bacee7707963d9b6ae2b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50532647"
---
# <a name="adding-functionality-to-the-composite-control"></a>Adicionando funcionalidade ao controle de composição

Após inserir todos os controles necessários para o controle de composição, a próxima etapa envolve a adição de nova funcionalidade. Essa nova funcionalidade geralmente se encaixa em duas categorias:

- Suporte a interfaces adicionais e personalizar o comportamento do controle de composição com recursos adicionais, específicos.

- Manipulação de eventos do controle ActiveX independente (ou controles).

A finalidade e o escopo deste artigo, o restante desta seção se concentra exclusivamente na manipulação de eventos de controles ActiveX.

> [!NOTE]
>  Se você precisar lidar com mensagens de controles do Windows, consulte [implementando uma janela](../atl/implementing-a-window.md) para obter mais informações sobre a lidar com mensagens no ATL.

Depois de inserir um controle ActiveX no recurso da caixa de diálogo, clique com botão direito do controle e clique em **Adicionar manipulador de eventos**. Selecione o evento que você deseja manipular e clique em **adicionar e editar**. O código de manipulador de eventos será adicionado ao arquivo. h do controle.

Pontos de Conexão para controles ActiveX do controle composto são automaticamente conectados e desconectados por meio de chamadas para [CComCompositeControl::AdviseSinkMap](../atl/reference/ccomcompositecontrol-class.md#advisesinkmap).

## <a name="see-also"></a>Consulte também

[Fundamentos do controle composto](../atl/atl-composite-control-fundamentals.md)

