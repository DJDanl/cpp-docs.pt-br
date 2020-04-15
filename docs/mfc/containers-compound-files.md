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
ms.openlocfilehash: 98166a355fd267ecbec0a7f0cc1d18fd0b2e7cd0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81353582"
---
# <a name="containers-compound-files"></a>Contêineres: arquivos compostos

Este artigo explica os componentes e a implementação de arquivos compostos e as vantagens e desvantagens do uso de arquivos compostos em seus aplicativos OLE.

Os arquivos compostos são parte integrante do OLE. Eles são usados para facilitar a transferência de dados e o armazenamento de documentos OLE. Os arquivos compostos são uma implementação do modelo de armazenamento estruturado Ativo. Existem interfaces consistentes que suportam serialização para um armazenamento, um fluxo ou um objeto de arquivo. Os arquivos compostos são suportados na `COleStreamFile` Biblioteca `COleDocument`de Classes da Microsoft Foundation pelas classes e .

> [!NOTE]
> O uso de um arquivo composto não implica que as informações provêm de um documento OLE ou de um documento composto. Os arquivos compostos são apenas uma das maneiras de armazenar documentos compostos, documentos OLE e outros dados.

## <a name="components-of-a-compound-file"></a><a name="_core_components_of_a_compound_file"></a>Componentes de um arquivo composto

A implementação de arquivos compostos do OLE usa `ILockBytes` três tipos de objetos: objetos de fluxo, objetos de armazenamento e objetos. Esses objetos são semelhantes aos componentes de um sistema de arquivos padrão das seguintes maneiras:

- Fluxo de objetos, como arquivos, armazenam dados de qualquer tipo.

- Objetos de armazenamento, como diretórios, podem conter outros objetos de armazenamento e fluxo.

- `LockBytes`objetos representam a interface entre os objetos de armazenamento e o hardware físico. Eles determinam como os bytes reais `LockBytes` são escritos em qualquer dispositivo de armazenamento que o objeto está acessando, como um disco rígido ou uma área de memória global. Para obter `LockBytes` mais informações `ILockBytes` sobre objetos e a interface, consulte a *referência do programador OLE*.

## <a name="advantages-and-disadvantages-of-compound-files"></a><a name="_core_advantages_and_disadvantages_of_compound_files"></a>Vantagens e desvantagens de arquivos compostos

Os arquivos compostos fornecem benefícios não disponíveis com métodos anteriores de armazenamento de arquivos. Elas incluem:

- Acesso incremental a arquivos.

- Modos de acesso a arquivos.

- Padronização da estrutura do arquivo.

As potenciais desvantagens dos arquivos compostos — grandes problemas de tamanho e desempenho relacionados ao armazenamento em disquetes — devem ser consideradas ao decidir se os devem usá-los em seu aplicativo.

### <a name="incremental-access-to-files"></a><a name="_core_incremental_access_to_files"></a>Acesso incremental a arquivos

O acesso incremental aos arquivos é um benefício automático do uso de arquivos compostos. Como um arquivo composto pode ser visto como um "sistema de arquivos dentro de um arquivo", tipos de objetos individuais, como fluxo ou armazenamento, podem ser acessados sem a necessidade de carregar todo o arquivo. Isso pode diminuir drasticamente o tempo que um aplicativo precisa para acessar novos objetos para edição pelo usuário. A atualização incremental, baseada no mesmo conceito, oferece benefícios semelhantes. Em vez de salvar todo o arquivo apenas para salvar as alterações feitas em um objeto, o OLE salva apenas o fluxo ou objeto de armazenamento editado pelo usuário.

### <a name="file-access-modes"></a><a name="_core_file_access_modes"></a>Modos de acesso a arquivos

Ser capaz de determinar quando as alterações de objetos em um arquivo composto são comprometidas com o disco é outro benefício do uso de arquivos compostos. O modo em que os arquivos são acessados, transacionados ou diretos, determina quando as alterações são cometidas.

- O modo transacionado usa uma operação de compromisso em duas fases para fazer alterações em objetos em um arquivo composto, mantendo assim as cópias antigas e novas do documento disponíveis até que o usuário escolha salvar ou desfazer as alterações.

- O modo direto incorpora alterações no documento à medida que são feitas, sem a capacidade de desfazê-las posteriormente.

Para obter mais informações sobre os modos de acesso, consulte a *referência do programador OLE*.

### <a name="standardization"></a><a name="_core_standardization"></a>Padronização

A estrutura padronizada de arquivos compostos permite que diferentes aplicativos OLE naveguem através de arquivos compostos criados pelo seu aplicativo OLE sem conhecimento do aplicativo que realmente criou o arquivo.

### <a name="size-and-performance-considerations"></a><a name="_core_size_and_performance_considerations"></a>Considerações sobre tamanho e desempenho

Devido à complexidade da estrutura de armazenamento de arquivos compostos e à capacidade de salvar dados incrementalmente, os arquivos que usam esse formato tendem a ser maiores do que outros arquivos usando armazenamento não estruturado ou "arquivo plano". Se o aplicativo frequentemente carrega e salva arquivos, o uso de arquivos compostos pode fazer com que o tamanho do arquivo aumente muito mais rapidamente do que os arquivos não compostos. Como os arquivos compostos podem ficar grandes, o tempo de acesso para arquivos armazenados e carregados de disquetes também pode ser afetado, resultando em acesso mais lento aos arquivos.

Outro problema que afeta o desempenho é a fragmentação de arquivos compostos. O tamanho de um arquivo composto é determinado pela diferença entre os primeiros e os últimos setores de disco usados pelo arquivo. Um arquivo fragmentado pode conter muitas áreas de espaço livre que não contêm dados, mas são contadas ao calcular o tamanho. Durante a vida de um arquivo composto, essas áreas são criadas pela inserção ou exclusão de objetos de armazenamento.

## <a name="using-compound-files-format-for-your-data"></a><a name="_core_using_compound_files_format_for_your_data"></a>Usando o formato de arquivos compostos para seus dados

Depois de criar com sucesso um aplicativo `COleDocument`que tenha uma classe `EnableCompoundFile`de documento derivada, certifique-se de que o construtor principal de documentos seja chamados . Quando o assistente de aplicativo cria aplicativos de contêiner OLE, essa chamada é inserida para você.

Na *referência do programador OLE,* consulte [IStream,](/windows/win32/api/objidl/nn-objidl-istream) [IStorage](/windows/win32/api/objidl/nn-objidl-istorage)e [ILockBytes](/windows/win32/api/objidl/nn-objidl-ilockbytes).

## <a name="see-also"></a>Confira também

[Contêineres](../mfc/containers.md)<br/>
[Contêineres: emissões de interface do usuário](../mfc/containers-user-interface-issues.md)<br/>
[Classe COleStreamFile](../mfc/reference/colestreamfile-class.md)<br/>
[Classe COleDocument](../mfc/reference/coledocument-class.md)
