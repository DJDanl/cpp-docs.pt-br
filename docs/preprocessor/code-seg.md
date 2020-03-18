---
title: code_seg (pragma)
ms.date: 08/29/2019
f1_keywords:
- vc-pragma.code_seg
helpviewer_keywords:
- pragmas, code_seg
- code_seg pragma
ms.assetid: bf4faac1-a511-46a6-8d9e-456851d97d56
ms.openlocfilehash: 65d702273593dc7fba68cc040f700b01a2c5e4a7
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446484"
---
# <a name="code_seg-pragma"></a>code_seg (pragma)

Especifica a seção de texto (segmento) em que as funções são armazenadas no arquivo de objeto (. obj).

## <a name="syntax"></a>Sintaxe

> **#pragma code_seg (** ["*nome da seção*" [ **,** "*seção-classe*"]] **)** \
> **#pragma code_seg (** { **Push** | **pop** } [ **,** *identificador* ] [ **,** "*nome da seção*" [ **,** "*classe-de-seção*"]] **)**

### <a name="parameters"></a>Parâmetros

\ **Push**
Adicional Coloca um registro na pilha interna do compilador. Um **Push** pode ter um *identificador* e um *nome de seção*.

\ **pop**
Adicional Remove um registro da parte superior da pilha interna do compilador. Um **pop** pode ter um *identificador* e um *nome de seção*. Você pode exibir vários registros usando apenas um comando **pop** usando o *identificador*. O *nome da seção* torna-se o nome da seção de texto ativo após o pop.

*identificador*\
Adicional Quando usado com **Push**, o atribui um nome ao registro na pilha do compilador interno. Quando usado com **pop**, a diretiva exibe registros fora da pilha interna até que o *identificador* seja removido. Se o *identificador* não for encontrado na pilha interna, nada será exibido.

"*nome da seção*" \
Adicional O nome de uma seção. Quando usado com **pop**, a pilha é exibida e o *nome da seção* se torna o nome da seção de texto ativo.

"*classe-de-seção*" \
Adicional Ignorado, mas incluído para compatibilidade com versões do Microsoft C++ anteriores à versão 2,0.

## <a name="remarks"></a>Comentários

Uma *seção* em um arquivo de objeto é um bloco nomeado de dados que é carregado na memória como uma unidade. Uma *seção de texto* é uma seção que contém código executável. Neste artigo, os termos de *segmento* e *seção* têm o mesmo significado.

A diretiva **code_seg** pragma informa ao compilador para colocar todo o código do objeto subsequente da unidade de tradução em uma seção de texto denominada *Section-Name*. Por padrão, a seção de texto usada para funções em um arquivo de objeto é denominada `.text`. Uma diretiva de pragma **code_seg** sem um parâmetro *de nome de seção* redefine o nome da seção de texto para o código do objeto subsequente como `.text`.

A diretiva de pragma **code_seg** não controla o posicionamento do código de objeto gerado para modelos instanciados. Nem o código de controle gerado implicitamente pelo compilador, como funções de membro especiais. Para controlar esse código, recomendamos que você use o atributo [__declspec (code_seg (...))](../cpp/code-seg-declspec.md) . Ele oferece controle sobre o posicionamento de todo o código do objeto, incluindo o código gerado pelo compilador.

Para obter uma lista de nomes que não devem ser usados para criar uma seção, consulte [/Section](../build/reference/section-specify-section-attributes.md).

Você também pode especificar seções para dados inicializados ([data_seg](../preprocessor/data-seg.md)), dados não inicializados ([bss_seg](../preprocessor/bss-seg.md)) e variáveis const ([const_seg](../preprocessor/const-seg.md)).

Você pode usar o [DUMPBIN. Aplicativo EXE](../build/reference/dumpbin-command-line.md) para exibir arquivos de objeto. As versões do DUMPBIN para cada arquitetura de destino com suporte estão incluídas no Visual Studio.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

Este exemplo mostra como usar a diretiva **code_seg** pragma para controlar onde o código do objeto é colocado:

```cpp
// pragma_directive_code_seg.cpp
void func1() {                  // stored in .text
}

#pragma code_seg(".my_data1")
void func2() {                  // stored in my_data1
}

#pragma code_seg(push, r1, ".my_data2")
void func3() {                  // stored in my_data2
}

#pragma code_seg(pop, r1)      // stored in my_data1
void func4() {
}

int main() {
}
```

## <a name="see-also"></a>Consulte também

[code_seg (__declspec)](../cpp/code-seg-declspec.md)\
[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
