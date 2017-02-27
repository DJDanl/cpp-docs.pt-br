---
title: "Declarações de estrutura | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- structure declarations
- anonymous structures
- types [C], declarations
- structure members
- embedded structures
ms.assetid: 5be3be77-a236-4153-b574-7aa77675df7f
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 69de9f2c7d45608e54a78a3dcfcadba67bf7157e

---
# <a name="structure-declarations"></a>Declarações de estrutura
Uma "declaração de estrutura" nomeia um tipo e especifica uma sequência de valores variáveis (chamados de "membros" ou "campos" da estrutura) que podem ter tipos diferentes. Um identificador opcional, chamado de "marca", fornece o nome do tipo de estrutura e pode ser usado em referências subsequentes ao tipo. Uma variável desse tipo de estrutura mantém a sequência inteira definida por esse tipo. As estruturas em C são semelhantes aos tipos conhecidos como "registros" em outras linguagens.  
  
## <a name="syntax"></a>Sintaxe  
 *struct-or-union-specifier*:  
 *struct-or-union identifier* opt**{** *struct-declaration-list* **}**  
  
 *struct-or-union identifier*  
  
 *struct-or-union*:  
 **struct**  
  
 **union**  
  
 *struct-declaration-list*:  
 *struct-declaration*  
  
 *struct-declaration-list struct-declaration*  
  
 O conteúdo da estrutura é definido para ser  
  
 *struct-declaration*:  
 *specifier-qualifier-list struct-declarator-list*  **;**  
  
 *specifier-qualifier-list*:  
 *type-specifier specifier-qualifier-list* opt  
  
 *type-qualifier specifier-qualifier-list* opt  
  
 *struct-declarator-list*:  
 *struct-declarator*  
  
 *struct-declarator-list*  **,**  *struct-declarator*  
  
 *struct-declarator*:  
 `declarator`  
  
 A declaração de um tipo de estrutura não reserva espaço para uma estrutura. É apenas um modelo para declarações posteriores de variáveis da estrutura.  
  
 Um *identifier* (marca) definido anteriormente pode ser usado para fazer referência a um tipo de estrutura definido em outro lugar. Nesse caso, *struct-declaration-list* não poderá ser repetida enquanto a definição estiver visível. Declarações de ponteiros para estruturas e typedefs de tipos de estrutura podem usar a marca de estrutura antes que o tipo de estrutura seja definido. No entanto, a definição da estrutura deve ser encontrada antes de qualquer uso real do tamanho dos campos. Essa é uma definição incompleta do tipo e da marca de tipo. Para que essa definição fique completa, uma definição de tipo deve aparecer depois no mesmo escopo.  
  
 A *struct-declaration-list* especifica os tipos e nomes dos membros da estrutura. Um argumento *struct-declaration-list* contém uma ou mais declarações de variável ou de campo de bits.  
  
 Cada variável declarada em *struct-declaration-list* é definida como um membro do tipo de estrutura. As declarações de variáveis em *struct-declaration-list* têm o mesmo formato que outras declarações de variável abordadas nesta seção, com exceção de que as declarações não podem conter inicializadores nem especificadores de classe de armazenamento. Os membros da estrutura podem ter qualquer tipo de variável, exceto o tipo `void`, um tipo incompleto ou um tipo de função.  
  
 Um membro não pode ser declarado para ter o tipo da estrutura em que aparece. Porém, um membro pode ser declarado como um ponteiro para o tipo de estrutura em que aparece, desde que o tipo tenha uma marca. Isso permite criar listas vinculadas de estruturas.  
  
 As estruturas seguem o mesmo escopo que outros identificadores. Os identificadores de estruturas devem ser distintos de outras marcas de estrutura, união e enumeração com a mesma visibilidade.  
  
 Cada *struct-declaration* em uma *struct-declaration-list* deve ser exclusivo na lista. No entanto, os nomes de identificadores em uma *struct-declaration-list* não precisam ser distintos de nomes de variáveis comuns ou de identificadores em outras listas de declarações de estrutura.  
  
 Também é possível acessar estruturas aninhadas como se fossem declaradas no nível do escopo do arquivo. Por exemplo, dada esta declaração:  
  
