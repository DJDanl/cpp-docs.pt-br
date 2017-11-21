---
title: -MAPA (Gerar Mapfile) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /map
- VC.Project.VCLinkerTool.MapFileName
- VC.Project.VCLinkerTool.GenerateMapFile
dev_langs: C++
helpviewer_keywords:
- mapfiles, creating linker
- generate mapfile linker option
- mapfile linker option
- mapfiles, information about program being linked
- MAP linker option
- -MAP linker option
- mapfiles, specifying file name
- /MAP linker option
ms.assetid: 9ccce53d-4e36-43da-87b0-7603ddfdea63
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 2e776803ab6f7046b2db1f80899ee6e465deb399
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="map-generate-mapfile"></a>/MAP (gerar mapfile)
```  
/MAP[:filename]  
```  
  
## <a name="remarks"></a>Comentários  
 em que:  
  
 *filename*  
 Um nome de usuário especificado para o arquivo de mapa. Ele substitui o nome padrão.  
  
## <a name="remarks"></a>Comentários  
 A opção /MAP informa o vinculador para criar um arquivo de mapa.  
  
 Por padrão, o vinculador nomeia o arquivo de mapa com o nome base do programa e o. map extensão. Opcional *filename* permite que você substitua o nome padrão para um arquivo de mapa.  
  
 Um arquivo de mapa é um arquivo de texto que contém as seguintes informações sobre o programa que está sendo vinculado:  
  
-   O nome do módulo, que é o nome base do arquivo  
  
-   O carimbo de hora no cabeçalho do arquivo de programa (e não do sistema de arquivos)  
  
-   Uma lista de grupos no programa, com o endereço inicial de cada grupo (como *seção*:*deslocamento*), comprimento, o nome de grupo e a classe  
  
-   Uma lista de símbolos públicos, com cada endereço (como *seção*:*deslocamento*), nome, endereço simples e arquivo. obj onde o símbolo é definido de símbolo  
  
-   O ponto de entrada (como *seção*:*deslocamento*)  
  
 O [/MAPINFO](../../build/reference/mapinfo-include-information-in-mapfile.md) opção especifica informações adicionais a serem incluídas no arquivo de mapa.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **depurar** página de propriedades.  
  
4.  Modificar o **gerar arquivo de mapa** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.GenerateMapFile%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.MapFileName%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)