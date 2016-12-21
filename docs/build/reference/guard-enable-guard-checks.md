---
title: "/GUARD (habilitar verifica&#231;&#245;es de prote&#231;&#227;o) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 72758e23-70ac-4616-94d7-d767477406d1
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /GUARD (habilitar verifica&#231;&#245;es de prote&#231;&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica o suporte para verificações de protetor de fluxo de controle da imagem executável.  
  
## Sintaxe  
  
```  
/GUARD:{CF|NO}  
```  
  
## Comentários  
 Quando \/GUARD:CF for especificado, o vinculador modifica o cabeçalho de um arquivo. dll ou .exe para indicar o suporte para verificações de tempo de execução de protetor de fluxo de controle \(CFG\).  O vinculador também adiciona os dados de endereço de destino de fluxo de controle necessário para o cabeçalho.  Por padrão, \/GUARD:CF está desabilitado.  Ele pode ser desabilitado explicitamente usando \/GUARD:NO.  Para ser eficiente, \/GUARD:CF também requer o [\/DYNAMICBASE \(usar aleatorização do layout de espaço do endereço\)](../../build/reference/dynamicbase-use-address-space-layout-randomization.md) opção de vinculador, que é ativado por padrão.  
  
 Quando o código\-fonte é compilado usando o [\/guard:cf](../../build/reference/guard-enable-control-flow-guard.md) opção, o compilador analisa o fluxo de controle examinando todas as chamadas indiretas para endereços de destino possíveis.  O compilador insere o código para verificar se que o endereço de destino de uma instrução de chamada indireta está na lista de endereços de destino conhecido em tempo de execução.  Verifique se os sistemas operacionais que oferecem suporte a parada CFG um programa que falha em tempo de execução do CFG.  Isso torna mais difícil para um invasor execute código mal\-intencionado usando dados corrompidos para alterar o destino de uma chamada.  
  
 A opção \/GUARD:CF deve ser especificada ao compilador e vinculador para criar imagens executáveis CFG habilitado.  Código compilado, mas não vinculados usando \/GUARD:CF incorre em custos de verificações de tempo de execução, mas não habilitar a proteção do CFG.  Quando a opção \/GUARD:CF é especificada para o `cl` comando para compilar e vincular em uma única etapa, o compilador passa o sinalizador para o vinculador.  Quando o **protetor de fluxo de controle** estiver definida no Visual Studio, a opção \/GUARD:CF é passada para o compilador e o vinculador.  Quando os arquivos de objeto ou bibliotecas foram compiladas separadamente, a opção deve ser especificada explicitamente no `link` comando.  
  
### Para definir essa opção do vinculador no Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter mais informações, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Expanda **Propriedades de configuração**, **vinculador**, **linha de comando**.  
  
3.  Em **Opções adicionais**, digite `/GUARD:CF`.  
  
## Consulte também  
 [\/guard \(habilitar proteção do fluxo de controle\)](../../build/reference/guard-enable-control-flow-guard.md)   
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)