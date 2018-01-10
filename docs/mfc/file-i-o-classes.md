---
title: Classes de e-S de arquivo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.classes.file
dev_langs: C++
helpviewer_keywords:
- disk file classes [MFC]
- stdio classes [MFC]
- OLE streams [MFC]
- I/O [MFC], MFC classes
- translated stream classes [MFC]
- file I/O classes [MFC]
- I/O [MFC], classes
- sockets classes [MFC]
- stream classes [MFC]
- memory file classes [MFC]
ms.assetid: 92821c3f-d9e1-47f6-98c9-3b632d86e811
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 454e64d67321282030126d2aab023e9f587c1cca
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="file-io-classes"></a>Classes de E/S do arquivo
Essas classes fornecem uma interface para arquivos de disco tradicional, arquivos em memória, fluxos ativos e soquetes do Windows. Todas as classes derivam de `CFile` pode ser usado com um `CArchive` objeto para executar a serialização.  
  
 Use as seguintes classes, especialmente `CArchive` e `CFile`, se você escrever seu próprio processamento de entrada/saída. Normalmente você não precisa derivar dessas classes. Se você usar a estrutura de aplicativo, as implementações padrão da **abrir** e **salvar** comandos no **arquivo** menu tratará a e/s de arquivo (usando a classe `CArchive`), contanto que você substituir o documento `Serialize` função para fornecer detalhes sobre como um documento serializa seu conteúdo. Para obter mais informações sobre as classes de arquivo e a serialização, consulte o artigo [arquivos no MFC](../mfc/files-in-mfc.md) e o artigo [serialização](../mfc/serialization-in-mfc.md).  
  
 [CFile](../mfc/reference/cfile-class.md)  
 Fornece uma interface de arquivo para arquivos binários no disco.  
  
 [CStdioFile](../mfc/reference/cstdiofile-class.md)  
 Fornece um `CFile` interface aos arquivos de disco do fluxo armazenado em buffer, geralmente em modo de texto.  
  
 [CMemFile](../mfc/reference/cmemfile-class.md)  
 Fornece um `CFile` interface para arquivos em memória.  
  
 [CSharedFile](../mfc/reference/csharedfile-class.md)  
 Fornece um `CFile` interface para arquivos de na memória compartilhados.  
  
 [COleStreamFile](../mfc/reference/colestreamfile-class.md)  
 Usa o COM `IStream` interface para fornecer `CFile` acesso compor os arquivos.  
  
 [CSocketFile](../mfc/reference/csocketfile-class.md)  
 Fornece um `CFile` interface para um soquete do Windows.  
  
## <a name="related-classes"></a>Classes relacionadas  
 [CArchive](../mfc/reference/carchive-class.md)  
 Coopera com um `CFile` objeto para implementar o armazenamento persistente de objetos por meio de serialização (consulte [CObject::Serialize](../mfc/reference/cobject-class.md#serialize)).  
  
 [CArchiveException](../mfc/reference/carchiveexception-class.md)  
 Uma exceção de arquivo morto.  
  
 [CFileException](../mfc/reference/cfileexception-class.md)  
 Uma exceção orientados a arquivos.  
  
 [CFileDialog](../mfc/reference/cfiledialog-class.md)  
 Fornece uma caixa de diálogo padrão para abrir ou salvar um arquivo.  
  
 [CRecentFileList](../mfc/reference/crecentfilelist-class.md)  
 Mantém a lista de arquivos (MRU) usados mais recentemente.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

