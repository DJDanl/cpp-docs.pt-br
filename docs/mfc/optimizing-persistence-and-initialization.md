---
title: "Otimizando persist&#234;ncia e inicializa&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Controles ActiveX MFC, otimizando"
  - "otimização, Controles ActiveX"
  - "otimizando o desempenho, Controles ActiveX"
  - "desempenho, Controles ActiveX"
ms.assetid: e821e19e-b9eb-49ab-b719-0743420ba80b
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Otimizando persist&#234;ncia e inicializa&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Por padrão, a persistência e a inicialização em um controle são tratadas pela função de membro de `DoPropExchange` .  Em um controle típico, essa função contém as chamadas para várias funções de **PX\_** \(`PX_Color`, `PX_Font`, e assim por diante\), um para cada propriedade.  
  
 Esse método tem a vantagem de que uma única implementação de `DoPropExchange` pode ser usada para inicialização, para a persistência em formato binário, e para a persistência no formato também chamado de “\-” catchall usado por qualquer contêiner.  Essa função fornece todas as informações sobre as propriedades e seus valores padrão em um local conveniente.  
  
 No entanto, essa generalidade vem às custas da eficiência.  As funções de **PX\_** obtém a flexibilidade com as implementações multicamadas que são inerentemente menos eficientes do que mais diretos, mas as abordagens menos flexíveis.  Além disso, se um controle passa um valor padrão a uma função de **PX\_** , esse valor padrão deve ser fornecido o tempo todo, mesmo em situações quando o valor padrão não necessariamente ser usado.  Se gerar o valor padrão é uma tarefa nontrivial \(por exemplo, quando o valor é obtido de uma propriedade de ambiente\), o acréscimo, trabalho desnecessário é feita nos casos em que o valor padrão não é usado.  
  
 Você pode melhorar o desempenho binário de persistência do controle substituindo a função de `Serialize` do controle.  A implementação padrão dessa função de membro faz uma chamada à função de `DoPropExchange` .  Substituindo a, você pode fornecer uma implementação mais direta para a persistência binário.  Por exemplo, considere esta função de `DoPropExchange` :  
  
 [!code-cpp[NVC_MFC_AxOpt#1](../mfc/codesnippet/CPP/optimizing-persistence-and-initialization_1.cpp)]  
  
 Para melhorar o desempenho de persistência binária deste controle, você pode substituir a função de `Serialize` como segue:  
  
 [!code-cpp[NVC_MFC_AxOpt#2](../mfc/codesnippet/CPP/optimizing-persistence-and-initialization_2.cpp)]  
  
 A variável local de `dwVersion` pode ser usado para detectar a versão do estado persistente de controle que está sendo carregada ou salvo.  Você pode usar essa variável em vez de chamar [CPropExchange::GetVersion](../Topic/CPropExchange::GetVersion.md).  
  
 Para salvar pouco espaço no formato persistente para uma propriedade de **BOOL** \(e para manter compatíveis com o formato gerado por `PX_Bool`\), você pode armazenar a propriedade como **BYTE**, como segue:  
  
 [!code-cpp[NVC_MFC_AxOpt#3](../mfc/codesnippet/CPP/optimizing-persistence-and-initialization_3.cpp)]  
  
 Observe que nos exemplos de carga, uma variável temporário é usado e seu valor é então atribuído, em vez de convertendo `m_boolProp` a uma referência de **BYTE** .  A técnica de conversão resultaria em apenas um byte de `m_boolProp` que está sendo alterado, deixando os bytes restantes não inicializado.  
  
 Para o mesmo controle, você pode otimizar a inicialização de controle substituindo [COleControl::OnResetState](../Topic/COleControl::OnResetState.md) como segue:  
  
 [!code-cpp[NVC_MFC_AxOpt#4](../mfc/codesnippet/CPP/optimizing-persistence-and-initialization_4.cpp)]  
  
 Embora `Serialize` e `OnResetState` sejam substituídos, a função de `DoPropExchange` deve ser mantida intacto porque ainda é usada para a persistência no formato do com conjunto.  É importante manter todas essas três funções para assegurar que o controle gerencia suas propriedades forma consistente, independentemente do mecanismo de persistência o contêiner usa.  
  
## Consulte também  
 [Controles ActiveX MFC: otimização](../mfc/mfc-activex-controls-optimization.md)