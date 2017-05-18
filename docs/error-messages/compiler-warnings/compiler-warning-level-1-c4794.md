---
title: "Compilador aviso (nível 1) C4794 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4794
dev_langs:
- C++
helpviewer_keywords:
- C4794
ms.assetid: badc9c36-fa1a-4fec-929b-7bfda7a7b79f
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 9e929445b378d5307dd2de39c11bf77d07ced9c5
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4794"></a>Compilador C4794 de aviso (nível 1)
segmento da variável de armazenamento local de thread 'variável' alterado de 'nome da seção' para '.tls$ '  
  
 Você usou [#pragma data_seg](../../preprocessor/data-seg.md) colocar uma variável tls em uma seção que não começa com .tls$.  
  
 O $ .tls*x* seção continuará a existir no arquivo de objeto onde [__declspec(thread)](../../cpp/thread.md) variáveis são definidas. Uma seção .tls no arquivo EXE ou DLL resultarão essas seções.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4794:  
  
```  
// C4794.cpp  
// compile with: /W1 /c  
#pragma data_seg(".someseg")  
__declspec(thread) int i;   // C4794  
  
// OK  
#pragma data_seg(".tls$9")  
__declspec(thread) int j;  
```
