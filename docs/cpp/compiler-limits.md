---
title: Limites do compilador
ms.date: 05/06/2019
helpviewer_keywords:
- cl.exe compiler, limits for language constructs
ms.assetid: f1fa59c6-55b4-414b-80c5-3df72952160d
ms.openlocfilehash: 9663da06c97886ef1cd20ca2928944795b39dc18
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65222198"
---
# <a name="compiler-limits"></a>Limites do compilador

O padrão do C++ recomenda limites para várias construções de linguagem. A seguir está uma lista de casos em que o Microsoft C++ compilador não implementa os limites recomendados. O primeiro número é o limite estabelecido no ISO do C++ padrão de 11 (INCITS/ISO/IEC 14882-2011 [2012], anexo B) e o segundo número é o limite implementado pelo Microsoft C++ compilador:

- Níveis de aninhamento de instruções compostas, estruturas de controle de iteração e estruturas de controle de seleção - C++ padrão: 256, Microsoft C++ compilador: depende da combinação de instruções que estão aninhadas, mas geralmente entre 100 e 110.

- Parâmetros em uma definição macro - C++ padrão: 256, Microsoft C++ compilador: 127.

- Argumentos em uma invocação de macro - C++ padrão: 256, Microsoft C++ compilador 127.

- Literal ou largo sequência de caracteres literal de cadeia de caracteres em um caractere (depois da concatenação) - C++ padrão: Microsoft 65536, C++ compilador: 65535 caracteres de byte único, incluindo o terminador NULL e os caracteres de byte duplo 32767, incluindo o terminador NULL.

- Níveis de classe aninhada, estrutura ou união definições em um único `struct-declaration-list` - C++ padrão: 256, Microsoft C++ compilador: 16.

- Inicializadores de membro em uma definição de construtor - C++ padrão: Microsoft 6144, C++ compilador: c++:6144.

- Qualificações do escopo de um identificador - C++ padrão: 256, Microsoft C++ compilador: 127.

- Aninhado **extern** especificações - C++ padrão: 1024, o Microsoft C++ compilador: 9 (sem contar o implícita **extern** especificação no escopo global ou 10, se você contar implícito **extern** especificação no escopo global...

- Argumentos do modelo em uma declaração de modelo - C++ padrão: 1024, o Microsoft C++ compilador: 2046.

## <a name="see-also"></a>Consulte também

[Comportamento não padrão](../cpp/nonstandard-behavior.md)