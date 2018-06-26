---
title: Otimizando persistência e inicialização | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC ActiveX controls [MFC], optimizing
- performance, ActiveX controls
- optimization, ActiveX controls
- optimizing performance, ActiveX controls
ms.assetid: e821e19e-b9eb-49ab-b719-0743420ba80b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d03966cb61e1ccab3f8f3886638efdf95a534a73
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36930307"
---
# <a name="optimizing-persistence-and-initialization"></a>Otimizando persistência e inicialização
Por padrão, persistência e inicialização em um controle são manipuladas pelo `DoPropExchange` função de membro. Em um controle comum, essa função contém chamadas para vários **px _** funções (`PX_Color`, `PX_Font`e assim por diante), uma para cada propriedade.  
  
 Essa abordagem tem a vantagem de que um único `DoPropExchange` implementação pode ser usada para a inicialização, persistência em formato binário e persistência no formato chamados "-recipiente de propriedades" usado por alguns contêineres. Essa um função fornece todas as informações sobre as propriedades e seus valores padrão em um local conveniente.  
  
 No entanto, essa generalidade vem às custas de eficiência. O **px _** funções obtém sua flexibilidade por meio de implementações de várias camadas que são inerentemente menos eficiente do que mais diretas, mas é menos flexíveis, abordagens. Além disso, se um controle passa um valor padrão para um **px _** de função, que o valor padrão deve ser fornecido sempre, mesmo em situações quando o valor padrão não necessariamente pode ser usado. Se gerar o valor padrão é uma tarefa não trivial (por exemplo, quando o valor é obtido de uma propriedade de ambiente), em seguida, extra, trabalho desnecessário é feito em casos onde o valor padrão não é usado.  
  
 Você pode melhorar o desempenho de persistência binário do controle por meio da substituição do controle `Serialize` função. A implementação padrão desta função de membro faz uma chamada para seu `DoPropExchange` função. Por meio de substituição, você pode fornecer uma implementação mais direta para a persistência de binária. Por exemplo, considere o seguinte `DoPropExchange` função:  
  
 [!code-cpp[NVC_MFC_AxOpt#1](../mfc/codesnippet/cpp/optimizing-persistence-and-initialization_1.cpp)]  
  
 Para melhorar o desempenho de persistência de binários deste controle, você pode substituir o `Serialize` funciona da seguinte maneira:  
  
 [!code-cpp[NVC_MFC_AxOpt#2](../mfc/codesnippet/cpp/optimizing-persistence-and-initialization_2.cpp)]  
  
 O `dwVersion` variável local pode ser usada para detectar a versão do estado persistente do controle que está sendo carregada ou salvo. Você pode usar essa variável em vez de chamar [CPropExchange::GetVersion](../mfc/reference/cpropexchange-class.md#getversion).  
  
 Para salvar um pouco de espaço no formato persistente para um **BOOL** propriedade (e mantê-lo compatível com o formato produzido por `PX_Bool`), você pode armazenar a propriedade como um **bytes**, da seguinte maneira:  
  
 [!code-cpp[NVC_MFC_AxOpt#3](../mfc/codesnippet/cpp/optimizing-persistence-and-initialization_3.cpp)]  
  
 Observe que, no caso de carga, uma variável temporária é usada e, em seguida, seu valor é atribuído, em vez de conversão *m_boolProp* para um **bytes** referência. A técnica de conversão resultaria em um byte de *m_boolProp* que está sendo modificado, deixando os bytes restantes não inicializados.  
  
 Para o mesmo controle, você pode otimizar a inicialização do controle, substituindo [COleControl::OnResetState](../mfc/reference/colecontrol-class.md#onresetstate) da seguinte maneira:  
  
 [!code-cpp[NVC_MFC_AxOpt#4](../mfc/codesnippet/cpp/optimizing-persistence-and-initialization_4.cpp)]  
  
 Embora `Serialize` e `OnResetState` foi substituída, o `DoPropExchange` função deve ser mantida intacta porque ele ainda é usado para persistência no formato de recipiente de propriedades. É importante manter todos os três dessas funções para garantir que o controle gerencia suas propriedades de forma consistente, independentemente de qual persistência usa o mecanismo do contêiner.  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC: otimização](../mfc/mfc-activex-controls-optimization.md)

