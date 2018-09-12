---
title: Declarações de ponteiro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- pointer declarations
- declarations, pointers
- const keyword [C]
- pointers, declarations
ms.assetid: 8b3b7fc7-f44d-480d-b6f9-cebe4e5462a6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0f7e5f8933aabe36362938a23c28ed1cd562a579
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43205387"
---
# <a name="pointer-declarations"></a>Declarações de ponteiro
Uma "declaração de ponteiro" nomeia uma variável de ponteiro e especifica o tipo de objeto para o qual a variável aponta. Uma variável declarada como um ponteiro contém um endereço de memória.  
  
## <a name="syntax"></a>Sintaxe

*declarator*:  
&nbsp;&nbsp;&nbsp;&nbsp;*pointer*<sub>opt</sub> *direct-declarator*  

*direct-declarator*:  
&nbsp;&nbsp;&nbsp;&nbsp;*identifier*  
&nbsp;&nbsp;&nbsp;&nbsp;**(** *declarator* **)**  
&nbsp;&nbsp;&nbsp;&nbsp;*direct-declarator* **[** *constant-expression*<sub>opt</sub> **]**  
&nbsp;&nbsp;&nbsp;&nbsp;*direct-declarator* **(** *parameter-type-list* **)**  
&nbsp;&nbsp;&nbsp;&nbsp;*direct-declarator* **(** *identifier-list*<sub>opt</sub> **)**  

*pointer*:  
&nbsp;&nbsp;&nbsp;&nbsp;<strong>\*</strong> *type-qualifier-list*<sub>opt</sub>  
&nbsp;&nbsp;&nbsp;&nbsp;<strong>\*</strong> *type-qualifier-list*<sub>opt</sub> *pointer*  

*type-qualifier-list*:  
&nbsp;&nbsp;&nbsp;&nbsp;*type-qualifier*  
&nbsp;&nbsp;&nbsp;&nbsp;*type-qualifier-list* *type-qualifier*  
  
 O *type-specifier* informa o tipo de objeto, que pode ser qualquer tipo básico, de estrutura ou união. As variáveis de ponteiro também podem apontar para funções, matrizes e outros ponteiros. (Para obter informações sobre como declarar e interpretar tipos de ponteiro mais complexos, consulte [Interpretar declaradores mais complexos](../c-language/interpreting-more-complex-declarators.md).)  
  
 Ao tornar o *type-specifier* **nulo**, é possível atrasar a especificação do tipo ao qual o ponteiro se refere. Esse item é chamado de "ponteiro para **nulo**" e escrito como `void *`. Uma variável declarada como um ponteiro para *nulo* pode ser usada para apontar para um objeto de qualquer tipo. No entanto, para realizar a maioria das operações no ponteiro ou no objeto para o qual ele aponta, o tipo para o qual ele aponta deve ser explicitamente especificado para cada operação. (Variáveis do tipo **char** <strong>\*</strong> e do tipo **void** <strong>\*</strong> são compatíveis com a atribuição sem uma conversão de tipo.) Essa conversão pode ser realizada com uma conversão de tipo (consulte [Conversões de tipo](../c-language/type-cast-conversions.md) para obter mais informações).  
  
 O *type-qualifier* pode ser **const** ou **volatile** ou ambos. Eles especificam, respectivamente, que o ponteiro não pode ser modificado pelo programa em si (**const**) ou que o ponteiro pode ser legitimamente modificado por algum processo fora do controle do programa (**volatile**). (Consulte [Qualificadores de Tipo](../c-language/type-qualifiers.md) para obter mais informações sobre **const** e **volatile**.)  
  
 O *declarator* atribui um nome à variável e pode incluir um modificador de tipo. Por exemplo, se o *declarator* representa uma matriz, o tipo do ponteiro é modificado para ser um ponteiro para uma matriz.  
  
 Você pode declarar um ponteiro para uma estrutura, união ou tipo de enumeração antes de definir a estrutura, a união ou o tipo de enumeração. Você declara o ponteiro com a marca de estrutura ou de união, conforme mostrado nos exemplos abaixo. Essas declarações são permitidas porque o compilador não precisa saber o tamanho da estrutura ou da união para alocar espaço para a variável de ponteiro.  
  
## <a name="examples"></a>Exemplos  
 Os exemplos a seguir ilustram as declarações de ponteiro.  
  
```  
char *message; /* Declares a pointer variable named message */  
```  
  
 O ponteiro *message* aponta para uma variável com tipo **char**.  
  
```  
int *pointers[10];  /* Declares an array of pointers */  
```  
  
 A matriz *pointers* tem 10 elementos; cada elemento é um ponteiro para uma variável com tipo **int**.  
  
```  
int (*pointer)[10]; /* Declares a pointer to an array of 10 elements */  
```  
  
 A variável *pointer* aponta para uma matriz com 10 elementos. Cada elemento desta matriz tem o tipo **int**.  
  
```  
int const *x;      /* Declares a pointer variable, x,  
                      to a constant value */   
```  
  
 O ponteiro *x* pode ser modificado para apontar para outro valor **int**, mas o valor para o qual ele aponta não pode ser modificado.  
  
```  
const int some_object = 5 ;  
int other_object = 37;  
int *const y = &fixed_object;  
int volatile *const z = &some_object;  
int *const volatile w = &some_object;  
```  
  
 A variável *y* dessas declarações é declarada como um ponteiro constante para um valor **int**. O valor para o qual ele aponta pode ser modificado, mas o ponteiro em si deve sempre apontar para o mesmo local: o endereço de *fixed_object*. De forma semelhante, *z* é um ponteiro constante, mas também é declarado para apontar para um **int** cujo valor não pode ser modificado pelo programa. O especificador adicional **volatile** indica que, embora o valor de **const int** apontado por *z* não possa ser modificado pelo programa, pode ser modificado de modo legítimo por um processo executado simultaneamente com o programa. A declaração de *w* especifica que o programa não pode alterar o valor para o qual está apontado e que o programa não pode modificar o ponteiro.  
  
```  
struct list *next, *previous; /* Uses the tag for list */  
```  
  
 Este exemplo declara duas variáveis de ponteiro, *next* e *previous*, que apontam para a o tipo de estrutura *list*. Essa declaração pode aparecer antes da definição do tipo de estrutura *list* (consulte o próximo exemplo), desde que a definição de tipo *list* tenha a mesma visibilidade que a declaração.  
  
```  
struct list   
{  
    char *token;  
    int count;  
    struct list *next;  
} line;  
```  
  
 A variável *line* tem o tipo de estrutura chamado *list*. O tipo da estrutura *list* tem três membros: o primeiro membro é um ponteiro para um valor **char**, o segundo é um valor **int** e o terceiro é um ponteiro para uma outra estrutura *list*.  
  
```  
struct id   
{  
    unsigned int id_no;  
    struct name *pname;  
} record;  
```  
  
 A variável *record* tem o tipo de estrutura chamado *id*. Observe que *pname* é declarado como um ponteiro para outro tipo de estrutura chamado *name*. Essa declaração pode aparecer antes que o tipo *name* seja definido.  
  
## <a name="see-also"></a>Consulte também  
 [Declaradores e declarações de variável](../c-language/declarators-and-variable-declarations.md)