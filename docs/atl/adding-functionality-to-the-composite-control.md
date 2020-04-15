---
title: Adicionando funcionalidade ao controle composto
ms.date: 11/04/2016
helpviewer_keywords:
- event handlers [C++], ActiveX controls
- composite controls, handling events
- ActiveX controls [C++], events
ms.assetid: 98f85681-9564-480d-af38-03f9733fe58b
ms.openlocfilehash: 5de18f863831973af384d2456adb5b2214f0dd68
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317424"
---
# <a name="adding-functionality-to-the-composite-control"></a>Adicionando funcionalidade ao controle composto

Uma vez que você tenha inserido quaisquer controles necessários no controle composto, o próximo passo envolve adicionar novas funcionalidades. Essa nova funcionalidade geralmente se enquadra em duas categorias:

- Suporte a interfaces adicionais e personalização do comportamento do seu controle composto com recursos adicionais e específicos.

- Manipulação de eventos a partir do controle ActiveX contido (ou controles).

Para o propósito e escopo deste artigo, o restante desta seção se concentra apenas no manuseio de eventos a partir de controles ActiveX.

> [!NOTE]
> Se você precisar lidar com mensagens dos controles do Windows, consulte [Implementando uma janela](../atl/implementing-a-window.md) para obter mais informações sobre o manuseio de mensagens no ATL.

Depois de inserir um controle ActiveX no recurso de diálogo, clique com o botão direito do mouse no controle e clique **em Adicionar manipulador de eventos**. Selecione o evento que deseja lidar e clique **em Adicionar e Editar**. O código do manipulador de eventos será adicionado ao arquivo .h do controle.

Os pontos de conexão para controles ActiveX no controle composto são automaticamente conectados e desconectados por meio de chamadas para [CComCompositeControl::AdviseSinkMap](../atl/reference/ccomcompositecontrol-class.md#advisesinkmap).

## <a name="see-also"></a>Confira também

[Fundamentos do controle composto](../atl/atl-composite-control-fundamentals.md)
