---
title: "Sequ&#234;ncia de opera&#231;&#245;es para cria&#231;&#227;o de controles ActiveX | Microsoft Docs"
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
  - "Controles ActiveX [C++], criando"
  - "Controles ActiveX MFC [C++], criando"
  - "Controles OLE [C++], MFC"
  - "sequência [C++]"
  - "sequência [C++], para criar controles ActiveX"
ms.assetid: 7d868c53-a0af-4ef6-a89c-e1c03c583a53
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Sequ&#234;ncia de opera&#231;&#245;es para cria&#231;&#227;o de controles ActiveX
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A tabela a seguir mostra a função e a função da estrutura na criação dos controles ActiveX \(anteriormente conhecido como controladores OLE\).  
  
### Criando controles ActiveX  
  
|Tarefa|Você fizer|A estrutura faz|  
|------------|----------------|---------------------|  
|Crie uma estrutura de controle ActiveX.|Execute o assistente de controle ActiveX de MFC para criar o controle.  Especifique as opções que você deseja nas páginas de opções.  As opções incluem o tipo e o nome do controle no projeto, em licenciamento do, em subclassing, e cerca de em um método na caixa.|O assistente de controle ActiveX de MFC cria os arquivos para um controle ActiveX com a funcionalidade básica, incluindo arquivos de origem do aplicativo, controle, e a página de propriedades ou páginas; um arquivo de recurso; um arquivo de projeto; e outro, qualquer personalizada para suas especificações.|  
|Veja o que o controle e o assistente de controle ActiveX oferecem sem adicionar uma linha de seu próprio código.|Criar o controle ActiveX e teste\-o com o Internet Explorer ou [Exemplo de TSTCON](../top/visual-cpp-samples.md).|O controle em execução do tem a capacidade de ser redimensionado e movido.  Também tem um método de **Caixa Sobre** \(se escolhido\) que pode ser invocado.|  
|Implementar os métodos e as propriedades de controle.|Implementar os métodos e propriedades controle\- específicos adicionando funções de membro para fornecer uma interface expõe aos dados de controle.  Adicionar variáveis de membro para manter estruturas de dados e usar manipuladores de eventos de eventos acionados quando você determina.|A estrutura já definiu um mapa para dar suporte aos eventos de controle, propriedades, e os métodos, deixando o para passe o mouse sobre como as propriedades e os métodos são implementados.  A página de propriedades padrão será visível e uma opção sobre o método da caixa é fornecida.|  
|Construir a página de propriedades ou páginas do controle.|Use os editores de recursos do Visual C\+\+ para editar visualmente a interface da página de propriedades de controle:<br /><br /> -   Crie páginas de propriedades adicionais.<br />-   Criar e editar bitmaps, ícones, e cursores.<br /><br /> Você também pode testar a página de propriedades no publicador da caixa de diálogo.|O arquivo de recursos padrão criado pelo assistente de aplicativo MFC fornece muitos dos recursos que você precisa.  Visual C\+\+ permite editar recursos existentes e adicionar facilmente e visualmente novos recursos.|  
|Testar os eventos, os métodos, e as propriedades do controle.|Recrie o contêiner de teste de controle e de uso para testar se os manipuladores funcionem corretamente.|Você pode invocar métodos de controle e para manipular suas propriedades na página de propriedades de interface ou no contêiner de teste.  Além disso, use o contêiner de teste para rastreie eventos acionados de controle e notificações recebidas pelo contêiner do controle.|  
  
## Consulte também  
 [Aproveitando o Framework](../mfc/building-on-the-framework.md)   
 [Sequência de operações para compilação de aplicativos MFC](../mfc/sequence-of-operations-for-building-mfc-applications.md)   
 [Sequência de operações para criação de aplicativos OLE](../mfc/sequence-of-operations-for-creating-ole-applications.md)   
 [Sequência de operações para criação de aplicativos de banco de dados](../mfc/sequence-of-operations-for-creating-database-applications.md)