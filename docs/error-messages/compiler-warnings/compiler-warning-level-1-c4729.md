---
title: Compilador (nível 1) de aviso C4729 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4729
dev_langs:
- C++
helpviewer_keywords:
- C4729
ms.assetid: 36a0151f-f258-48d9-9444-ae6d41ff70a4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 02ccbb80a44123498a231c1909c9c2c6fca72a24
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33281736"
---
# <a name="compiler-warning-level-1-c4729"></a>Compilador C4729 de aviso (nível 1)
função muito grande para o gráfico de fluxo com base em avisos  
  
 Esse aviso é gerado quando uma função é muito grande para ser compilada com verificação confiável para situações em que pode gerar um aviso. Este aviso só é gerado quando o [/Od](../../build/reference/od-disable-debug.md) opção de compilador usada.  
  
 Para resolver este aviso, divida a função em funções menores.