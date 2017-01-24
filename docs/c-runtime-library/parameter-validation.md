---
title: "Valida&#231;&#227;o do par&#226;metro | Microsoft Docs"
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
  - "C"
helpviewer_keywords: 
  - "parâmetros, validação"
ms.assetid: 019dd5f0-dc61-4d2e-b4e9-b66409ddf1f2
caps.latest.revision: 9
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Valida&#231;&#227;o do par&#226;metro
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A maioria das funções de segurança aprimoradas de CRT e de muitas das funções preexistentes valida seus parâmetros.  Isso pode incluir verifique os ponteiros para NULL, verificando se os números inteiros caíssem em um intervalo válido, ou verificar se os valores de enumeração é válido.  Quando um parâmetro inválido for localizado, o manipulador inválido do parâmetro será executado.  
  
## Rotina inválido de manipulador de parâmetro  
 O comportamento de tempo de execução C quando um parâmetro inválido é encontrado é chamar o manipulador inválido alocado no momento do parâmetro.  O parâmetro inválido padrão invoca o relatório de falhas de Watson, o que faz com que o aplicativo falhar e pergunta ao usuário se deseja carregar o despejo de memória a Microsoft para análise.  No modo de depuração, um parâmetro inválido também resulta em uma asserção com falha.  
  
 Esse comportamento pode ser alterado usando a função [set\_invalid\_parameter\_handler, \_set\_thread\_local\_invalid\_parameter\_handler](../c-runtime-library/reference/set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md) para definir o manipulador inválido do parâmetro à sua própria função.  Se a função que você especifica não finaliza o aplicativo, o controle é retornado à função que recebeu os parâmetros inválidos, e essas funções normalmente cessarão a execução, retornam o código de erro e, `errno` definido como um código de erro.  Em muitos casos, o valor de `errno` e o valor de retorno são ambos `EINVAL`, indicando um parâmetro inválido.  Em alguns casos, um código de erro mais específico for retornado, como `EBADF` para um ponteiro de arquivo incorreto passado como um parâmetro.  Para obter mais informações sobre o errno, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Consulte também  
 [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md)   
 [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)