---
title: Uso de tipos de dados TCHAR.H com _MBCS | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- _mbcs
dev_langs:
- C++
helpviewer_keywords:
- TCHAR.H data types
- MBCS data type
- _MBCS data type
ms.assetid: 48f471e7-9d2b-4a39-b841-16a0e15c0a18
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
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 8c36e82ae5e3f5e62f28a3036f78e68d2c18eaf1
ms.lasthandoff: 02/25/2017

---
# <a name="using-tcharh-data-types-with-mbcs"></a>Usando tipos de dados TCHAR.H com _MBCS
**Seção específica da Microsoft**  
  
 Como indica a tabela de mapeamentos de rotina de texto genérico (consulte [mapeamentos de texto genérico](../c-runtime-library/generic-text-mappings.md)), quando a constante de manifesto `_MBCS` é definida, uma determinada rotina de texto genérico mapeado para um dos seguintes tipos de rotinas:  
  
-   Uma rotina SBCS que lida com bytes, caracteres e cadeias de caracteres multibyte. Nesse caso, os argumentos de cadeia de caracteres devem ser do tipo `char*`. Por exemplo, `_tprintf` é mapeado para `printf`; os argumentos de cadeia de caracteres para `printf` são do tipo `char*`. Se você usar o `_TCHAR` tipo de dados de texto genérico para a cadeia de tipos, os tipos de parâmetro formal e real para `printf` corresponde porque `_TCHAR*` é mapeado para `char*`.  
  
-   Uma rotina específica do MBCS. Nesse caso, os argumentos de cadeia de caracteres devem ser do tipo `unsigned char*`. Por exemplo, `_tcsrev` é mapeado para `_mbsrev`, que espera e retorna uma cadeia de caracteres do tipo `unsigned char*`. Novamente, se você usar o `_TCHAR` tipo de dados de texto genérico para seus tipos de cadeia de caracteres, há a um possível conflito de tipo porque `_TCHAR` é mapeado para o tipo `char`.  
  
 A seguir estão três soluções para evitar esse conflito de tipo (e os avisos do compilador C ou erros do compilador C++ que resultariam):  
  
-   Use o comportamento padrão. TCHAR. H fornece protótipos de rotina de texto genérico para rotinas nas bibliotecas de tempo de execução, como no exemplo a seguir.  
  
    ```  
    char *_tcsrev(char *);  
    ```  
  
     No caso padrão, o protótipo para `_tcsrev` é mapeado para `_mbsrev` por meio de uma conversão em LIBC.LIB. Isso altera os tipos do `_mbsrev` parâmetros de entrada e saída retornam o valor de `_TCHAR *` (como `char *`) para `unsigned char *`. Esse método garante o tipo que corresponde ao usar `_TCHAR`, mas é relativamente lenta devido à sobrecarga de chamada de função.  
  
-   Use inlining de função incorporando a seguinte instrução de pré-processador em seu código.  
  
    ```  
    #define _USE_INLINING  
    ```  
  
     Esse método faz com que uma conversão de função embutida, fornecida em TCHAR. H, a rotina de texto genérico são mapeados diretamente para a rotina MBCS apropriada. O seguinte trecho de código de TCHAR.H fornece um exemplo de como isso é feito.  
  
    ```  
    __inline char *_tcsrev(char *_s1)  
    {return (char *)_mbsrev((unsigned char *)_s1);}  
    ```  
  
     Se você pode usar o inlining, essa é a melhor solução, pois ela garante o tipo de correspondência e tem um custo sem tempo adicional.  
  
-   Use "mapeamento direto" incorporando a seguinte instrução de pré-processador em seu código.  
  
    ```  
    #define _MB_MAP_DIRECT  
    ```  
  
     Essa abordagem fornece uma alternativa rápida se você não quiser usar o comportamento padrão ou não é possível usar inlining. Faz com que a rotina de texto genérico para ser mapeadas por uma macro diretamente para a versão MBCS de rotina, como no exemplo a seguir do TCHAR. H.  
  
    ```  
    #define _tcschr _mbschr  
    ```  
  
 Quando você usar essa abordagem, você deve ter cuidado para garantir que os tipos de dados apropriados são usados para argumentos de cadeia de caracteres e valores de retorno de cadeia de caracteres. Você pode usar a conversão de tipo para garantir a correspondência do tipo correto ou você pode usar o `_TXCHAR` tipo de dados de texto genérico. `_TXCHAR` é mapeado para o tipo `char` no código SBCS mas é mapeado para o tipo `unsigned char` no código MBCS. Para saber mais sobre as macros de texto genéricas, veja [Mapeamentos de texto genéricos](../c-runtime-library/generic-text-mappings.md).  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Internacionalização](../c-runtime-library/internationalization.md)   
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)
