---
title: Instrução GoTo (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- goto_cpp
dev_langs:
- C++
helpviewer_keywords:
- goto keyword [C++]
ms.assetid: 724c5deb-2de1-42d8-8ef1-23589d9bf5ed
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 52e3bbd026a00306fb2d8e69df94fd9c0c913039
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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