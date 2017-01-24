---
title: "Unicode fluxo I-O em modos de texto e bin&#225;rios | Microsoft Docs"
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
  - "c.io"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "rotinas de E/S de fluxo"
  - "E/s [CRT] fluxo unicode"
  - "Unicode, rotinas de e/s de fluxo"
  - "E/S de fluxo Unicode"
ms.assetid: 68be0c3e-a9e6-4fd5-b34a-1b5207f0e7d6
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# E/S de fluxo Unicode em modos de texto e bin&#225;rios
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando a rotina de e\/s de fluxo Unicode \(como `fwprintf`, `fwscanf`, `fgetwc`, `fputwc`, `fgetws`, ou `fputws`\) opera em um arquivo que está aberto no modo de texto \(o padrão\), dois tipos de caractere conversões ocorrem:  
  
-   Conversão de Unicode em MBCS ou MBCS para Unicode. Quando uma função de e\/S de fluxo Unicode opera em modo de texto, a fonte ou fluxo de destino deve para ser uma seqüência de caracteres multibyte. Portanto, as funções de entrada de fluxo Unicode convertem caracteres multibyte para caracteres largos \(como por uma chamada para o `mbtowc` função\). Pelo mesmo motivo, as funções de saída de fluxo do Unicode convertem caracteres largos para caracteres multibyte \(como por uma chamada para o `wctomb` função\).  
  
-   Retorno de carro – conversão de avanço de linha \(CR\-LF\). Essa conversão ocorre antes do MBCS – conversão Unicode \(para funções de entrada de fluxo Unicode\) e depois o Unicode – conversão de MBCS \(para funções de saída de fluxo Unicode\). Durante a entrada, cada retorno de carro – combinação de alimentação de linha é convertido em um caractere de avanço de linha única. Durante a saída, cada caractere de avanço de linha é convertido em um retorno de carro – combinação de avanço de linha.  
  
 No entanto, quando uma função de e\/S de fluxo Unicode opera no modo binário, o arquivo é considerado como Unicode, e nenhuma conversão de conversão ou caracteres CR\-LF ocorre durante a entrada ou saída. Usar o setmode \( fileno \(stdin\), o\_binary\); instruções para usar corretamente o wcin em um arquivo de texto UNICODE.  
  
## Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)   
 [Entrada e saída](../Topic/Input%20and%20Output.md)