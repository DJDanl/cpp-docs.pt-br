---
title: Aviso LNK4102 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4102
helpviewer_keywords:
- LNK4102
ms.assetid: bfd1b17e-05c7-4bc2-80d6-2888b1a425b2
ms.openlocfilehash: 0f9c8649988dd3056e98730ac4b02022a8c9dd51
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50643082"
---
# <a name="linker-tools-warning-lnk4102"></a>Aviso LNK4102 (Ferramentas de Vinculador)

exportação de exclusão de destrutor 'name'; imagem não pode ser executada corretamente

O programa tentou exportar um destruidor de exclusão. A exclusão resultante pode ocorrer em um limite de DLL, de modo que um processo pode liberar memória que não é proprietário. Certifique-se de que o símbolo fornecido não está listado em seu arquivo. def, e que o símbolo não está listado como um argumento do **/import** ou **/exportação** opção na linha de comando do vinculador.

Se você estiver recriando a biblioteca de tempo de execução C, você pode ignorar essa mensagem.