---
title: -WX (tratar avisos do vinculador como erros) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /WX
dev_langs:
- C++
helpviewer_keywords:
- /WX linker option
- -WX linker option
- WX linker option
ms.assetid: e4ba97c7-93f7-43ae-a4bb-d866790926c9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 686b17a3db00175340e3490241c6c2e9f9325225
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32377281"
---
# <a name="wx-treat-linker-warnings-as-errors"></a>/WX (tratar avisos do vinculador como erros)
```  
/WX[:NO]  
```  
  
## <a name="remarks"></a>Comentários  
 /WX faz com que nenhum arquivo de saída a ser gerado se o vinculador gera um aviso.  
  
 Isso é semelhante a **/WX** para o compilador (consulte [/w, /W0, /W1, /W2, /W3, /W4, /w1, /w2, /w3, /w4, /Wall, /wd, /, /wo, /Wv, /WX (nível de aviso)](../../build/reference/compiler-option-warning-level.md) para obter mais informações). Entretanto, a especificação **/WX** para a compilação não implica que **/WX** também entrará em vigor para a fase de link; você deve especificar explicitamente **/WX** para cada ferramenta.  
  
 Por padrão, **/WX** não está em vigor. Para tratar avisos do vinculador como erros, especifique **/WX**. **/WX:no** é o mesmo que especificar não **/WX**.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Digite a opção para o **opções adicionais** caixa.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)