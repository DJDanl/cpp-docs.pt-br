---
title: 'Contêineres: Arquivos compostos'
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
ms.openlocfilehash: cc34f5ed32ee48d538b67cab080b0a52b2e00ae8
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69508883"
---
# <a name="containers-compound-files"></a>Contêineres: Arquivos compostos

Este artigo explica os componentes e a implementação de arquivos compostos, bem como as vantagens e desvantagens de usar arquivos compostos em seus aplicativos OLE.

Os arquivos compostos são parte integrante do OLE. Eles são usados para facilitar a transferência de dados e o armazenamento de documentos OLE. Os arquivos compostos são uma implementação do modelo de armazenamento estruturado ativo. Existem interfaces consistentes que dão suporte à serialização para um armazenamento, um fluxo ou um objeto de arquivo. Os arquivos compostos têm suporte no biblioteca MFC pelas classes `COleStreamFile` e. `COleDocument`

> [!NOTE]
>  O uso de um arquivo composto não implica que as informações sejam provenientes de um documento OLE ou de um documento composto. Os arquivos compostos são apenas uma das maneiras de armazenar documentos compostos, documentos OLE e outros dados.

##  <a name="_core_components_of_a_compound_file"></a>Componentes de um arquivo composto

A implementação OLE de arquivos compostos usa três tipos de objeto: objetos de fluxo, objetos de `ILockBytes` armazenamento e objetos. Esses objetos são semelhantes aos componentes de um sistema de arquivos padrão das seguintes maneiras:

- Transmita objetos, como arquivos, armazene dados de qualquer tipo.

- Objetos de armazenamento, como diretórios, podem conter outros objetos de armazenamento e de fluxo.

- `LockBytes`os objetos representam a interface entre os objetos de armazenamento e o hardware físico. Eles determinam como os bytes reais são gravados em qualquer dispositivo `LockBytes` de armazenamento que o objeto está acessando, como um disco rígido ou uma área da memória global. Para obter mais informações `LockBytes` sobre objetos e `ILockBytes` a interface, consulte a *referência do programador de OLE*.

##  <a name="_core_advantages_and_disadvantages_of_compound_files"></a>Vantagens e desvantagens de arquivos compostos

Os arquivos compostos fornecem benefícios não disponíveis com os métodos anteriores de armazenamento de arquivos. Entre elas estão:

- Acesso incremental a arquivos.

- Modos de acesso ao arquivo.

- Padronização da estrutura de arquivos.

As possíveis desvantagens dos arquivos compostos — grandes problemas de tamanho e desempenho relacionados ao armazenamento em disquetes — devem ser consideradas ao decidir se devem ser usados em seu aplicativo.

###  <a name="_core_incremental_access_to_files"></a>Acesso incremental a arquivos

O acesso incremental a arquivos é um benefício automático do uso de arquivos compostos. Como um arquivo composto pode ser exibido como um "sistema de arquivos em um arquivo", os tipos de objeto individuais, como fluxo ou armazenamento, podem ser acessados sem a necessidade de carregar todo o arquivo. Isso pode diminuir drasticamente o tempo que um aplicativo precisa para acessar novos objetos para edição pelo usuário. A atualização incremental, com base no mesmo conceito, oferece benefícios semelhantes. Em vez de salvar o arquivo inteiro apenas para salvar as alterações feitas em um objeto, o OLE salva apenas o fluxo ou o objeto de armazenamento editado pelo usuário.

###  <a name="_core_file_access_modes"></a>Modos de acesso ao arquivo

Ser capaz de determinar quando as alterações em objetos em um arquivo composto são confirmadas em disco é outro benefício de usar arquivos compostos. O modo em que os arquivos são acessados, transacionado ou direto, determina quando as alterações são confirmadas.

- O modo transacionado usa uma operação de confirmação de duas fases para fazer alterações em objetos em um arquivo composto, mantendo assim as cópias antigas e novas do documento disponíveis até que o usuário escolha salvar ou desfazer as alterações.

- O modo direto incorpora alterações ao documento conforme elas são feitas, sem a capacidade de desfazê-las posteriormente.

Para obter mais informações sobre modos de acesso, consulte a *referência do programador de OLE*.

###  <a name="_core_standardization"></a>Padronização

A estrutura padronizada de arquivos compostos permite que diferentes aplicativos OLE naveguem por meio de arquivos compostos criados por seu aplicativo OLE sem conhecimento do aplicativo que realmente criou o arquivo.

###  <a name="_core_size_and_performance_considerations"></a>Considerações sobre tamanho e desempenho

Devido à complexidade da estrutura de armazenamento de arquivos compostos e à capacidade de salvar os dados de forma incremental, os arquivos que usam esse formato tendem a ser maiores que outros arquivos usando o armazenamento não estruturado ou "arquivo simples". Se seu aplicativo costuma carregar e salvar arquivos, usar arquivos compostos pode fazer com que o tamanho do arquivo aumente muito mais rapidamente do que arquivos não compostos. Como os arquivos compostos podem ser grandes, o tempo de acesso para arquivos armazenados e carregados de disquetes também pode ser afetado, resultando em um acesso mais lento aos arquivos.

Outro problema que afeta o desempenho é a fragmentação do arquivo composto. O tamanho de um arquivo composto é determinado pela diferença entre o primeiro e o último setores de disco usados pelo arquivo. Um arquivo fragmentado pode conter muitas áreas de espaço livre que não contêm dados, mas são contados ao calcular o tamanho. Durante o tempo de vida de um arquivo composto, essas áreas são criadas pela inserção ou exclusão de objetos de armazenamento.

##  <a name="_core_using_compound_files_format_for_your_data"></a>Usando o formato de arquivos compostos para seus dados

Depois de criar com êxito um aplicativo que tem uma classe de documento `COleDocument`derivada de, verifique se o construtor do `EnableCompoundFile`documento principal chama. Quando o assistente de aplicativo cria aplicativos de contêiner OLE, essa chamada é inserida para você.

Na *referência do programador de OLE*, consulte [IStream](/windows/win32/api/objidl/nn-objidl-istream), [IStorage](/windows/win32/api/objidl/nn-objidl-istorage)e [ILockBytes](/windows/win32/api/objidl/nn-objidl-ilockbytes).

## <a name="see-also"></a>Consulte também

[Contêineres](../mfc/containers.md)<br/>
[Contêineres: problemas da interface do usuário](../mfc/containers-user-interface-issues.md)<br/>
[Classe COleStreamFile](../mfc/reference/colestreamfile-class.md)<br/>
[Classe COleDocument](../mfc/reference/coledocument-class.md)
