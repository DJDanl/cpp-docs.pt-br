---
title: pack
ms.date: 12/17/2018
f1_keywords:
- pack_CPP
- vc-pragma.pack
helpviewer_keywords:
- pragmas, pack
- pack pragma
ms.assetid: e4209cbb-5437-4b53-b3fe-ac264501d404
ms.openlocfilehash: bf1ae81184d53dd271f63c26e8f9a52a6410b232
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59038441"
---
# <a name="pack"></a>pack
Especifica o alinhamento de empacotamento da estrutura, união e membros da classe.

## <a name="syntax"></a>Sintaxe

```
#pragma pack( [ show ] | [ push | pop ] [, identifier ] , n  )
```

### <a name="parameters"></a>Parâmetros

**programa**<br/>
(Opcional) Exibe o valor atual de bytes para alinhamento de empacotamento. O valor é exibido por uma mensagem de aviso.

**push**<br/>
(Opcional) Valor de alinhamento de empacotamento atual de envios por push na pilha interna do compilador e define o valor de alinhamento de empacotamento atual para *n*. Se *n* não for especificado, o atual valor de alinhamento de empacotamento é enviada por push.

**pop**<br/>
(Opcional) Remove o registro do topo da pilha interna do compilador. Se *n* não for especificado com **pop-up**, em seguida, o valor de empacotamento associado ao registro resultante na parte superior da pilha é o novo valor de alinhamento de empacotamento. Se *n* for especificado, por exemplo, `#pragma pack(pop, 16)`, *n* se torna o novo valor de alinhamento de empacotamento. Se você exibir com *identificador*, por exemplo, `#pragma pack(pop, r1)`, em seguida, todos os registros na pilha são exibidos até o registro que tem *identificador* for encontrado. Esse registro é exibido e o valor de empacotamento associado ao registro resultante na parte superior da pilha é o novo valor do alinhamento de empacotamento. Se você exibir com um *identificador* não for encontrado em nenhum registro na pilha, em seguida, a **pop-up** será ignorado.

*identifier*<br/>
(Opcional) Quando usado com *push*, atribui um nome ao registro na pilha interna do compilador. Quando usado com **pop-up**, elimina registros da pilha interna até *identificador* for removido; se *identificador* não for localizado na pilha interna, nada será exibido.

*n*<br/>
(Opcional) Especifica o valor, em bytes, para ser usado para o empacotamento. Se a opção de compilador [/Zp](../build/reference/zp-struct-member-alignment.md) não está definido para o módulo, o valor padrão de *n* é 8. Os valores válidos são 1, 2, 4, 8 e 16. O alinhamento de um membro será em um limite que seja um múltiplo de *n* ou um múltiplo do tamanho do membro, o que for menor.

`#pragma pack(pop, identifier, n)` é indefinido.

## <a name="remarks"></a>Comentários

Para empacotar uma classe é colocar seus membros diretamente após a outra na memória, o que pode significar que alguns ou todos os membros podem ser alinhados em um limite menor do que o alinhamento padrão a arquitetura de destino. **pacote de** proporciona controle no nível de declaração de dados. Isso é diferente da opção de compilador [/Zp](../build/reference/zp-struct-member-alignment.md), que fornece apenas o controle de nível de módulo. **Pack** entra em vigor na primeira **struct**, **união**, ou **classe** declaração após o pragma. **pacote de** não tem nenhum efeito nas definições. Chamando **pack** sem argumentos define *n* como um valor definido na opção de compilador `/Zp`. Se a opção de compilador não for definida, o valor padrão é 8.

Se você alterar o alinhamento de uma estrutura, isso pode não usar tanto espaço na memória, mas você pode passar por uma redução de desempenho ou mesmo uma exceção gerada por hardware devido ao acesso não alinhado.  Você pode modificar esse comportamento de exceção usando [SetErrorMode](https://msdn.microsoft.com/library/windows/desktop/ms680621).

Para obter mais informações sobre como modificar o alinhamento, consulte estes tópicos:

- [__alignof](../cpp/alignof-operator.md)

- [align](../cpp/align-cpp.md)

- [__unaligned](../cpp/unaligned.md)

- [Exemplos de alinhamento da estrutura](../build/x64-software-conventions.md#examples-of-structure-alignment) (específico para x64)

   > [!WARNING]
   > Observe que, no Visual Studio 2015 e posterior pode usar os operadores de alignof e alignas padrão que, diferentemente `__alignof` e `declspec( align )` são portáteis entre os compiladores. O padrão C++ não aborda o empacotamento, portanto, você ainda deve usar **pack** (ou a extensão correspondente nos outros compiladores) para especificar os alinhamentos menores do que o tamanho de palavras da arquitetura de destino.

## <a name="examples"></a>Exemplos

O exemplo a seguir mostra como usar o **pack** pragma para alterar o alinhamento de uma estrutura.

```cpp
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

```Output
0 4 8
0 4 6
```

O exemplo a seguir mostra como usar o *push*, *pop*, e *Mostrar* sintaxe.

```cpp
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

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)