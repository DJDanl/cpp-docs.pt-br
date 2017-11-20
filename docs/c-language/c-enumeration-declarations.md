---
title: "Declarações de enumeração C | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- declarations, enumerations
- define directive (#define), alternative to
- enumerators, declaring
- '#define directive, alternative to'
- named constants, enumeration declarations
- declaring enumerations
ms.assetid: bd18f673-4dda-4bc1-92fd-d1ce10074910
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 69b35d3007a26cd7ca605617b7441525f44ef3ca
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="c-enumeration-declarations"></a>Declarações de enumeração C
Uma enumeração consiste em um conjunto de constantes de número inteiro nomeadas. Uma declaração do tipo enumeração fornece o nome da marca da enumeração (opcional) e define o conjunto de identificadores de número inteiro nomeados (chamados de “conjunto de enumerações”, “constantes de enumerador”, "enumeradores” ou “membros”). Uma variável do tipo enumeração armazena um dos valores do conjunto de enumerações definido por esse tipo.  
  
 Variáveis do tipo `enum` podem ser usadas em expressões de indexação e como operandos de todos os operadores aritméticos e relacionais. As enumerações fornecem uma alternativa à política de pré-processador de `#define` com a vantagem de que os valores podem ser gerados para você e obedecer regras normais de escopo.  
  
 Em ANSI C, as expressões que definem o valor de uma constante de enumerador sempre têm o tipo `int`; assim, o armazenamento associado a uma variável de enumeração é o armazenamento exigido para um único valor de `int`. Uma constante de enumeração ou um valor do tipo enumerado podem ser usados em qualquer lugar em que a linguagem C permita uma expressão de inteiro.  
  
## <a name="syntax"></a>Sintaxe  
 *enum-specifier*:  
 **enum**  *identifier* opt**{** *enumerator-list* **}**  
  
 **enum**  *identifier*  
  
 O *identifier* opcional nomeia o tipo de enumeração definido por *enumerator-list*. Esse identificador é geralmente chamado de a "marca" de enumeração especificada pela lista. Um especificador de tipo no formato  
  
```  
  
enum  
identifier  
{  
enumerator-list  
}  
  
```  
  
 declara que *identifier* é a marca da enumeração especificada pelo não terminal *enumerator-list*. A *enumerator-list* define o "conteúdo do enumerador". A *enumerator-list* é descrita em detalhes a seguir.  
  
 Se a declaração de uma marca estiver visível, as declarações subsequentes que usam a marca, mas omitem *enumerator-list*, especificam o tipo enumerado declarado anteriormente. A marca deve se referir a um tipo definido da enumeração, e esse tipo de enumeração deve estar no escopo atual. Como o tipo de enumeração é definido em outro lugar, a *enumerator-list* não aparece nesta declaração. As declarações de tipos derivados das enumerações e as declarações `typedef` para tipos de enumeração podem usar a marca de enumeração antes que o tipo de enumeração seja definido.  
  
## <a name="syntax"></a>Sintaxe  
 *enumerator-list*:  
 *enumerator*  
  
 *enumerator-list* **,**  `enumerator`  
  
 `enumerator`:  
 *enumeration-constant*  
  
 *enumeration-constant*  **=**  *constant-expression*  
  
 *enumeration-constant*:  
 *identifier*  
  
 Cada *enumeration-constant* em uma *enumeration-list* nomeia um valor do conjunto de enumerações. Por padrão, a primeira *enumeration-constant* é associada ao valor 0. A próxima *enumeration-constant* na lista é associada ao valor de (*constant-expression* + 1 ), a menos que você a associe explicitamente a outro valor. O nome de uma *enumeration-constant* é equivalente ao seu valor.  
  
 Você pode usar *enumeration-constant = constant-expression* para substituir a sequência padrão dos valores. Portanto, se *enumeration-constant = constant-expression* aparece em *enumerator-list*, a *enumeration-constant* é associada ao valor especificado por *constant-expression*. A *constant-expression* deve ser do tipo `int` e pode ser negativa.  
  
 As regras a seguir se aplicam aos membros de um conjunto de enumerações:  
  
-   Um conjunto de enumerações pode conter valores duplicados de constantes. Por exemplo, você pode associar o valor 0 a dois identificadores diferentes, talvez nomeada `null` e `zero`, no mesmo conjunto.  
  
-   Os identificadores da lista de enumerações devem ser distintos de outros identificadores no mesmo escopo e com a mesma visibilidade, inclusive nomes de variável e identificadores comuns em outras listas da enumerações.  
  
-   As marcas de enumeração obedecem as regras normais de escopo. Elas devem ser distintas de outras marcas de enumerações, estruturas, e união com a mesma visibilidade.  
  
## <a name="examples"></a>Exemplos  
 Esses exemplos ilustram declarações de enumeração:  
  
```  
enum DAY            /* Defines an enumeration type    */  
{  
    saturday,       /* Names day and declares a       */  
    sunday = 0,     /* variable named workday with    */   
    monday,         /* that type                      */  
    tuesday,  
    wednesday,      /* wednesday is associated with 3 */  
    thursday,  
    friday  
} workday;  
```  
  
 O valor 0 é associado a `saturday` por padrão. O identificador `sunday` é explicitamente definido como 0. Os identificadores restantes recebem valores de 1 a 5 por padrão.  
  
 Neste exemplo, um valor do conjunto `DAY` é atribuído à variável `today`.  
  
```  
enum DAY today = wednesday;  
```  
  
 Observe que o nome de constante de enumeração é usado para atribuir o valor. Como o tipo de enumeração `DAY` foi declarado anteriormente, somente a marca de enumeração `DAY` é necessária.  
  
 Para atribuir explicitamente um valor inteiro a uma variável de tipo de dados enumerado, use uma conversão de tipo:  
  
```  
workday = ( enum DAY ) ( day_value - 1 );  
```  
  
 Essa conversão é recomendada em C, mas não é necessária.  
  
```  
enum BOOLEAN  /* Declares an enumeration data type called BOOLEAN */  
{  
    false,     /* false = 0, true = 1 */  
    true   
};   
  
enum BOOLEAN end_flag, match_flag; /* Two variables of type BOOLEAN */  
```  
  
 Essa declaração também pode ser especificada como  
  
```  
enum BOOLEAN { false, true } end_flag, match_flag;\  
```  
  
 ou como  
  
```  
enum BOOLEAN { false, true } end_flag;  
enum BOOLEAN match_flag;  
```  
  
 Um exemplo que usa essas variáveis pode ter esta aparência:  
  
```  
if ( match_flag == false )  
    {  
     .  
     .   /* statement */   
     .  
    }  
    end_flag = true;  
```  
  
 Os tipos de dados de enumerador sem nome também podem ser declarados. O nome do tipo de dados é omitido, mas as variáveis podem ser declaradas. A variável `response` é uma variável de tipo definida:  
  
```  
enum { yes, no } response;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Enumerações](../cpp/enumerations-cpp.md)