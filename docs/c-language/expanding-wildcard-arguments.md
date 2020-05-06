---
title: Expandindo argumentos de curinga
ms.date: 11/04/2016
helpviewer_keywords:
- asterisk wildcard
- question mark, wildcard
- expanding wildcard arguments
- wildcards, expanding
ms.assetid: 80a11c4b-0199-420e-a342-cf1d803be5bc
ms.openlocfilehash: f1fb964fe98223fb7187b83c7101027ed1f9cbea
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62233799"
---
# <a name="expanding-wildcard-arguments"></a>Expandindo argumentos de curinga

**Específico da Microsoft**

Ao executar um programa C, você pode usar qualquer um dos dois caracteres curinga — o ponto de interrogação (?) e o asterisco (*) — para especificar argumentos de nome de arquivo e caminho na linha de comando.

Por padrão, os curingas não são expandidos em argumentos de linha de comando. Você pode substituir o vetor de argumento normal `argv` carregando a rotina com uma versão que expande curingas por meio da vinculação com o arquivo setargv.obj ou wsetargv.obj. Se o seu programa usar `main` uma função, vincule com setargv. obj. Se o seu programa usar `wmain` uma função, vincule com Wsetargv. obj. Ambos têm comportamento equivalente.

Para vinculá-lo a Setargv.obj ou a wsetargv.obj, use a opção **/link**. Por exemplo: 

**cl example.c /link setargv.obj**

Os caracteres curinga são expandidos da mesma maneira que os comandos do sistema operacional. (Consulte o guia do usuário do sistema operacional se você não estiver familiarizado com os caracteres curinga.)

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Opções de link](../c-runtime-library/link-options.md)<br/>
[Função main e execução do programa](../c-language/main-function-and-program-execution.md)
