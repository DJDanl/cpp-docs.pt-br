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
ms.openlocfilehash: 23c626940e700d3e9827ef6a7cf849d970e40d5d
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619783"
---
# <a name="accessing-file-status"></a>Acessando status do arquivo

`CFile`também dá suporte à obtenção do status do arquivo, incluindo se o arquivo existe, datas de criação e modificação e horas, tamanho lógico e caminho.

### <a name="to-get-file-status"></a>Para obter o status do arquivo

1. Use a classe [testcfile](reference/cfile-class.md) para obter e definir informações sobre um arquivo. Um aplicativo útil é usar a `CFile` função de membro estático **GetStatus** para determinar se um arquivo existe. **GetStatus** retornará 0 se o arquivo especificado não existir.

Portanto, você pode usar o resultado de **GetStatus** para determinar se deve usar o sinalizador **testcfile:: modeCreate** ao abrir um arquivo, conforme mostrado no exemplo a seguir:

[!code-cpp[NVC_MFCFiles#3](../atl-mfc-shared/reference/codesnippet/cpp/accessing-file-status_1.cpp)]

Para obter informações relacionadas, consulte [serialização](serialization-in-mfc.md).

## <a name="see-also"></a>Consulte também

[Arquivos](files-in-mfc.md)
