---
title: Erro do compilador C2567
ms.date: 11/04/2016
f1_keywords:
- C2567
helpviewer_keywords:
- C2567
ms.assetid: 9c140ac9-7059-47e6-9ba1-e7939c8c0dc3
ms.openlocfilehash: 921992c678c1de0b74f99f544173478ebe809b2c
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80177450"
---
# <a name="compiler-error-c2567"></a>Erro do compilador C2567

Não é possível abrir os metadados em ' file ', o arquivo pode ter sido excluído ou movido

Um arquivo de metadados que foi referenciado na origem (com `#using`) não foi encontrado no mesmo diretório pelo processo de back-end do compilador como era pelo processo de front-end do compilador. Consulte [#using diretiva](../../preprocessor/hash-using-directive-cpp.md) para obter mais informações.

C2567 pode ser causado se você compilar with **/c** em um computador e, em seguida, tentar uma geração de código de tempo de vinculação em outro computador. Para obter mais informações, consulte [/LTCG (geração de código de tempo de vinculação)](../../build/reference/ltcg-link-time-code-generation.md)).

Ele também pode indicar que o computador não tinha mais memória.

Para corrigir esse erro, verifique se o arquivo de metadados está no mesmo local de diretório para todas as fases do processo de compilação.
