---
title: "Aloca&#231;&#227;o da pilha | Microsoft Docs"
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
ms.assetid: 098e51f2-eda6-40d0-b149-0b618aa48b47
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aloca&#231;&#227;o da pilha
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O prólogo de uma função é responsável por atribuir o espaço de pilha para variáveis locais, salvo registros, parâmetros de pilha, e parâmetros de registro.  
  
 A área de parâmetro sempre está na parte inferior da pilha \(mesmo se o alloca é usado\), de modo que sempre seja adjacente ao endereço de retorno durante qualquer chamada de função.  Contém pelo menos quatro entradas, mas sempre espaço suficiente para manter todos os parâmetros necessários por qualquer função que possa ser chamada.  Observe que o espaço é alocado sempre para os parâmetros do registro, mesmo se eles mesmos parâmetros são dirigidos nunca à pilha; um receptor é garantido que o espaço foi atribuído para todos os seus parâmetros.  Endereços domiciliários são necessários para os argumentos do registro para que uma área contígua está disponível no caso da função chamada precisa executar o endereço da lista de argumentos \(va\_list\) ou um argumento individual.  Essa área também fornece um local conveniente para salvar argumentos de registro durante a execução de thunk e como uma opção de depuração \(por exemplo, torna os argumentos fácil de localizar durante a depuração se são armazenados nos endereços domiciliários no código de prólogo\).  Mesmo se a função chamada tem menos de 4 parâmetros, esses locais de 4 pilhas possuidos efetivamente pela função chamada, e podem ser usados pela função chamada para outros fins além dos valores de registro do parâmetro de salvar.  O chamador não pode salvar as informações nessa região de pilha através de uma chamada de função.  
  
 Se o espaço é alocado dinamicamente \(alloca\) em uma função, então um registro permanente deve ser usado como um ponteiro de quadro para marcar a base da parte fixa de pilha e esse registro deve ser salvo e inicializada em prólogo.  Observe que quando o alloca for usado, chamadas para o mesmo receptor do mesmo chamador podem ter diferentes endereços domiciliários para seus parâmetros do registro.  
  
 A pilha será sempre mantida o byte 16 alinhado, a não ser que dentro de prólogo \(por exemplo, depois que o endereço de retorno é empurrado\), e exceto onde observado em [Tipos de função](../build/function-types.md) para qualquer classe de funções do quadro.  
  
 A seguir está um exemplo de layout de pilha onde a função A chama uma função B. de não folha.  O prólogo da função já tem o espaço alocado para todos os parâmetros do registro e de pilha exigidos por B na parte inferior da pilha.  A chamada pressiona o endereço de retorno e o prólogo de b atribui o espaço para suas variáveis locais, registros permanentes, e o espaço necessário para que chama funções.  Se B usa o alloca, o espaço é alocado entre a variável local\/área de salvar permanente do registro e a área de pilha do parâmetro.  
  
 ![Gráfico de exemplo 5 de conversão AMD](../build/media/vcamd_conv_ex_5.png "vcAmd\_conv\_ex\_5")  
  
 Quando a função B chama outra função, o endereço de retorno é empurrado logo abaixo do endereço domiciliário para RCX.  
  
## Consulte também  
 [Uso da pilha](../build/stack-usage.md)