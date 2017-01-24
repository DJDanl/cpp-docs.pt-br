---
title: "Serializando dados para e de arquivos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "dados [MFC]"
  - "dados [MFC], serializando"
  - "desserialização [C++]"
  - "dados de documento [C++]"
  - "documentos [C++], salvar"
  - "documentos [C++], serialização"
  - "salvando documentos"
  - "serialização [C++], função de dados"
  - "serialização [C++], função de documento"
ms.assetid: b42a0c68-4bc4-4012-9938-5433a26d2c24
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Serializando dados para e de arquivos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A exibição básica de persistência é que um objeto deve poder gravar seu estado atual, indicada pelos valores de suas variáveis de membro, ao armazenamento persistente.  Posteriormente, o objeto pode ser recriado ler, ou desserialização “,” o estado do objeto de armazenamento persistente.  Um ponto\-chave aqui é que o próprio objeto é responsável para ler e escrever seu próprio estado.  Assim, para que uma classe é persistente, implemente as operações básicas de serialização.  
  
 A estrutura fornece uma implementação padrão para salvar documentos em arquivos de disco em resposta à salvar e a salvar como comandos no menu arquivo e para carregar documentos de arquivos em disco em resposta ao comando aberto.  Com muito pouco trabalho, você pode implementar a capacidade de um documento de gravar e à leitura seus dados para e de um arquivo.  O elemento principal que você deve fazer é substituir a função de membro de [Serializar](../Topic/CObject::Serialize.md) em sua classe do documento.  
  
 O assistente de aplicativo MFC coloca uma substituição esqueletal da função de membro `Serialize` de **CDocument** na classe do documento que você cria para.  Depois que você implementou variáveis de membro do seu aplicativo, você poderá preencher sua substituição de `Serialize` com código que envia os dados “em um objeto arquivo morto” conectado a um arquivo.  Um objeto de [CArchive](../mfc/reference/carchive-class.md) é semelhante aos objetos de entrada\/saída de `cin` e de `cout` de biblioteca iostream C\+\+.  No entanto, `CArchive` grava e ler o formato binário, não texto formatado.  
  
## Que você deseja saber mais?  
  
-   [Série](../Topic/Serialization%20in%20MFC.md)  
  
-   [A função do documento na serialização](#_core_the_document.92.s_role_in_serialization)  
  
-   [A função de dados na serialização](#_core_the_data.92.s_role_in_serialization)  
  
-   [Ignorando o mecanismo de serialização](../mfc/bypassing-the-serialization-mechanism.md)  
  
##  <a name="_core_the_document.92.s_role_in_serialization"></a> A função do documento na serialização  
 A estrutura responde automaticamente a Abrir, a salva, e a salva no menu arquivo como comandos chamando a função de membro de `Serialize` do documento se for implementada.  Um comando de `ID_FILE_OPEN` , por exemplo, chama uma função de manipulador no objeto de aplicativo.  Durante esse processo, o usuário verá e responde à caixa de diálogo abrir Arquivo e a estrutura obtém o nome de arquivo escolhido pelo usuário.  A estrutura cria uma configuração de objeto de `CArchive` para carregar dados no documento e passa o arquivo morto a `Serialize`.  A estrutura tem aberto o arquivo.  O código da função de membro de `Serialize` do documento ler os dados no por meio de arquivo, recriando objetos de dados quando necessário.  Para obter mais informações sobre a serialização, consulte o artigo [Serialização](../Topic/Serialization%20in%20MFC.md).  
  
##  <a name="_core_the_data.92.s_role_in_serialization"></a> A função de dados na serialização  
 Em geral, os dados do tipo devem poder serializar\-se classe.  Ou seja, quando você passa um objeto em um arquivo, o objeto deve saber como escrever\-se ao arquivo morto e ler\-se de arquivo morto.  MFC O fornece suporte para fazer classes serializáveis dessa maneira.  Se você criar uma classe para definir um tipo de dados e você pretende serializar dados desse tipo, para criar a serialização.  
  
## Consulte também  
 [Usando documentos](../mfc/using-documents.md)