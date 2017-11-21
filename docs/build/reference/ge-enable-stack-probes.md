---
title: -Ge (habilitar sondas de pilha) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /ge
dev_langs: C++
helpviewer_keywords:
- -Ge compiler option [C++]
- enable stack probes
- /Ge compiler option [C++]
- stack, stack probes
- stack probes
- stack checking calls
- Ge compiler option [C++]
ms.assetid: 4b54deae-4e3c-4bfa-95f3-ba23590f7258
caps.latest.revision: "13"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 9c826b2f1d77e71d768ec73fb110f115bf7d0cfa
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ge-enable-stack-probes"></a>/Ge (habilitar sondas de pilha)
Ativa as sondas de pilha para cada chamada de função que requer o armazenamento para variáveis locais.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Ge  
```  
  
## <a name="remarks"></a>Comentários  
 Esse mecanismo é útil se você reescrever a funcionalidade do teste de pilha. É recomendável que você use [/Gh (habilitar penter função de gancho)](../../build/reference/gh-enable-penter-hook-function.md) em vez de reescrever o teste de pilha.  
  
 [/GS (chamadas de verificação de pilha de controle)](../../build/reference/gs-control-stack-checking-calls.md) tem o mesmo efeito.  
  
 **/GE** é preterido; a partir do Visual Studio 2005, o compilador gera automaticamente a verificação de pilha. Para obter uma lista de opções do compilador preterido, consulte **preteridos e removidos opções do compilador** na [opções do compilador listadas por categoria](../../build/reference/compiler-options-listed-by-category.md).  
  
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