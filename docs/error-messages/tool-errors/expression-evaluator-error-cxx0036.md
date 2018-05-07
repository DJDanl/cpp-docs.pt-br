---
title: CXX0036 de erro do avaliador de expressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- CXX0036
dev_langs:
- C++
helpviewer_keywords:
- CXX0036
- CAN0036
ms.assetid: 383404be-df5b-4eec-b113-df21bb5d269d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 18e1bf3cda85d7b3d64d51279688a52cec5c0336
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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