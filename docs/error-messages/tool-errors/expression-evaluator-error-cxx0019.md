---
title: Erro CXX0019 (avaliador de expressão)
ms.date: 11/04/2016
f1_keywords:
- CXX0019
helpviewer_keywords:
- CXX0019
- CAN0019
ms.assetid: 4c6431fd-3310-4a61-934d-58b070b330fe
ms.openlocfilehash: 61646462eeba4918a4993b23f7f4b394083296ce
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80195884"
---
# <a name="expression-evaluator-error-cxx0019"></a>Erro CXX0019 (avaliador de expressão)

conversão de tipo inadequada

O avaliador de expressão C não pode executar a conversão de tipo como gravada.

Esse erro é idêntico a CAN0019.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. O tipo especificado é desconhecido.

1. Havia muitos níveis de tipos de ponteiro. Por exemplo, a conversão de tipo

    ```
    (char **)h_message
    ```

   Não pode ser avaliado pelo avaliador de expressão C.
