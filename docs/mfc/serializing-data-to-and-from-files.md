---
title: Serializando dados para e de arquivos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- documents [MFC], serialization
- documents [MFC], saving
- saving documents
- deserialization [MFC]
- serialization [MFC], role of document
- serialization [MFC], role of data
- data [MFC]
- data [MFC], serializing
- document data [MFC]
ms.assetid: b42a0c68-4bc4-4012-9938-5433a26d2c24
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 65cf6d8944c1b14d6c55ce2c35a257bfa63a3606
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46395382"
---
# <a name="serializing-data-to-and-from-files"></a>Serializando dados para e de arquivos

A ideia básica de persistência é que um objeto deve ser capaz de gravar seu estado atual, indicado pelos valores de suas variáveis de membro, para o armazenamento persistente. Posteriormente, o objeto poderá ser recriado lendo ou "desserializar", o estado do objeto de armazenamento persistente. Um ponto importante aqui é que o próprio objeto é responsável por ler e gravar seu próprio estado. Portanto, para uma classe seja persistente, ele deve implementar as operações de serialização básica.

O framework fornece uma implementação padrão para salvar documentos em arquivos de disco em resposta a salvar e salvar como comandos no menu Arquivo e de carregamento de documentos dos arquivos de disco em resposta ao comando aberto. Com muito pouco trabalho, você pode implementar a capacidade de um documento para gravar e ler seus dados para e de um arquivo. O principal ponto em que você deve fazer é substituir a [Serialize](../mfc/reference/cobject-class.md#serialize) função de membro em sua classe de documento.

O Assistente de aplicativo do MFC coloca uma substituição de esqueleto do `CDocument` função de membro `Serialize` na classe de documento, ele cria para você. Depois de implementar as variáveis de membro do seu aplicativo, você pode preencher seu `Serialize` substituir com um código que envia os dados para um "objeto de arquivo morto" conectado a um arquivo. Um [CArchive](../mfc/reference/carchive-class.md) objeto é semelhante ao **cin** e **cout** objetos da biblioteca iostream C++ de entrada/saída. No entanto, `CArchive` gravações e leituras de formato binário, o texto não formatado.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Serialização](../mfc/serialization-in-mfc.md)

- [Função do documento na serialização](#_core_the_document.92.s_role_in_serialization)

- [Função dos dados na serialização](#_core_the_data.92.s_role_in_serialization)

- [Ignorando o mecanismo de serialização](../mfc/bypassing-the-serialization-mechanism.md)

##  <a name="_core_the_document.92.s_role_in_serialization"></a> Função do documento na serialização

A estrutura automaticamente responde a abrir do menu Arquivo, salvar e salvar como comandos chamando o documento `Serialize` função de membro se ele é implementado. Um comando ID_FILE_OPEN, por exemplo, chama uma função de manipulador no objeto de aplicativo. Durante esse processo, o usuário vê e responde à caixa de diálogo Abrir arquivo e o framework obtém o nome do arquivo que o usuário escolhe. A estrutura cria uma `CArchive` objeto configurada para carregar dados para o documento e passa o arquivo morto para `Serialize`. O framework já abriu o arquivo. O código no seu documento `Serialize` função de membro lê os dados por meio do arquivo morto, reconstruir os objetos de dados conforme necessário. Para obter mais informações sobre serialização, consulte o artigo [serialização](../mfc/serialization-in-mfc.md).

##  <a name="_core_the_data.92.s_role_in_serialization"></a> Função dos dados na serialização

Em geral, os dados de tipo de classe devem ser capazes de serializar-se. Ou seja, quando você passa um objeto para um arquivo morto, o objeto deve saber como gravar a mesmo para o arquivo morto e como ler em si do arquivo morto. MFC oferece suporte à criação de classes serializáveis dessa maneira. Se você criar uma classe para definir um tipo de dados e você deseja serializar os dados desse tipo, o design para a serialização.

## <a name="see-also"></a>Consulte também

[Usando documentos](../mfc/using-documents.md)

