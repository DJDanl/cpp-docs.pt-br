---
title: "Instrução GoTo (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- goto_cpp
dev_langs:
- C++
helpviewer_keywords:
- goto keyword [C++]
ms.assetid: 724c5deb-2de1-42d8-8ef1-23589d9bf5ed
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a002071bdb4e271df525b138647b0544cfe9f3c0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="goto-statement-c"></a>Instrução goto (C++)
A instrução `goto` transfere o controle incondicionalmente para a instrução rotulada pelo identificador especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
goto identifier;  
```  
  
## <a name="remarks"></a>Comentários  
 A instrução rotulada designada por `identifier` deve estar na função atual. Todos os nomes de `identifier` são membros de um namespace interno e, portanto, não interferem em outros identificadores.  
  
 Os rótulos de instrução são significativos apenas para uma instrução `goto`; caso contrário, são ignorados. Os rótulos não podem ser redeclarados.  
  
 É um bom estilo de programação usar as instruções `break`, `continue` e `return` em vez da instrução `goto` sempre que possível. No entanto, como a instrução `break` sai apenas de um nível de um loop, você pode ter que usar uma instrução `goto` para sair de um loop profundamente aninhado.  
  
 Para obter mais informações sobre rótulos e o `goto` instrução, consulte [instruções rotuladas](../cpp/labeled-statements.md) e [usando rótulos com a instrução goto](http://msdn.microsoft.com/en-us/6cd7c31a-9822-4241-8566-f79f51be48fe).  
  
## <a name="example"></a>Exemplo  
 Neste exemplo, um `goto` instrução transfere o controle para o ponto de rotulado `stop` quando `i` é igual a 3.  
  
```  
// goto_statement.cpp  
#include <stdio.h>  
int main()  
{  
    int i, j;  
  
    for ( i = 0; i < 10; i++ )  
    {  
        printf_s( "Outer loop executing. i = %d\n", i );  
        for ( j = 0; j < 2; j++ )  
        {  
            printf_s( " Inner loop executing. j = %d\n", j );  
            if ( i == 3 )  
                goto stop;  
        }  
    }  
  
    // This message does not print:   
    printf_s( "Loop exited. i = %d\n", i );  
  
    stop:   
    printf_s( "Jumped to stop. i = %d\n", i );  
}  
```  
  
```Output  
Outer loop executing. i = 0  
 Inner loop executing. j = 0  
 Inner loop executing. j = 1  
Outer loop executing. i = 1  
 Inner loop executing. j = 0  
 Inner loop executing. j = 1  
Outer loop executing. i = 2  
 Inner loop executing. j = 0  
 Inner loop executing. j = 1  
Outer loop executing. i = 3  
 Inner loop executing. j = 0  
Jumped to stop. i = 3  
```  
  
## <a name="see-also"></a>Consulte também  
 [Instruções de Hiperlink](../cpp/jump-statements-cpp.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)