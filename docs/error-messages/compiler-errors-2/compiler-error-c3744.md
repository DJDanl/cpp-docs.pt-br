---
title: C3744 de erro do compilador | Microsoft Docs
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
ms.openlocfilehash: f96b8445c343bdd4f606157e692c4d6ce262e369
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3744"></a>C3744 de erro do compilador
unhook deve ter pelo menos 3 argumentos para eventos managed  
  
 O [unhook](../../cpp/unhook.md) função deve ter três parâmetros quando usado em um programa que é compilado para extensões gerenciadas para C++.  
  
 `__hook` e `__unhook` não são compatíveis com /clr programação. Use os operadores + = e-=.  
  
 C3744 só está acessível usando a opção de compilador obsoleto **/CLR: oldSyntax**.  
