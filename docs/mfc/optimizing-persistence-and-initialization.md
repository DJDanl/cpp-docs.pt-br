---
title: Otimizando persistência e inicialização
ms.date: 11/04/2016
helpviewer_keywords:
- MFC ActiveX controls [MFC], optimizing
- performance, ActiveX controls
- optimization, ActiveX controls
- optimizing performance, ActiveX controls
ms.assetid: e821e19e-b9eb-49ab-b719-0743420ba80b
ms.openlocfilehash: 294d9c43f5f767329c04932c574485d7dca704e9
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64342126"
---
# <a name="optimizing-persistence-and-initialization"></a>Otimizando persistência e inicialização

Por padrão, persistência e inicialização em um controle são manipuladas pelo `DoPropExchange` função de membro. Em um controle típico, essa função contém chamadas para vários **px _** funções (`PX_Color`, `PX_Font`e assim por diante), um para cada propriedade.

Essa abordagem tem a vantagem que uma única `DoPropExchange` implementação pode ser usada para inicialização, persistência em formato binário e persistência no formato chamado "recipiente" usado por alguns contêineres. Essa um função fornece todas as informações sobre as propriedades e seus valores padrão em um lugar conveniente.

No entanto, essa generalidade vem às custas de eficiência. O **px _** funções obtém sua flexibilidade por meio de implementações de várias camadas que são inerentemente menos eficiente do que mais diretas, mas menos flexíveis, abordagens. Além disso, se um controle de passar um valor padrão para um **px _** funcione, o que o valor padrão deve ser fornecida sempre, mesmo em situações quando o valor padrão não pode ser usado necessariamente. Se gerar o valor padrão é uma tarefa não trivial (por exemplo, quando o valor é obtido de uma propriedade de ambiente) e, em seguida, extra, trabalho desnecessário é feito em casos em que o valor padrão não é usado.

Você pode melhorar o desempenho de persistência binário do seu controle substituindo o seu controle `Serialize` função. A implementação padrão dessa função de membro faz uma chamada para seu `DoPropExchange` função. Por meio de substituição, você pode fornecer uma implementação mais direta para persistência de binária. Por exemplo, considere o seguinte `DoPropExchange` função:

[!code-cpp[NVC_MFC_AxOpt#1](../mfc/codesnippet/cpp/optimizing-persistence-and-initialization_1.cpp)]

Para melhorar o desempenho de persistência de binário desse controle, você pode substituir o `Serialize` funcionam da seguinte maneira:

[!code-cpp[NVC_MFC_AxOpt#2](../mfc/codesnippet/cpp/optimizing-persistence-and-initialization_2.cpp)]

O `dwVersion` variável local pode ser usado para detectar a versão do estado persistente do controle que está sendo carregada ou salvo. Você pode usar essa variável em vez de chamar [CPropExchange::GetVersion](../mfc/reference/cpropexchange-class.md#getversion).

Para salvar um espaço pequeno no formato persistente para um **BOOL** propriedade (e mantê-lo compatível com o formato produzido pela `PX_Bool`), você pode armazenar a propriedade como um **bytes**, da seguinte maneira:

[!code-cpp[NVC_MFC_AxOpt#3](../mfc/codesnippet/cpp/optimizing-persistence-and-initialization_3.cpp)]

Observe que, no caso de carga, uma variável temporária é usada e, em seguida, seu valor é atribuído, em vez de conversão *m_boolProp* para um **bytes** referência. A técnica de conversão resulta em apenas um byte de *m_boolProp* que está sendo modificada, deixando os bytes restantes não inicializados.

Para o mesmo controle, você pode otimizar a inicialização do controle por meio da substituição [COleControl::OnResetState](../mfc/reference/colecontrol-class.md#onresetstate) da seguinte maneira:

[!code-cpp[NVC_MFC_AxOpt#4](../mfc/codesnippet/cpp/optimizing-persistence-and-initialization_4.cpp)]

Embora `Serialize` e `OnResetState` ter sido substituído, o `DoPropExchange` função deve ser mantida intacta porque ele ainda é usado para persistência no formato de recipiente de propriedades. É importante manter todos os três dessas funções para garantir que o controle gerencia suas propriedades de forma consistente, independentemente da persistência usa o mecanismo de contêiner.

## <a name="see-also"></a>Consulte também

[Controles ActiveX MFC: otimização](../mfc/mfc-activex-controls-optimization.md)
