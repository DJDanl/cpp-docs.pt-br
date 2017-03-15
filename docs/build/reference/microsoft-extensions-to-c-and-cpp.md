---
title: "Extens&#245;es da Microsoft para C e C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador !, extensão para C++"
  - "Operador !="
  - "Operador &, extensões para C/C++"
  - "Operador &&"
  - "Operador &="
  - "Operador ^, extensões para C/C++"
  - "Operador ^=, extensões C++"
  - "Operador |, extensões"
  - "Operador ||"
  - "Operador |="
  - "Operador ~, extensões para C/C++"
  - "Operador And, extensões para C/C++"
  - "Operador and_eq"
  - "Método compl"
  - "extensões"
  - "extensões, linguagem C"
  - "cabeçalho iso646.h"
  - "extensões da Microsoft para C/C++"
  - "Operador NOT"
  - "Operador not_eq"
  - "Operador Or, extensões da Microsoft para C/C++"
  - "Operador or_eq"
  - "Visual C, extensões da Microsoft"
  - "Visual C++, extensões para C/C++"
  - "Operador Xor, extensões da Microsoft para C/C++"
  - "Operador xor_eq"
ms.assetid: e811a74a-45ba-4c00-b206-2f2321b8689a
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Extens&#245;es da Microsoft para C e C++
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Visual C\+\+ estende os padrões ANSI C e C\+\+ 2.0 ANSI da seguinte maneira.  
  
## Palavras\-chave  
 Várias palavras\-chave são adicionados.  Na lista em [Palavras\-chave C\+\+](../../cpp/keywords-cpp.md), as palavras\-chave que têm dois sublinhados principais são extensões do Visual C\+\+.  
  
## Fora da definição de classe dos membros estáticos de integrante de const \(ou o enum\)  
 No**\/Za**\(padrão\), faça uma definição de falta da classe para membros de dados, como mostrado a seguir:  
  
```  
class CMyClass  {  
   static const int max = 5;  
   int m_array[max];  
}  
...  
const int CMyClass::max;   // out of class definition  
```  
  
 Em **\/Ze**, a definição de falta de classe é opcional para a digitação estática, a integrante de const, e os membros de dados de enum de const.  Somente as integral e os enum que são estáticas e o const podem ter inicializadores em uma classe; inicializando a expressão deve ser uma expressão de const.  
  
 Para evitar erros quando uma definição de falta de classe é fornecida em um arquivo de cabeçalho e o arquivo de cabeçalho está incluído em vários arquivos de origem, use [selectany](../../cpp/selectany.md).  Por exemplo:  
  
```  
__declspec(selectany) const int CMyClass::max = 5;  
```  
  
## Conversões  
 O compilador o compilador C e C\+\+ oferecem suporte a estes tipos de conversão de não ANSI:  
  
-   Conversões de não ANSI para gerar l\- valores.  Por exemplo:  
  
    ```  
    char *p;  
    (( int * ) p )++;  
    ```  
  
    > [!NOTE]
    >  Essa extensão está disponível na unidade C \- somente idioma.  Você pode usar o seguinte formato padrão ANSI C em código C\+\+ para alterar um ponteiro como se é um ponteiro para um tipo diferente.  
  
     O exemplo anterior poderia ser reescrito como segue pelo padrão ANSI C.  
  
    ```  
    p = ( char * )(( int * )p + 1 );  
    ```  
  
-   Conversões de não ANSI de um ponteiro de função para um ponteiro de dados.  Por exemplo:  
  
    ```  
    int ( * pfunc ) ();   
    int *pdata;  
    pdata = ( int * ) pfunc;  
    ```  
  
     Para executar a mesma conversão e manter também compatibilidade ANSI, você pode converter o ponteiro de função a `uintptr_t` antes que você converta ele a um ponteiro de dados:  
  
    ```  
    pdata = ( int * ) (uintptr_t) pfunc;  
    ```  
  
## Listas de argumento de comprimento variável  
 O compilador o compilador C e C\+\+ oferecem suporte a um declarator de função que especifica um número variável de argumentos, seguido por uma definição de função que fornece um tipo em vez de:  
  
```  
void myfunc( int x, ... );  
void myfunc( int x, char * c )  
{ }  
```  
  
## Comentários de linha única  
 O compilador C oferece suporte aos comentários de linha única, que são apresentados usando dois caracteres de barra \(\/\):  
  
```  
// This is a single-line comment.  
```  
  
## Escopo  
 O compilador C oferece suporte aos seguintes recursos escopo\- relacionados.  
  
-   Redefinições de itens extern como estático:  
  
    ```  
    extern int clip();  
    static int clip()  
    {}  
    ```  
  
