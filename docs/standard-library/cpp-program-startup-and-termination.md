---
title: Inicialização e encerramento de programas em C++
ms.date: 11/04/2016
helpviewer_keywords:
- C++ Standard Library, program startup and termination
- terminating execution
- Function Main procedures
- control text streams
- startup code, and C++ program termination
- main function, program startup
ms.assetid: f72c8f76-f507-4ddd-a270-7b60f4fed625
ms.openlocfilehash: 2246e50c81da9eb505fd30cfa31f9f24e3fe4703
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50459183"
---
# <a name="c-program-startup-and-termination"></a>Inicialização e encerramento de programas em C++

Um programa do C++ executa as mesmas operações que um programa do C na inicialização e no encerramento do programa, além de algumas outras descritas aqui.

Antes que o ambiente de destino chame a função `main` e depois que ele armazenar os valores iniciais de constante especificados em todos os objetos que têm duração estática, o programa executará os construtores restantes para esses objetos estáticos. A ordem de execução não é especificada entre as unidades de translação; entretanto, é possível supor que alguns objetos [iostreams](../standard-library/iostreams-conventions.md) são inicializados corretamente para uso desses construtores estáticos. Estes fluxos de texto de controle são:

- [cin](../standard-library/iostream.md#cin) – para entrada padrão.

- [cout](../standard-library/iostream.md#cout) – para saída padrão.

- [cerr](../standard-library/iostream.md#cerr) – para saída de erro padrão não armazenada em buffer.

- [clog](../standard-library/iostream.md#clog) – para saída de erro padrão armazenada em buffer.

Também é possível usar esses objetos nos destruidores chamados para objetos estáticos, durante o encerramento do programa.

Assim como ocorre com o C, retornar de `main` ou chamar `exit` chama todas as funções registradas com `atexit` na ordem inversa do Registro. Uma exceção gerada de uma função registrada desse tipo chama `terminate`.

## <a name="see-also"></a>Consulte também

[Visão geral da biblioteca padrão C++](../standard-library/cpp-standard-library-overview.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
