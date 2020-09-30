---
title: Texto e fluxos binários
description: Uma descrição do texto e fluxos binários na biblioteca de tempo de execução do Microsoft C.
ms.date: 11/04/2016
ms.topic: conceptual
helpviewer_keywords:
- binary streams
- text streams
ms.assetid: 57035e4a-955d-4e04-a560-fcf67ce68b4e
ms.openlocfilehash: 522e4d5f119e4415694b59b2b08141a45f06fe5a
ms.sourcegitcommit: 9451db8480992017c46f9d2df23fb17b503bbe74
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2020
ms.locfileid: "91589608"
---
# <a name="text-and-binary-streams"></a>Texto e fluxos binários

Um fluxo de texto consiste em uma ou mais linhas de texto que podem ser gravados em uma exibição de texto para que possam ser lidos. Durante a leitura de um fluxo de texto, o programa lê um `NL` (nova linha) no final de cada linha. Ao gravar em um fluxo de texto, o programa grava um `NL` para sinalizar o final de uma linha. Para corresponder a convenções diferentes entre ambientes de destino para a representação de texto em arquivos, as funções da biblioteca podem alterar o número e representações de caracteres transmitidos entre o programa e um fluxo de texto.

O posicionamento dentro de um fluxo de texto é limitado. Você pode obter o indicador de posição do arquivo atual chamando [fgetpos](../c-runtime-library/reference/fgetpos.md) ou [ftell](../c-runtime-library/reference/ftell-ftelli64.md). Você pode posicionar um fluxo de texto em uma posição obtidos dessa forma, ou no início ou no final do fluxo, chamando [fsetpos](../c-runtime-library/reference/fsetpos.md) ou [fseek](../c-runtime-library/reference/fseek-fseeki64.md). Qualquer outra alteração de posição pode não ter suporte.

Para portabilidade máxima, o programa não deve gravar:

- Arquivos vazios.
- Caracteres de espaço no final de uma linha.
- Linhas parciais (omitindo o `NL` no final de um arquivo).
- caracteres além dos caracteres imprimíveis, NL e `HT` (tabulação horizontal).

Se você seguir essas regras, a sequência de caracteres que você ler de um fluxo de texto (em bytes ou caracteres multibyte) corresponderá a sequência de caracteres que você escreveu para o fluxo de texto quando você criou o arquivo. Caso contrário, as funções de biblioteca podem remover um arquivo criado se o arquivo está vazio quando você fechá-lo. Ou pode alterar ou excluir caracteres gravados no arquivo.

Um fluxo binário consiste em um ou mais bytes de informações arbitrárias. É possível gravar o valor armazenado em um objeto arbitrário para um fluxo binário (orientado a bytes) e ler exatamente o que foi armazenado no objeto quando você o escreveu. As funções de biblioteca não alteram os bytes que você transmite entre o programa e um fluxo binário. No entanto, eles podem acrescentar um número arbitrário de `NULL` bytes ao arquivo que você escreve com um fluxo binário. O programa deve lidar com esses `NULL` bytes adicionais no final do fluxo binário.

O posicionamento dentro de um fluxo binário é bem definido, com exceção do posicionamento relativo ao final do fluxo. Você pode obter e alterar o indicador de posição do arquivo atual da mesma maneira que um fluxo de texto. Os deslocamentos usados por [ftell](../c-runtime-library/reference/ftell-ftelli64.md) e [fseek](../c-runtime-library/reference/fseek-fseeki64.md) contam com bytes do início do fluxo (que é zero byte), portanto, a aritmética de inteiros nesses deslocamentos gera resultados previsíveis.

Um fluxo de bytes trata um arquivo como uma sequência de bytes. Dentro do programa, o fluxo é semelhante a mesma sequência de bytes, exceto as possíveis alterações descritas acima.

## <a name="see-also"></a>Confira também

[Arquivos e fluxos](../c-runtime-library/files-and-streams.md)
