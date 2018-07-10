---
title: -constexpr (avaliação de constexpr de controle) | Microsoft Docs
ms.custom: ''
ms.date: 08/15/2017
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /constexpr
- -constexpr
dev_langs:
- C++
helpviewer_keywords:
- /constexpr control constexpr evaluation [C++]
- -constexpr control constexpr evaluation [C++]
- constexpr control constexpr evaluation [C++]
ms.assetid: 76d56784-f5ad-401d-841d-09d1059e8b8c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f83f1d9a505ebc4c05ce4e367bb1e978d6a14b78
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32373953"
---
# <a name="constexpr-control-constexpr-evaluation"></a>/constexpr (avaliação de constexpr de controle)  
  
Use o **/constexpr** opções do compilador para parâmetros de controle para `constexpr` avaliação em tempo de compilação.  
  
## <a name="syntax"></a>Sintaxe  
  
> /constexpr:Depth*N*  
> /constexpr:Backtrace*N*  
> /constexpr: Steps*N*  
  
## <a name="arguments"></a>Arguments  
  
**profundidade * N*  
Limitar a profundidade de recursiva `constexpr` a invocação de função *N* níveis. O padrão é 512.  
  
**Backtrace * N*  
Mostrar até *N* `constexpr` avaliações de diagnóstico. O padrão é 10.  
  
**etapas * N*  
Encerrar `constexpr` avaliação após *N* etapas. O padrão é 100.000.  
  
## <a name="remarks"></a>Comentários  
  
O **/constexpr** opções do compilador controlam avaliação do tempo de compilação de `constexpr` expressões. Etapas de avaliação, os níveis de recursão e profundidade backtrace são controladas para impedir que o compilador gastar muito tempo na `constexpr` avaliação. Para obter mais informações sobre o `constexpr` elemento de linguagem, consulte [constexpr (C++)](../../cpp/constexpr-cpp.md).  

O **/constexpr** opções estão disponíveis a partir no Visual Studio 2015.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1. Abra seu projeto **páginas de propriedade** caixa de diálogo.   
  
2. Em **propriedades de configuração**, expanda o **C/C++** pasta e escolha o **linha de comando** página de propriedades.  
  
3. Insira qualquer **/constexpr** opções de compilador no **opções adicionais** caixa. Escolha **Okey** ou **aplicar** para salvar suas alterações.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
  
[Opções do compilador](../../build/reference/compiler-options.md)   
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)