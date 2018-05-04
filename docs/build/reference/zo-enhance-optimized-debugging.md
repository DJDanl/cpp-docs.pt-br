---
title: -Zo (aprimorar a depuração otimizada) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- -Zo
- /Zo
dev_langs:
- C++
helpviewer_keywords:
- Zo compiler option [C++]
- /Zo compiler option [C++]
- -Zo compiler option [C++]
ms.assetid: eea8d89a-7fe0-4fe1-86b2-7689bbebbd7f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 013738ab05bf67d3db066d94d32d398a0555c55e
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="zo-enhance-optimized-debugging"></a>/Zo (Enhance Optimized Debugging)
Gere informações de depuração avançadas para código otimizado em compilações de depuração não.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
/Zo[-]  
```  
  
## <a name="remarks"></a>Comentários  
 O **/Zo** opção de compilador gera informações de depuração avançadas para código otimizado. Otimização pode usar registros para variáveis locais, reordenar código, vectorize loops e chamadas de função embutida. Essas otimizações podem obscurecer a relação entre o código-fonte e o código de objeto compilado. O **/Zo** opção faz com que o compilador gere informações de depuração adicionais para variáveis locais e funções embutidas. Usá-lo para ver as variáveis no **Autos**, **locais**, e **inspecionar** windows quando você percorrer o código no depurador do Visual Studio otimizado. Ele também permite que os rastreamentos de pilha mostrar as funções embutidas no depurador WinDBG. Depurar compilações que desabilitou otimizações ([/Od](../../build/reference/od-disable-debug.md)) não é necessário para as informações de depuração adicionais geradas quando **/Zo** for especificado. Use o **/Zo** alternar para configurações de versão de depuração com a otimização ativada. Para obter mais informações sobre opções de otimização, consulte [/O opções (otimizar código)](../../build/reference/o-options-optimize-code.md). O **/Zo** opção é habilitada por padrão no Visual Studio quando você especificar as informações de depuração com **/Zi** ou **/Z7**. Especifique **/Zo-** explicitamente desabilitar essa opção de compilador.  
  
 O **/Zo** comutador está disponível a partir do Visual Studio 2013 atualização 3 e substitui anteriormente não documentados **/d2Zi+** alternar.  
  
### <a name="to-set-the-zo-compiler-option-in-visual-studio"></a>Para definir a opção de compilador /Zo no Visual Studio  
  
1.  Abra o **páginas de propriedade** caixa de diálogo para o projeto. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **propriedades de configuração**, **C/C++** pasta.  
  
3.  Selecione o **linha de comando** página de propriedades.  
  
4.  Modificar o **opções adicionais** propriedade incluir `/Zo` e, em seguida, escolha **Okey**.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [/O opções (otimizar código)](../../build/reference/o-options-optimize-code.md)   
 [/Z7, /Zi, /ZI (formato de informações de depuração)](../../build/reference/z7-zi-zi-debug-information-format.md)   
 [Editar e continuar](/visualstudio/debugger/edit-and-continue)