---
title: Trocando dados | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- property sheets [MFC], data exchange
- exchanging data with property sheets [MFC]
- DDX (dialog data exchange) [MFC], property sheets
ms.assetid: 689f02d0-51a9-455b-8ffb-5b44f0aefa28
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e503bd9268423fbe63ec76de4bcb5443a7d52696
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="exchanging-data"></a>Trocando dados
Assim como acontece com a maioria das caixas de diálogo, a troca de dados entre a folha de propriedades e o aplicativo é uma das funções mais importantes da folha de propriedades. Este artigo descreve como realizar essa tarefa.  
  
 Trocando dados com uma folha de propriedades é realmente uma questão de troca de dados com páginas de propriedades individuais da folha de propriedades. O procedimento para trocar dados com uma página de propriedade é igual de troca de dados com uma caixa de diálogo, como um [CPropertyPage](../mfc/reference/cpropertypage-class.md) objeto é apenas um especializado [CDialog](../mfc/reference/cdialog-class.md) objeto. O procedimento aproveita o recurso exchange (DDX) da estrutura caixa de diálogo dados, que troca dados entre os controles em variáveis de membro e de caixa de diálogo do objeto de caixa de diálogo.  
  
 A diferença importante entre trocando dados com uma folha de propriedades e uma caixa de diálogo normal é que a folha de propriedades tem várias páginas, portanto você deve trocar dados com todas as páginas de folha de propriedades. Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../mfc/dialog-data-exchange-and-validation.md).  
  
 O exemplo a seguir ilustra a troca de dados entre um modo de exibição e duas páginas de uma folha de propriedades:  
  
 [!code-cpp[NVC_MFCDocView#4](../mfc/codesnippet/cpp/exchanging-data_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Folhas de propriedade](../mfc/property-sheets-mfc.md)

