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
ms.openlocfilehash: af042c80b9e3e0de872261f89255a26728b218cd
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79440509"
---
# <a name="memory-management-with-cstringt"></a>Gerenciamento de memória com CStringT

A classe [CStringT](../atl-mfc-shared/reference/cstringt-class.md) é uma classe de modelo usada para manipular cadeias de caracteres de comprimento variável. A memória para armazenar essas cadeias de caracteres é alocada e liberada por meio de um objeto do Gerenciador de cadeia de caracteres associado a cada instância do `CStringT`. MFC e ATL fornecem instanciações padrão de `CStringT`, chamadas `CString`, `CStringA`e `CStringW`, que manipulam cadeias de caracteres de tipos de caractere diferentes. Esses tipos de caracteres são do tipo TCHAR, **Char**e `wchar_t`, respectivamente. Esses tipos de cadeia de caracteres padrão usam um Gerenciador de cadeia de caracteres que aloca memória do heap de processo (na ATL) ou o heap de CRT (no MFC). Para aplicativos típicos, esse esquema de alocação de memória é suficiente. No entanto, para o código que faz uso intensivo de cadeias de caracteres (ou código multi-threaded), os gerenciadores de memória padrão podem não ser executados de forma ideal. Este tópico descreve como substituir o comportamento de gerenciamento de memória padrão de `CStringT`, criando alocadores especificamente otimizados para a tarefa em questão.

- [Implementação de um gerenciador de cadeia de caracteres personalizada (método básico)](../atl-mfc-shared/implementation-of-a-custom-string-manager-basic-method.md)

- [Evitar contenção de heap](../atl-mfc-shared/avoidance-of-heap-contention.md)

- [Implementação de um gerenciador de cadeia de caracteres personalizada (método avançado)](../atl-mfc-shared/implementation-of-a-custom-string-manager-advanced-method.md)

- [CFixedStringT: um exemplo de um Gerenciador de cadeia de caracteres personalizado](../atl-mfc-shared/cfixedstringt-example-of-a-custom-string-manager.md)

## <a name="see-also"></a>Consulte também

[Exemplo de CustomString](../overview/visual-cpp-samples.md)
