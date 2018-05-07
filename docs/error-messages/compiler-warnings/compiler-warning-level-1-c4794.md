---
title: Compilador (nível 1) de aviso C4794 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4794
dev_langs:
- C++
helpviewer_keywords:
- C4794
ms.assetid: badc9c36-fa1a-4fec-929b-7bfda7a7b79f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 88ffa1200e7c760f028549335f0df5a9ea8ba3d5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4794"></a>Compilador C4794 de aviso (nível 1)
segmento de variável de armazenamento local de thread 'variável' alterado de 'nome da seção' para '. TLS$ '  
  
 Você usou [#pragma data_seg](../../preprocessor/data-seg.md) para colocar uma variável de tls em uma seção que não começa com $. TLS.  
  
 $ A. TLS*x* seção vai existir no arquivo de objeto onde [__declspec(thread)](../../cpp/thread.md) variáveis são definidas. Uma seção. TLS EXE ou DLL resultarão essas seções.  
  
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