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
ms.openlocfilehash: f47cac34f6cdbdae01af98ec28be5af17edf0e25
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620958"
---
# <a name="bypassing-the-serialization-mechanism"></a>Fazendo bypass do mecanismo de serialização

Como você viu, a estrutura fornece uma maneira padrão de ler e gravar dados de e para arquivos. A serialização por meio de um objeto de arquivo é adequada às necessidades de muitos aplicativos. Esse aplicativo lê totalmente um arquivo na memória, permite que o usuário atualize o arquivo e, em seguida, grave a versão atualizada no disco novamente.

No entanto, alguns aplicativos operam em dados de maneira muito diferente e, para esses aplicativos, a serialização por meio de um arquivo não é adequada. Os exemplos incluem programas de banco de dados, programas que editam apenas partes de arquivos grandes, programas que gravam arquivos somente texto e programas que compartilham arquivos de dados.

Nesses casos, você pode substituir a função [Serialize](reference/cobject-class.md#serialize) de uma maneira diferente de mediar ações de arquivo por meio [de um objeto de](reference/cfile-class.md) retratação em vez de um objeto [CArchive](reference/carchive-class.md) .

Você pode usar as `Open` `Read` `Write` `Close` funções de membro,,, e `Seek` de classe `CFile` para abrir um arquivo, mover o ponteiro do arquivo (buscar) para um ponto específico no arquivo, ler um registro (um número especificado de bytes) nesse ponto, permitir que o usuário atualize o registro e, em seguida, busque o mesmo ponto novamente e grave o registro de volta no arquivo. A estrutura abrirá o arquivo para você e você poderá usar a `GetFile` função de membro da classe `CArchive` para obter um ponteiro para o `CFile` objeto. Para um uso ainda mais sofisticado e flexível, você pode substituir as funções de membro [OnOpenDocument](reference/cdocument-class.md#onopendocument) e [OnSaveDocument](reference/cdocument-class.md#onsavedocument) da classe `CWinApp` . Para obter mais informações, consulte classe [testcfile](reference/cfile-class.md) na *referência do MFC*.

Nesse cenário, sua `Serialize` substituição não faz nada, a menos que, por exemplo, você queira que ele leia e grave um cabeçalho de arquivo para mantê-lo atualizado quando o documento for fechado.

## <a name="see-also"></a>Consulte também

[Usando documentos](using-documents.md)
