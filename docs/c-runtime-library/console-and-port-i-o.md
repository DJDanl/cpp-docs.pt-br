---
title: "Console e E/S de porta | Microsoft Docs"
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
  - "E/S [CRT], console"
  - "E/S [CRT], porta"
  - "rotinas de E/S, console e E/S de porta"
  - "portas, rotinas de E/S"
  - "Rotinas "
  - "Rotinas , console e E/S de porta"
ms.assetid: 0eee1c92-9b3d-41e0-a43a-257e546eeec8
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Console e E/S de porta
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Leitura e gravação dessas rotinas no console ou na porta especificada.  As rotinas de E\/S do console não são compatíveis com o fluxo de E\/S ou rotinas de biblioteca de nível baixo de E\/S.  O console ou a porta não precisam ser aberto ou fechado antes de E\/S seja executado, assim não há nenhuma rotina aberta ou próximo nessa categoria.  Nos sistemas operacionais Windows, a saída dessas funções são sempre direcionadas ao console e não podem ser redirecionadas.  
  
### Rotinas de E\/S do console e porta  
  
|Rotina|Uso|  
|------------|---------|  
|[\_cgets, \_cgetws](../c-runtime-library/cgets-cgetws.md), [\_cgets\_s, \_cgetws\_s](../Topic/_cgets_s,%20_cgetws_s.md)|Cadeia de caracteres de leitura do console|  
|[\_cprintf, \_cwprintf](../c-runtime-library/reference/cprintf-cprintf-l-cwprintf-cwprintf-l.md), [\_cprintf\_s, \_cprintf\_s\_l, \_cwprintf\_s, \_cwprintf\_s\_l](../c-runtime-library/reference/cprintf-s-cprintf-s-l-cwprintf-s-cwprintf-s-l.md)|Dados formatados de gravação ao console|  
|[\_cputs](../Topic/_cputs,%20_cputws.md)|Cadeia de caracteres de gravação ao console|  
|[\_cscanf, \_cwscanf](../c-runtime-library/reference/cscanf-cscanf-l-cwscanf-cwscanf-l.md), [\_cscanf\_s, \_cscanf\_s\_l, \_cwscanf\_s, \_cwscanf\_s\_l](../c-runtime-library/reference/cscanf-s-cscanf-s-l-cwscanf-s-cwscanf-s-l.md)|Dados formatados de leitura do console|  
|[\_getch, \_getwch](../Topic/_getch,%20_getwch.md)|Caractere de leitura do console|  
|[\_getche, \_getwche](../Topic/_getch,%20_getwch.md)|O caractere de leitura do console e ecoa\-o|  
|[\_inp](../c-runtime-library/inp-inpw-inpd.md)|Leitura um byte da porta especificada de E\/S|  
|[\_inpd](../c-runtime-library/inp-inpw-inpd.md)|Palavra dupla de leitura da porta especificada de E\/S|  
|[\_inpw](../c-runtime-library/inp-inpw-inpd.md)|Leitura palavras de 2 bytes de porta especificada de E\/S|  
|[\_kbhit](../c-runtime-library/reference/kbhit.md)|Verificação para o pressionamento da tecla no console; use antes de tentar ler a partir do console|  
|[\_outp](../Topic/_outp,%20_outpw,%20_outpd.md)|Gravação uma porta especificada de E\/S de byte|  
|[\_outpd](../Topic/_outp,%20_outpw,%20_outpd.md)|Porta especificada dupla de E\/S do word de gravação|  
|[\_outpw](../Topic/_outp,%20_outpw,%20_outpd.md)|Porta especificada de E\/S do word de gravação|  
|[\_putch, \_putwch](../Topic/_putch,%20_putwch.md)|Caractere de gravação ao console|  
|[\_ungetch, \_ungetwch](../c-runtime-library/reference/ungetch-ungetwch-ungetch-nolock-ungetwch-nolock.md)|A leitura do último caractere “Unget” do console de forma que ele se tornará leitura seguir de caractere|  
  
## Consulte também  
 [Entrada e saída](../Topic/Input%20and%20Output.md)   
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)