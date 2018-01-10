---
title: "Concatenação literal da cadeia de caracteres | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- concatenating strings
- strings [C++], concatenating
ms.assetid: 51486b1f-4b1e-4061-9add-1aa38c6cdb3c
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: de245a061ed7d269aaafc856df0a422e31fd6d77
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="string-literal-concatenation"></a>Concatenação literal da cadeia de caracteres
Para formar literais de cadeia de caracteres que ocupam mais de uma linha, você pode concatenar duas cadeias de caracteres. Para fazer isso, digite uma barra invertida e pressione a tecla RETURN. A barra invertida faz com que o compilador ignore o próximo caractere de nova linha. Por exemplo, o literal de cadeia de caracteres  
  
```  
"Long strings can be bro\  
ken into two or more pieces."  
```  
  
 é idêntico à cadeia de caracteres  
  
```  
"Long strings can be broken into two or more pieces."  
```  
  
 A concatenação de cadeias de caracteres pode ser usada em qualquer lugar em que você usou anteriormente uma barra invertida seguida por um caractere de nova linha para inserir cadeias de caracteres mais longas que uma linha.  
  
 Para forçar uma nova linha dentro de uma literal de cadeia de caracteres, digite a sequência de escape de nova linha (**\n**) no ponto na cadeia de caracteres em que você deseja que a linha seja interrompida, como mostrado a seguir:  
  
```  
"Enter a number between 1 and 100\nOr press Return"  
```  
  
 Como as cadeias de caracteres podem começar em qualquer coluna do código-fonte e as cadeias de caracteres longas podem ser retomadas em qualquer coluna de uma linha sucessora, você pode posicionar as cadeias de caracteres para aumentar a legibilidade do código-fonte. Em ambos os casos, sua representação na tela resultante não é afetada. Por exemplo:  
  
```  
printf_s ( "This is the first half of the string, "  
           "this is the second half ") ;  
```  
  
 Contanto que cada parte da cadeia de caracteres esteja entre aspas duplas, as partes são concatenadas e reproduzidas como uma única cadeia de caracteres. Essa concatenação ocorre de acordo com a sequência de eventos durante a compilação especificada pelas [fases de conversão](../preprocessor/phases-of-translation.md).  
  
```  
"This is the first half of the string, this is the second half"  
```  
  
 Um ponteiro de cadeia de caracteres, inicializado como duas cadeias literais distintas separada apenas por espaço em branco, é armazenado como uma única cadeia de caracteres (os ponteiros são descritos em [Declarações de ponteiro](../c-language/pointer-declarations.md)). Quando referenciado corretamente, como no exemplo a seguir, o resultado é idêntico ao do exemplo anterior:  
  
```  
char *string = "This is the first half of the string, "  
               "this is the second half";  
  
printf_s( "%s" , string ) ;  
```  
  
 Na fase 6 de conversão, as sequências de caracteres multibyte especificadas por qualquer sequência de literais de cadeia de caracteres adjacentes ou literais de cadeia de caracteres largos adjacentes são concatenadas em uma única sequência de caracteres multibytes. Consequentemente, não crie programas para permitir a modificação de cadeias de caracteres literais durante a execução. O padrão ANSI C especifica que o resultado da modificação de uma cadeia de caracteres é indefinido.  
  
## <a name="see-also"></a>Consulte também  
 [Literais da cadeia de caracteres C](../c-language/c-string-literals.md)