---
title: Limites do compilador
ms.date: 11/04/2016
helpviewer_keywords:
- cl.exe compiler, limits for language constructs
ms.assetid: f1fa59c6-55b4-414b-80c5-3df72952160d
ms.openlocfilehash: a0c6041d326982dc9807355733cf714dcfa62ca8
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62399155"
---
# <a name="compiler-limits"></a>Limites do compilador

O padrão do C++ recomenda limites para várias construções de linguagem. A lista a seguir contém casos onde o compilador do Visual C++ não implementa os limites recomendados. O primeiro número é o limite estabelecido no padrão ISO C++11 (INCITS/ISO/IEC 14882-2011[2012], Anexo B) e o segundo número é o limite implementado pelo Visual C++:

- Níveis de aninhamento de instruções compostas, estruturas de controle de iteração e estruturas de controle de seleção - C++ padrão: Visual 256, C++ compilador: depende da combinação de instruções que estão aninhadas, mas geralmente entre 100 e 110.

- Parâmetros em uma definição macro - C++ padrão: Visual 256, C++ compilador: 127.

- Argumentos em uma invocação de macro - C++ padrão: Visual 256, C++ compilador 127.

- Literal ou largo sequência de caracteres literal de cadeia de caracteres em um caractere (depois da concatenação) - C++ padrão: Visual 65536, C++ compilador: 65535 caracteres de byte único, incluindo o terminador NULL e os caracteres de byte duplo 32767, incluindo o terminador NULL.

- Níveis de classe aninhada, estrutura ou união definições em um único `struct-declaration-list` - C++ padrão: Visual 256, C++ compilador: 16.

- Inicializadores de membro em uma definição de construtor - C++ padrão: Visual 6144, C++ compilador: c++:6144.

- Qualificações do escopo de um identificador - C++ padrão: Visual 256, C++ compilador: 127.

- Aninhado **extern** especificações - C++ padrão: 1024, o visual C++ compilador: 9 (sem contar o implícita **extern** especificação no escopo global ou 10, se você contar implícito **extern** especificação no escopo global...

- Argumentos do modelo em uma declaração de modelo - C++ padrão: 1024, o visual C++ compilador: 2046.

## <a name="see-also"></a>Consulte também

[Comportamento não padrão](../cpp/nonstandard-behavior.md)