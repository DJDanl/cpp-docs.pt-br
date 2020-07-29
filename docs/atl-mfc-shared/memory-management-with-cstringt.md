---
title: Gerenciamento de memória com CStringT
ms.date: 11/04/2016
helpviewer_keywords:
- CString objects, memory management
- memory [C++], usage
- IAtlStringMgr class, using
- strings [C++], custom memory management
- CFixedStringT class, description of
- strings [C++], memory management
- CStringT class, memory management
ms.assetid: 88b8342d-19b5-48c4-9cf6-e4c44cece21e
ms.openlocfilehash: bf1f99b92761c84d59b6f7bfb9aef67d7e097893
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222024"
---
# <a name="memory-management-with-cstringt"></a>Gerenciamento de memória com CStringT

A classe [CStringT](../atl-mfc-shared/reference/cstringt-class.md) é uma classe de modelo usada para manipular cadeias de caracteres de comprimento variável. A memória para armazenar essas cadeias de caracteres é alocada e liberada por meio de um objeto do Gerenciador de cadeia de caracteres associado a cada instância do `CStringT` . MFC e ATL fornecem instanciações padrão de `CStringT` , chamado `CString` , `CStringA` e `CStringW` , que manipulam cadeias de caracteres de tipos de caractere diferentes. Esses tipos de caracteres são do tipo TCHAR, **`char`** e **`wchar_t`** , respectivamente. Esses tipos de cadeia de caracteres padrão usam um Gerenciador de cadeia de caracteres que aloca memória do heap de processo (na ATL) ou o heap de CRT (no MFC). Para aplicativos típicos, esse esquema de alocação de memória é suficiente. No entanto, para o código que faz uso intensivo de cadeias de caracteres (ou código multi-threaded), os gerenciadores de memória padrão podem não ser executados de forma ideal. Este tópico descreve como substituir o comportamento de gerenciamento de memória padrão do `CStringT` , criando alocadores especificamente otimizados para a tarefa em questão.

- [Implementação de um Gerenciador de cadeia de caracteres personalizado (método básico)](../atl-mfc-shared/implementation-of-a-custom-string-manager-basic-method.md)

- [Impedimento de contenção de heap](../atl-mfc-shared/avoidance-of-heap-contention.md)

- [Implementação de um Gerenciador de cadeia de caracteres personalizado (método avançado)](../atl-mfc-shared/implementation-of-a-custom-string-manager-advanced-method.md)

- [CFixedStringT: um exemplo de um Gerenciador de cadeia de caracteres personalizado](../atl-mfc-shared/cfixedstringt-example-of-a-custom-string-manager.md)

## <a name="see-also"></a>Confira também

[Exemplo de CustomString](../overview/visual-cpp-samples.md)
