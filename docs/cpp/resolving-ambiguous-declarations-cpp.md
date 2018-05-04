---
title: Resolvendo declarações ambíguas (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 3d773ee7-bbea-47de-80c2-cb0a9d4ec0b9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 530111ee439a991201debab876d485a36b7f5ac5
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="resolving-ambiguous-declarations-c"></a>Resolvendo declarações ambíguas (C++)
Para executar conversões explícitas de um tipo em outro, você deve usar as conversões, especificando o nome do tipo desejado. Algumas conversões de tipos resultam na ambiguidade sintática. A seguinte conversão de tipos estilo função é ambígua:  
  
```  
char *aName( String( s ) );  
```  
  
 Não está claro se ela é uma declaração de função ou uma declaração de objeto com uma conversão como o inicializador function-style: ele pode declarar uma função de retorno de tipo **char \***  que usa um argumento do tipo `String` , ou ele pode declarar o objeto `aName` e inicializá-lo com o valor de `s` conversão para tipo `String`.  
  
 Se uma declaração puder ser considerada uma declaração de função válida, ela será tratada como tal. Se, possivelmente, ela não for uma declaração de função – ou seja, se estiver sintaticamente incorreta — será uma instrução examinada para ver se é uma conversão de tipo estilo função. Portanto, o compilador considera a instrução como uma declaração de uma função e ignora os parênteses em torno do identificador `s`. Por outro lado, as instruções:  
  
```  
char *aName( (String)s );  
```  
  
 e  
  
```  
char *aName = String( s );  
```  
  
 são claramente as declarações de objetos e uma conversão definida pelo usuário do tipo `String` digitar **char \***  é chamado para executar a inicialização de `aName`.  
  
## <a name="see-also"></a>Consulte também  
 