---
title: Operador (#) de colagem de token | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- '##'
dev_langs:
- C++
helpviewer_keywords:
- preprocessor, operators
- '## preprocessor operator'
ms.assetid: 4f173503-990f-4bff-aef3-ec4d1f1458ef
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c6e224c0327a7ba50c3e13ca78d749f41ad4641f
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33842225"
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