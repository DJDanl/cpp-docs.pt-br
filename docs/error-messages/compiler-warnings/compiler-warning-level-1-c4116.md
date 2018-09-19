---
title: Compilador aviso (nível 1) C4116 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4116
dev_langs:
- C++
helpviewer_keywords:
- C4116
ms.assetid: 25434ef3-061e-4252-91a5-0fe2a4b2ffb3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5f91892bd28733761c187705b8f576007862027b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46080695"
---
# <a name="compiler-warning-level-1-c4116"></a>Compilador aviso (nível 1) C4116

definição de tipo sem-nome entre parênteses

Uma estrutura, união ou tipo enumerado sem nome é definido em uma expressão entre parênteses. A definição de tipo não faz sentida.

Em uma chamada de função C, a definição tem escopo global. Em uma chamada de função do C++, a definição tem o mesmo escopo que a função que está sendo chamado.