---
title: Usando tipos de dados TCHAR.H com código _MBCS
ms.date: 11/04/2016
helpviewer_keywords:
- mapping generic-text
- generic-text data types [C++]
- generic-text mappings [C++]
- MBCS [C++], generic-text mappings
- TCHAR.H data types, mapping
- mappings [C++], TCHAR.H
ms.assetid: 298583c5-22c3-40f6-920e-9ec96d42abd8
ms.openlocfilehash: dd43c29d77c3351e8f597b474c4756ad3d45ef2b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215355"
---
# <a name="using-tcharh-data-types-with-_mbcs-code"></a>Usando tipos de dados TCHAR.H com código _MBCS

Quando a constante de manifesto `_MBCS` é definida, uma rotina de texto genérico determinada é mapeada para um dos seguintes tipos de rotinas:

- Uma rotina SBCS que lida com bytes, caracteres e cadeias de caracteres multibyte. Nesse caso, espera-se que os argumentos de cadeia de caracteres sejam do tipo **`char*`** . Por exemplo, `_tprintf` mapeia para `printf` ; os argumentos de cadeia de caracteres `printf` são do tipo **`char*`** . Se você usar o `_TCHAR` tipo de dados de texto genérico para os tipos de cadeia de caracteres, os tipos de parâmetro formal e real para `printf` correspondência, porque o `_TCHAR*` mapeia para **`char*`** .

- Uma rotina específica do MBCS. Nesse caso, os argumentos de cadeia de caracteres devem ser do tipo `unsigned char*`. Por exemplo, `_tcsrev` é mapeado para `_mbsrev`, que espera e retorna uma cadeia de caracteres do tipo `unsigned char*`. Se você usar o `_TCHAR` tipo de dados de texto genérico para os tipos de cadeia de caracteres, haverá um conflito de tipo em potencial porque o `_TCHAR` mapeia para o tipo **`char`** .

A seguir estão três soluções para evitar esse conflito de tipo (e os avisos do compilador C ou erros do compilador C++ que resultariam):

- Use o comportamento padrão. o TCHAR. h fornece protótipos de rotina de texto genérico para rotinas nas bibliotecas de tempo de execução, como no exemplo a seguir.

    ```cpp
    char * _tcsrev(char *);
    ```

   No caso padrão, o protótipo para é `_tcsrev` mapeado para `_mbsrev` por meio de uma conversão em libc. lib. Isso altera os tipos dos `_mbsrev` parâmetros de entrada e o valor de retorno de saída de `_TCHAR*` (ou seja, `char *` ) para `unsigned char *` . Esse método garante a correspondência de tipos quando você está usando `_TCHAR` , mas é relativamente lento devido à sobrecarga de chamada de função.

- Use inlining de função incorporando a seguinte instrução de pré-processador em seu código.

    ```cpp
    #define _USE_INLINING
    ```

   Esse método causa uma conversão de função embutida, fornecida em TCHAR. h, para mapear a rotina de texto genérico diretamente para a rotina MBCS apropriada. O trecho de código a seguir de TCHAR. h fornece um exemplo de como isso é feito.

    ```cpp
    __inline char *_tcsrev(char *_s1)
    {return (char *)_mbsrev((unsigned char *)_s1);}
    ```

   Se você pode usar o inlining, essa é a melhor solução, pois ela garante o tipo de correspondência e tem um custo sem tempo adicional.

- Use o mapeamento direto incorporando a seguinte instrução de pré-processador em seu código.

    ```cpp
    #define _MB_MAP_DIRECT
    ```

   Essa abordagem fornece uma alternativa rápida se você não quiser usar o comportamento padrão ou não é possível usar inlining. Isso faz com que a rotina de texto genérico seja mapeada por uma macro diretamente para a versão MBCS da rotina, como no exemplo a seguir de TCHAR. h.

    ```cpp
    #define _tcschr _mbschr
    ```

   Ao tomar essa abordagem, você deve ter cuidado para garantir o uso de tipos de dados apropriados para argumentos de cadeia de caracteres e valores de retorno de cadeia de caracteres. Você pode usar a conversão de tipo para garantir a correspondência do tipo correto ou você pode usar o `_TXCHAR` tipo de dados de texto genérico. `_TXCHAR`mapeia para o tipo **`char`** no código SBCS, mas mapeia para o tipo **`unsigned char`** no código MBCS. Para obter mais informações sobre macros de texto genérico, consulte [mapeamentos de texto genérico](../c-runtime-library/generic-text-mappings.md) na *referência da biblioteca de tempo de execução*.

## <a name="see-also"></a>Confira também

[Mapeamentos de texto genérico em TCHAR. h](../text/generic-text-mappings-in-tchar-h.md)
