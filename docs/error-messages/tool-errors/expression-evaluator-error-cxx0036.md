---
title: Erro CXX0036 (avaliador de expressão)
ms.date: 11/04/2016
f1_keywords:
- CXX0036
helpviewer_keywords:
- CXX0036
- CAN0036
ms.assetid: 383404be-df5b-4eec-b113-df21bb5d269d
ms.openlocfilehash: d7961d92760cc5ac325b4bc9f187d4ee2298479a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62397023"
---
# <a name="expression-evaluator-error-cxx0036"></a>Erro CXX0036 (avaliador de expressão)

contexto incorreto {...} especificação

Essa mensagem pode ser gerada por qualquer um dos vários erros no uso do operador de contexto (**{}**).

- A sintaxe do operador de contexto (**{}**) foi especificado incorretamente.

   A sintaxe do operador de contexto é:

     {*function*,*module*,*dll*}*expression*

   Isso especifica o contexto do *expressão*. O operador de contexto tem a mesma precedência e o uso como uma conversão de tipo.

   À direita vírgulas pode ser omitida. Se qualquer uma das *função*, *módulo*, ou *dll* contém uma vírgula literal, você deve colocar o nome inteiro entre parênteses.

- O nome da função está escrito incorretamente ou não existe na biblioteca de vínculo dinâmico ou módulo especificado.

   Como o C é uma linguagem diferencia maiusculas de minúsculas, *função* deve ser fornecido em diferencie maiusculas de minúsculas, conforme definido na fonte.

- Não foi possível encontrar o módulo ou DLL.

   Verifique o nome de caminho completo do módulo especificado ou da DLL.

Esse erro é idêntico ao CAN0036.