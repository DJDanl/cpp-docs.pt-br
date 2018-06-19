---
title: Compilador (nível 1) de aviso C4711 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4711
dev_langs:
- C++
helpviewer_keywords:
- C4711
ms.assetid: 270506ab-fead-4328-b714-2978113be238
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1faa8051ea2d167ae1386ef30ac54166c942aaf2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33279799"
---
# <a name="compiler-warning-level-1-c4711"></a>Compilador C4711 de aviso (nível 1)
função selecionada para expansão inline ' function'  
  
 O compilador executada inlining em determinada função, embora ele não foi marcado para inlining.  
  
 C4711 estará habilitada se [/Ob2](../../build/reference/ob-inline-function-expansion.md) for especificado.  
  
 Inlining é executada a critério do compilador. Esse aviso é informativo.  
  
 Esse aviso é desativada por padrão. Para habilitar um aviso, use [#pragma aviso](../../preprocessor/warning.md). Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.