```  
struct a  
{  
    int x;  
    struct b  
    {  
      int y;  
    } var2;  
} var1;  
```  
  
 estas duas declarações são válidas:  
  
```  
struct a var3;  
struct b var4;  
```  
  
## <a name="examples"></a>Exemplos  
 Estes exemplos ilustram declarações de estruturas:  
  
```  
struct employee   /* Defines a structure variable named temp */  
{  
    char name[20];  
    int id;  
    long class;  
} temp;  
```  
  
 A estrutura `employee` tem três membros: `name`, `id` e `class`. O membro `name` é uma matriz de 20 elementos e `id` e `class` são membros simples com o tipo `int` e **long**, respectivamente. O identificador `employee` é o identificador da estrutura.  
  
```  
struct employee student, faculty, staff;  
```  
  
 Esse exemplo define três variáveis de estrutura: `student`, `faculty` e `staff`. Cada estrutura tem a mesma lista de três membros. Os membros são declarados para ter o tipo de estrutura `employee`, definido no exemplo anterior.  
  
```  
struct           /* Defines an anonymous struct and a */  
{                /* structure variable named complex  */  
    float x, y;  
} complex;  
```  
  
 A estrutura `complex` tem dois membros do tipo **float**, `x` e `y`. O tipo de estrutura não tem marcas e, portanto, é não nomeado ou anônimo.  
  
```  
struct sample   /* Defines a structure named x */  
{  
    char c;  
    float *pf;  
    struct sample *next;  
} x;  
```  
  
 Os dois primeiros membros da estrutura são uma variável `char` e um ponteiro para um valor **float**. O terceiro membro, `next`, é declarado como um ponteiro para o tipo de estrutura que está sendo definido (`sample`).  
  
 As estruturas anônimas podem ser úteis quando a marca nomeada não é necessária. Esse é o caso quando uma declaração define todas as instâncias da estrutura. Por exemplo:  
  
```  
struct  
{  
    int x;  
    int y;  
} mystruct;  
```  
  
 As estruturas inseridas são frequentemente anônimas.  
  
```  
struct somestruct  
{  
    struct    /* Anonymous structure */  
    {  
        int x, y;  
    } point;  
    int type;  
} w;  
```  
  
 **Seção específica da Microsoft**  
  
 O compilador permite uma matriz não dimensionada ou de tamanho zero como o último membro de uma estrutura. Isso poderá ser útil se uma matriz constante tiver tamanhos diferentes quando usada em situações variadas. A declaração de uma estrutura assim é semelhante a esta:  
  
 `struct` *identifier***{** *set-of-declarations* *type array-name***[ ];};**  
  
 As matrizes não dimensionadas só podem aparecer como o último membro de uma estrutura. As estruturas que contêm declarações de matrizes não dimensionadas podem ser aninhadas em outras estruturas, desde que nenhum membro adicional seja declarado em nenhuma das estruturas de inclusão. Matrizes dessas estruturas não são permitidas. O operador `sizeof`, quando aplicado a uma variável desse tipo ou ao próprio tipo, pressupõe 0 como o tamanho da matriz.  
  
 Declarações de estruturas também podem ser especificadas sem um declarador quando são membros de outra estrutura ou união. Os nomes de campos são promovidos na estrutura de inclusão. Por exemplo, uma estrutura sem nome tem aparência semelhante a esta:  
  
```  
struct s  
{  
    float y;  
    struct  
    {  
        int a, b, c;  
    };  
    char str[10];  
} *p_s;  
.  
.  
.  
p_s->b = 100;  /* A reference to a field in the s structure */  
```  
  
 Consulte [Membros de estruturas e uniões](../c-language/structure-and-union-members.md) para obter informações sobre referências de estrutura.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Declaradores e declarações de variável](../c-language/declarators-and-variable-declarations.md)


<!--HONumber=Feb17_HO4-->


