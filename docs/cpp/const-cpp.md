---
title: Const (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- const_cpp
dev_langs:
- C++
helpviewer_keywords:
- const keyword [C++]
ms.assetid: b21c0271-1ad0-40a0-b21c-5e812bba0318
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 73e030ede8305db4ea05826f0ce7704420ac0400
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39403395"
---
# <a name="const-c"></a>const (C++)
Ao modificar uma declaração de dados, o **const** palavra-chave especifica que o objeto ou uma variável não é modificável.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
const declaration ;  
member-function const ;  
```  
  
## <a name="const-values"></a>valores constantes  
 O **const** palavra-chave especifica que o valor da variável é constante e informa ao compilador para impedir que o programador de modificá-lo.  
  
```cpp 
// constant_values1.cpp  
int main() {  
   const int i = 5;  
   i = 10;   // C3892  
   i++;   // C2105  
}  
```  
  
 No C++, você pode usar o **const** palavra-chave, em vez da [#define](../preprocessor/hash-define-directive-c-cpp.md) diretiva de pré-processador para definir valores de constante. Valores definidos com **const** estão sujeitos à verificação de tipo e pode ser usado no lugar de expressões de constante. No C++, você pode especificar o tamanho de uma matriz com um **const** variável da seguinte maneira:  
  
```cpp 
// constant_values2.cpp  
// compile with: /c  
const int maxarray = 255;  
char store_char[maxarray];  // allowed in C++; not allowed in C  
```  
  
 Em C, os valores constantes usam como padrão o vínculo externo, assim eles podem aparecer somente em arquivos de origem. Em C++, os valores constantes usam como padrão o vínculo interno, que permite que eles apareçam em arquivos de cabeçalho.  
  
 O **const** palavra-chave também pode ser usado em declarações de ponteiro.  
  
```cpp 
// constant_values3.cpp  
int main() {  
   char *mybuf = 0, *yourbuf;  
   char *const aptr = mybuf;  
   *aptr = 'a';   // OK  
   aptr = yourbuf;   // C3892  
}  
```  
  
 Um ponteiro para uma variável declarada como **const** pode ser atribuída somente a um ponteiro que também é declarado como **const**.  
  
```cpp 
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
  
 Para objetos que são declarados como **const**, só é possível chamar membro constante funções. Isso assegura que o objeto constante nunca seja modificado.  
  
```cpp 
birthday.getMonth();    // Okay  
birthday.setMonth( 4 ); // Error  
```  
  
 Você pode chamar funções membro constantes ou não constantes para um objeto não constante. Você também pode sobrecarregar uma função de membro usando o **const** palavra-chave; Isso permite que uma versão diferente da função a ser chamado para objetos constantes e.  
  
 Você não pode declarar construtores ou destruidores com a **const** palavra-chave.  
  
## <a name="const-member-functions"></a>funções de membro const  
 Declarar uma função de membro com o **const** palavra-chave especifica que a função é uma função de "somente leitura" que não modifica o objeto para o qual ele é chamado. Uma função de membro constante não é possível modificar todos os membros de dados não estáticos ou chamar funções que não seja uma constantes de qualquer membro. Para declarar uma função de membro constante, coloque o **const** palavra-chave após o parêntese de fechamento da lista de argumentos. O **const** palavra-chave é necessária na declaração e a definição.  
  
```cpp 
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
  
## <a name="c-and-c-const-differences"></a>Diferenças entre const de C e C++  
 Quando você declara uma variável como **const** em um arquivo de código de origem de C, você fazer isso como:  
  
```cpp 
const int i = 2;  
```  
  
 Então, você pode usar essa variável em outro módulo como segue:  
  
```cpp 
extern const int i;  
```  
  
 Mas para obter o mesmo comportamento em C++, você deve declarar sua **const** variável como:  
  
```cpp 
extern const int i = 2;  
```  
  
 Se você quiser declarar uma **extern** variável em um arquivo de código fonte C++ para uso em um arquivo de código de origem do C, use:  
  
```cpp 
extern "C" const int x=10;  
```  
  
 para evitar a desconfiguração do nome pelo compilador C++.  
  
## <a name="remarks"></a>Comentários  
 Ao seguir a lista de parâmetros de função de membro, o **const** palavra-chave especifica que a função não modifica o objeto para o qual ele é invocado.  
  
 Para obter mais informações sobre **const**, consulte os seguintes tópicos:  
    
-   [Ponteiros const e volatile](../cpp/const-and-volatile-pointers.md)  
  
-   [Qualificadores de tipo (referência da linguagem C)](../c-language/type-qualifiers.md)  
  
-   [volatile](../cpp/volatile-cpp.md)  
  
-   [#define](../preprocessor/hash-define-directive-c-cpp.md).  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)