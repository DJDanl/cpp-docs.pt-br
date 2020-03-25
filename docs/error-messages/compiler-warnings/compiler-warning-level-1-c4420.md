---
title: Aviso do compilador (nível 1) C4420
ms.date: 11/04/2016
f1_keywords:
- C4420
helpviewer_keywords:
- C4420
ms.assetid: 44a37754-7ddd-4764-a5f7-d33e05c20091
ms.openlocfilehash: 72ab87b34e07717112f5af1727a216b4f786ae0d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80186784"
---
# <a name="compiler-warning-level-1-c4420"></a>Aviso do compilador (nível 1) C4420

"Operator": operador não disponível, usando "Operator" em vez disso; a verificação de tempo de execução pode ser comprometida

Esse aviso é gerado quando você usa o [/RTCv](../../build/reference/rtc-run-time-error-checks.md) (nova verificação de vetor/exclusão) e quando nenhum formulário de vetor é encontrado. Nesse caso, o formato não vetorial é usado.

Para que o/RTCv funcione corretamente, o compilador sempre deve chamar o formato de vetor de [novo](../../cpp/new-operator-cpp.md)/[delete](../../cpp/delete-operator-cpp.md) se a sintaxe de vetor foi usada.
