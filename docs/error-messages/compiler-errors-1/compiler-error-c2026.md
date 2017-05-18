---
title: C2026 de erro do compilador | Documentos do Microsoft
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
ms.sourcegitcommit: 4fafe461008e3545243d693e0d9e34acd57163e0
ms.openlocfilehash: c429f81c64b7710b7edc2b8540d98e8c790e4062
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2026"></a>C2026 de erro do compilador
cadeia de caracteres muito grande, caracteres à direita truncados  
  
 A cadeia de caracteres era maior que o limite de caracteres de byte único 16380.  
  
 Antes de cadeias de caracteres adjacentes são concatenadas, uma cadeia de caracteres não pode ter mais de 16380 caracteres de byte único.  
  
 Uma cadeia de caracteres Unicode de comprimento aproximadamente metade desta também geram esse erro.  
  
 Se você tiver uma cadeia de caracteres definida da seguinte maneira, ele gera C2026:  
  
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
  
 Você pode desejar armazenar literais de cadeia de caracteres muito grandes (32K ou mais) em um arquivo externo ou de um recurso personalizado. Consulte [criando um recurso de dados ou novo personalizado](../../windows/creating-a-new-custom-or-data-resource.md) para obter mais informações.
