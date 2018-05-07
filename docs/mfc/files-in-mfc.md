---
title: Arquivos no MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- serialization [MFC], MFC files
- I/O [MFC], MFC classes
- files [MFC], MFC
- files [MFC], serialization
- binary access, binary file operations in MFC
- file I/O classes [MFC]
- I/O [MFC]
- persistence [MFC]
- MFC, file operations
- files [MFC], manipulating
- binary access [MFC]
ms.assetid: ae25e2c5-2859-4679-ab97-438824e93ce1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 30d220c928f2ca3fe0594d03d558d2d6dcfce773
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="files-in-mfc"></a>Arquivos no MFC
No Microsoft Foundation Class Library (MFC), classe [CFile](../mfc/reference/cfile-class.md) manipula as operações de e/s de arquivo normal. Essa família de artigos explica como abrir e fechar arquivos, bem como ler e gravar dados nesses arquivos. Ele também discute o status de operações de arquivo. Para obter uma descrição de como usar os recursos de serialização com base em objeto do MFC como uma maneira alternativa de ler e gravar dados em arquivos, consulte o artigo [serialização](../mfc/serialization-in-mfc.md).  
  
> [!NOTE]
>  Quando você usa MFC **CDocument** objetos, a estrutura faz muito do trabalho de serialização para você. Em particular, o framework cria e usa o `CFile` objeto. Você só precisa escrever código em sua substituição do `Serialize` função de membro de classe **CDocument**.  
  
 O `CFile` classe fornece uma interface para uso geral de arquivo binário. O `CStdioFile` e `CMemFile` classes derivadas de `CFile` e `CSharedFile` classe derivada de `CMemFile` fornecer serviços de arquivo mais especializados.  
  
 Para obter mais informações sobre alternativas para manipulação de arquivos do MFC, consulte [tratamento de arquivos](../c-runtime-library/file-handling.md) no *referência da biblioteca de tempo de execução*.  
  
 Para obter informações sobre derivado `CFile` classes, consulte o [gráfico de hierarquia MFC](../mfc/hierarchy-chart.md).  
  
## <a name="what-do-you-want-to-do"></a>O que você deseja fazer  
 *Use CFile*  
  
-   [Abrir um arquivo com CFile](../mfc/opening-files.md)  
  
-   [Ler e gravar um arquivo com CFile](../mfc/reading-and-writing-files.md)  
  
-   [Fechar um arquivo com CFile](../mfc/closing-files.md)  
  
-   [Status de acesso ao arquivo com CFile](../mfc/accessing-file-status.md)  
  
 *Usar a serialização de MFC (persistência de objetos)*  
  
-   [Criar uma classe serializável](../mfc/serialization-making-a-serializable-class.md)  
  
-   [Serializar um objeto por meio de um objeto CArchive](../mfc/serialization-serializing-an-object.md)  
  
-   [Criar um objeto CArchive](../mfc/two-ways-to-create-a-carchive-object.md)  
  
-   [Use CArchive <\< e >> operadores](../mfc/using-the-carchive-output-and-input-operators.md)  
  
-   [Armazenar e carregar CObjects e derivadas de CObject objetos por meio de um arquivo morto](../mfc/storing-and-loading-cobjects-via-an-archive.md)  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../mfc/mfc-concepts.md)   
 [Tópicos MFC gerais](../mfc/general-mfc-topics.md)   
 [Classe CArchive](../mfc/reference/carchive-class.md)   
 [Classe CObject](../mfc/reference/cobject-class.md)
