---
title: Conflitos com o compilador x86
ms.date: 11/04/2016
ms.assetid: 8e47f0d3-afe0-42d9-9efa-de239ddd3a05
ms.openlocfilehash: e56ebc5631ac5c96a9cdd2dfc2b8e81cdeed9769
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50614260"
---
# <a name="conflicts-with-the-x86-compiler"></a>Conflitos com o compilador x86

Tipos de dados que são maiores do que 4 bytes não são alinhadas automaticamente na pilha quando você usa o x86 compilador para compilar um aplicativo. Porque a arquitetura para x86 de compilador é uma pilha alinhado de 4 bytes, algo maior do que 4 bytes, por exemplo, um inteiro de 64 bits, não pode ser alinhada automaticamente para um endereço de 8 bytes.

Trabalhar com dados não alinhados tem implicações de dois.

- Pode levar mais tempo para acessar locais não alinhados, que é necessário para acessar locais alinhados.

- Locais não alinhados não podem ser usados em operações interconectadas.

Se você precisar de mais de alinhamento estrito, use `__declspec(align(N)) on your variable declarations`. Isso faz com que o compilador alinhar dinamicamente a pilha para atender às suas especificações. No entanto, ajustar dinamicamente a pilha em tempo de execução pode causar a execução mais lenta do seu aplicativo.

## <a name="see-also"></a>Consulte também

[Tipos e armazenamento](../build/types-and-storage.md)<br/>
[align](../cpp/align-cpp.md)