---
title: "-homeparams (copiar parâmetros de registro para pilha) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /homeparams
dev_langs: C++
helpviewer_keywords:
- /homeparams compiler option [C++]
- -homeparams compiler option [C++]
ms.assetid: 51067de4-24f7-436b-b8d9-bc867a7d53aa
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: f46da1b80fa8cc3a9ee1990e4db51ca87be85a2e
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="homeparams-copy-register-parameters-to-stack"></a>/homeparams (copiar parâmetros de registro para pilha)
Força os parâmetros passados em registros a serem gravados em seus locais na pilha mediante a entrada da função.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/homeparams  
```  
  
## <a name="remarks"></a>Comentários  
 Esta opção do compilador se destina apenas aos compiladores [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)] (nativos e de compilação cruzada).  
  
 Quando os parâmetros são passados em uma [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)] compilação, convenções de chamada exigem stackspace para parâmetros, mesmo para os parâmetros passados em registros. Para obter mais informações, consulte [parâmetro passando](../../build/parameter-passing.md). No entanto, por padrão, em uma compilação de versão, os parâmetros de registro serão não gravados na pilha, no espaço que já é fornecido para os parâmetros. Isso torna difícil de depurar um build otimizado (versão) do seu programa.  
  
 Para uma versão de compilação, use **/homeparams** para garantir que você pode depurar seu aplicativo. **/homeparams** implica uma desvantagem de desempenho, porque ele requer um ciclo para carregar os parâmetros de registro na pilha.  
  
 Em uma compilação de depuração, a pilha sempre é preenchida com os parâmetros passados em registros.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Digite a opção de compilador no **opções adicionais** caixa.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)