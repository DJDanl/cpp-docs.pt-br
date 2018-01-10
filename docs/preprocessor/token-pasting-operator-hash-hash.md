---
title: Operador (#) de colagem de token | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: '##'
dev_langs: C++
helpviewer_keywords:
- preprocessor, operators
- '## preprocessor operator'
ms.assetid: 4f173503-990f-4bff-aef3-ec4d1f1458ef
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b2f77a2bd61080c398256c5d9c28085ec779d2e5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="token-pasting-operator-"></a>Operador de colagem de token (##)
O operador de sinal de número de dupla ou "colagem de token" (**##**), que às vezes é chamado de operador de "mesclar" é usado em tipo de objeto e o tipo função macros. Ele permite que tokens separados sejam agrupados em um único token e, portanto, não pode ser o primeiro ou último o token na definição da macro.  
  
 Se um parâmetro formal em uma definição de macro é precedido ou seguido pelo operador token-pasting, o parâmetro formal é substituído imediatamente pelo argumento real não expandido. A expansão da macro não é executada no argumento antes da substituição.  
  
 Em seguida, cada ocorrência do operador de colagem de token em *cadeia de caracteres de token* for removido, e os tokens anteriores e seguintes são concatenados. O token resultante deve ser um token válido. Nesse caso, o token será verificado para uma possível substituição se representar o nome de uma macro. O identificador representa o nome pelo qual os tokens concatenados serão conhecidos no programa antes da substituição. Cada token representa um token definido em outro lugar, no programa ou na linha de comando do compilador. O espaço em branco que precede ou segue o operador é opcional.  
  
 Este exemplo ilustra o uso de operadores stringizing em token-pasting na especificação da saída do programa:  
  
```  
#define paster( n ) printf_s( "token" #n " = %d", token##n )  
int token9 = 9;  
```  
  
 Se uma macro é chamada com um argumento numérico como  
  
```  
paster( 9 );  
```  
  
 a macro gera  
  
```  
printf_s( "token" "9" " = %d", token9 );  
```  
  
 que se torna  
  
```  
printf_s( "token9 = %d", token9 );  
```  
  
## <a name="example"></a>Exemplo  
  
```  
// preprocessor_token_pasting.cpp  
#include <stdio.h>  
#define paster( n ) printf_s( "token" #n " = %d", token##n )  
int token9 = 9;  
  
int main()  
{  
   paster(9);  
}  
```  
  
```Output  
token9 = 9  
```  
  
## <a name="see-also"></a>Consulte também  
 [Operadores de pré-processador](../preprocessor/preprocessor-operators.md)