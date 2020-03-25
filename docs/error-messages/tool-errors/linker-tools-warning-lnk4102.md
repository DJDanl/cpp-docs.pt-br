---
title: Aviso LNK4102 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4102
helpviewer_keywords:
- LNK4102
ms.assetid: bfd1b17e-05c7-4bc2-80d6-2888b1a425b2
ms.openlocfilehash: fda1fdb03a7629894f846bb20ed84df519239327
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80183300"
---
# <a name="linker-tools-warning-lnk4102"></a>Aviso LNK4102 (Ferramentas de Vinculador)

exportação de exclusão de ' nome ' do destruidor; a imagem pode não ser executada corretamente

O programa tentou exportar um destruidor de exclusão. A exclusão resultante pode ocorrer em um limite de DLL, de modo que um processo possa liberar memória que não seja de sua propriedade. Verifique se o símbolo fornecido não está listado no arquivo. def e se o símbolo não está listado como um argumento da opção **/Import** ou **/Export** na linha de comando do vinculador.

Se você estiver recompilando a biblioteca de tempo de execução do C, poderá ignorar esta mensagem.
