---
title: "Extensões da Microsoft para C e C++ | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- or_eq operator
- ~ operator, extensions to C/C++
- '& operator, extensions to C/C++'
- '&= operator'
- iso646.h header
- Xor operator, Microsoft extensions to C/C++
- '!= operator'
- '! operator, extension to C++'
- Or operator, Microsoft extensions to C/C++
- ^ operator, extensions to C/C++
- ^= operator, C++ extensions
- xor_eq operator
- and_eq operator
- Microsoft extensions to C/C++
- '|= operator'
- '|| operator'
- And operator, extensions to C/C++
- NOT operator
- '&& operator'
- extensions, C language
- Visual C++, extensions to C/C++
- '| operator, extensions'
- not_eq operator
- Visual C, Microsoft extensions
- extensions
- compl method
ms.assetid: e811a74a-45ba-4c00-b206-2f2321b8689a
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d8453209a92b8f7485a9e7f575fb8810196d27fb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="microsoft-extensions-to-c-and-c"></a>Extensões da Microsoft para C e C++
Visual C++ estende os padrões ANSI C e C++ ANSI da seguinte maneira.  
  
## <a name="keywords"></a>Palavras-chave  
 Várias palavras-chave são adicionadas. Na lista na [palavras-chave](../../cpp/keywords-cpp.md), as palavras-chave com dois sublinhados são extensões do Visual C++.  
  
## <a name="out-of-class-definition-of-static-const-integral-or-enum-members"></a>Sem membros de definição de classe estática Integral const (ou enum)  
 Sob o padrão (**/Za**), você deve fazer uma definição de fora da classe para membros de dados, como mostrado aqui:  
  
```  
  
      class CMyClass  {  
   static const int max = 5;  
   int m_array[max];  
}  
...  
const int CMyClass::max;   // out of class definition  
```  
  
 Em **/Ze**, a definição de fora da classe é opcional para membros de dados static, const enum integral e const. Somente integrais e enumerações que são estáticos e const podem ter inicializadores em uma classe. a expressão de inicialização deve ser uma expressão constante.  
  
 Para evitar erros quando uma definição de fora da classe é fornecida em um cabeçalho de arquivo e o arquivo de cabeçalho é incluído em vários arquivos de origem, use [selectany](../../cpp/selectany.md). Por exemplo:  
  
```  
__declspec(selectany) const int CMyClass::max = 5;  
```  
  
## <a name="casts"></a>Conversões  
 O compilador do C++ e o compilador C dar suporte a esses tipos de conversões de não-ANSI:  
  
-   Conversões de não-ANSI para produzir valores l. Por exemplo:  
  
    ```  
    char *p;  
    (( int * ) p )++;  
    ```  
  
    > [!NOTE]
    >  Essa extensão está disponível na linguagem C somente. Você pode usar o seguinte formato padrão ANSI C no código C++ para modificar um ponteiro, como se fosse um ponteiro para um tipo diferente.  
  
     O exemplo anterior poderia ser reescrito da seguinte maneira para estar de acordo com o padrão ANSI C.  
  
    ```  
    p = ( char * )(( int * )p + 1 );  
    ```  
  
-   Conversões de não-ANSI de um ponteiro de função para um ponteiro de dados. Por exemplo:  
  
    ```  
    int ( * pfunc ) ();   
    int *pdata;  
    pdata = ( int * ) pfunc;  
    ```  
  
     Para executar a mesma conversão e também manter a compatibilidade ANSI, você pode converter o ponteiro de função para um `uintptr_t` antes de convertê-lo para um ponteiro de dados:  
  
    ```  
    pdata = ( int * ) (uintptr_t) pfunc;  
    ```  
  
## <a name="variable-length-argument-lists"></a>Listas de argumentos de comprimento variável  
 O compilador do C++ e o compilador C suportam um Declarador de função que especifica um número variável de argumentos, seguido por uma definição de função que fornece um tipo em vez disso:  
  
