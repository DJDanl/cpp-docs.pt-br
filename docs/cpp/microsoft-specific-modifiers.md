---
title: Modificadores específicos da Microsoft
ms.date: 08/16/2018
ms.assetid: 22c7178c-f854-47fa-9de6-07d23fda58e1
ms.openlocfilehash: 2d65c0fe99895949d537ccf4368df2add3ff91ad
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857418"
---
# <a name="microsoft-specific-modifiers"></a>Modificadores específicos da Microsoft

Esta seção descreve extensões específicas da Microsoft para C++ nas seguintes áreas:

- [Com base em endereçamento](based-addressing.md), a prática de usar um ponteiro como uma base da qual outros ponteiros podem ser deslocados

- [Convenções de chamada de função](calling-conventions.md)

- Atributos de classe de armazenamento estendidos declarados com a palavra-chave [__declspec](declspec.md)

- A palavra-chave [__w64](w64.md)

## <a name="microsoft-specific-keywords"></a>palavras-chave específicas da Microsoft

Várias das palavras-chave específicas da Microsoft podem ser usadas para modificar declaradores para formar tipos derivados. Para obter mais informações sobre declaradores, consulte [declaradores](overview-of-declarators.md).

|Palavra-chave|Significado|Usada para formar tipos derivados?|
|-------------|-------------|---------------------------------|
|[__based](based-grammar.md)|O nome que segue declara um deslocamento de 32 bits para a base de 32 bits contida na declaração.|Sim|
|[__cdecl](cdecl.md)|O nome que segue usa as convenções de nomenclatura e chamada do C.|Sim|
|[__declspec](declspec.md)|O nome que segue especifica um atributo de classe de armazenamento específico da Microsoft.|Não|
|[__fastcall](fastcall.md)|O nome que segue declara uma função que usa registros, quando disponíveis, em vez da pilha para passar argumentos.|Sim|
|[__restrict](extension-restrict.md)|Semelhante a __declspec ([restrict](restrict.md)), mas para uso em variáveis.|Não|
|[__stdcall](stdcall.md)|O nome que se segue especifica uma função que observa a convenção padrão de chamada.|Sim|
|[__w64](w64.md)|Marca um tipo de dados como sendo maior em um compilador de 64 bits.|Não|
|[__unaligned](unaligned.md)|Especifica que um ponteiro para um tipo ou outros dados não está alinhado.|Não|
|[__vectorcall](vectorcall.md)|O nome que segue declara uma função que usa registros, incluindo registros SSE, quando disponíveis, em vez da pilha para passar argumentos.|Sim|

## <a name="see-also"></a>Consulte também

[Referência da linguagem C++](cpp-language-reference.md)
