---
title: "Vari&#225;vel &#39;&lt; variablename &gt;&#39; &#233; passada por refer&#234;ncia antes que tenha sido atribu&#237;do um valor | Microsoft Docs"
ms.custom: ""
ms.date: "11/23/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-visual-basic"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vbc42030"
  - "BC42030"
helpviewer_keywords: 
  - "BC42030"
ms.assetid: 8f1aae99-f032-4fdf-b6dc-3360cc5b94de
caps.latest.revision: 11
caps.handback.revision: 11
author: "stevehoag"
ms.author: "shoag"
manager: "wpickett"
---
# Vari&#225;vel &#39;&lt; variablename &gt;&#39; &#233; passada por refer&#234;ncia antes que tenha sido atribu&#237;do um valor
Variável '\< variablename \>' é passada por referência antes que tenha sido atribuído um valor. Uma exceção de referência nula pode ocorrer em tempo de execução.  
  
 Uma chamada de procedimento passa uma variável como um argumento para um `ByRef` parâmetro antes que qualquer valor seja atribuído à variável.  
  
 Se nunca tiver sido atribuída um valor uma variável, ela armazena o valor padrão para seu tipo de dados. Para um tipo de dados de referência, o valor padrão é [nada](../Topic/Nothing%20\(Visual%20Basic\).md). Ler uma variável de referência que tem um valor de `Nothing` pode causar um <xref:System.NullReferenceException> em algumas circunstâncias.  
  
 Passar um argumento para um procedimento `ByRef` expõe a variável implícita ao argumento a possíveis modificações pelo procedimento.  
  
 Por padrão, essa mensagem é um aviso. Para obter mais informações sobre como ocultar avisos ou tratar avisos como erros, consulte [Configurando avisos no Visual Basic](../Topic/Configuring%20Warnings%20in%20Visual%20Basic.md).  
  
 **ID do erro:** BC42030  
  
### Para corrigir este erro  
  
-   Se você pretende que o procedimento para atribuir um valor à variável por meio de `ByRef` argumento, e se não importa se a variável já contém um valor, em seguida, nenhuma ação é necessária.  
  
-   Se a lógica no procedimento lê o argumento antes de atribuí\-lo qualquer valor, e se a variável for de um tipo de valor, certifique\-se de que a lógica do procedimento não depende do fato da variável armazenar seu valor padrão ou não.  
  
-   Se a lógica no procedimento lê o argumento antes de atribuí\-lo qualquer valor, e se a variável for de um tipo de referência, certifique\-se de que a lógica do procedimento pode manipular um valor de `Nothing`. Por exemplo, ele poderia usar um [Instrução Try...Catch...Finally](../Topic/Try...Catch...Finally%20Statement%20\(Visual%20Basic\).md) para capturar uma <xref:System.NullReferenceException>.  
  
## Consulte também  
 [Instrução Dim](../Topic/Dim%20Statement%20\(Visual%20Basic\).md)   
 [Tipos de valor e referência](../Topic/Value%20Types%20and%20Reference%20Types.md)   
 [Passando argumentos por valor e por referência](../Topic/Passing%20Arguments%20by%20Value%20and%20by%20Reference%20\(Visual%20Basic\).md)   
 [ByRef](../Topic/ByRef%20\(Visual%20Basic\).md)   
 [Declaração de variável](../Topic/Variable%20Declaration%20in%20Visual%20Basic.md)   
 [Solucionando problemas de variáveis](../Topic/Troubleshooting%20Variables%20in%20Visual%20Basic.md)