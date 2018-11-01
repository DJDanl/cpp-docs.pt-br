---
title: Abrindo arquivos
ms.date: 11/04/2016
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
ms.openlocfilehash: a29485b8258503682d59abb51dcfa72e383f0b8c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50577704"
---
# <a name="opening-files"></a>Abrindo arquivos

No MFC, a maneira mais comum para abrir um arquivo é um processo de duas etapas.

#### <a name="to-open-a-file"></a>Para abrir um arquivo

1. Crie o objeto de arquivo sem especificar um caminho ou permissão sinalizadores.

   Você normalmente cria um objeto de arquivo, declarando uma [CFile](../mfc/reference/cfile-class.md) variável no quadro da pilha.

1. Chame o [abrir](../mfc/reference/cfile-class.md#open) função de membro para o objeto de arquivo, fornecendo um caminho e permissão sinalizadores.

   O valor de retorno para `Open` será diferente de zero se o arquivo foi aberto com êxito ou 0 se o arquivo especificado não pôde ser aberto. O `Open` função de membro é o seguinte protótipo:

   `virtual BOOL Open( LPCTSTR lpszFileName, UINT nOpenFlags, CFileException* pError = NULL );`

   Os sinalizadores de abrir especificam quais permissões, como somente leitura, você deseja para o arquivo. Os valores possíveis de sinalizador são definidos como constantes enumeradas dentro de `CFile` classe, portanto, eles são qualificados com "`CFile::`" como em `CFile::modeRead`. Use o `CFile::modeCreate` sinalizador se você quiser criar o arquivo.

O exemplo a seguir mostra como criar um novo arquivo com permissão de leitura/gravação (substituindo qualquer arquivo anterior com o mesmo caminho):

[!code-cpp[NVC_MFCFiles#1](../atl-mfc-shared/reference/codesnippet/cpp/opening-files_1.cpp)]

> [!NOTE]
>  Este exemplo cria e abre um arquivo. Se houver problemas, o `Open` chamada possa retornar um `CFileException` do objeto em seu último parâmetro, conforme mostrado aqui. A macro TRACE imprime o nome do arquivo e um código que indica o motivo da falha. Você pode chamar o `AfxThrowFileException` funcionar se você precisar de mais detalhadas de relatório de erros.

## <a name="see-also"></a>Consulte também

[Classe CFile](../mfc/reference/cfile-class.md)<br/>
[CFile::Open](../mfc/reference/cfile-class.md#open)<br/>
[Arquivos](../mfc/files-in-mfc.md)

