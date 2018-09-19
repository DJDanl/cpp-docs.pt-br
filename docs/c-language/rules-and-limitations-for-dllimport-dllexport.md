---
title: Regras e limitações para dllimport/dllexport | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- dllexport attribute [C++], limitations and rules
- dllimport attribute [C++], limitations and rules
- dllexport attribute [C++]
ms.assetid: 274b735f-ab9c-4b07-8d0e-fdb65d664634
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6819ad58e3814f7c632c44db4549321e0c6969e4
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46038393"
---
# <a name="rules-and-limitations-for-dllimportdllexport"></a>Regras e limitações para dllimport/dllexport

**Seção específica da Microsoft**

- Se você declarar uma função sem o atributo **dllimport** ou `dllexport`, a função não será considerada parte da interface da DLL. Consequentemente, a definição da função deverá estar presente nesse módulo ou em outro módulo do mesmo programa. Para tornar a função parte da interface da DLL, você deve declarar a definição da função no outro módulo como `dllexport`. Caso contrário, um erro de vinculador é gerado quando o cliente é compilado.

- Se um módulo do programa contiver as declarações **dllimport** e `dllexport` para a mesma função, o atributo `dllexport` terá precedência sobre o atributo **dllimport**. No entanto, um aviso do compilador será gerado. Por exemplo:

    ```
    #define DllImport   __declspec( dllimport )
    #define DllExport   __declspec( dllexport )

       DllImport void func1( void );
       DllExport void func1( void );   /* Warning; dllexport */
                                       /* takes precedence. */

    ```

- Você não pode inicializar um ponteiro de dados estático com o endereço de um objeto de dados declarado com o atributo **dllimport**. Por exemplo, o código a seguir gera erros:

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

- Inicializar um ponteiro de função estática com o endereço de uma função declarada com **dllimport** define o ponteiro para o endereço de conversão de importação da DLL (um stub de código que transfere o controle para a função) em vez do endereço da função. Essa atribuição não gera uma mensagem de erro:

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

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Funções de importação e exportação de DLL](../c-language/dll-import-and-export-functions.md)