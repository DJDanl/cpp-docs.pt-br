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
ms.openlocfilehash: 1541840521695658b5c4d809ba7e11767b1330a2
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857548"
---
# <a name="customizing-c-command-line-processing"></a>Personalizando processamento de linha de comando C++

**Seção específica da Microsoft**

Se o seu programa não utiliza argumentos de linha de comando, é possível economizar um pequeno espaço suprimindo o uso da rotina de biblioteca que executa o processamento de linha de comando. Essa rotina é chamada de `_setargv` e é descrita na [expansão de curinga](../cpp/wildcard-expansion.md). Para suprimir seu uso, defina uma rotina que não faz nada no arquivo que contém a função `main` e nomeie-o `_setargv`. A chamada para `_setargv` é então satisfeita pela sua definição de `_setargv`, e a versão da biblioteca não é carregada.

Da mesma forma, se você nunca acessar a tabela de ambiente por meio do argumento `envp`, poderá fornecer sua própria rotina vazia a ser usada no lugar de `_setenvp`, a rotina de processamento de ambiente. Assim como com a função `_setargv`, `_setenvp` deve ser declarado como **"C" externo**.

Seu programa pode fazer chamadas para o `spawn` ou `exec` família de rotinas na biblioteca de tempo de execução do C. Se esse for o caso, você não deve suprimir a rotina de processamento de ambiente, pois essa rotina é usada para passar um ambiente do processo pai para o processo filho.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[main: inicialização do programa](../cpp/main-program-startup.md)