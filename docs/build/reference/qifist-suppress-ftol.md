---
title: -QIfist (Suprimir ftol) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /qifist
dev_langs:
- C++
helpviewer_keywords:
- QIfist compiler option [C++]
- -QIfist compiler option [C++]
- /QIfist compiler option [C++]
ms.assetid: 1afd32a5-f658-4b66-85f4-e0ce4cb955bd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 77ec65e330cebb1de718330ba129e960383b31c6
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="qifist-suppress-ftol"></a>/QIfist (suprimir _ftol)
Preterido. Suprime a chamada da função auxiliar `_ftol` quando é necessária uma conversão de um tipo de ponto flutuante para um tipo integral.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/QIfist  
```  
  
## <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  **/Qifist** só está disponível no compilador direcionamento x86; essa opção de compilador não está disponível nos compiladores direcionamento [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)] orARM.  
  
 Além de conversão de um tipo de ponto flutuante para tipo integral, o `_ftol` função garante que o modo de arredondamento da unidade de ponto flutuante (FPU) é em direção a zero (truncado), definindo bits 10 e 11 da palavra de controle. Isso garante que a conversão de um tipo de ponto flutuante para um tipo integral ocorre conforme descrito pelo padrão ANSI C (a parte fracionária do número é descartada). Ao usar **/QIfist**, essa garantia não se aplica. O modo de arredondamento será um dos quatro conforme documentado nos manuais de referência do Intel:  
  
-   Arredondar para o número mais próximo (mesmo se equidistante)  
  
-   Arredondar para o infinito negativo  
  
-   Arredondar para o infinito positivo  
  
-   Arredondar em direção a zero  
  
 Você pode usar o [control87, controlfp, \__control87_2](../../c-runtime-library/reference/control87-controlfp-control87-2.md) função C Run-Time para modificar o comportamento de arredondamento de FPU. O padrão de modo de FPU de arredondamento é "Round em direção a mais próximo." Usando **/QIfist** pode melhorar o desempenho do seu aplicativo, mas não sem riscos. Você deve testar completamente as partes do seu código que são sensíveis a modos de arredondamento antes de depender de código compilado com **/QIfist** em ambientes de produção.  
  
 [/arch (x86)](../../build/reference/arch-x86.md) e **/QIfist** não pode ser usado em compiland o mesmo.  
  
> [!NOTE]
>  **/Qifist** é não em vigor por padrão porque o arredondamento bits também afetam flutuante de ponto flutuante do ponto de arredondamento (que ocorre após cada cálculo), para que quando você define os sinalizadores de arredondamento de estilo C (em direção a zero), o ponto flutuante cálculos podem ser diferentes. **/Qifist** não deve ser usado se seu código depende do comportamento esperado de truncar a parte fracionária do número de ponto flutuante. Se você não tiver certeza, não use **/QIfist**.  
  
 O **/QIfist** opção é preterida, a partir do Visual Studio 2005. O compilador fez melhorias significativas em float para int velocidade de conversão. Para obter uma lista de opções do compilador preterido, consulte **preteridos e removidos opções do compilador** na [opções do compilador listadas por categoria](../../build/reference/compiler-options-listed-by-category.md).  
  
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