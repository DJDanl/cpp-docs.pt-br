---
title: "/INCREMENTAL (vincular de maneira incremental) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/incremental"
  - "VC.Project.VCLinkerTool.LinkIncremental"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /INCREMENTAL"
  - "opção de vinculador INCREMENTAL"
  - "opção de vinculador -INCREMENTAL"
  - "vinculação incremental"
  - "opção de link incremental"
  - "ferramenta LINK [C++], opções para vinculação completa"
ms.assetid: 135656ff-94fa-4ad4-a613-22e1a2a5d16b
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /INCREMENTAL (vincular de maneira incremental)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/INCREMENTAL[:NO]  
```  
  
## Comentários  
 Controla como o vinculador manipula a vinculação incremental.  
  
 Por padrão, o vinculador é executado no modo incremental. Para substituir um link incremental padrão, especifique \/incremental: no.  
  
 Um programa incrementalmente vinculado é funcionalmente equivalente a um programa vinculado não incrementalmente. No entanto, porque ele está preparado para links incrementais subsequentes, incrementalmente vinculada biblioteca estática, executável ou arquivo de biblioteca de vínculo dinâmico:  
  
-   É maior do que um programa vinculado não incrementalmente devido ao preenchimento de código e dados. Preenchimento permite que o vinculador aumentar o tamanho das funções e dos dados sem recriar o arquivo.  
  
-   Pode conter conversões de atalho para manipular a realocação de funções para novos endereços.  
  
    > [!NOTE]
    >  Para garantir que a compilação de lançamento final não tenha preenchimento ou conversões, vincule seu programa não incrementalmente.  
  
 Para vincular de maneira incremental independentemente do padrão, especifique \/incremental. Quando essa opção é selecionada, o vinculador emite um aviso se ele não é possível vincular incrementalmente e vincula o programa não incrementalmente. Determinadas opções e situações substituem \/incremental.  
  
 A maioria dos programas pode ser vinculada incrementalmente. No entanto, algumas alterações são muito grandes, e algumas opções são incompatíveis com a vinculação incremental. LINK executa uma vinculação completa se qualquer uma das seguintes opções são especificadas:  
  
-   Vincular incrementalmente não está selecionado \(\/ \/INCREMENTAL: NO\)  
  
-   \/OPT: REF está selecionado  
  
-   \/OPT: ICF está selecionado  
  
-   \/OPT: lbr está selecionado  
  
-   \/Order está selecionado  
  
 \/INCREMENTAL é inferido quando [\/Debug](../../build/reference/debug-generate-debug-info.md) for especificado.  
  
 Além disso, o LINK executa uma vinculação completa se qualquer uma das seguintes situações ocorrer:  
  
-   O arquivo de status incremental \(. ilk\) está ausente. \(O LINK cria um novo arquivo. ilk em preparação para a vinculação incremental subsequente.\)  
  
-   Não há nenhuma permissão de gravação para o arquivo. ilk. \(O LINK ignora o arquivo. ilk e links não incrementalmente.\)  
  
-   .Exe ou. dll de saída de arquivo está ausente.  
  
-   O carimbo de hora do. ilk, .exe ou. dll é alterado.  
  
-   Uma opção de LINK é alterada. A maioria das opções de LINK, quando alteradas entre as compilações, causa uma vinculação completa.  
  
-   Um arquivo de objeto \(. obj\) é adicionado ou omitido.  
  
### Para definir essa opção de vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter detalhes, consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **vinculador** pasta.  
  
3.  Selecione o **geral** página de propriedades.  
  
4.  Modificar o **habilitar vinculação Incremental** propriedade.  
  
### Para definir essa opção de vinculador programaticamente  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.LinkIncremental%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)