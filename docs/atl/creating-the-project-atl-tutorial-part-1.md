---
title: "Criando o projeto (Tutorial ATL, parte 1) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
dev_langs: 
  - "C++"
ms.assetid: f6b727d1-390a-4b27-b82f-daadcd9fc059
caps.latest.revision: 16
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando o projeto (Tutorial ATL, parte 1)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tutorial mostra cada parte da explicação passo a passo através um projeto nonattributed de ATL que cria um objeto ActiveX que exibe um polígono.  O objeto inclui opções para permitir que o usuário altere o número de lados que compõem o polígonos, e o código para atualizar a exibição.  
  
> [!NOTE]
>  ATL e o MFC geralmente não são suportados em Visual Studio express editions.  
  
> [!NOTE]
>  Este tutorial cria o mesmo código\-fonte que o exemplo polígono.  Se você desejar evitar digitar manualmente o código\-fonte, você poderá baixá\-lo de [Sumário de exemplo polygon](../top/visual-cpp-samples.md).  Você pode então referenciar o código\-fonte polygon como trabalhar com o tutorial, ou usa\-o para verificar se há erros em seu próprio projeto.  
  
### Para criar o projeto inicial de ATL que usa o ATL projeta o assistente  
  
1.  No ambiente de desenvolvimento Visual Studio, clique em **Novo** no menu de **Arquivo** , e clique em **Projeto**.  
  
2.  Clique na pasta de **Projetos Visual C\+\+** e selecione **Projeto do ATL**.  
  
3.  Tipo `Polígonos` como o nome do projeto.  
  
     O local para o código fonte é por padrão em geral a meus documentos \\ projetos do Visual Studio, e uma nova pasta será criada automaticamente.  
  
4.  Clique em **OK** e o assistente de ATL O abre.  
  
5.  Clique **Configurações do Aplicativo** para ver as opções disponíveis.  
  
6.  Enquanto você estiver criando um controle, e um controle deve ser um servidor em processo, você **Tipo de Aplicativo** como uma DLL.  
  
7.  Deixe outras opções em seus valores padrão, e clique em **Concluir**.  
  
 O assistente de ATL O criará o projeto produzir vários arquivos.  Você pode exibir esses arquivos no solution Explorer expandindo o objeto polígono.  Os arquivos são listados abaixo.  
  
|Arquivo|Descrição|  
|-------------|---------------|  
|Polygon.cpp|Contém a implementação de `DllMain`, de `DllCanUnloadNow`, de `DllGetClassObject`, de `DllRegisterServer`, e de `DllUnregisterServer`.  Também contém o mapa do objeto, que é uma lista de objetos de ATL em seu projeto.  Isso é inicialmente em branco.|  
|Polygon.def|Este arquivo de módulo definição fornece o vinculador com informações sobre as exportações exigidas por seu DLL.|  
|Polygon.idl|O arquivo do idioma da definição de interface, que descreve as interfaces específicas para seus objetos.|  
|Polygon.rgs|Esse script de Registro contém informações para registrar o DLL do seu programa.|  
|Polygon.rc|O arquivo de recurso, que contém inicialmente informações de versão e uma cadeia de caracteres que contém o nome do projeto.|  
|Resource.h|O arquivo de cabeçalho para o arquivo de recurso.|  
|Polygonps.def|Este arquivo de definição de módulo fornece o vinculador com informações sobre as exportações exigidas pelo proxy e o código de stub que chamadas de suporte através de construção.|  
|stdafx.cpp|O arquivo que `#include` a implementação de ATL arquivos.|  
|stdafx.h|O arquivo que `#include` os arquivos de cabeçalho de ATL.|  
  
1.  No solution Explorer, clique com o botão direito do mouse no projeto de `Polygon` .  
  
2.  No menu de atalho, clique em **Propriedades**.  
  
3.  Clique em **Vinculador**.  Altere a opção de **Por UsuárioRedirecionamento** a **Sim**.  
  
4.  Clique em **OK**.  
  
 No próximo passo, você irá adicionar um controle ao seu projeto.  
  
 [A etapa 2](../atl/adding-a-control-atl-tutorial-part-2.md)  
  
## Consulte também  
 [Tutorial](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md)