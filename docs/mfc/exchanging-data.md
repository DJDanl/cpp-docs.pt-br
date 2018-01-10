---
title: Trocando dados | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- property sheets [MFC], data exchange
- exchanging data with property sheets [MFC]
- DDX (dialog data exchange) [MFC], property sheets
ms.assetid: 689f02d0-51a9-455b-8ffb-5b44f0aefa28
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 172b03278ceede44f06b846c8b4f066e9f141e3b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="exchanging-data"></a>Trocando dados
Assim como acontece com a maioria das caixas de diálogo, a troca de dados entre a folha de propriedades e o aplicativo é uma das funções mais importantes da folha de propriedades. Este artigo descreve como realizar essa tarefa.  
  
 Trocando dados com uma folha de propriedades é realmente uma questão de troca de dados com páginas de propriedades individuais da folha de propriedades. O procedimento para trocar dados com uma página de propriedade é igual de troca de dados com uma caixa de diálogo, como um [CPropertyPage](../mfc/reference/cpropertypage-class.md) objeto é apenas um especializado [CDialog](../mfc/reference/cdialog-class.md) objeto. O procedimento aproveita o recurso exchange (DDX) da estrutura caixa de diálogo dados, que troca dados entre os controles em variáveis de membro e de caixa de diálogo do objeto de caixa de diálogo.  
  
 A diferença importante entre trocando dados com uma folha de propriedades e uma caixa de diálogo normal é que a folha de propriedades tem várias páginas, portanto você deve trocar dados com todas as páginas de folha de propriedades. Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../mfc/dialog-data-exchange-and-validation.md).  
  
 O exemplo a seguir ilustra a troca de dados entre um modo de exibição e duas páginas de uma folha de propriedades:  
  
 [!code-cpp[NVC_MFCDocView#4](../mfc/codesnippet/cpp/exchanging-data_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Folhas de propriedade](../mfc/property-sheets-mfc.md)

