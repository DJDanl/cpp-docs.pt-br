---
title: Acessando Status do arquivo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- files [MFC], status information
- examples [MFC], file status
- files [MFC], accessing
- file status [MFC]
- status of files [MFC]
ms.assetid: 1b8891d6-eb0f-4037-a837-4928fe595222
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d424502e991ea355a6e31bba8fedccb6d5ad2fcf
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33334289"
---
# <a name="accessing-file-status"></a>Acessando status do arquivo
`CFile` também oferece suporte para obter status do arquivo, incluindo se o arquivo existe, datas de criação e modificação e vezes, o tamanho lógico e caminho.  
  
### <a name="to-get-file-status"></a>Para obter o status do arquivo  
  
1.  Use o [CFile](../mfc/reference/cfile-class.md) classe para obter e definir informações sobre um arquivo. Um aplicativo útil é usar o `CFile` função de membro estático **GetStatus** para determinar se existe um arquivo. **GetStatus** retornará 0 se o arquivo especificado não existe.  
  
 Assim, você pode usar o resultado de **GetStatus** para determinar se deve usar o **CFile::modeCreate** sinalizador ao abrir um arquivo, conforme mostrado pelo exemplo a seguir:  
  
 [!code-cpp[NVC_MFCFiles#3](../atl-mfc-shared/reference/codesnippet/cpp/accessing-file-status_1.cpp)]  
  
 Para obter informações relacionadas, consulte [serialização](../mfc/serialization-in-mfc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos](../mfc/files-in-mfc.md)

