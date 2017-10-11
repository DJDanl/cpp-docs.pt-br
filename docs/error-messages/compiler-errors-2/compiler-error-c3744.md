---
title: C3744 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3744
dev_langs:
- C++
helpviewer_keywords:
- C3744
ms.assetid: a447d050-80d1-406a-9a6e-f15c527d717c
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 87df3fd92ac3fcad9b3e87f02f16b8151e678b77
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3744"></a>C3744 de erro do compilador
unhook deve ter pelo menos 3 argumentos para eventos managed  
  
 O [unhook](../../cpp/unhook.md) função deve ter três parâmetros quando usado em um programa que é compilado para extensões gerenciadas para C++.  
  
 `__hook`e `__unhook` não são compatíveis com /clr programação. Use os operadores + = e-=.  
  
 C3744 só está acessível usando a opção de compilador obsoleto **/CLR: oldSyntax**.  

