---
title: Compilador aviso (nível 1) C4650 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4650
dev_langs:
- C++
helpviewer_keywords:
- C4650
ms.assetid: 3190b3e3-dcd6-4846-939b-f900ab652b2a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d49b21452465f26d6e696f928c04c20dc0e33307
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46052877"
---
# <a name="compiler-warning-level-1-c4650"></a>Compilador aviso (nível 1) C4650

informações de depuração não está no cabeçalho pré-compilado; apenas símbolos globais do cabeçalho estarão disponíveis

O arquivo de cabeçalho pré-compilado não foi compilado com informações de depuração simbólicas de Microsoft.

Quando vinculado, o arquivo executável ou dynamic-link library resultante não incluirá informações de depuração para símbolos locais contido no cabeçalho pré-compilado.

Esse aviso pode ser evitado ao recompilar o arquivo de cabeçalho pré-compilado com o [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md) opção de linha de comando.