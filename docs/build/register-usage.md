---
title: Registrar uso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: ce58e2cf-afd3-4068-980e-28a209298265
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6792fcf035ee698767c9dd099cb7b84f5b784616
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="register-usage"></a>Uso do Registro
A arquitetura do [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)] sustenta 16 registros de uso geral (a partir de agora chamados de registros de inteiros), bem como para 16 registros XMM/YMM disponíveis para uso de ponto flutuante. Os registros voláteis são registros a partir do zero presumidos pelo chamador para serem destruídos em uma chamada. Os registros não voláteis são obrigados a manter seus valores em uma chamada de função e devem ser salvos pelo receptor da chamada se usados.  
  
 A tabela a seguir descreve como cada registro é usado nas chamadas de função:  
  
||||  
|-|-|-|  
|Registro|Status|Uso|  
|RAX|Volátil|Registro de valores retornados|  
|RCX|Volátil|Primeiro argumento inteiro|  
|RDX|Volátil|Segundo argumento inteiro|  
|R8|Volátil|Terceiro argumento inteiro|  
|R9|Volátil|Quarto argumento inteiro|  
|R10, R11|Volátil|Deve ser preservado, conforme a necessidade do chamador; usado em instruções syscall/sysret|  
|R12, R15|Não volátil|Deve ser preservado pelo receptor da chamada|  
|RDI|Não volátil|Deve ser preservado pelo receptor da chamada|  
|RSI|Não volátil|Deve ser preservado pelo receptor da chamada|  
|RBX|Não volátil|Deve ser preservado pelo receptor da chamada|  
|RBP|Não volátil|Pode ser usado como um ponteiro de quadro; deve ser preservado pelo receptor da chamada|  
|RSP|Não volátil|Ponteiro de pilha|  
|XMM0, YMM0|Volátil|Primeiro argumento FP; primeiro argumento de tipo vetorial quando `__vectorcall` for usado|  
|XMM1, YMM1|Volátil|Segundo argumento FP; segundo argumento de tipo vetorial quando `__vectorcall` for usado|  
|XMM2, YMM2|Volátil|Terceiro argumento FP; terceiro argumento de tipo vetorial quando `__vectorcall` for usado|  
|XMM3, YMM3|Volátil|Quarto argumento FP; quarto argumento de tipo vetorial quando `__vectorcall` for usado|  
|XMM4, YMM4|Volátil|Deve ser preservado conforme necessário pelo chamador; quinto argumento de tipo vetorial quando `__vectorcall` for usado|  
|XMM5, YMM5|Volátil|Deve ser preservado conforme necessário pelo chamador; sexto argumento de tipo vetorial quando `__vectorcall` for usado|  
|XMM6:XMM15, YMM6:YMM15|Não volátil (XMM), Volátil (metade superior de YMM)|Deve ser preservado pelo receptor. Os registros YMM devem ser preservados conforme necessário pelo chamador.|  
  
## <a name="see-also"></a>Consulte também  
 [x64 convenções de software](../build/x64-software-conventions.md)   
 [__vectorcall](../cpp/vectorcall.md)
