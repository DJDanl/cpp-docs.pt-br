---
title: "/APPCONTAINER (aplicativo da Windows Store) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 9a432db5-7640-460b-ab18-6f61fa7daf6f
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /APPCONTAINER (aplicativo da Windows Store)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica se o vinculador cria uma imagem executável que deve ser executada em um contêiner de aplicativo.  
  
## Sintaxe  
  
```  
/APPCONTAINER[:NO]  
```  
  
## Comentários  
 Por padrão, \/APPCONTAINER está desativado.  
  
 Esta opção modifica um executável para indicar se o aplicativo deve ser executado no ambiente de isolamento de processo de appcontainer.  Especifica \/APPCONTAINER para um aplicativo que deve ser executado no appcontainer ambiente\- por exemplo, um aplicativo de [!INCLUDE[win8_appstore_long](../../build/reference/includes/win8_appstore_long_md.md)] . \(A opção é definida automaticamente no Visual Studio quando você cria um app [!INCLUDE[win8_appstore_long](../../build/reference/includes/win8_appstore_long_md.md)] a partir de um modelo.\) Para um aplicativo de área de trabalho, especifique \/APPCONTAINER:NO ou apenas omita a opção.  
  
 A opção de \/APPCONTAINER foi introduzida em [!INCLUDE[win8](../../build/includes/win8_md.md)].  
  
### Para definir essa opção de vinculador no Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter mais informações, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Expanda o nó **Propriedades de Configuração**.  
  
3.  Expanda o nó **Vinculador**.  
  
4.  Selecione a página de propriedades **Linha de Comando** .  
  
5.  Em **Opções Adicionais**, digite `/APPCONTAINER` ou `/APPCONTAINER:NO`.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)