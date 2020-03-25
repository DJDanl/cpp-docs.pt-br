---
title: Erro CXX0036 (avaliador de expressão)
ms.date: 11/04/2016
f1_keywords:
- CXX0036
helpviewer_keywords:
- CXX0036
- CAN0036
ms.assetid: 383404be-df5b-4eec-b113-df21bb5d269d
ms.openlocfilehash: 164fd9ee00071e218e5bb4f3ab00febc618725a7
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80195494"
---
# <a name="expression-evaluator-error-cxx0036"></a>Erro CXX0036 (avaliador de expressão)

contexto inadequado {...} especificação

Essa mensagem pode ser gerada por qualquer um dos vários erros no uso do operador de contexto ( **{}** ).

- A sintaxe do operador de contexto ( **{}** ) foi fornecida incorretamente.

   A sintaxe do operador de contexto é:

     {*função*,*módulo*,*dll*} *expressão* de

   Especifica o contexto da *expressão*. O operador de contexto tem a mesma precedência e uso como uma conversão de tipo.

   Vírgulas à direita podem ser omitidas. Se qualquer *função*, *módulo*ou *dll* contiver uma vírgula literal, você deverá colocar o nome inteiro entre parênteses.

- O nome da função foi digitado incorretamente ou não existe no módulo especificado ou na biblioteca de vínculo dinâmico.

   Como C é uma linguagem que diferencia maiúsculas de minúsculas, a *função* deve ser fornecida no caso exato, pois ela é definida na origem.

- Não foi possível encontrar o módulo ou a DLL.

   Verifique o nome do caminho completo do módulo ou DLL especificado.

Esse erro é idêntico a CAN0036.
