---
title: Usando extern para especificar ligação | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-language
ms.tgt_pltfrm: ''
ms.topic: language-reference
f1_keywords:
- extern
dev_langs:
- C++
helpviewer_keywords:
- extern keyword [C++], linkage to non-C++ functions
- declarations, external
- external linkage, extern modifier
ms.assetid: 1e2f0ae3-ae98-4410-85b5-222d6abc865a
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: db93feb8c8fad13cf8de082858e68b89f93b5323
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-extern-to-specify-linkage"></a>Usando extern para especificar ligação
## <a name="syntax"></a>Sintaxe  
  
```  
  
      extern string-literal { declaration-list }  
extern string-literal declaration  
```  
  
## <a name="remarks"></a>Comentários  
 A palavra-chave `extern` declara uma variável ou uma função e especifica que tem vinculação externa (seu nome é visível em arquivos diferentes daquele em que é definida). Ao alterar uma variável, `extern` especifica que a variável tem duração estática (é atribuída quando o programa começa e desalocada quando o programa é encerrado). A variável ou função pode ser definida em outro arquivo de origem, ou posteriormente no mesmo arquivo. As declarações de variáveis e funções no escopo do arquivo são externas por padrão.  
  
## <a name="example"></a>Exemplo  
  
```  
// specifying_linkage1.cpp  
int i = 1;  
void other();  
  
int main() {  
   // Reference to i, defined above:  
   extern int i;  
}  
  
void other() {  
   // Address of global i assigned to pointer variable:  
   static int *external_i = &i;  
  
   // i will be redefined; global i no longer visible:  
   // int i = 16;  
}  
```  
  
 Em C++, quando usada com uma cadeia de caracteres, `extern` especifica que as convenções de vinculação de outra linguagem estão sendo usadas para os declaradores. As funções C e os dados podem ser acessados somente se forem declarados anteriormente como tendo vinculação C. No entanto, devem ser definidos em uma unidade de conversão compilada separadamente.  
  
 Microsoft C++ oferece suporte as cadeias de caracteres **"C"** e **"C++"** no *literal de cadeia de caracteres* campo. Todos os arquivos de inclusão padrão usam a sintaxe `extern` “C ” para permitir que funções da biblioteca em tempo de execução sejam usadas em programas C++.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra formas alternativas de declarar os nomes que têm vinculação C:  
  
```  
// specifying_linkage2.cpp  
// compile with: /c  
// Declare printf with C linkage.  
extern "C" int printf( const char *fmt, ... );  
  
//  Cause everything in the specified header files  
//   to have C linkage.  
extern "C" {  
   // add your #include statements here  
   #include <stdio.h>  
}  
  
//  Declare the two functions ShowChar and GetChar  
//   with C linkage.  
extern "C" {  
   char ShowChar( char ch );  
   char GetChar( void );  
}  
  
//  Define the two functions ShowChar and GetChar  
//   with C linkage.  
extern "C" char ShowChar( char ch ) {  
   putchar( ch );  
   return ch;  
}  
  
extern "C" char GetChar( void ) {  
   char ch;  
  
   ch = getchar();  
   return ch;  
}  
  
// Declare a global variable, errno, with C linkage.  
extern "C" int errno;  
```  
  
 Se uma função tiver mais de uma especificação de vinculação, elas devem concordar; é errado declarar funções como tendo o vínculos de C e C++. Além disso, se duas declarações para uma função ocorrem em um programa — uma com uma especificação de vinculação e a outra sem — a declaração com a especificação de vinculação deve ser a primeira. Todas as declarações redundantes de funções que já têm a especificação de vinculação são atribuídas a uma vinculação especificada na primeira declaração. Por exemplo:  
  
```  
extern "C" int CFunc1();  
...  
int CFunc1();            // Redeclaration is benign; C linkage is  
                         //  retained.  
  
int CFunc2();  
...  
extern "C" int CFunc2(); // Error: not the first declaration of  
                         //  CFunc2;  cannot contain linkage  
                         //  specifier.  
```  
  
 Funções e objetos explicitamente declarado como **estático** dentro do corpo de um especificador de vinculação composta (**{}**) são tratados como funções estáticas ou objetos; o especificador de vinculação é ignorado. Funções e outros objetos se comportam como se declarados usando a palavra-chave `extern`. (Consulte [usando extern para especificar ligação](../cpp/using-extern-to-specify-linkage.md) para obter detalhes sobre o `extern` palavra-chave.)  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [extern especificador de classe de armazenamento](../c-language/extern-storage-class-specifier.md)   
 [Comportamento de identificadores](../c-language/behavior-of-identifiers.md)   
 [Vinculação](../c-language/linkage.md)