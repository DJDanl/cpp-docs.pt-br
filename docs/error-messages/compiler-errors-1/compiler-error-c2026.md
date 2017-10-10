---
title: C2026 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2026
dev_langs:
- C++
helpviewer_keywords:
- C2026
ms.assetid: 8e64b6e1-b967-479b-be97-d12dc4a8e389
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 97937579c12730fecfa89c69d9e7cf51229b5c6c
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2026"></a>C2026 de erro do compilador
cadeia de caracteres muito grande, caracteres truncados à direita  
  
 A cadeia de caracteres era maior que o limite de 16380 caracteres de byte único.  
  
 Antes de cadeias de caracteres adjacentes são concatenadas, uma cadeia de caracteres não pode ter mais de 16380 caracteres de byte único.  
  
 Uma cadeia de caracteres Unicode de aproximadamente metade esse comprimento também poderia gerar esse erro.  
  
 Se você tiver uma cadeia de caracteres definida da seguinte forma, ele gera C2026:  
  
```  
char sz[] =  
"\  
imagine a really, really \  
long string here\  
";  
```  
  
 Você pode dividi-la da seguinte maneira:  
  
```  
char sz[] =  
"\  
imagine a really, really "  
"long string here\  
";  
```  
  
 Você pode desejar armazenar literais de cadeia de caracteres muito grandes (32K ou mais) em um recurso personalizado ou um arquivo externo. Consulte [criando um recurso de dados ou novo personalizado](../../windows/creating-a-new-custom-or-data-resource.md) para obter mais informações.
