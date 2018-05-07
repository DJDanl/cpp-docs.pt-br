---
title: Gerenciando os dados de estado dos módulos MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- global state [MFC]
- data management [MFC], MFC modules
- window procedure entry points [MFC]
- exported interfaces and global state [MFC]
- module states [MFC], saving and restoring
- data management [MFC]
- MFC, managing state data
- multiple modules [MFC]
- module state restored [MFC]
ms.assetid: 81889c11-0101-4a66-ab3c-f81cf199e1bb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9d87b2a601e6e25d61de6ca6ad639ac6a62861ac
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="managing-the-state-data-of-mfc-modules"></a>Gerenciando os dados de estado dos módulos MFC
Este artigo aborda os dados de estado dos módulos MFC e como esse estado é atualizado quando o fluxo de execução (o código de caminho leva através de um aplicativo ao executar) entra e sai de um módulo. Alternando estados de módulo com o `AFX_MANAGE_STATE` e `METHOD_PROLOGUE` macros também é abordado.  
  
> [!NOTE]
>  O termo "módulo" aqui se refere a um programa executável, ou para uma DLL (ou conjunto de DLLs) que operam independentemente do restante do aplicativo, mas usa uma cópia compartilhada da DLL do MFC. Um controle ActiveX é um exemplo típico de um módulo.  
  
 Conforme mostrado na figura a seguir, o MFC tem dados de estado para cada módulo usado em um aplicativo. Esses dados são exemplos de identificadores de instância do Windows (usados para carregar os recursos), ponteiros para atual `CWinApp` e `CWinThread` objetos de um aplicativo, contagens de referência de módulo OLE e uma variedade de mapas que mantêm as conexões entre Windows do objeto correspondentes instâncias de objetos MFC e identificadores. No entanto, quando um aplicativo usa vários módulos, os dados de estado de cada módulo não são aplicativos ampla. Em vez disso, cada módulo tem sua própria cópia dos dados do estado do MFC.  
  
 ![Dados de um único módulo de estado &#40;aplicativo&#41;](../mfc/media/vc387n1.gif "vc387n1")  
Dados de estado de um único módulo (aplicativo)  
  
 Dados de estado do módulo estão contidos em uma estrutura e estão sempre disponíveis por meio de um ponteiro para a estrutura. Quando o fluxo de execução entra em um módulo específico, conforme mostrado na figura a seguir, o estado do módulo deve ser o estado "atual" ou "efetivo". Portanto, cada objeto de thread tem um ponteiro para a estrutura de estado efetivo desse aplicativo. Manter esse ponteiro atualizado em todos os tempos de é essencial para gerenciar o estado do aplicativo global e manter a integridade do estado de cada módulo. Gerenciamento incorreto do estado global pode resultar em comportamento imprevisível do aplicativo.  
  
 ![Dados de vários módulos de estado](../mfc/media/vc387n2.gif "vc387n2")  
Dados de estado de vários módulos  
  
 Em outras palavras, cada módulo é responsável por corretamente alternar entre os estados de módulo em todos os seus pontos de entrada. Um "ponto de entrada" é qualquer lugar em que o fluxo de execução pode inserir o código do módulo. Pontos de entrada incluem:  
  
-   [Funções exportadas em uma DLL](../mfc/exported-dll-function-entry-points.md)  
  
-   [Funções de membro de interfaces COM](../mfc/com-interface-entry-points.md)  
  
-   [Procedimentos de janela](../mfc/window-procedure-entry-points.md)  
  
## <a name="see-also"></a>Consulte também  
 [Tópicos gerais do MFC](../mfc/general-mfc-topics.md)

