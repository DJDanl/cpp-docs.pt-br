---
title: "Como importar e exportar recursos | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vs.resvw.resource.importing"
  - "vc.resvw.resource.importing"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "bitmaps [C++], importando e exportando"
  - "cursores [C++], importando e exportando"
  - "gráficos [C++], exportando"
  - "gráficos [C++], importando"
  - "imagens [C++], exportando"
  - "imagens [C++], importando"
  - "recursos [Visual Studio], exportando"
  - "recursos [Visual Studio], importando"
  - "barras de ferramentas [C++], exportando"
  - "barras de ferramentas [C++], importando"
ms.assetid: 3c9329dc-dcb8-4edd-a600-78e3e572bd89
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como importar e exportar recursos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode importar recursos gráficos \(bitmaps, ícones, cursores e barras de ferramentas\), arquivos HTML e recursos personalizados para uso no Visual C\+\+.  Você pode exportar os mesmos tipos de arquivos de um projeto do Visual C\+\+ para separar os arquivos que podem ser usados fora do ambiente de desenvolvimento.  
  
> [!NOTE]
>  Tipos de recursos como aceleradores, caixas de diálogo e tabelas de cadeia de caracteres não podem ser importados ou exportados porque eles não são tipos de arquivo autônomo.  
  
### Para importar um recurso individual em seu arquivo de recurso atual  
  
1.  Em [exibição recurso](../windows/resource-view-window.md), com o botão direito no nó do script de recurso \(\*. rc\) ao qual você deseja adicionar um recurso de arquivo.  
  
2.  Clique em **importação** no menu de atalho.  
  
3.  Localize e selecione o nome do arquivo de bitmap \(. bmp\), ícone \(. ico\), o cursor \(. cur\), arquivo Html \(. htm\) ou outro arquivo que você deseja importar.  
  
4.  Clique em **OK** para adicionar o recurso para o arquivo selecionado em **recurso** exibição.  
  
    > [!NOTE]
    >  O processo de importação funciona da mesma maneira, independentemente de qual recurso determinado tipo você selecionou.  O recurso importado é adicionado automaticamente para o nó correto para esse tipo de recurso.  
  
### Para exportar um bitmap, ícone ou cursor como um arquivo separado \(para uso fora do Visual C\+\+\)  
  
1.  Em **recurso** exibir, clique no recurso que você deseja exportar.  
  
2.  Clique em **exportar** no menu de atalho.  
  
3.  No **Exportar recurso** caixa de diálogo caixa, aceite o nome do arquivo atual ou digite um novo nome.  
  
4.  Navegue até a pasta onde deseja salvar o arquivo e clique em **exportar**.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [Recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos para propriedades, consulte [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 Requisitos  
  
 Win32  
  
## Consulte também  
 [Arquivos de recursos](../mfc/resource-files-visual-studio.md)   
 [Editores de recursos](../mfc/resource-editors.md)