---
title: "Funções de retorno de chamada usadas pelo MFC | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.functions
dev_langs:
- C++
helpviewer_keywords:
- callback functions, MFC
- MFC, callback functions
- functions [C++], callback
- callback functions
ms.assetid: b2a6857c-fdd3-45ec-8fd8-2e71fac77582
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: b4d104fa76347da43c84611672f843511f0f3725
ms.lasthandoff: 02/25/2017

---
# <a name="callback-functions-used-by-mfc"></a>Funções de Retorno de Chamada Usadas pelo MFC
Três funções de retorno de chamada são exibidos no Microsoft Foundation Class Library. Uma descrição das funções de retorno de chamada que são passados para [CDC:: enumobjects](../../mfc/reference/cdc-class.md#enumobjects), [CDC:: graystring](../../mfc/reference/cdc-class.md#graystring), e [CDC:: SetAbortProc](../../mfc/reference/cdc-class.md#setabortproc) após este tópico. O uso geral de funções de retorno de chamada, consulte a seção comentários dessas funções de membro. Observe que todas as funções de retorno de chamada devem interceptar exceções MFC antes de retornar ao Windows, como exceções não podem ser geradas em limites de retorno de chamada. Para obter mais informações sobre exceções, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)


