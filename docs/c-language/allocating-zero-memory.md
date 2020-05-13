---
title: Alocando memória igual a zero
ms.date: 11/04/2016
helpviewer_keywords:
- memory allocation, zero memory
- zero memory
ms.assetid: 768f2ab9-83a1-4887-8eb5-c094c18489a8
ms.openlocfilehash: 40f21c0fa9a2a4068cb2592c49ccefed82176a35
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62313487"
---
# <a name="allocating-zero-memory"></a>Alocando memória igual a zero

**4.10.3 ANSI** O comportamento da função `calloc`, `malloc`ou `realloc` se o tamanho solicitado for zero

As funções `calloc`, `malloc` e `realloc` aceitam zero como argumento. Nenhuma memória real é alocada, mas um ponteiro válido é retornado e o bloco de memória pode ser modificado mais tarde por realloc.

## <a name="see-also"></a>Confira também

[Funções de biblioteca](../c-language/library-functions.md)
