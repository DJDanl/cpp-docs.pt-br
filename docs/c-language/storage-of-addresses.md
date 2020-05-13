---
title: Armazenamento de endereços
ms.date: 11/04/2016
helpviewer_keywords:
- storage [C++], addresses
- addresses [C++], storage of
ms.assetid: 423b2402-b847-4788-ad70-943b7c9c5c8b
ms.openlocfilehash: 47b09ab6cd0b2045206daaee4badad32858ff934
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62336186"
---
# <a name="storage-of-addresses"></a>Armazenamento de endereços

A quantidade de armazenamento necessária para um endereço e o significado do endereço dependem da implementação do compilador. Não há garantia de que ponteiros para tipos diferentes tenham o mesmo tamanho. Portanto, **sizeof(char \*)** não é necessariamente igual a **sizeof(int \*)**.

**Específico da Microsoft**

Para o compilador Microsoft C, **sizeof(char \*)** é igual a **sizeof(int \*)**.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Declarações de ponteiro](../c-language/pointer-declarations.md)
