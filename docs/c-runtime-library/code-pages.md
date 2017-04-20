---
title: "Páginas de código | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- c.international
dev_langs:
- C++
helpviewer_keywords:
- character sets [C++], code pages
- ANSI [C++], code pages
- system-default code page
- multibyte code pages [C++]
- localization [C++], code pages
- code pages [C++], types of
- locale code pages [C++]
ms.assetid: 4a26fc42-185a-4add-98bf-a7b314ae6186
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Human Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: dc4480e79931f1ad3c1dc81b9687e82fcb2697a7
ms.lasthandoff: 04/01/2017

---
# <a name="code-pages"></a>Páginas de código
`code page` é um conjunto de caracteres, que pode incluir números, marcas de pontuação e outros glifos. Localidades e idiomas diferentes usam diferentes páginas de código. Por exemplo, a página de código ANSI 1252 é usada para inglês e a maioria dos idiomas europeus; a página de código OEM 932 é usada para japonês kanji.  
  
 Uma página de código pode ser representada em uma tabela como mapeamento de caracteres para valores de byte único ou multibyte. Muitas páginas de código compartilham o conjunto de caracteres ASCII no intervalo 0x00 – 0x7F.  
  
 A biblioteca em tempo de execução da Microsoft usa os seguintes tipos de página de código:  
  
-   Página de código ANSI padrão do sistema. Por padrão, na inicialização, o sistema de tempo de execução define automaticamente a página de código multibyte para a página de código ANSI padrão do sistema, que é obtida do sistema operacional. A chamada:  
  
    ```  
    setlocale ( LC_ALL, "" );  
    ```  
  
     também define a localidade para a página de código ANSI padrão do sistema.  
  
-   Página de código de localidade. O comportamento de várias rotinas de tempo de execução depende da configuração de localidade atual, que inclui a página de código de localidade. (Para obter mais informações, consulte [Rotinas dependentes de localidade](../c-runtime-library/locale.md).) Por padrão, todas as rotinas dependentes de localidade da biblioteca de tempo de execução da Microsoft usam a página de código que corresponde à localidade "C". Em tempo de execução, você pode alterar ou consultar a página de código de localidade em uso com uma chamada para [setlocale](../c-runtime-library/reference/setlocale-wsetlocale.md).  
  
-   Página de código multibyte. O comportamento da maioria das rotinas de caracteres multibyte da biblioteca de tempo de execução depende da configuração atual de página de código multibyte. Por padrão, essas rotinas usam a página de código ANSI padrão do sistema. Em tempo de execução, você pode consultar e alterar a página de código multibyte com [_getmbcp](../c-runtime-library/reference/getmbcp.md) e [_setmbcp](../c-runtime-library/reference/setmbcp.md), respectivamente.  
  
-   A localidade "C" é definida pela ANSI para corresponder à localidade em que os programas em C foram tradicionalmente executados. A página de código para a localidade "C" (página de código "C") corresponde ao conjunto de caracteres ASCII. Por exemplo, na localidade "C", `islower` retorna true apenas para os valores 0x61 – 0x7A. Em outra localidade, `islower` pode retornar true para esses e para outros valores, conforme definido por essa localidade.  
  
## <a name="see-also"></a>Consulte também  
 [Internacionalização](../c-runtime-library/internationalization.md)   
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)
