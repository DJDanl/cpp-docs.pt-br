---
title: Usando tipos de dados TCHAR.H com código _MBCS
ms.date: 11/04/2016
f1_keywords:
- tchar.h
- TCHAR
helpviewer_keywords:
- mapping generic-text
- generic-text data types [C++]
- generic-text mappings [C++]
- MBCS [C++], generic-text mappings
- TCHAR.H data types, mapping
- mappings [C++], TCHAR.H
ms.assetid: 298583c5-22c3-40f6-920e-9ec96d42abd8
ms.openlocfilehash: dcb194c72ca2a64317cddda8a1559e78edc0978f
ms.sourcegitcommit: ff3cbe4235b6c316edcc7677f79f70c3e784ad76
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/19/2018
ms.locfileid: "53626663"
---
# <a name="using-tcharh-data-types-with-mbcs-code"></a>Usando tipos de dados TCHAR.H com código _MBCS

Quando a constante de manifesto `_MBCS` é definido, uma determinada rotina de texto genérico mapeado para um dos seguintes tipos de rotinas:

- Uma rotina SBCS que lida com bytes, caracteres e cadeias de caracteres multibyte. Nesse caso, os argumentos de cadeia de caracteres devem ser do tipo `char*`. Por exemplo, `_tprintf` é mapeado para `printf`; os argumentos de cadeia de caracteres para `printf` são do tipo `char*`. Se você usar o `_TCHAR` tipo de dados de texto genérico para a cadeia de tipos, os tipos de parâmetro formal e real para `printf` corresponde porque `_TCHAR*` é mapeado para `char*`.

- Uma rotina específica do MBCS. Nesse caso, os argumentos de cadeia de caracteres devem ser do tipo `unsigned char*`. Por exemplo, `_tcsrev` é mapeado para `_mbsrev`, que espera e retorna uma cadeia de caracteres do tipo `unsigned char*`. Se você usar o `_TCHAR` de tipo de dados de texto genérico para seus tipos de cadeia de caracteres, há a um possível conflito de tipo porque `_TCHAR` mapeia para o tipo `char`.

A seguir estão três soluções para evitar esse conflito de tipo (e os avisos do compilador C ou erros do compilador C++ que resultariam):

- Use o comportamento padrão. TCHAR. h fornece protótipos de rotina de texto genérico para rotinas nas bibliotecas de tempo de execução, como no exemplo a seguir.

    ```cpp
    char * _tcsrev(char *);
    ```

   No caso padrão, o protótipo `_tcsrev` mapeia para `_mbsrev` por meio de uma conversão em libc. lib. Isso altera os tipos dos `_mbsrev` parâmetros de entrada e saída retornam o valor da `_TCHAR*` (ou seja, `char *`) para `unsigned char *`. Esse método garante o tipo correspondente quando você estiver usando `_TCHAR`, mas é relativamente lenta devido à sobrecarga de chamada de função.

- Use inlining de função incorporando a seguinte instrução de pré-processador em seu código.

    ```cpp
    #define _USE_INLINING
    ```

   Esse método faz com que uma conversão de função embutida, fornecida em TCHAR. h, a rotina de texto genérico são mapeados diretamente para a rotina MBCS apropriada. O seguinte trecho de código de TCHAR. h fornece um exemplo de como isso é feito.

    ```cpp
    __inline char *_tcsrev(char *_s1)
    {return (char *)_mbsrev((unsigned char *)_s1);}
    ```

   Se você pode usar o inlining, essa é a melhor solução, pois ela garante o tipo de correspondência e tem um custo sem tempo adicional.

- Use o mapeamento direto incorporando a seguinte instrução de pré-processador em seu código.

    ```cpp
    #define _MB_MAP_DIRECT
    ```

   Essa abordagem fornece uma alternativa rápida se você não quiser usar o comportamento padrão ou não é possível usar inlining. Isso faz com que a rotina de texto genérico para ser mapeadas por uma macro diretamente para a versão MBCS de rotina, como no exemplo a seguir do TCHAR. h.

    ```cpp
    #define _tcschr _mbschr
    ```

   Quando você usar essa abordagem, você deve ter cuidado para assegurar o uso de tipos de dados apropriados para os argumentos de cadeia de caracteres e valores de retorno de cadeia de caracteres. Você pode usar a conversão de tipo para garantir a correspondência do tipo correto ou você pode usar o `_TXCHAR` tipo de dados de texto genérico. `_TXCHAR` mapeia para o tipo **char** no código SBCS mas mapeia para o tipo **unsigned char** no código MBCS. Para obter mais informações sobre as macros de texto genérico, consulte [mapeamentos de texto genérico](../c-runtime-library/generic-text-mappings.md) na *referência de biblioteca de tempo de execução*.

## <a name="see-also"></a>Consulte também

[Mapeamentos de texto genéricos em TCHAR. h](../text/generic-text-mappings-in-tchar-h.md)
