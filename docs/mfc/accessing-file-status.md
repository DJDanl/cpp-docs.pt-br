---
title: Acessando status do arquivo
ms.date: 11/04/2016
helpviewer_keywords:
- files [MFC], status information
- examples [MFC], file status
- files [MFC], accessing
- file status [MFC]
- status of files [MFC]
ms.assetid: 1b8891d6-eb0f-4037-a837-4928fe595222
ms.openlocfilehash: 26c263b2d7e4e0243444925cb9416cb337dcd79d
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57298887"
---
# <a name="accessing-file-status"></a>Acessando status do arquivo

`CFile` também oferece suporte para obter status do arquivo, incluindo se o arquivo existe, datas de criação e modificação e horas, tamanho lógico e caminho.

### <a name="to-get-file-status"></a>Para obter o status do arquivo

1. Use o [CFile](../mfc/reference/cfile-class.md) classe para obter e definir informações sobre um arquivo. Um aplicativo útil é usar o `CFile` função de membro estático **GetStatus** para determinar se existe um arquivo. **GetStatus** retornará 0 se o arquivo especificado não existe.

Assim, você pode usar o resultado de **GetStatus** para determinar se deve usar o **CFile::modeCreate** sinalizador ao abrir um arquivo, conforme mostrado no exemplo a seguir:

[!code-cpp[NVC_MFCFiles#3](../atl-mfc-shared/reference/codesnippet/cpp/accessing-file-status_1.cpp)]

Para obter informações relacionadas, consulte [serialização](../mfc/serialization-in-mfc.md).

## <a name="see-also"></a>Consulte também

[Arquivos](../mfc/files-in-mfc.md)
