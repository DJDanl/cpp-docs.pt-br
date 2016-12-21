---
title: "Modelo de projeto de biblioteca de classes WRL | Microsoft Docs"
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
ms.assetid: 628b0852-89e5-44f8-bf58-a09762bda15c
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Modelo de projeto de biblioteca de classes WRL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se você usar o Visual Studio para gravar um projeto de [!INCLUDE[cppwrl](../windows/includes/cppwrl_md.md)] \([!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)]\), você pode simplificar muito sua tarefa baixando o modelo de projeto de biblioteca de classes de WRL.  
  
> [!NOTE]
>  Se for necessário atualizar manualmente as configurações de um projeto existente, consulte [DLL \(C\+\+\/CX\)](http://msdn.microsoft.com/library/windows/apps/hh699881\(v=vs.110\).aspx).  
  
## Baixe o modelo de projeto de WRL  
 Visual Studio não fornece um modelo para projetos de [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)] .  Veja como baixar um modelo de projeto do que cria uma biblioteca básica da classe para aplicativos de [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] com [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)].  
  
#### Para baixar o modelo de projeto de WRL  
  
1.  Na barra de menu, escolha **Arquivo**, **Novo Projeto**.  
  
2.  No painel esquerdo da caixa de diálogo de **Novo Projeto** , **Online**, selecione e selecione **Modelos**.  
  
3.  Na caixa de **Pesquisar modelos online** no canto superior direito, digite `Biblioteca de classes de WRL`.  Quando o modelo é exibido nos resultados da pesquisa, escolha o botão de **OK** .  
  
4.  Na caixa de diálogo de **Fazer o download e Instalar** , se você concordar com os termos de licença, escolha o botão de **Instalar** .  
  
5.  Depois que as instalações do modelo, criará um projeto escolhendo **Arquivo**, **Novo Projeto**, e selecione o modelo de `WRLClassLibrary` .  O projeto cria um DLL.  
  
## Exemplos que usam o modelo de projeto  
 Ler [Passo a passo: Criando um componente básico do Tempo de Execução do Windows](../windows/walkthrough-creating-a-basic-windows-runtime-component-using-wrl.md) para obter um exemplo que usa esse modelo para criar um componente de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] .  
  
## O que o modelo de projeto fornece  
 O modelo de projeto fornece:  
  
-   um arquivo de .idl que declare MIDL atribui uma interface básica para sua implementação da classe.  Veja um exemplo.  
  
     [!code-cpp[wrl-project-template#1](../windows/codesnippet/CPP/wrl-class-library-project-template_1.idl)]  
  
-   um arquivo .cpp que define a implementação da classe.  Veja um exemplo.  
  
     [!code-cpp[wrl-project-template#2](../windows/codesnippet/CPP/wrl-class-library-project-template_2.cpp)]  
  
     Ajuda da classe base de [RuntimeClass](../windows/runtimeclass-class.md) gerenciam a referência global de todos os objetos no módulo e declaram os métodos de [IUnknown](http://msdn.microsoft.com/pt-br/33f1d79a-33fc-4ce5-a372-e08bda378332) e [IInspectable](http://msdn.microsoft.com/pt-br/0657e51f-d4c0-46c6-927d-b01e54b6846c) interfaces.  A macro de [InspectableClass](../windows/inspectableclass-macro.md) implementa `IUnknown` e `IInspectable`.  A macro de [ActivatableClass](../Topic/ActivatableClass%20Macros.md) cria uma fábrica da classe que cria instâncias da classe.  
  
-   um arquivo denominado module.cpp que define as `DllMain`exportações, `DllCanUnloadNow`, `DllGetActivationFactory`, e `DllGetClassObject`de biblioteca.  
  
## Consulte também  
 [Biblioteca de Modelos C\+\+ do Tempo de Execução do Windows \(WRL\)](../Topic/Windows%20Runtime%20C++%20Template%20Library%20\(WRL\).md)