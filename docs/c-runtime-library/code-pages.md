---
title: "P&#225;ginas de c&#243;digo | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "c.international"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "ANSI [C++], páginas de código"
  - "conjunto de caracteres [C++], páginas de código"
  - "páginas de código [C++], tipos de"
  - "páginas de código de localidade [C++]"
  - "localização [C++], páginas de código"
  - "páginas de código multibyte [C++]"
  - "página de códigos padrão do sistema"
ms.assetid: 4a26fc42-185a-4add-98bf-a7b314ae6186
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# P&#225;ginas de c&#243;digo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

`code page` é um conjunto de caracteres, que pode incluir números, marcas de pontuação, e outros glifos.  Os idiomas diferentes e as localidades podem usar páginas de código diferentes.  Por exemplo, a página de código 1252 ANSI é usada para inglês e a maioria dos idiomas europeus; A página de código OEM 932 é usada para o Kanji japonês.  
  
 Uma página de código pode ser representada em uma tabela como um mapeamento de caracteres com os valores de byte único ou os valores de vários bytes.  Muitas páginas de código diferentes compartilharem o conjunto de caracteres ASCII de caracteres no intervalo 0x00 – 0x7F.  
  
 A biblioteca de tempo de execução Microsoft usa os seguintes tipos de páginas de código:  
  
-   Página de código ANSI de sistema padrão.  Por padrão, ao inicializar o sistema de tempo de execução define automaticamente a página de código de multibyte para a página de código ANSI de sistema padrão, que é obtida do sistema operacional.  A chamada:  
  
    ```  
    setlocale ( LC_ALL, "" );  
    ```  
  
     também define a localidade para a página de código ANSI de sistema padrão.  
  
-   Página de código da localidade.  O comportamento de um número de rotinas de tempo de execução é dependente da configuração de localidade atual, que inclui a página de código da localidade. \(Para obter mais informações, consulte [Rotinas de localidade dependente](../c-runtime-library/locale.md).\) Por padrão, todas as rotinas de localidade dependente na biblioteca de tempo de execução Microsoft usam a página de código correspondente à localidade de C “2.0”.  Em tempo de execução é possível modificar ou consulte a página de código da localidade em uso com uma chamada a [setlocale](../Topic/setlocale,%20_wsetlocale.md).  
  
-   Página de código de Multibyte.  O comportamento da maioria das rotinas de multibyte\- caractere na biblioteca de tempo de execução depende da composição atual do código de multibyte.  Por padrão, essas rotinas usam a página de código ANSI de sistema padrão.  Em tempo de execução você pode consultar e modificar a página de código de multibyte com [\_getmbcp](../c-runtime-library/reference/getmbcp.md) e [\_setmbcp](../c-runtime-library/reference/setmbcp.md), respectivamente.  
  
-   A localidade de C “2.0” é definida por ANSI para corresponder à localidade em que os programas de 2.0 c executaram tradicional.  A página de código da localidade de “C” 2.0 \(página de código de “C” 2.0\) corresponde ao conjunto de caracteres ASCII.  Por exemplo, na localidade de C “2.0”, `islower` retorna true para os valores 0x61 – 0x7A somente.  Em outra localidade, `islower` pode retornar true para esses bem como outros valores, como definido por essa localidade.  
  
## Consulte também  
 [Internacionalização](../c-runtime-library/internationalization.md)   
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)