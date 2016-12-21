---
title: "Regras de consist&#234;ncia para /Yc e /Yu | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/yc"
  - "/yu"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /Yc (C++)"
  - "Opção de compilador /Yu (C++)"
  - "Opção de compilador Yc [C++]"
  - "Opção de compilador -Yc [C++]"
  - "Opção de compilador Yu [C++]"
  - "Opção de compilador -Yu [C++]"
ms.assetid: 9dfb0e32-ec9b-4a36-9355-27a0e5fba512
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Regras de consist&#234;ncia para /Yc e /Yu
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Quando você usa um cabeçalho pré\-compilado criado usando \/Yc ou \/Yu, o compilador compara o ambiente atual da compilação ao que existiu quando você criou o arquivo de .pch.  Especifique um ambiente consistente com anterior \(usando opções consistentes, pragmas do compilador, e assim por diante\) para a compilação atual.  Se o compilador detectar uma inconsistência, o emitirá um aviso e identifica a inconsistência sempre que possível.  Esses avisos não indica necessariamente um problema com o arquivo de .pch; advertem\-no somente de conflitos possíveis.  As seções a seguir explicam os requisitos de consistência para cabeçalhos pré\-compilados.  
  
## Consistência da opção do compilador  
 A tabela a seguir lista as opções do compilador que podem disparar um aviso de inconsistência ao usar um cabeçalho pré\-compilado.  
  
|Opção|Nome|Regra|  
|-----------|----------|-----------|  
|\/D|Defina constantes e macros|Deve ser igual entre a compilação que criou o cabeçalho pré\-compilado e a compilação atual.  O estado de constantes definidas não está marcada, mas os resultados imprevisíveis podem ocorrer se os arquivos dependem dos valores de constantes alteradas.|  
|\/E ou \/EP|Saída de pré\-processador de cópia para a saída padrão|Os cabeçalhos pré\-compilados não funcionam com a opção \/E ou \/EP.|  
|\/Fr ou \/FR|Gerencia as informações do navegador de origem da Microsoft|Para que as opções de \/Fr e \/FR são válidos com a opção \/Yu, também devem ter sido aplicado quando o cabeçalho pré\-compilado foi criado.  As compilações subsequentes que usam o cabeçalho pré\-compilado também gerencia as informações do navegador de origem.  Informações do navegador é colocada em um único arquivo de .sbr e referenciada por outros arquivos da mesma maneira como as informações de CodeView.  Não é possível substituir a colocação de informações do navegador de origem.|  
|\/GA, \/GD, \/GE, \/Gw, \/GW ou|Opções de protocolo do windows|Deve ser igual entre a compilação que criou o cabeçalho pré\-compilado e a compilação atual.  Se essas opções diferem, ocorrerá uma mensagem de aviso.|  
|\/Zi|Gerencia informações de depuração completo|Se essa opção for aplicado quando o cabeçalho pré\-compilado é criado, as compilações subsequentes que usam o precompilation podem usar essas informações de depuração.  \/Zi Se não for aplicado quando o cabeçalho pré\-compilado é criado, as compilações subsequentes que usam o precompilation e o gatilho da opção \/Zi um aviso.  Informações de depuração é colocada no arquivo do objeto atual, e símbolos locais definidos no cabeçalho pré\-compilado não estão disponíveis para o depurador.|  
  
> [!NOTE]
>  A facilidade pré\-compilado do cabeçalho é planejado para uso apenas com um arquivo com arquivos de origem de 2.0 C e C\+\+.  
  
## Inclua a consistência de caminho  
 Um cabeçalho pré\-compilado criado com \/Yc não contém informações sobre o caminho de inclusão que estava em vigor quando você criou o arquivo de .pch.  Quando você usa um arquivo de .pch, o compilador sempre usa o caminho de inclusão especificado na compilação atual.  
  
## Consistência do arquivo de origem  
 Quando você usa um cabeçalho pré\-compilado, o compilador ignora todas as políticas de pré\-processador \(inclusive pragmas\) que aparecem antes de pragma de hdrstop.  A compilação especificada por essas políticas de pré\-processador deve ser igual à compilação usada para criar o arquivo de cabeçalho pré\-compilado.  
  
## Consistência de pragma  
 Os pragmas processados durante a compilação de um cabeçalho pré\-compilado geralmente afetam o arquivo no qual o cabeçalho pré\-compilado é usada subsequentemente.  A seguinte efeito de pragmas somente o código dentro do arquivo de .pch; não afetam o código que usa subsequentemente o arquivo de .pch:  
  
||||  
|-|-|-|  
|Comment|página|legenda|  
|Linesize|pagesize|Nome|  
|Message \(Mensagem\)|skip||  
  
 Os seguintes pragmas são retidos como parte de um cabeçalho pré\-compilado, e afetam o restante de uma compilação que usa o cabeçalho pré\-compilado:  
  
||||  
|-|-|-|  
|alloc\_text|função|optimize|  
|auto\_inline|inline\_depth|Bloco|  
|check\_pointer|inline\_recursion|same\_seg|  
|check\_stack|intrínseco|aviso|  
|code\_seg|loop\_opt||  
|data\_seg|native\_caller||  
  
## Consulte também  
 [Regras de consistência do cabeçalho pré\-compilado](../../build/reference/precompiled-header-consistency-rules.md)   
 [\/Yc \(criar arquivo de cabeçalho pré\-compilado\)](../../build/reference/yc-create-precompiled-header-file.md)   
 [\/Yu \(usar arquivo de cabeçalho pré\-compilado\)](../../build/reference/yu-use-precompiled-header-file.md)