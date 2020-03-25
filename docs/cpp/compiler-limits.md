---
title: Limites do compilador
ms.date: 05/06/2019
helpviewer_keywords:
- cl.exe compiler, limits for language constructs
ms.assetid: f1fa59c6-55b4-414b-80c5-3df72952160d
ms.openlocfilehash: 9e61cae1638c87f03b6fa775552408961bde6859
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80189566"
---
# <a name="compiler-limits"></a>Limites do compilador

O padrão do C++ recomenda limites para várias construções de linguagem. Veja a seguir uma lista de casos em que o C++ compilador da Microsoft não implementa os limites recomendados. O primeiro número é o limite estabelecido no padrão ISO C++ 11 (INCITS/ISO/IEC 14882-2011 [2012], anexo B) e o segundo número é o limite implementado pelo compilador da Microsoft: C++

- Aninhando níveis de instruções compostas, estruturas de controle de iteração e C++ estruturas de controle de seleção C++ -Standard: 256, compilador da Microsoft: depende da combinação de instruções que são aninhadas, mas geralmente entre 100 e 110.

- Parâmetros em uma definição de macro C++ -standard: 256, C++ compilador Microsoft: 127.

- Argumentos em uma única chamada de macro C++ -standard: 256, C++ Microsoft Compiler 127.

- Caracteres em um literal de cadeia de caracteres ou literal de cadeia de caracteres largo ( C++ após concatenação)- C++ Standard: 65536, compilador da Microsoft: 65535 caracteres de byte único, incluindo o terminador nulo e 32767 caracteres de byte duplo, incluindo o terminador nulo.

- Níveis de definições de classe aninhada, estrutura ou União em um único `struct-declaration-list` C++ padrão: 256, compilador C++ Microsoft: 16.

- Inicializadores de membro em uma definição de C++ Construtor-standard: 6144 C++ , compilador da Microsoft: pelo menos 6144.

- Qualificações de escopo de um C++ identificador-padrão: 256 C++ , Microsoft Compiler: 127.

- Especificações aninhadas **extern** - C++ Standard: 1024 C++ , compilador da Microsoft: 9 (não contando a especificação **explícita implícita no** escopo global ou 10, se você contar a especificação de **externo** implícita no escopo global...

- Argumentos de modelo em uma declaração de C++ modelo-standard: 1024 C++ , compilador Microsoft: 2046.

## <a name="see-also"></a>Confira também

[Comportamento não padrão](../cpp/nonstandard-behavior.md)
