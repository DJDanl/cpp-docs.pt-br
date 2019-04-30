---
title: Incrementando e decrementando ponteiros
ms.date: 11/04/2016
helpviewer_keywords:
- incrementing pointers
- MBCS [C++], pointers
- pointers [C++], multibyte characters
- decrementing pointers
ms.assetid: 0872b4a0-e2bd-4004-8319-070efb76f2fd
ms.openlocfilehash: cdaee3d13a8ceab47f62100953a0eb6e51bfc255
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62410649"
---
# <a name="incrementing-and-decrementing-pointers"></a>Incrementando e decrementando ponteiros

Use as dicas a seguir:

- Aponte para o cliente potencial bytes, não rastros bytes. Não é normalmente seguro para ter um ponteiro para um byte final. É geralmente mais segura verificar uma cadeia de caracteres para frente em vez de em ordem inversa.

- Há funções de aumentar/diminuir de ponteiro e macros disponíveis que se movem sobre um caractere de inteiro:

    ```cpp
    sz1++;
    ```

   se torna:

    ```cpp
    sz1 = _mbsinc( sz1 );
    ```

   O `_mbsinc` e `_mbsdec` funções corretamente incremento e decréscimo em `character` unidades, independentemente do tamanho do caractere.

- Para diminui, você precisa de um ponteiro para o início da cadeia de caracteres, da seguinte maneira:

    ```cpp
    sz2--;
    ```

   se torna:

    ```cpp
    sz2 = _mbsdec( sz2Head, sz2 );
    ```

   Como alternativa, o ponteiro de cabeçalho pode ser um caractere válido na cadeia de caracteres, que:

    ```cpp
    sz2Head < sz2
    ```

   Você deve ter um ponteiro para um byte inicial válido conhecido.

- Você talvez queira manter um ponteiro para o caractere anterior para chamadas mais rápidas para `_mbsdec`.

## <a name="see-also"></a>Consulte também

[Dicas de programação do MBCS](../text/mbcs-programming-tips.md)<br/>
[Índices de byte](../text/byte-indices.md)
