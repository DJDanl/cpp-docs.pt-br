---
title: 'Contêineres: Composta arquivos | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- compound files [MFC]
- compound documents
- containers [MFC], compound files
- OLE documents [MFC], compound files
- performance [MFC], compound files
- files [MFC], compound
- standardized file structure compound files
- documents [MFC], compound
- documents [MFC], OLE
- OLE containers [MFC], compound files
- access modes for files [MFC]
ms.assetid: 8b83cb3e-76c8-4bbe-ba16-737092b36f49
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a8bee847d1121a6d5da1679c29a9107c8a447ab1
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36930219"
---
# <a name="containers-compound-files"></a>Contêineres: arquivos compostos
Este artigo explica os componentes e a implementação de arquivos compostos e as vantagens e desvantagens do uso de arquivos compostos em seus aplicativos de OLE.  
  
 Arquivos compostos são parte integrante de OLE. Eles são usados para facilitar a transferência de dados e armazenamento de documentos OLE. Arquivos compostos são uma implementação do modelo de armazenamento estruturado ativo. Interfaces consistentes existem que oferecem suporte à serialização de armazenamento, um fluxo ou um objeto de arquivo. Arquivos compostos têm suporte na biblioteca de classes Microsoft Foundation pelas classes `COleStreamFile` e `COleDocument`.  
  
> [!NOTE]
>  Usar um arquivo composto não implica que a informação vem de um documento OLE ou um documento composto. Arquivos compostos são apenas uma das maneiras de armazenar documentos compostos, documentos OLE e outros dados.  
  
##  <a name="_core_components_of_a_compound_file"></a> Componentes de um arquivo composto  
 A implementação de OLE de arquivos compostos usa três tipos de objetos: objetos de fluxo, objetos de armazenamento e `ILockBytes` objetos. Esses objetos são semelhantes aos componentes de um sistema de arquivos padrão das seguintes maneiras:  
  
-   Objetos de fluxo, como arquivos, armazenam dados de qualquer tipo.  
  
-   Objetos de armazenamento, como pastas, podem conter outros objetos de armazenamento e o fluxo.  
  
-   `LockBytes` os objetos representam a interface entre os objetos de armazenamento e o hardware físico. Elas determinam como os bytes reais são gravados para qualquer dispositivo de armazenamento do `LockBytes` acessa o objeto, como um disco rígido ou uma área da memória global. Para obter mais informações sobre `LockBytes` objetos e o `ILockBytes` interface, consulte o *referência do programador de OLE*.  
  
##  <a name="_core_advantages_and_disadvantages_of_compound_files"></a> Vantagens e desvantagens de arquivos compostos  
 Arquivos compostos fornecem benefícios não está disponíveis com os métodos anteriores de armazenamento de arquivos. Entre elas estão:  
  
-   Acessando arquivos incremental.  
  
-   Modos de acesso do arquivo.  
  
-   Padronização da estrutura de arquivo.  
  
 Possíveis desvantagens de arquivos compostos — grandes problemas de tamanho e desempenho relacionadas ao armazenamento em disquetes — deve ser considerado quando decidir se deseja usá-los em seu aplicativo.  
  
###  <a name="_core_incremental_access_to_files"></a> Incremental acesso a arquivos  
 Incremental acesso aos arquivos é um benefício automática do uso de arquivos compostos. Como um arquivo composto pode ser visto como um "sistema de arquivos dentro de um arquivo", tipos de objetos individuais, como fluxo ou armazenamento, podem ser acessados sem a necessidade de carregar o arquivo inteiro. Isso drasticamente pode diminuir o tempo que um aplicativo precisa acessar novos objetos para edição pelo usuário. Atualização incremental, com base no mesmo conceito, oferece benefícios de similares. Em vez de salvar o arquivo inteiro apenas para salvar as alterações feitas em um objeto, o OLE salva apenas o fluxo ou armazenamento de objeto editado pelo usuário.  
  
###  <a name="_core_file_access_modes"></a> Modos de acesso a arquivo  
 Ser capaz de determinar quando as alterações nos objetos em um arquivo composto são confirmadas no disco é outro benefício de usar arquivos compostos. O modo no qual arquivos são acessados, transacionado ou direto, determina quando as alterações são confirmadas.  
  
-   Modo de transação usa uma operação de confirmação de duas fases para fazer alterações em objetos em um arquivo composto, mantendo as antigas e novas cópias do documento disponível até que o usuário optar por salvar ou desfazer as alterações.  
  
-   Modo direto incorpora as alterações no documento que elas são feitas, sem a capacidade de desfazê-las posteriormente.  
  
 Para obter mais informações sobre modos de acesso, consulte o *referência do programador de OLE*.  
  
###  <a name="_core_standardization"></a> Padronização  
 A estrutura padronizada de arquivos compostos permite que diferentes aplicativos OLE procurar arquivos compostos criados pelo seu aplicativo OLE sem conhecimento do aplicativo que criou o arquivo.  
  
###  <a name="_core_size_and_performance_considerations"></a> Tamanho e considerações sobre desempenho  
 Devido à complexidade da estrutura de armazenamento de arquivo composto e a capacidade de salvar dados incrementalmente, os arquivos usando esse formato tendem a ser maior do que outros arquivos usando não estruturados ou armazenamento "simples de arquivo". Se seu aplicativo frequentemente carrega e salva arquivos, o uso de arquivos compostos pode causar o tamanho do arquivo aumentar muito mais rapidamente do que os arquivos noncompound. Porque arquivos compostos podem ficar grandes, o tempo de acesso para arquivos armazenados em e carregados de disquetes também pode ser afetado, resultando em um acesso mais lento a arquivos.  
  
 Outro problema que afeta o desempenho é a fragmentação de arquivo composto. O tamanho de um arquivo composto é determinado pela diferença entre os setores de disco primeiro e último usado pelo arquivo. Um arquivo fragmentado pode conter muitas áreas que não contêm dados, mas são contadas ao calcular o tamanho de espaço livre. Durante o tempo de vida de um arquivo composto, essas áreas são criadas pela inserção ou exclusão de objetos de armazenamento.  
  
##  <a name="_core_using_compound_files_format_for_your_data"></a> Usando o formato de arquivos compostos para seus dados  
 Depois de criar com êxito um aplicativo que tem uma classe de documento derivada de `COleDocument`, certifique-se de que seu construtor documento principal chama `EnableCompoundFile`. Quando o Assistente de aplicativo criar aplicativos de contêiner OLE, essa chamada é inserida.  
  
 No *referência do programador de OLE*, consulte [IStream](http://msdn.microsoft.com/library/windows/desktop/aa380034), [IStorage](http://msdn.microsoft.com/library/windows/desktop/aa380015), e [ILockBytes](http://msdn.microsoft.com/library/windows/desktop/aa379238).  
  
## <a name="see-also"></a>Consulte também  
 [Contêineres](../mfc/containers.md)   
 [Contêineres: Problemas de Interface do usuário](../mfc/containers-user-interface-issues.md)   
 [Classe COleStreamFile](../mfc/reference/colestreamfile-class.md)   
 [Classe COleDocument](../mfc/reference/coledocument-class.md)
