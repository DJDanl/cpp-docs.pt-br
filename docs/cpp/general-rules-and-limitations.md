---
title: Regras e limitações gerais
ms.date: 11/04/2016
ms.assetid: 6c48902d-4259-4761-95d4-e421d69aa050
ms.openlocfilehash: 8d21f627f461dce90af93ca5c1af8c4a28098539
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213405"
---
# <a name="general-rules-and-limitations"></a>Regras e limitações gerais

**Específico da Microsoft**

- Se você declarar uma função ou um objeto sem **`dllimport`** o **`dllexport`** atributo ou, a função ou o objeto não será considerado parte da interface DLL. Consequentemente, a definição da função ou do objeto deverá estar presente nesse módulo ou em outro módulo do mesmo programa. Para tornar a função ou objeto parte da interface DLL, você deve declarar a definição da função ou objeto no outro módulo como **`dllexport`** . Caso contrário, será gerado um erro de vinculador.

   Se você declarar uma função ou um objeto com o **`dllexport`** atributo, sua definição deverá aparecer em algum módulo do mesmo programa. Caso contrário, será gerado um erro de vinculador.

- Se um único módulo em seu programa contiver **`dllimport`** **`dllexport`** declarações e para a mesma função ou objeto, o **`dllexport`** atributo terá precedência sobre o **`dllimport`** atributo. No entanto, um aviso do compilador será gerado. Por exemplo:

    ```cpp
    __declspec( dllimport ) int i;
    __declspec( dllexport ) int i;   // Warning; inconsistent;
                                     // dllexport takes precedence.
    ```

- Em C++, você pode inicializar um ponteiro de dados local declarado globalmente ou estático ou com o endereço de um objeto de dados declarado com o **`dllimport`** atributo, que gera um erro em C. Além disso, você pode inicializar um ponteiro de função local estático com o endereço de uma função declarada com o **`dllimport`** atributo. Em C, essa atribuição define o ponteiro como o endereço da conversão de importação da DLL (um stub de código que transfere o controle para a função) em vez do endereço da função. Em C++, ela define o ponteiro como o endereço da função. Por exemplo:

    ```cpp
    __declspec( dllimport ) void func1( void );
    __declspec( dllimport ) int i;

    int *pi = &i;                             // Error in C
    static void ( *pf )( void ) = &func1;     // Address of thunk in C,
                                              // function in C++

    void func2()
    {
       static int *pi = &i;                  // Error in C
       static void ( *pf )( void ) = &func1; // Address of thunk in C,
                                             // function in C++
    }
    ```

   No entanto, como um programa que inclui o **`dllexport`** atributo na declaração de um objeto deve fornecer a definição para esse objeto em algum lugar no programa, você pode inicializar um ponteiro de função estática global ou local com o endereço de uma **`dllexport`** função. Da mesma forma, você pode inicializar um ponteiro de dados estático global ou local com o endereço de um **`dllexport`** objeto de dados. Por exemplo, o seguinte código não gera erros em C ou C++:

    ```cpp
    __declspec( dllexport ) void func1( void );
    __declspec( dllexport ) int i;

    int *pi = &i;                              // Okay
    static void ( *pf )( void ) = &func1;      // Okay

    void func2()
    {
        static int *pi = &i;                   // Okay
        static void ( *pf )( void ) = &func1;  // Okay
    }
    ```

- Se você aplicar **`dllexport`** a uma classe regular que tenha uma classe base que não esteja marcada como **`dllexport`** , o compilador irá gerar C4275.

   O compilador irá gerar o mesmo aviso se a classe base for uma especialização de um modelo de classe. Para contornar isso, marque a classe base com **`dllexport`** . O problema com uma especialização de um modelo de classe é onde colocá-lo **`__declspec(dllexport)`** ; você não tem permissão para marcar o modelo de classe. Em vez disso, instancie explicitamente o modelo de classe e marque essa instanciação explícita com **`dllexport`** . Por exemplo:

    ```cpp
    template class __declspec(dllexport) B<int>;
    class __declspec(dllexport) D : public B<int> {
    // ...
    ```

   Essa solução alternativa falhará se o argumento do modelo for a classe derivada. Por exemplo:

    ```cpp
    class __declspec(dllexport) D : public B<D> {
    // ...
    ```

   Como esse é um padrão comum com modelos, o compilador alterou a semântica de **`dllexport`** quando ele é aplicado a uma classe que tem uma ou mais classes base e quando uma ou mais das classes base é uma especialização de um modelo de classe. Nesse caso, o compilador se aplica implicitamente **`dllexport`** às especializações de modelos de classe. Você pode fazer o seguinte e não receber um aviso:

    ```cpp
    class __declspec(dllexport) D : public B<D> {
    // ...
    ```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[dllexport, dllimport](../cpp/dllexport-dllimport.md)
