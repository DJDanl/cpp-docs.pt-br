---
title: "Funções Recursivas | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- functions [C], recursive
- function calls, recursive
- functions [C], calling recursively
- recursive function calls
ms.assetid: 59739040-3081-4006-abbc-9d8423992bce
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
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
ms.translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 1978224fd80451eb74734d7010402567e402f875
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="recursive-functions"></a>Funções Recursivas
Qualquer função em um programa C pode ser chamada recursivamente, ou seja, pode chamar a si mesma. O número de chamadas recursivas está limitado ao tamanho da pilha. Consulte a opção de vinculador [/STACK (Stack Allocations)](../build/reference/stack-stack-allocations.md) (/STACK) para obter informações sobre as opções de vinculador que definem o tamanho da pilha. Cada vez que a função é chamada, um novo armazenamento é alocado para os parâmetros e para as variáveis **auto** e **register**, de modo que os respectivos valores em chamadas anteriores inacabadas não sejam substituídos. Os parâmetros só são diretamente acessíveis para a instância da função na qual são criados. Os parâmetros anteriores não são diretamente acessíveis para instâncias resultantes da função.  
  
 Observe que as variáveis declaradas com o armazenamento **static** não exigem um novo armazenamento com cada chamada recursiva. O armazenamento existe para todo o tempo de vida do programa. Cada referência a essa variável acessa a mesma área de armazenamento.  
  
## <a name="example"></a>Exemplo  
 Este exemplo ilustra chamadas recursivas:  
  
```  
int factorial( int num );      /* Function prototype */  
  
int main()  
{  
    int result, number;  
    .  
    .  
    .  
    result = factorial( number );  
}  
  
int factorial( int num )      /* Function definition */  
{  
    .  
    .  
    .  
    if ( ( num > 0 ) || ( num <= 10 ) )  
        return( num * factorial( num - 1 ) );  
}  
  
```  
  
## <a name="see-also"></a>Consulte também  
 [Chamadas de função](../c-language/function-calls.md)
