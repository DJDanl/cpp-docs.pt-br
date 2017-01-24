---
title: "Interpretando declaradores mais complexos | Microsoft Docs"
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
  - "declaradores complexos"
  - "interpretando declaradores complexos"
ms.assetid: dd5b7019-c86d-4645-a5cc-21f834de6f4a
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Interpretando declaradores mais complexos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode incluir qualquer declarador entre parênteses para especificar uma interpretação de um "declarador complexo" específico. Um declarador complexo é um identificador qualificado por mais de um modificador de função, matriz ou ponteiro.  Você pode aplicar várias combinações de modificadores de função, matriz e ponteiro a um único identificador.  Geralmente, `typedef` pode ser usado para simplificar declarações.  Consulte [Declarações de Typedef](../c-language/typedef-declarations.md).  
  
 Na interpretação de declaradores complexos, os colchetes e parênteses \(ou seja, os modificadores à direita do identificador\) têm precedência sobre os asteriscos \(modificadores à esquerda do identificador\).  Os colchetes e os parênteses têm a mesma precedência e são associados da esquerda para a direita.  Depois que o declarador for completamente interpretado, o especificador do tipo é aplicado como a última etapa.  Usando parênteses, você pode substituir a ordem padrão de associação e forçar uma interpretação específica.  No entanto, nunca use parênteses ao redor de um nome de identificador por si só.  Ele pode ser interpretado erradamente como uma lista de parâmetros.  
  
 Uma maneira simples de interpretar declaradores complexos é lê\-los de "dentro para fora" usando as quatro etapas a seguir:  
  
1.  Comece com o identificador e o procure pelos colchetes ou parênteses \(se houver\) diretamente à direita.  
  
2.  Interprete esses colchetes ou parênteses, então procure pelos asteriscos à esquerda.  
  
3.  Se você encontrar um parêntese direito em qualquer momento, retorne e aplique as regras 1 e 2 a todos os elementos entre parênteses.  
  
4.  Aplique o especificador do tipo.  
  
    ```  
    char *( *(*var)() )[10];  
     ^   ^  ^ ^ ^   ^    ^  
     7   6  4 2 1   3    5  
    ```  
  
 Neste exemplo, as etapas estão em ordem numérica e podem ser interpretadas da seguinte maneira:  
  
1.  O identificador `var` é declarado como  
  
2.  um ponteiro para  
  
3.  uma função que retorna  
  
4.  um ponteiro para  
  
5.  uma matriz de 10 elementos, que são  
  
6.  ponteiros para  
  
7.  os valores `char`.  
  
## Exemplos  
 Os exemplos a seguir ilustram outras instruções complexas e mostram como os parênteses podem afetar o significado de uma declaração.  
  
```  
int *var[5]; /* Array of pointers to int values */  
```  
  
 O modificador da matriz tem prioridade maior que o modificador do ponteiro, portanto, `var` é declarado como matriz.  O modificador do ponteiro se aplica ao tipo dos elementos da matriz; consequentemente, os elementos da matriz são ponteiros para os valores `int`.  
  
```  
int (*var)[5]; /* Pointer to array of int values */  
```  
  
 Nesta declaração para `var`, os parênteses dão ao modificador do ponteiro uma prioridade maior que o modificador de matriz e `var` é declarado como ponteiro para uma matriz de cinco valores `int`.  
  
```  
long *var( long, long ); /* Function returning pointer to long */  
```  
  
 Os modificadores da função também têm prioridade maior que os modificadores do ponteiro, portanto, esta declaração para `var` declara `var` como função que retorna um ponteiro para um valor **long**.  A função é declarada para pegar dois valores **long** como argumentos.  
  
```  
long (*var)( long, long ); /* Pointer to function returning long */  
```  
  
 Este exemplo é semelhante ao anterior.  Os parênteses dão ao modificador do ponteiro uma prioridade maior que o modificador da função e `var` é declarado como um ponteiro para uma função que retorna um valor **long**.  Além disso, a função pega dois argumentos **long**.  
  
```  
struct both       /* Array of pointers to functions */  
{                 /*   returning structures         */  
    int a;  
    char b;  
} ( *var[5] )( struct both, struct both );  
```  
  
 Os elementos de uma matriz não podem ser funções, mas esta declaração demonstra como declarar uma matriz dos ponteiros às funções.  Neste exemplo, `var` é declarado como uma matriz de cinco ponteiros para as funções que retornam estruturas com dois membros.  Os argumentos para as funções são declarados como duas estruturas com o mesmo tipo de estrutura, `both`.  Observe que os parênteses que cercam `*var[5]` são necessários.  Sem eles, a declaração é uma tentativa inválida de declarar uma matriz de funções, conforme mostrado abaixo:  
  
```  
/* ILLEGAL */  
struct both *var[5](struct both, struct both);  
```  
  
 A instrução a seguir declara uma matriz de ponteiros.  
  
```  
unsigned int *(* const *name[5][10] ) ( void );  
```  
  
 A matriz `name` tem 50 elementos organizados em uma matriz multidimensional.  Os elementos são ponteiros para um ponteiro que é uma constante.  Esse ponteiro constante aponta para uma função que não tem parâmetros e retorna um ponteiro para um tipo sem assinatura.  
  
 O exemplo a seguir é uma função que retorna um ponteiro para uma matriz de três valores **double**.  
  
```  
double ( *var( double (*)[3] ) )[3];  
```  
  
 Nesta declaração, uma função retorna um ponteiro para uma matriz, uma vez que as funções que retornam matrizes são inválidas.  Aqui, `var` é declarado uma função que retorna um ponteiro para uma matriz de três valores **double**.  A função `var` usa um argumento.  O argumento, como o valor de retorno, é um ponteiro para uma matriz de três valores **double**.  O tipo de argumento é determinado por um *declarador abstrato*complexo.  Os parênteses que delimitam o asterisco no tipo de argumento são necessários; sem eles, o tipo de argumento seria uma matriz de três ponteiros para os valores **double**.  Para obter uma discussão e exemplos de declaradores abstratos, consulte [Declaradores abstratos](../c-language/c-abstract-declarators.md).  
  
```  
union sign         /* Array of arrays of pointers */  
{                  /* to pointers to unions       */  
     int x;  
     unsigned y;  
} **var[5][5];  
```  
  
 Como mostra o exemplo acima, um ponteiro pode apontar para outro ponteiro e uma matriz pode conter matrizes como elementos.  Aqui, `var` é uma matriz de cinco elementos.  Cada elemento é uma matriz de cinco elementos de ponteiros para ponteiros para uniões com dois membros.  
  
```  
union sign *(*var[5])[5]; /* Array of pointers to arrays  
                             of pointers to unions        */  
```  
  
 Este exemplo mostra como a colocação de parênteses altera o significado da declaração.  Neste exemplo, `var` é uma matriz de cinco elementos de ponteiros para as matrizes de cinco elementos de ponteiros para uniões.  Para obter exemplos de como usar o `typedef` para evitar instruções complexas, consulte [Declarações de Typedef](../c-language/typedef-declarations.md).  
  
## Consulte também  
 [Declarações e tipos](../c-language/declarations-and-types.md)