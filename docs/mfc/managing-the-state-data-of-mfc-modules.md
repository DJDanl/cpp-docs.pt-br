---
title: "Gerenciando os dados de estado dos m&#243;dulos MFC | Microsoft Docs"
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
  - "gerenciamento de dados [C++]"
  - "gerenciamento de dados [C++], Módulos MFC"
  - "interfaces exportadas e estado global [C++]"
  - "estado global [C++]"
  - "MFC [C++], gerenciando dados de estado"
  - "estado de módulo restaurado"
  - "estados de módulo, salvando e restaurando"
  - "vários módulos"
  - "pontos de entrada do procedimento de janela [C++]"
ms.assetid: 81889c11-0101-4a66-ab3c-f81cf199e1bb
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Gerenciando os dados de estado dos m&#243;dulos MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo discutir estado dados MFC módulo e como esse estado estar atualizar quando fluxo execução \(caminho código executada por um aplicativo durante execução\) inserir e deixar um módulo.  Os estados de módulo para o trabalho com macros de `AFX_MANAGE_STATE` e de `METHOD_PROLOGUE` são discutidos também.  
  
> [!NOTE]
>  O termo “módulo” refere\-se aqui para um programa executável, ou uma DLL \(ou conjunto de dlls\) que opera independentemente do restante do aplicativo, mas usa uma cópia compartilhada da DLL MFC.  Um controle ActiveX é um exemplo típico de um módulo.  
  
 Conforme mostrado na seguinte figura, o MFC tem dados de estado de cada módulo usado em um aplicativo.  Os exemplos desses dados incluem janelas instâncias de identificadores \(usadas para carregar recursos\), os ponteiros a `CWinApp` e os objetos atuais de `CWinThread` de um aplicativo OLE, contagens de referência do módulo, e uma variedade de mapas que mantêm as conexões entre os identificadores de objeto do windows e instâncias de objetos correspondentes MFC.  No entanto, quando um aplicativo usa vários módulos, os dados do estado de cada módulo não são aplicativo largura.  Em vez disso, cada módulo tem sua própria cópia privada de dados do estado de MFC.  
  
 ![Dados de estado do aplicativo de módulo único](../Image/vc387N1.gif "vc387N1")  
Dados de estado de um único módulo \(aplicativo\)  
  
 Os dados do estado de um módulo são contidos em uma estrutura e estão sempre disponíveis por meio de um ponteiro a essa estrutura.  Quando o fluxo de execução inserir um módulo específico, conforme mostrado na figura a seguir, que o estado do módulo deve ser “atual” ou “efetivo estado”.  Consequentemente, cada objeto de thread tem um ponteiro para a estrutura efetivo do estado desse aplicativo.  Manter esse ponteiro atualizado em todas as vezes é vital a gerenciar o estado global do aplicativo e a manter a integridade do estado de cada módulo.  O gerenciamento incorreto de estado global pode resultar em comportamento imprevisível de aplicativo.  
  
 ![Vários dados do estado de módulos](../mfc/media/vc387n2.png "vc387N2")  
Dados de estado de vários módulos  
  
 Ou seja cada módulo é responsável por corretamente alternar entre estados de módulo de qualquer dos pontos de entrada.  “Um ponto de entrada” é qualquer local onde o fluxo de execução pode digitar o código do módulo.  Os pontos de entrada incluem:  
  
-   [Funções exportadas em uma DLL](../mfc/exported-dll-function-entry-points.md)  
  
-   [Funções de membro de interfaces COM](../mfc/com-interface-entry-points.md)  
  
-   [Procedimentos de janela](../Topic/Window%20Procedure%20Entry%20Points.md)  
  
## Consulte também  
 [Tópicos MFC gerais](../mfc/general-mfc-topics.md)