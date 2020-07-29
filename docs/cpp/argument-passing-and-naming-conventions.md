---
title: Passagem de argumento e convenções de nomenclatura
ms.date: 12/17/2018
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
ms.openlocfilehash: b6b65b4e0cc33ea384eff306952589a49e7ad41a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229227"
---
# <a name="argument-passing-and-naming-conventions"></a>Passagem de argumento e convenções de nomenclatura

**Específico da Microsoft**

Os compiladores do Microsoft C++ permitem que você especifique convenções para passar argumentos e valores de retorno entre funções e chamadores. Nem todas as convenções estão disponíveis em todas as plataformas com suporte. Além disso, algumas convenções usam implementações específicas para a plataforma. Na maioria dos casos, as palavras-chave ou opções de compilador que especificam uma convenção sem suporte em uma plataforma específica são ignoradas e a convenção padrão de plataforma é usada.

Nas plataformas x86, todos os argumentos são ampliados para 32 bits quando passados. Os valores de retorno também são ampliados para 32 bits e retornados no registro de EAX, com exceção das estruturas de 8 bytes, que são retornadas no par de registro EDX:EAX. Estruturas maiores são retornadas no registro de EAX como ponteiros para estruturas de retorno ocultas. Os parâmetros são empurrados para a pilha da direita para a esquerda. As estruturas que não forem PODs não serão retornadas em registros.

O compilador gera códigos de prólogo e de epílogo para salvar e restaurar os registros de ESI, EDI, EBX e EBP, se eles forem usados na função.

> [!NOTE]
> Quando um estrutura, união ou classe é retornada de uma função pelo valor, todas as definições de tipo precisam ser iguais, caso contrário, o programa poderá falhar no runtime.

Para obter informações sobre como definir seu próprio prólogo de função e código epílogo, consulte [chamadas de função Naked](../cpp/naked-function-calls.md).

Para obter informações sobre as convenções de chamada padrão em código direcionado a plataformas x64, consulte [Convenção de chamada x64](../build/x64-calling-convention.md). Para obter informações sobre como chamar problemas de Convenção no código direcionado a plataformas ARM, consulte [problemas comuns de migração do Visual C++ ARM](../build/common-visual-cpp-arm-migration-issues.md).

As seguintes convenções de chamada são suportadas pelo compilador visual do C/C++.

|Palavra-chave|Limpeza da pilha|Passagem de parâmetro|
|-------------|-------------------|-----------------------|
|[__cdecl](../cpp/cdecl.md)|Chamador|Empurra parâmetros para a pilha, em ordem inversa (direita para a esquerda)|
|[__clrcall](../cpp/clrcall.md)|N/D|Carrega parâmetros na pilha de expressões CLR em ordem (da esquerda para a direita).|
|[__stdcall](../cpp/stdcall.md)|Receptor|Empurra parâmetros para a pilha, em ordem inversa (direita para a esquerda)|
|[__fastcall](../cpp/fastcall.md)|Receptor|Armazenado em registros, em seguida, empurrado para a pilha|
|[__thiscall](../cpp/thiscall.md)|Receptor|Enviado por push na pilha; **`this`** ponteiro armazenado no ecx|
|[__vectorcall](../cpp/vectorcall.md)|Receptor|Armazenado em registros e depois empurrado na pilha na ordem inversa (da direita para a esquerda)|

Para obter informações relacionadas, consulte [convenções de chamada obsoletas](../cpp/obsolete-calling-conventions.md).

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Convenções de chamada](../cpp/calling-conventions.md)
