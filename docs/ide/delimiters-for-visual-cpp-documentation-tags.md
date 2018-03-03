---
title: "Delimitadores para marcações de documentação do Visual C++ | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- XML documentation, delimiters
ms.assetid: debfbdd9-63fa-4c58-a18e-a4d203d241d7
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 134605f86ef8019d34f5246fd75abbbf94d40fbc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="delimiters-for-visual-c-documentation-tags"></a>Delimitadores de marcações de documentação para o Visual C++
O uso de marcações de documentação requer delimitadores, que indicam para o compilador onde um comentário de documentação começa e termina.  
  
 Você pode usar os seguintes tipos de delimitadores com as marcas de documentação XML:  
  
 `///`  
 Este é o formulário que é mostrado nos exemplos de documentação e usado pelos modelos de projeto do Visual C++.  
  
 `/** */`  
 Esses são os delimitadores de várias linhas.  
  
 Há alguma formatação regras ao usar o `/** */` delimitadores:  
  
-   Para a linha que contém o `/**` delimitador, se o restante da linha é o espaço em branco, a linha não será processado para comentários. Se o primeiro caractere é um espaço em branco, esse caractere de espaço em branco será ignorado e o restante da linha é processado. Caso contrário, todo o texto da linha após o delimitador `/**` é processado como parte do comentário.  
  
-   Para a linha que contém o `*/` delimitador, se houver apenas espaços em branco até o `*/` delimitador, essa linha será ignorada. Caso contrário, o texto da linha até o delimitador `*/` é processado como parte do comentário, sujeito às regras de correspondência de padrão descritas no marcador seguinte.  
  
-   Para as linhas depois que começa com o `/**` delimitador, o compilador procura um padrão comum no início de cada linha que consiste de espaço em branco opcional e um asterisco (`*`), seguido de mais espaço em branco opcional. Se o compilador encontra um conjunto comum de caracteres no início de cada linha, ele ignorará esse padrão para todas as linhas após o `/**` delimitador, até e, possivelmente, incluindo a linha que contém o `*/` delimitador.  
  
 Alguns exemplos:  
  
-   A única parte do comentário a seguir que será processada é a linha que começa com `<summary>`. Os seguintes formatos de duas marca produzirá os mesmos comentários:  
  
    ```  
    /**  
    <summary>text</summary>   
    */  
    /** <summary>text</summary> */  
    ```  
  
-   O compilador aplica um padrão de "*" para ignorar no início da segunda e terceira linhas.  
  
    ```  
    /**  
     * <summary>  
     *  text </summary>*/  
    ```  
  
-   O compilador não encontra nenhum padrão deste comentário porque não há nenhum asterisco na segunda linha. Portanto, todo o texto na segunda e terceira linhas, para cima até o `*/`, será processado como parte do comentário.  
  
    ```  
    /**  
     * <summary>  
       text </summary>*/  
    ```  
  
-   O compilador não encontra nenhum padrão deste comentário por dois motivos. Primeiro, não há nenhuma linha que começa com um número consistente de espaços antes do asterisco. Segundo, a quinta linha começa com uma guia, que não coincide com espaços. Portanto, todo o texto da segunda linha até que o `*/` será processado como parte do comentário.  
  
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