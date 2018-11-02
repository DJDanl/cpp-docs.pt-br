---
title: Personalizando processamento de linha de comando C++
ms.date: 11/04/2016
f1_keywords:
- _setenvp
- _setargv
helpviewer_keywords:
- command line [C++], processing
- command-line processing
- startup code, customizing command-line processing
- environment, environment-processing routine
- _setargv function
- command line [C++], processing arguments
- suppressing environment processing
- _setenvp function
ms.assetid: aae01cbb-892b-48b8-8e1f-34f22421f263
ms.openlocfilehash: da1b3bdd6392b144f9315add4c19de14c1d14d41
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50582683"
---
# <a name="customizing-c-command-line-processing"></a>Personalizando processamento de linha de comando C++

## <a name="microsoft-specific"></a>Específico da Microsoft

Se o seu programa não utiliza argumentos de linha de comando, é possível economizar um pequeno espaço suprimindo o uso da rotina de biblioteca que executa o processamento de linha de comando. Essa rotina é chamada `_setargv` e é descrito na [expansão de curinga](../cpp/wildcard-expansion.md). Para suprimir seu uso, defina uma rotina que não faça nada no arquivo que contém o `main` funcionar e nomeie- `_setargv`. A chamada para `_setargv` é atendida por sua definição de `_setargv`, e a versão da biblioteca não está carregada.

Da mesma forma, se você nunca acessar a tabela de ambiente por meio de `envp` argumento, você pode fornecer sua própria rotina vazia a ser usado no lugar de `_setenvp`, a rotina de processamento de ambiente. Assim como ocorre com o `_setargv` função, `_setenvp` deve ser declarado como **extern "C"**.

O programa poderá fazer chamadas para o `spawn` ou `exec` família de rotinas na biblioteca de tempo de execução C. Se esse for o caso, você não deve suprimir a rotina de processamento de ambiente, pois essa rotina é usada para passar um ambiente do processo pai para o processo filho.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[main: inicialização do programa](../cpp/main-program-startup.md)