---
title: Compilador (nível 4) de aviso C4092 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4092
dev_langs:
- C++
helpviewer_keywords:
- C4092
ms.assetid: 396ae826-a892-4327-bd66-f4762376d72b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8ca145addc16306d613817643e363ecd9c95069a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-4-c4092"></a>Compilador C4092 de aviso (nível 4)
sizeof retorna 'sem sinal longa'  
  
 O operando do `sizeof` operador era muito grande, portanto `sizeof` retornado sem um sinal **longo**. Este aviso ocorre em extensões do Microsoft ([/Ze](../../build/reference/za-ze-disable-language-extensions.md)). Em compatibilidade ANSI (/Za), o resultado será truncado em vez disso.