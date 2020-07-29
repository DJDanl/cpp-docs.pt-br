---
title: Limites do compilador
ms.date: 05/06/2019
helpviewer_keywords:
- cl.exe compiler, limits for language constructs
ms.assetid: f1fa59c6-55b4-414b-80c5-3df72952160d
ms.openlocfilehash: e0e2381d88c727466b06a97c72826d2d5e15a87b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233763"
---
# <a name="compiler-limits"></a>Limites do compilador

O padrão do C++ recomenda limites para várias construções de linguagem. Veja a seguir uma lista de casos em que o compilador do Microsoft C++ não implementa os limites recomendados. O primeiro número é o limite estabelecido no padrão ISO C++ 11 (INCITS/ISO/IEC 14882-2011 [2012], anexo B) e o segundo número é o limite implementado pelo compilador do Microsoft C++:

- Aninhando níveis de instruções compostas, estruturas de controle de iteração e estruturas de controle de seleção-C++ Standard: 256, compilador do Microsoft C++: depende da combinação de instruções que estão aninhadas, mas geralmente entre 100 e 110.

- Parâmetros em uma definição de macro-C++ Standard: 256, compilador do Microsoft C++: 127.

- Argumentos em uma única macro invoca-C++ Standard: 256, compilador do Microsoft C++ 127.

- Caracteres em um literal de cadeia de caracteres ou literal de cadeia de caracteres largo (após concatenação)-C++ Standard: 65536, compilador do Microsoft C++: 65535 caracteres de byte único, incluindo o terminador nulo e 32767 caracteres de byte duplo, incluindo o terminador nulo.

- Níveis de definições de classe aninhada, estrutura ou União em um `struct-declaration-list` padrão de c++ único: 256, compilador do Microsoft C++: 16.

- Inicializadores de membro em uma definição de construtor-C++ Standard: 6144, compilador do Microsoft C++: pelo menos 6144.

- Qualificações de escopo de um identificador-C++ Standard: 256, compilador do Microsoft C++: 127.

- Especificações aninhadas **`extern`** -C++ Standard: 1024, compilador do Microsoft C++: 9 (sem contar a **`extern`** especificação implícita no escopo global, ou 10, se você contar a **`extern`** especificação implícita no escopo global...

- Argumentos de modelo em uma declaração de modelo-C++ Standard: 1024, compilador do Microsoft C++: 2046.

## <a name="see-also"></a>Confira também

[Comportamento não padrão](../cpp/nonstandard-behavior.md)
