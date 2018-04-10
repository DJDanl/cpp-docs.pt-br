---
title: -guard (Habilitar proteção de fluxo de controle) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: article
f1_keywords:
- /guard
- VC.Project.VCCLCompilerTool.ControlFlowGuard
dev_langs:
- C++
ms.assetid: be495323-f59f-4cf3-a6b6-8ee69e6a19dd
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e7f87c101122b8f74e3bffefd42b1d9a9ddc55c3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="guard-enable-control-flow-guard"></a>/guard (habilitar proteção do fluxo de controle)
Habilite a geração de compilador protetor de fluxo de controle de verificações de segurança.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/guard:cf[-]  
```  
  
## <a name="remarks"></a>Comentários  
 O **/Guard: CF** opção faz com que o compilador analisar o fluxo de controle para destinos de chamada indireta em tempo de compilação e, em seguida, inserir o código para verificar se os destinos em tempo de execução. Por padrão, **/Guard: CF** está desativado e deve ser explicitamente habilitado. Para desabilitar explicitamente essa opção, use **/guard:cf-**.  
  
 Quando o **/Guard: CF** opção de proteção de fluxo de controle (CFG) for especificada, o compilador e vinculador inserem verificações de segurança de tempo de execução extra para detectar tentativas de comprometer seu código. Durante a compilação e o vínculo, todas as chamadas indiretas em seu código são analisadas para localizar todos os locais em que o código pode acessar quando ele é executado corretamente. Essas informações são armazenadas em estruturas extras nos cabeçalhos de seus binários. O compilador também insere uma verificação antes de cada chamada indireta em seu código que garante que o destino é um dos locais verificados. Se a verificação falhar em tempo de execução em um sistema operacional com suporte a configuração, o sistema operacional fecha o programa.  
  
 Um ataque comuns em software tira proveito dos bugs no tratamento entradas extremas ou inesperadas. Entrada concebida cuidadosamente para o aplicativo pode substituir um local que contém um ponteiro para o código executável. Isso pode ser usado para redirecionar o fluxo de controle para código controlado pelo invasor. As verificações de tempo de execução CFG não corrigir os erros de corrupção de dados em seu executável. Eles em vez disso, fazer mais difícil para um invasor usá-los para executar código arbitrário. CFG é uma ferramenta de atenuação que evita que as chamadas para locais diferentes pontos de entrada de função em seu código. É semelhante a como prevenção de execução de dados (DEP), [/GS](../../build/reference/gs-buffer-security-check.md) verificações de pilha e [/DYNAMICBASE](../../build/reference/dynamicbase-use-address-space-layout-randomization.md) e [/HIGHENTROPYVA](../../build/reference/highentropyva-support-64-bit-aslr.md) endereço aleatorização do espaço (ASLR) inferior a chances que seu código se torna um vetor de exploração.  
  
 O **/Guard: CF** opção deve ser passada para ambos o compilador e vinculador para criar o código que usa o CFG explorar técnica de mitigação. Se o binário é construído usando um único `cl` de comando, o compilador passa a opção para o vinculador. Se você compilar e vincular separadamente, a opção deve ser definida em comandos de compilador e vinculador. A opção de vinculador /DYNAMICBASE também é necessária. Para verificar que o binário tem dados de configuração, use o `dumpbin /headers /loadconfig` comando. Tem ativado CFG binários `Guard` na lista de características EXE ou DLL e os sinalizadores de proteção incluem `CF Instrumented` e `FID table present`.  
  
 O **/Guard: CF** opção é incompatível com [/ZI](../../build/reference/z7-zi-zi-debug-information-format.md) (Editar e continuar informações de depuração) ou [/clr](../../build/reference/clr-common-language-runtime-compilation.md) (Common Language Runtime Compilation).  
  
 Código compilado usando **/Guard: CF** pode ser vinculado a bibliotecas e arquivos que não são compilados com a opção do objeto. Apenas este código, quando vinculados também usando o **/Guard: CF** opção e executar em um sistema operacional com suporte a configuração, tem proteção CFG. Como o código compilado sem a opção não irá parar um ataque, é recomendável que você use a opção em todo o código que você compilar. Há um tempo de execução pequeno custo de verificações de configuração, mas a análise de compilador tenta otimizar as verificações de saltos indiretos que podem ser comprovadamente seguros.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione **propriedades de configuração**, **C/C++**, **a geração de código**.  
  
3.  Selecione o **protetor de fluxo de controle** propriedade.  
  
4.  No controle de lista suspensa, escolha **Sim** para habilitar a proteção de fluxo de controle, ou **não** para desabilitá-lo.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)