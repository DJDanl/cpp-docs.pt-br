---
title: Classes de tipo de dados simples
ms.date: 11/04/2016
f1_keywords:
- vc.classes.data
helpviewer_keywords:
- scalar classes [MFC]
- data classes [MFC]
- simple data type classes [MFC]
ms.assetid: 0d591d68-0a33-49e9-8a6d-90c90de5c16a
ms.openlocfilehash: 4e415805301d7d12bd418a3b55509a7732851492
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62307412"
---
# <a name="simple-data-type-classes"></a>Classes de tipo de dados simples

As seguintes classes encapsulam coordenadas, cadeias de caracteres e tempo de desenho e informações de data, permitindo que conveniente usar sintaxe de C++. Esses objetos são usados amplamente como parâmetros para as funções de membro de classes do Windows na biblioteca de classes. Porque `CPoint`, `CSize`, e `CRect` correspondem aos **ponto**, **tamanho**, e **RECT** estruturas, respectivamente, no SDK do Windows, Você pode usar objetos dessas classes C++ sempre que você pode usar essas estruturas de linguagem C. As classes fornecem interfaces úteis por meio de suas funções de membro. `CStringT` Fornece as cadeias de caracteres dinâmica muito flexível. `CTime`, `COleDateTime`, `CTimeSpan`, e `COleTimeSpan` representam valores de data e hora. Para obter mais informações sobre essas classes, consulte o artigo [data e hora](../atl-mfc-shared/date-and-time.md).

As classes que começam com "`COle`" são encapsulamentos dos tipos de dados fornecidos pelo OLE. Esses tipos de dados podem ser usados em programas do Windows, independentemente de se outros recursos do OLE são usados.

[Classe CStringT](../atl-mfc-shared/reference/cstringt-class.md)<br/>
Contém as cadeias de caracteres.

[CTime](../atl-mfc-shared/reference/ctime-class.md)<br/>
Contém valores de data e hora absolutas.

[COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md)<br/>
Wrapper para o tipo de automação OLE **data**. Representa valores de data e hora.

[CTimeSpan](../atl-mfc-shared/reference/ctimespan-class.md)<br/>
Contém valores de data e hora relativas.

[COleDateTimeSpan](../atl-mfc-shared/reference/coledatetimespan-class.md)<br/>
Mantém relativa `COleDateTime` valores, como a diferença entre dois `COleDateTime` valores.

[CPoint](../atl-mfc-shared/reference/cpoint-class.md)<br/>
Contém pares de coordenadas (x, y).

[CSize](../atl-mfc-shared/reference/csize-class.md)<br/>
Mantém a distância, posições relativas ou valores de pares.

[CRect](../atl-mfc-shared/reference/crect-class.md)<br/>
Contém as coordenadas das áreas retangulares.

[CImageList](../mfc/reference/cimagelist-class.md)<br/>
Fornece a funcionalidade da lista de imagens do Windows. Listas de imagens são usadas com controles de árvore e controles de lista. Eles também podem ser usados para armazenar e arquivar um conjunto de bitmaps de mesmo tamanho.

[COleVariant](../mfc/reference/colevariant-class.md)<br/>
Wrapper para o tipo de automação OLE **VARIANT**. Dados no **VARIANT**s podem ser armazenados em vários formatos.

[COleCurrency](../mfc/reference/colecurrency-class.md)<br/>
Wrapper para o tipo de automação OLE **moeda**, um tipo aritmético de ponto fixo, com 15 dígitos antes do ponto decimal e 4 dígitos após.

> [!NOTE]
>  `CRect`, `CSize`, e `CPoint` podem ser usados em aplicativos MFC ou ATL. Além disso, `CStringT` fornece um independente de MFC `CString`-como a classe. Para obter mais informações sobre classes de utilitário compartilhado, consulte [Classes compartilhadas](../atl-mfc-shared/atl-mfc-shared-classes.md).

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
