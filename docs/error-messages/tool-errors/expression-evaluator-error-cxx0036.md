---
title: "CXX0036 de erro do avaliador de expressão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: CXX0036
dev_langs: C++
helpviewer_keywords:
- CXX0036
- CAN0036
ms.assetid: 383404be-df5b-4eec-b113-df21bb5d269d
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: fdf6ddf412786a53ec8da995c2824274da2da3b1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="expression-evaluator-error-cxx0036"></a>Erro CXX0036 (avaliador de expressão)
contexto inválido {...} especificação  
  
 Essa mensagem pode ser gerada por qualquer um dos vários erros no uso do operador de contexto (**{}**).  
  
-   A sintaxe do operador de contexto (**{}**) foi especificado incorretamente.  
  
     A sintaxe do operador de contexto é:  
  
     {*função*,*módulo*,*dll*}*expressão*  
  
     Isso especifica o contexto de *expressão*. O operador de contexto tem a mesma precedência e o uso como uma conversão de tipo.  
  
     À direita vírgulas pode ser omitida. Se qualquer um dos *função*, *módulo*, ou *dll* contém uma vírgula literal, você deve colocar o nome inteiro entre parênteses.  
  
-   O nome da função foi digitado incorretamente ou não existe na biblioteca de vínculo dinâmico ou módulo especificado.  
  
     Porque C é uma linguagem diferencia maiusculas de minúsculas, *função* deve ser fornecido em diferencie maiusculas de minúsculas, conforme definido na fonte.  
  
-   Não foi possível encontrar o módulo ou DLL.  
  
     Verifique o nome do caminho completo da DLL ou módulo especificado.  
  
 Esse erro é idêntico ao CAN0036.