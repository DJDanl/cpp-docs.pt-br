---
title: 'Como: importar e exportar recursos | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vs.resvw.resource.importing
- vc.resvw.resource.importing
dev_langs: C++
helpviewer_keywords:
- resources [Visual Studio], exporting
- graphics [C++], exporting
- graphics [C++], importing
- resources [Visual Studio], importing
- bitmaps [C++], importing and exporting
- toolbars [C++], importing
- images [C++], importing
- toolbars [C++], exporting
- cursors [C++], importing and exporting
- images [C++], exporting
ms.assetid: 3c9329dc-dcb8-4edd-a600-78e3e572bd89
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 21f596996d090d9d41146c6f8ea9cb24884dd4c0
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="how-to-import-and-export-resources"></a>Como importar e exportar recursos
Você pode importar recursos gráficos (bitmaps, ícones, cursores e barras de ferramentas), arquivos HTML e recursos personalizados para uso em Visual C++. Você pode exportar os mesmos tipos de arquivos de um projeto do Visual C++ para separar arquivos que podem ser usados fora do ambiente de desenvolvimento.  
  
> [!NOTE]
>  Tipos de recursos como aceleradores, caixas de diálogo e tabelas de cadeia de caracteres não podem ser importados ou exportados porque eles não são tipos de arquivo autônomo.  
  
### <a name="to-import-an-individual-resource-into-your-current-resource-file"></a>Para importar um recurso individual para o arquivo de recurso atual  
  
1.  Em [exibição recursos](../windows/resource-view-window.md), com o botão direito no nó para o script de recurso (*. rc) para o qual você deseja adicionar um recurso de arquivo.  
  
2.  Clique em **importação** no menu de atalho.  
  
3.  Localize e selecione o nome do arquivo de bitmap (bmp), ícone (. ico), o cursor (. cur), arquivo Html (. htm) ou outros arquivos que você deseja importar.  
  
4.  Clique em **Okey** para adicionar o recurso para o arquivo selecionado em **recurso** exibição.  
  
    > [!NOTE]
    >  O processo de importação funcionar da mesma forma, não importando qual recurso determinado tipo que você selecionou. O recurso importado é adicionado automaticamente para o nó correto para esse tipo de recurso.  
  
### <a name="to-export-a-bitmap-icon-or-cursor-as-a-separate-file-for-use-outside-of-visual-c"></a>Para exportar um bitmap, ícone ou cursor como um arquivo separado (para uso fora do Visual C++)  
  
1.  Em **recurso** exibir, clique no recurso que você deseja exportar.  
  
2.  Clique em **exportar** no menu de atalho.  
  
3.  No **Exportar recurso** caixa de diálogo caixa, aceite o nome do arquivo atual ou digite um novo.  
  
4.  Navegue até a pasta onde deseja salvar o arquivo e clique em **exportar**.  
  

  
 Requisitos  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos de recurso](../windows/resource-files-visual-studio.md)   
 [Editores de recursos](../windows/resource-editors.md)