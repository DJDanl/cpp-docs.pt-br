---
title: Visão geral do x64 convenções de chamada | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: a05db5eb-0844-4d9d-8b92-b1b2434be0ea
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: eb4071cd3223ad2ab073f84418e641b515c05112
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="overview-of-x64-calling-conventions"></a>Visão geral de convenções de chamada de x64
Duas diferenças importantes entre x86 e [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)] são a capacidade de endereçamento de 64 bits e registra um conjunto simples de 16 64 bits para uso geral. Fornecido expandidos registrar conjunto, [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)] usa o [fastcall](../cpp/fastcall.md) chamando convenção e um modelo de tratamento de exceção com RISC. O `__fastcall` convenção usa registros para os quatro primeiros argumentos e o quadro de pilha para passar argumentos adicionais.  
  
 A seguinte opção de compilador ajuda a otimizar seu aplicativo para [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]:  
  
-   [/favor (otimizar para especificações da arquitetura)](../build/reference/favor-optimize-for-architecture-specifics.md)  
  
## <a name="calling-convention"></a>Convenção de chamada  
 O [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)] Interface binária do aplicativo (ABI) usa uma convenção de chamada de quatro registro fast chamada por padrão. Espaço é alocado na pilha de chamadas como um armazenamento de sombra para chamados salvar esses registros. Há uma correspondência estrita entre os argumentos para uma chamada de função e os registros usados para esses argumentos. Um argumento que não se encaixa em 8 bytes, ou não é 1, 2, 4 ou 8 bytes, deve ser transmitido por referência. Não há nenhuma tentativa para distribuir um único argumento entre vários registros. O x87 pilha de registro é usada. Ele pode ser usado pelo receptor, mas deve ser considerado volátil em chamadas de função. Ponto flutuante de todas as operações são feitas usando a 16 XMM registra. Argumentos inteiros são passados em registros RCX, RDX, R8 e R9. Argumentos são passados em XMM0L, XMM1L, XMM2L e XMM3L de ponto flutuante. argumentos de 16 bytes são passados por referência. Passagem de parâmetro é descrito detalhadamente no [parâmetro passando](../build/parameter-passing.md). Além desses registros RAX R10, R11, XMM4 e XMM5 são considerados voláteis. Todos os outros registros não são voláteis. Uso de registro está documentado em detalhes em [registrar o uso do](../build/register-usage.md) e [chamador/receptor salvo registra](../build/caller-callee-saved-registers.md).  
  
 O chamador é responsável pela alocação de espaço para os parâmetros para o receptor e sempre deve alocar espaço suficiente para armazenar os quatro parâmetros de registro, mesmo que o chamador não tem muitos parâmetros. Isso simplifica o suporte para funções da linguagem C sem protótipo e funções de C/C++ vararg. Para funções vararg ou unprototyped, qualquer ponto flutuante valores deve ser duplicado no registro correspondente para fins gerais. Quaisquer parâmetros além os quatro primeiros devem ser armazenados na pilha, acima o armazenamento de sombra para os quatro primeiros, antes da chamada. Detalhes da função vararg podem ser encontradas em [Varargs](../build/varargs.md). Informações de função sem protótipo são detalhadas na [funções sem protótipo](../build/unprototyped-functions.md).  
  
## <a name="alignment"></a>Alinhamento  
 A maioria das estruturas são alinhadas com o alinhamento natural. As principais exceções são o ponteiro de pilha e `malloc` ou `alloca` memória, que são alinhados com 16 bytes para ajudar o desempenho. Alinhamento acima de 16 bytes deve ser feito manualmente, mas como 16 bytes é um tamanho comum de alinhamento para operações de XMM, isso deve funcionar para grande parte do código. Para obter mais informações sobre o layout da estrutura e o alinhamento, consulte [tipos e armazenamento](../build/types-and-storage.md). Para obter informações sobre o layout de pilha, consulte [uso da pilha](../build/stack-usage.md).  
  
## <a name="unwindability"></a>Unwindability  
 Funções de folha são funções que não mudam de quaisquer registros não volátil. Uma função de folha não pode alterar RSP não volátil, por exemplo, chamando uma função ou a alocação de espaço de pilha adicionais para variáveis locais. Para recuperar os registros não volátil quando uma exceção é manipulada, funções de não-folha devem ser anotadas com dados estáticos que descreve como corretamente desenrolar a função em uma instrução arbitrária. Esses dados são armazenados como *pdata*, ou dados de procedimento, que por sua vez se refere a *xdata*, dados de manipulação de exceções. O xdata contém as informações de liberação e pode apontar para pdata adicional ou uma função de manipulador de exceção. Prólogos e epilogs são altamente restrita para que eles possam ser corretamente descritos xdata. O ponteiro de pilha deve ser alinhado a 16 bytes em qualquer região de código que não faz parte de um epílogo ou prólogo, exceto nas funções de folha. Funções de folha podem ser retornou simplesmente simulando um retorno, portanto, pdata e xdata não são necessários. Para obter detalhes sobre a estrutura apropriada de Prólogos de função e epilogs, consulte [prólogo e epílogo](../build/prolog-and-epilog.md). Para obter mais informações sobre o tratamento de exceção e a manipuladores de exceção e liberação de pdata e xdata, consulte [(x64) de tratamento de exceção](../build/exception-handling-x64.md).  
  
## <a name="see-also"></a>Consulte também  
 [Convenções de software x64](../build/x64-software-conventions.md)