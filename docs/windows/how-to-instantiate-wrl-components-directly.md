---
title: "Como instanciar componentes WRL diretamente | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
ms.assetid: 1a9fa011-0cee-4abf-bf83-49adf53ff906
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como instanciar componentes WRL diretamente
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Saiba como usar [!INCLUDE[cppwrl](../windows/includes/cppwrl_md.md)] \([!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)]\) [Microsoft::WRL::Make](../windows/make-function.md) e funções de [Microsoft::WRL::Details::MakeAndInitialize](../windows/makeandinitialize-function.md) para criar uma instância de um componente do módulo que define o.  
  
 Criando uma instância do componente diretamente, você pode reduzir a sobrecarga quando não precisar fábricas da classe ou outros mecanismos.  Você pode criar uma instância de um componente diretamente em ambos os aplicativos de [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] e em aplicativos de área de trabalho.  
  
 Para saber como usar [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)] para criar um componente básico de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] e para criar\-lo uma instância de um aplicativo externo de [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] , consulte [Passo a passo: Criando um componente básico do Tempo de Execução do Windows](../windows/walkthrough-creating-a-basic-windows-runtime-component-using-wrl.md).  Para saber como usar [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)] para criar um componente COM clássico e para criar\-lo uma instância de um aplicativo externo de área de trabalho, consulte [Como criar um componente COM clássico](../windows/how-to-create-a-classic-com-component-using-wrl.md).  
  
 Este documento mostra dois exemplos.  O primeiro exemplo usa a função de `Make` para criar uma instância de um componente.  O segundo exemplo usa a função de `MakeAndInitialize` para criar uma instância de um componente que pode falhar durante a compilação. \(Porque COM geralmente usa valores de `HRESULT` , em vez de exceções, para indicar erros, um tipo de COM normalmente não lança do construtor.  `MakeAndInitialize` permite que um componente para validar seus argumentos de compilação com o método de `RuntimeClassInitialize` .\) Os dois exemplos definem uma interface e implemente básicos de agente que têm interface definindo uma classe que mensagens de gravações no console.  
  
> [!IMPORTANT]
>  Você não pode usar o operador de `new` para criar uma instância componentes de [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)] .  Consequentemente, recomendamos que você sempre use `Make` ou `MakeAndInitialize` para criar uma instância diretamente um componente.  
  
### Para criar uma instância de um componente básico do registrador  
  
1.  No Visual Studio, crie um projeto de **Aplicativo do Console Win32** .  O nome do projeto, por exemplo, `WRLLogger`.  
  
2.  Adicionar um arquivo de **Midl Arquivo \(.idl\)** ao projeto, nomeie o arquivo `ILogger.idl`, e adicione esse código:  
  
     [!CODE [wrl-logger-make#1](../CodeSnippet/VS_Snippets_Misc/wrl-logger-make#1)]  
  
3.  Use o código a seguir para substituir o conteúdo de WRLLogger.cpp.  
  
     [!CODE [wrl-logger-make#2](../CodeSnippet/VS_Snippets_Misc/wrl-logger-make#2)]  
  
### Para controlar a falha de compilação para o componente básico do registrador  
  
1.  Use o código a seguir para substituir a definição da classe de `CConsoleWriter` .  Esta versão mantém uma variável de membro particular de cadeia de caracteres e substitui o método de `RuntimeClass::RuntimeClassInitialize` .  `RuntimeClassInitialize` falha se a chamada a `SHStrDup` falha.  
  
     [!code-cpp[wrl-logger-makeandinitialize#1](../windows/codesnippet/CPP/how-to-instantiate-wrl-components-directly_1.cpp)]  
  
2.  Use o código a seguir para substituir a definição de `wmain`.  Esta versão `MakeAndInitialize` usa para criar uma instância do objeto de `CConsoleWriter` e verifica o resultado de `HRESULT` .  
  
     [!code-cpp[wrl-logger-makeandinitialize#2](../windows/codesnippet/CPP/how-to-instantiate-wrl-components-directly_2.cpp)]  
  
## Consulte também  
 [Biblioteca de Modelos C\+\+ do Tempo de Execução do Windows \(WRL\)](../Topic/Windows%20Runtime%20C++%20Template%20Library%20\(WRL\).md)   
 [Microsoft::WRL::Make](../windows/make-function.md)   
 [Microsoft::WRL::Details::MakeAndInitialize](../windows/makeandinitialize-function.md)