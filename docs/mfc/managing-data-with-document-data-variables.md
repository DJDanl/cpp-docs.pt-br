---
title: Gerenciando dados com variáveis de dados do documento
ms.date: 11/04/2016
helpviewer_keywords:
- documents [MFC], data storage
- friend classes [MFC]
- classes [MFC], friend
- data [MFC]
- data [MFC], documents
- collection classes [MFC], used by document object
- document data [MFC]
- member variables [MFC], document class [MFC]
ms.assetid: e70b87f4-8c30-49e5-8986-521c2ff91704
ms.openlocfilehash: 3d845b0fc3d00369d44c21c04a3fb7e3b8d6189e
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618319"
---
# <a name="managing-data-with-document-data-variables"></a>Gerenciando dados com variáveis de dados do documento

Implemente os dados do documento como variáveis de membro de sua classe de documento. Por exemplo, o programa rabiscar declara um membro de dados do tipo `CObList` — uma lista vinculada que armazena ponteiros para `CObject` objetos. Essa lista é usada para armazenar matrizes de pontos que compõem um desenho de linha livre.

A maneira como você implementa os dados do membro do documento depende da natureza do seu aplicativo. Para ajudá-lo, o MFC fornece um grupo de "classes de coleção" — matrizes, listas e mapas (dicionários), incluindo coleções baseadas em modelos C++ – juntamente com classes que encapsulam uma variedade de tipos de dados comuns, como,,, `CString` `CRect` `CPoint` `CSize` e `CTime` . Para obter mais informações sobre essas classes, consulte a [visão geral da biblioteca de classes](class-library-overview.md) na referência do *MFC*.

Ao definir os dados de membro do documento, você geralmente adicionará funções de membro à classe de documento para definir e obter itens de dados e executar outras operações úteis neles.

Suas exibições acessam o objeto de documento usando o ponteiro do modo de exibição para o documento, instalado na exibição no momento da criação. Você pode recuperar esse ponteiro nas funções de membro de uma exibição chamando a `CView` função de membro `GetDocument` . Certifique-se de converter esse ponteiro para seu próprio tipo de documento. Em seguida, você pode acessar membros de documento público por meio do ponteiro.

Se a transferência de dados frequente exigir acesso direto ou se você quiser usar os membros não públicos da classe de documento, talvez queira tornar sua classe de exibição um amigo (em termos de C++) da classe de documento.

## <a name="see-also"></a>Consulte também

[Usando documentos](using-documents.md)
