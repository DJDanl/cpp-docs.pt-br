---
title: "Salvando e carregando diferentes cores paletas (Editor de imagens para ícones) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.editors.image.color
dev_langs:
- C++
helpviewer_keywords:
- color palettes [C++]
- palettes
- palettes, Image editor
- colors [C++], Image editor
- Image editor [C++], palettes
ms.assetid: 694b6346-e606-4f19-aa01-9b4ceb47f423
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d7ef7200300eb4809496bfa342e9bab645f4c40e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="saving-and-loading-different-color-palettes-image-editor-for-icons"></a>Salvando e carregando paletas de cores diferentes (editor de imagens para ícones)
Você pode salvar e carregar uma paleta de cores que contém [personalizado cores](../windows/customizing-or-changing-colors-image-editor-for-icons.md). (Por padrão, a paleta de cores usada mais recentemente é carregada automaticamente quando você iniciar o Visual Studio.)  
  
> [!TIP]
>  Como o editor de imagem não tem meios para restaurar a paleta de cores padrão, você deve salvar a paleta de cores padrão com um nome como standard.pal ou default.pal para que você possa restaurar facilmente as configurações padrão.  
  
### <a name="to-save-a-custom-colors-palette"></a>Para salvar uma paleta de cores personalizadas  
  
1.  Do **imagem** menu, escolha **Salvar paleta**.  
  
2.  Navegue até o diretório onde você deseja salvar a paleta e digite um nome para a paleta.  
  
3.  Clique em **Salvar**.  
  
### <a name="to-load-a-custom-colors-palette"></a>Para carregar uma paleta de cores personalizadas  
  
1.  Do **imagem** menu, escolha **paleta carga**.  
  
2.  No [caixa de diálogo carregar a paleta de cores](../windows/load-palette-colors-dialog-box-image-editor-for-icons.md), navegue até o diretório correto e selecione a paleta que você deseja carregar. Paletas de cores são salvos com uma extensão de arquivo. PAL.  
  

  
 Requisitos  
  
 Nenhum  
  
## <a name="see-also"></a>Consulte também  
 [Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)   
 [Trabalhando com cor](../windows/working-with-color-image-editor-for-icons.md)