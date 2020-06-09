---
title: 'Gerenciamento de memória: alocação do heap'
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
ms.openlocfilehash: 1f0b07a0a3439faba71078af1e2d7d1559a42b41
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626290"
---
# <a name="memory-management-heap-allocation"></a>Gerenciamento de memória: alocação do heap

O heap é reservado para as necessidades de alocação de memória do programa. É uma área além do código do programa e da pilha. Programas C típicos usam as funções **malloc** e **Free** para alocar e desalocar a memória heap. A versão de depuração do MFC fornece versões modificadas dos operadores internos do C++ **New** e **delete** para alocar e desalocar objetos na memória de heap.

Ao usar **New** e **delete** em vez de **malloc** e **Free**, você poderá aproveitar os aprimoramentos de depuração de gerenciamento de memória da biblioteca de classes, o que pode ser útil na detecção de vazamentos de memória. Quando você cria seu programa com a versão de lançamento do MFC, as versões padrão dos operadores **novo** e **excluir** fornecem uma maneira eficiente de alocar e desalocar memória (a versão de lançamento do MFC não fornece versões modificadas desses operadores).

Observe que o tamanho total dos objetos alocados no heap é limitado apenas pela memória virtual disponível do sistema.

## <a name="see-also"></a>Consulte também

[Gerenciamento de memória](memory-management.md)
