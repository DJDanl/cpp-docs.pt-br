---
title: 'Contêineres: arquivos compostos'
ms.date: 11/04/2016
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
ms.openlocfilehash: 5a8ba0821d92ab41a4b95fb7b2a26da63c1df285
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50643256"
---
# <a name="containers-compound-files"></a>Contêineres: arquivos compostos

Este artigo explica os componentes e a implementação de arquivos compostos e as vantagens e desvantagens de usar arquivos compostos em seus aplicativos OLE.

Arquivos compostos são parte integrante do OLE. Eles são usados para facilitar a transferência de dados e armazenamento de documentos OLE. Arquivos compostos são uma implementação do modelo de armazenamento estruturado Active Directory. Interfaces consistentes existem que oferecem suporte à serialização em um armazenamento, um fluxo ou um objeto de arquivo. Arquivos compostos dá suporte a biblioteca Microsoft Foundation Class pelas classes `COleStreamFile` e `COleDocument`.

> [!NOTE]
>  Usar um arquivo composto não implica que a informação vem de um documento OLE ou um documento composto. Arquivos compostos são apenas uma das maneiras de armazenar documentos compostos, documentos OLE e outros dados.

##  <a name="_core_components_of_a_compound_file"></a> Componentes de um arquivo composto

A implementação arquivos compostos OLE usa três tipos de objetos: objetos de fluxo, os objetos de armazenamento, e `ILockBytes` objetos. Esses objetos são semelhantes aos componentes de um sistema de arquivos padrão das seguintes maneiras:

- Objetos de Stream, como arquivos, armazenam dados de qualquer tipo.

- Objetos de armazenamento, como diretórios, podem conter outros objetos de armazenamento e o fluxo.

- `LockBytes` os objetos representam a interface entre os objetos de armazenamento e o hardware físico. Elas determinam como os bytes reais são gravados em qualquer dispositivo de armazenamento a `LockBytes` acessando o objeto, como um disco rígido ou uma área da memória global. Para obter mais informações sobre `LockBytes` objetos e o `ILockBytes` interface, consulte o *referência do programador OLE*.

##  <a name="_core_advantages_and_disadvantages_of_compound_files"></a> Vantagens e desvantagens de arquivos compostos

Arquivos compostos fornecem benefícios não disponíveis com os métodos anteriores de armazenamento de arquivos. Entre elas estão:

- Acessando arquivos com incremento.

- Modos de acesso de arquivo.

- Padronização da estrutura de arquivos.

Possíveis desvantagens de arquivos compostos — grandes problemas de tamanho e desempenho relacionadas ao armazenamento em disquetes — deve ser considerado quando decidir se deseja usá-los em seu aplicativo.

###  <a name="_core_incremental_access_to_files"></a> Incremental acesso a arquivos

Incremental acesso aos arquivos é um benefício automática de usar arquivos compostos. Como um arquivo composto pode ser visto como um "sistema de arquivos dentro de um arquivo", tipos de objetos individuais, como o fluxo ou armazenamento, podem ser acessados sem a necessidade de carregar o arquivo inteiro. Drasticamente, isso pode diminuir o tempo que um aplicativo precisa acessar os novos objetos para edição pelo usuário. Atualização incremental, com base no mesmo conceito, ofertas de benefícios semelhantes. Em vez de salvar o arquivo inteiro apenas para salvar as alterações feitas a um objeto, o OLE salva apenas o fluxo ou armazenamento de objeto editado pelo usuário.

###  <a name="_core_file_access_modes"></a> Modos de acesso de arquivo

Ser capaz de determinar quando as alterações nos objetos em um arquivo composto são confirmadas para o disco é outro benefício de usar arquivos compostos. O modo no qual arquivos são acessados, transacionado ou direta, determina quando as alterações são confirmadas.

- Modo de transação usa uma operação de confirmação de duas fases para fazer alterações em objetos em um arquivo composto, mantendo as antigas e novas cópias do documento disponível até que o usuário optar por salvar ou desfazer as alterações.

- Modo direto incorpora as alterações no documento, conforme elas são feitas, sem a capacidade de desfazê-los o mais tarde.

Para obter mais informações sobre modos de acesso, consulte o *referência do programador OLE*.

###  <a name="_core_standardization"></a> Padronização

A estrutura padronizada de arquivos compostos permite que diferentes aplicativos OLE navegar pelos arquivos compostos criados pelo seu aplicativo OLE sem o conhecimento do aplicativo que criou o arquivo.

###  <a name="_core_size_and_performance_considerations"></a> Tamanho e as considerações de desempenho

Devido à complexidade da estrutura de armazenamento do arquivo composto e a capacidade de salvar dados de forma incremental, usando esse formato de arquivos tendem a ser maiores que outros arquivos não estruturados usando o ou o armazenamento de "simples de arquivo". Se seu aplicativo com frequência carrega e salva os arquivos, usar arquivos compostos pode causar o tamanho do arquivo aumentar muito mais rapidamente do que arquivos noncompound. Porque arquivos compostos podem ficar grandes, o tempo de acesso para arquivos armazenados em e carregados em disquetes também pode ser afetado, resultando em um acesso mais lento a arquivos.

Outro problema que afeta o desempenho é a fragmentação de arquivo composto. O tamanho de um arquivo composto é determinado pela diferença entre os setores de disco primeiro e último usado pelo arquivo. Um arquivo fragmentado pode conter muitas áreas que não contêm dados, mas são contadas ao calcular o tamanho de espaço livre. Durante o tempo de vida de um arquivo composto, essas áreas são criadas pela inserção ou exclusão de objetos de armazenamento.

##  <a name="_core_using_compound_files_format_for_your_data"></a> Usando o formato de arquivos compostos para seus dados

Depois de criar com êxito um aplicativo que tem uma classe de documento derivada `COleDocument`, certifique-se de que o construtor do seu documento principal chama `EnableCompoundFile`. Quando o Assistente de aplicativo cria aplicativos de contêiner OLE, essa chamada é inserida para você.

No *referência do programador OLE*, consulte [IStream](/windows/desktop/api/objidl/nn-objidl-istream), [IStorage](/windows/desktop/api/objidl/nn-objidl-istorage), e [ILockBytes](/windows/desktop/api/objidl/nn-objidl-ilockbytes).

## <a name="see-also"></a>Consulte também

[Contêineres](../mfc/containers.md)<br/>
[Contêineres: problemas da interface do usuário](../mfc/containers-user-interface-issues.md)<br/>
[Classe COleStreamFile](../mfc/reference/colestreamfile-class.md)<br/>
[Classe COleDocument](../mfc/reference/coledocument-class.md)
