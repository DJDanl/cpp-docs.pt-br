---
title: -Zm (Especificar limite de alocação de memória de cabeçalho pré-compilado) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /zm
dev_langs:
- C++
helpviewer_keywords:
- PCH files, memory allocation limit
- Zm compiler option [C++]
- /Zm compiler option [C++]
- precompiled header files, memory allocation limit
- Specify Precompiled Header Memory Allocation Limit compiler option
- cl.exe compiler, memory allocation limit
- .pch files, memory allocation limit
- memory allocation, Memory Allocation Limit compiler option
- -Zm compiler option [C++]
ms.assetid: 94c77d5e-6672-46a7-92e0-3f69e277727d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 379d3d6673e673522334d685a47220bcfa2523ec
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="zm-specify-precompiled-header-memory-allocation-limit"></a>/Zm (especificar limite de alocação da memória de cabeçalho pré-compilado)
Determina a quantidade de memória que o compilador atribui para construir cabeçalhos pré-compilados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Zmfactor  
```  
  
## <a name="arguments"></a>Arguments  
 `factor`  
 Um fato de escala que determina a quantidade de memória que o compilador usa para construir cabeçalhos pré-compilados.  
  
 O argumento `factor` é uma porcentagem do tamanho padrão de um buffer de trabalho definido pelo compilador. O valor padrão de `factor` é 100 (por cento), mas você pode especificar quantidades maiores ou menores.  
  
## <a name="remarks"></a>Comentários  
 Em versões anteriores do Visual C++, o compilador usou vários heaps discretos, e cada um tinha um limite finito. Atualmente, o compilador aumenta dinamicamente os heaps conforme necessário até o limite de tamanho total do heap e requer um buffer de tamanho fixo somente para construir cabeçalhos pré-compilados. Consequentemente, o **/Zm** opção de compilador raramente é necessária.  
  
 Se o compilador ficou sem espaço de pilha e emite o [C1060](../../error-messages/compiler-errors-1/fatal-error-c1060.md) mensagem de erro quando você usar o **/Zm** opção de compilador pode reservado muita memória. Considere remover o **/Zm** opção. Se o compilador emite o [C1076](../../error-messages/compiler-errors-1/fatal-error-c1076.md) mensagem de erro, uma que acompanha [C3859](../../error-messages/compiler-errors-2/compiler-error-c3859.md) mensagem especifica o `factor` argumento a ser usado ao recompilar usando o **/Zm** opção de compilador.  
  
 A tabela a seguir mostra como o argumento `factor` afeta o limite de alocação de memória se você pressupor que o tamanho do buffer de cabeçalhos pré-compilados padrão seja de 75 MB.  
  
|Valor de `factor`|Limite de alocação de memória|  
|-----------------------|-----------------------------|  
|10|7.5 MB|  
|100|75 MB|  
|200|150 MB|  
|1000|750 MB|  
|2000|1500 MB|  
  
## <a name="other-ways-to-set-the-memory-allocation-limit"></a>Outras maneiras de definir o limite de alocação de memória  
  
#### <a name="to-set-the-zm-compiler-option-in-the-visual-studio-development-environment"></a>Para definir a opção do compilador /Zm no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  No painel de navegação, selecione **propriedades de configuração**, **C/C++**, **linha de comando**.  
  
3.  Insira o **/Zm** opção de compilador no **opções adicionais** caixa.  
  
#### <a name="to-set-the-zm-compiler-option-programmatically"></a>Para definir a opção do compilador /Zm via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)