---
title: Operador const_cast | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: const_cast_cpp
dev_langs: C++
helpviewer_keywords: const_cast keyword [C++]
ms.assetid: 4d8bb203-ef33-4a10-9f9f-c64d4fbc1687
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 79c4aa00038f2d4d7e5cc3d1c86d2e28c6d44229
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="constcast-operator"></a>Operador const_cast
Remove o **const**, `volatile`, e **unaligned** atributos de uma classe.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
const_cast <   
type-id  
 > (   
expression  
 )  
  
```  
  
## <a name="remarks"></a>Comentários  
 Um ponteiro para qualquer tipo de objeto ou um ponteiro para um membro de dados pode ser convertido explicitamente a um tipo que é idêntico, exceto para o **const**, `volatile`, e **unaligned** qualificadores. Para ponteiros e referências, o resultado fará referência ao objeto original. Para ponteiros para membros de dados, o resultado fará referência ao mesmo membro que o ponteiro original (não convertido) para o membro de dados. Dependendo do tipo do objeto referenciado, uma operação de gravação pelo ponteiro, referência ou ponteiro para o membro de dados resultante pode gerar comportamento indefinido.  
  
 Você não pode usar o operador `const_cast` para substituir diretamente o status de constante de uma variáveis constante.  
  
 O operador `const_cast` converte um valor de ponteiro nulo em valor de ponteiro nulo do tipo de destino.  
  
## <a name="example"></a>Exemplo  
  
```  
// expre_const_cast_Operator.cpp  
// compile with: /EHsc  
#include <iostream>  
  
using namespace std;  
class CCTest {  
public:  
   void setNumber( int );  
   void printNumber() const;  
private:  
   int number;  
};  
  
void CCTest::setNumber( int num ) { number = num; }  
  
void CCTest::printNumber() const {  
   cout << "\nBefore: " << number;  
   const_cast< CCTest * >( this )->number--;  
   cout << "\nAfter: " << number;  
}  
  
int main() {  
   CCTest X;  
   X.setNumber( 8 );  
   X.printNumber();  
}  
```  
  
 Na linha que contém `const_cast`, o tipo de dados de ponteiro `this` é `const CCTest *`. O operador `const_cast` altera o tipo de dados do ponteiro `this` para `CCTest *`, permitindo que o membro `number` seja alterado. A conversão só durará pelo restante da instrução em que aparece.  
  
## <a name="see-also"></a>Consulte também  
 [Operadores de conversão](../cpp/casting-operators.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)