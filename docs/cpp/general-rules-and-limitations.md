---
title: Regras e limitações gerais
ms.date: 11/04/2016
ms.assetid: 6c48902d-4259-4761-95d4-e421d69aa050
ms.openlocfilehash: 931ae04ef47262f15d037a2b5eeb35bd01a8419d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62153769"
---
# <a name="general-rules-and-limitations"></a>Regras e limitações gerais

## <a name="microsoft-specific"></a>Específico da Microsoft

- Se você declarar uma função ou um objeto sem o **dllimport** ou **dllexport** atributo, a função ou o objeto não é considerado parte da interface da DLL. Consequentemente, a definição da função ou do objeto deverá estar presente nesse módulo ou em outro módulo do mesmo programa. Para tornar a parte de função ou o objeto da interface da DLL, você deve declarar a definição da função ou do objeto em outro módulo como **dllexport**. Caso contrário, será gerado um erro de vinculador.

   Se você declarar uma função ou um objeto com o **dllexport** de atributo, sua definição deve aparecer em algum módulo do mesmo programa. Caso contrário, será gerado um erro de vinculador.

- Se um módulo em seu programa contiver ambos **dllimport** e **dllexport** declarações para a mesma função ou objeto, o **dllexport** atributo terá precedência sobre o **dllimport** atributo. No entanto, um aviso do compilador será gerado. Por exemplo:

    ```cpp
    __declspec( dllimport ) int i;
    __declspec( dllexport ) int i;   // Warning; inconsistent;
                                     // dllexport takes precedence.
    ```

- No C++, você pode inicializar um ponteiro de dados local estático ou declarado globalmente ou com o endereço de um objeto de dados declarado com o **dllimport** atributo, que gera um erro em C. Além disso, você pode inicializar um ponteiro de função local estático com o endereço de uma função declarada com o **dllimport** atributo. Em C, essa atribuição define o ponteiro como o endereço da conversão de importação da DLL (um stub de código que transfere o controle para a função) em vez do endereço da função. Em C++, ela define o ponteiro como o endereço da função. Por exemplo:

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

   No entanto, como um programa que inclui o **dllexport** atributo na declaração de um objeto deve fornecer a definição para esse objeto em algum lugar no programa, você pode inicializar um ponteiro de função estático local ou global com o endereço de uma **dllexport** função. Da mesma forma, você pode inicializar um ponteiro de dados estático global ou local com o endereço de uma **dllexport** objeto de dados. Por exemplo, o seguinte código não gera erros em C ou C++:

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

- Se você aplicar **dllexport** a uma classe regular que tenha uma classe base que não está marcada como **dllexport**, o compilador irá gerar C4275.

   O compilador irá gerar o mesmo aviso se a classe base for uma especialização de um modelo de classe. Para resolver esse problema, marcar a classe base com **dllexport**. O problema com uma especialização de um modelo de classe é onde colocar o **dllexport**; você não tem permissão para marcar o modelo de classe. Em vez disso, explicitamente instanciar o modelo de classe e marque essa instanciação explícita com **dllexport**. Por exemplo:

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

   Como esse é um padrão comum com modelos, o compilador alterou a semântica de **dllexport** quando ele é aplicado a uma classe que tem uma ou mais classes de base e quando um ou mais das classes base é uma especialização de um modelo de classe . Nesse caso, o compilador aplica implicitamente **dllexport** às especializações de modelos de classe. Você pode fazer o seguinte e não receber um aviso:

    ```cpp
    class __declspec(dllexport) D : public B<D> {
    // ...
    ```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[dllexport, dllimport](../cpp/dllexport-dllimport.md)