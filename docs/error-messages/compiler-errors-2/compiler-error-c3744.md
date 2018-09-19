---
title: Erro do compilador C3744 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3744
dev_langs:
- C++
helpviewer_keywords:
- C3744
ms.assetid: a447d050-80d1-406a-9a6e-f15c527d717c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d644a621fc6d8e460e1b97e5baec360de8662365
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46063717"
---
# <a name="compiler-error-c3744"></a>Erro do compilador C3744

unhook deve ter pelo menos 3 argumentos para eventos gerenciados

O [unhook](../../cpp/unhook.md) função deve levar três parâmetros quando usado em um programa que é compilado para extensões gerenciadas para C++.

`__hook` e `__unhook` não são compatíveis com /clr programação. Use os operadores + = e -=.

C3744 só está acessível usando a opção de compilador obsoletos **/CLR: oldSyntax**.
