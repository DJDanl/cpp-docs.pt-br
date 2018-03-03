---
title: "-GX (habilitar tratamento de exceções) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /gx
dev_langs:
- C++
helpviewer_keywords:
- exception handling, enabling
- /GX compiler option [C++]
- -GX compiler option [C++]
- cl.exe compiler, exception handling
- enable exception handling compiler option [C++]
- GX compiler option [C++]
ms.assetid: 933b43ba-de77-4ff8-a48b-7074de90bc1c
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3013b4233621e63de0230e088dfc10ff65a5705d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="gx-enable-exception-handling"></a>/GX (habilitar tratamento de exceções)
Preterido. Permite a manipulação de exceção síncrona usando a suposição de que as funções declarada usando `extern "C"` nunca lançam uma exceção.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/GX  
```  
  
## <a name="remarks"></a>Comentários  
 **/GX** foi preterido. Use o equivalente [/EHsc](../../build/reference/eh-exception-handling-model.md) opção. Para obter uma lista de opções do compilador preterido, consulte o **preteridos e removidos opções do compilador** seção [opções do compilador listadas por categoria](../../build/reference/compiler-options-listed-by-category.md).  
  
 Por padrão, **/EHsc**, o equivalente de **/GX**, está em vigor quando você compila usando o ambiente de desenvolvimento do Visual Studio. Ao usar as ferramentas de linha de comando, nenhum tratamento de exceção é especificado. Este é o equivalente de **/GX-**.  
  
 Para obter mais informações, consulte [manipulação de exceção C++](../../cpp/cpp-exception-handling.md).  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  No painel de navegação, escolha **propriedades de configuração**, **C/C++**, **linha de comando**.  
  
3.  Digite a opção de compilador no **opções adicionais** caixa.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [/EH (modelo de tratamento de exceções)](../../build/reference/eh-exception-handling-model.md)