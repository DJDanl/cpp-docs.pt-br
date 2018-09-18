---
title: CXX0052 de erro do avaliador de expressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- CXX0052
dev_langs:
- C++
helpviewer_keywords:
- CXX0052
- CAN0052
ms.assetid: 5060d479-d0a4-4682-b858-c8b9a4f324e6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1ba8fb898930ef830857773a89cd80e4c43c59c4
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46028149"
---
# <a name="expression-evaluator-error-cxx0052"></a>Erro CXX0052 (avaliador de expressão)

função de membro não está presente

Uma função de membro foi especificada como um ponto de interrupção, mas não pôde ser encontrada. Definindo um ponto de interrupção em uma função que foi embutida pode causar esse erro.

Recompilar o arquivo com o inlining desconectados (/ Ob0) para definir um ponto de interrupção nessa função.

Uma expressão de chamada de função que não foi definida.

Esse erro é idêntico ao CAN0052.