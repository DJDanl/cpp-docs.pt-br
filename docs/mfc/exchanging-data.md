---
title: Trocando dados
ms.date: 11/04/2016
helpviewer_keywords:
- property sheets [MFC], data exchange
- exchanging data with property sheets [MFC]
- DDX (dialog data exchange) [MFC], property sheets
ms.assetid: 689f02d0-51a9-455b-8ffb-5b44f0aefa28
ms.openlocfilehash: de82a337f19b7b2ac6039fd3f3c16ab67aa1dc99
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62405840"
---
# <a name="exchanging-data"></a>Trocando dados

Assim como acontece com a maioria das caixas de diálogo, a troca de dados entre a folha de propriedades e o aplicativo é uma das funções mais importantes da folha de propriedades. Este artigo descreve como realizar essa tarefa.

Trocando dados com uma folha de propriedades é realmente uma questão de troca de dados com as páginas de propriedades individuais da folha de propriedades. O procedimento para a troca de dados com uma página de propriedades é da mesma maneira que a troca de dados com uma caixa de diálogo, como um [CPropertyPage](../mfc/reference/cpropertypage-class.md) objeto é apenas especializada [CDialog](../mfc/reference/cdialog-class.md) objeto. O procedimento aproveita caixa de diálogo dados (DDX) instalação do exchange a estrutura, que troca dados entre os controles em variáveis de membro e de caixa de diálogo do objeto de caixa de diálogo.

A diferença importante entre a troca de dados com uma folha de propriedades e uma caixa de diálogo normal é que a folha de propriedades tem várias páginas, portanto, você deve trocar dados com todas as páginas na folha de propriedades. Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../mfc/dialog-data-exchange-and-validation.md).

O exemplo a seguir ilustra a troca de dados entre um modo de exibição e duas páginas de uma folha de propriedades:

[!code-cpp[NVC_MFCDocView#4](../mfc/codesnippet/cpp/exchanging-data_1.cpp)]

## <a name="see-also"></a>Consulte também

[Folhas de propriedades](../mfc/property-sheets-mfc.md)
