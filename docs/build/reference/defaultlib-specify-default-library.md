---
title: -DEFAULTLIB (especificar biblioteca padrão) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e48db05ea50917a09e618c782d86dace73a1bf7e
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="defaultlib-specify-default-library"></a>/DEFAULTLIB (especificar biblioteca padrão)
```  
/DEFAULTLIB:library  
```  
  
## <a name="remarks"></a>Comentários  
 em que:  
  
 *Biblioteca*  
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