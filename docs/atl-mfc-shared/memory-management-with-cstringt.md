---
title: Gerenciamento de memória com CStringT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CStringT
- ATL::CStringT
- ATL.CStringT
dev_langs:
- C++
helpviewer_keywords:
- CString objects, memory management
- memory [C++], usage
- IAtlStringMgr class, using
- strings [C++], custom memory management
- CFixedStringT class, description of
- strings [C++], memory management
- CStringT class, memory management
ms.assetid: 88b8342d-19b5-48c4-9cf6-e4c44cece21e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b65efd934fecdab36bfa1c0c882de1dd8862c81f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="memory-management-with-cstringt"></a>Gerenciamento de memória com CStringT
Classe [CStringT](../atl-mfc-shared/reference/cstringt-class.md) é uma classe de modelo usada para manipular cadeias de caracteres de comprimento variável. A memória para manter essas cadeias de caracteres é alocada e lançada por meio de um objeto do Gerenciador de cadeia de caracteres, associado a cada instância de `CStringT`. MFC e ATL fornecem instanciações de padrão de `CStringT`, chamado `CString`, `CStringA`, e `CStringW`, que manipular cadeias de caracteres de tipos de caracteres diferentes. Esses tipos de caractere são do tipo **TCHAR**, `char`, e `wchar_t`, respectivamente. Esses tipos de cadeia de caracteres padrão usam um Gerenciador de cadeia de caracteres que aloca a memória de heap de processo (em ATL) ou o heap de CRT (em MFC). Em aplicativos típicos, esse esquema de alocação de memória é suficiente. No entanto, fazer uso intensivo de código de uso de cadeias de caracteres (ou código multi-threaded) os gerenciadores de memória padrão não podem executar de forma ideal. Este tópico descreve como substituir o comportamento de gerenciamento de memória padrão de `CStringT`, criar alocadores especificamente otimizado para a tarefa em questão.  
  
-   [Implementação de um gerenciador de cadeia de caracteres personalizada (método básico)](../atl-mfc-shared/implementation-of-a-custom-string-manager-basic-method.md)  
  
-   [Evitar contenção de heap](../atl-mfc-shared/avoidance-of-heap-contention.md)  
  
-   [Implementação de um gerenciador de cadeia de caracteres personalizada (método avançado)](../atl-mfc-shared/implementation-of-a-custom-string-manager-advanced-method.md)  
  
-   [CFixedStringT: Um exemplo de um Gerenciador de cadeia de caracteres personalizada](../atl-mfc-shared/cfixedstringt-example-of-a-custom-string-manager.md)  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo de CustomString](../visual-cpp-samples.md)

