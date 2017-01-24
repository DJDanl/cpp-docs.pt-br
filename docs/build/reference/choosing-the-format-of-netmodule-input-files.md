---
title: "Escolhendo o formato de arquivos de entrada .netmodule | Microsoft Docs"
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
ms.assetid: 4653d1bd-300f-4083-86f5-d1a06f44e61c
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Escolhendo o formato de arquivos de entrada .netmodule
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um arquivo de .obj MSIL \(compilado com [\/clr](../../build/reference/clr-common-language-runtime-compilation.md)\) também pode ser usado como um arquivo de .netmodule.  os arquivos de .obj contêm metadados e símbolos nativos.  .netmodules contêm apenas metadados.  
  
 Você pode passar um arquivo de .obj a MSIL qualquer outro compilador do Visual Studio pela opção do compilador de \/addmodule \(porém lembre\-se de que o arquivo de .obj se torna na parte do assembly resultante e deve ser enviado ao assembly\).  Por exemplo, Visual C \#e Visual Basic têm a opção do compilador do \/addmodule.  
  
> [!NOTE]
>  Na maioria dos casos, você precisará passar para o vinculador o arquivo de .obj de compilação que criou o módulo do .net.  Uma exceção é se o .netmodule foi criado com [\/clr: puro](../../build/reference/clr-common-language-runtime-compilation.md).  Passe um arquivo .dll do módulo ou de .netmodule MSIL ao vinculador pode resultar em LNK1107.  
  
 os arquivos de .obj, junto com seus arquivos associados de .h, referenciada pelo \#include na origem, permitem que os aplicativos de consumir o C\+\+ nativo no módulo, enquanto no arquivo de .netmodule, somente os tipos gerenciados podem ser consumidos pelo aplicativo c. criando  Se você tentar passar um arquivo de .obj a \#using, as informações sobre tipos nativos não estará disponível; \#include o arquivo de .h do arquivo de .obj em vez disso.  
  
 Outros compiladores do Visual Studio só podem consumir tipos gerenciados de um módulo.  
  
 Use o seguinte para determinar se você precisa usar um .netmodule ou um arquivo de .obj como o módulo está conectado ao vinculador Visual C\+\+:  
  
-   Se você estiver compilando com um compilador do Visual Studio diferente do Visual C\+\+, gerar um .netmodule e use o .netmodule como entrada para o vinculador.  
  
-   Se você estiver usando o compilador do Visual C\+\+ para gerar os módulos e se os módulos serão usados para criar algo diferente de uma biblioteca, use os arquivos de .obj gerados pelo compilador como o módulo a entrada para o vinculador; não use o arquivo de .netmodule como entrada.  
  
-   Se os seus módulos serão usados para criar uma biblioteca nativo \(não gerenciado\), use um arquivo de .obj como a entrada de módulo para o vinculador e gerencia um arquivo de biblioteca de .lib.  
  
-   Se os seus módulos serão usados para criar uma biblioteca gerenciado, e se toda a entrada de módulo para o vinculador será verificável \(gerado com \/clr:safe\), use arquivos de .obj como a entrada de módulo para o vinculador e gerencia um arquivo de biblioteca de assembly \(.dll\) ou de .netmodule \(módulo\).  
  
-   Se os seus módulos serão usados para criar uma biblioteca gerenciado, e se toda a entrada de módulo para o vinculador será gerado com \/clr:pure ou \/clr:safe, use arquivos de .obj como a entrada de módulo para o vinculador e gerencia um assembly \(.dll\) ou .netmodule \(módulo\) se você só quiser expor tipos gerenciados de biblioteca.  Se você quiser expor tipos gerenciados da biblioteca e se você deseja aplicativos de consumir o C\+\+ nativo na biblioteca, a biblioteca consistirá nos arquivos de .obj para os módulos componentes das bibliotecas \(você também pode querer enviar os arquivos de .h para cada módulo, assim podem ser referenciados com \#include de origem\).  
  
-   Se os seus módulos serão usados para criar uma biblioteca gerenciado, e se a entrada de um ou mais módulos ao vinculador será gerada somente com \/clr, use arquivos de .obj como a entrada de módulo para o vinculador e gerencia um assembly \(.dll\).  Se você quiser expor tipos gerenciados da biblioteca e se você deseja aplicativos de consumir o C\+\+ nativo na biblioteca, a biblioteca consistirá nos arquivos de .obj para os módulos componentes das bibliotecas \(você também pode querer enviar os arquivos de .h para cada módulo, assim podem ser referenciados com \#include de origem\).  
  
## Consulte também  
 [Arquivos .netmodule como entrada de vinculador](../Topic/.netmodule%20Files%20as%20Linker%20Input.md)