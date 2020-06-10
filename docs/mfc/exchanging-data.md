---
title: Trocando dados
ms.date: 11/04/2016
helpviewer_keywords:
- property sheets [MFC], data exchange
- exchanging data with property sheets [MFC]
- DDX (dialog data exchange) [MFC], property sheets
ms.assetid: 689f02d0-51a9-455b-8ffb-5b44f0aefa28
ms.openlocfilehash: 5be82567e02fd5e935d42f9eff5bdee20fa0d5a8
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84622700"
---
# <a name="exchanging-data"></a>Trocando dados

Assim como ocorre com a maioria das caixas de diálogo, a troca de dados entre a folha de propriedades e o aplicativo é uma das funções mais importantes da folha de propriedades. Este artigo descreve como realizar essa tarefa.

A troca de dados com uma folha de propriedades é, na verdade, uma questão de trocar dados com as páginas de propriedades individuais da folha de propriedades. O procedimento para trocar dados com uma página de propriedades é o mesmo que para trocar dados com uma caixa de diálogo, já que um objeto [CPropertyPage](reference/cpropertypage-class.md) é apenas um objeto [CDialog](reference/cdialog-class.md) especializado. O procedimento aproveita o recurso de troca de dados de diálogo (campo DDX) da estrutura, que troca dados entre controles em uma caixa de diálogo e variáveis de membro do objeto da caixa de diálogo.

A diferença importante entre a troca de dados com uma folha de propriedades e com uma caixa de diálogo normal é que a folha de propriedades tem várias páginas, portanto, você deve trocar dados com todas as páginas na folha de propriedades. Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](dialog-data-exchange-and-validation.md).

O exemplo a seguir ilustra a troca de dados entre uma exibição e duas páginas de uma folha de propriedades:

[!code-cpp[NVC_MFCDocView#4](codesnippet/cpp/exchanging-data_1.cpp)]

## <a name="see-also"></a>Consulte também

[Folhas de propriedades](property-sheets-mfc.md)
