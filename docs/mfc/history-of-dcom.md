---
title: "Hist&#243;rico de DCOM | Microsoft Docs"
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
helpviewer_keywords: 
  - "DCOM"
  - "DCOM, sobre DCOM"
  - "Automação remota, DCOM"
ms.assetid: c21aa0ea-1396-4b52-b77f-88fb0fdd2a5c
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Hist&#243;rico de DCOM
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando a automação foi introduzida primeiro ao princípio de 1993, era capaz de usar apenas entre os aplicativos executados no mesmo computador.  No entanto, como usarem os mesmos sustentamentos que o restante OLE, ou seja, ou COM \(Component Object Model\), pretendeu\-se sempre que se tornaria “remotable” quando COM próprio foi atualizado para incluir recursos comunicação remota.  Também planejou\-se que a transição da operação puramente local para a operação distribuída exigiria quase nenhuma alteração no código existente.  
  
 Assim que faz a comunicação remota”? “  O local COM ditou que o consumidor de uma interface reside e executa no mesmo computador que o provedor dessa interface.  Por exemplo, o Microsoft Visual Basic pode controlar uma cópia do Microsoft Excel no computador de área de trabalho, mas não é capaz de direcionar a execução do excel em outro computador.  Com o desenvolvimento de COM distribuída, o consumidor de uma interface já não precisar residir no mesmo computador que o de que o provedor da interface é executado.  
  
 Uma vez que foi adaptado COM ao trabalho por uma rede, então qualquer interface que não é associada a um modelo local de execução \(algumas interfaces tem a confiança inerente em instalações do computador local, como as interfaces de desenho cujos métodos têm identificadores para contextos de dispositivo como parâmetros\) teriam o recurso de distribuição.  Um consumidor da interface faz uma solicitação para uma interface especificada; essa interface pode ser fornecida por uma instância de um objeto que executa \(ou\) para ser executado em um computador diferente.  O mecanismo de distribuição em COM conectaria o consumidor do provedor de modo que as chamadas de método feitas pelo consumidor apareceriam no final do provedor, onde serão executados.  Todos os valores de retorno em posteriores serão enviados ao consumidor.  Para todos os fins práticos, o ato de distribuição é transparente ao consumidor e ao provedor.  
  
 Como uma variedade de COM agora existe.  DCOM \(distributed COM” para “\) enviados com as versões do Windows NT que começam com a versão 4,0 e que incluem o Windows 2000.  Desde o fim de 1996, também esteve disponível para as janelas 9x.  Em ambos os casos, o DCOM compõe um conjunto de substituição e de DLL adicionais, com alguns utilitários, que fornece recursos locais e remotas da.  Em virtude disso é agora uma parte inerentemente de plataformas de Win32\-based, e será disponibilizado em outras plataformas por outras empresas com o passar do tempo.  
  
## Nesta seção  
 [Onde a automação remoto se ajustar em?](../mfc/where-does-remote-automation-fit-in-q.md)  
  
 [A automação remoto fornece?](../mfc/what-does-remote-automation-provide-q.md)  
  
## Consulte também  
 [Automação remota](../mfc/remote-automation.md)