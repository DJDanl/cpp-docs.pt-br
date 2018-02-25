---
title: vtordisp | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3cdb90de659dfe0f366d6501bc18c18e0cf39fff
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="vtordisp"></a>vtordisp
**Específicas do C++**  
  
 Controla a adição do membro oculto do deslocamento de construção/destruição vtordisp.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
#pragma vtordisp([push,] n)  
#pragma vtordisp(pop)  
#pragma vtordisp()  
#pragma vtordisp([push,] {on | off})  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `push`  
 Envia a configuração atual de vtordisp na pilha interna do compilador e define a nova configuração de vtordisp em `n`.  Se `n` não for especificado, a configuração atual de vtordisp não será alterada.  
  
 `pop`  
 Remove o registro superior da pilha interna do compilador e restaura a configuração de vtordisp para o valor removido.  
  
 `n`  
 Especifica o novo valor da configuração de vtordisp. Os valores possíveis são 0, 1 ou 2, correspondente às opções do compilador /vd0, /vd1 e /vd2. Para obter mais informações, consulte [/vd (desabilitar deslocamentos de construção)](../build/reference/vd-disable-construction-displacements.md).  
  
 `on`  
 Equivalente a `#pragma vtordisp(1)`.  
  
 `off`  
 Equivalente a `#pragma vtordisp(0)`.  
  
## <a name="remarks"></a>Comentários  
 O pragma `vtordisp` é aplicável somente ao código que usa bases virtuais. Se uma classe derivada substitui uma função virtual que herda de uma classe base virtual e, se um construtor ou um destruidor para a classe base derivada chamar essa função usando um ponteiro para a classe base virtual, o compilador virtual poderá inserir campos `vtordisp` adicionais ocultos nas classes com bases virtuais.  
  
 O pragma `vtordisp` afeta o layout das classes que o seguem. As opções /vd0, /vd1 e /vd2 especificam o mesmo comportamento para os módulos concluídos. Especificar `0` ou `off` elimina os membros `vtordisp` ocultos. Desative `vtordisp` somente se não houver nenhuma possibilidade de os construtores e destruidores da classe chamarem funções virtuais no objeto apontado pelo ponteiro `this`.  
  
 Especificar `1` ou `on`, o padrão, permite que membros `vtordisp` ocultos onde são necessários.  
  
 Especificando `2` permite oculto `vtordisp` membros para todas as bases virtual com funções virtuais.  `vtordisp(2)` pode ser necessário para garantir desempenho correto do `dynamic_cast` em um objeto parcialmente construído. Para obter mais informações, consulte [C4436 de aviso do compilador (nível 1)](../error-messages/compiler-warnings/compiler-warning-level-1-c4436.md).  
  
 `#pragma vtordisp()`, sem argumentos, restaura a configuração de vtordisp como a configuração inicial.  
  
```  
#pragma vtordisp(push, 2)  
class GetReal : virtual public VBase { ... };  
#pragma vtordisp(pop)  
```  
  
 **TÉRMINO específicas do C++**  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)