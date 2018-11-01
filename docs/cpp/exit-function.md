---
title: Função exit
ms.date: 11/04/2016
f1_keywords:
- Exit
helpviewer_keywords:
- exit function
ms.assetid: 26ce439f-81e2-431c-9ff8-a09a96f32127
ms.openlocfilehash: 82c9d00a49c8a080d893a51052739a0265ad0860
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50532555"
---
# <a name="exit-function"></a>Função exit

O **saia** função, declarada no arquivo de inclusão padrão \<stdlib. h >, encerra um programa C++.

O valor fornecido como um argumento para **sair** é retornado para o sistema operacional como código retorno de código ou sair do programa. Por convenção, um código de retorno de zero indica que o programa foi encerrado com êxito.

> [!NOTE]
>  Você pode usar as constantes EXIT_FAILURE e EXIT_SUCCESS, definido em \<stdlib. h >, para indicar êxito ou falha do programa.

Emitir uma **retornar** instrução from a `main` função é equivalente a chamar o **sair** função com o valor de retorno como seu argumento.

Para obter mais informações, consulte [saia](../c-runtime-library/reference/exit-exit-exit.md) na *referência de biblioteca de tempo de execução*.

## <a name="see-also"></a>Consulte também

[Término do programa](../cpp/program-termination.md)