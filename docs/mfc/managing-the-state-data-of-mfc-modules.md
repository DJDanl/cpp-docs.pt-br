---
title: Gerenciando os dados de estado dos módulos MFC
ms.date: 11/19/2018
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
ms.openlocfilehash: 0cdb368dc70b73ba70b3721fecdaf47de36686d5
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57293791"
---
# <a name="managing-the-state-data-of-mfc-modules"></a>Gerenciando os dados de estado dos módulos MFC

Este artigo discute os dados de estado dos módulos MFC e como esse estado é atualizado quando o fluxo de execução (o código do caminho usa por meio de um aplicativo ao executar) entra e sai de um módulo. Alternando os estados de módulo com as macros AFX_MANAGE_STATE e METHOD_PROLOGUE também é discutido.

> [!NOTE]
>  O termo "módulo" aqui se refere a um programa executável, ou a uma DLL (ou conjunto de DLLs) que operam independentemente do restante do aplicativo, mas usa uma cópia compartilhada da DLL da MFC. Um controle ActiveX é um exemplo típico de um módulo.

Conforme mostrado na figura a seguir, o MFC tem dados de estado para cada módulo usado em um aplicativo. Esses dados são exemplos de identificadores de instância do Windows (usados para carregar os recursos), ponteiros para o atual `CWinApp` e `CWinThread` objetos de um aplicativo, contagens de referência de módulo OLE e uma variedade de mapas que mantêm as conexões entre O objeto Windows identificadores e instâncias correspondentes de objetos MFC. No entanto, quando um aplicativo usa vários módulos, os dados de estado de cada módulo não serão aplicativo ampla. Em vez disso, cada módulo tem sua própria cópia dos dados do estado do MFC.

![Dados de um único módulo de estado &#40;aplicativo&#41;](../mfc/media/vc387n1.gif "dados de um único módulo de estado &#40;aplicativo&#41;") <br/>
Dados de estado de um único módulo (aplicativo)

Dados de estado de um módulo estão contidos em uma estrutura e sempre estão disponíveis por meio de um ponteiro para essa estrutura. Quando o fluxo de execução entra em um módulo específico, conforme mostrado na figura a seguir, o estado do módulo deve ser o estado "atual" ou "efetivo". Portanto, cada objeto de thread tem um ponteiro para a estrutura de estado efetivo desse aplicativo. Manter esse ponteiro atualizado em todos os tempos de é vital para gerenciar o estado do aplicativo global e manter a integridade de estado do cada módulo. Gerenciamento incorreto do estado global pode resultar em comportamento imprevisível do aplicativo.

![Dados de vários módulos de estado](../mfc/media/vc387n2.gif "dados de vários módulos de estado") <br/>
Dados de estado dos vários módulos

Em outras palavras, cada módulo é responsável por corretamente alternando entre os estados de módulo em todos os seus pontos de entrada. Um "ponto de entrada" é qualquer lugar em que o fluxo de execução pode inserir o código do módulo. Pontos de entrada incluem:

- [Funções exportadas em uma DLL](../mfc/exported-dll-function-entry-points.md)

- [Funções de membro de interfaces COM](../mfc/com-interface-entry-points.md)

- [Procedimentos de janela](../mfc/window-procedure-entry-points.md)

## <a name="see-also"></a>Consulte também

[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)
