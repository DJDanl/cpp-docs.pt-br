---
title: -GR (Habilitar informações de tipo de tempo de execução) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /gr
- VC.Project.VCCLWCECompilerTool.RuntimeTypeInfo
- VC.Project.VCCLCompilerTool.RuntimeTypeInfo
dev_langs:
- C++
helpviewer_keywords:
- -Gr compiler option [C++]
- Gr compiler option [C++]
- RTTI compiler option
- /Gr compiler option [C++]
- enable run-time type information compiler option [C++]
ms.assetid: d1f9f850-dcec-49fd-96ef-e72d01148906
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 79e91f11fa6397d2ba8279998726249182c541d4
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32374968"
---
# <a name="gr-enable-run-time-type-information"></a>/GR (habilitar informações de tipo de tempo de execução)
Adiciona código para verificar tipos de objeto em tempo de execução.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/GR[-]  
```  
  
## <a name="remarks"></a>Comentários  
 Quando **/GR** está ativada, o compilador define o `_CPPRTTI` macro de pré-processador. Por padrão, **/GR** está em. **/GR-** desabilita as informações de tipo de tempo de execução.  
  
 Use **/GR** se o compilador não puder resolver estaticamente um tipo de objeto em seu código. Geralmente, é necessário o **/GR** quando seu código usa a opção [operador dynamic_cast](../../cpp/dynamic-cast-operator.md) ou [typeid](../../cpp/typeid-operator.md). No entanto, **/GR** aumenta o tamanho das seções RDATA da imagem. Se seu código usar **dynamic_cast** ou **typeid**, **/GR-** pode produzir uma imagem menor.  
  
 Para obter mais informações sobre a verificação de tipo de tempo de execução, consulte [informações de tipo de tempo de execução](../../cpp/run-time-type-information.md) no *referência de linguagem C++*.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **idioma** página de propriedades.  
  
4.  Modificar o **habilitar informações de tipo de tempo de execução** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.RuntimeTypeInfo%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)