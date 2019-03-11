---
title: Último caractere em uma cadeia de caracteres
ms.date: 11/04/2016
helpviewer_keywords:
- last character in string
- MBCS [C++], last character in string
ms.assetid: 0a180376-4e55-41e8-9c64-539c7b6d8047
ms.openlocfilehash: 4c99628cd12738fabb877a94cfd04a4033ee45aa
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57740292"
---
# <a name="last-character-in-a-string"></a>Último caractere em uma cadeia de caracteres

Use as dicas a seguir:

- Intervalos de bytes de trilha de sobreponham o caractere ASCII definido em muitos casos. Com segurança, você pode usar exames bytewise para caracteres de controle (menor que 32).

- Considere a seguinte linha de código, que pode incluir verificar para ver se o último caractere em uma cadeia de caracteres é um caractere de barra invertida:

    ```cpp
    if ( sz[ strlen( sz ) - 1 ] == '\\' )    // Is last character a '\'?
        // . . .
    ```

   Porque `strlen` não dá suporte MBCS, ele retorna o número de bytes, não o número de caracteres, em uma cadeia de caracteres multibyte. Além disso, observe que, em algumas páginas (932, por exemplo), de código '\\' (0x5c) é um byte final válido (`sz` é uma cadeia de caracteres do C).

   É uma solução possível reescrever o código desta forma:

    ```cpp
    char *pLast;
    pLast = _mbsrchr( sz, '\\' );    // find last occurrence of '\' in sz
    if ( pLast && ( *_mbsinc( pLast ) == '\0' ) )
        // . . .
    ```

   Esse código usa as funções MBCS `_mbsrchr` e `_mbsinc`. Como essas funções são com suporte a MBCS, eles podem distinguir entre um '\\'caractere e um byte final'\\'. O código executa alguma ação se o último caractere na cadeia de caracteres é um valor nulo ('\0').

## <a name="see-also"></a>Consulte também

[Dicas de programação do MBCS](../text/mbcs-programming-tips.md)<br/>
[Atribuição de caractere](../text/character-assignment.md)
