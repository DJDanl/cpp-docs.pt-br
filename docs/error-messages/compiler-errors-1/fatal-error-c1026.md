---
title: Erro fatal C1026 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1026
dev_langs:
- C++
helpviewer_keywords:
- C1026
ms.assetid: 89bb9d40-673a-44aa-a9f4-b42c07b49d44
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: db9167383df48dad274ef8941defaa53f51d3bfa
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46068982"
---
# <a name="fatal-error-c1026"></a>Erro fatal C1026

estouro de pilha do analisador, programa muito complexo

O espaço necessário para analisar o programa causou um estouro de pilha do compilador.

Reduza a complexidade de expressões por:

- Diminuindo o aninhamento `for` e `switch` instruções. Colocar instruções mais profundamente aninhadas em funções separadas.

- Dividir expressões longas que envolvem operadores de vírgulas ou chamadas de função.