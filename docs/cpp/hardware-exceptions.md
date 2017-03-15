---
title: "Exce&#231;&#245;es de hardware | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "erros [C++], hardware"
  - "erros [C++], nível inferior"
  - "exceções, hardware"
  - "exceções de hardware"
  - "erros de nível inferior"
ms.assetid: 06ac6f01-a8cf-4426-bb12-1688315ae1cd
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Exce&#231;&#245;es de hardware
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A maioria das exceções padrão reconhecidas pelo sistema operacional são exceções definidas por hardware.  O Windows reconhece algumas exceções de software de nível baixo, mas elas geralmente são mais bem tratadas pelo sistema operacional.  
  
 O Windows mapeia os erros de hardware de processadores diferentes para os códigos de exceção nesta seção.  Em alguns casos, um processador pode gerar somente um subconjunto dessas exceções.  O Windows pré\-processa informações sobre a exceção e emite o código de exceção apropriado.  
  
 As exceções de hardware reconhecidas pelo windows são resumidas na seguinte tabela:  
  
|Código da exceção|Causa da exceção|  
|-----------------------|----------------------|  
|**STATUS\_ACCESS\_VIOLATION**|Leitura ou gravação em um local de memória inacessível.|  
|**STATUS\_BREAKPOINT**|Encontro de um ponto de interrupção definido por hardware; usado somente por depuradores.|  
|**STATUS\_DATATYPE\_MISALIGNMENT**|Leitura ou gravação de dados em um endereço que não está alinhado corretamente; por exemplo, as entidades de 16 bits devem ser alinhadas em limites de 2 bytes. \(Não aplicável a processadores Intel 80*x*86\).|  
|**STATUS\_FLOAT\_DIVIDE\_BY\_ZERO**|Divisão do tipo de ponto flutuante por 0,0.|  
|**STATUS\_FLOAT\_OVERFLOW**|Expoente positivo máximo do tipo de ponto flutuante excedido.|  
|**STATUS\_FLOAT\_UNDERFLOW**|Magnitude excedida do expoente negativo mais baixo do tipo de ponto flutuante.|  
|**STATUS\_FLOATING\_RESEVERED\_OPERAND**|Usando um formato de ponto flutuante reservado \(uso inválido de formato\).|  
|**STATUS\_ILLEGAL\_INSTRUCTION**|Tentativa de executar um código de instrução não definido pelo processador.|  
|**STATUS\_PRIVILEGED\_INSTRUCTION**|Execução de uma instrução não permitida no modo atual do computador.|  
|**STATUS\_INTEGER\_DIVIDE\_BY\_ZERO**|Divisão de um tipo de inteiro por 0.|  
|**STATUS\_INTEGER\_OVERFLOW**|Tentativa de uma operação que excede o intervalo do inteiro.|  
|**STATUS\_SINGLE\_STEP**|Execução de uma instrução no modo de etapa única; usado somente por depuradores.|  
  
 Muitas das exceções listadas na tabela anterior devem ser tratadas por depuradores, pelo sistema operacional, ou outro código de nível baixo.  Com a exceção de erros de inteiro e de ponto flutuante, seu código não deve tratar esses erros.  Assim, geralmente você deve usar o filtro de tratamento de exceções para ignorar exceções \(avaliado como 0\).  Caso contrário, você poderá impedir que os mecanismos de nível inferior respondam adequadamente.  É possível, contudo, tomar precauções apropriadas contra o efeito potencial desses erros de baixo nível [gravando manipuladores de término](../cpp/writing-a-termination-handler.md).  
  
## Consulte também  
 [Escrevendo um manipulador de exceção](../cpp/writing-an-exception-handler.md)   
 [Tratamento de exceções estruturado](../cpp/structured-exception-handling-c-cpp.md)