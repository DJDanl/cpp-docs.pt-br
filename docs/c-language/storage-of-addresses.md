---
title: Armazenamento de endereços | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- storage [C++], addresses
- addresses [C++], storage of
ms.assetid: 423b2402-b847-4788-ad70-943b7c9c5c8b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5fe77d3775c489399bb8b9032e645eee17d70b0a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46076587"
---
# <a name="storage-of-addresses"></a>Armazenamento de endereços

A quantidade de armazenamento necessária para um endereço e o significado do endereço dependem da implementação do compilador. Não há garantia de que ponteiros para tipos diferentes tenham o mesmo tamanho. Portanto, **sizeof(char \*)** não é necessariamente igual a **sizeof(int \*)**.

**Seção específica da Microsoft**

Para o compilador Microsoft C, **sizeof(char \*)** é igual a **sizeof(int \*)**.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Declarações de ponteiro](../c-language/pointer-declarations.md)