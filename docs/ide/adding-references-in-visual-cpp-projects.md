---
title: "Adicionando refer&#234;ncias em projetos do Visual C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "VC.Project.References"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - ".NET Framework (C++), Caixa de diálogo Adicionar Referências"
  - "Caixa de diálogo Adicionar Referências (C++)"
ms.assetid: 12b8f571-0f21-40b3-9404-5318a57e9cb5
caps.latest.revision: 32
caps.handback.revision: 32
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando refer&#234;ncias em projetos do Visual C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

É muito comum para programas chamar APIs em outros binários, como DLLs, componentes de tempo de execução do Windows, SDKs de extensão, componentes COM e assemblies do .NET. A maneira que seu programa localiza os outros binários depende do tipo do seu projeto e o tipo do binário.  
  
 Em um projeto de C\+\+ nativo, se estão consumindo um componente nativo de DLL ou COM que não é produzido por outro projeto em sua solução, use LoadLibrary ou CoCreateInstance para especificar o caminho para o binário, senão permitem que o sistema localizá\-lo examinando específicas locais bem definidos.  
  
 Em outros tipos de projetos, como projetos UWP ou C \+ \+ \/ projetos CLI, ou quando o binário é produzido por outro projeto em sua solução, você adiciona um *referência* ao assembly, componente ou projeto.   Uma referência é essencialmente um conjunto de dados que permite que seu programa localizar e se comunicar com o binário.       Quando você adiciona uma referência, o Visual Studio trata os detalhes de baixo níveis. Definir referências de um projeto de C\+\+ para [!INCLUDE[dnprdnshort](../Token/dnprdnshort_md.md)] assemblies \(C \+ c\+\+ CLI apenas\), componentes COM, outros projetos na sua solução, incluindo projetos compartilhados ou serviços conectados, clique no **referências** nó **Solution Explorer** para abrir o **Gerenciador de referências**. O que você vê no Gerenciador de referências é diferente dependendo do tipo de projeto.  
  
 Em um projeto de C\+\+ nativo \(ATL\) o conceito de *referências* só se aplica a outros projetos na solução, incluindo projetos compartilhados, isso é tudo que você vê no **Gerenciador de referências**:  
  
 ![Visual C&#43;&#43; Reference Manager &#40;ATL Projects&#41;](../Image/Visual%20C++%20Reference%20Manager%20\(ATL%20Projects\).png "Visual C\+\+ Reference Manager \(ATL Projects\)")  
  
 No C \+ \+ \/ projeto CLI ou plataforma Universal do Windows, o conceito de referências se aplica a mais tipos de binários, além de outros projetos na solução.  Elas são expostas em **Gerenciador de referências**:  
  
 ![Visual C&#43;&#43; Reference Manager for C&#43;&#43;&#47;CLI projects](../Image/Visual%20C++%20Reference%20Manager%20for%20C++/CLI%20projects.png "Visual C\+\+ Reference Manager for C\+\+\/CLI projects")  
  
## Propriedades de referência  
 Cada tipo de referência tem propriedades. Você pode exibir as propriedades, selecionando a referência no Gerenciador de soluções e pressionando **Alt \+ Enter**, ou se encontram com o botão direito e escolhendo **propriedades**. Algumas propriedades são somente leitura e algumas podem ser modificadas. No entanto, normalmente você não precisa modificar manualmente essas propriedades.  
  
### Propriedades de referência do ActiveX  
 Propriedades de referência do ActiveX estão disponíveis apenas para referências a componentes COM. Essas propriedades são exibidas somente quando um componente é selecionado no **referências** painel. As propriedades não podem ser modificadas.  
  
 **Caminho completo do controle**  
 Exibe o caminho do diretório do controle referenciado.  
  
 **GUID de controle**  
 Exibe o GUID para o controle ActiveX.  
  
 **Versão de controle**  
 Exibe a versão do controle ActiveX mencionado.  
  
 **Nome da biblioteca de tipo**  
 Exibe o nome da biblioteca de tipos referenciada.  
  
 **Ferramenta do wrapper**  
 Exibe a ferramenta que é usada para criar o assembly de interoperabilidade da biblioteca COM referenciada ou controle ActiveX.  
  
### Propriedades de referência do assembly  
 Propriedades de referência do assembly estão disponíveis apenas para referências a [!INCLUDE[dnprdnshort](../Token/dnprdnshort_md.md)] assemblies no C \+ \+ \/ projetos CLI. Essas propriedades são exibidas apenas quando um [!INCLUDE[dnprdnshort](../Token/dnprdnshort_md.md)] assembly está selecionado no **referências** painel. As propriedades não podem ser modificadas.  
  
 **Caminho relativo**  
 Exibe o caminho relativo do diretório do projeto para o assembly referenciado.  
  
### As propriedades de compilação  
 As seguintes propriedades estão disponíveis em vários tipos de referências. Elas permitem que você especifique como compilar com referências.  
  
 **Cópia Local**  
 Especifica se deve copiar automaticamente o assembly referenciado para o local de destino durante uma compilação.  
  
 **Copie os Assemblies satélite de Local**  
 Especifica se deve copiar automaticamente os assemblies satélite do assembly referenciado para o local de destino durante uma compilação. Usado somente se **Copy Local** é `true`.  
  
 **Saída de Assembly de referência**  
 Especifica que este assembly é usado no processo de compilação. Se `true`, o assembly é usado na linha de comando do compilador durante a compilação.  
  
### Propriedades de referência de projeto para projeto  
 Definem as propriedades a seguir um *referência projeto a projeto* do projeto selecionado no **referências** painel a outro projeto na mesma solução. Para obter mais informações, consulte [Gerenciando referências em um projeto](../Topic/Managing%20references%20in%20a%20project.md).  
  
 **Dependências da biblioteca de link**  
 Quando essa propriedade é **True**, vínculos de sistema do projeto no projeto dependente os arquivos. lib que são produzidos pelo projeto independente. Normalmente, você especificará **True**.  
  
 **Identificador de projeto**  
 Identifica exclusivamente o projeto independente. O valor da propriedade é um sistema interno GUID não pode ser modificada.  
  
 **Usar entradas de dependência de biblioteca**  
 Quando essa propriedade for **False**, o sistema do projeto não serão vinculados ao projeto dependente os arquivos. obj para a biblioteca produzidos pelo projeto independente. Consequentemente, este valor desabilita a vinculação incremental. Normalmente, você especificará **False** porque a criação do aplicativo pode levar muito tempo se houver muitos projetos independentes.  
  
### Propriedades de referência  
 As seguintes propriedades são encontradas em referências de assembly COM e .NET e não podem ser modificadas.  
  
 **Nome do assembly**  
 Exibe o nome do assembly do assembly referenciado.  
  
 **Cultura**  
 Exibe a cultura da referência selecionada.  
  
 **Descrição**  
 Exibe a descrição da referência selecionada.  
  
 **Caminho completo**  
 Exibe o caminho do diretório do assembly referenciado.  
  
 **Identidade**  
 Para o [!INCLUDE[dnprdnshort](../Token/dnprdnshort_md.md)] assemblies, exibe o caminho completo. Para componentes COM, exibe o GUID.  
  
 **Rótulo**  
 Exibe o rótulo da referência.  
  
 **Nome**  
 Exibe o nome da referência.  
  
 **Token de chave pública**  
 Exibe o token de chave pública que é usado para identificar o assembly referenciado.  
  
 **Nome forte**  
 `true` Se o assembly referenciado tem um nome forte. Um assembly de nome forte é exclusivamente da versão.  
  
 **Version**  
 Exibe a versão do assembly referenciado.  
  
## Consulte também  
 [Páginas de propriedade](../ide/property-pages-visual-cpp.md)   
 [Como abrir páginas de propriedade do projeto](../misc/how-to-open-project-property-pages.md)