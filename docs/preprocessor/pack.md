---
title: Pragma pack
ms.date: 07/22/2020
f1_keywords:
- pack_CPP
- vc-pragma.pack
helpviewer_keywords:
- pragmas, pack
- pack pragma
ms.assetid: e4209cbb-5437-4b53-b3fe-ac264501d404
ms.openlocfilehash: 72f94520516cce2ae36b70795fb29e3d4d8068df
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219385"
---
# <a name="pack-pragma"></a>Pragma pack

Especifica o alinhamento da embalagem para a estrutura, União e membros de classe.

## <a name="syntax"></a>Sintaxe

> **`#pragma pack( show )`**\
> **`#pragma pack( push`** [ **`,`** *`identifier`* ] [ **`,`** *`n`* ] **`)`**\
> **`#pragma pack( pop`** [ **`,`** { *`identifier`* | *`n`* } ] **`)`**\
> **`#pragma pack(`** [ *`n`* ] **`)`**

### <a name="parameters"></a>parâmetros

**`show`**\
Adicional Exibe o valor de byte atual para o alinhamento da embalagem. O valor é exibido por uma mensagem de aviso.

**`push`**\
Adicional Envia o valor de alinhamento atual da embalagem na pilha interna do compilador e define o valor de alinhamento atual da embalagem como *n*. Se *n* não for especificado, o valor de alinhamento de embalagem atual será enviado por push.

**`pop`**\
Adicional Remove o registro da parte superior da pilha interna do compilador. Se *n* não for especificado com **`pop`** , o valor de embalagem associado ao registro resultante na parte superior da pilha será o novo valor de alinhamento de embalagem. Se *n* for especificado, por exemplo, `#pragma pack(pop, 16)` *n* se tornará o novo valor de alinhamento de embalagem. Se você pop-up usando um *`identifier`* , por exemplo,, `#pragma pack(pop, r1)` todos os registros na pilha serão retirados até o registro que foi *`identifier`* encontrado. Esse registro é exibido e o valor de embalagem associado ao registro encontrado na parte superior da pilha se torna o novo valor de alinhamento de embalagem. Se você pop-up usando um *`identifier`* que não seja encontrado em nenhum registro na pilha, o **`pop`** será ignorado.

A instrução `#pragma pack (pop, r1, 2)` é equivalente a `#pragma pack (pop, r1)` seguido de `#pragma pack(2)` .

*`identifier`*\
Adicional Quando usado com **`push`** , o atribui um nome ao registro na pilha interna do compilador. Quando usado com **`pop`** , o exibe registros da pilha interna até que *`identifier`* seja removido. Se *`identifier`* não for encontrado na pilha interna, nada será exibido.

*`n`*\
Adicional Especifica o valor, em bytes, a ser usado para empacotamento. Se a opção do compilador [`/Zp`](../build/reference/zp-struct-member-alignment.md) não estiver definida para o módulo, o valor padrão para *`n`* será 8. Os valores válidos são 1, 2, 4, 8 e 16. O alinhamento de um membro está em um limite que é um múltiplo de *`n`* ou um múltiplo do tamanho do membro, o que for menor.

## <a name="remarks"></a>Comentários

Para *empacotar* uma classe, coloque seus membros diretamente depois um do outro na memória. Isso pode significar que alguns ou todos os membros podem ser alinhados em um limite menor do que o alinhamento padrão da arquitetura de destino. **`pack`** concede o controle no nível de declaração de dados. Ele difere da opção do compilador [`/Zp`](../build/reference/zp-struct-member-alignment.md) , que fornece apenas o controle de nível de módulo. o **pacote** entra em vigor na **`struct`** primeira **`union`** declaração, ou **`class`** depois que o pragma é visto. **`pack`** Não tem nenhum efeito nas definições. Chamar sem **`pack`** argumentos define *`n`* como o valor definido na opção do compilador **`/Zp`** . Se a opção do compilador não estiver definida, o valor padrão será 8 para x86, ARM e ARM64. O padrão é 16 para x64 nativo.

Se você alterar o alinhamento de uma estrutura, ela não poderá usar o máximo de espaço na memória. No entanto, você pode ver uma perda de desempenho ou até mesmo obter uma exceção gerada pelo hardware para acesso não alinhado. Você pode modificar esse comportamento de exceção usando [`SetErrorMode`](/windows/win32/api/errhandlingapi/nf-errhandlingapi-seterrormode) .

Para obter mais informações sobre como modificar o alinhamento, consulte estes artigos:

- [`alignof`](../cpp/alignof-operator.md)

- [`align`](../cpp/align-cpp.md)

- [`__unaligned`](../cpp/unaligned.md)

- [Exemplos de alinhamento de estrutura](../build/x64-software-conventions.md#examples-of-structure-alignment) (específico para x64)

   > [!WARNING]
   > No Visual Studio 2015 e posterior, você pode usar o padrão **`alignas`** e os **`alignof`** operadores, que, ao contrário, **`__alignof`** **`__declspec( align )`** são portáteis entre compiladores. O padrão C++ não trata de empacotamento, portanto, você ainda deve usar **`pack`** (ou a extensão correspondente em outros compiladores) para especificar alinhamentos menores do que o tamanho da palavra da arquitetura de destino.

## <a name="examples"></a>Exemplos

O exemplo a seguir mostra como usar o **`pack`** pragma para alterar o alinhamento de uma estrutura.

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

O exemplo a seguir mostra como usar a sintaxe *Push*, *pop*e *show* .

```cpp
// pragma_directives_pack_2.cpp
// compile with: /W1 /c
#pragma pack()   // n defaults to 8; equivalent to /Zp8
#pragma pack(show)   // C4810
#pragma pack(4)   // n = 4
#pragma pack(show)   // C4810
#pragma pack(push, r1, 16)   // n = 16, pushed to stack
#pragma pack(show)   // C4810

// pop to the identifier and then set
// the value of the current packing alignment:
#pragma pack(pop, r1, 2)   // n = 2 , stack popped
#pragma pack(show)   // C4810
```

## <a name="see-also"></a>Confira também

[Diretivas pragma e a `__pragma` palavra-chave](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
