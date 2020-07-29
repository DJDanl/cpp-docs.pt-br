---
title: Regras e limitações para dllimport–dllexport
ms.date: 11/04/2016
helpviewer_keywords:
- dllexport attribute [C++], limitations and rules
- dllimport attribute [C++], limitations and rules
- dllexport attribute [C++]
ms.assetid: 274b735f-ab9c-4b07-8d0e-fdb65d664634
ms.openlocfilehash: c2f121d978962fe7fc03aa453fb0a16650aa2727
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220867"
---
# <a name="rules-and-limitations-for-dllimportdllexport"></a>Regras e limitações para dllimport/dllexport

**Específico da Microsoft**

- Se você declarar uma função sem o **`dllimport`** `dllexport` atributo ou, a função não será considerada parte da interface DLL. Consequentemente, a definição da função deverá estar presente nesse módulo ou em outro módulo do mesmo programa. Para tornar a função parte da interface da DLL, você deve declarar a definição da função no outro módulo como `dllexport`. Caso contrário, um erro de vinculador é gerado quando o cliente é compilado.

- Se um único módulo no seu programa contiver **`dllimport`** `dllexport` declarações e para a mesma função, o `dllexport` atributo terá precedência sobre o **`dllimport`** atributo. No entanto, um aviso do compilador será gerado. Por exemplo:

    ```
    #define DllImport   __declspec( dllimport )
    #define DllExport   __declspec( dllexport )

       DllImport void func1( void );
       DllExport void func1( void );   /* Warning; dllexport */
                                       /* takes precedence. */

    ```

- Não é possível inicializar um ponteiro de dados estáticos com o endereço de um objeto de dados declarado com o **`dllimport`** atributo. Por exemplo, o código a seguir gera erros:

    ```
    #define DllImport   __declspec( dllimport )
    #define DllExport   __declspec( dllexport )

       DllImport int i;
       .
       .
       .
       int *pi = &i;                           /* Error */

       void func2()
       {
          static int *pi = &i;                   /* Error */
       }

    ```

- Inicializar um ponteiro de função estática com o endereço de uma função declarado com **`dllimport`** define o ponteiro para o endereço da conversão de importação de dll (um stub de código que transfere o controle para a função) em vez do endereço da função. Essa atribuição não gera uma mensagem de erro:

    ```
    #define DllImport   __declspec( dllimport )
    #define DllExport   __declspec( dllexport )

       DllImport void func1( void
       .
       .
       .
       static void ( *pf )( void ) = &func1;   /* No Error */

       void func2()
       {
          static void ( *pf )( void ) = &func1;  /* No Error */
       }

    ```

- Como um programa que inclui o atributo `dllexport` na declaração de um objeto deve fornecer a definição desse objeto, você pode inicializar um ponteiro de função estático local ou global com o endereço de uma função `dllexport`. Da mesma forma, você pode inicializar um ponteiro de dados estático global ou local com o endereço de um objeto de dados `dllexport`. Por exemplo:

    ```
    #define DllImport   __declspec( dllimport )
    #define DllExport   __declspec( dllexport )

       DllImport void func1( void );
       DllImport int i;

       DllExport void func1( void );
       DllExport int i;
       .
       .
       .
       int *pi = &i;                            /* Okay */
       static void ( *pf )( void ) = &func1;    /* Okay */

       void func2()
       {
          static int *pi = i;                     /* Okay */
          static void ( *pf )( void ) = &func1;   /* Okay */
       }

    ```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Funções de importação e exportação de DLL](../c-language/dll-import-and-export-functions.md)
