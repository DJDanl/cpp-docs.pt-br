---
title: Delimitadores de marcas de documentação para o Visual C++
ms.date: 11/04/2016
helpviewer_keywords:
- XML documentation, delimiters
ms.assetid: debfbdd9-63fa-4c58-a18e-a4d203d241d7
ms.openlocfilehash: e8e312eacb46d82270d7ca1782b04d06012b207d
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90041530"
---
# <a name="delimiters-for-visual-c-documentation-tags"></a>Delimitadores de marcas de documentação para o Visual C++

O uso de marcas de documentação exige delimitadores, que indicam ao compilador o local em que um comentário da documentação começa e termina.

Você pode usar os seguintes tipos de delimitadores com as marcas de documentação XML:

| Delimitador | Descrição |
|-|-|
| `///` | Esse é o formulário mostrado nos exemplos de documentação e usado pelos modelos de projeto do Visual Studio C++.  |
| `/** */`  | Veja abaixo os delimitadores multilinha.  |

Há algumas regras de formatação no uso dos delimitadores `/** */`:

- Na linha que contém o delimitador `/**`, se o restante da linha é um espaço em branco, a linha não é processada para comentários. Se o primeiro caractere é um espaço em branco, esse caractere de espaço em branco é ignorado e o restante da linha é processado. Caso contrário, todo o texto da linha após o delimitador `/**` é processado como parte do comentário.

- Na linha que contém o delimitador `*/`, se há apenas um espaço em branco até o delimitador `*/`, essa linha é ignorada. Caso contrário, o texto da linha até o delimitador `*/` é processado como parte do comentário, sujeito às regras de correspondência de padrão descritas no marcador seguinte.

- Nas linhas após aquela que começa com o delimitador `/**`, o compilador procura um padrão comum no início de cada linha que consiste em um espaço em branco opcional e um asterisco (`*`), seguido por mais um espaço em branco opcional. Se o compilador encontrar um conjunto comum de caracteres no início de cada linha, ele ignorará esse padrão em todas as linhas após o delimitador `/**`, até e, possivelmente, incluindo a linha que contém o delimitador `*/`.

Alguns exemplos:

- A única parte do comentário a seguir que será processada é a linha que começa com `<summary>`. Os dois seguintes formatos de marcação produzirão os mesmos comentários:

    ```cpp
    /**
    <summary>text</summary>
    */
    /** <summary>text</summary> */
    ```

- O compilador aplica o padrão "\*" a ser ignorado no início da segunda e da terceira linhas.

    ```cpp
    /**
     * <summary>
     *  text </summary>*/
    ```

- O compilador não encontra nenhum padrão nesse comentário porque não há nenhum asterisco na segunda linha. Portanto, todo o texto na segunda e terceira linhas, até o `*/`, será processado como parte do comentário.

    ```cpp
    /**
     * <summary>
       text </summary>*/
    ```

- O compilador não encontra nenhum padrão nesse comentário por dois motivos. Primeiro, não há nenhuma linha que começa com um número consistente de espaços antes do asterisco. Segundo, a quinta linha começa com uma guia, que não coincide com espaços. Portanto, todo o texto da segunda linha até o `*/` será processado como parte do comentário.

    ```cpp
    /**
      * <summary>
      * text
     *  text2
       *  </summary>
    */
    ```

## <a name="see-also"></a>Confira também

[Documentação XML](xml-documentation-visual-cpp.md)
