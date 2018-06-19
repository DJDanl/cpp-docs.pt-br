---
title: C2396 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2396
dev_langs:
- C++
helpviewer_keywords:
- C2396
ms.assetid: 1b515ef6-7af4-400f-b4ed-564313ea15f6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fd9007d15cb5b6f9badf8f0962c8c1aa29df5bf7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33197449"
---
# <a name="compiler-error-c2396"></a>C2396 de erro do compilador
' your_type::operator'type ': CLR ou WinRT functionnot de conversão definida pelo usuário válido. Deve converter de ou converter em: ' t ^', ' t ^ %', ' t ^ &', onde T = 'your_type'  
  
 Uma função de conversão em um tempo de execução do Windows ou um tipo gerenciado não tem pelo menos um parâmetro cujo tipo é o mesmo que o tipo que contém a função de conversão.  
  
 O exemplo a seguir gera C2396 e mostra como corrigi-lo:  
  
```  
// C2396.cpp  
// compile with: /clr /c  
  
ref struct Y {  
   static operator int(char c);   // C2396  
  
   // OK  
   static operator int(Y^ hY);  
   // or  
   static operator Y^(char c);  
};  
```