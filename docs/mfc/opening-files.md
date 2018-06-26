---
title: Abrindo arquivos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Open member functions [MFC]
- CFile class [MFC], variable
- opening files, in MFC
- Open calls [MFC]
- Open method, CFile class [MFC]
- examples [MFC], opening files
- opening files, handling exceptions
- exception handling [MFC], when opening files
- files [MFC], opening
- file objects [MFC]
- MFC, file operations
- opening files [MFC]
- exception handling [MFC], opening files
ms.assetid: a991b8ec-b04a-4766-b47e-7485b5dd0b01
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3ba12cce799d0d1ed9a02f3a4d3a268ca86d4447
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36931561"
---
# <a name="opening-files"></a>Abrindo arquivos
Em MFC, a maneira mais comum para abrir um arquivo é um processo de duas etapas.  
  
#### <a name="to-open-a-file"></a>Para abrir um arquivo  
  
1.  Crie o objeto de arquivo sem especificar um caminho ou permissão sinalizadores.  
  
     Você normalmente cria um objeto de arquivo, declarando um [CFile](../mfc/reference/cfile-class.md) variável no quadro de pilha.  
  
2.  Chamar o [abrir](../mfc/reference/cfile-class.md#open) função de membro para o objeto de arquivo, fornecendo um caminho e permissão sinalizadores.  
  
     O valor de retorno `Open` será diferente de zero se o arquivo foi aberto com êxito ou 0 se o arquivo especificado não pôde ser aberto. O `Open` função de membro é protótipo da seguinte maneira:  
  
     `virtual BOOL Open( LPCTSTR lpszFileName, UINT nOpenFlags, CFileException* pError = NULL );`  
  
     Os sinalizadores de abrir especificar quais permissões, como somente leitura, você deseja para o arquivo. Os valores possíveis de sinalizador são definidos como constantes enumeradas dentro de `CFile` de classe, para que sejam qualificados com "`CFile::`" como no `CFile::modeRead`. Use o `CFile::modeCreate` sinalizador se você deseja criar o arquivo.  
  
 O exemplo a seguir mostra como criar um novo arquivo com permissão de leitura/gravação (substituindo qualquer arquivo anterior com o mesmo caminho):  
  
 [!code-cpp[NVC_MFCFiles#1](../atl-mfc-shared/reference/codesnippet/cpp/opening-files_1.cpp)]  
  
> [!NOTE]
>  Este exemplo cria e abre um arquivo. Se houver problemas, o `Open` chamada possa retornar um `CFileException` do objeto no último parâmetro, conforme mostrado aqui. A macro de rastreamento imprime o nome de arquivo e um código que indica o motivo da falha. Você pode chamar o `AfxThrowFileException` funcionar se você precisar de mais detalhadas que o relatório de erros.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CFile](../mfc/reference/cfile-class.md)   
 [CFile::Open](../mfc/reference/cfile-class.md#open)   
 [Arquivos](../mfc/files-in-mfc.md)

