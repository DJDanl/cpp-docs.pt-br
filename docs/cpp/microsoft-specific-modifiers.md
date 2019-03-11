---
title: Modificadores específicos da Microsoft
ms.date: 08/16/2018
ms.assetid: 22c7178c-f854-47fa-9de6-07d23fda58e1
ms.openlocfilehash: 119e4d06d0235bbf637eefe8754668d3e90b0c52
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57749718"
---
# <a name="microsoft-specific-modifiers"></a>Modificadores específicos da Microsoft

Esta seção descreve extensões específicas da Microsoft para C++ nas seguintes áreas:

- [Endereçamento com base em](based-addressing.md), a prática de usar um ponteiro como base da qual outros ponteiros podem ser deslocados

- [Convenções de chamada de função](calling-conventions.md)

- Estendida de atributos de classe de armazenamento declarados com o [declspec](declspec.md) palavra-chave

- O [__w64](w64.md) palavra-chave

## <a name="microsoft-specific-keywords"></a>Palavras-chave específicas da Microsoft

Várias das palavras-chave específicas da Microsoft podem ser usadas para modificar declaradores para formar tipos derivados. Para obter mais informações sobre declaradores, consulte [declaradores](overview-of-declarators.md).

|Palavra-chave|Significado|Usada para formar tipos derivados?|
|-------------|-------------|---------------------------------|
|[__based](based-grammar.md)|O nome que segue declara um deslocamento de 32 bits para a base de 32 bits contida na declaração.|Sim|
|[__cdecl](cdecl.md)|O nome que segue usa as convenções de nomenclatura e chamada do C.|Sim|
|[__declspec](declspec.md)|O nome que segue especifica um atributo de classe de armazenamento específico da Microsoft.|Não|
|[__fastcall](fastcall.md)|O nome que segue declara uma função que usa registros, quando disponíveis, em vez da pilha para passar argumentos.|Sim|
|[__restrict](extension-restrict.md)|Semelhante a declspec ([restringir](restrict.md)), mas para uso em variáveis.|Não|
|[__stdcall](stdcall.md)|O nome que se segue especifica uma função que observa a convenção padrão de chamada.|Sim|
|[__w64](w64.md)|Marca um tipo de dados como sendo maior em um compilador de 64 bits.|Não|
|[__unaligned](unaligned.md)|Especifica que um ponteiro para um tipo ou outros dados não está alinhado.|Não|
|[__vectorcall](vectorcall.md)|O nome que segue declara uma função que usa registros, incluindo registros SSE, quando disponíveis, em vez da pilha para passar argumentos.|Sim|

## <a name="see-also"></a>Consulte também

[Referência da linguagem C++](cpp-language-reference.md)
