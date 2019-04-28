---
title: Erro do compilador C3744
ms.date: 11/04/2016
f1_keywords:
- C3744
helpviewer_keywords:
- C3744
ms.assetid: a447d050-80d1-406a-9a6e-f15c527d717c
ms.openlocfilehash: 407ed4b30b55b63aa9bf36de9f8675a531d70534
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62227092"
---
# <a name="compiler-error-c3744"></a>Erro do compilador C3744

unhook deve ter pelo menos 3 argumentos para eventos gerenciados

O [unhook](../../cpp/unhook.md) função deve levar três parâmetros quando usado em um programa que é compilado para extensões gerenciadas do C++.

`__hook` e `__unhook` não são compatíveis com /clr programação. Use os operadores + = e -=.

C3744 só está acessível usando a opção de compilador obsoletos **/CLR: oldSyntax**.
