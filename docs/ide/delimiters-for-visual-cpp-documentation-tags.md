---
title: Delimitadores de marcas de documentação para o Visual C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- XML documentation, delimiters
ms.assetid: debfbdd9-63fa-4c58-a18e-a4d203d241d7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a2394516773f428ae62fb9e8e39dd78dd790bebd
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46033908"
---
# <a name="delimiters-for-visual-c-documentation-tags"></a>Delimitadores de marcações de documentação para o Visual C++
O uso de marcas de documentação exige delimitadores, que indicam ao compilador o local em que um comentário da documentação começa e termina.  
  
 Você pode usar os seguintes tipos de delimitadores com as marcas de documentação XML:  
|||
|-|-|
|`///`  | Esse é o formulário mostrado nos exemplos de documentação e usado pelos modelos de projeto do Visual C++.  |
| `/** */`  | Veja abaixo os delimitadores multilinha.  |
  
Há algumas regras de formatação no uso dos delimitadores `/** */`:  
  
-   Na linha que contém o delimitador `/**`, se o restante da linha é um espaço em branco, a linha não é processada para comentários. Se o primeiro caractere é um espaço em branco, esse caractere de espaço em branco é ignorado e o restante da linha é processado. Caso contrário, todo o texto da linha após o delimitador `/**` é processado como parte do comentário.  
  
-   Na linha que contém o delimitador `*/`, se há apenas um espaço em branco até o delimitador `*/`, essa linha é ignorada. Caso contrário, o texto da linha até o delimitador `*/` é processado como parte do comentário, sujeito às regras de correspondência de padrão descritas no marcador seguinte.  
  
-   Nas linhas após aquela que começa com o delimitador `/**`, o compilador procura um padrão comum no início de cada linha que consiste em um espaço em branco opcional e um asterisco (`*`), seguido por mais um espaço em branco opcional. Se o compilador encontrar um conjunto comum de caracteres no início de cada linha, ele ignorará esse padrão em todas as linhas após o delimitador `/**`, até e, possivelmente, incluindo a linha que contém o delimitador `*/`.  
  
Alguns exemplos:  
  
-   A única parte do comentário a seguir que será processada é a linha que começa com `<summary>`. Os dois seguintes formatos de marcação produzirão os mesmos comentários:  
  
    ```  
    /**  
    <summary>text</summary>   
    */  
    /** <summary>text</summary> */  
    ```  
  
-   O compilador aplica o padrão "\*" a ser ignorado no início da segunda e da terceira linhas.  
  
    ```  
    /**  
     * <summary>  
     *  text </summary>*/  
    ```  
  
-   O compilador não encontra nenhum padrão nesse comentário porque não há nenhum asterisco na segunda linha. Portanto, todo o texto na segunda e terceira linhas, até o `*/`, será processado como parte do comentário.  
  
    ```  
    /**  
     * <summary>  
       text </summary>*/  
    ```  
  
-   O compilador não encontra nenhum padrão nesse comentário por dois motivos. Primeiro, não há nenhuma linha que começa com um número consistente de espaços antes do asterisco. Segundo, a quinta linha começa com uma guia, que não coincide com espaços. Portanto, todo o texto da segunda linha até o `*/` será processado como parte do comentário.  
  
    ```  
    /**  
      * <summary>  
      * text   
     *  text2  
       *  </summary>  
    */  
    ```  
  
## <a name="see-also"></a>Consulte também  
 [Documentação XML](../ide/xml-documentation-visual-cpp.md)