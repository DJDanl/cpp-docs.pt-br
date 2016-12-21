---
title: "Declara&#231;&#245;es de ponteiro | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "palavra-chave const [C]"
  - "declarações, ponteiros"
  - "declarações de ponteiro"
  - "ponteiros, declarações"
ms.assetid: 8b3b7fc7-f44d-480d-b6f9-cebe4e5462a6
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Declara&#231;&#245;es de ponteiro
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma "declaração de ponteiro" nomeia uma variável de ponteiro e especifica o tipo de objeto para o qual a variável aponta.  Uma variável declarada como um ponteiro contém um endereço de memória.  
  
## Sintaxe  
 `declarator`:  
 `pointer` opt *direct\-declarator*  
  
 *direct\-declarator*:  
 *identifier*  
  
 **\(**  *declarator*  **\)**  
  
 *direct\-declarator*  **\[**  *constant\-expression* opt **\]**  
  
 *direct\-declarator*  **\(**  *parameter\-type\-list*  **\)**  
  
 *direct\-declarator*  **\(**  *identifier\-list* opt **\)**  
  
 `pointer`:  
 **\*** *type\-qualifier\-list* opt  
  
 **\*** *type\-qualifier\-list* opt `pointer`  
  
 *type\-qualifier\-list*:  
 *type\-qualifier*  
  
 *type\-qualifier\-list type\-qualifier*  
  
 O *type\-specifier* informa o tipo de objeto, que pode ser qualquer tipo básico, de estrutura ou união.  As variáveis de ponteiro também podem apontar para funções, matrizes e outros ponteiros. \(Para obter informações sobre como declarar e interpretar tipos de ponteiro mais complexos, consulte [Interpretando declaradores mais complexos](../c-language/interpreting-more-complex-declarators.md).\)  
  
 Ao fazer o *type\-specifier* `void`, você pode atrasar a especificação do tipo ao qual o ponteiro se refere.  Esse item é chamado de "ponteiro para `void`" e escrito como `void *`.  Uma variável declarada como um ponteiro para `void` pode ser usada para apontar para um objeto de qualquer tipo.  No entanto, para realizar a maioria das operações no ponteiro ou no objeto para o qual ele aponta, o tipo para o qual ele aponta deve ser explicitamente especificado para cada operação. \(Variáveis do tipo **char \*** e do tipo **void \*** são compatíveis com a atribuição sem uma conversão de tipo.\) Essa conversão pode ser realizada com uma conversão de tipo \(consulte [Conversões de tipo](../c-language/type-cast-conversions.md) para obter mais informações\).  
  
 O *type\-qualifier* pode ser **const**, `volatile` ou ambos.  Eles especificam, respectivamente, que o ponteiro não pode ser modificado pelo programa em si \(**const**\) ou que o ponteiro pode ser legitimamente modificado por algum processo além do controle do programa \(`volatile`\). \(Consulte [Qualificadores de tipo](../c-language/type-qualifiers.md) para obter mais informações sobre **const** e `volatile`.\)  
  
 O `declarator` atribui um nome à variável e pode incluir um modificador de tipo.  Por exemplo, se o `declarator` representa uma matriz, o tipo do ponteiro é modificado para ser um ponteiro para uma matriz.  
  
 Você pode declarar um ponteiro para uma estrutura, união ou tipo de enumeração antes de definir a estrutura, a união ou o tipo de enumeração.  Você declara o ponteiro com a marca de estrutura ou de união, conforme mostrado nos exemplos abaixo.  Essas declarações são permitidas porque o compilador não precisa saber o tamanho da estrutura ou da união para alocar espaço para a variável de ponteiro.  
  
## Exemplos  
 Os exemplos a seguir ilustram as declarações de ponteiro.  
  
```  
char *message; /* Declares a pointer variable named message */  
```  
  
 O ponteiro `message` aponta para uma variável com tipo `char`.  
  
```  
int *pointers[10];  /* Declares an array of pointers */  
```  
  
 A matriz `pointers` tem 10 elementos; cada elemento é um ponteiro para uma variável com tipo `int`.  
  
```  
int (*pointer)[10]; /* Declares a pointer to an array of 10 elements */  
```  
  
 A variável de ponteiro aponta para uma matriz com 10 elementos.  Cada elemento desta matriz tem o tipo `int`.  
  
```  
int const *x;      /* Declares a pointer variable, x,  
                      to a constant value */   
```  
  
 O ponteiro `x` pode ser modificado para apontar para outro valor `int`, mas o valor para o qual ele aponta não pode ser modificado.  
  
```  
const int some_object = 5 ;  
int other_object = 37;  
int *const y = &fixed_object;  
int volatile *const z = &some_object;  
int *const volatile w = &some_object;  
```  
  
 A variável `y` dessas declarações é declarada como um ponteiro constante para um valor `int`.  O valor para o qual ele aponta pode ser modificado, mas o ponteiro em si deve sempre apontar para o mesmo local: o endereço de `fixed_object`.  De forma semelhante, `z` é um ponteiro constante, mas também é declarado para apontar para um `int` cujo valor não pode ser modificado pelo programa.  O especificador adicional `volatile` indica que, embora o valor de **const int** apontado por `z` não possa ser modificado pelo programa, ele pode ser modificado de modo legítimo por um processo executado simultaneamente com o programa.  A declaração de `w` especifica que o programa não pode alterar o valor para o qual está apontado e que o programa não pode modificar o ponteiro.  
  
```  
struct list *next, *previous; /* Uses the tag for list */  
```  
  
 Este exemplo declara duas variáveis de ponteiro, `next` e `previous`, que apontam para o tipo de estrutura `list`.  Essa declaração pode aparecer antes da definição do tipo de estrutura `list` \(consulte o próximo exemplo\), desde que a definição de tipo `list` tenha a mesma visibilidade que a declaração.  
  
```  
struct list   
{  
    char *token;  
    int count;  
    struct list *next;  
} line;  
```  
  
 A variável `line` tem o tipo de estrutura chamado `list`.  O tipo da estrutura `list` tem três membros: o primeiro membro é um ponteiro para um valor `char`, o segundo é um valor `int` e o terceiro é um ponteiro para uma outra estrutura `list`.  
  
```  
struct id   
{  
    unsigned int id_no;  
    struct name *pname;  
} record;  
```  
  
 A variável `record` tem o tipo de estrutura `id`.  `pname` é declarado como um ponteiro para outro tipo de estrutura chamado `name`.  Essa declaração pode aparecer antes que o tipo `name` seja definido.  
  
## Consulte também  
 [Declaradores e declarações variáveis](../c-language/declarators-and-variable-declarations.md)