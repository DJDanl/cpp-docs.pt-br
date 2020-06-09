---
title: Otimizando persistência e inicialização
ms.date: 11/04/2016
helpviewer_keywords:
- MFC ActiveX controls [MFC], optimizing
- performance, ActiveX controls
- optimization, ActiveX controls
- optimizing performance, ActiveX controls
ms.assetid: e821e19e-b9eb-49ab-b719-0743420ba80b
ms.openlocfilehash: 57b98f7e2e4f9e23175b8b01c2e37ff49c499949
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84623993"
---
# <a name="optimizing-persistence-and-initialization"></a>Otimizando persistência e inicialização

Por padrão, a persistência e a inicialização em um controle são manipuladas pela `DoPropExchange` função de membro. Em um controle típico, essa função contém chamadas para várias funções de **PX_** ( `PX_Color` , `PX_Font` e assim por diante), uma para cada propriedade.

Essa abordagem tem a vantagem de que uma única `DoPropExchange` implementação pode ser usada para a inicialização, para persistência em formato binário e para persistência no formato "recipiente de propriedades" usado por alguns contêineres. Essa função fornece todas as informações sobre as propriedades e seus valores padrão em um único local conveniente.

No entanto, essa generalidade vem às custas da eficiência. As funções de **PX_** têm sua flexibilidade por meio de implementações em várias camadas que são inerentemente menos eficientes do que as abordagens mais diretas, mas menos flexíveis. Além disso, se um controle passar um valor padrão para uma função **PX_** , esse valor padrão deverá ser fornecido a cada vez, mesmo em situações em que o valor padrão não seja necessariamente usado. Se a geração do valor padrão for uma tarefa não trivial (por exemplo, quando o valor é obtido de uma propriedade de ambiente), um trabalho extra e desnecessário é feito nos casos em que o valor padrão não é usado.

Você pode melhorar o desempenho de persistência binária do controle substituindo a função do controle `Serialize` . A implementação padrão dessa função de membro faz uma chamada para sua `DoPropExchange` função. Ao substituí-lo, você pode fornecer uma implementação mais direta para persistência binária. Por exemplo, considere esta `DoPropExchange` função:

[!code-cpp[NVC_MFC_AxOpt#1](codesnippet/cpp/optimizing-persistence-and-initialization_1.cpp)]

Para melhorar o desempenho da persistência binária desse controle, você pode substituir a `Serialize` função da seguinte maneira:

[!code-cpp[NVC_MFC_AxOpt#2](codesnippet/cpp/optimizing-persistence-and-initialization_2.cpp)]

A `dwVersion` variável local pode ser usada para detectar a versão do estado persistente do controle que está sendo carregado ou salvo. Você pode usar essa variável em vez de chamar [CPropExchange:: GetVersion](reference/cpropexchange-class.md#getversion).

Para economizar um pouco de espaço no formato persistente para uma propriedade **bool** (e para mantê-lo compatível com o formato produzido por `PX_Bool` ), você pode armazenar a propriedade como um **byte**, da seguinte maneira:

[!code-cpp[NVC_MFC_AxOpt#3](codesnippet/cpp/optimizing-persistence-and-initialization_3.cpp)]

Observe que no caso de carga, uma variável temporária é usada e, em seguida, seu valor é atribuído, em vez de converter *m_boolProp* em uma referência de **byte** . A técnica de conversão resultaria em apenas um byte de *m_boolProp* sendo modificado, deixando os bytes restantes não inicializados.

Para o mesmo controle, você pode otimizar a inicialização do controle substituindo [COleControl:: OnResetState](reference/colecontrol-class.md#onresetstate) da seguinte maneira:

[!code-cpp[NVC_MFC_AxOpt#4](codesnippet/cpp/optimizing-persistence-and-initialization_4.cpp)]

Embora `Serialize` e `OnResetState` tenham sido substituídos, a `DoPropExchange` função deve ser mantida intacta porque ainda é usada para persistência no formato de recipiente de propriedades. É importante manter todas as três funções para garantir que o controle gerencie suas propriedades de forma consistente, independentemente do mecanismo de persistência usado pelo contêiner.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC: otimização](mfc-activex-controls-optimization.md)
