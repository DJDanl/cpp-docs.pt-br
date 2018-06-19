---
title: -Qimprecise_fwaits (remover fwaits dentro de blocos Try) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /Qimprecise_fwaits
dev_langs:
- C++
helpviewer_keywords:
- -Qimprecise_fwaits compiler option (C++)
- /Qimprecise_fwaits compiler option (C++)
ms.assetid: b1501f21-7e08-4fea-95e8-176ec03a635b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a688f4b9f8f3c9302bb6a49e4b0a94a0e0931b33
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32378048"
---
# <a name="qimprecisefwaits-remove-fwaits-inside-try-blocks"></a>/Qimprecise_fwaits (remover fwaits dentro de blocos Try)
Remove o `fwait` comandos internos `try` bloqueia quando você usar o [/fp: exceto](../../build/reference/fp-specify-floating-point-behavior.md) opção de compilador.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Qimprecise_fwaits  
```  
  
## <a name="remarks"></a>Comentários  
 Essa opção não tem nenhum efeito se **/fp: exceto** também não for especificado. Se você especificar o **/fp: exceto** opção, o compilador para inserir um `fwait` comando em torno de cada linha de código em um `try` bloco. Dessa forma, o compilador pode identificar a linha de código que gera uma exceção específica. **/Qimprecise_fwaits** remove interno `fwait` instruções, deixando apenas as esperas em torno de `try` bloco. Isso melhora o desempenho, mas o compilador só poderá dizer qual `try` bloco gera uma exceção, não a linha.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Digite a opção de compilador no **opções adicionais** caixa.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [/Q opções (operações de nível baixo)](../../build/reference/q-options-low-level-operations.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)