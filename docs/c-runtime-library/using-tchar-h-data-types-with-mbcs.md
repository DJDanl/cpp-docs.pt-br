---
title: Usando tipos de dados TCHAR.H com _MBCS
ms.date: 11/04/2016
helpviewer_keywords:
- TCHAR.H data types
- MBCS data type
- _MBCS data type
ms.assetid: 48f471e7-9d2b-4a39-b841-16a0e15c0a18
ms.openlocfilehash: d1aab0c21a348e4b1a6e85a7adb7f7f8ea1587b2
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87188629"
---
# <a name="using-tcharh-data-types-with-_mbcs"></a>Usando tipos de dados TCHAR.H com _MBCS

**Específico da Microsoft**

Como indica a tabela de mapeamentos de rotina de texto genérico (consulte [Mapeamentos de texto genérico](../c-runtime-library/generic-text-mappings.md)), quando a constante de manifesto **_MBCS** é definida, uma determinada rotina de texto genérico mapeia para um dos seguintes tipos de rotinas:

- Uma rotina SBCS que lida com bytes, caracteres e cadeias de caracteres multibyte. Nesse caso, os argumentos de cadeia de caracteres devem ser do tipo **char&#42;**. Por exemplo, **_tprintf** mapeia para **printf**. Os argumentos de cadeia de caracteres para **printf** são do tipo **char&#42;**. Se você usar o tipo de dados de texto genérico **_TCHAR** para os tipos de cadeia de caracteres, os tipos de parâmetro formal e real para **printf** corresponderão porque **_TCHAR&#42;** mapeará para **char&#42;**.

- Uma rotina específica do MBCS. Nesse caso, os argumentos de cadeia de caracteres devem ser do tipo __unsigned char&#42;__. Por exemplo, **_tcsrev** mapeia para **_mbsrev**, que espera e retorna uma cadeia de caracteres do tipo __unsigned char&#42;__. Novamente, se você usar o **_TCHAR** tipo de dados de texto genérico para os tipos de cadeia de caracteres, haverá um conflito de tipo potencial porque **_TCHAR** mapeia para o tipo **`char`** .

A seguir estão três soluções para evitar esse conflito de tipo (e os avisos do compilador C ou erros do compilador C++ que resultariam):

- Use o comportamento padrão. TCHAR. H fornece protótipos de rotina de texto genérico para rotinas nas bibliotecas de tempo de execução, como no exemplo a seguir.

   ```C
   char *_tcsrev(char *);
   ```

   No caso padrão, o protótipo para **_tcsrev** mapeia para **_mbsrev** por meio de uma conversão em LIBC.LIB. Isso altera os tipos dos parâmetros de entrada **_mbsrev** e valor retornado de saída de **_TCHAR &#42;** (como **char &#42;**) para **unsigned char &#42;**. Esse método garante o tipo correspondente ao usar **_TCHAR**, mas é relativamente lento devido à sobrecarga de chamada de função.

- Use inlining de função incorporando a seguinte instrução de pré-processador em seu código.

   ```C
   #define _USE_INLINING
   ```

   Esse método faz com que uma conversão de função embutida, fornecida em TCHAR. H, a rotina de texto genérico são mapeados diretamente para a rotina MBCS apropriada. O seguinte trecho de código de TCHAR.H fornece um exemplo de como isso é feito.

   ```C
   __inline char *_tcsrev(char *_s1)
   {return (char *)_mbsrev((unsigned char *)_s1);}
   ```

   Se você pode usar o inlining, essa é a melhor solução, pois ela garante o tipo de correspondência e tem um custo sem tempo adicional.

- Use "mapeamento direto" incorporando a seguinte instrução de pré-processador em seu código.

   ```C
   #define _MB_MAP_DIRECT
   ```

   Essa abordagem fornece uma alternativa rápida se você não quiser usar o comportamento padrão ou não é possível usar inlining. Faz com que a rotina de texto genérico para ser mapeadas por uma macro diretamente para a versão MBCS de rotina, como no exemplo a seguir do TCHAR. H.

   ```C
   #define _tcschr _mbschr
   ```

Quando você usar essa abordagem, você deve ter cuidado para garantir que os tipos de dados apropriados são usados para argumentos de cadeia de caracteres e valores de retorno de cadeia de caracteres. Você pode usar a conversão de tipo para garantir a correspondência do tipo correto ou pode usar o tipo de dados de texto genérico **_TXCHAR**. **_TXCHAR** mapeia para tipo **`char`** no código SBCS, mas mapeia para tipo **`unsigned char`** no código MBCS. Para saber mais sobre as macros de texto genéricas, veja [Mapeamentos de texto genéricos](../c-runtime-library/generic-text-mappings.md).

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Internacionalização](../c-runtime-library/internationalization.md)<br/>
[Rotinas de runtime C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
