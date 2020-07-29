---
title: Pragma vtordisp
ms.date: 08/29/2019
f1_keywords:
- vc-pragma.vtordisp
- vtordisp_CPP
helpviewer_keywords:
- pragmas, vtordisp
- vtordisp pragma
ms.assetid: 05b7d73c-43fa-4b62-8c8a-170a9e427391
ms.openlocfilehash: a6ffc5c0323389d812e659ff68555a8c8c993126
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219359"
---
# <a name="vtordisp-pragma"></a>Pragma vtordisp

**Específico do C++**

Controla a adição do membro de `vtordisp` substituição de construção/destruição oculta.

## <a name="syntax"></a>Sintaxe

> **#pragma vtordisp (** [ **Push,** ] *n* **)**\
> **#pragma vtordisp (pop)**\
> **#pragma vtordisp ()**\
> **#pragma vtordisp (** [ **Push,** ] { **on**  |  **off** } **)**

### <a name="parameters"></a>parâmetros

**pressionado**\
Envia por push a `vtordisp` configuração atual na pilha interna do compilador e define a nova `vtordisp` configuração como *n*.  Se *n* não for especificado, a `vtordisp` configuração atual será inalterada.

**pop**\
Remove o registro superior da pilha interna do compilador e restaura a `vtordisp` configuração para o valor removido.

*p*\
Especifica o novo valor para a `vtordisp` configuração. Os valores possíveis são 0, 1 ou 2, correspondentes às `/vd0` `/vd1` Opções de compilador, e `/vd2` . Para obter mais informações, consulte [/VD (desabilitar as substituições de construção)](../build/reference/vd-disable-construction-displacements.md).

**no**\
Equivalente a `#pragma vtordisp(1)`.

**desconto**\
Equivalente a `#pragma vtordisp(0)`.

## <a name="remarks"></a>Comentários

O pragma **vtordisp** é aplicável somente ao código que usa bases virtuais. Se uma classe derivada substitui uma função virtual que herda de uma classe base virtual e, se um construtor ou um destruidor para a classe base derivada chamar essa função usando um ponteiro para a classe base virtual, o compilador virtual poderá inserir campos `vtordisp` adicionais ocultos nas classes com bases virtuais.

O pragma **vtordisp** afeta o layout das classes que o seguem. As `/vd0` `/vd1` Opções, e `/vd2` especificam o mesmo comportamento para os módulos completos. Especificar 0 ou **off** suprime os membros ocultos `vtordisp` . Desative o **vtordisp** somente se não houver possibilidade de que os construtores e destruidores da classe chamem funções virtuais no objeto apontado pelo **`this`** ponteiro.

Especificar 1 ou **on**, o padrão, habilita os membros ocultos `vtordisp` onde eles são necessários.

Especificar 2 habilita os membros ocultos `vtordisp` para todas as bases virtuais com funções virtuais.  `#pragma vtordisp(2)`pode ser necessário para garantir o desempenho correto de **`dynamic_cast`** um objeto parcialmente construído. Para obter mais informações, consulte [aviso do compilador (nível 1) C4436](../error-messages/compiler-warnings/compiler-warning-level-1-c4436.md).

`#pragma vtordisp()`, sem argumentos, restaura a `vtordisp` configuração para sua configuração inicial.

```cpp
#pragma vtordisp(push, 2)
class GetReal : virtual public VBase { ... };
#pragma vtordisp(pop)
```

**FIM de Específico do C++**

## <a name="see-also"></a>Confira também

[Diretivas Pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
