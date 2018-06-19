---
title: Compilador (nível 1) de aviso C4789 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4789
dev_langs:
- C++
helpviewer_keywords:
- C4789
ms.assetid: 5800c301-5afb-4af0-85c1-ceb54d775234
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f8b16fada030783f5f9e3aa3d1f9a04e7743a13c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33282981"
---
# <a name="compiler-warning-level-1-c4789"></a>Compilador C4789 de aviso (nível 1)
Identificador de N bytes de tamanho do buffer será substituído; M bytes serão escritos começando no deslocamento L  
  
 Avisa sobre buffer saturação quando funções específicas de (CRT) de tempo de execução C são usadas, os parâmetros são passados e atribuições são executadas, de modo que os tamanhos dos dados são conhecidos no tempo de compilação. Esse aviso é para situações que podem elude detecção de incompatibilidade de tamanho de dados típica.  
  
 O aviso é exibido quando os dados, cujo comprimento é conhecido em tempo de compilação, são copiados e colocar em um bloco de dados cujo tamanho é conhecido em tempo de compilação para ser muito pequeno para os dados. A cópia deve ser feita usando o formulário intrínseco de uma das seguintes funções de CRT:  
  
-   [strcpy](../../c-runtime-library/reference/strcpy-wcscpy-mbscpy.md)  
  
-   [memset](../../c-runtime-library/reference/memset-wmemset.md)  
  
-   [memcpy](../../c-runtime-library/reference/memcpy-wmemcpy.md), [wmemcpy](../../c-runtime-library/reference/memcpy-wmemcpy.md)  
  
 O aviso também é exibida quando um parâmetro de tipo de dados é incompatível com o uso de uma conversão e, em seguida, uma tentativa de uma atribuição de cópia de uma referência lvalue.  
  
 Visual C++ pode gerar esse aviso para um caminho de código que nunca seja executado. Você pode desativar temporariamente o aviso usando `#pragma`, conforme mostrado neste exemplo:  
  
 `#pragma(push)`  
  
 `#pragma warning ( disable : 4789 )`  
  
 `// unused code that generates compiler warning C4789`  
  
 `#pragma(pop)`  
  
 Isso impede que o Visual C++ gerando o aviso para esse bloco específico de código. O `#pragma(push)` preserva o estado existente antes de `#pragma warning(disable: 4789)` altera. O `#pragma(pop)` restaura o estado enviado e remove os efeitos da `#pragma warning(disable:4789)`. Para obter mais informações sobre a diretiva de pré-processador C++ `#pragma`, consulte [aviso](../../preprocessor/warning.md) e [diretivas Pragma e a palavra-chave de pragma](../../preprocessor/pragma-directives-and-the-pragma-keyword.md).  
  
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