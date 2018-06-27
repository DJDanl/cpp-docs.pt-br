---
title: Lendo e gravando arquivos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CFile class [MFC], objects
- examples [MFC], reading files
- files [MFC], writing to
- examples [MFC], writing to files
- files [MFC], reading
- MFC, file operations
- CFile class [MFC], reading and writing CFile objects
- reading files
- writing to files [MFC]
ms.assetid: cac0c826-ba56-495f-99b3-ce6336f65763
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e30ee5b326833b45365c422238ecfcd4f82c556d
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36930905"
---
# <a name="reading-and-writing-files"></a>Lendo e gravando arquivos
Se você tiver usado as funções de manipulação de arquivos de biblioteca de tempo de execução C, MFC lendo e gravando operações aparecerá familiar. Este artigo descreve ler diretamente e gravar diretamente para um `CFile` objeto. Você pode também em buffer e/s de arquivo com o [CArchive](../mfc/reference/carchive-class.md) classe.  
  
#### <a name="to-read-from-and-write-to-the-file"></a>Para ler e gravar no arquivo  
  
1.  Use o `Read` e `Write` funções de membro para ler e gravar dados no arquivo.  
  
     -ou-  
  
2.  O `Seek` função membro também está disponível para mover para um deslocamento específico dentro do arquivo.  
  
 `Read` usa um ponteiro para um buffer e o número de bytes a serem lidos e retorna o número real de bytes que foram lidos. Se o número de bytes necessário não foi possível ler porque o fim do arquivo (EOF) for atingido, o número real de bytes lidos é retornado. Se ocorrer um erro de leitura, uma exceção será lançada. `Write` é semelhante ao `Read`, mas o número de bytes gravados não é retornado. Se ocorrer um erro de gravação, incluindo não gravar todos os bytes especificados, uma exceção será lançada. Se você tiver um válido `CFile` do objeto, você pode lê-lo ou gravar conforme mostrado no exemplo a seguir:  
  
 [!code-cpp[NVC_MFCFiles#2](../atl-mfc-shared/reference/codesnippet/cpp/reading-and-writing-files_1.cpp)]  
  
> [!NOTE]
>  Você normalmente deve executar as operações de entrada/saída dentro de um **tente**/**catch** bloco de tratamento de exceções. Para obter mais informações, consulte [de tratamento de exceção (MFC)](../mfc/exception-handling-in-mfc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos](../mfc/files-in-mfc.md)

