---
title: "-V (número de versão) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /v
dev_langs: C++
helpviewer_keywords:
- embedding version strings
- /V compiler option [C++]
- version numbers, specifying for .obj
- V compiler option [C++]
- -V compiler option [C++]
ms.assetid: 3e93fb7a-5dfd-49a6-bd49-3dca8052e0f3
caps.latest.revision: "14"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9a940000b5330c4eccdcabcc5a31f0c3e3e74d65
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="v-version-number"></a>/V (número de versão)
Preterido. Insere uma cadeia de caracteres de texto no arquivo. obj.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Vstring  
```  
  
## <a name="arguments"></a>Arguments  
 `string`  
 Uma cadeia de caracteres especificando o número de versão ou o aviso de direitos autorais a ser inserido em um arquivo. obj.  
  
## <a name="remarks"></a>Comentários  
 O rótulo de stringcan um arquivo. obj, com um número de versão ou um aviso de direitos autorais. Qualquer caractere de espaço ou tabulação deverão ser colocado entre aspas duplas (") se eles fazem parte da cadeia de caracteres. Uma barra invertida (\\) devem preceder qualquer aspas duplas se fizerem parte da cadeia de caracteres. Um espaço entre **/V** e `string` é opcional.  
  
 Você também pode usar [comentário (C/C++)](../../preprocessor/comment-c-cpp.md) com o argumento de tipo de comentário do compilador para colocar o nome e número de versão do compilador no arquivo. obj.  
  
 O **/V** opção é substituída, começando no Visual Studio 2005; **/V** principalmente foi usado para dar suporte à criação de drivers de dispositivo virtual (VxDs) e não há suporte para a criação de VxDs pelo conjunto de ferramentas do Visual C++. Para obter uma lista de opções do compilador preterido, consulte **preteridos e removidos opções do compilador** na [opções do compilador listadas por categoria](../../build/reference/compiler-options-listed-by-category.md).  
  
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