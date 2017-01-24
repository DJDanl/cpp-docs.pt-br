---
title: "Usando tipos de dados TCHAR.H com _MBCS | Microsoft Docs"
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
  - "_mbcs"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Tipo de dados _MBCS"
  - "Tipo de dados MBCS"
  - "Tipos de dados TCHAR.H"
ms.assetid: 48f471e7-9d2b-4a39-b841-16a0e15c0a18
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Usando tipos de dados TCHAR.H com _MBCS
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Como a tabela de mapeamentos de rotina de genérico\- texto indica [Mapeamentos de Genérico\- texto](../c-runtime-library/generic-text-mappings.md)\(consulte\), quando `_MBCS` constante manifesto tenha sido definido, mapas dados de uma rotina de genérico\- texto a um dos seguintes tipos de rotinas:  
  
-   Uma rotina de SBCS que trata bytes, caracteres, e cadeias de caracteres multibyte adequadamente.  Nesse caso, os argumentos de cadeia de caracteres devem ser do tipo `char*`.  Por exemplo, mapas de `_tprintf` a `printf`; os argumentos de cadeia de caracteres a `printf` são do tipo `char*`.  Se você usar o tipo de dados de genérico\- texto de `_TCHAR` para seus tipos de cadeia de caracteres, os tipos de parâmetro formal com e reais para `printf` correspondem como mapas de `_TCHAR*` a `char*`.  
  
-   Uma rotina MBCS\-específica.  Nesse caso, os argumentos de cadeia de caracteres devem ser do tipo `unsigned char*`.  Por exemplo, mapas de `_tcsrev` a `_mbsrev`, que espera e retorna uma cadeia de caracteres de tipo `unsigned char*`.  Além disso, se você usar o tipo de dados de genérico\- texto de `_TCHAR` para seus tipos de cadeia de caracteres, há um conflito potencial do tipo porque os mapas de `_TCHAR` para digitar `char`.  
  
 A lista a seguir apresenta três soluções para evitar esse conflito de tipo \(e os avisos do compilador do compilador C ou C\+\+ erros que resultariam\):  
  
-   Use o comportamento padrão.  TCHAR.H fornece o texto genérico\- protótipos de rotina para rotinas em bibliotecas de tempo de execução, como no exemplo a seguir.  
  
    ```  
    char *_tcsrev(char *);  
    ```  
  
     Nas caixas padrão, o protótipo para mapas de `_tcsrev` a `_mbsrev` por meio de um thunk em LIBC.LIB.  Isso altera os tipos de parâmetros de entrada de `_mbsrev` e o valor de retorno de saída de `_TCHAR *` \(como\) `char *`a `unsigned char *`.  Esse método garante a correspondência de tipo quando você estiver usando `_TCHAR`, mas é relativamente lento devido a sobrecarga da chamada de função.  
  
-   Use a função que inlining inserindo a seguinte instrução de pré\-processador em seu código.  
  
    ```  
    #define _USE_INLINING  
    ```  
  
     Esse método faz um thunk da função embutida, desde que em TCHAR.H, mapeie a rotina de genérico\- texto diretamente para a rotina apropriado de MBCS.  O trecho de código de TCHAR.H fornece um exemplo de como isso é feito.  
  
    ```  
    __inline char *_tcsrev(char *_s1)  
    {return (char *)_mbsrev((unsigned char *)_s1);}  
    ```  
  
     Se você pode usar inlining, esta será a melhor solução, porque garante a correspondência do tipo e não tem nenhum custo de tempo adicional.  
  
-   Use “mapeamento direto” inserindo a seguinte instrução de pré\-processador em seu código.  
  
    ```  
    #define _MB_MAP_DIRECT  
    ```  
  
     Esta abordagem fornece uma alternativa rápida se você não quiser usar o comportamento padrão nem pode usar inlining.  Faz com que a rotina de genérico\- texto a ser mapeada por uma macro diretamente à versão de MBCS da rotina, como no exemplo de TCHAR.H.  
  
    ```  
    #define _tcschr _mbschr  
    ```  
  
 Quando você usa essa abordagem, você deve ter cuidado para garantir que os tipos de dados apropriados são usados para argumentos de cadeia de caracteres e retornam valores de cadeia de caracteres.  Você pode usar a conversão de tipo para assegurar que a correspondência adequada ou é do tipo UDT possam usar o tipo de dados de genérico\- texto de `_TXCHAR` .  mapas de`_TXCHAR` para digitar `char` no código de SBCS mas mapeia para digitar `unsigned char` no código de MBCS.  Para obter mais informações sobre macros de genérico\- texto, consulte [Mapeamentos de Genérico\- texto](../c-runtime-library/generic-text-mappings.md).  
  
 **FINALIZAR Específico da Microsoft**  
  
## Consulte também  
 [Internacionalização](../c-runtime-library/internationalization.md)   
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)