---
title: Declarações typedef | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- declarations, typedef
- typedef declarations
- types [C], declarations
ms.assetid: e92a3b82-9269-4bc6-834a-6f431ccac83e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 192f7ab037362219261852cfdb0a5eac53e5df9f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32391646"
---
# <a name="typedef-declarations"></a>Declarações typedef
Uma declaração de typedef é uma declaração com typedef como a classe de armazenamento. O declarador se torna um novo tipo. Você pode usar declarações de typedef para construir nomes mais curtos ou significativos para os tipos já definidos por C ou para os tipos que você declarou. Os nomes de typedef permitem que você encapsule os detalhes da implementação que podem ser alterados.  
  
 Uma declaração de typedef é interpretada da mesma maneira que uma declaração de variável ou de função, mas o identificador, em vez de assumir o tipo especificado pela declaração, se tornará um sinônimo para o tipo.  
  
## <a name="syntax"></a>Sintaxe  
 `declaration`:  
 *declaration-specifiers init-declarator-list* opt **;**  
  
 *declaration-specifiers*:  
 *storage-class-specifier declaration-specifiers* opt  
  
 *type-specifier declaration-specifiers* opt  
  
 *type-qualifier declaration-specifiers* opt  
  
 *storage-class-specifier*:  
 `typedef`  
  
 *type-specifier*:  
 **void**  
  
 **char**  
  
 **short**  
  
 **int**  
  
 **long**  
  
 **float**  
  
 **double**  
  
 **signed**  
  
 **unsigned**  
  
 *struct-or-union-specifier*  
  
 *enum-specifier*  
  
 *typedef-name*  
  
 *typedef-name*:  
 *identifier*  
  
 Observe que uma declaração de typedef não cria tipos. Ela cria sinônimos para tipos existentes ou nomes para os tipos que podem ser especificados de outras formas. Quando um nome de typedef é usado como um especificador de tipo, ele pode ser combinado com determinados especificadores de tipo, mas não outros. Os modificadores aceitáveis incluem **const** e `volatile`.  
  
 Os nomes de typedef compartilham o namespace com identificadores comuns (consulte [Namespaces](../c-language/name-spaces.md) para obter mais informações). Portanto, um programa pode ter um nome de typedef e um identificador de escopo local com o mesmo nome. Por exemplo:  
  
```  
typedef char FlagType;  
  
int main()  
{  
}  
  
int myproc( int )  
{  
    int FlagType;  
}  
```  
  
 Ao declarar um identificador de escopo local com o mesmo nome de um typedef, ou ao declarar um membro de uma estrutura ou de uma união no mesmo escopo ou em um escopo interno, o especificador do tipo deverá ser especificado. Este exemplo ilustra essa restrição:  
  
```  
typedef char FlagType;  
const FlagType x;  
```  
  
 Para reutilizar o nome `FlagType` para um identificador, um membro da estrutura ou da união, o tipo deve ser fornecido:  
  
```  
const int FlagType;  /* Type specifier required */  
```  
  
 Não é suficiente indicar  
  
```  
const FlagType;      /* Incomplete specification */  
```  
  
 pois `FlagType` é tomado como parte do tipo, não como um identificador que redeclarado. Esta declaração é executada para ser uma declaração inválida como  
  
```  
int;  /* Illegal declaration */  
```  
  
 Você pode declarar qualquer tipo com typedef, incluindo o ponteiro, função e tipos de matriz. Você pode declarar um nome de typedef para um ponteiro para um tipo de estrutura ou união antes de definir o tipo da estrutura ou de união, contanto que a definição tenha a mesma visibilidade da declaração.  
  
 Os nomes de typedef podem ser usados para melhorar a legibilidade de código. As três declarações a seguir de `signal` especificam exatamente do mesmo tipo. O primeiro não usa os nomes de typedef.  
  
```  
typedef void fv( int ), (*pfv)( int );  /* typedef declarations */  
  
void ( *signal( int, void (*) (int)) ) ( int );  
fv *signal( int, fv * );   /* Uses typedef type */  
pfv signal( int, pfv );    /* Uses typedef type */  
```  
  
## <a name="examples"></a>Exemplos  
 Os exemplos a seguir ilustram as declarações de typedef:  
  
```  
typedef int WHOLE; /* Declares WHOLE to be a synonym for int */  
```  
  
 Observe que agora `WHOLE` pode ser usado em uma declaração variável, como `WHOLE i;` ou `const WHOLE i;`. No entanto, a declaração `long WHOLE i;` seria inválida.  
  
```  
typedef struct club   
{  
    char name[30];  
    int size, year;  
} GROUP;  
```  
  
 Essa instrução declara `GROUP` como um tipo de estrutura com três membros. Como uma marca de estrutura, `club`, também está especificada, o nome de typedef (`GROUP`) ou a marca de estrutura pode ser usadas em declarações. Você deve usar a palavra-chave da estrutura com a marca e não pode usar a palavra-chave da estrutura com o nome de typedef.  
  
```  
typedef GROUP *PG; /* Uses the previous typedef name   
                      to declare a pointer            */  
```  
  
 O tipo `PG` é declarado como um ponteiro para o tipo `GROUP`, que por sua vez é definido como um tipo de estrutura.  
  
```  
typedef void DRAWF( int, int );  
```  
  
 Esse exemplo fornece o tipo `DRAWF` para uma função que não retorna valor e que usa dois argumentos int. Isso significa, por exemplo, se a declaração  
  
```  
DRAWF box;   
```  
  
 for equivalente à declaração  
  
```  
void box( int, int );  
```  
  
## <a name="see-also"></a>Consulte também  


