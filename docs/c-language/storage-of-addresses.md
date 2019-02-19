---
title: Armazenamento de endereços
ms.date: 11/04/2016
helpviewer_keywords:
- storage [C++], addresses
- addresses [C++], storage of
ms.assetid: 423b2402-b847-4788-ad70-943b7c9c5c8b
ms.openlocfilehash: 47b09ab6cd0b2045206daaee4badad32858ff934
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56148732"
---
# <a name="storage-of-addresses"></a>Armazenamento de endereços

A quantidade de armazenamento necessária para um endereço e o significado do endereço dependem da implementação do compilador. Não há garantia de que ponteiros para tipos diferentes tenham o mesmo tamanho. Portanto, **sizeof(char \*)** não é necessariamente igual a **sizeof(int \*)**.

**Seção específica da Microsoft**

Para o compilador Microsoft C, **sizeof(char \*)** é igual a **sizeof(int \*)**.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Declarações de ponteiro](../c-language/pointer-declarations.md)
