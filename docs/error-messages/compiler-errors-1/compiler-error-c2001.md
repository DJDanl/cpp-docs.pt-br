---
title: C2001 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2001
dev_langs:
- C++
helpviewer_keywords:
- C2001
ms.assetid: 0c3a7821-d8e5-4398-ab5a-4116d46e8dda
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: aedba438451089aa2d71e06da7ce189ab97d4190
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2001"></a>C2001 de erro do compilador
nova linha em constante  
  
 Uma constante de cadeia de caracteres não pode continuar em uma segunda linha, a menos que você faça o seguinte:  
  
-   Finalizar a primeira linha com uma barra invertida.  
  
-   Feche a cadeia de caracteres na primeira linha com aspas duplas e abra a cadeia de caracteres na próxima linha com outra aspa dupla.  
  
 Terminando a primeira linha com \n não é suficiente.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2001:  
  
```  
// C2001.cpp  
// C2001 expected  
#include <stdio.h>  
  
int main()  
{  
    printf_s("Hello,  
             world");  
    printf_s("Hello,\n  
             world");  
}  
```  
  
## <a name="example"></a>Exemplo  
 Espaços no início da próxima linha depois de um caractere de continuação de linha são incluídos na constante de cadeia de caracteres. Nenhum dos exemplos acima inserir um caractere de nova linha em constante de cadeia de caracteres. Você pode inserir um caractere de nova linha, conforme mostrado aqui:  
  
```  
// C2001b.cpp  
#include <stdio.h>  
  
int main()  
{  
    printf_s("Hello,\n\  
             world");  
  
    printf_s("Hello,\  
             \nworld");  
  
    printf_s("Hello,\n"  
             "world");  
  
    printf_s("Hello,"  
             "\nworld");  
  
    printf_s("Hello,"  
             " world");  
  
    printf_s("Hello,\  
             world");  
}  
```
