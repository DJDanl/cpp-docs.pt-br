---
title: Modificadores específicos da Microsoft | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 22c7178c-f854-47fa-9de6-07d23fda58e1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8490a50f30d366a53a9e3288417a8d83032c556d
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32420217"
---
# <a name="microsoft-specific-modifiers"></a>Modificadores específicos da Microsoft
Esta seção descreve extensões específicas da Microsoft para C++ nas seguintes áreas:  
  
-   [Abordando com base em](../cpp/based-addressing.md), a prática de usar um ponteiro como uma base do qual outros ponteiros podem ser deslocados  
  
-   [Convenções de chamada de função](../cpp/calling-conventions.md)  
  
-   Atributos de classe de armazenamento declarados com estendidos a [declspec](../cpp/declspec.md) palavra-chave  
  
-   O [w64](../cpp/w64.md) palavra-chave  
  
 Várias das palavras-chave específicas da Microsoft podem ser usadas para modificar declaradores para formar tipos derivados. Para obter mais informações sobre declaradores, consulte [declaradores](http://msdn.microsoft.com/en-us/8a7b9b51-92bd-4ac0-b3fe-0c4abe771838).  
  
### <a name="microsoft-specific-keywords"></a>Palavras-chave específicas da Microsoft  
  
|Palavra-chave|Significado|Usada para formar tipos derivados?|  
|-------------|-------------|---------------------------------|  
|[__based](../cpp/based-grammar.md)|O nome que segue declara um deslocamento de 32 bits para a base de 32 bits contida na declaração.|Sim|  
|[__cdecl](../cpp/cdecl.md)|O nome que segue usa as convenções de nomenclatura e chamada do C.|Sim|  
|[__declspec](../cpp/declspec.md)|O nome que segue especifica um atributo de classe de armazenamento específico da Microsoft.|Não|  
|[__fastcall](../cpp/fastcall.md)|O nome que segue declara uma função que usa registros, quando disponíveis, em vez da pilha para passar argumentos.|Sim|  
|[__restrict](../cpp/extension-restrict.md)|Semelhante a declspec ([restringir](../cpp/restrict.md)), mas para uso em variáveis.|Não|  
|[__stdcall](../cpp/stdcall.md)|O nome que se segue especifica uma função que observa a convenção padrão de chamada.|Sim|  
|[__w64](../cpp/w64.md)|Marca um tipo de dados como sendo maior em um compilador de 64 bits.|Não|  
|[__unaligned](../cpp/unaligned.md)|Especifica que um ponteiro para um tipo ou outros dados não está alinhado.|Não|  
|[__vectorcall](../cpp/vectorcall.md)|O nome que segue declara uma função que usa registros, incluindo registros SSE, quando disponíveis, em vez da pilha para passar argumentos.|Sim|  
  
## <a name="see-also"></a>Consulte também  
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)