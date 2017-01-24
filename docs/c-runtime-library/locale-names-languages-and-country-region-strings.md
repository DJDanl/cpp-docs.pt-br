---
title: "Nomes de localidades, idiomas e cadeias de caracteres de pa&#237;s-regi&#227;o | Microsoft Docs"
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
  - "c.strings"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "cadeias de caracteres de país/região"
  - "localização, localidade"
  - "localidades"
  - "setlocale - função"
  - "cadeias de caracteres de idioma"
ms.assetid: a0e5a0c5-5602-4da0-b65f-de3d6c8530a2
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Nomes de localidades, idiomas e cadeias de caracteres de pa&#237;s/regi&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O `locale` argumento para o `setlocale` e `_create_locale` funções podem ser definidas usando os nomes de localidades, idiomas, códigos de país\/região e páginas de código que são suportadas pela API NLS do Windows. O `locale` argumento usa o seguinte formato:  
  
```  
  
locale :: "locale_name"  
        | "language[_country_region[.code_page]]"  
        | ".code_page"  
        | "C"  
        | ""  
        | NULL  
```  
  
 O formato de nome da localidade — por exemplo, `en-US` para inglês \(Estados Unidos\) ou `bs-Cyrl-BA` para bósnio \(cirílico, Bósnia e Herzegovina\) — é preferido. O conjunto de nomes de localidade é descrito em [nomes de localidades](http://msdn.microsoft.com/library/windows/desktop/dd373814.aspx). Para obter uma lista de nomes de localidades com suporte pela versão do sistema operacional Windows, consulte o **nome de cultura** coluna o [referência de API de suporte ao idioma nacional \(NLS\)](http://msdn.microsoft.com/goglobal/bb896001.aspx). Esse recurso lista as partes de linguagem, script e região com suporte dos nomes de localidade. Para obter informações sobre os nomes de localidade com suporte que têm não padrão ordens de classificação, consulte o **nome da localidade** coluna [identificadores de ordem de classificação](http://msdn.microsoft.com/library/windows/desktop/dd374060.aspx).  
  
 O *idioma*\[\_*country\_region*\[.*code\_page*\]\] formulário é armazenado na configuração de localidade para uma categoria quando uma cadeia de caracteres de idioma, ou cadeia de caracteres de idioma e cadeia de caracteres de país\/região, é usada para criar a localidade. O conjunto de cadeias de caracteres de idioma com suporte é descrito em [Cadeias de caracteres de idioma](../c-runtime-library/language-strings.md), e a lista de cadeias de caracteres de país\/região com suporte é listada em [Cadeias de caracteres de país\/região](../c-runtime-library/country-region-strings.md). Se o idioma especificado não está associado com o país\/região especificado, o idioma padrão para o país\/região especificado é armazenado na configuração de localidade. Não recomendamos essa forma de cadeias de caracteres de localidade inseridas no código ou serializadas para armazenamento, pois essas cadeias de caracteres são mais prováveis de serem modificadas por uma atualização do sistema operacional que o formato de nome de localidade.  
  
 A página de código é a página de código ANSI\/OEM associado com a localidade. A página de código é determinada por você ao especificar uma localidade por idioma ou por idioma e país\/região apenas. O valor especial `.ACP` Especifica a página de código ANSI para o país\/região. O valor especial `.OCP` Especifica a página de código OEM para o país\/região. Por exemplo, se você especificar `"Greek_Greece.ACP"` como a localidade, a localidade é armazenada como `Greek_Greece.1253` \(página de código ANSI para grego\), e se você especificar `"Greek_Greece.OCP"` como a localidade, ela é armazenada como `Greek_Greece.737` \(a página de código OEM para grego\). Para obter mais informações sobre páginas de código, consulte [Páginas de código](../c-runtime-library/code-pages.md). Para obter uma lista de páginas de código suportadas no Windows, consulte [identificadores de página de código](http://msdn.microsoft.com/library/windows/desktop/dd317756.aspx).  
  
 Se você usar a página de código para especificar a localidade, o país\/região e idioma padrão do sistema são usados. Por exemplo, se você especificar `".1254"` \(turco ANSI\) como a localidade em um sistema que está configurado para inglês \(Estados Unidos\), a localidade armazenada é `English_United States.1254`. Não recomendamos essa forma, pois isso poderia resultar em comportamento inconsistente.  
  
 Um `locale` valor `C` Especifica o ambiente em conformidade mínima com ANSI para conversão em C. O `C` localidade pressupõe que cada `char` tipo de dados é 1 byte e seu valor é sempre menor que 256. Se `locale` aponta para uma cadeia de caracteres vazia, a localidade é o ambiente nativo definido pela implementação.  
  
 Você pode especificar todas as categorias de localidade ao mesmo tempo para o `setlocale` e `_wsetlocale` funções usando o `LC_ALL` categoria. As categorias podem ser definidas para a mesma localidade, ou você pode definir cada categoria individualmente usando um argumento de localidade que tenha esta forma:  
  
```  
LC_ALL_specifier :: locale  
        | [LC_COLLATE=locale][;LC_CTYPE=locale][;LC_MONETARY=locale][;LC_NUMERIC=locale][;LC_TIME=locale]  
  
```  
  
 Você pode especificar vários tipos de categoria, separados por ponto e vírgula. Tipos de categoria não especificados usam a configuração de localidade atual. Por exemplo, este código define a localidade atual para todas as categorias para `de-DE`, e, em seguida, define as categorias de `LC_MONETARY` para `en-GB` e `LC_TIME` para `es-ES`:  
  
 `_wsetlocale(LC_ALL, L"de-DE");`  
  
 `_wsetlocale(LC_ALL, L"LC_MONETARY=en-GB;LC_TIME=es-ES");`  
  
## Consulte também  
 [Referência da biblioteca em tempo de execução do C](../c-runtime-library/c-run-time-library-reference.md)   
 [\_get\_current\_locale](../Topic/_get_current_locale.md)   
 [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)   
 [\_create\_locale, \_wcreate\_locale](../c-runtime-library/reference/create-locale-wcreate-locale.md)   
 [Cadeias de caracteres de idioma](../c-runtime-library/language-strings.md)   
 [Cadeias de caracteres de país\/região](../c-runtime-library/country-region-strings.md)