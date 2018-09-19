---
title: Estouro negativo de valores de ponto flutuante | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 78af8016-643c-47db-b4f1-7f06cb4b243e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 980000932c8cc4a6be3798976d273dae8608324f
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46089158"
---
# <a name="underflow-of-floating-point-values"></a>Estouro negativo de valores de ponto flutuante

**ANSI 4.5.1** Se as funções matemáticas definem a expressão de inteiro `errno` como o valor da macro `ERANGE` em erros de alcance de estouro negativo

Um estouro negativo de ponto flutuante não define a expressão `errno` como `ERANGE`. Quando um valor se aproxima de zero e acaba sofrendo um estouro negativo, o valor é definido como zero.

## <a name="see-also"></a>Consulte também

[Funções de biblioteca](../c-language/library-functions.md)