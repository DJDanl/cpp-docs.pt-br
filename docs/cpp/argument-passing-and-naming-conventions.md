---
title: Passagem de argumento e convenções de nomenclatura | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- argument passing [C++], conventions
- arguments [C++], widening
- coding conventions, arguments
- arguments [C++], passing
- registers, return values
- thiscall keyword [C++]
- naming conventions [C++], arguments
- arguments [C++], naming
- passing arguments [C++], conventions
- conventions [C++], argument names
ms.assetid: de468979-eab8-4158-90c5-c198932f93b9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 43aa3430b641f6333c6c35d618f9e9de123b7390
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32413480"
---
# <a name="argument-passing-and-naming-conventions"></a>Passagem de argumento e convenções de nomenclatura
**Seção específica da Microsoft**  
  
 Os compiladores do Visual C++ permitem que você especifique convenções para passar argumentos e retornar valores entre funções e chamadores. Nem todas as convenções estão disponíveis em todas as plataformas com suporte. Além disso, algumas convenções usam implementações específicas para a plataforma. Na maioria dos casos, as palavras-chave ou opções de compilador que especificam uma convenção sem suporte em uma plataforma específica são ignoradas e a convenção padrão de plataforma é usada.  
  
 Nas plataformas x86, todos os argumentos são ampliados para 32 bits quando passados. Os valores de retorno também são ampliados para 32 bits e retornados no registro de EAX, com exceção das estruturas de 8 bytes, que são retornadas no par de registro EDX:EAX. Estruturas maiores são retornadas no registro de EAX como ponteiros para estruturas de retorno ocultas. Os parâmetros são empurrados para a pilha da direita para a esquerda. As estruturas que não forem PODs não serão retornadas em registros.  
  
 O compilador gera códigos de prólogo e de epílogo para salvar e restaurar os registros de ESI, EDI, EBX e EBP, se eles forem usados na função.  
  
> [!NOTE]
>  Quando um estrutura, união ou classe é retornada de uma função pelo valor, todas as definições de tipo precisam ser iguais, caso contrário, o programa poderá falhar no tempo de execução.  
  
 Para obter informações sobre como definir seu próprio código de prólogo e epílogo de função, consulte [chamadas de função Naked](../cpp/naked-function-calls.md).  
  
 Para obter informações sobre o padrão de convenções de chamada no código que plataformas de destino x64, consulte [visão geral do x64 convenções de chamada](../build/overview-of-x64-calling-conventions.md). Para obter informações sobre problemas de convenção de chamada no código que tem como alvo plataformas ARM, consulte [Visual C++ ARM migração problemas](../build/common-visual-cpp-arm-migration-issues.md).  
  
 As seguintes convenções de chamada são suportadas pelo compilador visual do C/C++.  
  
|Palavra-chave|Limpeza da pilha|Passagem de parâmetro|  
|-------------|-------------------|-----------------------|  
|[__cdecl](../cpp/cdecl.md)|Chamador|Empurra parâmetros para a pilha, em ordem inversa (direita para a esquerda)|  
|[__clrcall](../cpp/clrcall.md)|N/D|Carrega parâmetros na pilha de expressões CLR em ordem (da esquerda para a direita).|  
|[__stdcall](../cpp/stdcall.md)|Receptor|Empurra parâmetros para a pilha, em ordem inversa (direita para a esquerda)|  
|[__fastcall](../cpp/fastcall.md)|Receptor|Armazenado em registros, em seguida, empurrado para a pilha|  
|[__thiscall](../cpp/thiscall.md)|Receptor|Enviado por push na pilha; **isso** ponteiro armazenado em ECX|  
|[__vectorcall](../cpp/vectorcall.md)|Receptor|Armazenado em registros e depois empurrado na pilha na ordem inversa (da direita para a esquerda)|  
  
 Para obter informações relacionadas, consulte [obsoletos convenções de chamada](../cpp/obsolete-calling-conventions.md).  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Convenções de chamada](../cpp/calling-conventions.md)