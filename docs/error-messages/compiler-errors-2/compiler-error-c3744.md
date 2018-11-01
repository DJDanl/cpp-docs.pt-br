---
title: Erro do compilador C3744
ms.date: 11/04/2016
f1_keywords:
- C3744
helpviewer_keywords:
- C3744
ms.assetid: a447d050-80d1-406a-9a6e-f15c527d717c
ms.openlocfilehash: 407ed4b30b55b63aa9bf36de9f8675a531d70534
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50516227"
---
# <a name="compiler-error-c3744"></a>Erro do compilador C3744

unhook deve ter pelo menos 3 argumentos para eventos gerenciados

O [unhook](../../cpp/unhook.md) função deve levar três parâmetros quando usado em um programa que é compilado para extensões gerenciadas para C++.

`__hook` e `__unhook` não são compatíveis com /clr programação. Use os operadores + = e -=.

C3744 só está acessível usando a opção de compilador obsoletos **/CLR: oldSyntax**.
