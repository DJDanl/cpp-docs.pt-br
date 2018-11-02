---
title: Erro M6202 (Math)
ms.date: 11/04/2016
f1_keywords:
- M6202
helpviewer_keywords:
- M6202
ms.assetid: 4d17045f-c6dc-4705-9512-e9af12c35fb4
ms.openlocfilehash: c216c4d01513868dd56f47c7d5ca7f8b734d1797
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50538561"
---
# <a name="math-error-m6202"></a>Erro M6202 (Math)

'function': erro de sing

Um argumento para a função fornecida era um valor de singularidade para essa função. A função não está definida para o argumento.

Esse erro chama o `_matherr` função com o nome da função, seus argumentos e o tipo de erro. Você pode reescrever o `_matherr` função para personalizar o tratamento de certos erros de matemática de ponto flutuante de tempo de execução.