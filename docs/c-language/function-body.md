---
title: "Corpo da Função | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- functions [C], syntax
- variables, function syntax
- function definitions, function body
- function body
ms.assetid: f7e74822-fac8-4dc8-8f3a-2b1611da4640
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a0c85ecf0752ff34bf5b61e42309360f2bc4d448
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="function-body"></a>Corpo da função
Um “corpo da função” é uma instrução composta que contém as instruções que especificam o que a função faz.  
  
## <a name="syntax"></a>Sintaxe  
 *function-definition*:  
 *declaration-specifiers* opt*attribute-seq* opt*declarator declaration-list* opt*compound-statement*  
  
 /\* *attribute-seq* é específico da Microsoft */  
  
 *compound-statement*: /\* O corpo da função \*/  
 **{**  *declaration-list* opt*statement-list* opt**}**  
  
 Variáveis declaradas em um corpo da função, “variáveis locais”, têm a classe de armazenamento **auto**, a menos que especificado o contrário. Quando a função for chamada, o armazenamento é criado para as variáveis locais e as inicializações de local são executadas. O controle de execução passa para a primeira instrução em *instrução composta* e continua até que uma instrução `return` seja executada ou o final do corpo da função seja encontrado. O controle então retorna para o ponto no qual a função foi chamada.  
  
 Uma instrução `return` que contenha uma expressão deve ser executada se a função tiver que retornar um valor. O valor de retorno de uma função é indefinido se nenhuma instrução `return` for executada ou se a instrução `return` não incluir uma expressão.  
  
## <a name="see-also"></a>Consulte também  
 [Definições de função C](../c-language/c-function-definitions.md)