---
title: vtordisp | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- vc-pragma.vtordisp
- vtordisp_CPP
dev_langs:
- C++
helpviewer_keywords:
- pragmas, vtordisp
- vtordisp pragma
ms.assetid: 05b7d73c-43fa-4b62-8c8a-170a9e427391
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5d0b28c855ab8a6f6da814ee17521a5ad7799993
ms.sourcegitcommit: d4c803bd3a684d7951bf88dcecf1f14af43ae411
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/10/2018
ms.locfileid: "42538374"
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
*push*  
Envia a configuração atual de vtordisp na pilha interna do compilador e define a nova configuração de vtordisp para *n*.  Se *n* não for especificado, a configuração atual de vtordisp não é alterada.  
  
*pop*  
Remove o registro superior da pilha interna do compilador e restaura a configuração de vtordisp para o valor removido.  
  
*n*  
Especifica o novo valor da configuração de vtordisp. Os valores possíveis são 0, 1 ou 2, correspondente a `/vd0`, `/vd1`, e `/vd2` opções do compilador. Para obter mais informações, consulte [/vd (desabilitar deslocamentos de construção)](../build/reference/vd-disable-construction-displacements.md).  
  
*on*  
Equivalente a `#pragma vtordisp(1)`.  
  
*Desativar*  
Equivalente a `#pragma vtordisp(0)`.  
  
## <a name="remarks"></a>Comentários  
 
O **vtordisp** pragma é aplicável somente ao código que usa bases virtuais. Se uma classe derivada substitui uma função virtual que herda de uma classe base virtual e, se um construtor ou destruidor da classe derivada chamar essa função usando um ponteiro para a classe base virtual, o compilador pode introduzir ocultosadicionais**vtordisp** campos em classes com bases virtuais.  
  
O **vtordisp** pragma afeta o layout das classes que o seguem. O `/vd0`, `/vd1`, e `/vd2` opções especificam o mesmo comportamento para os módulos concluídos. Especificar 0 ou *off* suprime oculto **vtordisp** membros. Desative **vtordisp** somente se não houver nenhuma possibilidade de que os construtores e destruidores da classe chamam virtuais funções no objeto apontado pela **isso** ponteiro.  
  
Especificar 1 ou *na*, o padrão, permite que o oculto **vtordisp** membros que são necessários.  
  
Especificando 2 habilita o oculto **vtordisp** membros para todas as bases virtuais com funções virtuais.  `vtordisp(2)` pode ser necessário para garantir o desempenho correto de **dynamic_cast** em um objeto parcialmente construído. Para obter mais informações, consulte [aviso do compilador (nível 1) C4436](../error-messages/compiler-warnings/compiler-warning-level-1-c4436.md).  
  
`#pragma vtordisp()`, sem argumentos, restaura a configuração de vtordisp como a configuração inicial.  
  
```  
#pragma vtordisp(push, 2)  
class GetReal : virtual public VBase { ... };  
#pragma vtordisp(pop)  
```  
  
**FIM de específico de C++**  
  
## <a name="see-also"></a>Consulte também  
 
[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)