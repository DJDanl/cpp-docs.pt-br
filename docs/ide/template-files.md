---
title: "Arquivos de modelo | Microsoft Docs"
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
  - "assistentes personalizados, arquivos de modelo"
  - "Arquivos  [C++], criado por Assistente Personalizado"
  - "modelos [C++], para assistentes"
ms.assetid: 48fae3d8-3a53-4f62-8010-144c5ffe334e
caps.latest.revision: 8
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Arquivos de modelo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os modelos que compõem um assistente são uma coleção de arquivos de texto que contenham alguns  [diretivas simples](../ide/template-directives.md) analisada e são processadas de acordo com o usuário de entrada e adicionado ao projeto inicial.  As informações apropriadas para os modelos de análise são obtidas acessando diretamente da tabela de símbolos do controle wizard.  
  
 O exemplo a seguir é um arquivo de modelo muito simples para um assistente que solicita que o usuário selecione a ou b.  
  
## Exemplo  
  
```  
This file has been created by My Custom wizard.  
You selected:  
[!if TYPE_A]  
Type A  
[!else]  
Type B  
[!endif]  
The name of this project is [!output PROJECT_NAME].root.cpp:  
```  
  
 Se o usuário escolher o tipo B, o modelo acima seria processado da seguinte maneira:  
  
  **Este arquivo foi criado pelo assistente meu personalizada.  Você selecionou:**  
**Tipo B**  
**O nome deste projeto é MyApp8.**    
## Saída  
  
```  
This file has been created by My Custom wizard.  
You selected:  
Type B  
The name of this project is MyApp8.  
```  
  
 **Nota**  a sintaxe acima é nova no Visual C\+\+.NET.  Sintaxe de versões anteriores do Visual C\+\+ não é suportada no Visual C\+\+.NET.  
  
## Consulte também  
 [Arquivos criados para o assistente](../ide/files-created-for-your-wizard.md)   
 [Assistente Personalizado](../ide/custom-wizard.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)   
 [Arquivo Templates.inf](../Topic/Templates.inf%20File.md)