---
title: Ferramentas de vinculador LNK4102 aviso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4102
dev_langs:
- C++
helpviewer_keywords:
- LNK4102
ms.assetid: bfd1b17e-05c7-4bc2-80d6-2888b1a425b2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9daaffc4ddfa9a869c2e60e2c05dc2b7e296d94b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46031842"
---
# <a name="linker-tools-warning-lnk4102"></a>Aviso LNK4102 (Ferramentas de Vinculador)

exportação de exclusão de destrutor 'name'; imagem não pode ser executada corretamente

O programa tentou exportar um destruidor de exclusão. A exclusão resultante pode ocorrer em um limite de DLL, de modo que um processo pode liberar memória que não é proprietário. Certifique-se de que o símbolo fornecido não está listado em seu arquivo. def, e que o símbolo não está listado como um argumento do **/import** ou **/exportação** opção na linha de comando do vinculador.

Se você estiver recriando a biblioteca de tempo de execução C, você pode ignorar essa mensagem.