---
title: Inicializando documentos e exibições
ms.date: 11/04/2016
helpviewer_keywords:
- initializing documents [MFC]
- documents [MFC], initializing
- views [MFC], initializing
- initializing objects [MFC], document objects
- initializing views [MFC]
ms.assetid: 33cb8643-8a16-478c-bc26-eccc734e3661
ms.openlocfilehash: 0e970d6e8a166283f82575b309cf023f48899403
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626347"
---
# <a name="initializing-documents-and-views"></a>Inicializando documentos e exibições

Os documentos são criados de duas maneiras diferentes, portanto, sua classe de documento deve dar suporte a ambas as maneiras. Primeiro, o usuário pode criar um novo documento vazio com o comando arquivo novo. Nesse caso, inicialize o documento em sua substituição da função membro [OnNewDocument](reference/cdocument-class.md#onnewdocument) da classe [CDocument](reference/cdocument-class.md). Em segundo lugar, o usuário pode usar o comando abrir no menu arquivo para criar um novo documento cujo conteúdo seja lido a partir de um arquivo. Nesse caso, inicialize o documento em sua substituição da função de membro [OnOpenDocument](reference/cdocument-class.md#onopendocument) da classe `CDocument` . Se ambas as inicializações forem as mesmas, você poderá chamar uma função de membro comum de ambas as substituições ou `OnOpenDocument` pode chamar `OnNewDocument` para inicializar um documento limpo e, em seguida, concluir a operação de abertura.

As exibições são criadas depois que seus documentos são criados. O melhor momento para inicializar uma exibição é depois que a estrutura termina de criar o documento, a janela do quadro e a exibição. Você pode inicializar o modo de exibição substituindo a função membro [OnInitialUpdate](reference/cview-class.md#oninitialupdate) de [cvisualização](reference/cview-class.md). Se precisar reinicializar ou ajustar qualquer coisa sempre que o documento for alterado, você poderá substituir [OnUpdate](reference/cview-class.md#onupdate).

## <a name="see-also"></a>Consulte também

[Inicializando e limpando documentos e exibições](initializing-and-cleaning-up-documents-and-views.md)
