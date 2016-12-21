---
title: "Declara&#231;&#245;es de estrutura | Microsoft Docs"
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
  - "declarações de estrutura"
  - "estruturas anônimas"
  - "tipos [C], declarações"
  - "membros de estrutura"
  - "estruturas inseridas"
ms.assetid: 5be3be77-a236-4153-b574-7aa77675df7f
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Declara&#231;&#245;es de estrutura
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma "declaração de estrutura" nomeia um tipo e especifica uma seqüência de valores de variáveis \(chamados de "membros" ou "campos" da estrutura\) que podem ter tipos diferentes. Um identificador opcional, chamado de "marca", fornece o nome do tipo de estrutura e pode ser usado em referências subsequentes para o tipo de estrutura. Uma variável desse tipo de estrutura contém a sequência inteira definida por esse tipo. Estruturas em C são semelhantes aos tipos conhecidos como "registros" em outros idiomas.  
  
## Sintaxe  
 *especificador de estrutura ou união*:  
 *Identificador de estrutura ou união* aceitação**{** *struct\-declaration\-list* **}**  
  
 *Identificador de estrutura ou união*  
  
 *estrutura ou união*:  
 **struct**  
  
 **union**  
  
 *struct\-declaration\-list*:  
 *declaração de estrutura*  
  
 *declaração de struct struct\-declaration\-list*  
  
 O conteúdo da estrutura é definido para ser  
  
 *declaração struct*:  
 *especificador de qualificador de lista struct\-declarator\-list*  **;**  
  
 *especificador\-qualifier\-list*:  
 *especificador de tipo especificador\-qualifier\-list* aceitação  
  
 *qualificador de tipo especificador\-qualifier\-list* aceitação  
  
 *lista de declaradores struct*:  
 *Declarador de estrutura*  
  
 *lista de declaradores struct*  **,**  *Declarador de estrutura*  
  
 *struct declarador*:  
 `declarator`  
  
 A declaração de um tipo de estrutura não reservar espaço para uma estrutura. É apenas um modelo para declarações posteriores de variáveis de estrutura.  
  
 Um definido anteriormente *identificador* \(tag\) pode ser usado para se referir a um tipo de estrutura definido em outro lugar. Nesse caso, *struct\-declaration\-list* não pode ser repetido, desde a definição é visível. Declarações de ponteiros para estruturas e typedefs de tipos de estrutura podem usar a marca de estrutura antes que o tipo de estrutura seja definido. No entanto, a definição da estrutura deve ser encontrada antes de qualquer uso real do tamanho dos campos. Isso é uma definição incompleta do tipo e a marca de tipo. Para essa definição ser concluída, uma definição de tipo deve aparecer depois no mesmo escopo.  
  
 O *struct\-declaration\-list* Especifica os tipos e nomes de membros da estrutura. Um *struct\-declaration\-list* argumento contiver uma variável ou mais declarações de campo de bits.  
  
 Cada variável declarada em *struct\-declaration\-list* é definido como um membro do tipo de estrutura. Declarações de variável em *struct\-declaration\-list* possuem a mesma forma que outras declarações de variáveis discutidas nesta seção, exceto que as declarações não podem conter inicializadores ou especificadores de classe de armazenamento. Os membros de estrutura podem ter qualquer tipo exceto o tipo de variável `void`, um tipo incompleto ou um tipo de função.  
  
 Um membro não pode ser declarado para ter o tipo da estrutura na qual ele aparece. No entanto, um membro pode ser declarado como um ponteiro para o tipo de estrutura em que aparece, desde que o tipo de estrutura tem uma marca. Isso permite que você crie listas vinculadas de estruturas.  
  
 As estruturas seguem o mesmo escopo que outros identificadores. Os identificadores de estruturas devem ser distintos de outra estrutura, união e marcas enumeração com a mesma visibilidade.  
  
 Cada *declaração struct* em uma *struct\-declaration\-list* deve ser exclusivo dentro da lista. No entanto, os nomes de identificadores em uma *struct\-declaration\-list* não precisam ser distintos de nomes de variáveis comuns ou de identificadores em outras listas de declaração de estrutura.  
  
 Estruturas aninhadas também podem ser acessadas como se fossem declaradas no nível de escopo de arquivo. Por exemplo, dada esta declaração:  
  
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
  
 Essas duas declarações são válidas:  
  
```  
struct a var3;  
struct b var4;  
```  
  
## Exemplos  
 Estes exemplos ilustram declarações de estrutura:  
  
```  
struct employee   /* Defines a structure variable named temp */  
{  
    char name[20];  
    int id;  
    long class;  
} temp;  
```  
  
 O `employee` estrutura tem três membros: `name`, `id`, e `class`. O `name` membro é uma matriz de 20 elementos, e `id` e `class` são membros simples `int` e **longo** digite, respectivamente. O identificador de `employee` é o identificador da estrutura.  
  
```  
struct employee student, faculty, staff;  
```  
  
 Este exemplo define três variáveis de estrutura: `student`, `faculty`, e `staff`. Cada estrutura tem a mesma lista de três membros. Os membros são declarados com o tipo de estrutura `employee`, definida no exemplo anterior.  
  
```  
struct           /* Defines an anonymous struct and a */  
{                /* structure variable named complex  */  
    float x, y;  
} complex;  
```  
  
 O `complex` estrutura tem dois membros **float** tipo, `x` e `y`. O tipo de estrutura não tem nenhuma marca e, portanto, não nomeado ou anônimo.  
  
```  
struct sample   /* Defines a structure named x */  
{  
    char c;  
    float *pf;  
    struct sample *next;  
} x;  
```  
  
 Os dois primeiros membros da estrutura são uma `char` variável e um ponteiro para um **float** valor. O terceiro membro, `next`, é declarado como um ponteiro para o tipo de estrutura que está sendo definido \(`sample`\).  
  
 Estruturas anônimas podem ser úteis quando a marca nomeada não é necessária. Esse é o caso quando uma declaração define todas as instâncias de estrutura. Por exemplo:  
  
```  
struct  
{  
    int x;  
    int y;  
} mystruct;  
```  
  
 Estruturas inseridas são frequentemente anônimas.  
  
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
  
 **Específico da Microsoft**  
  
 O compilador permite uma matriz sem tamanho ou tamanho zero como o último membro de uma estrutura. Isso pode ser útil se o tamanho de uma matriz constante diferente quando usado em várias situações. A declaração de uma estrutura tem esta aparência:  
  
 `struct` *identificador***{** *conjunto de declarações* *Digite o nome da matriz***\[\];};**  
  
 Matrizes sem dimensões podem aparecer somente como o último membro de uma estrutura. Estruturas que contêm declarações de matriz não dimensionada podem ser aninhadas dentro de outras estruturas, desde que nenhum membro adicional seja declarado em qualquer das estruturas de inclusão. Matrizes dessas estruturas não são permitidas. O `sizeof` operador, quando aplicada a uma variável desse tipo ou o próprio tipo, pressupõe 0 para o tamanho da matriz.  
  
 Declarações de estrutura também podem ser especificadas sem um declarador quando são membros de outra estrutura ou união. Os nomes dos campos são promovidos na estrutura de inclusão. Por exemplo, uma estrutura sem nome tem esta aparência:  
  
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
  
 Consulte [membros de união e estrutura](../c-language/structure-and-union-members.md) para obter informações sobre referências de estrutura.  
  
 **FIM de específico da Microsoft**  
  
## Consulte também  
 [Declaradores e declarações variáveis](../c-language/declarators-and-variable-declarations.md)