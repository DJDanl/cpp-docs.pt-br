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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: acee7db1513dd3e999a90218ea674930c2a13f1d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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