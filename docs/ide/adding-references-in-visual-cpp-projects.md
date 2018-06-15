---
title: Adicionando referências em projetos do Visual C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- VC.Project.References
dev_langs:
- C++
helpviewer_keywords:
- Add References Dialog Box (C++)
- .NET Framework (C++), Add References Dialog Box
ms.assetid: 12b8f571-0f21-40b3-9404-5318a57e9cb5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bda420768b1ff0819ba666f71d62bfffa86e2105
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "33336102"
---
# <a name="adding-references-in-visual-c-projects"></a>Adicionando referências em projetos do Visual C++
É muito comum que os programas chamem APIs em outros binários, como DLLs, componentes do Tempo de Execução do Windows, SDKs de extensão, componentes COM e assemblies .NET. A maneira que o programa encontra esses outros binários depende do tipo do projeto e do tipo do binário.  
  
 Em um projeto do C++ nativo, se você estiver consumindo um componente COM ou DLL nativa que não está sendo produzido por outro projeto na solução, use LoadLibrary ou CoCreateInstance para especificar o caminho para o binário; caso contrário, deixe o sistema localizá-lo procurando em locais bem definidos específicos.  
  
 Em outros tipos de projetos, como projetos UWP ou C++/CLI, ou quando o binário é produzido por outro projeto na solução, adicione uma *referência* ao assembly, ao componente ou ao projeto.   Essencialmente, uma referência é um conjunto de dados que permite ao programa localizar o binário e se comunicar com ele.       Quando você adiciona uma referência, o Visual Studio cuida dos detalhes de nível inferior. Para definir as referências de um projeto do C++ para assemblies .NET Framework (somente C++/CLI), componentes COM, outros projetos na solução, incluindo projetos compartilhados ou serviços conectados, clique com o botão direito do mouse no nó **Referências** no **Gerenciador de Soluções** para exibir o **Gerenciador de Referências**. O que é exibido no Gerenciador de Referências varia, dependendo do tipo de projeto.  
  
 Em um projeto do C++ nativo (ATL), o conceito de *referências* só se aplica a outros projetos na solução, incluindo projetos compartilhados; portanto, isso é tudo o que é exibido no **Gerenciador de Referências**:  
  
 ![Gerenciador de Referências do Visual C&#43;&#43; &#40;Projetos ATL&#41;](../ide/media/visual-c---reference-manager--atl-projects-.png "Gerenciador de Referências do Visual C++ (projetos ATL)")  
  
 Em um projeto do C++/CLI ou da Plataforma Universal do Windows, o conceito de referências se aplica a mais tipos de binários, além de outros projetos na solução.  Todas elas são expostas no **Gerenciador de Referências**.
  
## <a name="reference-properties"></a>Propriedades de referência  
 Cada tipo de referência tem propriedades. Exiba as propriedades selecionando a referência no Gerenciador de Soluções e pressionando **Alt+Enter** ou clicando com o botão direito do mouse e escolhendo **Propriedades**. Algumas propriedades são somente leitura e algumas podem ser modificadas. No entanto, em geral, você não precisa modificar essas propriedades manualmente.  
  
### <a name="activex-reference-properties"></a>Propriedades de referência do ActiveX  
 As propriedades de referência do ActiveX estão disponíveis somente para referências a componentes COM. Essas propriedades são exibidas apenas quando um componente COM é selecionado no painel **Referências**. As propriedades não podem ser modificadas.  
  
 **Caminho Completo do Controle**  
 Exibe o caminho do diretório do controle referenciado.  
  
 **GUID do Controle**  
 Exibe o GUID do controle ActiveX.  
  
 **Versão do Controle**  
 Exibe a versão do controle ActiveX referenciado.  
  
 **Nome da Biblioteca de Tipos**  
 Exibe o nome da biblioteca de tipos referenciada.  
  
 **Ferramenta Wrapper**  
 Exibe a ferramenta usada para compilar o assembly de interoperabilidade da biblioteca COM referenciada ou do controle ActiveX.  
  
### <a name="assembly-reference-properties"></a>Propriedades de referência do assembly  
 As propriedades de referência do assembly estão disponíveis somente para referências a assemblies .NET Framework em projetos do C++/CLI. Essas propriedades são exibidas apenas quando um assembly .NET Framework é selecionado no painel **Referências**. As propriedades não podem ser modificadas.  
  
 **Caminho Relativo**  
 Exibe o caminho relativo do diretório do projeto ao assembly referenciado.  
  
### <a name="build-properties"></a>Propriedades de build  
 As propriedades a seguir estão disponíveis em vários tipos de referências. Elas permitem que você especifique como compilar com referências.  
  
 **Local da Cópia**  
 Especifica se o assembly referenciado será copiado automaticamente para o local de destino durante um build.  
  
 **Assemblies Satélite do Local da Cópia**  
 Especifica se os assemblies satélite serão copiados automaticamente do assembly referenciado para o local de destino durante um build. Usado somente se **Local da Cópia** é `true`.  
  
 **Saída do Assembly de Referência**  
 Especifica que esse assembly é usado no processo de build. Se `true`, o assembly é usado na linha de comando do compilador durante o build.  
  
### <a name="project-to-project-reference-properties"></a>Propriedades de referência projeto a projeto  
 As propriedades a seguir definem uma *referência projeto a projeto* do projeto selecionado no painel **Referências** como outro projeto na mesma solução. Para obter mais informações, consulte [Gerenciando referências em um projeto](/visualstudio/ide/managing-references-in-a-project).  
  
 **Dependências da Biblioteca de Links**  
 Quando essa propriedade é **True**, o sistema de projeto é vinculado ao projeto dependente dos arquivos .lib que são produzidos pelo projeto independente. Normalmente, você especificará **True**.  
  
 **Identificador do Projeto**  
 Identifica exclusivamente o projeto independente. O valor da propriedade é um GUID de sistema interno que não pode ser modificado.  
  
 **Usar Entradas de Dependência da Biblioteca**  
 Quando essa propriedade é **False**, o sistema de projeto não é vinculado ao projeto dependente dos arquivos .obj para a biblioteca produzidos pelo projeto independente. Consequentemente, esse valor desabilita a vinculação incremental. Em geral, você especificará **False** porque o build do aplicativo pode levar muito tempo se há muitos projetos independentes.  
  
### <a name="reference-properties"></a>Propriedades de referência  
 As propriedades a seguir são encontradas em referências de assembly .NET e COM e não podem ser modificadas.  
  
 **Nome do assembly**  
 Exibe o nome do assembly para o assembly referenciado.  
  
 **Cultura**  
 Exibe a cultura da referência selecionada.  
  
 **Descrição**  
 Exibe a descrição da referência selecionada.  
  
 **Caminho Completo**  
 Exibe o caminho do diretório do assembly referenciado.  
  
 **Identidade**  
 Para assemblies .NET Framework, exibe o caminho completo. Para componentes COM, exibe o GUID.  
  
 **Rótulo**  
 Exibe o rótulo da referência.  
  
 **Nome**  
 Exibe o nome da referência.  
  
 **Token de Chave Pública**  
 Exibe o token de chave pública usado para identificar o assembly referenciado.  
  
 **Nome Forte**  
 `true` se o assembly referenciado tem um nome forte. Um assembly com nome forte tem uma versão exclusiva.  
  
 **Versão**  
 Exibe a versão do assembly referenciado.  
  
## <a name="see-also"></a>Consulte também  
 [Páginas de propriedades](../ide/property-pages-visual-cpp.md)   
 [Trabalhando com Propriedades do Projeto](../ide/working-with-project-properties.md)