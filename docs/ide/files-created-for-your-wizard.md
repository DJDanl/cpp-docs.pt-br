---
title: "Arquivos criados para o assistente | Microsoft Docs"
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
  - "assistentes personalizados, excluindo arquivos"
  - "assistentes personalizados, arquivos criados"
  - "Arquivos  [C++], criado por Assistente Personalizado"
  - "ícones, excluindo"
ms.assetid: 7f0e393c-395e-491b-add2-904cf8838e81
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Arquivos criados para o assistente
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O assistente usa o nome que você especificar na  **nome**  caixa no  **Novo projeto** caixa de diálogo para derivar de nomes para alguns arquivos e classes.  
  
 O  [Assistente personalizada](../ide/custom-wizard.md) adiciona comentários para os arquivos que ele cria para o seu assistente.  O assistente personalizada também cria um arquivo de texto Readme. txt, no seu novo diretório de aplicativo.  Esse arquivo explica o conteúdo e usa dos outros novos arquivos criados pelo assistente personalizada.  
  
 A tabela a seguir descreve os arquivos criados pelo assistente personalizada.  Para obter mais informações sobre como os principais elementos interagem para criar um assistente, consulte [Projetando um assistente](../ide/designing-a-wizard.md).  
  
|File|Descrição|  
|----------|---------------|  
|[Project.vsz](../ide/dot-vsz-file-project-control.md)|Um arquivo de texto semelhante ao formato. ini antigo.  Ele identifica o mecanismo de assistente e fornece contexto e opcionais  [parâmetros personalizados](../ide/custom-parameters-in-the-wizard-dot-vsz-file.md).|  
|[Project.vsdir](../Topic/Adding%20Wizards%20to%20the%20Add%20Item%20and%20New%20Project%20Dialog%20Boxes%20by%20Using%20.Vsdir%20Files.md)|Um arquivo de texto que permite que o shell de Visual Studio para localizar o assistente e exibi\-la na  **Novo projeto** caixa de diálogo.|  
|[Arquivos HTML \(opcionais\)](../ide/html-files.md)|Um assistente pode conter uma interface de usuário \(UI\), que é uma interface HTML.  Um assistente sem uma interface de usuário não contém nenhum arquivo HTML.<br /><br /> Se um assistente tem uma interface do usuário, cada tela do assistente individual é conhecida como um  *página*, e cada página especifica os recursos de interface do usuário.<br /><br /> O arquivo default. htm define a primeira página do assistente.  Use o  **número de páginas** caixa de listagem de  [configurações de aplicativo, o assistente personalizada](../Topic/Application%20Settings,%20Custom%20Wizard.md) para especificar as páginas adicionais.  Cada página é definida por um Page \_*número de página*arquivo. htm, onde  *número de página* intervalos entre 2 e o número de páginas que você especificar.|  
|[Arquivos de script](../ide/jscript-file.md)|O assistente personalizada cria um arquivo de JScript, default. js, para cada assistente criado.  Este arquivo contém funções de JScript que acessem o Assistente do Visual C\+\+, código e modelos de objeto de ambiente para personalizar um assistente.  Você pode personalizar e adicionar funções no arquivo de default. js do seu assistente.<br /><br /> Além disso, seu assistente inclui o  [common.js](../ide/customizing-cpp-wizards-with-common-jscript-functions.md) arquivo, que contém as funções de JScript usadas com freqüência e é compartilhado entre todos os assistentes, inclusive dos assistentes usados pelo Visual C\+\+ para criar outros tipos de projeto.  Para obter mais informações, consulte [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md).|  
|[Modelos](../ide/template-files.md)|Os modelos de um assistente são uma coleção de arquivos de texto que contêm diretivas, que são analisadas e inseridas na tabela de símbolo, dependendo das seleções do usuário assistente.  Os arquivos de texto do modelo são processados de acordo com o usuário de entrada e adicionado ao projeto criado pelo assistente.  As informações apropriadas são obtidas acessando diretamente da tabela de símbolos do controle wizard.|  
|[Templates.inf](../Topic/Templates.inf%20File.md)|Um arquivo de texto que lista todos os modelos associados ao projeto.|  
|Default.vcxproj|Um arquivo. XML que contém as informações sobre o tipo de projeto.|  
|Txt|Um arquivo de modelo que mostra como as diretivas de seus assistente são usadas.|  
|Readme. txt|Um arquivo de modelo que contém um resumo de cada arquivo criado pelo assistente personalizada.|  
|Imagens \(opcionais\)|Você pode fornecer quaisquer imagens, como, por exemplo, ícones, GIFs, BMPs e outros formatos de imagem compatíveis com HTML, para aprimorar a interface do usuário para seu assistente.  Um assistente que não tem nenhuma interface do usuário não precisa de imagens.|  
|Styles. CSS \(opcional\)|Um arquivo que define os estilos para a interface do usuário.  Se o assistente não tem uma interface de usuário, o assistente personalizada não cria um arquivo. css.|  
  
 Se você excluir os arquivos do assistente e diretórios, você também deve excluir os seguintes arquivos do diretório \\vc7\\vcprojects\\.  Até que você excluir esses arquivos, ícones para o seu assistente continuará apareça na  **Novo projeto** caixa de diálogo.  
  
-   *ProjectName*vsz  
  
-   *ProjectName*. ico  
  
-   *ProjectName*.vsdir  
  
## Consulte também  
 [Assistente Personalizado](../ide/custom-wizard.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)   
 [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)