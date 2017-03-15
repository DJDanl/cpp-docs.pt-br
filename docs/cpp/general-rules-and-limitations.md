---
title: "Regras gerais e limita&#231;&#245;es | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
ms.assetid: 6c48902d-4259-4761-95d4-e421d69aa050
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Regras gerais e limita&#231;&#245;es
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
  
-   Se você declarar uma função ou um objeto sem o atributo **dllimport** ou `dllexport`, a função ou o objeto não serão considerados parte da interface da DLL.  Consequentemente, a definição da função ou do objeto deverá estar presente nesse módulo ou em outro módulo do mesmo programa.  Para tornar a função ou o objeto parte da interface da DLL, você deve declarar a definição da função ou do objeto no outro módulo como `dllexport`.  Caso contrário, será gerado um erro de vinculador.  
  
     Se você declarar uma função ou um objeto com o atributo `dllexport`, a respectiva definição deverá aparecer em algum módulo do mesmo programa.  Caso contrário, será gerado um erro de vinculador.  
  
-   Se um módulo do programa contiver as declarações de **dllimport** e de `dllexport` para a mesma função ou o mesmo objeto, o atributo `dllexport` terá precedência sobre o atributo **dllimport**.  No entanto, um aviso do compilador será gerado.  Por exemplo:  
  
    ```  
    __declspec( dllimport ) int i;  
    __declspec( dllexport ) int i;   // Warning; inconsistent;  
                                     // dllexport takes precedence.  
    ```  
  
-   Em C\+\+, você pode inicializar um ponteiro de dados local estático ou declarado globalmente com o endereço de um objeto de dados declarado com o atributo **dllimport**, o que gera um erro em C.  Além disso, você pode inicializar um ponteiro de função local estático com o endereço de uma função declarada com o atributo **dllimport**.  Em C, essa atribuição define o ponteiro como o endereço da conversão de importação da DLL \(um stub de código que transfere o controle para a função\) em vez do endereço da função.  Em C\+\+, ela define o ponteiro como o endereço da função.  Por exemplo:  
  
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
  
     Porém, como um programa que inclui o atributo `dllexport` na declaração de um objeto deve fornecer a definição desse objeto em algum lugar do programa, você pode inicializar um ponteiro de função estático local ou global com o endereço de uma função `dllexport`.  Da mesma forma, você pode inicializar um ponteiro de dados estático global ou local com o endereço de um objeto de dados `dllexport`.  Por exemplo, o seguinte código não gera erros em C ou C\+\+:  
  
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
  
-   Devido a uma alteração de comportamento introduzida no Visual C\+\+ .NET para tornar a aplicação de `dllexport` mais consistente entre classes regulares e especializações de modelos de classe, se você aplicar `dllexport` a uma classe regular que tenha uma classe base que não esteja marcada como `dllexport`, o compilador irá gerar C4275.  
  
     O compilador irá gerar o mesmo aviso se a classe base for uma especialização de um modelo de classe.  Para contornar esse problema, marque a classe base com `dllexport`.  O problema com uma especialização de um modelo de classe é onde colocar **\_\_declspec\(dllexport\)**; não é permitido marcar o modelo de classe.  Em vez disso, crie explicitamente uma instância do modelo de classe e marque essa instanciação explícita com `dllexport`.  Por exemplo:  
  
    ```  
    template class __declspec(dllexport) B<int>;  
    class __declspec(dllexport) D : public B<int> {  
    // ...  
    ```  
  
     Essa solução alternativa falhará se o argumento do modelo for a classe derivada.  Por exemplo:  
  
    ```  
    class __declspec(dllexport) D : public B<D> {  
    // ...  
    ```  
  
     Como esse é um padrão comum com modelos, o compilador alterou a semântica de `dllexport` quando ele é aplicado a uma classe que tem uma ou mais classes base e quando uma ou mais das classes base são uma especialização de um modelo de classe.  Nesse caso, o compilador aplicará `dllexport` implicitamente às especializações de modelos de classe.  No Visual C\+\+ .NET, um usuário pode fazer o seguinte e não receber um aviso:  
  
    ```  
    class __declspec(dllexport) D : public B<D> {  
    // ...  
    ```  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [dllexport, dllimport](../cpp/dllexport-dllimport.md)