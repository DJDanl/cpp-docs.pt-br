---
title: "-DEFAULTLIB (especificar biblioteca padrão) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCLinkerTool.DefaultLibraries
- /defaultlib
dev_langs:
- C++
helpviewer_keywords:
- -DEFAULTLIB linker option
- DEFAULTLIB linker option
- /DEFAULTLIB linker option
- libraries, adding to list of
ms.assetid: 6af7ff49-c170-4a13-97e2-2b9ae2de20c9
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 40fe07543dd9dc65d93cc9f79504f5fd324204dd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="defaultlib-specify-default-library"></a>/DEFAULTLIB (especificar biblioteca padrão)
```  
/DEFAULTLIB:library  
```  
  
## <a name="remarks"></a>Comentários  
 em que:  
  
 *biblioteca*  
 O nome de uma biblioteca de pesquisa ao resolver referências externas.  
  
## <a name="remarks"></a>Comentários  
 A opção /DEFAULTLIB adiciona uma *biblioteca* à lista de bibliotecas de LINK busca ao resolver referências. Uma biblioteca especificada com /DEFAULTLIB é pesquisada após bibliotecas especificadas na linha de comando e antes de bibliotecas padrão chamadas nos arquivos. obj.  
  
 O [ignorar todas as bibliotecas padrão](../../build/reference/nodefaultlib-ignore-libraries.md) (/ /NODEFAULTLIB) opção substitui /DEFAULTLIB:*biblioteca*. O [ignorar bibliotecas](../../build/reference/nodefaultlib-ignore-libraries.md) (/ /NODEFAULTLIB:*biblioteca*) opção substitui /DEFAULTLIB:*biblioteca* quando o mesmo *biblioteca* nome é especificado em ambos.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
-   Essa opção de vinculador não está disponível no ambiente de desenvolvimento do Visual Studio. Para adicionar uma biblioteca para a fase de link, use o **dependências adicionais** propriedade a partir de **entrada** página de propriedades.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)