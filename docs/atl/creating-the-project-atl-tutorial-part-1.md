---
title: Criando o projeto de (ATL Tutorial, parte 1) | Microsoft Docs
ms.custom: get-started-article
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: f6b727d1-390a-4b27-b82f-daadcd9fc059
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1aedf7b4112d4c8d4bb5b2a174e93925f5a46ce5
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="creating-the-project-atl-tutorial-part-1"></a>Criando o projeto (Tutorial ATL, parte 1)
Este tutorial vai orientá-lo por meio de um projeto ATL nonattributed que cria um objeto do ActiveX que exibe um polígono. O objeto inclui opções para permitir que o usuário para alterar o número de lados que compõe o polígono e o código para atualizar a exibição.  
  
> [!NOTE]
>  ATL e MFC não têm suporte geralmente nas edições Express do Visual Studio.  
  
> [!NOTE]
>  Este tutorial cria o mesmo código-fonte do exemplo de polígono. Se você quiser evitar inserir o código-fonte manualmente, você pode baixá-lo do [abstrato de exemplo de polígono](../visual-cpp-samples.md). Você pode referir-se ao código-fonte polígono conforme você trabalha com o tutorial ou usá-lo para verificar se há erros em seu próprio projeto.  
  
### <a name="to-create-the-initial-atl-project-using-the-atl-project-wizard"></a>Para criar o projeto ATL inicial usando o Assistente de projeto de ATL  
  
1.  No ambiente de desenvolvimento do Visual Studio, clique em **novo** no **arquivo** menu e clique **projeto**.  
  
2.  Clique o **projetos Visual C++** pasta e selecione **projeto ATL**.  
  
3.  Tipo `Polygon` como o nome do projeto.  
  
     O local para o código-fonte geralmente padrão será Meus Documentos\Visual Studio projetos e uma nova pasta será criada automaticamente.  
  
4.  Clique em **Okey** e abre o Assistente de projeto de ATL.  
  
5.  Clique em **configurações do aplicativo** para ver as opções disponíveis.  
  
6.  À medida que você estiver criando um controle e um controle deve ser um servidor em processo, deixar o **tipo de aplicativo** como uma DLL.  
  
7.  Deixe as outras opções com seus valores padrão e, em seguida, clique em **concluir**.  
  
 O Assistente de projeto de ATL criará o projeto por meio da geração de vários arquivos. Você pode exibir esses arquivos no Gerenciador de soluções, expandindo o objeto de polígono. Os arquivos estão listados abaixo.  
  
|Arquivo|Descrição|  
|----------|-----------------|  
|Polygon.cpp|Contém a implementação de `DllMain`, `DllCanUnloadNow`, `DllGetClassObject`, `DllRegisterServer`, e `DllUnregisterServer`. Também contém o mapa de objeto, que é uma lista dos objetos em seu projeto ATL. Isso é inicialmente em branco.|  
|Polygon.def|Esse arquivo de definição de módulo fornece o vinculador com informações sobre as exportações exigido por sua DLL.|  
|Polygon.idl|O interface idioma arquivo de definição, que descreve as interfaces específicas para seus objetos.|  
|Polygon.rgs|Esse script de registro contém informações para registrar a DLL do programa.|  
|Polygon.rc|O arquivo de recurso, que inicialmente contém as informações de versão e uma cadeia de caracteres que contém o nome do projeto.|  
|Resource.h|O arquivo de cabeçalho do arquivo de recurso.|  
|Polygonps.def|Esse arquivo de definição de módulo fornece o vinculador com informações sobre as exportações necessários para o código de proxy e stub que oferecem suporte a chamadas entre apartments.|  
|stdafx.cpp|O arquivo que será `#include` os arquivos de implementação de ATL.|  
|stdafx.h|O arquivo que será `#include` os arquivos de cabeçalho do ATL.|  
  
1.  No Gerenciador de soluções, clique com botão direito do `Polygon` projeto.  
  
2.  No menu de atalho, clique em **propriedades**.  
  
3.  Clique em **vinculador**. Alterar o **por UserRedirection** opção para **Sim**.  
  
4.  Clique em **OK**.  
  
 A próxima etapa, você adicionará um controle ao seu projeto.  
  
 [Para a etapa 2](../atl/adding-a-control-atl-tutorial-part-2.md)  
  
## <a name="see-also"></a>Consulte também  
 [Tutorial](../atl/active-template-library-atl-tutorial.md)

