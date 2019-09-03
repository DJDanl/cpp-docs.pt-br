---
title: bss_seg pragma
ms.date: 08/29/2019
f1_keywords:
- vc-pragma.bss_seg
- bss_seg_CPP
helpviewer_keywords:
- pragmas, bss_seg
- bss_seg pragma
ms.assetid: 755f0154-de51-4778-97d3-c9b24e445079
ms.openlocfilehash: a343fb45b4bbe4789f38b7a1102572cf4241ec53
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70218553"
---
# <a name="bss_seg-pragma"></a>bss_seg pragma

Especifica a seção (segmento) em que as variáveis não inicializadas são armazenadas no arquivo de objeto (. obj).

## <a name="syntax"></a>Sintaxe

> **#pragma bss_seg (** ["*nome da seção*" [ **,** "*seção-classe*"]] **)** \
> **#pragma bss_seg (** { **Push** | **pop** } [ **,** *Identifier* ] [ **,** "*nome da seção*" [ **,** "*seção-Class*"]] **)**

### <a name="parameters"></a>Parâmetros

**pressionado**\
Adicional Coloca um registro na pilha interna do compilador. Um **Push** pode ter um *identificador* e um *nome de seção*.

**pop**\
Adicional Remove um registro da parte superior da pilha interna do compilador. Um **pop** pode ter um *identificador* e um *nome de seção*. Você pode exibir vários registros usando apenas um comando **pop** usando o *identificador*. O *nome da seção* torna-se o nome da seção BSS ativa após o pop.

*ID*\
Adicional Quando usado com **Push**, o atribui um nome ao registro na pilha do compilador interno. Quando usado com **pop**, a diretiva exibe registros fora da pilha interna até que o *identificador* seja removido. Se o *identificador* não for encontrado na pilha interna, nada será exibido.

*"nome da seção"* \
Adicional O nome de uma seção. Quando usado com **pop**, a pilha é exibida e o *nome da seção* se torna o nome da seção BSS ativa.

*"classe-de-seção"* \
Adicional Ignorado, mas incluído para compatibilidade com versões do Microsoft C++ anteriores à versão 2,0.

## <a name="remarks"></a>Comentários

Uma *seção* em um arquivo de objeto é um bloco nomeado de dados que é carregado na memória como uma unidade. Uma *seção de BSS* é uma seção que contém dados não inicializados. Neste artigo, os termos de *segmento* e *seção* têm o mesmo significado.

A diretiva pragma **bss_seg** informa ao compilador para colocar todos os itens de dados não inicializados da unidade de tradução em uma seção de BSS denominada *Section-Name*. Em alguns casos, o uso de **bss_seg** pode acelerar os tempos de carregamento agrupando dados não inicializados em uma única seção. Por padrão, a seção BSS usada para dados não inicializados em um arquivo de objeto é `.bss`denominada. Uma diretiva de pragma **bss_seg** sem um parâmetro *de nome de seção* redefine o nome da seção BSS para os itens de dados não `.bss`inicializados subsequentes para.

Os dados alocados usando o pragma **bss_seg** não retêm nenhuma informação sobre seu local.

Para obter uma lista de nomes que não devem ser usados para criar uma seção, consulte [/Section](../build/reference/section-specify-section-attributes.md).

Você também pode especificar seções para dados inicializados ([data_seg](../preprocessor/data-seg.md)), Functions ([code_seg](../preprocessor/code-seg.md)) e variáveis const ([const_seg](../preprocessor/const-seg.md)).

Você pode usar o [DUMPBIN. Aplicativo EXE](../build/reference/dumpbin-command-line.md) para exibir arquivos de objeto. As versões do DUMPBIN para cada arquitetura de destino com suporte estão incluídas no Visual Studio.

## <a name="example"></a>Exemplo

```cpp
// pragma_directive_bss_seg.cpp
int i;                     // stored in .bss
#pragma bss_seg(".my_data1")
int j;                     // stored in .my_data1

#pragma bss_seg(push, stack1, ".my_data2")
int l;                     // stored in .my_data2

#pragma bss_seg(pop, stack1)   // pop stack1 from stack
int m;                     // stored in .my_data1

int main() {
}
```

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
