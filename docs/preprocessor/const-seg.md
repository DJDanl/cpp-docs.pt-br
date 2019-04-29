---
title: const_seg
ms.date: 09/17/2018
f1_keywords:
- vc-pragma.const_seg
- const_seg_CPP
helpviewer_keywords:
- pragmas, const_seg
- const_seg pragma
ms.assetid: 1eb58ee2-fb0e-4a39-9621-699c8f5ef957
ms.openlocfilehash: c58f154f5e1ab6906b45d59f454a7dc2b5c0bfbe
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62366583"
---
# <a name="constseg"></a>const_seg
Especifica o segmento em que [const](../cpp/const-cpp.md) as variáveis são armazenadas no arquivo. obj.

## <a name="syntax"></a>Sintaxe

```
#pragma const_seg ( [ [ { push | pop}, ] [ identifier, ] ] [ "segment-name" [, "segment-class" ] )
```

### <a name="parameters"></a>Parâmetros

**push**<br/>
(Opcional) Coloca um registro na pilha interna do compilador. Um **push** pode ter um *identificador* e *nome do segmento*.

**pop**<br/>
(Opcional) Remove um registro do topo da pilha interna do compilador.

*identifier*<br/>
(Opcional) Quando usado com **push**, atribui um nome ao registro na pilha interna do compilador. Quando usado com **pop-up**, elimina registros da pilha interna até *identificador* for removido; se *identificador* não for localizado na pilha interna, nada será exibido.

Usando o *identificador* habilita vários registros a serem exibidos com uma única **pop-up** comando.

"*segment-name*"<br/>
(Opcional) O nome de um segmento. Quando usado com **pop-up**, a pilha é exibida e *nome do segmento* se torna o nome do segmento ativo.

"*segment-class*"<br/>
(Opcional) Incluído para compatibilidade com o C++ antes da versão 2.0. É ignorado.

## <a name="remarks"></a>Comentários

O significado dos termos *segmento* e *seção* são usados alternadamente neste tópico.

Arquivos OBJ podem ser exibidos com o [dumpbin](../build/reference/dumpbin-command-line.md) aplicativo. O segmento padrão no arquivo. obj para `const` variáveis é. RDATA. Alguns `const` variáveis, como escalares, são embutidas automaticamente no fluxo de código. O código embutido não aparecerá em .rdata.

Definindo um objeto que exigem a inicialização dinâmica em um `const_seg` resulta em um comportamento indefinido.

`#pragma const_seg` sem parâmetros redefine o segmento como. RDATA.

## <a name="example"></a>Exemplo

```cpp
// pragma_directive_const_seg.cpp
// compile with: /EHsc
#include <iostream>

const int i = 7;               // inlined, not stored in .rdata
const char sz1[]= "test1";     // stored in .rdata

#pragma const_seg(".my_data1")
const char sz2[]= "test2";     // stored in .my_data1

#pragma const_seg(push, stack1, ".my_data2")
const char sz3[]= "test3";     // stored in .my_data2

#pragma const_seg(pop, stack1) // pop stack1 from stack
const char sz4[]= "test4";     // stored in .my_data1

int main() {
    using namespace std;
   // const data must be referenced to be put in .obj
   cout << sz1 << endl;
   cout << sz2 << endl;
   cout << sz3 << endl;
   cout << sz4 << endl;
}
```

```Output
test1
test2
test3
test4
```

## <a name="comments"></a>Comentários

Ver [/seção](../build/reference/section-specify-section-attributes.md) para obter uma lista de nomes que você não deve usar ao criar uma seção.

Você também pode especificar seções para dados inicializados ([data_seg](../preprocessor/data-seg.md)), dados não inicializados ([bss_seg](../preprocessor/bss-seg.md)) e funções ([code_seg](../preprocessor/code-seg.md)).

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)