---
title: "Ignorando o mecanismo de serialização | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- archive objects [MFC]
- bypassing serialization
- archives [MFC], serialization
- serialization [MFC], bypassing
- archives [MFC]
- serialization [MFC], role of framework
- serialization [MFC], overriding
ms.assetid: 48d4a279-b51c-4ba5-81cd-ed043312b582
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: b0beb14c2ddb159616f7cbb34b83b68e84ef0a1e
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="bypassing-the-serialization-mechanism"></a>Fazendo bypass do mecanismo de serialização
Como vimos, o framework fornece uma maneira de padrão para ler e gravar dados para e de arquivos. Serializando por meio de um objeto de arquivo morto adequado às necessidades de uma grande muitos aplicativos. Esse aplicativo lê um arquivo inteiramente na memória, permite que o usuário atualizar o arquivo e, em seguida, grava a versão atualizada para o disco novamente.  
  
 No entanto, alguns aplicativos operam em dados de forma muito diferente, e serialização por meio de um arquivo morto não é adequada para esses aplicativos. Exemplos incluem programas de banco de dados, programas que editar somente as partes de arquivos grandes, programas que gravam arquivos de texto e programas que compartilham arquivos de dados.  
  
 Nesses casos, você pode substituir o [Serialize](../mfc/reference/cobject-class.md#serialize) função de forma diferente para mediar as ações de arquivo por meio de um [CFile](../mfc/reference/cfile-class.md) objeto em vez de [CArchive](../mfc/reference/carchive-class.md) objeto.  
  
 Você pode usar o **abrir**, **leitura**, **gravar**, **fechar**, e `Seek` funções membro de classe `CFile` para abrir um arquivo , mova o ponteiro de arquivo (busca) para um ponto específico no arquivo, leia um registro (um número especificado de bytes) nesse ponto, permitem a atualização do usuário no registro, em seguida, busca no mesmo ponto novamente e a gravação de registro de volta para o arquivo. A estrutura irá abrir o arquivo para você, e você pode usar o `GetFile` função de membro de classe `CArchive` para obter um ponteiro para o `CFile` objeto. Para usar ainda mais sofisticado e flexível, você pode substituir o [OnOpenDocument](../mfc/reference/cdocument-class.md#onopendocument) e [OnSaveDocument](../mfc/reference/cdocument-class.md#onsavedocument) funções membro de classe `CWinApp`. Para obter mais informações, consulte a classe [CFile](../mfc/reference/cfile-class.md) no *referência MFC*.  
  
 Nesse cenário, sua `Serialize` substituição não faz nada, a menos que, por exemplo, você deseja que ele seja de leitura e gravação a um cabeçalho de arquivo para manter atualizado quando o documento é fechado.  
  
## <a name="see-also"></a>Consulte também  
 [Usando documentos](../mfc/using-documents.md)

