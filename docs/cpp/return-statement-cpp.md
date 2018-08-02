---
title: Instrução Return (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- return_cpp
dev_langs:
- C++
helpviewer_keywords:
- return keyword [C++], syntax
- return keyword [C++]
ms.assetid: a498903a-056a-4df0-a6cf-72f633a62210
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: dda9406909f3508472c11524402c37baa17a76b0
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39465783"
---
# <a name="return-statement-c"></a>Instrução return (C++)
Finaliza a execução de uma função e retorna o controle para a função de chamada (ou para o sistema operacional, se o controle for transferido da função `main`). A execução é retomada na função de chamada no ponto imediatamente após a chamada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
return [expression];  
```  
  
## <a name="remarks"></a>Comentários  
 A cláusula `expression`, caso exista, é convertida no tipo especificado na declaração da função, como se uma inicialização estivesse sendo executada. Conversão do tipo da expressão para o **retornar** tipo de função pode criar objetos temporários. Para obter mais informações sobre como e quando os temporários são criados, consulte [objetos temporários](../cpp/temporary-objects.md).  
  
 O valor da cláusula `expression` é retornado à função de chamada. Se a expressão for omitida, o valor de retorno da função será indefinido. Construtores e destruidores e funções do tipo **void**, não é possível especificar uma expressão na **retornar** instrução. Funções de todos os outros tipos devem especificar uma expressão na **retornar** instrução.  
  
 Quando o fluxo de controle sai do bloco que inclui a definição da função, o resultado é o mesmo como seria se um **retornar** instrução sem uma expressão tivesse sido executada. Isso não é válido para funções que são declaradas como retornando um valor.  
  
 Uma função pode ter qualquer número de **retornar** instruções.  
  
 O exemplo a seguir usa uma expressão com um **retornar** instrução para obter o maior dos dois inteiros.  
  
## <a name="example"></a>Exemplo  
  
```cpp 
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