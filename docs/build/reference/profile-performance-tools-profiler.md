---
title: -PERFIL (criador de perfil de ferramentas de desempenho) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.Profile
dev_langs:
- C++
helpviewer_keywords:
- -PROFILE linker option
- /PROFILE linker option
ms.assetid: e676baa1-5063-47a3-a357-ba0d1f0d1699
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 15379914b4c4852e3065d1abc03c2ce1b17fb044
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32377112"
---
# <a name="profile-performance-tools-profiler"></a>/PROFILE (criador de perfil das ferramentas de desempenho)
Produz um arquivo de saída que pode ser usado com o criador de perfil de Ferramentas de desempenho.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/PROFILE  
```  
  
## <a name="remarks"></a>Comentários  
 / As seguintes opções de vinculador implica em perfil:  
  
-   [/OPT: REF](../../build/reference/opt-optimizations.md)  
  
-   /OPT: NOICF  
  
-   [/ INCREMENTAL: NÃO](../../build/reference/incremental-link-incrementally.md)  
  
-   [/FIXED: NÃO](../../build/reference/fixed-fixed-base-address.md)  
  
 Ou o perfil faz com que o vinculador gerar uma seção de realocação na imagem do programa.  Uma seção de realocação permite que o criador de perfil transformar a imagem do programa para obter dados de perfil.  
  
 **/Profile** só está disponível somente em versões Enterprise (desenvolvimento em equipe).  Para obter mais informações sobre PREfast, consulte [análise de código para visão geral do C/C++](/visualstudio/code-quality/code-analysis-for-c-cpp-overview).  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda o **propriedades de configuração** nó.  
  
3.  Expanda o **vinculador** nó.  
  
4.  Selecione o **avançado** página de propriedades.  
  
5.  Modificar o **perfil** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.Profile%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)