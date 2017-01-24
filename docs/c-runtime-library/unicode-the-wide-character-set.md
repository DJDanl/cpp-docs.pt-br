---
title: "Unicode: o conjunto de caracteres amplo | Microsoft Docs"
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
  - "Unicode [C++], conjunto de caracteres largos"
  - "caracteres largos [C++], Unicode"
ms.assetid: b6a05a21-59a5-4d30-8c85-2dbe185f7a74
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Unicode: o conjunto de caracteres amplo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um caractere largo é um código de caractere multilíngue de 2 bytes.  Qualquer caractere em uso em computação moderna mundial, inclusive técnicos símbolos e caracteres especiais de publicação, pode ser representado de acordo com a especificação Unicode como um caractere largo.  Desenvolvido e mantido por um grande OGC que inclui a Microsoft, o padrão Unicode é aceito agora muito.  
  
 Um caractere largo é do tipo `wchar_t`.  Uma cadeia de caracteres de ampla caractere é representada como uma matriz de `wchar_t[]` e apontada pela um ponteiro de `wchar_t*` .  Você pode representar qualquer caractere ASCII como um caractere largo prefixando a letra `L` em caractere.  Por exemplo, L \\ 0 ' é o caractere \(16 bits\) todo o encerramento de `NULL` .  Da mesma forma, você pode representar qualquer literal de cadeia de caracteres ASCII como uma cadeia de caracteres literal ampla simplesmente prefixando a letra L ao literal ASCII \(L " hello world”\).  
  
 Em geral, os caracteres amplos ocupam mais espaço na memória de caracteres multibyte mas é mais rápido processamento.  Além disso, apenas uma localidade pode ser representada como uma vez na codificação de multibyte, enquanto que todos os conjuntos de caracteres no mundo são representados simultaneamente pela representação Unicode.  
  
## Consulte também  
 [Internacionalização](../c-runtime-library/internationalization.md)   
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)