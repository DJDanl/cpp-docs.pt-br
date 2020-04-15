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
ms.openlocfilehash: c8e79f54ed586201a7d82327662643a9a241b8f4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81357276"
---
# <a name="managing-the-state-data-of-mfc-modules"></a>Gerenciando os dados de estado dos módulos MFC

Este artigo discute os dados estaduais dos módulos MFC e como este estado é atualizado quando o fluxo de execução (o código de caminho leva através de um aplicativo ao executar) entra e sai de um módulo. O módulo de comutação dos estados com as macros AFX_MANAGE_STATE e METHOD_PROLOGUE também é discutido.

> [!NOTE]
> O termo "módulo" aqui refere-se a um programa executável, ou a um DLL (ou conjunto de DLLs) que operam independentemente do resto do aplicativo, mas usa uma cópia compartilhada do DLL MFC. Um controle ActiveX é um exemplo típico de um módulo.

Como mostrado na figura a seguir, o MFC tem dados de estado para cada módulo utilizado em um aplicativo. Exemplos desses dados incluem alças de instância do Windows (usadas `CWinApp` `CWinThread` para carregar recursos), ponteiros para a corrente e objetos de um aplicativo, contagens de referência de módulo OLE e uma variedade de mapas que mantêm as conexões entre as alças de objeto do Windows e as instâncias correspondentes de objetos MFC. No entanto, quando um aplicativo usa vários módulos, os dados de estado de cada módulo não são de largura de aplicação. Em vez disso, cada módulo tem sua própria cópia privada dos dados estaduais do MFC.

![Dados estaduais de um único módulo &#40;&#41;](../mfc/media/vc387n1.gif "Dados de estado de um único módulo &#40;aplicativo&#41;") <br/>
Dados estaduais de um módulo único (aplicativo)

Os dados de estado de um módulo estão contidos em uma estrutura e estão sempre disponíveis através de um ponteiro para essa estrutura. Quando o fluxo de execução entra em um módulo específico, como mostrado na figura a seguir, o estado desse módulo deve ser o estado "atual" ou "efetivo". Portanto, cada objeto de segmento tem um ponteiro para a estrutura de estado eficaz dessa aplicação. Manter este ponteiro sempre atualizado é vital para gerenciar o estado global do aplicativo e manter a integridade do estado de cada módulo. A gestão incorreta do estado global pode levar a um comportamento imprevisível de aplicação.

![Dados estaduais de vários módulos](../mfc/media/vc387n2.gif "Dados estaduais de vários módulos") <br/>
Dados estaduais de módulos múltiplos

Em outras palavras, cada módulo é responsável por alternar corretamente entre estados do módulo em todos os seus pontos de entrada. Um "ponto de entrada" é qualquer lugar onde o fluxo de execução pode inserir o código do módulo. Os pontos de entrada incluem:

- [Funções exportadas em uma DLL](../mfc/exported-dll-function-entry-points.md)

- [Funções de membro das interfaces COM](../mfc/com-interface-entry-points.md)

- [Procedimentos de janela](../mfc/window-procedure-entry-points.md)

## <a name="see-also"></a>Confira também

[Tópicos MFC gerais](../mfc/general-mfc-topics.md)
