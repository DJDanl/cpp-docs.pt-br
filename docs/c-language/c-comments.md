---
title: "Comentários C | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- code comments, C code
- comments, documenting code
- comments, C code
- /* */ comment delimiters
- comments
ms.assetid: 0f5f2825-e673-49e7-8669-94e2f5294989
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 78c3e97530198b6685e402237bda5cdaf9a0754a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="c-comments"></a>Comentários C
Um “comentário” é uma sequência de caracteres que começam com uma combinação de barra e asterisco (<b>/\*</b>) que é tratada como um único caractere de espaço em branco e ignorada pelo compilador de outra forma. Um comentário pode incluir qualquer combinação de caracteres do conjunto de caracteres representável, inclusive caracteres de nova linha, mas excluindo o delimitador de fim do comentário (<b>\*/</b>). Os comentários podem ocupar mais de uma linha mas não podem ser aninhados.  
  
 Os comentários podem aparecer em qualquer lugar em que um caractere de espaço em branco é permitido. Como o compilador trata um comentário como um único caractere de espaço em branco, você não pode incluir comentários nos tokens. O compilador ignora os caracteres no comentário.  
  
 Use comentários para documentar seu código. Este exemplo é um comentário aceito pelo compilador:  
  
```  
/* Comments can contain keywords such as  
   for and while without generating errors. */  
```  
  
 Os comentários podem aparecer na mesma linha de uma instrução de código:  
  
```  
printf( "Hello\n" );  /* Comments can go here */  
```  
  
 Você pode optar por preceder funções ou módulos do programa com um bloco de comentário descritivo:  
  
```  
/* MATHERR.C illustrates writing an error routine   
 * for math functions.   
 */   
```  
  
 Como os comentários não podem conter comentários aninhados, este exemplo causa um erro:  
  
```  
/* Comment out this routine for testing   
  
   /* Open file */  
    fh = _open( "myfile.c", _O_RDONLY );  
    .  
    .  
    .  
 */  
```  
  
 O erro ocorre porque o compilador reconhece o primeiro `*/`, após as palavras `Open file`, como o fim do comentário. Ele tenta processar o texto restante e gera um erro ao encontrar `*/` fora de um comentário.  
  
 Embora você possa usar comentários para executar determinadas linhas de código inativo para fins de teste, as políticas `#if` e `#endif` do pré-processador e a compilação condicional são uma alternativa útil para essa tarefa. Para obter mais informações, consulte [Diretivas do pré-processador](../preprocessor/preprocessor-directives.md) na *Referência do pré-processador*.  
  
 **Seção específica da Microsoft**  
  
 O compilador da Microsoft também dá suporte aos comentários de linha única precedidos por duas barras (**//**). Se você compilar com /Za (padrão ANSI), esses comentários gerarão erros. Esses comentários não podem se estender para uma segunda linha.  
  
```  
// This is a valid comment  
```  
  
 Os comentários que começam com duas barras (**//**) são finalizados pelo caractere de nova linha que não é precedido por um caractere de escape. No exemplo a seguir, o caractere de nova linha é precedido por uma barra invertida (**\\**), criando uma "sequência de escape." Essa sequência de escape faz com que o compilador trate a próxima linha como parte da linha anterior. (Para obter mais informações, consulte [Sequências de escape](../c-language/escape-sequences.md).)  
  
```  
// my comment \  
    i++;   
```  
  
 Portanto, a instrução `i++;` é comentada.  
  
 O padrão do Microsoft C é que as extensões da Microsoft sejam habilitadas. Use /Za para desabilitar essas extensões.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Tokens C](../c-language/c-tokens.md)
