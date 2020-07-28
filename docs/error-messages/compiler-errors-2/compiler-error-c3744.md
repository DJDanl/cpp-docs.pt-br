---
title: Erro do compilador C3744
ms.date: 11/04/2016
f1_keywords:
- C3744
helpviewer_keywords:
- C3744
ms.assetid: a447d050-80d1-406a-9a6e-f15c527d717c
ms.openlocfilehash: 8db81afc348434e9ea2f57c991962fb15dc6bf98
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220152"
---
# <a name="compiler-error-c3744"></a>Erro do compilador C3744

__unhook deve ter pelo menos 3 argumentos para eventos gerenciados

A [`__unhook`](../../cpp/unhook.md) função deve levar três parâmetros quando usada em um programa que é compilado para Managed Extensions for C++.

**`__hook`** e **`__unhook`** não são compatíveis com **`/clr`** programação. Em vez disso, use os operadores + = e-=.

C3744 só pode ser acessado usando a opção de compilador obsoleto **`/clr:oldSyntax`** .
