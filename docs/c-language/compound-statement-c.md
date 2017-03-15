---
title: "Instrução composta (C) | Microsoft Docs"
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
- compound statements
- statements, compound
ms.assetid: 32d1bf86-cbbc-42a9-ba3a-1be1c6c7754c
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: b3e1a3ac8663403d4e226caca7ed33d41f58fe5b
ms.lasthandoff: 02/25/2017

---
# <a name="compound-statement-c"></a>Instrução composta (C)
Uma instrução composta (também chamada de “bloco”) aparece geralmente como o corpo de uma outra instrução, como a instrução **if**. [Declarações e tipos](../c-language/declarations-and-types.md) descreve o formato e o significado das declarações que podem aparecer no cabeçalho de uma instrução composta.  
  
## <a name="syntax"></a>Sintaxe  
 *compound-statement*:  
 **{**  *declaration-list* opt*statement-list*opt**}**  
  
 *declaration-list*:  
 *declaration*  
  
 *declaration-list declaration*  
  
 *statement-list*:  
 s*tatement*  
  
 *statement-list statement*  
  
 Se houver declarações, elas deverão vir antes de todas as instruções. O escopo de cada identificador declarado no início de uma instrução composta estende-se de seu ponto de declaração ao fim do bloco. É visível em todo o bloco a menos que uma declaração do mesmo identificador exista em um bloco interno.  
  
 Os identificadores em uma instrução composta são presumidos como **auto**, a menos que declarados explicitamente de outra forma com **register**, **static** ou `extern`, exceto as funções, que só podem ser `extern`. Você pode deixar de fora o especificador `extern` em declarações de função, e a função ainda será `extern`.  
  
 O armazenamento não será alocado e a inicialização não será permitida se uma variável ou função for declarada em uma instrução composta com a classe de armazenamento `extern`. A declaração se refere a uma variável ou função externa definida em outro lugar.  
  
 Variáveis declaradas em um bloco com a palavra-chave **auto** ou **register** são realocadas e, se necessário, inicializadas cada vez que a instrução composta é inserida. Essas variáveis não são definidas depois que a instrução composta é encerrada. Se uma variável declarada em um bloco tiver o atributo **static**, a variável será inicializada quando a execução do programa iniciar e manterá seu valor ao longo do programa. Consulte [Classes de armazenamento](../c-language/c-storage-classes.md) para obter informações sobre **static**.  
  
 Este exemplo ilustra uma instrução composta:  
  
```  
if ( i > 0 )   
{  
    line[i] = x;  
    x++;  
    i--;  
}  
```  
  
 Neste exemplo, se `i` for maior que 0, todas as instruções na instrução composta serão executadas na ordem.  
  
## <a name="see-also"></a>Consulte também  
 [Instruções](../c-language/statements-c.md)
