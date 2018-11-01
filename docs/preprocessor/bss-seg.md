---
title: bss_seg
ms.date: 10/22/2018
f1_keywords:
- vc-pragma.bss_seg
- bss_seg_CPP
helpviewer_keywords:
- pragmas, bss_seg
- bss_seg pragma
ms.assetid: 755f0154-de51-4778-97d3-c9b24e445079
ms.openlocfilehash: 489ced11bb6024fdf9818872c07ab7feebfeabf3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50566303"
---
# <a name="bssseg"></a>bss_seg

Especifica o segmento em que as variáveis não inicializadas são armazenadas no arquivo .obj.

## <a name="syntax"></a>Sintaxe

```
#pragma bss_seg( [ [ { push | pop }, ] [ identifier, ] ] [ "segment-name" [, "segment-class" ] )
```

### <a name="parameters"></a>Parâmetros

**push**<br/>
(Opcional) Coloca um registro na pilha interna do compilador. Um *pu*sh * pode ter um *identificador* e *nome do segmento*.

**pop**<br/>
(Opcional) Remove um registro do topo da pilha interna do compilador.

*identifier*<br/>
(Opcional) Quando usado com **push**, atribui um nome ao registro na pilha interna do compilador. *identificador* habilita vários registros a serem exibidos com uma única **pop-up** comando. Quando usado com **pop-up**, a diretiva elimina registros da pilha interna até *identificador* for removido; se *identificador* não for encontrado na pilha interna, nada é ser exibido.

*"nome do segmento"*<br/>
(Opcional) O nome de um segmento. Quando usado com **pop-up**, a pilha é exibida e *nome do segmento* se torna o nome do segmento ativo.

*"segmento-class"*<br/>
(Opcional) Incluído para compatibilidade com o C++ antes da versão 2.0. É ignorado.

## <a name="remarks"></a>Comentários

. Arquivos obj podem ser exibidos com o [dumpbin](../build/reference/dumpbin-command-line.md) aplicativo. O segmento padrão no arquivo .obj para os dados não inicializados é .bss. Em alguns casos de uso de **bss_seg** pode acelerar tempos de carregamento, agrupando dados não inicializados em uma seção.

**bss_seg** sem parâmetros redefine o segmento BSS.

Dados alocados usando o **bss_seg** pragma não retêm nenhuma informação sobre o respectivo local.

Você também pode especificar seções para dados inicializados ([data_seg](../preprocessor/data-seg.md)), funções ([code_seg](../preprocessor/code-seg.md)) e variáveis constantes ([const_seg](../preprocessor/const-seg.md)).

Ver [/seção](../build/reference/section-specify-section-attributes.md) para obter uma lista de nomes que você não deve usar ao criar uma seção.

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

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
