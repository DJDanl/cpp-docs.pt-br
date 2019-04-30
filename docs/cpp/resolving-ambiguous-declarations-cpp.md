---
title: Resolvendo declarações ambíguas (C++)
ms.date: 11/04/2016
ms.assetid: 3d773ee7-bbea-47de-80c2-cb0a9d4ec0b9
ms.openlocfilehash: 52e94f474d59505298cb4f78a477cedd21b90aad
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62403393"
---
# <a name="resolving-ambiguous-declarations-c"></a>Resolvendo declarações ambíguas (C++)

Para executar conversões explícitas de um tipo em outro, você deve usar as conversões, especificando o nome do tipo desejado. Algumas conversões de tipos resultam na ambiguidade sintática. A seguinte conversão de tipos estilo função é ambígua:

```cpp
char *aName( String( s ) );
```

Está claro se ela é uma declaração de função ou uma declaração com um estilo de função convertido como o inicializador de objeto: Ele poderia declarar uma função que retorna o tipo `char *` que usa um argumento do tipo `String`, ou poderia declarar o objeto `aName` e inicializá-lo com o valor de `s` convertido no tipo `String`.

Se uma declaração puder ser considerada uma declaração de função válida, ela será tratada como tal. Se, possivelmente, ela não for uma declaração de função – ou seja, se estiver sintaticamente incorreta — será uma instrução examinada para ver se é uma conversão de tipo estilo função. Portanto, o compilador considera a instrução como uma declaração de uma função e ignora os parênteses em torno do identificador `s`. Por outro lado, as instruções:

```cpp
char *aName( (String)s );
```

e

```cpp
char *aName = String( s );
```

são claramente declarações de objetos e uma conversão definida pelo usuário do tipo `String` digitar `char *` é chamado para executar a inicialização de `aName`.