---
title: 'Gerenciamento de memória: Alocação de heap'
ms.date: 11/04/2016
helpviewer_keywords:
- memory [MFC], detecting leaks
- delete operator [MFC], using with debug MFC
- heap allocation [MFC], described
- memory allocation [MFC], heap memory
- memory leaks [MFC], detecting
- new operator [MFC], using with debug MFC
- heap allocation [MFC]
- detecting memory leaks [MFC]
ms.assetid: a5d949c6-1b79-476e-9c66-513a558203d9
ms.openlocfilehash: 93eee5cbfe1cd49042a9080f06657e751640de69
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62219471"
---
# <a name="memory-management-heap-allocation"></a>Gerenciamento de memória: Alocação de heap

O heap é reservado para as necessidades de alocação de memória do programa. É uma área além do código do programa e a pilha. Programas em C típicos usam as funções **malloc** e **livre** para alocar e desalocar a memória de heap. A versão de depuração do MFC fornece versões modificadas dos operadores C++ internos **novos** e **excluir** aloque e desaloque os objetos na memória de heap.

Quando você usa **novos** e **excluir** em vez de **malloc** e **livre**, você é capaz de aproveitar a biblioteca de classes gerenciamento de memória depuração aprimoramentos, que podem ser úteis na detecção de vazamentos de memória. Quando você compila seu programa com a versão de lançamento do MFC, as versões padrão do **novos** e **excluir** operadores fornecem uma maneira eficiente para alocar e desalocar a memória (a versão de lançamento do MFC não fornece versões modificadas desses operadores).

Observe que o tamanho total dos objetos alocados no heap é limitado apenas pela memória disponível de virtual do seu sistema.

## <a name="see-also"></a>Consulte também

[Gerenciamento de memória](../mfc/memory-management.md)
