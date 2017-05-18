---
title: "CXX0036 de erro do avaliador de expressão | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- CXX0036
dev_langs:
- C++
helpviewer_keywords:
- CXX0036
- CAN0036
ms.assetid: 383404be-df5b-4eec-b113-df21bb5d269d
caps.latest.revision: 6
author: corob-msft
ms.author: corob
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 81da32ddfdb96efc806cfb1a72ceb89deb97cd43
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="expression-evaluator-error-cxx0036"></a>Erro CXX0036 (avaliador de expressão)
contexto inválido {...} especificação  
  
 Essa mensagem pode ser gerada por qualquer um dos vários erros no uso do operador de contexto (**{**).  
  
-   A sintaxe do operador de contexto (**{**) foi especificado incorretamente.  
  
     A sintaxe do operador de contexto é:  
  
     {*function*,*module*,*dll*}*expression*  
  
     Especifica o contexto de *expressão*. O operador de contexto tem a mesma precedência e o uso como uma conversão de tipo.  
  
     À direita vírgulas pode ser omitida. Se qualquer um dos *função*, *módulo*, ou *dll* contém uma vírgula literal, você deve colocar o nome inteiro entre parênteses.  
  
-   O nome da função foi digitado incorretamente ou não existe na biblioteca de vínculo dinâmico ou módulo especificado.  
  
     Como C é uma linguagem diferencia maiusculas de minúsculas, *função* deve ser fornecido em diferencie maiusculas de minúsculas, como definido na origem.  
  
-   Não foi possível encontrar o módulo ou a DLL.  
  
     Verifique o nome do caminho completo da DLL ou módulo especificado.  
  
 Esse erro é idêntico ao CAN0036.
