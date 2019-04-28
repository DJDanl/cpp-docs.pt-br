---
title: Usando abort
ms.date: 11/04/2016
f1_keywords:
- Abort
helpviewer_keywords:
- abort function
ms.assetid: 3ba39b78-ef74-4a8d-8dee-2d62442de174
ms.openlocfilehash: 0961f6f88f5de4d435fa65e50b9dbdbc478e7608
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62244201"
---
# <a name="using-abort"></a>Usando abort

Chamar o [anular](../c-runtime-library/reference/abort.md) função causa o encerramento imediato. Ignora o processo normal de destruição para objetos estáticos globais inicializados. Também ignora o processamento especial que foi especificado usando a função `atexit`.

## <a name="see-also"></a>Consulte também

[Considerações de término adicionais](../cpp/additional-termination-considerations.md)