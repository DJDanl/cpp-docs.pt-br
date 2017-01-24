---
title: "Aviso D9025 (linha de comando) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "D9025"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "D9025"
ms.assetid: 6edff72c-1508-46c2-99f4-0e4b3c5e60c9
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso D9025 (linha de comando)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

substituindo “opção” com “option2”  
  
 A opção *opção* foi especificada mas substituída *por option2*.  A opção *option2* foi usada.  
  
 Se as duas opções especificam políticas contraditórias ou incompatíveis, a política especificada ou implícita na opção do mais distante até linha de comando é usada exatamente.  
  
 Se você obtiver esse aviso ao criar o ambiente de desenvolvimento, e não certifique\-se de que as opções em conflito estão se originando, considere o seguinte:  
  
-   Uma opção pode ser especificada no código ou em configurações de projeto do projeto.  Se você examina [Páginas de propriedades de linha de comando](../../ide/command-line-property-pages.md) do compilador e se você vir as opções conflitante no campo de **Todas as opções** as opções estão definidas nas páginas de propriedades do projeto, caso contrário, as opções são definidas no código\-fonte.  
  
     Se as opções são definidas nas páginas de propriedades do projeto, examine a página de propriedades de pré\-processador do compilador \(com o nó do projeto selecionado no Solution Explorer\).  Se você não vir a opção definida ativa, verifique as configurações de propriedade de pré\-processador para cada arquivo de origem \(no Solution Explorer\) para ter certeza de que não é adicionado.  
  
     Se as opções são definidas no código pode ser definido no código ou nos cabeçalhos do windows.  Você pode tentar criar um arquivo[\/P](../../build/reference/p-preprocess-to-a-file.md)pré\-processados \(\) e procurará\-lo pelo símbolo.