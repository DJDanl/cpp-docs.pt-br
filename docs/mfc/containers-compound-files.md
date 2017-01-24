---
title: "Cont&#234;ineres: arquivos compostos | Microsoft Docs"
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
  - "modos de acesso para arquivos [C++]"
  - "documentos compostos"
  - "arquivos compostos"
  - "contêineres [C++], arquivos compostos"
  - "documentos [C++], composto"
  - "documentos [C++], OLE"
  - "Arquivos  [C++], composto"
  - "Contêineres OLE, arquivos compostos"
  - "Documentos OLE, arquivos compostos"
  - "desempenho [C++], arquivos compostos"
  - "arquivos compostos da estrutura de arquivos padronizados"
ms.assetid: 8b83cb3e-76c8-4bbe-ba16-737092b36f49
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Cont&#234;ineres: arquivos compostos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica os componentes e a implementação de arquivos compostos e as vantagens e desvantagens de usar arquivos compostos em seus aplicativos OLE.  
  
 Os arquivos são compostos parte integrante de OLE.  São usados para facilitar a transferência e armazenamento de dados OLE do documento.  Os arquivos são compostos uma implementação do modelo de armazenamento estruturado ativa.  As interfaces consistentes existem essa serialização de suporte para um armazenamento, em um fluxo, ou a um objeto de arquivo.  Os arquivos compostos têm suporte na biblioteca de classes do Microsoft foundation classes pela `COleStreamFile` e `COleDocument`.  
  
> [!NOTE]
>  Usar um arquivo composto não significa que a informação vem de um documento OLE ou documento composto.  Os arquivos são compostos apenas uma das formas de armazenar documentos compostos, documentos OLE, e outros dados.  
  
##  <a name="_core_components_of_a_compound_file"></a> Componentes de Arquivo composto  
 A implementação de arquivos compostos OLE usa três tipos de objeto: passe objetos, objetos de armazenamento, e objetos de `ILockBytes` .  Esses objetos são semelhantes aos componentes de um sistema de arquivos padrão das seguintes maneiras:  
  
-   Passe objetos, como arquivos, dados de repositório de qualquer tipo.  
  
-   Os objetos de armazenamento, como diretórios, podem conter outros objetos de armazenamento e de fluxo.  
  
-   Os objetos de**LockBytes** representam a interface entre os objetos de armazenamento e o hardware físico.  Determinam como os bytes reais são gravados que o dispositivo de armazenamento o objeto de **LockBytes** está acessando, como um disco rígido ou uma área de memória global.  Para obter mais informações sobre os objetos de **LockBytes** e a interface de `ILockBytes` , consulte *a referência do programador OLE*.  
  
##  <a name="_core_advantages_and_disadvantages_of_compound_files"></a> Vantagens e desvantagens de arquivos compostos  
 Os arquivos compostos fornecem os benefícios não disponíveis com métodos anteriores de armazenamento de arquivo.  Incluem:  
  
-   Acessar incremental do arquivo.  
  
-   Modos de acesso ao arquivo.  
  
-   Normalização da estrutura do arquivo.  
  
 As possíveis desvantagens de arquivos compostos — grandes problemas de tamanho e de desempenho em relação ao armazenamento em discos flexíveis — devem ser consideradas ao decidir se usá\-los em seu aplicativo.  
  
###  <a name="_core_incremental_access_to_files"></a> Acesso aos arquivos incremental  
 O acesso incremental dos arquivos é um benefício automático de usar arquivos compostos.  Como um arquivo composto pode ser exibido como “o sistema de arquivos em um arquivo,” os tipos de objeto individuais, como o fluxo ou armazenamento, podem ser acessados sem a necessidade de carregar o arquivo inteiro.  Isso pode reduzir drasticamente o tempo que um aplicativo precisa acessar novos objetos para editar pelo usuário.  Atualizar incrementalmente, com base no mesmo conceito, oferece benefícios semelhantes.  Em vez de salvar o arquivo inteiro apenas para salvar as alterações feitas a um objeto OLE, salva o objeto somente de fluxo ou armazenamento editado pelo usuário.  
  
###  <a name="_core_file_access_modes"></a> Modos de acesso ao arquivo  
 Determinar quando as alterações aos objetos em um arquivo composto são confirmadas no disco é outro benefício do uso de arquivos compostos.  O modo no qual os arquivos são acessados, transacionado ou diretos, determina quando as alterações são confirmadas.  
  
-   O usa o modo de transação uma operação de confirmação em duas fases para fazer alterações em objetos de um arquivo composto, assim mantendo cópias antigas e novas do documento disponível até que o usuário escolha para salvar ou desfazer as alterações.  
  
-   O modo directquery digita alterações no documento como são feitas, sem capacidade de desfazer posterior.  
  
 Para obter mais informações sobre modos de acesso, consulte *a referência do programador OLE*.  
  
###  <a name="_core_standardization"></a> Normalização  
 A estrutura padronizada de arquivos compostos permite que os aplicativos OLE diferentes navegar pelos arquivos compostos criados pelo seu aplicativo OLE sem o conhecimento do aplicativo que criou realmente o arquivo.  
  
###  <a name="_core_size_and_performance_considerations"></a> Considerações de tamanho e de desempenho  
 Devido à complexidade da estrutura composta de armazenamento de arquivo e a habilidade de salvar incremental dados, os arquivos que usam esse formato tendem a ser maior do que a outra usando os arquivos não estruturados ou armazenamento de arquivo simples”. “  Se seu aplicativo frequentemente carrega e salva arquivos, usar arquivos compostos pode fazer com que o tamanho do arquivo aumenta muito mais rápido do que arquivos de noncompound.  Como os arquivos compostos podem obter grande, a hora de acesso para arquivos armazenados em e são carregadas de discos também podem ser afetadas, resultando em um acesso mais lento para os arquivos.  
  
 Outros tema que afetam o desempenho são fragmentação de composto\-Arquivo.  O tamanho de um arquivo composto é determinado pela diferença entre o primeiro e o último setores de disco usado pelo arquivo.  Um arquivo fragmentado pode conter muitas áreas de espaço livre que não contêm dados, mas é contado ao calcular o tamanho.  Durante o tempo de vida de um arquivo composto, essas áreas são criadas pela inserção ou pela exclusão de objetos de armazenamento.  
  
##  <a name="_core_using_compound_files_format_for_your_data"></a> Usando o formato de arquivos composto para seus dados  
 Após com êxito criar um aplicativo que tem uma classe de documento é derivada de `COleDocument`, verifique se o construtor de documento principal exige `EnableCompoundFile`.  Quando o assistente de aplicativo cria aplicativos de contêiner OLE, essa chamada é inserido.  
  
 *Na referência do programador OLE*, consulte [IStream](http://msdn.microsoft.com/library/windows/desktop/aa380034), [IStorage](http://msdn.microsoft.com/library/windows/desktop/aa380015), e [ILockBytes](http://msdn.microsoft.com/library/windows/desktop/aa379238).  
  
## Consulte também  
 [Contêineres](../mfc/containers.md)   
 [Contêineres: emissões de interface do usuário](../mfc/containers-user-interface-issues.md)   
 [Classe de COleStreamFile](../Topic/COleStreamFile%20Class.md)   
 [Classe de COleDocument](../mfc/reference/coledocument-class.md)