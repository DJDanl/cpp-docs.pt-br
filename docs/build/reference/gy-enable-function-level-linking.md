---
title: -Gy (habilitar vinculação do nível de função) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: article
f1_keywords:
- VC.Project.VCCLCompilerTool.EnableFunctionLevelLinking
- /gy
- VC.Project.VCCLWCECompilerTool.EnableFunctionLevelLinking
dev_langs:
- C++
helpviewer_keywords:
- enable function-level linking compiler option [C++]
- COMDAT function
- Gy compiler option [C++]
- -Gy compiler option [C++]
- /Gy compiler option [C++]
- packaged functions
ms.assetid: 0d3cf14c-ed7d-4ad3-b4b6-104e56f61046
caps.latest.revision: 17
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ebe272b12a503a310319526f53f312a033a0ee26
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="gy-enable-function-level-linking"></a>/Gy (habilitar vinculação do nível de função)
Permite que o compilador empacote funções individuais no formato de funções empacotadas (COMDATs).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Gy[-]  
```  
  
## <a name="remarks"></a>Comentários  
 O vinculador requer que funções ser empacotado separadamente como COMDATs para excluir ou ordenar funções individuais em um arquivo DLL ou .exe.  
  
 Você pode usar a opção de vinculador [/OPÇ (otimizações)](../../build/reference/opt-optimizations.md) para excluir funções empacotadas sem referência do arquivo .exe.  
  
 Você pode usar a opção de vinculador [/ORDER (colocar funções na ordem)](../../build/reference/order-put-functions-in-order.md) para incluir funções empacotadas em uma ordem especificada no arquivo .exe.  
  
 Funções embutidas são sempre compactadas se eles são instanciados como chamadas (que ocorre, por exemplo, se inlining é desativado ou tomar o endereço de uma função). Além disso, as funções de membro de C++ definidas na declaração da classe automaticamente são empacotadas; outras funções não são, e a seleção dessa opção é necessário para compilá-los como funções empacotadas.  
  
> [!NOTE]
>  O [/ZI](../../build/reference/z7-zi-zi-debug-information-format.md) opcional usada para editar e continuar, define automaticamente o **/Gy** opção.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **geração de código** página de propriedades.  
  
4.  Modificar o **habilitar vínculo em nível de função** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnableFunctionLevelLinking%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)