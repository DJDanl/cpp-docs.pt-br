---
title: "Declarações de união | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- unions
- union keyword [C], declarations
- variant records
ms.assetid: 978c6165-e0ae-4196-afa7-6d94e24f62f7
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 4088aea4025e7c51aba75efe28978d05c0e48730
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="union-declarations"></a>Declarações de união
Uma "declaração de união" especifica um conjunto de valores de variáveis e, opcionalmente, uma tag que nomeia a união. Os valores de variáveis são chamados de “membros” da união e podem ter tipos diferentes. Uniões são semelhantes a "registros variantes" em outras linguagens.  
  
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
  
 O conteúdo da união é definido para ser  
  
 *struct-declaration*:  
 *specifier-qualifier-list struct-declarator-list*  **;**  
  
 *specifier-qualifier-list*:  
 *type-specifier specifier-qualifier-list* opt  
  
 *type-qualifier specifier-qualifier-list* opt  
  
 *struct-declarator-list*:  
 *struct-declarator*  
  
 *struct-declarator-list*  **,**  *struct-declarator*  
  
 Uma variável com tipo **union** armazena um dos valores definidos por esse tipo. As mesmas regras controlam declarações da estrutura e de união. Uniões também podem ter campos de bits.  
  
 Os membros de uniões não podem ter um tipo incompleto, o tipo `void`, tipo de função. Portanto, os membros não podem ser uma instância de união, mas podem ser ponteiros ao tipo de união que está sendo declarado.  
  
 Uma declaração de tipo de união é somente um modelo. A memória não é reservada até que a variável seja declarada.  
  
> [!NOTE]
>  Se uma união de dois tipos é declarada e um valor é armazenado, mas a união é acessada com o outro tipo, os resultados são não confiáveis. Por exemplo, uma união de **float** e `int` é declarada. Um valor **float** é armazenado, mas o programa acessa posteriormente o valor como `int`. Nessa situação, o valor dependeria do armazenamento interno de valores **float**. O valor inteiro não seria confiável.  
  
## <a name="examples"></a>Exemplos  
 Veja a seguir alguns exemplos de uniões:  
  
```  
union sign   /* A definition and a declaration */  
{  
    int svar;  
    unsigned uvar;  
} number;  
```  
  
 Este exemplo define uma variável de união com tipo `sign` e declara uma variável nomeada `number` que tem dois membros: `svar`, um inteiro assinado, e `uvar`, um inteiro sem sinal. Esta declaração permite que o valor atual de `number` seja armazenado como um valor assinado ou não assinado. A marca associada a esse tipo de união é `sign`.  
  
```  
union               /* Defines a two-dimensional */  
{                   /*  array named screen */  
    struct      
    {   
      unsigned int icon : 8;    
      unsigned color : 4;  
    } window1;  
    int screenval;  
} screen[25][80];  
```  
  
 A matriz `screen` contém 2.000 elementos. Cada elemento da matriz é uma união individual com dois membros: `window1` e `screenval`. O membro `window1` é uma estrutura com dois membros de campos de bits, `icon` e `color`. O membro `screenval` é um `int`. Em um determinado momento, cada elemento da união mantém `int` representada por `screenval` ou a estrutura representada por `window1`.  
  
 **Seção específica da Microsoft**  
  
 Uniões aninhadas podem ser declaradas anonimamente quando são membros de outra estrutura ou união. Este é um exemplo de uma união sem nome:  
  
```  
struct str  
{  
    int a, b;  
    union            / * Unnamed union */  
    {  
      char c[4];  
      long l;  
      float f;  
   };  
   char c_array[10];  
} my_str;  
.  
.  
.  
my_str.l == 0L;  /* A reference to a field in the my_str union */  
```  
  
 Uniões frequentemente são aninhadas em uma estrutura que inclui um campo que fornece o tipo de dados contido na união de qualquer horário específico. Este é um exemplo de uma declaração para essa união:  
  
```  
struct x  
{  
    int type_tag;  
    union  
    {  
      int x;  
      float y;  
    }  
}  
```  
  
 Consulte [Membros de estruturas e uniões](../c-language/structure-and-union-members.md) para obter informações sobre uniões de referência.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Declaradores e declarações de variável](../c-language/declarators-and-variable-declarations.md)