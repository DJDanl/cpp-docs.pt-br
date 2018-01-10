---
title: "-GUARD (habilitar verificações de proteção) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 72758e23-70ac-4616-94d7-d767477406d1
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 48abdc4f923ed01ecba482b82da897d06fd56dcd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="guard-enable-guard-checks"></a>/GUARD (habilitar verificações de proteção)
Especifica o suporte para verificações de proteção de fluxo de controle na imagem executável.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/GUARD:{CF|NO}  
```  
  
## <a name="remarks"></a>Comentários  
 Quando /Guard: CF for especificado, o vinculador modifica o cabeçalho de um arquivo. dll ou .exe para indicar o suporte para verificações de tempo de execução de protetor de fluxo de controle (CFG). O vinculador também adiciona os dados de endereço de destino de fluxo de controle necessário para o cabeçalho. Por padrão, /Guard: CF está desabilitado. Ele pode ser desabilitado explicitamente usando /GUARD:NO. Para ser eficiente, /Guard: CF também requer o [/DYNAMICBASE (aleatória de layout do espaço de endereço de uso)](../../build/reference/dynamicbase-use-address-space-layout-randomization.md) opção de vinculador, que é ativado por padrão.  
  
 Quando o código-fonte é compilado usando o [/Guard: CF](../../build/reference/guard-enable-control-flow-guard.md) opção, o compilador analisa o fluxo de controle examinando todas as chamadas indiretas para os endereços de destino possíveis. O compilador insere o código para verificar que o endereço de destino de uma instrução de chamada indireta está na lista de endereços de destino conhecidos em tempo de execução. Verifique se os sistemas operacionais que oferecem suporte a parada CFG um programa que falha um tempo de execução CFG. Isso torna mais difícil para um invasor executar um código mal-intencionado com corrupção de dados para alterar um destino de chamada.  
  
 A opção /Guard: CF deve ser especificada para o compilador e vinculador para criar imagens executáveis CFG habilitado. Código compilado, mas não vinculada usando /Guard: CF incorre em custos de verificações de tempo de execução, mas não habilitar a proteção de configuração. Quando a opção /Guard: CF é especificada para o `cl` comando para compilar e vincular em uma única etapa, o compilador passa o sinalizador para o vinculador. Quando o **protetor de fluxo de controle** propriedade é definida no Visual Studio, a opção /Guard: CF é passada para o compilador e vinculador. Quando arquivos de objeto ou bibliotecas foram compiladas separadamente, a opção deve ser especificada explicitamente no `link` comando.  
  
### <a name="to-set-this-linker-option-in-visual-studio"></a>Para definir essa opção do vinculador no Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda **propriedades de configuração**, **vinculador**, **linha de comando**.  
  
3.  Em **opções adicionais**, digite `/GUARD:CF`.  
  
## <a name="see-also"></a>Consulte também  
 [/Guard (habilitar o controle de fluxo de proteção)](../../build/reference/guard-enable-control-flow-guard.md)   
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)