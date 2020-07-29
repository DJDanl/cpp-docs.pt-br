---
title: Pragma const_seg
ms.date: 08/29/2019
f1_keywords:
- vc-pragma.const_seg
- const_seg_CPP
helpviewer_keywords:
- pragmas, const_seg
- const_seg pragma
ms.assetid: 1eb58ee2-fb0e-4a39-9621-699c8f5ef957
ms.openlocfilehash: 04467df1205bd6d4c70687422572aef898d46f68
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231618"
---
# <a name="const_seg-pragma"></a>Pragma const_seg

Especifica a seção (segmento) em que as variáveis [const](../cpp/const-cpp.md) são armazenadas no arquivo de objeto (. obj).

## <a name="syntax"></a>Sintaxe

> **#pragma const_seg (** ["*nome da seção*" [ **,** "*seção-classe*"]] **)**\
> **#pragma const_seg (** { **Push**  |  **pop** } [ **,** *Identifier* ] [ **,** "*nome da seção*" [ **,** "*seção-Class*"]] **)**

### <a name="parameters"></a>parâmetros

**pressionado**\
Adicional Coloca um registro na pilha interna do compilador. Um **Push** pode ter um *identificador* e um *nome de seção*.

**pop**\
Adicional Remove um registro da parte superior da pilha interna do compilador. Um **pop** pode ter um *identificador* e um *nome de seção*. Você pode exibir vários registros usando apenas um comando **pop** usando o *identificador*. O *nome da seção* se torna o nome da seção const ativa após o pop.

*ID*\
Adicional Quando usado com **Push**, o atribui um nome ao registro na pilha do compilador interno. Quando usado com **pop**, a diretiva exibe registros fora da pilha interna até que o *identificador* seja removido. Se o *identificador* não for encontrado na pilha interna, nada será exibido.

"*nome da seção*" \
Adicional O nome de uma seção. Quando usado com **pop**, a pilha é exibida e o *nome da seção* se torna o nome da seção const ativa.

"*classe-de-seção*" \
Adicional Ignorado, mas incluído para compatibilidade com versões do Microsoft C++ anteriores à versão 2,0.

## <a name="remarks"></a>Comentários

Uma *seção* em um arquivo de objeto é um bloco nomeado de dados que é carregado na memória como uma unidade. Uma *seção const* é uma seção que contém dados constantes. Neste artigo, os termos de *segmento* e *seção* têm o mesmo significado.

A diretiva **const_seg** pragma informa ao compilador para colocar todos os itens de dados constantes da unidade de tradução em uma seção const denominada *Section-Name*. A seção padrão no arquivo de objeto para **`const`** variáveis é `.rdata` . Algumas **`const`** variáveis, como escalares, são automaticamente embutidas no fluxo de código. O código embutido não aparece em `.rdata` . Uma diretiva de pragma **const_seg** sem um parâmetro *de nome de seção* redefine o nome da seção para os itens de dados subsequentes **`const`** para `.rdata` .

Se você definir um objeto que requer inicialização dinâmica em um `const_seg` , o resultado será um comportamento indefinido.

Para obter uma lista de nomes que não devem ser usados para criar uma seção, consulte [/Section](../build/reference/section-specify-section-attributes.md).

Você também pode especificar seções para dados inicializados ([data_seg](../preprocessor/data-seg.md)), dados não inicializados ([bss_seg](../preprocessor/bss-seg.md)) e funções ([code_seg](../preprocessor/code-seg.md)).

Você pode usar o aplicativo [DUMPBIN.EXE](../build/reference/dumpbin-command-line.md) para exibir arquivos de objeto. As versões do DUMPBIN para cada arquitetura de destino com suporte estão incluídas no Visual Studio.

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

## <a name="see-also"></a>Confira também

[Diretivas Pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
