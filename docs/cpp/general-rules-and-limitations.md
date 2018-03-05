---
title: "Regras e limitações gerais | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 6c48902d-4259-4761-95d4-e421d69aa050
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 51f92844e993671a3423c04523ccf4e03f7f7e48
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="general-rules-and-limitations"></a>Regras e limitações gerais
## <a name="microsoft-specific"></a>Específico da Microsoft  
  
-   Se você declarar uma função ou um objeto sem o **dllimport** ou `dllexport` atributo, a função ou o objeto não é considerado parte da interface da DLL. Consequentemente, a definição da função ou do objeto deverá estar presente nesse módulo ou em outro módulo do mesmo programa. Para tornar a função ou o objeto parte da interface da DLL, você deve declarar a definição da função ou do objeto no outro módulo como `dllexport`. Caso contrário, será gerado um erro de vinculador.  
  
     Se você declarar uma função ou um objeto com o atributo `dllexport`, a respectiva definição deverá aparecer em algum módulo do mesmo programa. Caso contrário, será gerado um erro de vinculador.  
  
-   Se um único módulo em seu programa contém **dllimport** e `dllexport` declarações para o mesmo objeto, ou função de `dllexport` atributo tem precedência sobre o **dllimport** atributo. No entanto, um aviso do compilador será gerado. Por exemplo:  
  
    ```  
    __declspec( dllimport ) int i;  
    __declspec( dllexport ) int i;   // Warning; inconsistent;  
                                     // dllexport takes precedence.  
    ```  
  
-   No C++, você pode inicializar um ponteiro de dados locais globalmente declarados ou estático ou com o endereço de um objeto de dados declarado com o **dllimport** atributo, o que gera um erro em C. Além disso, você pode inicializar um ponteiro de função local estática com o endereço de uma função declarada com o **dllimport** atributo. Em C, essa atribuição define o ponteiro como o endereço da conversão de importação da DLL (um stub de código que transfere o controle para a função) em vez do endereço da função. Em C++, ela define o ponteiro como o endereço da função. Por exemplo:  
  
    ```  
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
  
     Porém, como um programa que inclui o atributo `dllexport` na declaração de um objeto deve fornecer a definição desse objeto em algum lugar do programa, você pode inicializar um ponteiro de função estático local ou global com o endereço de uma função `dllexport`. Da mesma forma, você pode inicializar um ponteiro de dados estático global ou local com o endereço de um objeto de dados `dllexport`. Por exemplo, o seguinte código não gera erros em C ou C++:  
  
    ```  
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
  
-   Se você aplicar `dllexport` para uma classe regular que tem uma classe base que não está marcada como `dllexport`, o compilador gerará C4275.  
  
     O compilador irá gerar o mesmo aviso se a classe base for uma especialização de um modelo de classe. Para contornar esse problema, marque a classe base com `dllexport`. O problema com uma especialização de um modelo de classe é o local onde colocar o **dllexport**; você não tem permissão para marcar o modelo de classe. Em vez disso, crie explicitamente uma instância do modelo de classe e marque essa instanciação explícita com `dllexport`. Por exemplo:  
  
    ```  
    template class __declspec(dllexport) B<int>;  
    class __declspec(dllexport) D : public B<int> {  
    // ...  
    ```  
  
     Essa solução alternativa falhará se o argumento do modelo for a classe derivada. Por exemplo:  
  
    ```  
    class __declspec(dllexport) D : public B<D> {  
    // ...  
    ```  
  
     Como esse é um padrão comum com modelos, o compilador alterou a semântica de `dllexport` quando ele é aplicado a uma classe que tem uma ou mais classes base e quando uma ou mais das classes base são uma especialização de um modelo de classe. Nesse caso, o compilador aplicará `dllexport` implicitamente às especializações de modelos de classe. Você pode fazer o seguinte e não receber um aviso:  
  
    ```  
    class __declspec(dllexport) D : public B<D> {  
    // ...  
    ```  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [dllexport, dllimport](../cpp/dllexport-dllimport.md)