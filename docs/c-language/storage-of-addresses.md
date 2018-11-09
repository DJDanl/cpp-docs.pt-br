---
title: Armazenamento de endereços
ms.date: 11/04/2016
helpviewer_keywords:
- storage [C++], addresses
- addresses [C++], storage of
ms.assetid: 423b2402-b847-4788-ad70-943b7c9c5c8b
ms.openlocfilehash: 2a0e218d4d34fa1482986ecccd7da8adba38086b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50539367"
---
# <a name="storage-of-addresses"></a>Armazenamento de endereços

A quantidade de armazenamento necessária para um endereço e o significado do endereço dependem da implementação do compilador. Não há garantia de que ponteiros para tipos diferentes tenham o mesmo tamanho. Portanto, **sizeof(char \*)** não é necessariamente igual a **sizeof(int \*)**.

**Seção específica da Microsoft**

Para o compilador Microsoft C, **sizeof(char \*)** é igual a **sizeof(int \*)**.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Declarações de ponteiro](../c-language/pointer-declarations.md)