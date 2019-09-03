---
title: data_seg pragma
ms.date: 08/29/2019
f1_keywords:
- data_seg_CPP
- vc-pragma.data_seg
helpviewer_keywords:
- data_seg pragma
- pragmas, data_seg
ms.assetid: 65c66466-4c98-494f-93af-106beb4caf78
ms.openlocfilehash: f67a9f39695adf5067c61288cf09ea7eb481c7dd
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70220387"
---
# <a name="data_seg-pragma"></a>data_seg pragma

Especifica a seção de dados (segmento) em que as variáveis inicializadas são armazenadas no arquivo de objeto (. obj).

## <a name="syntax"></a>Sintaxe

> **#pragma data_seg (** ["*nome da seção*" [ **,** "*seção-classe*"]] **)** \
> **#pragma data_seg (** { **Push** | **pop** } [ **,** *Identifier* ] [ **,** "*nome da seção*" [ **,** "*seção-Class*"]] **)**

### <a name="parameters"></a>Parâmetros

**pressionado**\
Adicional Coloca um registro na pilha interna do compilador. Um **Push** pode ter um *identificador* e um *nome de seção*.

**pop**\
Adicional Remove um registro da parte superior da pilha interna do compilador. Um **pop** pode ter um *identificador* e um *nome de seção*. Você pode exibir vários registros usando apenas um comando **pop** usando o *identificador*. O *nome da seção* torna-se o nome da seção de dados ativos após o pop.

*ID*\
Adicional Quando usado com **Push**, o atribui um nome ao registro na pilha do compilador interno. Quando usado com **pop**, o exibe registros da pilha interna até que o *identificador* seja removido. Se o *identificador* não for encontrado na pilha interna, nada será exibido.

o *identificador* permite que vários registros sejam retirados com um único comando **pop** .

*"nome da seção"* \
Adicional O nome de uma seção. Quando usado com **pop**, a pilha é exibida e o *nome da seção* se torna o nome da seção de dados ativa.

*"classe-de-seção"* \
Adicional Ignorado, mas incluído para compatibilidade com versões do Microsoft C++ anteriores à versão 2,0.

## <a name="remarks"></a>Comentários

Uma *seção* em um arquivo de objeto é um bloco nomeado de dados que é carregado na memória como uma unidade. Uma *seção de dados* é uma seção que contém dados inicializados. Neste artigo, os termos de *segmento* e *seção* têm o mesmo significado.

A seção padrão no arquivo. obj para variáveis inicializadas é `.data`. As variáveis não inicializadas são consideradas como inicializadas como zero e armazenadas em `.bss`.

A diretiva pragma **data_seg** informa ao compilador para colocar todos os itens de dados inicializados da unidade de tradução em uma seção de dados denominada *Section-Name*. Por padrão, a seção de dados usada para dados inicializados em um arquivo de `.data`objeto é denominada. As variáveis não inicializadas são consideradas como inicializadas como zero e são armazenadas em `.bss`. Uma diretiva de pragma **data_seg** sem um parâmetro *de nome de seção* redefine o nome da seção de dados para os itens `.data`de dados inicializados subsequentes para.

Os dados alocados usando **data_seg** não retêm nenhuma informação sobre seu local.

Para obter uma lista de nomes que não devem ser usados para criar uma seção, consulte [/Section](../build/reference/section-specify-section-attributes.md).

Você também pode especificar seções para variáveis const ([const_seg](../preprocessor/const-seg.md)), dados não inicializados ([bss_seg](../preprocessor/bss-seg.md)) e funções ([code_seg](../preprocessor/code-seg.md)).

Você pode usar o [DUMPBIN. Aplicativo EXE](../build/reference/dumpbin-command-line.md) para exibir arquivos de objeto. As versões do DUMPBIN para cada arquitetura de destino com suporte estão incluídas no Visual Studio.

## <a name="example"></a>Exemplo

```cpp
// pragma_directive_data_seg.cpp
int h = 1;                     // stored in .data
int i = 0;                     // stored in .bss
#pragma data_seg(".my_data1")
int j = 1;                     // stored in .my_data1

#pragma data_seg(push, stack1, ".my_data2")
int l = 2;                     // stored in .my_data2

#pragma data_seg(pop, stack1)   // pop stack1 off the stack
int m = 3;                     // stored in .my_data1

int main() {
}
```

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
