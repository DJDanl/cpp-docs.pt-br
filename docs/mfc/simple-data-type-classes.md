---
title: Classes de tipo de dados simples | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.classes.data
dev_langs:
- C++
helpviewer_keywords:
- scalar classes [MFC]
- data classes [MFC]
- simple data type classes [MFC]
ms.assetid: 0d591d68-0a33-49e9-8a6d-90c90de5c16a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 176ad940e95fbbf18e4ea86800111b483ee32135
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36953590"
---
# <a name="simple-data-type-classes"></a>Classes de tipo de dados simples
As seguintes classes encapsulam coordenadas, cadeias de caracteres e tempo de desenho e informações de data, permitindo conveniente usar sintaxe de C++. Esses objetos são usados amplamente como parâmetros para as funções de membro de classes do Windows na biblioteca de classes. Porque `CPoint`, `CSize`, e `CRect` correspondem do **ponto**, **tamanho**, e **RECT** estruturas, respectivamente, no SDK do Windows, Você pode usar os objetos dessas classes C++ sempre que você pode usar essas estruturas de linguagem C. As classes fornecem interfaces útil por meio de suas funções de membro. `CStringT` Fornece as cadeias de caracteres dinâmica muito flexível. `CTime`, `COleDateTime`, `CTimeSpan`, e `COleTimeSpan` representar valores de data e hora. Para obter mais informações sobre essas classes, consulte o artigo [data e hora](../atl-mfc-shared/date-and-time.md).  
  
 As classes que começam com "`COle`" são encapsulamentos de tipos de dados fornecidos pelo OLE. Esses tipos de dados podem ser usados em programas Windows independentemente do uso de outros recursos OLE.  
  
 [Classe CStringT](../atl-mfc-shared/reference/cstringt-class.md)  
 Contém cadeias de caracteres.  
  
 [CTime](../atl-mfc-shared/reference/ctime-class.md)  
 Contém os valores de hora e data absolutos.  
  
 [COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md)  
 Wrapper para o tipo de automação OLE **data**. Representa os valores de data e hora.  
  
 [CTimeSpan](../atl-mfc-shared/reference/ctimespan-class.md)  
 Contém os valores de data e hora relativos.  
  
 [COleDateTimeSpan](../atl-mfc-shared/reference/coledatetimespan-class.md)  
 Contém relativo `COleDateTime` valores, como a diferença entre dois `COleDateTime` valores.  
  
 [CPoint](../atl-mfc-shared/reference/cpoint-class.md)  
 Contém pares de coordenadas (x, y).  
  
 [CSize](../atl-mfc-shared/reference/csize-class.md)  
 Mantém a distância, posições relativas ou pares de valores.  
  
 [CRect](../atl-mfc-shared/reference/crect-class.md)  
 Contém as coordenadas das áreas retangulares.  
  
 [CImageList](../mfc/reference/cimagelist-class.md)  
 Fornece a funcionalidade da lista de imagens do Windows. Listas de imagens são usadas com controles de árvore e controles de lista. Eles também podem ser usados para armazenar e arquivar um conjunto de bitmaps do mesmo tamanho.  
  
 [COleVariant](../mfc/reference/colevariant-class.md)  
 Wrapper para o tipo de automação OLE **VARIANT**. Dados em **VARIANT**s podem ser armazenados em vários formatos.  
  
 [COleCurrency](../mfc/reference/colecurrency-class.md)  
 Wrapper para o tipo de automação OLE **moeda**, um tipo aritmético de ponto fixo, com 15 dígitos antes do ponto decimal e 4 dígitos após.  
  
> [!NOTE]
>  `CRect`, `CSize`, e `CPoint` podem ser usados em aplicativos MFC ou do ATL. Além disso, `CStringT` fornece um independente de MFC `CString`-como classe. Para obter mais informações sobre classes de utilitário compartilhados, consulte [Classes compartilhadas](../atl-mfc-shared/atl-mfc-shared-classes.md).  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

