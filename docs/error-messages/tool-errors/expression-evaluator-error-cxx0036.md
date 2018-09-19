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
ms.openlocfilehash: e2d82a1254a11dbda3164ea1c350dc14e2b1a122
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46050106"
---
# <a name="expression-evaluator-error-cxx0036"></a>Erro CXX0036 (avaliador de expressão)

contexto incorreto {...} especificação

Essa mensagem pode ser gerada por qualquer um dos vários erros no uso do operador de contexto (**{}**).

- A sintaxe do operador de contexto (**{}**) foi especificado incorretamente.

     A sintaxe do operador de contexto é:

     {*função*,*módulo*,*dll*}*expressão*

     Isso especifica o contexto do *expressão*. O operador de contexto tem a mesma precedência e o uso como uma conversão de tipo.

     À direita vírgulas pode ser omitida. Se qualquer uma das *função*, *módulo*, ou *dll* contém uma vírgula literal, você deve colocar o nome inteiro entre parênteses.

- O nome da função está escrito incorretamente ou não existe na biblioteca de vínculo dinâmico ou módulo especificado.

     Como o C é uma linguagem diferencia maiusculas de minúsculas, *função* deve ser fornecido em diferencie maiusculas de minúsculas, conforme definido na fonte.

- Não foi possível encontrar o módulo ou DLL.

     Verifique o nome de caminho completo do módulo especificado ou da DLL.

Esse erro é idêntico ao CAN0036.