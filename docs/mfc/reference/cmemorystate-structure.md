---
title: "Estrutura de CMemoryState | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CMemoryState"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura de CMemoryState"
  - "detectando vazamentos de memória"
  - "vazamentos de memória, detectar"
ms.assetid: 229d9de7-a6f3-4cc6-805b-5a9d9b1bfe1d
caps.latest.revision: 19
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura de CMemoryState
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece uma maneira conveniente para detectar vazamentos de memória em seu programa.  
  
## Sintaxe  
  
```  
struct CMemoryState  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMemoryState::CMemoryState](../Topic/CMemoryState::CMemoryState.md)|Constrói a classe como a estrutura pontos de verificação de essa memória dos controles.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMemoryState::Checkpoint](../Topic/CMemoryState::Checkpoint.md)|Obter um instantâneo \(ponto de verificação\) de estado atual de memória.|  
|[CMemoryState::Difference](../Topic/CMemoryState::Difference.md)|Calcula a diferença entre dois objetos do tipo `CMemoryState`.|  
|[CMemoryState::DumpAllObjectsSince](../Topic/CMemoryState::DumpAllObjectsSince.md)|Despeja um resumo de todos os objetos atualmente atribuído como um ponto de verificação anterior.|  
|[CMemoryState::DumpStatistics](../Topic/CMemoryState::DumpStatistics.md)|Estatísticas de alocação de memória das cópias para um objeto de `CMemoryState` .|  
  
## Comentários  
 `CMemoryState` é uma estrutura e não tem uma classe base.  
  
 Um “vazamento de memória” ocorre quando a memória para um objeto é atribuída na heap mas não desalocada quando ele não for necessário.  Como vazamentos de memória eventualmente podem levar a erros de para fora de memória.  Há várias maneiras para atribuir e desalocar a memória do seu programa:  
  
-   Usando a família de `malloc`\/**free** funções de biblioteca em tempo de execução.  
  
-   Usando funções de gerenciamento de memória da API do windows, **LocalAlloc**\/**LocalFree** e **GlobalAlloc**\/**GlobalFree**.  
  
-   Usando o C\+\+ **new** e operadores de **delete** .  
  
 Ajuda de diagnóstico de `CMemoryState` somente detecta os vazamentos de memória causados quando a memória alocada usando o operador de **new** não é desalocada usando **delete**.  Outros dois grupos de funções de gerenciamento de memória são para programas de non\-C\+\+, e misturar com os **new** e **delete** no mesmo programa não é recomendada.  Uma macro adicional, `DEBUG_NEW`, é fornecido para substituir o operador de **new** quando você precisa o rastreamento de arquivo e número de linhas das alocações de memória.  `DEBUG_NEW` é usado sempre que você normalmente seria usar o operador de **new** .  
  
 Como com outros diagnóstico, diagnósticos de `CMemoryState` só estão disponíveis nas versões de depuração do seu programa.  Uma versão de depuração deve ter a constante de **\_DEBUG** definida.  
  
 Se você suspeitar seu programa tiver um vazamento de memória, você pode usar `Checkpoint`, **Difference**, e funções de `DumpStatistics` para descobrir a diferença entre o estado de memória \(objetos\) atribuídos em dois diferentes pontos na execução do programa.  Essa informação pode ser útil em determinar se uma função é limpando todos os objetos que atribui.  
  
 Se apenas saber onde o desequilíbrio na alocação e em desalocação ocorre não fornece informação suficiente, você pode usar a função de `DumpAllObjectsSince` para despejar todos os objetos atribuídos desde que a chamada anterior a `Checkpoint`.  Este despejo mostra a ordem de alocação, o arquivo de origem e a linha onde o objeto foi atribuído \(se você estiver usando `DEBUG_NEW` para a alocação\), e a derivação do objeto, seu endereço, e seu tamanho.  `DumpAllObjectsSince` também chama a função de `Dump` de cada objeto para fornecer informações sobre seu estado atual.  
  
 Para obter mais informações sobre como usar `CMemoryState` e outros diagnóstico, consulte [Aplicativos MFC de depuração](../Topic/MFC%20Debugging%20Techniques.md).  
  
> [!NOTE]
>  Declarações de objetos do tipo `CMemoryState` e das chamadas a funções de membro devem ser suportados pelas políticas de `#if defined(_DEBUG)/#endif`.  Isso faz com que diagnósticos de memória somente a serem incluídos em compilações de depuração do seu programa.  
  
## Hierarquia de herança  
 `CMemoryState`  
  
## Requisitos  
 **Cabeçalho:** afx.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)