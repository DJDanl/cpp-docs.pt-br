---
title: "pack | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "pack_CPP"
  - "vc-pragma.pack"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "pragma pack"
  - "pragmas, pack"
ms.assetid: e4209cbb-5437-4b53-b3fe-ac264501d404
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# pack
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica o alinhamento de empacotamento da estrutura, união e membros da classe.  
  
## Sintaxe  
  
```  
  
#pragma pack( [ show ] | [ push | pop ] [, identifier ] , n  )  
```  
  
## Comentários  
 Para uma classe do pacote é colocar seus membros diretamente após uma da outra na memória, o que pode significar que alguns ou todos os membros podem ser alinhados em um limite menor do que o alinhamento padrão a arquitetura de destino.  `pack` dá o controle no nível de declaração de dados.  Isso é diferente da opção de compilador [\/Zp](../Topic/-Zp%20\(Struct%20Member%20Alignment\).md), que fornece apenas o controle a nível de módulo.  `pack` entra em vigor no primeiro `struct`, `union`, ou a declaração `class` após a consideração do pragma.  `pack` não tem nenhum efeito em definições.  Chamar `pack` sem argumentos define `n` como um valor definido na opção de compilador **\/Zp**.  Se a opção de compilador não for definida, o valor padrão é 8.  
  
 Se você alterar o alinhamento de uma estrutura, isso pode não usar tanto espaço na memória, mas você pode passar por uma redução de desempenho ou mesmo uma exceção gerada por hardware devido ao acesso não alinhado.  Você pode alterar esse comportamento de exceção usando [SetErrorMode](http://msdn.microsoft.com/library/windows/desktop/ms680621).  
  
 **show** \(opcional\)  
 Exibe o valor atual de byte para o alinhamento de empacotamento.  O valor é exibido por uma mensagem de aviso.  
  
 **push** \(opcional\)  
 Impulsiona o valor atual do alinhamento de empacotamento atual na pilha interna do compilador e define o valor atual do alinhamento do empacotamento atual como `n`.  Se `n` não for especificado, o valor atual do alinhamento do empacotamento é impulsionado.  
  
 **pop** \(opcional\)  
 Remove o registro do topo da pilha interna do compilador.  Se `n` não for especificado com **pop**, o valor de empacotamento associado ao registro resultante na parte superior da pilha é o novo valor do alinhamento de empacotamento.  Se `n` for especificado, por exemplo, `#pragma pack(pop, 16)`, `n` se torna o novo valor de alinhamento de empacotamento.  Se você exibir com `identifier`, por exemplo, `#pragma pack(pop, r1)`, todos os registros na pilha são exibidos até o registro que tem `identifier` for localizado.  Esse registro é exibido e o valor de empacotamento associado ao registro resultante na parte superior da pilha é o novo valor do alinhamento de empacotamento.  Se você exibir com `identifier` que não foi encontrando em nenhum registro na pilha, então **pop** é ignorado.  
  
 `identifier` \(opcional\)  
 Quando usado com **push**, atribui um nome ao registro na pilha interna do compilador.  Quando usado com **pop**, elimina registros da pilha interna até que `identifier` seja removido; se `identifier` não for localizado na pilha interna, nada será exibido.  
  
 `n` \(opcional\)  
 Especifica o valor, em bytes, a ser usado para empacotamento.  Se a opção de compilador [\/Zp](../Topic/-Zp%20\(Struct%20Member%20Alignment\).md) não estiver definida para o módulo, o valor padrão é de 8. `n`.  Os valores válidos são 1, 2, 4, 8 e 16.  O alinhamento de um membro estará em um limite que é um múltiplo de `n` ou um múltiplo do tamanho do membro, o que for menor.  
  
 `#pragma pack(pop,` `identifier``,` `n``)` é indefinido.  
  
 Para obter mais informações sobre como modificar o alinhamento, consulte estes tópicos:  
  
-   [\_\_alignof](../cpp/alignof-operator.md)  
  
-   [align](../cpp/align-cpp.md)  
  
-   [\_\_unaligned](../cpp/unaligned.md)  
  
-   [Exemplos de alinhamento da estrutura](../build/examples-of-structure-alignment.md) \(específico para x64\)  
  
    > [!WARNING]
    >  Observe que no Visual Studio de 2015 e mais tarde você pode usar os operadores de alignof e alignas padrão que, diferentemente `__alignof` e `declspec( align )` são portáteis em compiladores.  O padrão C\+\+ não trata de remessa, você ainda deve usar `pack` \(ou a extensão correspondente em outros compiladores\) para especificar alinhamentos menores que a arquitetura de destino word.  
  
## Exemplo  
 O exemplo a seguir mostra como usar o pragma `pack` para alterar o alinhamento de uma estrutura.  
  
```  
// pragma_directives_pack.cpp  
#include <stddef.h>  
#include <stdio.h>  
  
struct S {  
   int i;   // size 4  
   short j;   // size 2  
   double k;   // size 8  
};  
  
#pragma pack(2)  
struct T {  
   int i;  
   short j;  
   double k;  
};  
  
int main() {  
   printf("%zu ", offsetof(S, i));  
   printf("%zu ", offsetof(S, j));  
   printf("%zu\n", offsetof(S, k));  
  
   printf("%zu ", offsetof(T, i));  
   printf("%zu ", offsetof(T, j));  
   printf("%zu\n", offsetof(T, k));  
}  
```  
  
```  
0 4 8  
0 4 6  
```  
  
## Exemplo  
 O exemplo a seguir mostra como usar a sintaxe **push**, **pop** e **show**.  
  
```  
// pragma_directives_pack_2.cpp  
// compile with: /W1 /c  
#pragma pack()   // n defaults to 8; equivalent to /Zp8  
#pragma pack(show)   // C4810  
#pragma pack(4)   // n = 4  
#pragma pack(show)   // C4810  
#pragma pack(push, r1, 16)   // n = 16, pushed to stack  
#pragma pack(show)   // C4810  
#pragma pack(pop, r1, 2)   // n = 2 , stack popped  
#pragma pack(show)   // C4810  
```  
  
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)