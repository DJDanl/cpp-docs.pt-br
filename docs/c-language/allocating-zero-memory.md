---
title: Alocando memória zero | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- memory allocation, zero memory
- zero memory
ms.assetid: 768f2ab9-83a1-4887-8eb5-c094c18489a8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bc3b7a92cdc8a05c73f15c7cea917d86a3b6bb46
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46085050"
---
# <a name="allocating-zero-memory"></a>Alocando memória igual a zero

**ANSI 4.10.3** O comportamento da função `calloc`,`malloc` ou `realloc`, se o tamanho solicitado é zero

As funções `calloc`, `malloc` e `realloc` aceitam zero como argumento. Nenhuma memória real é alocada, mas um ponteiro válido é retornado e o bloco de memória pode ser modificado mais tarde por realloc.

## <a name="see-also"></a>Consulte também

[Funções de biblioteca](../c-language/library-functions.md)