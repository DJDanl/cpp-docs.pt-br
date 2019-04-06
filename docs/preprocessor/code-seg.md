---
title: code_seg
ms.date: 11/04/2016
f1_keywords:
- code_seg_CPP
- vc-pragma.code_seg
helpviewer_keywords:
- pragmas, code_seg
- code_seg pragma
ms.assetid: bf4faac1-a511-46a6-8d9e-456851d97d56
ms.openlocfilehash: e566fb01bf70b343b75254a10466bdda2bc7ce1b
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59041235"
---
# <a name="codeseg"></a>code_seg
Especifica o segmento de texto onde as funções são armazenadas no arquivo .obj.

## <a name="syntax"></a>Sintaxe

```
#pragma code_seg( [ [ { push | pop }, ] [ identifier, ] ] [ "segment-name" [, "segment-class" ] )
```

### <a name="parameters"></a>Parâmetros

**push**<br/>
(Opcional) Coloca um registro na pilha interna do compilador. Um **push** pode ter um *identificador* e *nome do segmento*.

**pop**<br/>
(Opcional) Remove um registro do topo da pilha interna do compilador.

*identifier*<br/>
(Opcional) Quando usado com **push**, atribui um nome ao registro na pilha interna do compilador. Quando usado com **pop-up**, elimina registros da pilha interna até *identificador* for removido; se *identificador* não for localizado na pilha interna, nada será exibido.

*identificador* habilita vários registros a serem exibidos com apenas um **pop-up** comando.

"*segment-name*"<br/>
(Opcional) O nome de um segmento. Quando usado com **pop-up**, a pilha é exibida e *nome do segmento* se torna o nome de segmento de texto ativo.

"*segment-class*"<br/>
(Opcional) Ignorado, mas incluído para compatibilidade com versões anteriores à versão 2.0 do C++.

## <a name="remarks"></a>Comentários

O **code_seg** diretiva de pragma não controla o posicionamento do código de objeto gerado por modelos instanciados, nem o código gerado implicitamente pelo compilador — por exemplo, as funções de membro especial. É recomendável que você use o [__declspec(code_seg(...)) ](../cpp/code-seg-declspec.md) de atributo em vez disso, porque isso lhe dá controle sobre o posicionamento de todo o código de objeto. Isso inclui o código gerado pelo compilador.

Um *segmento* em um. obj arquivo é um bloco nomeado de dados que são carregados na memória como uma unidade. Um *segmento de texto* é um segmento que contém o código executável. Neste artigo, os termos *segmento* e *seção* são intercambiáveis.

O **code_seg** diretiva de pragma informa ao compilador para colocar todo o código de objeto subsequentes da unidade de tradução em um segmento de texto denominado *nome do segmento*. Por padrão, o segmento de texto usado para funções em um arquivo .obj é denominado .text.

Um **code_seg** diretiva de pragma sem parâmetros redefine o nome do segmento de texto para o código de objeto subsequente para. Text.

Você pode usar o [(DUMPBIN). EXE](../build/reference/dumpbin-command-line.md) aplicativo para exibir os arquivos. obj. As versões de DUMPBIN para cada arquitetura de destino com suporte são incluídas com o Visual Studio.

## <a name="example"></a>Exemplo

Este exemplo mostra como usar o **code_seg** diretiva de pragma para controlar onde o código de objeto é colocado:

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

Para obter uma lista de nomes que não deve ser usado para criar uma seção, consulte [/seção](../build/reference/section-specify-section-attributes.md).

Você também pode especificar seções para dados inicializados ([data_seg](../preprocessor/data-seg.md)), dados não inicializados ([bss_seg](../preprocessor/bss-seg.md)) e variáveis constantes ([const_seg](../preprocessor/const-seg.md)).

## <a name="see-also"></a>Consulte também

[code_seg (__declspec)](../cpp/code-seg-declspec.md)<br/>
[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)