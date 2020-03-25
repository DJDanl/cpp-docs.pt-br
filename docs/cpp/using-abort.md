---
title: Usando abort
ms.date: 11/04/2016
helpviewer_keywords:
- abort function
ms.assetid: 3ba39b78-ef74-4a8d-8dee-2d62442de174
ms.openlocfilehash: db0f6cdcdaf4bca1b74d89a9415c4f7951455d80
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80187851"
---
# <a name="using-abort"></a>Usando abort

Chamar a função [Abort](../c-runtime-library/reference/abort.md) causa um encerramento imediato. Ignora o processo normal de destruição para objetos estáticos globais inicializados. Também ignora o processamento especial que foi especificado usando a função `atexit`.

## <a name="see-also"></a>Confira também

[Considerações de término adicionais](../cpp/additional-termination-considerations.md)
