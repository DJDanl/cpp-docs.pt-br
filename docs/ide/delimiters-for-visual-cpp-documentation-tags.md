---
title: "Delimitadores de marcas de documenta&#231;&#227;o para o Visual C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "documentação XML, delimitadores"
ms.assetid: debfbdd9-63fa-4c58-a18e-a4d203d241d7
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Delimitadores de marcas de documenta&#231;&#227;o para o Visual C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O uso de marcas de documentação requer os delimitadores, que indicam o compilador onde um comentário da documentação começam e terminam.  
  
 Você pode usar os seguintes tipos de delimitadores com as marcas de documentação XML:  
  
 `///`  
 Este é o formulário que é mostrado em exemplos de documentação e usado pelos modelos de projeto Visual C\+\+.  
  
 `/** */`  
 Esses são delimitadores de várias linhas.  
  
 Há algumas regras de formatação ao usar os delimitadores de `/** */` \*\/:  
  
-   Para a linha que contém o delimitador de `/**`, se o restante da linha é o espaço em branco, a linha não é processada para comentários.  Se o primeiro caractere é o espaço em branco, o caractere de espaço em branco será ignorado e o resto da linha é processado.  Caso contrário, o texto inteiro de linha após o delimitador de `/**` é processado como parte do comentário.  
  
-   Para a linha que contém o delimitador de `*/`, se houver somente espaço em branco até o delimitador de `*/` , a linha será ignorada.  Caso contrário, o texto em training ao delimitador de `*/` é processado como parte de comentário, sujeitos a regras de coincidência de padrão descritas no seguinte marcador.  
  
-   Para linha após o que começa com o delimitador de `/**` , o compilador procura por um padrão comum no início de cada linha que consiste no espaço em branco opcional e um asterisco \(`*`\), seguido por um espaço em branco mais opcional.  Se o compilador encontra um conjunto comum de caracteres definida no início de cada linha, irá ignorar esse padrão para todas as linhas após o delimitador de `/**` , até e possivelmente incluindo a linha que contém o delimitador de `*/` .  
  
 Alguns exemplos:  
  
-   A única parte da seguir comentário que será processado é a linha que inicia com `<summary>`.  Os dois seguintes formatos de marca irão gerar os mesmos comentários:  
  
    ```  
    /**  
    <summary>text</summary>   
    */  
    /** <summary>text</summary> */  
    ```  
  
-   O compilador aplica um padrão de “\*” para ignorar no início da segunda e terceira linhas.  
  
    ```  
    /**  
     * <summary>  
     *  text </summary>*/  
    ```  
  
-   O compilador não encontrar nenhum padrão no comentário porque não há nenhum asterisco na segunda linha.  Portanto, qualquer texto na segunda e terceira linhas, acima até de `*/`, será processado como parte do comentário.  
  
    ```  
    /**  
     * <summary>  
       text </summary>*/  
    ```  
  
-   O compilador não encontrar nenhum padrão no comentário por dois motivos.  Primeiro, não há nenhuma linha que inicia com um número consistente de espaços antes de asterisco.  Segundo, a quinta linha começa com um guia, que não corresponde aos espaços.  Portanto, qualquer texto da segunda linha até `*/` será processado como parte do comentário.  
  
    ```  
    /**  
      * <summary>  
      * text   
     *  text2  
       *  </summary>  
    */  
    ```  
  
## Consulte também  
 [A Documentação XML](../ide/xml-documentation-visual-cpp.md)