```  
void myfunc( int x, ... );  
void myfunc( int x, char * c )  
{ }  
```  
  
## <a name="single-line-comments"></a>Comentários de linha única  
 O compilador C oferece suporte a comentários de linha única, que são introduzidos pelo usando dois barra invertida (/ /) caracteres:  
  
```  
// This is a single-line comment.  
```  
  
## <a name="scope"></a>Escopo  
 O compilador do C suporta os seguintes recursos de escopo.  
  
-   Redefinições de itens extern como estático:  
  
    ```  
    extern int clip();  
    static int clip()  
    {}  
    ```  
  
-   Uso de redefinições de typedef benignas dentro do mesmo escopo:  
  
    ```  
    typedef int INT;  
    typedef int INT;  
    ```  
  
-   Declaradores de função tem um escopo de arquivo:  
  
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
  
-   Uso de variáveis de escopo de bloco que são inicializadas usando expressões não constantes:  
  
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
  
## <a name="data-declarations-and-definitions"></a>Definições e declarações de dados  
 O compilador do C suporta os seguintes recursos de declaração e definição de dados.  
  
-   Constantes de caractere e de cadeia de caracteres mistos um inicializador de:  
  
    ```  
    char arr[5] = {'a', 'b', "cde"};  
    ```  
  
-   Campos que têm tipos de base diferente de bit **int não assinado** ou **assinado int**.  
  
-   Declaradores que não têm um tipo:  
  
    ```  
    x;  
    int main( void )  
    {  
        x = 1;  
    }  
    ```  
  
-   Matrizes sem tamanho como o último campo em estruturas e uniões:  
  
    ```  
    struct zero  
    {  
        char *c;  
        int zarray[];  
    };  
    ```  
  
-   Estruturas (anônimas) sem nome:  
  
    ```  
    struct  
    {  
        int i;  
        char *s;  
    };  
    ```  
  
-   Uniões (anônimos) sem nome:  
  
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
  
## <a name="intrinsic-floating-point-functions"></a>Funções intrínsecas de ponto flutuantes  
 O compilador do C++ e o compilador C dão suporte à geração de embutido **x86 específico >** do `atan`, `atan2`, `cos`, `exp`, `log`, `log10`, `sin`, `sqrt`, e `tan` funções **final x86 específico** quando **/Oi** for especificado. Para o compilador do C, conformidade com ANSI é perdida quando esses intrínsecos são usados, porque eles não definirem o `errno` variável.  
  
## <a name="passing-a-non-const-pointer-parameter-to-a-function-that-expects-a-reference-to-a-const-pointer-parameter"></a>Passando um parâmetro de ponteiro não constante para uma função que espera uma referência a um parâmetro de ponteiro Const  
 Essa é uma extensão para C++. Esse código será compilado com **/Ze**:  
  
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
  
## <a name="iso646h-not-enabled"></a>ISO646. H não habilitado  
 Em **/Ze**, você precisa incluir iso646. h, se você quiser usar formas de texto dos operadores a seguir:  
  
-   & & (e)  
  
-   & = (and_eq)  
  
-   & (bitand)  
  
-   &#124; (bitor)  
  
-   ~ (concluído)  
  
-   ! (não)  
  
-   ! = (not_eq)  
  
-   &#124; &#124; (ou)  
  
-   &#124; = (or_eq)  
  
-   ^ (xor)  
  
-   ^ = (xor_eq)  
  
## <a name="address-of-string-literal-has-type-const-char--not-const-char--"></a>Endereço da cadeia de caracteres Literal tem tipo const char [], não const char (*)]  
 O exemplo a seguir produzirá char const (\*) [4] em **/Za**, mas char const [4] em **/Ze**.  
  
```  
#include <stdio.h>  
#include <typeinfo>  
  
int main()  
{  
    printf_s("%s\n", typeid(&"abc").name());  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [/Za, /Ze (desabilitar extensões de linguagem)](../../build/reference/za-ze-disable-language-extensions.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)