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
ms.openlocfilehash: 73407eba802b7640e880b821144954fa6442f177
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84622157"
---
# <a name="opening-files"></a>Abrindo arquivos

No MFC, a maneira mais comum de abrir um arquivo é um processo de duas etapas.

#### <a name="to-open-a-file"></a>Para abrir um arquivo

1. Crie o objeto de arquivo sem especificar um caminho ou sinalizadores de permissão.

   Normalmente, você cria um objeto de arquivo declarando uma variável [testcfile](reference/cfile-class.md) no registro de ativação.

1. Chame a função de membro [Open](reference/cfile-class.md#open) para o objeto File, fornecendo um caminho e sinalizadores de permissão.

   O valor de retorno para `Open` será diferente de zero se o arquivo tiver sido aberto com êxito ou 0 se o arquivo especificado não puder ser aberto. A `Open` função de membro é protótipo da seguinte maneira:

   `virtual BOOL Open( LPCTSTR lpszFileName, UINT nOpenFlags, CFileException* pError = NULL );`

   Os sinalizadores abertos especificam quais permissões, como somente leitura, você deseja para o arquivo. Os valores de sinalizador possíveis são definidos como constantes enumeradas dentro da `CFile` classe, portanto, eles são qualificados com " `CFile::` " como em `CFile::modeRead` . Use o `CFile::modeCreate` sinalizador se você quiser criar o arquivo.

O exemplo a seguir mostra como criar um novo arquivo com permissão de leitura/gravação (substituindo qualquer arquivo anterior com o mesmo caminho):

[!code-cpp[NVC_MFCFiles#1](../atl-mfc-shared/reference/codesnippet/cpp/opening-files_1.cpp)]

> [!NOTE]
> Este exemplo cria e abre um arquivo. Se houver problemas, a `Open` chamada poderá retornar um `CFileException` objeto em seu último parâmetro, como mostrado aqui. A macro de rastreamento imprime o nome do arquivo e um código que indica o motivo da falha. Você pode chamar a `AfxThrowFileException` função se precisar de relatórios de erros mais detalhados.

## <a name="see-also"></a>Consulte também

[Classe CFile](reference/cfile-class.md)<br/>
[Testcfile:: abrir](reference/cfile-class.md#open)<br/>
[Arquivos](files-in-mfc.md)
