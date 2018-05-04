---
title: -Gs (controle pilha de chamadas de verificação) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /GS
dev_langs:
- C++
helpviewer_keywords:
- disabling stack probes
- GS compiler option [C++]
- /GS compiler option [C++]
- stack, stack probes
- stack probes
- -GS compiler option [C++]
- stack checking calls
ms.assetid: 40daed7c-f942-4085-b872-01e12b37729e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c5665187548b1f8ace41bed281684f1a830c0ad4
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="gs-control-stack-checking-calls"></a>/Gs (controlar chamadas de verificação da pilha)
Controla investigações de pilha.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Gs[size]  
```  
  
## <a name="arguments"></a>Arguments  
 `size`  
 (Opcional) O número de bytes que as variáveis locais podem ocupar antes que uma sonda de pilha seja iniciada. Se o **/Gs** opção for especificada sem uma `size` argumento, é o mesmo que especificar **/Gs0**,  
  
## <a name="remarks"></a>Comentários  
 Uma sonda de pilha é uma sequência de códigos que o compilador insere em cada chamada de função. Quando iniciada, uma sonda de pilha atinge de maneira favorável a memória pela quantidade de espaço necessária para armazenar as variáveis locais da função.  
  
 Se uma função exigir mais que `size` bytes de espaço de pilha para variáveis locais, sua sonda de pilha é iniciada. Por padrão, o compilador gera o código que inicia uma sonda de pilha quando uma função exige mais de uma página de espaço de pilha. Isso é equivalente a uma opção de compilador de **/Gs4096** para x86, [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)]e as plataformas ARM. Esse valor permite que um aplicativo e o gerenciador de memória do Windows aumentem a quantidade de memória confirmada dinamicamente para a pilha do programa no tempo de execução.  
  
> [!NOTE]
>  O valor padrão de **/Gs4096** permite que a pilha do programa de aplicativos do Windows a crescer corretamente em tempo de execução. Recomendamos que o valor padrão não seja alterado a menos que você saiba exatamente por que deve alterá-lo.  
  
 Alguns programas, por exemplo, drivers de dispositivo virtual, não requerem esse mecanismo de aumento de pilha padrão. Nesses casos, as sondas de pilha não são necessárias e você pode fazer com que o compilador deixe de gerá-las configurando `size` para um valor maior que aquilo que qualquer função exigirá para o armazenamento local da variável. Não são permitidos espaços entre **/Gs** e `size`.  
  
 **/ Gs0** ativa sondas de pilha para cada chamada de função que requer o armazenamento para variáveis locais. Isso pode causar um impacto negativo no desempenho.  
  
 Você pode ativar ou desativar as sondas de pilha usando [check_stack](../../preprocessor/check-stack.md). **/GS** e `check_stack` pragma não têm nenhum efeito em rotinas de biblioteca C padrão; elas afetam apenas as funções que você compilar.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **C/C++** pasta.  
  
3.  Selecione o **linha de comando** página de propriedades.  
  
4.  Digite a opção de compilador no **opções adicionais** caixa.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)