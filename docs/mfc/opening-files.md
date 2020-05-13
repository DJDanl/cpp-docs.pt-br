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
ms.openlocfilehash: 6119bf922b05c30a14d8421800e3931c4a038779
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375954"
---
# <a name="opening-files"></a>Abrindo arquivos

No MFC, a maneira mais comum de abrir um arquivo é um processo em duas etapas.

#### <a name="to-open-a-file"></a>Para abrir um arquivo

1. Crie o objeto de arquivo sem especificar um caminho ou sinalizadores de permissão.

   Você geralmente cria um objeto de arquivo declarando uma variável [CFile](../mfc/reference/cfile-class.md) no quadro stack.

1. Ligue [para](../mfc/reference/cfile-class.md#open) a função Open member para o objeto de arquivo, fornecendo um caminho e sinalizadores de permissão.

   O valor `Open` de devolução será não zero se o arquivo foi aberto com sucesso ou 0 se o arquivo especificado não puder ser aberto. A `Open` função do membro é protótipo da seguinte forma:

   `virtual BOOL Open( LPCTSTR lpszFileName, UINT nOpenFlags, CFileException* pError = NULL );`

   Os sinalizadores abertos especificam quais permissões, como somente leitura, você deseja para o arquivo. Os possíveis valores da bandeira são definidos como constantes enumeradas dentro da `CFile` classe, de modo que eles são qualificados com "`CFile::`" como em `CFile::modeRead`. Use `CFile::modeCreate` o sinalizador se quiser criar o arquivo.

O exemplo a seguir mostra como criar um novo arquivo com permissão de leitura/gravação (substituindo qualquer arquivo anterior pelo mesmo caminho):

[!code-cpp[NVC_MFCFiles#1](../atl-mfc-shared/reference/codesnippet/cpp/opening-files_1.cpp)]

> [!NOTE]
> Este exemplo cria e abre um arquivo. Se houver problemas, a `Open` `CFileException` chamada pode retornar um objeto em seu último parâmetro, como mostrado aqui. A macro TRACE imprime o nome do arquivo e um código que indica a razão da falha. Você pode `AfxThrowFileException` ligar para a função se precisar de relatórios de erro mais detalhados.

## <a name="see-also"></a>Confira também

[Classe CFile](../mfc/reference/cfile-class.md)<br/>
[Arquivo::Abrir](../mfc/reference/cfile-class.md#open)<br/>
[Arquivos](../mfc/files-in-mfc.md)
