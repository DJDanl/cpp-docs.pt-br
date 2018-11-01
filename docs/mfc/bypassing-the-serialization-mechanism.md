---
title: Fazendo bypass do mecanismo de serialização
ms.date: 11/04/2016
helpviewer_keywords:
- archive objects [MFC]
- bypassing serialization
- archives [MFC], serialization
- serialization [MFC], bypassing
- archives [MFC]
- serialization [MFC], role of framework
- serialization [MFC], overriding
ms.assetid: 48d4a279-b51c-4ba5-81cd-ed043312b582
ms.openlocfilehash: 4c76be874752a577aaeb4c3641818f8a2850b465
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50556592"
---
# <a name="bypassing-the-serialization-mechanism"></a>Fazendo bypass do mecanismo de serialização

Como você viu, o framework fornece uma maneira padrão para ler e gravar dados para e de arquivos. Serializando por meio de um objeto de arquivo morto atender às necessidades de uma ótima muitos aplicativos. Esse aplicativo lê um arquivo inteiramente na memória, permite que o usuário atualize o arquivo e, em seguida, grava a versão atualizada em disco novamente.

No entanto, alguns aplicativos operam em dados de forma muito diferente e serialização por meio de um arquivo morto não é adequada para esses aplicativos. Exemplos incluem programas de banco de dados, os programas que editar apenas partes de arquivos grandes, programas que gravar arquivos de texto e programas que compartilham arquivos de dados.

Nesses casos, você pode substituir a [Serialize](../mfc/reference/cobject-class.md#serialize) função de maneira diferente para mediar as ações de arquivo por meio de uma [CFile](../mfc/reference/cfile-class.md) objeto em vez de um [CArchive](../mfc/reference/carchive-class.md) objeto.

Você pode usar o `Open`, `Read`, `Write`, `Close`, e `Seek` funções de membro da classe `CFile` para abrir um arquivo, mova o ponteiro do arquivo (busca) para um ponto específico no arquivo, um registro (um número especificado de bytes de leitura ) neste ponto, permitir que o usuário atualizar o registro, em seguida, buscar novamente para o mesmo ponto e gravar o registro de volta para o arquivo. O framework irá abrir o arquivo para você, e você pode usar o `GetFile` função de membro da classe `CArchive` para obter um ponteiro para o `CFile` objeto. Para uso ainda mais sofisticado e flexível, você pode substituir a [OnOpenDocument](../mfc/reference/cdocument-class.md#onopendocument) e [OnSaveDocument](../mfc/reference/cdocument-class.md#onsavedocument) funções membro da classe `CWinApp`. Para obter mais informações, consulte a classe [CFile](../mfc/reference/cfile-class.md) na *referência da MFC*.

Nesse cenário, sua `Serialize` substituição não faz nada, a menos que, por exemplo, você deseja para que ele seja de leitura e gravação de um cabeçalho de arquivo para mantê-lo atualizado quando o documento é fechado.

## <a name="see-also"></a>Consulte também

[Usando documentos](../mfc/using-documents.md)

