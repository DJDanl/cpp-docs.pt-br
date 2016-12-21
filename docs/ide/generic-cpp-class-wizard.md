---
title: "Assistente da Classe C++ Gen&#233;rica | Microsoft Docs"
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
  - "vc.codewiz.class.generic"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente da Classe C++ Genérica [C++]"
ms.assetid: aa95be9e-fc1b-45db-a11d-0d32c4929077
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assistente da Classe C++ Gen&#233;rica
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Adiciona uma classe genérica do C\+\+ a um projeto.  A classe herda da ATL ou MFC.  
  
 **Nome da classe**  
 Define o nome da nova classe.  
  
 **arquivo. h**  
 Define o nome do arquivo de cabeçalho para a nova classe.  Por padrão, esse nome se baseia o nome fornecido na  **nome da classe**.  Para salvar o arquivo de cabeçalho para o local de sua preferência ou para acrescentar a declaração de classe para um arquivo existente, clique no botão de reticências \(**...**\).  Se você especifica um arquivo existente, quando você clica em  **Concluir**, o assistente solicita que você especifique se a declaração de classe deve ser acrescentada ao conteúdo do arquivo.  Para acrescentar a declaração, clique em  **Sim**; para retornar ao assistente e especificar outro nome de arquivo, clique em  **não**.  
  
 **arquivo. cpp**  
 Define o nome do arquivo de implementação da nova classe.  Por padrão, esse nome se baseia o nome fornecido na  **nome da classe**.  Para salvar o arquivo de implementação para o local de sua preferência ou para acrescentar a definição de classe para um arquivo existente, clique no botão de reticências \(**...**\).  Se você especifica um arquivo existente, quando você clica em  **Concluir**, o assistente solicita que você especifique se a definição de classe deve ser acrescentada ao conteúdo do arquivo.  Para acrescentar a definição, clique em  **Sim**; para retornar ao assistente e especificar outro nome de arquivo, clique em  **não**.  
  
 **Classe base**  
 Define a classe base para a nova classe.  
  
 **Access**  
 Define o acesso para os membros da classe base para a nova classe.  Modificadores de acesso são as palavras\-chave que especificam o nível de acesso de outras classes para as funções de membro de classe.  Para obter mais informações sobre como especificar o acesso, consulte [Controle de acesso a membro](../cpp/member-access-control-cpp.md).  Por padrão, o nível de acesso de classe é definido como `public`.  
  
-   `public`  
  
-   `protected`  
  
-   `private`  
  
-   **Padrão** \(nenhum modificador de acesso é gerado\).  
  
 **Destrutor virtual**  
 Especifica se o destruidor de classe é virtual.  Uso de um destruidor virtual ajuda a garantir que o destruidor correto é chamado quando a instâncias de classes derivadas são excluídas.  
  
 **Interno**  
 Gera o construtor da classe e a definição de classe como funções embutidas no arquivo de cabeçalho.  
  
 **Managed**  
 Quando selecionada, adiciona um arquivo de cabeçalho e de classe gerenciado.  Quando desmarcada, adiciona um arquivo de classe e o cabeçalho nativo.  
  
## Consulte também  
 [Adicionando uma classe do C\+\+ genérica](../ide/adding-a-generic-cpp-class.md)