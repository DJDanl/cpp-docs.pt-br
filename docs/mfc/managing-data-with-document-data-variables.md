---
title: Gerenciando dados com variáveis de dados de documento | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e0a1db1e15733a0a3cd217c44aaaa325c146ee64
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46435877"
---
# <a name="managing-data-with-document-data-variables"></a>Gerenciando dados com variáveis de dados do documento

Implemente dados do seu documento como variáveis de membro de sua classe de documento. Por exemplo, o programa de rabisco declara um membro de dados do tipo `CObList` — uma lista vinculada que armazena ponteiros para `CObject` objetos. Essa lista é usada para armazenar as matrizes de pontos que compõem um desenho de linha traçada à mão livre.

Como você pode implementar dados de membro do seu documento depende da natureza do seu aplicativo. Para ajudá-lo, o MFC fornece um grupo de "classes de coleção" — matrizes, listas e mapas (dicionários), incluindo coleções com base em modelos de C++ — junto com as classes que encapsulam uma variedade de tipos de dados comuns, como `CString`, `CRect`, `CPoint`, `CSize`, e `CTime`. Para obter mais informações sobre essas classes, consulte o [visão geral da biblioteca de classes](../mfc/class-library-overview.md) na *referência da MFC*.

Quando você define os dados de membro do seu documento, geralmente adicionará funções de membro à classe de documento para definir e obter itens de dados e executar outras operações úteis neles.

Suas exibições de acessar o objeto do documento usando o ponteiro da exibição para o documento, instalado no modo de exibição no momento da criação. Você pode recuperar esse ponteiro nas funções de membro de uma exibição chamando o `CView` função de membro `GetDocument`. Certifique-se de converter esse ponteiro para seu próprio tipo de documento. Em seguida, você pode acessar membros públicos de documento através do ponteiro.

Se a transferência de dados frequentes requer acesso direto, ou você deseja usar os membros não públicos da classe do documento, você talvez queira tornar a exibição de classe a um amigo (em termos de C++) da classe do documento.

## <a name="see-also"></a>Consulte também

[Usando documentos](../mfc/using-documents.md)

