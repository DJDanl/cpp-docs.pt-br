---
title: C2218 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2218
dev_langs:
- C++
helpviewer_keywords:
- C2218
ms.assetid: b0f55da4-8edb-4b45-b298-1a091981bd7b
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: f3ece905f03dc788580afde3e526041e933e3072
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2218"></a>Erro do Compilador C2218
vectorcall' não pode ser usado com ' / arch: IA32'  
  
 A convenção de chamada `__vectorcall` é suportada somente em código nativo nos processadores de x86 e x64 que incluem Streaming SIMD Extensions 2 (SSE2) e superiores. Para obter mais informações, consulte [vectorcall](../../cpp/vectorcall.md).  
  
 Para corrigir esse erro, altere as opções do compilador para conjuntos de instruções SSE2, AVX ou AVX2 de destino. Para obter mais informações, consulte [/arch (x86)](../../build/reference/arch-x86.md).
