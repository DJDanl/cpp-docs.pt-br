---
title: 'Como: importar e exportar recursos (C++) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vs.resvw.resource.importing
- vc.resvw.resource.importing
dev_langs:
- C++
helpviewer_keywords:
- resources [C++], exporting
- graphics [C++], exporting
- graphics [C++], importing
- resources [C++], importing
- bitmaps [C++], importing and exporting
- toolbars [C++], importing
- images [C++], importing
- toolbars [C++], exporting
- cursors [C++], importing and exporting
- images [C++], exporting
ms.assetid: 3c9329dc-dcb8-4edd-a600-78e3e572bd89
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a6b975b932545d62b62db0b44bad549a3570a602
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44318545"
---
# <a name="how-to-import-and-export-resources"></a>Como importar e exportar recursos

Você pode importar recursos gráficos (bitmaps, ícones, cursores e barras de ferramentas), arquivos HTML e recursos personalizados para uso no Visual C++. Você pode exportar os mesmos tipos de arquivos de um projeto do Visual C++ para separar os arquivos que podem ser usados fora do ambiente de desenvolvimento.

> [!NOTE]
> Tipos de recursos como aceleradores, caixas de diálogo e tabelas de cadeia de caracteres não podem ser importados ou exportados porque eles não são tipos de arquivo autônomo.

### <a name="to-import-an-individual-resource-into-your-current-resource-file"></a>Para importar um recurso individual em seu arquivo de recurso atual

1. Na [exibição de recurso](../windows/resource-view-window.md), clique com botão direito no nó para o script de recurso (*. rc) ao qual você deseja adicionar um recurso de arquivo.

2. Clique em **importação** no menu de atalho.

3. Localize e selecione o nome do arquivo de bitmap (. bmp), o ícone (. ico), o cursor (. cur), arquivo Html (. htm) ou outro arquivo que você deseja importar.

4. Clique em **Okey** para adicionar o recurso para o arquivo selecionado no **recursos** modo de exibição.

   > [!NOTE]
   > O processo de importação funcionar da mesma maneira, independentemente de qual recurso determinado tipo que você selecionou. O recurso importado é adicionado automaticamente para o nó correto para esse tipo de recurso.

### <a name="to-export-a-bitmap-icon-or-cursor-as-a-separate-file-for-use-outside-of-visual-c"></a>Para exportar um bitmap, ícone ou cursor como um arquivo separado (para uso fora do Visual C++)

1. Na **recurso** exibir, clique no recurso que você deseja exportar.

2. Clique em **exportar** no menu de atalho.

3. No **Exportar recurso** caixa de diálogo caixa, aceite o nome do arquivo atual ou digite um novo.

4. Navegue até a pasta onde deseja salvar o arquivo e clique em **exportar**.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Arquivos de recurso](../windows/resource-files-visual-studio.md)  
[Editores de recursos](../windows/resource-editors.md)