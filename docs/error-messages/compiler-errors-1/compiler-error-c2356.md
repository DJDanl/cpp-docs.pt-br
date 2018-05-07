---
title: C2356 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2356
dev_langs:
- C++
helpviewer_keywords:
- C2356
ms.assetid: 84d5a816-9a61-4d45-9978-38e485bbf767
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a9dfb13f388c6c40c6c1853ab8e87b2e39edbc1e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2356"></a>C2356 de erro do compilador
segmento de inicialização não deve mudar durante unidade de tradução  
  
 Possíveis causas:  
  
-   `#pragma init_seg` precedido pelo código de inicialização de segmento  
  
-   `#pragma init_seg` precedido por outro `#pragma init_seg`  
  
 Para resolver, mova o código de inicialização de segmento para o início do módulo. Se várias áreas devem ser inicializadas, mova-os para separar os módulos.  
  
 O exemplo a seguir gera C2356:  
  
```  
// C2356.cpp  
#pragma warning(disable : 4075)  
  
int __cdecl myexit(void (__cdecl *)());  
int __cdecl myexit2(void (__cdecl *)());  
  
#pragma init_seg(".mine$m",myexit)  
#pragma init_seg(".mine$m",myexit2)   // C2356  
```