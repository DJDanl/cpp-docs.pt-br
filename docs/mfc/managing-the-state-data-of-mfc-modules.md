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
ms.openlocfilehash: 64888b8ab53ebd80f328e1efe79df6256f30f9b6
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84622579"
---
# <a name="managing-the-state-data-of-mfc-modules"></a>Gerenciando os dados de estado dos módulos MFC

Este artigo discute os dados de estado dos módulos do MFC e como esse estado é atualizado quando o fluxo de execução (o código do caminho passa por um aplicativo durante a execução) entra e sai de um módulo. Também é discutido o switching de Estados de módulo com as macros AFX_MANAGE_STATE e METHOD_PROLOGUE.

> [!NOTE]
> O termo "módulo" refere-se a um programa executável ou a uma DLL (ou conjunto de DLLs) que opera independentemente do restante do aplicativo, mas usa uma cópia compartilhada da DLL do MFC. Um controle ActiveX é um exemplo típico de um módulo.

Conforme mostrado na figura a seguir, o MFC tem dados de estado para cada módulo usado em um aplicativo. Exemplos desses dados incluem identificadores de instância do Windows (usados para carregar recursos), ponteiros para os `CWinApp` objetos atuais e `CWinThread` de um aplicativo, contagens de referência de módulo OLE e uma variedade de mapas que mantêm as conexões entre identificadores de objeto do Windows e instâncias correspondentes de objetos MFC. No entanto, quando um aplicativo usa vários módulos, os dados de estado de cada módulo não têm todo o aplicativo. Em vez disso, cada módulo tem sua própria cópia privada dos dados de estado do MFC.

![Dados de estado de um único módulo &#40;aplicativo&#41;](../mfc/media/vc387n1.gif "Dados de estado de um único módulo &#40;aplicativo&#41;") <br/>
Dados de estado de um único módulo (aplicativo)

Os dados de estado de um módulo estão contidos em uma estrutura e estão sempre disponíveis por meio de um ponteiro para essa estrutura. Quando o fluxo de execução entra em um módulo específico, conforme mostrado na figura a seguir, o estado desse módulo deve ser o estado "atual" ou "efetivo". Portanto, cada objeto de thread tem um ponteiro para a estrutura de estado efetivo desse aplicativo. Manter esse ponteiro atualizado em todos os momentos é vital para gerenciar o estado global do aplicativo e manter a integridade do estado de cada módulo. O gerenciamento incorreto do estado global pode levar a um comportamento imprevisível do aplicativo.

![Dados de estado de vários módulos](../mfc/media/vc387n2.gif "Dados de estado de vários módulos") <br/>
Dados de estado de vários módulos

Em outras palavras, cada módulo é responsável por alternar corretamente entre os Estados de módulo em todos os seus pontos de entrada. Um "ponto de entrada" é qualquer lugar em que o fluxo de execução pode inserir o código do módulo. Os pontos de entrada incluem:

- [Funções exportadas em uma DLL](exported-dll-function-entry-points.md)

- [Funções de membro de interfaces COM](com-interface-entry-points.md)

- [Procedimentos de janela](window-procedure-entry-points.md)

## <a name="see-also"></a>Consulte também

[Tópicos MFC gerais](general-mfc-topics.md)
