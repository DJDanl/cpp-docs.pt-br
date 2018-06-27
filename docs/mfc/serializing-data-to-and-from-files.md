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
ms.openlocfilehash: 49553c785e450114698efeb4472ce2d15e6ae422
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36956110"
---
# <a name="serializing-data-to-and-from-files"></a>Serializando dados para e de arquivos
A ideia básica de persistência é que um objeto deve ser capaz de gravar o estado atual, indicado pelos valores de suas variáveis de membro, para o armazenamento persistente. Posteriormente, o objeto pode ser recriado lendo ou "desserialização", o estado do objeto de armazenamento persistente. Um ponto importante aqui é que o próprio objeto é responsável por ler e gravar seu próprio estado. Portanto, para uma classe persistente, ele deve implementar as operações básicas de serialização.  
  
 O framework fornece uma implementação padrão para salvar documentos em arquivos de disco em resposta a salvar e salvar como comandos no menu Arquivo e para carregar documentos de arquivos em disco em resposta ao comando aberto. Com pouquíssimo trabalho, você pode implementar a capacidade de gravar e ler os dados para e de um arquivo do documento. O principal você deve fazer é substituir a [Serialize](../mfc/reference/cobject-class.md#serialize) função de membro em sua classe de documento.  
  
 O Assistente de aplicativo MFC coloca uma substituição de esqueleto do `CDocument` função de membro `Serialize` na classe de documento, ele cria para você. Depois de implementar as variáveis de membro do seu aplicativo, você pode preencher o `Serialize` Substituir pelo código que envia os dados para um "objeto de arquivo morto" conectado a um arquivo. Um [CArchive](../mfc/reference/carchive-class.md) objeto é semelhante do **cin** e **cout** objetos da biblioteca iostream C++ de entrada/saída. No entanto, `CArchive` gravações e leituras de formato binário, o texto não formatado.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Serialização](../mfc/serialization-in-mfc.md)  
  
-   [Função do documento na serialização](#_core_the_document.92.s_role_in_serialization)  
  
-   [Função dos dados na serialização](#_core_the_data.92.s_role_in_serialization)  
  
-   [Ignorando o mecanismo de serialização](../mfc/bypassing-the-serialization-mechanism.md)  
  
##  <a name="_core_the_document.92.s_role_in_serialization"></a> Função do documento na serialização  
 A estrutura automaticamente responde a abrir do menu Arquivo, salvar e salvar como comandos chamando o documento `Serialize` função de membro, se ele é implementado. Um comando ID_FILE_OPEN, por exemplo, chama uma função de manipulador no objeto application. Durante esse processo, o usuário verá e responde à caixa de diálogo Abrir arquivo e o framework obtém o nome do arquivo que o usuário escolhe. Cria a estrutura de um `CArchive` objeto configuradas para carregar dados para o documento e passa o arquivo para `Serialize`. A estrutura já abriu o arquivo. O código no seu documento `Serialize` função membro lê os dados por meio de arquivamento, reconstruir os objetos de dados conforme necessário. Para obter mais informações sobre serialização, consulte o artigo [serialização](../mfc/serialization-in-mfc.md).  
  
##  <a name="_core_the_data.92.s_role_in_serialization"></a> Função dos dados na serialização  
 Em geral, os dados de tipo de classe devem ser capazes de serializar ele mesmo. Ou seja, quando você passar um objeto para um arquivo morto, o objeto deve saber como gravar no arquivo em si e como ler em si do arquivo morto. MFC oferece suporte à criação de classes serializável dessa maneira. Se você criar uma classe para definir um tipo de dados e que deseja serializar dados desse tipo, o design para serialização.  
  
## <a name="see-also"></a>Consulte também  
 [Usando documentos](../mfc/using-documents.md)

