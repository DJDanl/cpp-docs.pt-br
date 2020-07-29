---
title: 'Gerenciamento de memória: alocação do quadro'
ms.date: 11/04/2016
helpviewer_keywords:
- memory leaks [MFC], frame allocation
- memory [MFC], detecting leaks
- memory [MFC], reclaiming
- memory allocation [MFC], frames
- frame variables [MFC], automatic deletion of
- scope [MFC], frame variables
- heap allocation [MFC], vs. frame allocation
- variables [MFC], frame variables
- memory leaks [MFC], detecting
- memory, releasing [MFC]
- stack frames [MFC]
- memory leaks [MFC], allocating objects on the frame
- detecting memory leaks [MFC]
- frame allocation [MFC]
- frame variables [MFC]
ms.assetid: 945a211a-6f4f-4679-bb6a-b0f2a0d4a6c1
ms.openlocfilehash: cb66a0c0aea16f7e6831b6a1aff1a125df355210
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225040"
---
# <a name="memory-management-frame-allocation"></a>Gerenciamento de memória: alocação do quadro

A alocação no quadro leva seu nome do "quadro de pilhas" que é configurado sempre que uma função é chamada. O registro de ativação é uma área de memória que mantém temporariamente os argumentos para a função, bem como qualquer variável que esteja definida como local para a função. Variáveis de quadro geralmente são chamadas de variáveis "automáticas" porque o compilador automaticamente aloca o espaço para elas.

Há duas características principais das alocações de quadros. Primeiro, quando você define uma variável local, espaço suficiente é alocado no quadro de pilha para manter a variável inteira, mesmo se for uma grande matriz ou estrutura de dados. Segundo, as variáveis de quadro são excluídas automaticamente quando saem do escopo:

[!code-cpp[NVC_MFC_Utilities#10](codesnippet/cpp/memory-management-frame-allocation_1.cpp)]

Para variáveis de função locais, essa transição de escopo ocorre quando a função é encerrada, mas o escopo de uma variável de quadro pode ser menor do que uma função se chaves aninhadas forem usadas. Essa exclusão automática de variáveis de quadro é muito importante. No caso de tipos primitivos simples (como **`int`** ou **byte**), matrizes ou estruturas de dados, a exclusão automática simplesmente recupera a memória usada pela variável. Como a variável saiu do escopo, ela não pode ser acessada mesmo assim. No entanto, no caso de objetos C++, o processo de exclusão automática é um pouco mais complicado.

Quando um objeto é definido como uma variável de quadro, seu construtor é invocado automaticamente no ponto em que a definição é encontrada. Quando o objeto sai do escopo, seu destruidor é invocado automaticamente antes que a memória do objeto seja recuperada. Essa construção e destruição automáticas podem ser muito úteis, mas você deve estar atento às chamadas automáticas, especialmente ao destruidor.

A principal vantagem de alocar objetos no quadro é que eles são excluídos automaticamente. Ao alocar seus objetos no quadro, você não precisa se preocupar com objetos esquecidos causando vazamentos de memória. (Para obter detalhes sobre vazamentos de memória, consulte o artigo [detectando vazamentos de memória no MFC](/previous-versions/visualstudio/visual-studio-2010/c99kz476(v=vs.100)).) Uma desvantagem da alocação de quadros é que as variáveis de quadro não podem ser usadas fora do seu escopo. Outro fator na escolha de alocação de quadro versus alocação de heap é que para grandes estruturas e objetos, geralmente é melhor usar o heap em vez da pilha para armazenamento, já que o espaço de pilha é geralmente limitado.

## <a name="see-also"></a>Confira também

[Gerenciamento de memória](memory-management.md)
