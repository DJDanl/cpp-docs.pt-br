---
title: "const (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "const_cpp"
  - "const"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "palavra-chave const [C++]"
ms.assetid: b21c0271-1ad0-40a0-b21c-5e812bba0318
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# const (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Ao modificar uma declaração de dados, a palavra\-chave **const** especifica que o objeto ou a variável não é modificável.  
  
## Sintaxe  
  
```  
  
        const declaration ;  
member-function const ;  
```  
  
## valores de constante  
 A palavra\-chave **const** especifica que um valor de variável é constante e informa o compilador para impedir que o programador a modifique.  
  
```  
// constant_values1.cpp  
int main() {  
   const int i = 5;  
   i = 10;   // C3892  
   i++;   // C2105  
}  
```  
  
 Em C\+\+, você pode usar a palavra\-chave **const** em vez de política de pré\-processador [\#define](../preprocessor/hash-define-directive-c-cpp.md) para definir valores constantes.  Os valores definidos com **const** estão sujeitos à verificação de tipo e podem ser usados no lugar de expressões constantes.  Em C\+\+, você pode especificar o tamanho de uma matriz com uma variável **const** como a seguir:  
  
```  
// constant_values2.cpp  
// compile with: /c  
const int maxarray = 255;  
char store_char[maxarray];  // allowed in C++; not allowed in C  
```  
  
 Em C, os valores constantes usam como padrão o vínculo externo, assim eles podem aparecer somente em arquivos de origem.  Em C\+\+, os valores constantes usam como padrão o vínculo interno, que permite que eles apareçam em arquivos de cabeçalho.  
  
 A palavra\-chave **const** também pode ser usado em declarações de ponteiro.  
  
```  
// constant_values3.cpp  
int main() {  
   char *mybuf = 0, *yourbuf;  
   char *const aptr = mybuf;  
   *aptr = 'a';   // OK  
   aptr = yourbuf;   // C3892  
}  
```  
  
 Um ponteiro para uma variável declarada como **const** pode ser atribuído a um ponteiro que é declarado também como **const**.  
  
```  
// constant_values4.cpp  
#include <stdio.h>  
int main() {  
   const char *mybuf = "test";  
   char *yourbuf = "test2";  
   printf_s("%s\n", mybuf);  
  
   const char *bptr = mybuf;   // Pointer to constant data  
   printf_s("%s\n", bptr);  
  
   // *bptr = 'a';   // Error  
}  
```  
  
 Você pode usar ponteiros para os dados constantes como parâmetros de função para evitar que a função modifique um parâmetro passado por um ponteiro.  
  
 Para os objetos declarados como **const**, você poderá chamar apenas [funções de membro constantes](../misc/constant-member-functions.md).  Isso assegura que o objeto constante nunca seja modificado.  
  
```  
birthday.getMonth();    // Okay  
birthday.setMonth( 4 ); // Error  
```  
  
 Você pode chamar funções membro constantes ou não constantes para um objeto não constante.  Você também pode sobrecarregar uma função membro usando a palavra\-chave **const**; isso permite que uma versão diferente da função seja chamada para objetos constantes e não constantes.  
  
 Você não pode declarar construtores ou destruidores com a palavra\-chave **const**.  
  
## funções de membro const  
 A declaração de uma função membro com a palavra\-chave **const** especifica que aquela é uma função “somente leitura” que não modifica o objeto para o qual é chamada.  Uma função de membro constante não pode modificar nenhum membro de dados não estáticos ou chamar funções que não seja uma constantes de qualquer membro. Para declarar uma função de membro constante, coloque o **const** palavra\-chave após o parêntese de fechamento da lista de argumentos.  A palavra\-chave **const** é necessária na declaração e na definição.  
  
```  
// constant_member_function.cpp  
class Date  
{  
public:  
   Date( int mn, int dy, int yr );  
   int getMonth() const;     // A read-only function  
   void setMonth( int mn );   // A write function; can't be const  
private:  
   int month;  
};  
  
int Date::getMonth() const  
{  
   return month;        // Doesn't modify anything  
}  
void Date::setMonth( int mn )  
{  
   month = mn;          // Modifies data member  
}  
int main()  
{  
   Date MyDate( 7, 4, 1998 );  
   const Date BirthDate( 1, 18, 1953 );  
   MyDate.setMonth( 4 );    // Okay  
   BirthDate.getMonth();    // Okay  
   BirthDate.setMonth( 4 ); // C2662 Error  
}  
```  
  
## Diferenças entre const de C e C\+\+  
 Quando você declara uma variável como **const** no arquivo de origem de C, você faz de modo a:  
  
```  
const int i = 2;  
```  
  
 Então, você pode usar essa variável em outro módulo como segue:  
  
```  
extern const int i;  
```  
  
 Mas para obter o mesmo comportamento em C\+\+, você deve declarar sua variável **const** como:  
  
```  
extern const int i = 2;  
```  
  
 Se você quiser declarar uma variável `extern` no arquivo de código de origem de C\+\+ para uso no arquivo de código de origem de C, use:  
  
```  
extern "C" const int x=10;  
```  
  
 para evitar a desconfiguração do nome pelo compilador C\+\+.  
  
## Comentários  
 Após a lista de parâmetros de uma função membro, a palavra\-chave **const** especifica que a função não modifica o objeto para o qual é chamada.  
  
 Para obter mais informações sobre **const**, consulte os seguintes tópicos:  
  
-   [Valores de constante](../misc/constant-values.md)  
  
-   [Funções membro constantes](../misc/constant-member-functions.md)  
  
-   [Ponteiros const e volatile](../Topic/const%20and%20volatile%20Pointers.md)  
  
-   [Qualificadores de tipo \(Referência da linguagem C\)](../c-language/type-qualifiers.md)  
  
-   [volatile](../cpp/volatile-cpp.md)  
  
-   [\#define](../preprocessor/hash-define-directive-c-cpp.md).  
  
## Consulte também  
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)