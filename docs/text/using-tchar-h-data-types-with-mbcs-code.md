---
title: "Usando tipos de dados TCHAR.H com c&#243;digo _MBCS | Microsoft Docs"
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
  - ""tchar.h""
  - "TCHAR"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tipos de dados de texto genérico [C++]"
  - "mapeamentos de texto genérico [C++]"
  - "mapeando texto genérico"
  - "mapeamentos [C++], TCHAR.H"
  - "MBCS [C++], mapeamentos de texto genérico"
  - "Tipos de dados TCHAR.H, mapeamento"
ms.assetid: 298583c5-22c3-40f6-920e-9ec96d42abd8
caps.latest.revision: 7
caps.handback.revision: 7
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# Usando tipos de dados TCHAR.H com c&#243;digo _MBCS
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando **\_MBCS** constante manifesto for definido, mapas dados de uma rotina de genérico\- texto a um dos seguintes tipos de rotinas:  
  
-   Uma rotina de SBCS que trata bytes, caracteres, e cadeias de caracteres multibyte adequadamente.  Nesse caso, os argumentos de cadeia de caracteres devem ser do tipo **char\***.  Por exemplo, mapas de `_tprintf` a `printf`; os argumentos de cadeia de caracteres a `printf` são do tipo **char\***.  Se você usar o tipo de dados de genérico\- texto de **\_TCHAR** para seus tipos de cadeia de caracteres, os tipos de parâmetro formal com e reais para `printf` correspondem porque **\_TCHAR**\* é mapeado para **char\***.  
  
-   Uma rotina MBCS\-específica.  Nesse caso, os argumentos de cadeia de caracteres devem ser do tipo `unsigned` **char\***.  Por exemplo, mapas de `_tcsrev` a `_mbsrev`, que espera e retorna uma cadeia de caracteres de tipo `unsigned` **char\***.  Se você usar o tipo de dados de genérico\- texto de **\_TCHAR** para seus tipos de cadeia de caracteres, há um conflito potencial do tipo porque os mapas de **\_TCHAR** para digitar `char`.  
  
 A lista a seguir apresenta três soluções para evitar esse conflito de tipo \(e os avisos do compilador do compilador C ou C\+\+ erros que resultariam\):  
  
-   Use o comportamento padrão.  Tchar.h fornece o texto genérico\- protótipos de rotina para rotinas em bibliotecas de tempo de execução, como no exemplo a seguir.  
  
    ```  
    char * _tcsrev(char *);  
    ```  
  
     Nas caixas padrão, o protótipo para mapas de `_tcsrev` a `_mbsrev` por meio de um thunk em Libc.lib.  Isso altera os tipos de parâmetros de entrada de `_mbsrev` e o valor de retorno de saída de  **\_TCHAR\*** \(isto é, `char` **\***\) a  `unsigned``char` **\***.  Esse método garante a correspondência de tipo quando você estiver usando **\_TCHAR**, mas é relativamente lento devido a sobrecarga da chamada de função.  
  
-   Use a função que inlining inserindo a seguinte instrução de pré\-processador em seu código.  
  
    ```  
    #define _USE_INLINING  
    ```  
  
     Esse método faz um thunk da função embutida, desde que em Tchar.h, mapeie a rotina de genérico\- texto diretamente para a rotina apropriado de MBCS.  O trecho de código de Tchar.h fornece um exemplo de como isso é feito.  
  
    ```  
    __inline char *_tcsrev(char *_s1)  
    {return (char *)_mbsrev((unsigned char *)_s1);}  
    ```  
  
     Se você pode usar inlining, esta será a melhor solução, porque garante a correspondência do tipo e não tem nenhum custo de tempo adicional.  
  
-   Mapeamento direto de uso inserindo a seguinte instrução de pré\-processador em seu código.  
  
    ```  
    #define _MB_MAP_DIRECT  
    ```  
  
     Esta abordagem fornece uma alternativa rápida se você não quiser usar o comportamento padrão nem pode usar inlining.  Faz com que a rotina de genérico\- texto a ser mapeada por uma macro diretamente à versão de MBCS da rotina, como no exemplo de Tchar.h.  
  
    ```  
    #define _tcschr _mbschr  
    ```  
  
     Quando você usa essa abordagem, você deve ter cuidado para assegurar o uso de tipos de dados apropriados para argumentos de cadeia de caracteres e retornam valores de cadeia de caracteres.  Você pode usar a conversão de tipo para assegurar que a correspondência adequada ou é do tipo UDT possam usar o tipo de dados de genérico\- texto de **\_TXCHAR** .  mapas de**\_TXCHAR** para digitar `char` no código de SBCS mas mapeia para digitar `unsigned` `char` no código de MBCS.  Para obter mais informações sobre macros de genérico\- texto, consulte [Mapeamentos de Genérico\- texto](../c-runtime-library/generic-text-mappings.md)*na referência da biblioteca de tempo de execução*.  
  
## Consulte também  
 [Mapeamentos de texto genéricos em Tchar.h](../Topic/Generic-Text%20Mappings%20in%20Tchar.h.md)