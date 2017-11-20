---
title: Especificadores de tipo C | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- type specifiers, C
- specifiers, type
ms.assetid: fbe13441-04c3-4829-b047-06d374adc2b6
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 78cd6292c97f41cb7e862389113404346da80460
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="c-type-specifiers"></a>Especificadores de tipo C
Os especificadores de tipo em declarações definem o tipo de uma declaração de função ou variável.  
  
## <a name="syntax"></a>Sintaxe  
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
  
 Os tipos **signed char**, **signed int**, **signed short int** e **signed long int**, junto com suas contrapartes `unsigned` e `enum`, são chamados de tipos “integrais”. Os especificadores de tipo **float**, **double** e `long double` são chamados de "flutuantes" ou tipos de "ponto flutuante". Você pode usar qualquer especificador do tipo integral ou de ponto flutuante em uma declaração de variável ou função. Se um *especificador de tipo* não for fornecido em uma declaração, será tomado como `int`.  
  
 As palavras-chave opcionais **signed** e `unsigned` podem vir antes ou depois de qualquer um dos tipos integrais, exceto `enum`, e também podem ser usadas separadamente, como especificadores do tipo. Nesse caso, são entendidas como **signed int** e `unsigned int`, respectivamente. Quando usada sozinha, a palavra-chave `int` é considerada como **signed**. Quando usadas isoladamente, as palavras-chave **long** e **short** são entendidas como **long int** e `short int`.  
  
 Os tipos de enumeração são considerados tipos básicos. Os especificadores de tipo para tipos de enumeração são discutidos em [Declarações de enumeração](../c-language/c-enumeration-declarations.md).  
  
 A palavra-chave `void` tem três usos: especificar um tipo de retorno da função, especificar uma lista de tipo de argumento para uma função que não leve argumentos e especificar um ponteiro para um tipo não especificado. Você pode usar o tipo de `void` para declarar as funções que não retornam nenhum valor ou para declarar um ponteiro para um tipo não especificado. Consulte [Argumentos](../c-language/arguments.md) para obter informações sobre `void` quando é exibido sozinho dentro dos parênteses depois de um nome de função.  
  
 **Seção específica da Microsoft**  
  
 A verificação de tipo agora está em conformidade com ANSI, o que significa que o tipo **short** e o tipo `int` são tipos distintos. Por exemplo, esta é uma redefinição do compilador do Microsoft C que foi aceita por versões anteriores do compilador.  
  
```  
int   myfunc();  
short myfunc();  
```  
  
 O exemplo a seguir também gerencia um aviso sobre a ação indireta a diferentes tipos:  
  
```  
int *pi;  
short *ps;  
  
ps = pi;  /* Now generates warning */  
```  
  
 O compilador do Microsoft C também gerencia avisos para as diferenças no sinal. Por exemplo:  
  
```  
signed int *pi;  
unsigned int *pu  
  
pi = pu;  /* Now generates warning */  
```  
  
 As expressões do tipo `void` são avaliadas quanto a efeitos colaterais. Você não pode usar o valor (inexistente) de uma expressão que tem o tipo `void` em qualquer modo, nem pode converter uma expressão `void` (por conversão implícita ou explícita) em qualquer tipo exceto `void`. Se você usar uma expressão de qualquer outro tipo em um contexto onde a expressão `void` é necessária, seu valor será descartado.  
  
 Para estar em conformidade com a especificação de ANSI, **void\*\*** não pode ser usado como **int\*\***. Somente **void\*** pode ser usado como um ponteiro para um tipo não especificado.  
  
 **Fim da seção específica da Microsoft**  
  
 Você pode criar especificadores de tipo adicionais com as declarações `typedef`, conforme descrito em [Declarações de Typedef](../c-language/typedef-declarations.md). Consulte [Armazenamento de tipos básicos](../c-language/storage-of-basic-types.md) para obter informações sobre o tamanho de cada tipo.  
  
## <a name="see-also"></a>Consulte também  
 [Declarações e tipos](../c-language/declarations-and-types.md)