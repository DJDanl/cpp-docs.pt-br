---
title: -/LARGEADDRESSAWARE (identificar endereços grandes) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.LargeAddressAware
- /largeaddressaware
dev_langs:
- C++
helpviewer_keywords:
- LARGEADDRESSAWARE linker option
- -LARGEADDRESSAWARE linker option
- /LARGEADDRESSAWARE linker option
ms.assetid: a29756c8-e893-47a9-9750-1f0d25359385
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4f81424c49c5d67713cf478f69701c52504cfa8c
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="largeaddressaware-handle-large-addresses"></a>/LARGEADDRESSAWARE (identificar endereços grandes)
```  
/LARGEADDRESSAWARE[:NO]  
```  
  
## <a name="remarks"></a>Comentários  
 A opção /LARGEADDRESSAWARE informa o vinculador que o aplicativo pode manipular endereços maiores que 2 gigabytes. Em que os compiladores de 64 bits, essa opção é habilitada por padrão. Em que os compiladores de 32 bits, /LARGEADDRESSAWARE: no está habilitado se /LARGEADDRESSAWARE não forem especificadas na linha de vinculador.  
  
 Se um aplicativo foi vinculado com /LARGEADDRESSAWARE, DUMPBIN [/HEADERS](../../build/reference/headers.md) exibirá informações para esse efeito.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **sistema** página de propriedades.  
  
4.  Modificar o **habilitar endereços grandes** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.LargeAddressAware%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)