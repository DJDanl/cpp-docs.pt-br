---
title: "Instrução Return (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- return_cpp
dev_langs:
- C++
helpviewer_keywords:
- return keyword [C++], syntax
- return keyword [C++]
ms.assetid: a498903a-056a-4df0-a6cf-72f633a62210
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 7474bc55a5c9d2406465a6ee763c19c2e56e1159
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="return-statement-c"></a>Instrução return (C++)
Finaliza a execução de uma função e retorna o controle para a função de chamada (ou para o sistema operacional, se o controle for transferido da função `main`). A execução é retomada na função de chamada no ponto imediatamente após a chamada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
return [expression];  
```  
  
## <a name="remarks"></a>Comentários  
 A cláusula `expression`, caso exista, é convertida no tipo especificado na declaração da função, como se uma inicialização estivesse sendo executada. A conversão do tipo da expressão para o tipo `return` da função pode criar objetos temporários. Para obter mais informações sobre como e quando longa é criadas, consulte [objetos temporários](../cpp/temporary-objects.md).  
  
 O valor da cláusula `expression` é retornado à função de chamada. Se a expressão for omitida, o valor de retorno da função será indefinido. Construtores e destruidores e funções do tipo `void`, não é possível especificar uma expressão no `return` instrução. As funções de todos os outros tipos devem especificar uma expressão na instrução `return`.  
  
 Quando o fluxo de controle sair do bloco que inclui a definição de função, o resultado é o mesmo que haveria se uma instrução `return` sem uma expressão tivesse sido executada. Isso não é válido para funções que são declaradas como retornando um valor.  
  
 Uma função pode ter qualquer número de instruções `return`.  
  
 O exemplo a seguir usa uma expressão com uma instrução `return` para obter o maior de dois inteiros.  
  
## <a name="example"></a>Exemplo  
  
```  
// return_statement2.cpp  
#include <stdio.h>  
  
int max ( int a, int b )  
{  
   return ( a > b ? a : b );  
}  
  
int main()  
{  
    int nOne = 5;  
    int nTwo = 7;  
  
    printf_s("\n%d is bigger\n", max( nOne, nTwo ));  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Instruções de Hiperlink](../cpp/jump-statements-cpp.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)
