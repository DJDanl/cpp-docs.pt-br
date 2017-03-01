---
title: "Compilador aviso (nível 1) C4789 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4789
dev_langs:
- C++
helpviewer_keywords:
- C4789
ms.assetid: 5800c301-5afb-4af0-85c1-ceb54d775234
caps.latest.revision: 18
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: e79d0443d3e0c947abf54f15213c71a4824c2566
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4789"></a>Compilador C4789 de aviso (nível 1)
Identificador de N bytes do tamanho de buffer superará; Bytes de M serão gravados começam no deslocamento L  
  
 Avisa sobre quando específico C Runtime (CRT) funções são usadas, de estouro de buffer parâmetros são passados e atribuições são executadas, que os tamanhos de dados são conhecidos no tempo de compilação. Esse aviso é para situações que podem elude detecção de incompatibilidade de tamanho de dados típico.  
  
 O aviso é exibido quando os dados, cujo tamanho é conhecido no tempo de compilação, são copiados e colocados em um bloco de dados cujo tamanho é conhecido em tempo de compilação para ser muito pequeno para os dados. A cópia deve ser feita usando o formulário intrínseco de uma das seguintes funções de CRT:  
  
-   [strcpy](../../c-runtime-library/reference/strcpy-wcscpy-mbscpy.md)  
  
-   [memset](../../c-runtime-library/reference/memset-wmemset.md)  
  
-   [memcpy](../../c-runtime-library/reference/memcpy-wmemcpy.md), [wmemcpy](../../c-runtime-library/reference/memcpy-wmemcpy.md)  
  
 O aviso também é exibida quando um parâmetro de tipo de dados é incompatível com o uso de uma conversão e, em seguida, uma atribuição de cópia de uma referência de lvalue é tentada.  
  
 Visual C++ pode gerar esse aviso para um caminho de código nunca seja executado. Você pode desativar temporariamente o aviso usando `#pragma`, conforme mostrado neste exemplo:  
  
 `#pragma(push)`  
  
 `#pragma warning ( disable : 4789 )`  
  
 `// unused code that generates compiler warning C4789`  
  
 `#pragma(pop)`  
  
 Isso impede que o Visual C++ gera o aviso para o bloco de código específico. O `#pragma(push)` preserva o estado existente antes de `#pragma warning(disable: 4789)` altera. O `#pragma(pop)` restaura o estado enviado e remove os efeitos do `#pragma warning(disable:4789)`. Para obter mais informações sobre a diretiva de pré-processador C++ `#pragma`, consulte [aviso](../../preprocessor/warning.md) e [diretivas Pragma e a palavra-chave pragma](../../preprocessor/pragma-directives-and-the-pragma-keyword.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4789.  
  
```  
// C4789.cpp  
// compile with: /Oi /W1 /c  
#include <string.h>  
#include <stdio.h>  
  
int main()   
{  
    char a[20];  
    strcpy(a, "0000000000000000000000000\n");   // C4789  
  
    char buf2[20];  
    memset(buf2, 'a', 21);   // C4789  
  
    char c;  
    wchar_t w = 0;  
    memcpy(&c, &w, sizeof(wchar_t));  
}  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir também gera C4789.  
  
```  
// C4789b.cpp  
// compile with: /W1 /O2 /c  
// processor: x86  
short G;  
  
void main()  
{  
   int * p = (int *)&G;   
   *p = 3;   // C4789 - writes an int through a pointer to short  
}   
```