-   O uso de volta benignas do typedef dentro do mesmo define o escopo:  
  
    ```  
    typedef int INT;  
    typedef int INT;  
    ```  
  
-   Os declarators da função têm o escopo do arquivo:  
  
    ```  
    void func1()  
    {  
        extern int func2( double );  
    }  
    int main( void )  
    {  
        func2( 4 );    //  /Ze passes 4 as type double  
    }                  //  /Za passes 4 as type int  
    ```  
  
-   Uso de variáveis de bloco\- escopo que são inicializados usando expressões não constante:  
  
    ```  
    int clip( int );  
    int bar( int );  
    int main( void )  
    {  
        int array[2] = { clip( 2 ), bar( 4 ) };  
    }  
    int clip( int x )  
    {  
        return x;  
    }  
    int bar( int x )  
    {  
        return x;  
    }  
    ```  
  
## Declarações e definições de dados  
 O compilador C oferece suporte aos seguintes recursos de declaração e de definição de dados.  
  
-   Constantes mistas e de caractere da cadeia de caracteres em um inicializador:  
  
    ```  
    char arr[5] = {'a', 'b', "cde"};  
    ```  
  
-   Campos de bits que têm tipos diferentes de base de **unsigned int** ou de **signed int**.  
  
-   Declarators que não têm um tipo:  
  
    ```  
    x;  
    int main( void )  
    {  
        x = 1;  
    }  
    ```  
  
-   Matrizes Unsized como o último campo nas estruturas e uniões em:  
  
    ```  
    struct zero  
    {  
        char *c;  
        int zarray[];  
    };  
    ```  
  
-   Estruturas \(anônimas\) sem nome:  
  
    ```  
    struct  
    {  
        int i;  
        char *s;  
    };  
    ```  
  
-   Uniões \(anônimas\) sem nome:  
  
    ```  
    union  
    {  
        int i;  
        float fl;  
    };  
    ```  
  
-   Membros sem nome:  
  
    ```  
    struct s  
    {  
       unsigned int flag : 1;  
       unsigned int : 31;  
    }  
    ```  
  
## Funções de ponto flutuante intrínsecas  
 O compilador do C\+\+ e suporte do compilador C geração embutido **x86 Specific \>** de `atan`, de `atan2`, de `cos`, de `exp`, de `log`, de `log10`, de `sin`, de `sqrt`, e funções **END x86 Specific** de `tan` quando **\/Oi** seja especificado.  Para o compilador C, conformidade ANSI é perdida quando esses intrinsics são usados, porque não definem a variável de `errno` .  
  
## Transmitindo um parâmetro de ponteiro de não const a uma função que aguarda uma referência a um parâmetro de ponteiro de const  
 Essa é uma extensão do C\+\+.  Esse código criará com **\/Ze**:  
  
```  
typedef   int   T;  
  
const T  acT = 9;      // A constant of type 'T'  
const T* pcT = &acT;   // A pointer to a constant of type 'T'  
  
void func2 ( const T*& rpcT )   // A reference to a pointer to a constant of type 'T'  
{  
   rpcT = pcT;  
}  
  
T*   pT;               // A pointer to a 'T'  
  
void func ()  
{  
   func2 ( pT );      // Should be an error, but isn't detected  
   *pT   = 7;         // Invalidly overwrites the constant 'acT'  
}  
```  
  
## ISO646.H não habilitado  
 Em **\/Ze**, você tem que incluir iso646.h se você desejar usar formas de texto dos seguintes operadores:  
  
-   && \(e\)  
  
-   &\= \(and\_eq\)  
  
-   & \(bitand\)  
  
-   &#124; \(bitor\)  
  
-   ~ \(compl\)  
  
-   \! \(não\)  
  
-   \!\= \(not\_eq\)  
  
-   &#124;&#124; \(ou\)  
  
-   &#124;\= \(or\_eq\)  
  
-   ^ \(XOR\)  
  
-   ^\= \(xor\_eq\)  
  
## O endereço de literal de cadeia de caracteres tiver o caractere de const de tipo \[\], não o caractere de const \(\*\) \[\]  
 O exemplo const char de saída \(\*\) \[4\] em **\/Za**, mas const char \[4\] em **\/Ze**.  
  
```  
#include <stdio.h>  
#include <typeinfo>  
  
int main()  
{  
    printf_s("%s\n", typeid(&"abc").name());  
}  
```  
  
## Consulte também  
 [\/Za, \/Ze \(desabilitar extensões de linguagem\)](../../build/reference/za-ze-disable-language-extensions.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)