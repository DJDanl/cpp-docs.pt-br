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
ms.openlocfilehash: 78e5d89e1e87d081e762fab1298eb990b914324c
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446597"
---
# <a name="using-tcharh-data-types-with-_mbcs-code"></a>Usando tipos de dados TCHAR.H com código _MBCS

Quando a constante de manifesto `_MBCS` é definida, uma rotina de texto genérico determinada é mapeada para um dos seguintes tipos de rotinas:

- Uma rotina SBCS que lida com bytes, caracteres e cadeias de caracteres multibyte. Nesse caso, os argumentos de cadeia de caracteres devem ser do tipo `char*`. Por exemplo, `_tprintf` é mapeado para `printf`; os argumentos de cadeia de caracteres para `printf` são do tipo `char*`. Se você usar o `_TCHAR` tipo de dados de texto genérico para a cadeia de tipos, os tipos de parâmetro formal e real para `printf` corresponde porque `_TCHAR*` é mapeado para `char*`.

- Uma rotina específica do MBCS. Nesse caso, os argumentos de cadeia de caracteres devem ser do tipo `unsigned char*`. Por exemplo, `_tcsrev` é mapeado para `_mbsrev`, que espera e retorna uma cadeia de caracteres do tipo `unsigned char*`. Se você usar o `_TCHAR` tipo de dados de texto genérico para os tipos de cadeia de caracteres, haverá um conflito de tipo potencial porque `_TCHAR` mapeia para o tipo `char`.

A seguir estão três soluções para evitar esse conflito de tipo (e os avisos do compilador C ou erros do compilador C++ que resultariam):

- Use o comportamento padrão. o TCHAR. h fornece protótipos de rotina de texto genérico para rotinas nas bibliotecas de tempo de execução, como no exemplo a seguir.

    ```cpp
    char * _tcsrev(char *);
    ```

   No caso padrão, o protótipo para `_tcsrev` é mapeado para `_mbsrev` por meio de uma conversão em libc. lib. Isso altera os tipos de `_mbsrev` parâmetros de entrada e o valor de retorno de saída de `_TCHAR*` (ou seja, `char *`) para `unsigned char *`. Esse método garante a correspondência de tipos quando você está usando `_TCHAR`, mas é relativamente lento devido à sobrecarga de chamada de função.

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

   Ao tomar essa abordagem, você deve ter cuidado para garantir o uso de tipos de dados apropriados para argumentos de cadeia de caracteres e valores de retorno de cadeia de caracteres. Você pode usar a conversão de tipo para garantir a correspondência do tipo correto ou você pode usar o `_TXCHAR` tipo de dados de texto genérico. o `_TXCHAR` mapeia para o tipo **Char** no código SBCS, mas mapeia para tipo **Char não assinado** no código MBCS. Para obter mais informações sobre macros de texto genérico, consulte [mapeamentos de texto genérico](../c-runtime-library/generic-text-mappings.md) na *referência da biblioteca de tempo de execução*.

## <a name="see-also"></a>Consulte também

[Mapeamentos de texto genérico em tchar.h](../text/generic-text-mappings-in-tchar-h.md)
