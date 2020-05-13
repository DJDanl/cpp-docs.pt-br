---
title: Serializando dados para e de arquivos
ms.date: 11/04/2016
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
ms.openlocfilehash: 043ba019c6b5ad79db2cedb6314c9e65f14b14b5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376930"
---
# <a name="serializing-data-to-and-from-files"></a>Serializando dados para e de arquivos

A ideia básica de persistência é que um objeto deve ser capaz de escrever seu estado atual, indicado pelos valores de suas variáveis membros, para o armazenamento persistente. Mais tarde, o objeto pode ser recriado lendo ou "desserializando", o estado do objeto a partir do armazenamento persistente. Um ponto-chave aqui é que o objeto em si é responsável pela leitura e escrita de seu próprio estado. Assim, para que uma classe seja persistente, deve implementar as operações básicas de serialização.

A estrutura fornece uma implementação padrão para salvar documentos em arquivos de disco em resposta aos comandos Salvar e Salvar Como no menu Arquivo e para carregar documentos de arquivos de disco em resposta ao comando Abrir. Com muito pouco trabalho, você pode implementar a capacidade de um documento de escrever e ler seus dados de e para um arquivo. A principal coisa que você deve fazer é substituir a função de membro [Serialize](../mfc/reference/cobject-class.md#serialize) em sua classe de documentos.

O Assistente de Aplicativo do MFC coloca `CDocument` uma `Serialize` substituição esquelética da função de membro na classe de documento que ela cria para você. Depois de implementar as variáveis de membro do aplicativo, você pode preencher sua `Serialize` substituição com código que envia os dados para um "objeto de arquivamento" conectado a um arquivo. Um objeto [CArchive](../mfc/reference/carchive-class.md) é semelhante aos objetos de entrada/saída **de cin** e **cout** da biblioteca de iostream C++. No `CArchive` entanto, grava e lê formato binário, não texto formatado.

## <a name="what-do-you-want-to-know-more-about"></a>O que você quer saber mais sobre

- [Serialização](../mfc/serialization-in-mfc.md)

- [O papel do documento na serialização](#_core_the_document.92.s_role_in_serialization)

- [O papel dos dados na serialização](#_core_the_data.92.s_role_in_serialization)

- [Contornando o mecanismo de serialização](../mfc/bypassing-the-serialization-mechanism.md)

## <a name="the-documents-role-in-serialization"></a><a name="_core_the_document.92.s_role_in_serialization"></a>O papel do documento na serialização

O framework responde automaticamente aos comandos Open, Save e Save As do menu `Serialize` de arquivos, chamando a função de membro do documento se for implementada. Um comando ID_FILE_OPEN, por exemplo, chama uma função de manipulador no objeto do aplicativo. Durante esse processo, o usuário vê e responde à caixa de diálogo Abrir arquivos e a estrutura obtém o nome de arquivo que o usuário escolhe. A estrutura `CArchive` cria um objeto configurado para carregar dados `Serialize`no documento e passa o arquivo para . A estrutura já abriu o arquivo. O código na função `Serialize` de membro do documento lê os dados através do arquivo, reconstruindo objetos de dados conforme necessário. Para obter mais informações sobre serialização, consulte o artigo [Serialização](../mfc/serialization-in-mfc.md).

## <a name="the-datas-role-in-serialization"></a><a name="_core_the_data.92.s_role_in_serialization"></a>O papel dos dados na serialização

Em geral, os dados do tipo de classe devem ser capazes de se serializar. Ou seja, quando você passa um objeto para um arquivo, o objeto deve saber como escrever-se para o arquivo e como ler-se a partir do arquivo. O MFC oferece suporte para tornar as classes serializáveis desta forma. Se você projetar uma classe para definir um tipo de dados e pretende serializar dados desse tipo, projete para serialização.

## <a name="see-also"></a>Confira também

[Usando documentos](../mfc/using-documents.md)
