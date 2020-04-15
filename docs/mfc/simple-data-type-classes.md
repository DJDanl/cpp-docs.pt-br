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
ms.openlocfilehash: d4038334e35b734370a437d35519498b96c00770
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365406"
---
# <a name="simple-data-type-classes"></a>Classes de tipo de dados simples

As classes a seguir encapsulam coordenadas de desenho, seqüências de caracteres e informações de hora e data, permitindo o uso conveniente da sintaxe C++. Esses objetos são amplamente usados como parâmetros para as funções de membros das classes windows na biblioteca de classes. Porque `CPoint` `CSize`, `CRect` e corresponder às estruturas **POINT,** **SIZE**e **RECT,** respectivamente, no Windows SDK, você pode usar objetos dessas classes C++ onde você pode usar essas estruturas de linguagem C. As aulas fornecem interfaces úteis através de suas funções de membro. `CStringT`fornece strings de caracteres dinâmicos muito flexíveis. `CTime`, `COleDateTime` `CTimeSpan`e `COleTimeSpan` representar valores de data e hora. Para obter mais informações sobre essas aulas, consulte o artigo [Data e hora](../atl-mfc-shared/date-and-time.md).

As classes que`COle`começam com " " são encapsulamentos de tipos de dados fornecidos pela OLE. Esses tipos de dados podem ser usados em programas do Windows, independentemente de outros recursos oLE serem usados.

[Classe Cstringt](../atl-mfc-shared/reference/cstringt-class.md)<br/>
Segura as cordas do caractere.

[Ctime](../atl-mfc-shared/reference/ctime-class.md)<br/>
Mantém valores absolutos de tempo e data.

[Coledatetime](../atl-mfc-shared/reference/coledatetime-class.md)<br/>
Wrapper para o tipo de automação OLE **DATE**. Representa valores de data e hora.

[Ctimespan](../atl-mfc-shared/reference/ctimespan-class.md)<br/>
Mantém valores relativos de hora e data.

[Coledatetimespan](../atl-mfc-shared/reference/coledatetimespan-class.md)<br/>
Possui `COleDateTime` valores relativos, como `COleDateTime` a diferença entre dois valores.

[Cpoint](../atl-mfc-shared/reference/cpoint-class.md)<br/>
Segura os pares de coordenadas (x, y).

[Csize](../atl-mfc-shared/reference/csize-class.md)<br/>
Mantém distância, posições relativas ou valores emparelhados.

[Crect](../atl-mfc-shared/reference/crect-class.md)<br/>
Mantém coordenadas de áreas retangulares.

[Cimagelist](../mfc/reference/cimagelist-class.md)<br/>
Fornece a funcionalidade da lista de imagens do Windows. Listas de imagens são usadas com controles de lista e controles de árvores. Eles também podem ser usados para armazenar e arquivar um conjunto de bitmaps do mesmo tamanho.

[Colevariant](../mfc/reference/colevariant-class.md)<br/>
Wrapper para o tipo de automação OLE **VARIANT**. Os dados em **VARIANTS**podem ser armazenados em muitos formatos.

[Colecurrency](../mfc/reference/colecurrency-class.md)<br/>
Wrapper para o tipo de automação OLE **CURRENCY**, um tipo de aritmética de ponto fixo, com 15 dígitos antes do ponto decimal e 4 dígitos depois.

> [!NOTE]
> `CRect`, `CSize`e `CPoint` são utilizáveis em aplicações ATL ou MFC. Além disso, `CStringT` fornece uma `CString`classe independente de MFC. Para obter mais informações sobre classes de utilidade compartilhadas, consulte [Classes compartilhadas](../atl-mfc-shared/atl-mfc-shared-classes.md).

## <a name="see-also"></a>Confira também

[Visão geral da classe](../mfc/class-library-overview.md)
