---
title: Gerenciamento de memória com CStringT
ms.date: 11/04/2016
f1_keywords:
- CStringT
- ATL::CStringT
- ATL.CStringT
helpviewer_keywords:
- CString objects, memory management
- memory [C++], usage
- IAtlStringMgr class, using
- strings [C++], custom memory management
- CFixedStringT class, description of
- strings [C++], memory management
- CStringT class, memory management
ms.assetid: 88b8342d-19b5-48c4-9cf6-e4c44cece21e
ms.openlocfilehash: 8f83b088becf97ca3d8779a537e42369b4a8c832
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62235192"
---
# <a name="memory-management-with-cstringt"></a>Gerenciamento de memória com CStringT

Classe [CStringT](../atl-mfc-shared/reference/cstringt-class.md) é uma classe de modelo usada para manipular cadeias de caracteres de comprimento variável. A memória para manter essas cadeias de caracteres é alocada e liberada por meio de um objeto do Gerenciador de cadeia de caracteres, associado a cada instância de `CStringT`. MFC e ATL fornecem instanciações de padrão de `CStringT`, chamado `CString`, `CStringA`, e `CStringW`, que manipulam cadeias de caracteres de diferentes tipos de caracteres. Esses tipos de caractere são do tipo TCHAR, **char**, e `wchar_t`, respectivamente. Esses tipos de cadeia de caracteres padrão usam um Gerenciador de cadeia de caracteres que aloca memória do heap de processo (em ATL) ou o heap de CRT (em MFC). Para aplicativos típicos, esse esquema de alocação de memória é suficiente. No entanto, para fazer com uso intensivo de código use cadeias de caracteres (ou um código multithread) os gerenciadores de memória padrão não podem executar de forma ideal. Este tópico descreve como substituir o comportamento de gerenciamento de memória padrão do `CStringT`, criar alocadores especificamente otimizada para a tarefa em questão.

- [Implementação de um gerenciador de cadeia de caracteres personalizada (método básico)](../atl-mfc-shared/implementation-of-a-custom-string-manager-basic-method.md)

- [Evitar contenção de heap](../atl-mfc-shared/avoidance-of-heap-contention.md)

- [Implementação de um gerenciador de cadeia de caracteres personalizada (método avançado)](../atl-mfc-shared/implementation-of-a-custom-string-manager-advanced-method.md)

- [CFixedStringT: Um exemplo de um Gerenciador de cadeia de caracteres personalizada](../atl-mfc-shared/cfixedstringt-example-of-a-custom-string-manager.md)

## <a name="see-also"></a>Consulte também

[Exemplo de CustomString](../overview/visual-cpp-samples.md)
