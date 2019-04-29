---
title: Erro do compilador C2567
ms.date: 11/04/2016
f1_keywords:
- C2567
helpviewer_keywords:
- C2567
ms.assetid: 9c140ac9-7059-47e6-9ba1-e7939c8c0dc3
ms.openlocfilehash: eec529f43e23810843651888ef5722c5d0a0b2c9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62366349"
---
# <a name="compiler-error-c2567"></a>Erro do compilador C2567

não é possível abrir metadados 'file', arquivo pode ter foram excluído ou movido

Um arquivo de metadados que foi referenciado no código-fonte (com `#using`) não foi encontrado no mesmo diretório pelo processo de back-end do compilador como ele era pelo processo de front-end do compilador. Ver [#using diretiva](../../preprocessor/hash-using-directive-cpp.md) para obter mais informações.

C2567 pode ser causado se você compilar com **/c** em um computador e, em seguida, tente uma geração de código para link-time em outro computador. Para obter mais informações, consulte [/LTCG (geração de código Link-time)](../../build/reference/ltcg-link-time-code-generation.md)).

Isso também pode indicar que o computador não tem mais nenhuma memória.

Para corrigir esse erro, verifique se o arquivo de metadados está no mesmo local de diretório para todas as fases do processo de compilação.