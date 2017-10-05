---
title: Operador sizeof | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- sizeof_cpp
- sizeof
dev_langs:
- C++
helpviewer_keywords:
- sizeof operator
ms.assetid: 8bc3b6fb-54a1-4eb7-ada0-05f8c5efc532
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 67b699a93880a89e634ac024699ac79a9ea8d3ba
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="sizeof-operator"></a>Operador sizeof
Retorna o tamanho do operando em relação ao tamanho do tipo `char`.  
  
> [!NOTE]
>  Para obter informações sobre o `sizeof ...` operador, consulte [reticências e modelos Variadic](../cpp/ellipses-and-variadic-templates.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
sizeof unary-expression  
sizeof  ( type-name )  
```  
  
## <a name="remarks"></a>Comentários  
 O resultado do operador de `sizeof` é do tipo `size_t`, um tipo integral definido no arquivo. STDDEF.H de inclusão. Esse operador permite que você evite especificar tamanhos de dados dependentes do computador em seus programas.  
  
 O operando para `sizeof` pode ser um destes:  
  
-   O nome de um tipo. Para usar `sizeof` com o nome de um tipo, o nome deve ser colocado entre parênteses.  
  
-   Uma expressão. Quando usado com uma expressão, `sizeof` pode ser especificado com ou sem parênteses. A expressão não é avaliada.  
  
 Quando o operador de `sizeof` é aplicado a um objeto do tipo `char`, ele resulta em 1. Quando o operador de `sizeof` é aplicado a uma matriz, ele produz o número total de bytes na matriz, não o tamanho do ponteiro representado pelo identificador da matriz. Para obter o tamanho do ponteiro representado pelo identificador de matriz, transmita-o como um parâmetro para uma função que usa `sizeof`. Por exemplo:  
  
## <a name="example"></a>Exemplo  
  
```  
#include <iostream>  
using namespace std;  
  
size_t getPtrSize( char *ptr )  
{  
   return sizeof( ptr );  
}  
  
int main()  
{  
   char szHello[] = "Hello, world!";  
  
   cout  << "The size of a char is: "  
         << sizeof( char )  
         << "\nThe length of " << szHello << " is: "  
         << sizeof szHello  
         << "\nThe size of the pointer is "  
         << getPtrSize( szHello ) << endl;  
}  
```  
  
## <a name="sample-output"></a>Saída de Exemplo  
  
```  
The size of a char is: 1  
The length of Hello, world! is: 14  
The size of the pointer is 4  
```  
  
 Quando o operador de `sizeof` é aplicado a um tipo `class`, `struct` ou `union`, o resultado é o número de bytes em um objeto desse tipo, mais todos os preenchimentos adicionados para alinhar os membros em limites de palavras. O resultado não corresponde necessariamente ao tamanho calculado pela adição dos requisitos de armazenamento dos membros individuais. O [/Zp](../build/reference/zp-struct-member-alignment.md) opção de compilador e o [pacote](../preprocessor/pack.md) pragma afeta os limites de alinhamento de membros.  
  
 O operador de `sizeof` nunca resulta em 0, até mesmo para uma classe vazia.  
  
 O operador de `sizeof` não pode ser usado com os seguintes operandos:  
  
-   Funções. (No entanto, `sizeof` pode ser aplicado aos ponteiros para as funções.)  
  
-   Campos de bits.  
  
-   Classes indefinidas.  
  
-   O tipo `void`.  
  
-   Matrizes alocadas dinamicamente.  
  
-   Matrizes externas.  
  
-   Tipos incompletos.  
  
-   Nomes entre parênteses de tipos incompletos.  
  
 Quando o operador de `sizeof` é aplicado a uma referência, o resultado é o mesmo que seria obtido se `sizeof` tivesse sido aplicado ao próprio objeto.  
  
 Se uma matriz não dimensionada é o último elemento de uma estrutura, o operador `sizeof` retorna o tamanho da estrutura sem a matriz.  
  
 O operador de `sizeof` é frequentemente usado para calcular o número de elementos em uma matriz usando uma expressão no formato:  
  
```  
sizeof array / sizeof array[0]  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)
