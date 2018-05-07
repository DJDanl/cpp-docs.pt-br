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
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="adding-references-in-visual-c-projects"></a>Adicionando referências em projetos do Visual C++
É muito comum para programas chamar APIs em outros binários, como DLLs, componentes do Windows Runtime, SDKs de extensão, componentes COM e assemblies .NET. A maneira que o programa localizará os outros binários depende do tipo do seu projeto e o tipo do binário.  
  
 Em um projeto de C++ nativo, se está consumindo um componente nativo de DLL ou COM que não está sendo produzido por outro projeto em sua solução, use LoadLibrary ou CoCreateInstance para especificar o caminho para o binário, caso contrário, deixe o sistema localizá-lo através do boas-vindas específico locais definidas l.  
  
 Em outros tipos de projetos, como projetos UWP ou C + + projetos CLI, ou quando o binário é produzido por outro projeto em sua solução, você adiciona um *referência* para o assembly, o componente ou o projeto.   Uma referência é essencialmente um conjunto de dados que permite que seu programa localizar e se comunicar com o binário.       Quando você adiciona uma referência, o Visual Studio trata os detalhes de nível inferior. Para definir as referências de um projeto de C++ para .NET Frameworkassemblies (C + + CLI somente), componentes COM, outros projetos na sua solução, incluindo projetos compartilhados ou conectada a serviços, clique com botão direito no **referências** nó **Solution Explorer** para ativar o **Gerenciador de referências**. O que é exibido no Gerenciador de referências difere dependendo de seu tipo de projeto.  
  
 Em um projeto de C++ nativo (ATL) o conceito de *referências* só se aplica a outros projetos na solução, incluindo projetos compartilhados, portanto, isso é tudo o que você vê no **Gerenciador de referências**:  
  
 ![Visual C#&#43; &#43; Gerenciador de referências &#40;projetos ATL&#41;](../ide/media/visual-c---reference-manager--atl-projects-.png "Gerenciador de referências do Visual C++ (projetos ATL)")  
  
 Em C + + o conceito de referências de projeto CLI ou plataforma Universal do Windows, aplica a mais tipos de binários, além de outros projetos na solução.  Esses são expostos no **Gerenciador de referências**.
  
## <a name="reference-properties"></a>Propriedades da referência  
 Cada tipo de referência tem propriedades. Você pode exibir as propriedades, selecionando a referência no Gerenciador de soluções e pressionando **Alt + Enter**, ou se encontram com o botão direito e escolhendo **propriedades**. Algumas propriedades são somente leitura e algumas podem ser modificadas. No entanto, normalmente você não precisa modificar manualmente essas propriedades.  
  
### <a name="activex-reference-properties"></a>Propriedades da referência do ActiveX  
 Propriedades da referência do ActiveX estão disponíveis apenas para referências a componentes COM. Essas propriedades são exibidas apenas quando um componente COM está selecionado no **referências** painel. As propriedades não podem ser modificadas.  
  
 **Caminho completo do controle**  
 Exibe o caminho do diretório do controle referenciado.  
  
 **GUID de controle**  
 Exibe o GUID para o controle ActiveX.  
  
 **Controle de versão**  
 Exibe a versão do controle ActiveX mencionado.  
  
 **Nome da biblioteca de tipo**  
 Exibe o nome da biblioteca de tipos referenciada.  
  
 **Ferramenta do wrapper**  
 Exibe a ferramenta que é usada para compilar o assembly de interoperabilidade da biblioteca COM referenciada ou controle ActiveX.  
  
### <a name="assembly-reference-properties"></a>Propriedades da referência do assembly  
 Propriedades da referência do assembly estão disponíveis apenas para referências a .NET Frameworkassemblies no C + + projetos CLI. Essas propriedades são exibidas apenas quando um Frameworkassembly .NET é selecionada no **referências** painel. As propriedades não podem ser modificadas.  
  
 **Caminho relativo**  
 Exibe o caminho relativo do diretório do projeto para o assembly referenciado.  
  
### <a name="build-properties"></a>Propriedades de compilação  
 As seguintes propriedades estão disponíveis em vários tipos de referências. Elas permitem que você especificar como compilar com referências.  
  
 **Local da cópia**  
 Especifica se deve copiar o assembly referenciado automaticamente para o local de destino durante uma compilação.  
  
 **Copiar Assemblies satélite de Local**  
 Especifica se deve copiar os assemblies satélites do assembly referenciado automaticamente para o local de destino durante uma compilação. Usado somente se **Copy Local** é `true`.  
  
 **Saída de Assembly de referência**  
 Especifica que este assembly é usado no processo de compilação. Se `true`, o assembly é usado na linha de comando do compilador durante a compilação.  
  
### <a name="project-to-project-reference-properties"></a>Propriedades da referência de projeto-a-projeto  
 Definem as propriedades a seguir um *referência projeto a projeto* do projeto selecionado no **referências** painel para outro projeto na mesma solução. Para obter mais informações, consulte [Gerenciando referências em um projeto](/visualstudio/ide/managing-references-in-a-project).  
  
 **Dependências de biblioteca de link**  
 Quando essa propriedade é **True**, o sistema do projeto contém links para o projeto dependente os arquivos. lib que são produzidos pelo projeto independente. Normalmente, você especificará **True**.  
  
 **Identificador do projeto**  
 Identifica exclusivamente o projeto independente. O valor da propriedade é um sistema interno GUID não pode ser modificado.  
  
 **Usar entradas de dependência de biblioteca**  
 Quando essa propriedade é **False**, o sistema do projeto não será vinculado para o projeto dependente os arquivos. obj para a biblioteca produzidos pelo projeto independente. Como consequência, este valor desabilita vínculo incremental. Normalmente, você especificará **False** porque a criação do aplicativo pode levar muito tempo se houver muitos projetos independentes.  
  
### <a name="reference-properties"></a>Propriedades da referência  
 As propriedades a seguir são encontradas no .NET e COM referências de assembly e não podem ser modificadas.  
  
 **Nome do assembly**  
 Exibe o nome do assembly para o assembly referenciado.  
  
 **Cultura**  
 Exibe a cultura da referência selecionada.  
  
 **Descrição**  
 Exibe a descrição da referência selecionada.  
  
 **Caminho completo**  
 Exibe o caminho do diretório do assembly referenciado.  
  
 **Identidade**  
 Para o .NET Frameworkassemblies, exibe o caminho completo. Para componentes COM, exibe o GUID.  
  
 **Rótulo**  
 Exibe o rótulo da referência.  
  
 **Nome**  
 Exibe o nome da referência.  
  
 **Token de chave pública**  
 Exibe o token de chave pública que é usado para identificar o assembly referenciado.  
  
 **Nome forte**  
 `true` Se o assembly mencionado tiver um nome forte. Um assembly com nome forte é exclusivamente da versão.  
  
 **Versão**  
 Exibe a versão do assembly referenciado.  
  
## <a name="see-also"></a>Consulte também  
 [Páginas de propriedade](../ide/property-pages-visual-cpp.md)   
 [Trabalhando com Propriedades do Projeto](../ide/working-with-project-properties.md)