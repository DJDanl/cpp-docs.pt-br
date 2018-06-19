---
title: C2026 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2026
dev_langs:
- C++
helpviewer_keywords:
- C2026
ms.assetid: 8e64b6e1-b967-479b-be97-d12dc4a8e389
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a6b2952daa8cc7b3642cca5ba278990fde7d1ebe
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33167659"
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