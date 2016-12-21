---
title: "Sem&#226;ntica de express&#245;es | Microsoft Docs"
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
helpviewer_keywords: 
  - "avaliação de expressão"
  - "avaliação de expressão, sobre avaliação de expressão"
  - "expressões [C++], semântica"
  - "gramática, expressões"
ms.assetid: 4a792154-533b-48b9-8709-31bfc170f0a7
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Sem&#226;ntica de express&#245;es
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As expressões são avaliadas de acordo com a precedência e o agrupamento dos respectivos operadores.  \(O tópico sobre [precedência e associatividade de operadores](../cpp/cpp-built-in-operators-precedence-and-associativity.md), em [Convenções léxicas](../cpp/lexical-conventions.md), mostra as relações que os operadores do C\+\+ impõem às expressões.\)  
  
## Ordem de avaliação  
 Considere este exemplo:  
  
```  
// expre_pluslang__pluslang_Order_of_Evaluation.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
int main()  
{  
    int a = 2, b = 4, c = 9;  
  
    cout << a + b * c << "\n";  
    cout << a + (b * c) << "\n";  
    cout << (a + b) * c << "\n";  
}  
//Output:  
38  
38  
54  
```  
  
 ![Ordem de avaliação de expressão](../Image/vc38ZV1.gif "vc38ZV1")  
Ordem de avaliação da expressão  
  
 A ordem na qual a expressão mostrada na figura acima é avaliada é determinada pela precedência e associatividade dos operadores:  
  
1.  A multiplicação \(\*\) tem a precedência mais alta nessa expressão; portanto, a subexpressão `b * c` é avaliada primeiro.  
  
2.  A adição \(\+\) tem a precedência mais alta a seguir, de modo que `a` é adicionado ao produto de `b` vezes `c`.  
  
3.  O deslocamento para a esquerda \(\<\<\) tem a precedência mais baixa na expressão, mas há duas ocorrências.  Como o operador de deslocamento para a esquerda é agrupado da esquerda para a direita, a subexpressão à esquerda é avaliada primeiro, seguida pela subexpressão à direita.  
  
 Quando são usados parênteses para agrupar as subexpressões, eles alteram a precedência e também a ordem em que a expressão é avaliada, conforme mostra a figura a seguir.  
  
 ![Ordem de avaliação de expressões com parênteses](../cpp/media/vc38zv2.png "vc38ZV2")  
Ordem de avaliação da expressão com parênteses  
  
 Expressões como as da figura acima são avaliadas apenas por seus efeitos colaterais — nesse caso, para transferir informações para o dispositivo de saída padrão.  
  
## Notação em expressões  
 A linguagem C\+\+ especifica determinadas compatibilidades ao especificar operandos.  A tabela a seguir mostra os tipos de operandos aceitáveis aos operadores que exigem operandos de tipo `type`.  
  
### Tipos de operandos aceitáveis para operadores  
  
|Tipo esperado|Tipos permitidos|  
|-------------------|----------------------|  
|`type`|**const** *type*<br /><br /> `volatile` *type*<br /><br /> `type`&<br /><br /> **const** `type`&<br /><br /> `volatile` `type`&<br /><br /> **const volatile** *tipo*<br /><br /> **volatile const** `type`&|  
|*type\**|`type`\* **const**`type`\* `volatile``type`\* **const volatile**|  
|**const** `type`|`type` **const** `type`**const** `type`&|  
|`volatile` `type`|`type` `volatile` `type``volatile` `type`&|  
  
 Como as regras acima podem sempre ser usadas em conjunto, um ponteiro const para um objeto volatile pode ser fornecido onde um ponteiro é esperado.  
  
## Expressões ambíguas  
 Algumas expressões são ambíguas em seu significado.  Essas expressões ocorrem com mais frequência quando o valor de um objeto é modificado mais de uma vez na mesma expressão.  Essas expressões confiam em uma determinada ordem de avaliação, onde a linguagem não define uma.  Considere o exemplo a seguir:  
  
```  
int i = 7;  
  
func( i, ++i );  
```  
  
 A linguagem C\+\+ não garante a ordem de avaliação dos argumentos para uma chamada de função.  Portanto, no exemplo anterior, `func` pode receber os valores 7 e 8 ou 8 e 8 para seus parâmetros, dependendo se os parâmetros são avaliados da esquerda para a direita ou da direita para a esquerda.  
  
## Pontos de sequência do C\+\+ \(Specific da Microsoft\)  
 Uma expressão pode modificar o valor de um objeto apenas uma vez entre "pontos de sequência" consecutivos.  
  
 No momento, a definição da linguagem C\+\+ não especifica pontos de sequência.  O Microsoft C\+\+ usa os mesmos pontos de sequência que o ANSI C para qualquer expressão que envolva operadores de C e não envolva operadores sobrecarregados.  Quando os operadores estão sobrecarregados, a semântica muda de sequenciamento de operadores para sequenciamento de chamada de funções.  O Microsoft C\+\+ os seguintes pontos de sequência:  
  
-   Operando esquerdo do operador AND lógico \(&&\).  O operando esquerdo do operador AND lógico é completamente avaliado e todos os efeitos colaterais são concluídos antes de continuar.  Não há nenhuma garantia de que o operando direito do operador AND lógico será avaliado.  
  
-   Operando esquerdo do operador OR lógico \(&#124;&#124;\).  O operando esquerdo do operador OR lógico é completamente avaliado e todos os efeitos colaterais são concluídos antes de continuar.  Não há nenhuma garantia de que o operando direito do operador OR lógico será avaliado.  
  
-   Operando esquerdo do operador vírgula  O operando esquerdo do operador vírgula é completamente avaliado e todos os efeitos colaterais são concluídos antes de continuar.  Os dois operandos do operador vírgula são sempre avaliados.  
  
-   Operador de chamada de função.  A expressão de chamada de função e todos os argumentos para uma função, inclusive os argumentos padrão, são avaliados e todos os efeitos colaterais são concluídos antes da entrada na função.  Não há nenhuma ordem de avaliação especificada entre os argumentos ou a expressão de chamada de função.  
  
-   Primeiro operando do operador condicional.  O primeiro operando do operador condicional é completamente avaliado e todos os efeitos colaterais são concluídos antes de continuar.  
  
-   O término de uma expressão de inicialização completa, por exemplo, o término de uma inicialização em uma instrução de declaração.  
  
-   A expressão em uma instrução de expressão.  As instruções da expressão consistem em uma expressão opcional seguida por um ponto e vírgula \(;\).  A expressão é completamente avaliada em relação a seus efeitos colaterais.  
  
-   A expressão de controle em uma instrução de seleção \(if ou switch\).  A expressão é completamente avaliada e todos os efeitos colaterais são concluídos antes que o código dependente da seleção seja executado.  
  
-   A expressão de controle de uma instrução while ou do.  A expressão é completamente avaliada e todos os efeitos colaterais são concluídos antes que as instruções na próxima iteração do loop while ou do sejam executadas.  
  
-   Cada uma das três expressões de uma instrução for.  Cada expressão é completamente avaliada e todos os efeitos colaterais são concluídos antes de passar para a próxima expressão.  
  
-   A expressão em uma instrução return.  A expressão é completamente avaliada e todos os efeitos colaterais são concluídos antes que o controle retorne à função de chamada.  
  
## Consulte também  
 [Expressões](../cpp/expressions-cpp.md)