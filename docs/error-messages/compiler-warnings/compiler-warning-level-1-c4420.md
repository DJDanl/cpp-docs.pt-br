---
title: Compilador aviso (nível 1) C4420
ms.date: 11/04/2016
f1_keywords:
- C4420
helpviewer_keywords:
- C4420
ms.assetid: 44a37754-7ddd-4764-a5f7-d33e05c20091
ms.openlocfilehash: a4a7e91e7845cc0fc25d5a6fad16ae7b7e327952
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62408167"
---
# <a name="compiler-warning-level-1-c4420"></a>Compilador aviso (nível 1) C4420

'operator': operador não está disponível, usando 'operator'; verificação de tempo de execução pode ser comprometida

Esse aviso é gerado quando você usa o [/RTCv](../../build/reference/rtc-run-time-error-checks.md) (vetor de verificação de novo/excluir) e quando nenhum formulário de vetor é encontrado. Nesse caso, a forma de vetor não é usada.

Para /RTCv funcione corretamente, o compilador deve sempre chamar o formulário de vetor de [novos](../../cpp/new-operator-cpp.md)/[excluir](../../cpp/delete-operator-cpp.md) se a sintaxe de vetor foi usada.