---
title: Erro CXX0019 (avaliador de expressão)
ms.date: 11/04/2016
f1_keywords:
- CXX0019
helpviewer_keywords:
- CXX0019
- CAN0019
ms.assetid: 4c6431fd-3310-4a61-934d-58b070b330fe
ms.openlocfilehash: 266e97f28cf0f27cb87e9743399c66aba87c0e8d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62397101"
---
# <a name="expression-evaluator-error-cxx0019"></a>Erro CXX0019 (avaliador de expressão)

conversão de tipo incorreto

O avaliador de expressão C não é possível executar a conversão como escrito de tipos.

Esse erro é idêntico ao CAN0019.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. O tipo especificado é desconhecido.

1. Havia muitos níveis de tipos de ponteiro. Por exemplo, a conversão de tipos

    ```
    (char **)h_message
    ```

   não pode ser avaliada pelo avaliador de expressão C.