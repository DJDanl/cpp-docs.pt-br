---
title: vtordisp
ms.date: 10/18/2018
f1_keywords:
- vc-pragma.vtordisp
- vtordisp_CPP
helpviewer_keywords:
- pragmas, vtordisp
- vtordisp pragma
ms.assetid: 05b7d73c-43fa-4b62-8c8a-170a9e427391
ms.openlocfilehash: 075f00ad8a4071af57014638707503847b58756d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50557177"
---
# <a name="vtordisp"></a>vtordisp

**Específico do C++**

Controla a adição do membro oculto do deslocamento de construção/destruição vtordisp.

## <a name="syntax"></a>Sintaxe

```cpp
#pragma vtordisp([push,] n)
#pragma vtordisp(pop)
#pragma vtordisp()
#pragma vtordisp([push,] {on | off})
```

### <a name="parameters"></a>Parâmetros

*push*<br/>
Envia a configuração atual de vtordisp na pilha interna do compilador e define a nova configuração de vtordisp para *n*.  Se *n* não for especificado, a configuração atual de vtordisp não é alterada.

*pop*<br/>
Remove o registro superior da pilha interna do compilador e restaura a configuração de vtordisp para o valor removido.

*n*<br/>
Especifica o novo valor da configuração de vtordisp. Os valores possíveis são 0, 1 ou 2, correspondente a `/vd0`, `/vd1`, e `/vd2` opções do compilador. Para obter mais informações, consulte [/vd (desabilitar deslocamentos de construção)](../build/reference/vd-disable-construction-displacements.md).

*on*<br/>
Equivalente a `#pragma vtordisp(1)`.

*Desativar*<br/>
Equivalente a `#pragma vtordisp(0)`.

## <a name="remarks"></a>Comentários

O **vtordisp** pragma é aplicável somente ao código que usa bases virtuais. Se uma classe derivada substitui uma função virtual que herda de uma classe base virtual e, se um construtor ou destruidor da classe derivada chamar essa função usando um ponteiro para a classe base virtual, o compilador pode introduzir ocultosadicionais**vtordisp** campos em classes com bases virtuais.

O **vtordisp** pragma afeta o layout das classes que o seguem. O `/vd0`, `/vd1`, e `/vd2` opções especificam o mesmo comportamento para os módulos concluídos. Especificar 0 ou *off* suprime oculto **vtordisp** membros. Desative **vtordisp** somente se não houver nenhuma possibilidade de que os construtores e destruidores da classe chamam virtuais funções no objeto apontado pela **isso** ponteiro.

Especificar 1 ou *na*, o padrão, permite que o oculto **vtordisp** membros que são necessários.

Especificando 2 habilita o oculto **vtordisp** membros para todas as bases virtuais com funções virtuais.  `vtordisp(2)` pode ser necessário para garantir o desempenho correto de **dynamic_cast** em um objeto parcialmente construído. Para obter mais informações, consulte [aviso do compilador (nível 1) C4436](../error-messages/compiler-warnings/compiler-warning-level-1-c4436.md).

`#pragma vtordisp()`, sem argumentos, restaura a configuração de vtordisp como a configuração inicial.

```cpp
#pragma vtordisp(push, 2)
class GetReal : virtual public VBase { ... };
#pragma vtordisp(pop)
```

**FIM de específico de C++**

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)