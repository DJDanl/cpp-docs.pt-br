---
title: Alocando memória igual a zero
ms.date: 11/04/2016
helpviewer_keywords:
- memory allocation, zero memory
- zero memory
ms.assetid: 768f2ab9-83a1-4887-8eb5-c094c18489a8
ms.openlocfilehash: 40f21c0fa9a2a4068cb2592c49ccefed82176a35
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56147458"
---
# <a name="allocating-zero-memory"></a>Alocando memória igual a zero

**ANSI 4.10.3** O comportamento da função `calloc`,`malloc` ou `realloc`, se o tamanho solicitado é zero

As funções `calloc`, `malloc` e `realloc` aceitam zero como argumento. Nenhuma memória real é alocada, mas um ponteiro válido é retornado e o bloco de memória pode ser modificado mais tarde por realloc.

## <a name="see-also"></a>Consulte também

[Funções de biblioteca](../c-language/library-functions.md)
