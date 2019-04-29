---
title: Erro CXX0052 (avaliador de expressão)
ms.date: 11/04/2016
f1_keywords:
- CXX0052
helpviewer_keywords:
- CXX0052
- CAN0052
ms.assetid: 5060d479-d0a4-4682-b858-c8b9a4f324e6
ms.openlocfilehash: 12b4aff2c07e81a77b1a822fa15beb972a7e1e05
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62299565"
---
# <a name="expression-evaluator-error-cxx0052"></a>Erro CXX0052 (avaliador de expressão)

função de membro não está presente

Uma função de membro foi especificada como um ponto de interrupção, mas não pôde ser encontrada. Definindo um ponto de interrupção em uma função que foi embutida pode causar esse erro.

Recompilar o arquivo com o inlining desconectados (/ Ob0) para definir um ponto de interrupção nessa função.

Uma expressão de chamada de função que não foi definida.

Esse erro é idêntico ao CAN0052.