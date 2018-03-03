---
title: -HIGHENTROPYVA (suporte a ASLR de 64 bits) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: fe35f9f7-d28e-4694-9aeb-a79db06168e0
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 059f6169cafc48fc67587ae2f5827966269e6ac7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="highentropyva-support-64-bit-aslr"></a>/HIGHENTROPYVA (dar suporte a ASLR de 64 bits)
Especifica que a imagem executável suporta uma ASLR (Address Space Layout Randomization) de 64 bits de alta entropia.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/HIGHENTROPYVA[:NO]  
```  
  
## <a name="remarks"></a>Comentários  
 Por padrão, /HIGHENTROPYVA está ativado para imagens executáveis de 64 bits. Não é aplicável para imagens executáveis de 32 bits. Para habilitar essa opção, o /DYNAMICBASE também deve estar ativado.  
  
 / HIGHENTROPYVA modifica o cabeçalho de um arquivo .dll ou .exe para indicar se a ASLR com endereços de 64 bits é suportada. Quando essa opção é definida em um arquivo executável e todos os módulos dos quais depende, um sistema operacional que dê suporte a ASLR de 64 bits pode rebasear os segmentos da imagem executável no tempo de carregamento usando endereços aleatórios em um espaço de endereço virtual de 64 bits. Esse grande espaço de endereço torna mais difícil para um invasor adivinhar a localização de uma região de memória específica.  
  
### <a name="to-set-this-linker-option-in-visual-studio"></a>Para definir essa opção do vinculador no Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda o **propriedades de configuração** nó.  
  
3.  Expanda o **vinculador** nó.  
  
4.  Selecione o **linha de comando** página de propriedades.  
  
5.  Em **opções adicionais**, digite `/HIGHENTROPYVA` ou `/HIGHENTROPYVA:NO`.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)